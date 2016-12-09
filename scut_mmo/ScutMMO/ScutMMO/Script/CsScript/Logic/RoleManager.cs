using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using GameServer.Script.Model;
using ProtoBuf;

namespace GameServer.Script.Logic
{
    public class RoleManager
    {
        public static int RoleIdParam = 100000000;

        private static RoleManager _Instance;

        public static RoleManager Instance()
        {
            if (_Instance == null)
            {
                _Instance = new RoleManager();
            }
            return _Instance;
        }


        protected RoleManager()
        {

        }

        public static RoleExpConfig GetRoleExpCfg(int level)
        {
            return ConfigMgr.GetRoleExpCfg(level);
        }

        public static RoleBornConfig GetRoleBornCfg(int sex, int prof)
        {
            foreach (KeyValuePair<int, RoleBornConfig> roleBorn in ConfigMgr.Inst().RoleBorn.configs)
            {
                RoleBornConfig config = roleBorn.Value;
                if (config.professionID == prof && config.gender == sex)
                {
                    return config;
                }
            }
            return null;
        }

        public static void GetRoleSimpleInfo(UserRole role, CharacterDBSimpleInfo charSimpleInfo)
        {
            if (charSimpleInfo == null || role == null)
            {
                return;
            }

            charSimpleInfo.charId = (uint)role.RoleId;
            charSimpleInfo.name = role.Name;
            charSimpleInfo.sex = (uint)role.Sex;
            charSimpleInfo.prof = (uint)role.Prof;
            charSimpleInfo.level = (uint)role.Level;
            charSimpleInfo.race = (uint)role.Race;
            charSimpleInfo.exp = (uint)role.Exp;
            charSimpleInfo.hp = (uint)role.Hp;
            charSimpleInfo.fightPower =(uint)role.FightPower;
            charSimpleInfo.official = role.Official;
            charSimpleInfo.knight = role.Knight;
            charSimpleInfo.camp = role.Camp;
        }

        public static UserRole CreateRole(int userId, int roleId, string name, int sex, int prof)
        {
            RoleBornConfig bornConfig = GetRoleBornCfg(sex,prof);
            if (bornConfig == null)
            {
                return null;
            }

            UserRole role = new UserRole();

            role.RoleId = roleId;
            role.UserId = userId;
            role.Name = name;
            role.Sex = sex;
            role.Prof = prof;
            role.Level = bornConfig.bornLevel;
            role.Exp = 0;
            role.Hp = 100;
            role.FightPower = 1;
            role.Gold = bornConfig.gold;
            role.BindGold = bornConfig.bindGold;
            role.Diamond = bornConfig.diamond;
            role.BindDiamond = bornConfig.bindDiamond;
            role.Race = bornConfig.race;

            role.EnterSceneId = bornConfig.mapID;
            role.EnterMapId = bornConfig.mapID;

            role.EnterPosX = bornConfig.mapX/1000.0f;
            role.EnterPosY = bornConfig.mapY / 1000.0f;
            role.EnterPosZ = bornConfig.mapZ / 1000.0f;

            role.LastSceneId = bornConfig.mapID;
            role.LastMapId = bornConfig.mapID;

            role.LastPosX = bornConfig.mapX / 1000.0f;
            role.LastPosY = bornConfig.mapY / 1000.0f;
            role.LastPosZ = bornConfig.mapZ / 1000.0f;

            RoleExpConfig expConfig = GetRoleExpCfg(bornConfig.bornLevel);
            if (expConfig == null)
            {
                return null;
            }

            role.Stamina = expConfig.stamina;

            return role;
        }
    }
}
