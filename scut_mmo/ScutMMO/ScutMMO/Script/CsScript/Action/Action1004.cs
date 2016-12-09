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

using ZyGames.Framework.Common;

using ZyGames.Framework.Common.Serialization;
using ZyGames.Framework.RPC.IO;
using ProtoBuf;
using ZyGames.Framework.Model;


namespace GameServer.Script.CsScript.Action
{

    public class Action1004 : LoginExtendActionProtoBuf
    {
        /// <summary>
        /// 授权凭证
        /// </summary>
        private string _token;

        /// <summary>
        /// 末填写则默认为1.0版本
        /// </summary>
        //private string _clientAppVersion = "1.0";

        public Action1004(ActionGetter actionGetter)
            : base((short)ActionType.Login, actionGetter)
        {

        }

        protected override bool DoSuccess(int userId, out IUser user)
        {
            user = null;
            var userCache = new PersonalCacheStruct<GameUser>();
            GameUser gameUser;
            if (userCache.TryFindKey(UserId.ToString(), out gameUser) == LoadingStatus.Success)
            {
                if (gameUser == null)
                {
                    gameUser = new GameUser
                    {
                        UserId = userId,
                        PassportId = PassportId,
                        RetailId = RetailID,
                        SId = Current.SessionId,
                        NickName = NickName
                    };
                    userCache.Add(gameUser);
                }
            }

            user = new SessionUser(gameUser);

            return true;
        }

        /// <summary>
        /// 处理结束执行
        /// </summary>
        public override void TakeActionAffter(bool state)
        {
            if (state)
            {
                responsePack = new ResponseLogin1004Pack();
                responsePack.SessionID = Current.SessionId;
                responsePack.UserID = Current.UserId.ToNotNullString();
                responsePack.UserType = UserType;
                responsePack.RefreshToken = RefeshToken;
            }
        }

        protected override void DoLoginFail(ILogin login)
        {
            ErrorCode = Language.Instance.ErrorCode;
            ErrorInfo = Language.Instance.ServerBusy;
        }
    }
}
