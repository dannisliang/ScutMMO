using System;
using System.Collections.Generic;
using GameServer.Script.Model;
using ZyGames.Framework.Cache.Generic;
using ZyGames.Framework.Game.Context;
using ZyGames.Framework.Game.Contract;
using ZyGames.Framework.Game.Contract.Action;
using ZyGames.Framework.Game.Service;
using ZyGames.Framework.Game.Sns;
using ZyGames.Framework.Game.Runtime;
using ZyGames.Framework.Game.Lang;

using ZyGames.Framework.Common.Serialization;
using ZyGames.Framework.RPC.IO;
using Game.Script;
using ProtoBuf;

namespace GameServer.Script.CsScript.Action
{
    public abstract class  LoginExtendActionProtoBuf : LoginExtendAction
    {
        protected RequestLogin1004Pack requestPack;
        protected ResponseLogin1004Pack responsePack;

        private ResponsePack _responseHead;

        protected LoginExtendActionProtoBuf(int actionId, ActionGetter actionGetter)
            : base((short)actionId, actionGetter)
        {
        }

        private void SetResponseHead()
        {
            _responseHead = new ResponsePack()
            {
                MsgId = actionGetter.GetMsgId(),
                ActionId = actionGetter.GetActionId(),
                ErrorCode = ErrorCode,
                ErrorInfo = ErrorInfo,
                St = St
            };
        }

        public override void WriteResponse(BaseGameResponse response)
        {
            SetResponseHead();
            byte[] headBytes = ProtoBufUtils.Serialize(_responseHead);
            byte[] contentBytes = BuildResponsePack();
            byte[] buffer = null;
            if (contentBytes == null || contentBytes.Length == 0)
            {
                buffer = BufferUtils.AppendHeadBytes(headBytes);
            }
            else
            {
                buffer = BufferUtils.MergeBytes(
                    BufferUtils.AppendHeadBytes(headBytes),
                    contentBytes
                );
            }
            //需要对字节数据加密处理，这里跳过

            response.BinaryWrite(buffer);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        protected override ILogin CreateLogin()
        {
            return LoginProxyProtoBuf.GetLogin(actionGetter, RetailID);
        }

        /// <summary>
        /// 客户端请求的参数较验
        /// </summary>
        /// <returns>false:中断后面的方式执行并返回Error</returns>
        public override bool GetUrlElement()
        {
            byte[] data = (byte[])actionGetter.GetMessage();
            if (data.Length > 0)
            {
                requestPack = ProtoBufUtils.Deserialize<RequestLogin1004Pack>(data);
                if (requestPack == null)
                {
                    return false;
                }

                MobileType = (MobileType)requestPack.MobileType;
                PassportId = requestPack.Pid;
                Password = requestPack.Pwd;
                RetailID = requestPack.RetialId;

                ServerID = requestPack.ServerId;
                DeviceID = requestPack.DeviceID;

                NickName = requestPack.NickName;
                return true;
            }
            return false;
        }

        /// <summary>
        /// 下发给客户的包结构数据
        /// </summary>
        protected virtual byte[] BuildResponsePack()
        {
            if (responsePack == null)
            {
                return null;
            }
            return ProtoBufUtils.Serialize(responsePack);
        }
    }
}
