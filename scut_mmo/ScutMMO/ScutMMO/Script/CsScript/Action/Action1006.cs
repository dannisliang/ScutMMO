using System;
using System.Collections.Generic;

using ZyGames.Framework.Cache.Generic;
using ZyGames.Framework.Common;
using ZyGames.Framework.Game.Contract;
using ZyGames.Framework.Game.Service;

using ZyGames.Framework.Common.Serialization;
using ZyGames.Framework.RPC.IO;
using ProtoBuf;
using ZyGames.Framework.Game.Sns;
using GameServer.Script.Model;
using GameServer.Script.Logic;

namespace GameServer.Script.CsScript.Action
{
    /// <summary>
    /// 1002_注册
    /// </summary>
    /// <remarks>继续BaseStruct类:不检查用户合法性请求;AuthorizeAction:有验证合法性</remarks>
    public class Action1006 : BaseAuthorizeAction
    {
        private ClientCharacterListRequest requestPack;
        private ClientCharacterListResponse responsePack;

        public Action1006(ActionGetter actionGetter)
            : base((short)ActionType.GetRoleList, actionGetter)
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
                requestPack = ProtoBufUtils.Deserialize<ClientCharacterListRequest>(data);
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
            responsePack = new ClientCharacterListResponse();
            var RoleCache = new PersonalCacheStruct<UserRole>();

            var RoleList = RoleCache.FindAll(Current.UserId.ToString());
            for (int i = 0; i < RoleList.Count; i++)
            {
                UserRole role = RoleList[i];
                CharacterDBSimpleInfo simpleInfo = new CharacterDBSimpleInfo();
                RoleManager.GetRoleSimpleInfo(role, simpleInfo);
                responsePack.charInfoList.Add(simpleInfo);
            }

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
