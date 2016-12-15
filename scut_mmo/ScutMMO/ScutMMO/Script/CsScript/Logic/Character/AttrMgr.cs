using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using ProtoBuf;

namespace GameServer.Script.Logic
{
    //外部使用的公有属性枚举列表


    public static class AttrMgr
    {
        private static uint[] m_CommonAttrToPlayerAttr = new uint[(int)CreatureCommonAttr.C_MAX];
        private static uint[] m_CommonAttrToMonsterAttr = new uint[(int)MonsterAttr.M_MAX];

        public static bool Init()
        {
            InitPlayerAttr();
            InitMonsterAttr();
            return true;
        }

        private static void InitPlayerAttr()
        {
            InitPlayerBaseAttr();
        }

        private static void InitMonsterAttr()
        {
            InitMonsterBaseAttr();
        }

        private static void InitPlayerBaseAttr()
        {
            //注册公共属性与玩家属性id映射关系
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_POWER] = (int)PlayerAttr.P_POWER;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_INTELLIGENCE] = (int)PlayerAttr.P_INTELLIGENCE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_AGILITY] = (int)PlayerAttr.P_AGILITY;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_PHYSIQUE] = (int)PlayerAttr.P_PHYSIQUE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_ENDURANCE] = (int)PlayerAttr.P_ENDURANCE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_PRECISION] = (int)PlayerAttr.P_PRECISION;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_RACE] = (int)PlayerAttr.P_RACE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_PROF] = (int)PlayerAttr.P_PROF;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_GENDER] = (int)PlayerAttr.P_GENDER;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_LEVEL] = (int)PlayerAttr.P_LEVEL;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_VIP] = (int)PlayerAttr.P_VIP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_EXP] = (int)PlayerAttr.P_EXP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_GOLD] = (int)PlayerAttr.P_GOLD;
            //m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_GOLD_BIND]		 = (int)PlayerAttr.P_GOLD_BIND;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_DIAMOND] = (int)PlayerAttr.P_DIAMOND;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_DIAMOND_BIND] = (int)PlayerAttr.P_DIAMOND_BIND;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_CAMP_ID] = (int)PlayerAttr.P_CAMP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_OFFICIAL] = (int)PlayerAttr.P_OFFICIAL;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_KNIGHT] = (int)PlayerAttr.P_KNIGHT;
            //m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_CAM(int)PlayerAttr.P_LEV]		 = (int)PlayerAttr.P_CAM(int)PlayerAttr.P_LEV;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_UNION_CONTRI] = (int)PlayerAttr.P_UNION_CONTRI;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_ENERGY] = (int)PlayerAttr.P_ENERGY;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_TEAM_ID] = (int)PlayerAttr.P_TEAM_ID;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_TEAM_LEADER_ID] = (int)PlayerAttr.P_TEAM_LEADER_ID;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_ROOM_ID] = (int)PlayerAttr.P_ROOM_ID;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_ROOM_LEADER_ID] = (int)PlayerAttr.P_ROOM_LEADER_ID;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MARRIED] = (int)PlayerAttr.P_MARRIED;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_HP] = (int)PlayerAttr.P_HP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MAX_HP] = (int)PlayerAttr.P_MAX_HP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_AP] = (int)PlayerAttr.P_AP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MAT] = (int)PlayerAttr.P_MAT;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_DP] = (int)PlayerAttr.P_DP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MDP] = (int)PlayerAttr.P_MDP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_HIT] = (int)PlayerAttr.P_HIT;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_DODGE] = (int)PlayerAttr.P_DODGE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_CRIT] = (int)PlayerAttr.P_CRIT;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_CRIT_RATE] = (int)PlayerAttr.P_CRIT_RATE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_DIRECT] = (int)PlayerAttr.P_DIRECT;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_RESTORE_HP] = (int)PlayerAttr.P_RESTORE_HP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_RESTART_HP] = (int)PlayerAttr.P_RESTART_HP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_ASPEED] = (int)PlayerAttr.P_ASPEED;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MSPEED] = (int)PlayerAttr.P_MSPEED;
            //m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_CAM(int)PlayerAttr.P_KILLING]	 = (int)PlayerAttr.P_CAM(int)PlayerAttr.P_KILLING;
            //m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_HOSTILEKILLING] = (int)PlayerAttr.P_HOSTILEKILLING;
            //m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_STAMINA]		 = (int)PlayerAttr.P_STAMINA;
            //m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_STAMINA_REPLY]	 = (int)PlayerAttr.P_STAMINA_REPLY;
            //m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MAX_STAMINA]	 = (int)PlayerAttr.P_MAX_STAMINA;
            //m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_ACCPOWER]		 = (int)PlayerAttr.P_ACCPOWER;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MAX_ACCPOWER] = (int)PlayerAttr.P_MAX_ACCPOWER;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_FREEZE] = (int)PlayerAttr.P_FREEZE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_BRUN] = (int)PlayerAttr.P_BRUN;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_WEAK] = (int)PlayerAttr.P_WEAK;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_FASTING] = (int)PlayerAttr.P_FASTING;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_FUNK] = (int)PlayerAttr.P_FUNK;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_REFDAMAGE] = (int)PlayerAttr.P_REFDAMAGE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_IMMUNITY] = (int)PlayerAttr.P_IMMUNITY;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_PABODY] = (int)PlayerAttr.P_PABODY;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MIRACLE] = (int)PlayerAttr.P_MIRACLE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_LUCKY] = (int)PlayerAttr.P_LUCKY;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_FREEZERES] = (int)PlayerAttr.P_FREEZERES;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_BURNRES] = (int)PlayerAttr.P_BURNRES;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_WEAKRES] = (int)PlayerAttr.P_WEAKRES;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_FASTINGRES] = (int)PlayerAttr.P_FASTINGRES;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_FUNKRES] = (int)PlayerAttr.P_FUNKRES;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_ATTR_POINT] = (int)PlayerAttr.P_ATTR_POINT;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_DUPLICATE_ID] = (int)PlayerAttr.P_DUPLICATE_ID;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_APDAMAGERATE] = (int)PlayerAttr.P_APDAMAGERATE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MATDAMAGERATE] = (int)PlayerAttr.P_MATDAMAGERATE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_APREDUCEDAMAGERATE] = (int)PlayerAttr.P_APREDUCEDAMAGERATE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MATREDUCEDAMAGERATE] = (int)PlayerAttr.P_MATREDUCEDAMAGERATE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_CUREADDITION] = (int)PlayerAttr.P_CUREADDITION;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_CUREEFFECT] = (int)PlayerAttr.P_CUREEFFECT;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MP] = (int)PlayerAttr.P_MP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_MAX_MP] = (int)PlayerAttr.P_MAX_MP;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_FIGHT_POWER] = (int)PlayerAttr.P_FIGHT_POWER;

            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_AUTO_POINT] = (int)PlayerAttr.P_AUTO_POINT;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_AUTO_POINT_POWER] = (int)PlayerAttr.P_AUTO_POINT_POWER;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_AUTO_POINT_INTELLIGENCE] = (int)PlayerAttr.P_AUTO_POINT_INTELLIGENCE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_AUTO_POINT_AGILITY] = (int)PlayerAttr.P_AUTO_POINT_AGILITY;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_AUTO_POINT_PHYSIQUE] = (int)PlayerAttr.P_AUTO_POINT_PHYSIQUE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_AUTO_POINT_ENDURANCE] = (int)PlayerAttr.P_AUTO_POINT_ENDURANCE;
            m_CommonAttrToPlayerAttr[(int)CreatureCommonAttr.C_AUTO_POINT_PRECISION] = (int)PlayerAttr.P_AUTO_POINT_PRECISION;
        }

        private static void InitMonsterBaseAttr()
        {
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_HP] = (int)MonsterAttr.M_HP;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_MAX_HP] = (int)MonsterAttr.M_MAX_HP;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_MP] = (int)MonsterAttr.M_MP;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_MAX_MP] = (int)MonsterAttr.M_MAX_MP;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_AP] = (int)MonsterAttr.M_AP;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_MAT] = (int)MonsterAttr.M_MAT;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_DP] = (int)MonsterAttr.M_DP;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_MDP] = (int)MonsterAttr.M_MDP;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_HIT] = (int)MonsterAttr.M_HIT;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_DODGE] = (int)MonsterAttr.M_DODGE;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_CRIT] = (int)MonsterAttr.M_CRIT;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_TOUGHNESS] = (int)MonsterAttr.M_TOUGHNESS;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_CRIT_RATE] = (int)MonsterAttr.M_CRIT_RATE;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_CRIT_EXTRADAMAGE] = (int)MonsterAttr.M_CRIT_EXTRADAMAGE;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_CRIT_REDUCEDAMAGE] = (int)MonsterAttr.M_CRIT_REDUCEDAMAGE;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_EXTRA_DAMAGE] = (int)MonsterAttr.M_EXTRA_DAMAGE;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_REDUCE_DAMAGE] = (int)MonsterAttr.M_REDUCE_DAMAGE;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_FREEZERES] = (int)MonsterAttr.M_FREEZERES;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_BURNRES] = (int)MonsterAttr.M_BURNRES;

            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_WEAKRES] = (int)MonsterAttr.M_WEAKRES;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_FASTINGRES] = (int)MonsterAttr.M_FASTINGRES;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_FUNKRES] = (int)MonsterAttr.M_FUNKRES;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_MSPEED] = (int)MonsterAttr.M_MSPEED;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_ASPEED] = (int)MonsterAttr.M_ASPEED;

            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_CUREADDITION] = (int)MonsterAttr.M_CUREADDITION;
            m_CommonAttrToMonsterAttr[(int)CreatureCommonAttr.C_CUREEFFECT] = (int)MonsterAttr.M_CUREEFFECT;
        }

        	//******************属性外部调用接口******************
	//玩家
	    public static PlayerAttr GetPlayerAttr(CreatureCommonAttr attrType)
        {
            if ((int)attrType <= (int)CreatureCommonAttr.C_NONE || (int)attrType >= (int)CreatureCommonAttr.C_MAX)
            {
                return PlayerAttr.P_NONE;
            }

            return (PlayerAttr)m_CommonAttrToPlayerAttr[(int)attrType];
        }

        public static MonsterAttr GetMonsterAttr(CreatureCommonAttr attrType)
        {
            if ((int)attrType <= (int)CreatureCommonAttr.C_NONE || (int)attrType >= (int)CreatureCommonAttr.C_MAX)
            {
                return MonsterAttr.M_NONE;
            }

            return (MonsterAttr)m_CommonAttrToMonsterAttr[(int)attrType];
        }
    }
}
