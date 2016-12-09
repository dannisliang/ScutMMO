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
    public class Action1005 : BaseAuthorizeAction
    {
        private ClientCreateCharacterRequest requestPack;
        private ClientCreateCharacterResponse responsePack;

        public Action1005(ActionGetter actionGetter)
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
                requestPack = ProtoBufUtils.Deserialize<ClientCreateCharacterRequest>(data);
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
            responsePack = new ClientCreateCharacterResponse();

            int userId = Current.UserId;
            string name = requestPack.name;
            int sex = (int)requestPack.sex;
            int prof = (int)requestPack.prof;

            if (name.Length < (int)CharacterDefine.CHARACTER_NAME_MIN_LENGTH 
                || name.Length > (int)CharacterDefine.CHARACTER_NAME_MAX_LENGTH)
            {
                responsePack.result = (uint)ClientCreateCharacterResponse.RESULT.CREATE_CHARACTER_RESULT_NAME_LENGTH;
                return true;
            }

            var UserCache = new PersonalCacheStruct<GameUser>();
            var RoleCache = new PersonalCacheStruct<UserRole>();

            GameUser gameUser = UserCache.FindKey(userId.ToString());
            if (gameUser == null)
            {
                responsePack.result = (uint)ClientCreateCharacterResponse.RESULT.CREATE_CHARACTER_RESULT_FAIL;
                return true;
            }

            var RoleList = RoleCache.FindAll(userId.ToString());
            if (RoleList.Count > (int)CharacterDefine.MAX_CREATE_CHARACTER_COUNT)
            {
                responsePack.result = (uint)ClientCreateCharacterResponse.RESULT.CREATE_CHARACTER_RESULT_MAX_COUNT;
                return true;
            }

            var SameNameRole = RoleList.Find(_role => _role.Name == name);
            if (SameNameRole != null)
            {
                responsePack.result = (uint)ERetCode.RET_LOGIN_CHARACTER_NAME_EXISTS;
                return true;
            }

            int roleId = 0;
            if (gameUser.MaxRoleId == 0)
            {
                roleId = userId * RoleManager.RoleIdParam;
                gameUser.MaxRoleId = roleId;
            }
            else
            {
                roleId = gameUser.MaxRoleId + 1;
                gameUser.MaxRoleId = roleId;
            }
            
            UserRole role = RoleManager.CreateRole(userId, roleId, name, sex, prof);
            if (role == null)
            {
                responsePack.result = (uint)ClientCreateCharacterResponse.RESULT.CREATE_CHARACTER_RESULT_FAIL;
                return false;
            }

            RoleCache.Add(role);
            RoleCache.Update();

            {
                responsePack.result = (uint)ClientCreateCharacterResponse.RESULT.CREATE_CHARACTER_RESULT_SUCCESS;
                CharacterDBSimpleInfo dbSimpleInfo = new CharacterDBSimpleInfo();
                RoleManager.GetRoleSimpleInfo(role, dbSimpleInfo);
                responsePack.newCharacterInfo = dbSimpleInfo;
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

