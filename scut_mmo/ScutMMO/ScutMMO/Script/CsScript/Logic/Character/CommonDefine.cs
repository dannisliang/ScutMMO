using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Logic
{
    public enum CreatureCommonAttr : int
    {
        C_NONE = 0,
        //策划配置的属性id
        //////////////////////////////////////////////////////////////////////////
        C_POWER,						//力量
        C_INTELLIGENCE,    				//智力
        C_AGILITY,         				//敏捷
        C_PHYSIQUE,        				//体质
        C_ENDURANCE,       				//耐力
        C_PRECISION,       				//精准
        C_MAX_HP,					    //最大生命值
        C_MAX_MP,       			    //最大魔法值
        C_AP,		   			        //物理攻击
        C_MAT, 		 			        //魔法攻击
        C_DP,		   			        //物理防御
        C_MDP, 		 			        //魔法防御
        C_HIT, 		 			        //命中
        C_DODGE,   	 			        //闪避
        C_CRIT,  	   			        //暴击
        C_TOUGHNESS,    			    //韧性
        C_CRIT_RATE,    			    //暴击倍率
        C_CRIT_EXTRADAMAGE,			    //暴击额外伤害
        C_CRIT_REDUCEDAMAGE,			//暴击额外免伤
        C_EXTRA_DAMAGE,					//额外伤害
        C_REDUCE_DAMAGE,				//额外免伤
        C_APDAMAGERATE,					//物理伤害率
        C_APREDUCEDAMAGERATE,			//物理免伤率
        C_FREEZERES,					//冰冻抗性
        C_BURNRES, 						//灼烧抗性
        C_WEAKRES, 						//虚弱抗性
        C_FASTINGRES,					//禁食抗性
        C_FUNKRES, 						//恐惧抗性
        C_RESTORE_HP,					//生命恢复
        C_RESTORE_MP,					//魔法恢复
        C_MSPEED,						//移动速度
        C_ASPEED,						//攻击速度
        //C_VIEW,							//视野
        C_MAX_ACCPOWER,					//蓄力值上限
        C_MATDAMAGERATE,				//魔法伤害率
        C_MATREDUCEDAMAGERATE,			//魔法免伤率
        C_HP,						    //当前生命值  
        C_MP,           			    //魔法值
        C_CUREADDITION,					//治疗加成
        C_CUREADDITIONBY,				//被治疗加成
        C_CUREEFFECT,					//治疗效果
        C_CUREEFFECTBY,					//被治疗效果
        C_SPEED_PERCENT,				//移动速度百分比

        //---
        C_FIGHT_POWER = 101,			//战斗力
        C_RACE,  						//种族
        C_PROF,  						//职业
        C_GENDER,						//性别
        C_VIP, 							//VIP等级
        C_EXP, 							//经验
        C_EXPMAX,						//经验上限
        C_GOLD,							//金币
        C_DIAMOND_BIND,					//绑定钻石
        C_DIAMOND,						//钻石
        C_LEVEL,   						//等级
        C_MARRIED, 						//婚姻(已婚、未婚)
        C_ENERGY,						//当前活力值
        C_UNION_ID,						//公会ID
        C_UNION_CONTRI,					//工会贡献
        C_UNION_SCORE,					//公会积分
        C_CAMP_ID,  					//阵营id
        C_CAMP_SCORE,					//阵营军功点
        C_CAMP_PRESTIGE,				//阵营声望
        C_ARENA_SCORE,					//竞技场积分
        C_CHARACTER_PRO = 200,
        //////////////////////////////////////////////////////////////////////////

        C_ATTR_POINT,					//属性点

        C_DIRECT,	   			        //直接伤害
        C_FREEZE,						//冰冻几率
        C_BRUN,  						//灼烧几率
        C_WEAK,  						//虚弱几率
        C_FASTING, 						//禁食几率
        C_FUNK,  						//恐惧几率
        C_RESTART_HP,					//死亡恢复
        C_SILENTRES,					//沉默抗性
        C_REFDAMAGE,					//减伤几率
        C_IMMUNITY,  					//免疫几率
        C_PABODY,						//霸体几率
        C_MIRACLE, 						//神迹几率
        C_LUCKY,						//幸运几率
        C_SLIENT,						//沉默几率






        //C_CAMP_LEV,  					//阵营等级

        //C_CAMP_KILLING,  				//本阵营杀戮值
        //C_HOSTILEKILLING,				//敌对阵营杀戮值
        //C_STAMINA, 						//体力
        //C_STAMINA_REPLY,				//体力恢复
        //C_MAX_STAMINA, 					//体力上限
        //C_ACCPOWER,  					//蓄力值



        //C_GOLD_BIND,					//绑定金币

        C_DUPLICATE_ID,					//副本ID
        C_OFFICIAL,						//官职
        C_KNIGHT,						//爵位


        C_TEAM_ID,						//队伍ID
        C_TEAM_LEADER_ID,				//队长ID
        C_ROOM_ID,						//房间ID
        C_ROOM_LEADER_ID,				//房主ID
        C_CLINET_END,

        //定义类似装备、技能等属性时注：
        //1.必须在此加入属性端区间，在区间内加入属性名对应的索引值
        //2.这里是外部属性索引值，所以必须对真正属性作用对象也添加对应的属性索引，在comProtocol里面加入
        //3.要在AttrMgr的初始化里面注册commonAttr与对应生物属性的映射关系
        //////////////////////////////////////////////////////////////////////////

        //******************属性公式需要用到的数值******************

        //******************公式属性数值类型******************
        C_VALUE_BEGIN,
        C_VALUE_POWER,							 //数值力量
        C_VALUE_INTELLIGENCE,      				 //数值智力
        C_VALUE_AGILITY,           				 //数值敏捷
        C_VALUE_PHYSIQUE,          				 //数值体质
        C_VALUE_ENDURANCE,         				 //数值耐力
        C_VALUE_PRECISION,         				 //数值精准
        C_VALUE_MAX_HP,		    				 //数值最大生命值
        C_VALUE_MAX_MP,            				 //数值最大魔法值
        C_VALUE_AP,			    				 //数值物理攻击
        C_VALUE_MAT, 		      				 //数值魔法攻击
        C_VALUE_DP,			    				 //数值物理防御
        C_VALUE_MDP, 		      	             //数值魔法防御
        C_VALUE_HIT, 		      	             //数值命中
        C_VALUE_DODGE,   	      	             //数值闪避
        C_VALUE_CRIT,  		    				 //数值暴击
        C_VALUE_TOUGHNESS,         				 //数值韧性
        C_VALUE_CRIT_EXTRADAMAGE,  				 //数值暴击额外伤害
        C_VALUE_CRIT_REDUCEDAMAGE, 				 //数值暴击额外免伤
        C_VALUE_EXTRA_DAMAGE,      				 //数值额外伤害
        C_VALUE_REDUCE_DAMAGE,     				 //数值额外免伤
        C_VALUE_END,
        //******************公式属性百分比类型*****数值*************
        C_PERCENT_BEGIN,
        C_PERCENT_POWER,						 //百分比力量
        C_PERCENT_INTELLIGENCE,     			 //百分比智力
        C_PERCENT_AGILITY,          			 //百分比敏捷
        C_PERCENT_PHYSIQUE,         			 //百分比体质
        C_PERCENT_ENDURANCE,        			 //百分比耐力
        C_PERCENT_PRECISION,        			 //百分比精准
        C_PERCENT_MAX_HP,		   			     //百分比最大生命值
        C_PERCENT_MAX_MP,           			 //百分比最大魔法值
        C_PERCENT_AP,		       				 //百分比物理攻击
        C_PERCENT_MAT, 		     			     //百分比魔法攻击
        C_PERCENT_DP,		       			     //百分比物理防御
        C_PERCENT_MDP, 		     			     //百分比魔法防御
        C_PERCENT_HIT, 		     			     //百分比命中
        C_PERCENT_DODGE,   	     			     //百分比闪避
        C_PERCENT_CRIT,  	       			     //百分比暴击
        C_PERCENT_TOUGHNESS,        			 //百分比韧性
        C_PERCENT_CRIT_EXTRADAMAGE, 			 //百分比暴击额外伤害
        C_PERCENT_CRIT_REDUCEDAMAGE,			 //百分比暴击额外免伤
        C_PERCENT_EXTRA_DAMAGE,     			 //百分比额外伤害
        C_PERCENT_REDUCE_DAMAGE,    			 //百分比额外免伤
        C_PERCENT_CUREEFFECTBY,     			 //百分比被治疗效果
        C_PERCENT_APDAMAGERATE,     			 //百分比物理伤害率
        C_PERCENT_MATDAMAGERATE,    			 //百分比魔法伤害率
        C_PERCENT_APREDUCEDAMAGERATE,			 //百分比物理免伤率
        C_PERCENT_MATREDUCEDAMAGERATE,			 //百分比魔法免伤率
        C_PERCENT_CRIT_RATE,					 //百分比暴击倍率
        C_PERCENT_CUREADDITION,   				 //百分比治疗加成
        C_PERCENT_CUREADDITIONBY, 				 //百分比被治疗加成
        C_PERCENT_END,

        //玩家属性点附加属性
        //////////////////////////////////////////////////////////////////////////
        C_ATTR_POINT_BEGIN,
        C_ATTR_POINT_POWER,         //属性点加成力量
        C_ATTR_POINT_INTELLIGENCE,  //属性点加成智力
        C_ATTR_POINT_AGILITY,       //属性点加成敏捷
        C_ATTR_POINT_PHYSIQUE,      //属性点加成体质
        C_ATTR_POINT_ENDURANCE,     //属性点加成耐力
        C_ATTR_POINT_PRECISION,     //属性点加成精准
        C_ATTR_POINT_ATTR_POINT_END,

        C_ADVANCED_ATTR_BEGIN,
        C_ADVANCED_ATTR_AP, 	  //一级属性影响物理攻击
        C_ADVANCED_ATTR_MAT,   	  //一级属性影响魔法攻击
        C_ADVANCED_ATTR_DP, 	  //一级属性影响物理防御
        C_ADVANCED_ATTR_MDP, 	  //一级属性影响魔法防御
        C_ADVANCED_ATTR_HIT, 	  //一级属性影响命中
        C_ADVANCED_ATTR_DODGE,   	  //一级属性影响闪避
        C_ADVANCED_ATTR_CRIT,   	  //一级属性影响暴击
        C_ADVANCED_ATTR_TOUGHNESS,   //一级属性影响韧性
        C_ADVANCED_ATTR_MP_MAX,       //一级属性影响魔法值
        C_ADVANCED_ATTR_HP_MAX,       //一级属性影响血量上限值
        C_ADVANCED_ATTR_END,
        //////////////////////////////////////////////////////////////////////////

        //装备
        //////////////////////////////////////////////////////////////////////////
        C_EQUIP_BEGIN,

        C_EQUIP_POWER,				//力量
        C_EQUIP_INTELLIGENCE,		//智力
        C_EQUIP_AGILITY,			//敏捷
        C_EQUIP_PHYSIQUE,			//体质
        C_EQUIP_ENDURANCE,			//耐力
        C_EQUIP_PRECISION,			//精准
        C_EQUIP_MAX_HP,				//最大生命值
        C_EQUIP_MAX_MP,				//最大魔法值
        C_EQUIP_AP,					//物理攻击
        C_EQUIP_MAT, 				//魔法攻击
        C_EQUIP_DP,					//物理防御
        C_EQUIP_MDP, 				//魔法防御
        C_EQUIP_HIT, 				//命中率
        C_EQUIP_DODGE,   			//闪避率
        C_EQUIP_CRIT,  				//暴击
        C_EQUIP_TOUGHNESS,			//韧性
        C_EQUIP_CRIT_RATE,			//暴击倍率
        C_EQUIP_CRIT_EXTRADAMAGE,	//暴击额外伤害
        C_EQUIP_CRIT_REDUCEDAMAGE,	//暴击额外免伤
        C_EQUIP_EXTRA_DAMAGE,		//额外伤害
        C_EQUIP_REDUCE_DAMAGE,		//额外免伤
        C_EQUIP_DAMAGE_RATE,		//暴击率
        C_EQUIP_FREEZERES,			//冰冻抗性
        C_EQUIP_BURNRES, 			//灼烧抗性
        C_EQUIP_WEAKRES, 			//虚弱抗性
        C_EQUIP_FASTINGRES,			//禁食抗性
        C_EQUIP_FUNKRES, 			//恐惧抗性
        C_EQUIP_APDAMAGERATE,		//物理伤害率
        C_EQUIP_MATDAMAGERATE,		//魔法伤害率
        C_EQUIP_APREDUCEDAMAGERATE,	//物理免伤率
        C_EQUIP_MATREDUCEDAMAGERATE,//魔法免伤
        C_EQUIP_END,
        //////////////////////////////////////////////////////////////////////////

        //等级
        //////////////////////////////////////////////////////////////////////////
        C_LEV_BEGIN,
        C_LEV_POWER,           //等级力量
        C_LEV_INTELLIGENCE,    //等级智力
        C_LEV_AGILITY,         //等级敏捷
        C_LEV_PHYSIQUE,        //等级体质
        C_LEV_ENDURANCE,       //等级耐力
        C_LEV_PRECISION,       //等级精准
        C_LEV_MAX_HP,	       //等级最大命值
        C_LEV_MAX_MP,          //等级最大法值
        C_LEV_AP,	           //等级物攻
        C_LEV_MAT, 	           //等级魔攻
        C_LEV_DP,	           //等级物防
        C_LEV_MDP, 	           //等级魔防御
        C_LEV_HIT, 		       //等级命中
        C_LEV_DODGE,   	       //等级闪避
        C_LEV_CRIT,  	       //等级暴击
        C_LEV_TOUGHNESS,       //等级韧性
        C_LEV_CRIT_RATE,       //等级暴击倍率
        C_LEV_LEV_END,
        //////////////////////////////////////////////////////////////////////////

        //******************技能配置表数据****************** 
        C_SKILL_FIX_BEGIN,
        C_SKILL_FIX_AP,       //技能物攻固定值
        C_SKILL_FIX_MAT,      //技能魔攻固定值
        C_SKILL_FIX_END,

        C_SKILL_PERCENT_BEGIN,
        C_SKILL_PERCENT_MAT,     //技能魔攻百分比
        C_SKILL_PERCENT_AP,      //技能物攻百分比
        C_SKILL_PERCENT_END,
        //************************************

        C_AUTO_POINT_BEGIN,
        C_AUTO_POINT_POWER,         //自动分配属性点加成力量
        C_AUTO_POINT_INTELLIGENCE,  //自动分配属性点加成智力
        C_AUTO_POINT_AGILITY,       //自动分配属性点加成敏捷
        C_AUTO_POINT_PHYSIQUE,      //自动分配属性点加成体质
        C_AUTO_POINT_ENDURANCE,     //自动分配属性点加成耐力
        C_AUTO_POINT_PRECISION,     //自动分配属性点加成精准
        C_AUTO_POINT,				//是否自动分配属性点
        C_AUTO_POINT_END,

        //******************buff公式属性固定值类型******************
        C_BUFF_FIX_BEGIN,
        C_BUFF_FIX_POWER,							 //固定值值力量
        C_BUFF_FIX_INTELLIGENCE,      				 //固定值智力
        C_BUFF_FIX_AGILITY,           				 //固定值敏捷
        C_BUFF_FIX_PHYSIQUE,          				 //固定值体质
        C_BUFF_FIX_ENDURANCE,         				 //固定值耐力
        C_BUFF_FIX_PRECISION,         				 //固定值精准
        C_BUFF_FIX_MAX_HP,		    				 //固定值最大生命值
        C_BUFF_FIX_MAX_MP,            				 //固定值最大魔法值
        C_BUFF_FIX_AP,			    				 //固定值物理攻击
        C_BUFF_FIX_MAT, 		      				 //固定值魔法攻击
        C_BUFF_FIX_DP,			    				 //固定值物理防御
        C_BUFF_FIX_MDP, 		      	             //固定值魔法防御
        C_BUFF_FIX_HIT, 		      	             //固定值命中
        C_BUFF_FIX_DODGE,   	      	             //固定值闪避
        C_BUFF_FIX_CRIT,  		    				 //固定值暴击
        C_BUFF_FIX_TOUGHNESS,         				 //固定值韧性
        C_BUFF_FIX_CRIT_EXTRADAMAGE,  				 //固定值暴击额外伤害
        C_BUFF_FIX_CRIT_REDUCEDAMAGE, 				 //固定值暴击额外免伤
        C_BUFF_FIX_EXTRA_DAMAGE,      				 //固定值额外伤害
        C_BUFF_FIX_REDUCE_DAMAGE,     				 //固定值额外免伤
        C_BUFF_FIX_END,
        //******************buff公式属性百分比类型******************
        C_BUFF_PERCENT_BEGIN,
        C_BUFF_PERCENT_POWER,						 //百分比力量
        C_BUFF_PERCENT_INTELLIGENCE,     			 //百分比智力
        C_BUFF_PERCENT_AGILITY,          			 //百分比敏捷
        C_BUFF_PERCENT_PHYSIQUE,         			 //百分比体质
        C_BUFF_PERCENT_ENDURANCE,        			 //百分比耐力
        C_BUFF_PERCENT_PRECISION,        			 //百分比精准
        C_BUFF_PERCENT_MAX_HP,		   			     //百分比最大生命值
        C_BUFF_PERCENT_MAX_MP,           			 //百分比最大魔法值
        C_BUFF_PERCENT_AP,		       				 //百分比物理攻击
        C_BUFF_PERCENT_MAT, 		     			 //百分比魔法攻击
        C_BUFF_PERCENT_DP,		       			     //百分比物理防御
        C_BUFF_PERCENT_MDP, 		     		     //百分比魔法防御
        C_BUFF_PERCENT_HIT, 		     		     //百分比命中
        C_BUFF_PERCENT_DODGE,   	     			 //百分比闪避
        C_BUFF_PERCENT_CRIT,  	       			     //百分比暴击
        C_BUFF_PERCENT_TOUGHNESS,        			 //百分比韧性
        C_BUFF_PERCENT_CRIT_EXTRADAMAGE, 			 //百分比暴击额外伤害
        C_BUFF_PERCENT_CRIT_REDUCEDAMAGE,			 //百分比暴击额外免伤
        C_BUFF_PERCENT_EXTRA_DAMAGE,     			 //百分比额外伤害
        C_BUFF_PERCENT_REDUCE_DAMAGE,    			 //百分比额外免伤
        C_BUFF_PERCENT_CUREEFFECTBY,     			 //百分比被治疗效果
        C_BUFF_PERCENT_APDAMAGERATE,     			 //百分比物理伤害率
        C_BUFF_PERCENT_MATDAMAGERATE,    			 //百分比魔法伤害率
        C_BUFF_PERCENT_APREDUCEDAMAGERATE,			 //百分比物理免伤率
        C_BUFF_PERCENT_MATREDUCEDAMAGERATE,			 //百分比魔法免伤率
        C_BUFF_PERCENT_CRIT_RATE,					 //百分比暴击倍率
        C_BUFF_PERCENT_CUREADDITION,   				 //百分比治疗加成
        C_BUFF_PERCENT_CUREADDITIONBY, 				 //百分比被治疗加成
        C_BUFF_PERCENT_END,

        //******************公式属性固定值类型******************
        C_FIX_BEGIN,
        C_FIX_POWER,							 //固定值力量
        C_FIX_INTELLIGENCE,      				 //固定值智力
        C_FIX_AGILITY,           				 //固定值敏捷
        C_FIX_PHYSIQUE,          				 //固定值体质
        C_FIX_ENDURANCE,         				 //固定值耐力
        C_FIX_PRECISION,         				 //固定值精准
        C_FIX_MAX_HP,		    				 //固定值最大生命值
        C_FIX_MAX_MP,            				 //固定值最大魔法值
        C_FIX_AP,			    				 //固定值物理攻击
        C_FIX_MAT, 		      					 //固定值魔法攻击
        C_FIX_DP,			    				 //固定值物理防御
        C_FIX_MDP, 		      					 //固定值魔法防御
        C_FIX_HIT, 		      					 //固定值命中
        C_FIX_DODGE,   	      					 //固定值闪避
        C_FIX_CRIT,  		    				 //固定值暴击
        C_FIX_TOUGHNESS,         				 //固定值韧性
        C_FIX_CRIT_EXTRADAMAGE,  				 //固定值暴击额外伤害
        C_FIX_CRIT_REDUCEDAMAGE, 				 //固定值暴击额外免伤
        C_FIX_EXTRA_DAMAGE,      				 //固定值额外伤害
        C_FIX_REDUCE_DAMAGE,     				 //固定值额外免伤
        C_FIX_END,
        C_MAX
    };

    public enum CreatureTypeEnum : uint
    {
        CREATURE_NONE = 0,
        CREATURE_PLAYER,    //玩家类型
        CREATURE_MONSTER,   //玩家类型
        CREATURE_NPC,		//NPC类型
        CREATURE_DROP,		//掉落类型
        CREATURE_SUMMON,	//召唤物
        CREATURE_HERBS,		//草药类型
        CREATURE_MINE,		//矿石类型
        CREATURE_FISH,		//渔类型
        CREATURE_MAX
    };

    public enum MonsterFightType
    {
        ENUM_MONSTER_FIGHT_TYPE_NO_ATTACK = 1,		//不攻击 沙包怪
        ENUM_MONSTER_FIGHT_TYPE_ATTACK_AFTER_ATTACK = 2, //受攻击后攻击 被动怪
        ENUM_MONSTER_FIGHT_TYPE_ACTIVE_ATTACK = 3, //主动怪
    };

    public enum MonsterType
    {
        ENUM_MONSTER_TYPE_LITTLE_MONSTER = 1, //小怪
        ENUM_MONSTER_TYPE_BIG_MONSTER = 2, //精英
        ENUM_MONSTER_TYPE_BOSS_MONSTER = 3, //boss
        ENUM_MONSTER_TYPE_BOSS_TA = 4, //塔
    };

    public enum MonsterAttackType
    {
        ENUM_MONSTER_TYPE_ATTACK_TYPE_MELEE = 1, //近战
        ENUM_MONSTER_TYPE_ATTACK_TYPE_RANGED = 2, //远程
        ENUM_MONSTER_TYPE_ATTACK_TYPE_MIX = 3, //混合
    };

    public enum MonsterCfgType
    {
        ENUM_MONSTER_CFG_TYPE_FIELD = 1, //野外怪
        ENUM_MONSTER_CFG_TYPE_COPY_SCENE = 2, //副本
    };

    public enum MonsterViewType
    {
        ENUM_MONSTER_VIEW_TYPE_CIRCLE = 1, //圆形
        ENUM_MONSTER_VIEW_TYPE_SECTOR = 2, //扇形
        ENUM_MONSTER_VIEW_TYPE_BALL = 3, //球形
    };

    public enum MonsterPatrolType
    {
        ENUM_MONSTER_PATROL_TYPE_ROUND_TRIP = 1, //往返巡逻
        ENUM_MONSTER_PATROL_TYPE_LOOP_TRIP = 2, //循环巡逻
        ENUM_MONSTER_PATROL_TYPE_ONE_WAY_TRIP = 3, //一次性巡逻
    };

    public enum ViewLayerType
    {
        ENUM_NINE_GRID_LITTLE = 1, //最初的九格宫 怪物用
        ENUM_NINE_GRID_MIDDLE = 2, //比上面大一圈 
        ENUM_NINE_GRID_BIGGER = 3,//比上面大一圈
    };

    public static class CommonDefine
    {

    }
}
