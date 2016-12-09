using System;
using System.Collections.Generic;

using ZyGames.Framework.Cache.Generic;
using ZyGames.Framework.Common;
using ZyGames.Framework.Game.Contract;
using ZyGames.Framework.Game.Service;

using ZyGames.Framework.Common.Serialization;
using ZyGames.Framework.RPC.IO;
using ProtoBuf;
using ZyGames.Framework.Game.Contract.Action;

namespace GameServer.Script.CsScript.Action
{
    /// <summary>
    /// hello
    /// </summary>
    /// <remarks>继续BaseStruct类:允许无身份认证的请求;AuthorizeAction:需要身份认证的请求</remarks>
    public class Action1001 : BaseAction
    {
        private RequestHello1001Pack requestPack;
        private ResponseHello1001Pack responsePack;

        public Action1001(ActionGetter actionGetter)
            : base((short)1001, actionGetter)
        {

        }

        /// <summary>
        /// 客户端请求的参数较验
        /// </summary>
        /// <returns>false:中断后面的方式执行并返回Error</returns>
        public override bool GetUrlElement()
        {
            byte[] data = (byte[])actionGetter.GetMessage();
            if (data.Length >= 0)
            {
                requestPack = ProtoBufUtils.Deserialize<RequestHello1001Pack>(data);
                if (requestPack == null)
                {
                    return false;
                }
                return true;
            }
            return false;
        }

        /// <summary>
        /// 业务逻辑处理
        /// </summary>
        /// <returns>false:中断后面的方式执行并返回Error</returns>
        public override bool TakeAction()
        {
            responsePack = new ResponseHello1001Pack();
            return true;
        }

        /// <summary>
        /// 下发给客户的包结构数据
        /// </summary>
        protected override byte[] BuildResponsePack()
        {
            if (responsePack == null)
            {
                return null;
            }
            return ProtoBufUtils.Serialize(responsePack);
        }
    }
}
