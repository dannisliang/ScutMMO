#pragma once

#include "ComTypeDefine.h"

////////////////////////////////////AttributeSuppress//////////////////////////////////////



struct AttributeSuppressCfgInfo
{
	int32_t   maxLvlDiff; //等级差  
	int32_t   critSuppress; //暴击压制率  
	int32_t   stateSuppress; //状态压制率  
	int32_t   hitSuppress; //命中压制率  

	AttributeSuppressCfgInfo()
	{
		maxLvlDiff = 0;
		critSuppress = 0;
		stateSuppress = 0;
		hitSuppress = 0;

	}
};

typedef unordered_map<int32_t, AttributeSuppressCfgInfo> AttributeSuppressCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////AttributeConvert//////////////////////////////////////

struct AttributeConvertAttributeCfgInfo
{
	int32_t   Type; //ID  
	int32_t   Value; //值  

	AttributeConvertAttributeCfgInfo()
	{
		Type = 0;
		Value = 0;

	}
};
//
typedef vector<AttributeConvertAttributeCfgInfo> VecAttributeConvertAttributeCfg;


struct AttributeConvertCfgInfo
{
	int32_t   attribute_Id; //属性ID  
	VecAttributeConvertAttributeCfg   vecAttributeConvertAttributeCfg; //属性  
	int32_t   constantID; //配置ID  
	int32_t   professionID; //职业ID  

	AttributeConvertCfgInfo()
	{
		attribute_Id = 0;
		vecAttributeConvertAttributeCfg.clear();
		constantID = 0;
		professionID = 0;

	}
};

typedef unordered_map<int32_t, AttributeConvertCfgInfo> AttributeConvertCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////PkmodePkWanted//////////////////////////////////////



struct PkmodePkWantedCfgInfo
{
	int32_t   pkRewardNum; //悬赏令数量  
	int32_t   bodyEquipMax; //此玩家死亡后身上装备掉落最大数量  
	int32_t   minPKNum; //最小PK值  
	int32_t   bodyEquipMin; //此玩家死亡后身上装备掉落最小数量  
	int32_t   killPkAdd; //杀死此玩家时获得PK值  
	int32_t   bagPropMin; //此玩家死亡后背包物品掉落最少数量  
	int32_t   bagPropLose; //此玩家死亡后背包物品掉落几率  
	int32_t   pkRewardId; //悬赏令ID  
	int32_t   bodyEquipLose; //此玩家死亡后身上装备掉落几率  
	int32_t   wanteLeveldId; //通缉等级ID  
	int32_t   bagPropMax; //此玩家死亡后背包物品掉落最大数量  
	int32_t   maxPKNum; //最大PK值  

	PkmodePkWantedCfgInfo()
	{
		pkRewardNum = 0;
		bodyEquipMax = 0;
		minPKNum = 0;
		bodyEquipMin = 0;
		killPkAdd = 0;
		bagPropMin = 0;
		bagPropLose = 0;
		pkRewardId = 0;
		bodyEquipLose = 0;
		wanteLeveldId = 0;
		bagPropMax = 0;
		maxPKNum = 0;

	}
};

typedef unordered_map<int32_t, PkmodePkWantedCfgInfo> PkmodePkWantedCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////AvocationAvocationskill//////////////////////////////////////



struct AvocationAvocationskillCfgInfo
{
	int32_t   level; //等级  
	string   openCreateList; //开启制造列表  
	int32_t   id; //id  
	int32_t   classification; //分类  
	int32_t   type; //类型  
	int32_t   exp; //经验值  
	int32_t   needMoney; //消耗金币数量  

	AvocationAvocationskillCfgInfo()
	{
		level = 0;
		openCreateList = "";
		id = 0;
		classification = 0;
		type = 0;
		exp = 0;
		needMoney = 0;

	}
};

typedef unordered_map<int32_t, AvocationAvocationskillCfgInfo> AvocationAvocationskillCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////AvocationCompose//////////////////////////////////////

struct AvocationComposeNewItemCfgInfo
{
	int32_t   Id; //ID  
	int32_t   Rate; //几率  

	AvocationComposeNewItemCfgInfo()
	{
		Id = 0;
		Rate = 0;

	}
};
//
typedef vector<AvocationComposeNewItemCfgInfo> VecAvocationComposeNewItemCfg;
struct AvocationComposeNeedMaterialCfgInfo
{
	int32_t   Num; //数量  
	int32_t   Id; //id  

	AvocationComposeNeedMaterialCfgInfo()
	{
		Num = 0;
		Id = 0;

	}
};
//
typedef vector<AvocationComposeNeedMaterialCfgInfo> VecAvocationComposeNeedMaterialCfg;
struct AvocationComposeConsumeReelCfgInfo
{
	int32_t   Id; //ID  

	AvocationComposeConsumeReelCfgInfo()
	{
		Id = 0;

	}
};
//
typedef vector<AvocationComposeConsumeReelCfgInfo> VecAvocationComposeConsumeReelCfg;


struct AvocationComposeCfgInfo
{
	VecAvocationComposeNewItemCfg   vecAvocationComposeNewItemCfg; //合成物  
	int32_t   id; //制造id  
	int32_t   consumeRandomReel_Id; //随机卷轴ID  
	VecAvocationComposeNeedMaterialCfg   vecAvocationComposeNeedMaterialCfg; //需要材料  
	int32_t   creatList; //所在制造列表  
	int32_t   type; //类型  
	VecAvocationComposeConsumeReelCfg   vecAvocationComposeConsumeReelCfg; //卷轴  
	int32_t   sonType; //子类型  
	int32_t   jobList; //职业列表  
	int32_t   isName; //是否铭刻  
	int32_t   linkId; //关联id  
	int32_t   needMoney; //需要金币  

	AvocationComposeCfgInfo()
	{
		vecAvocationComposeNewItemCfg.clear();
		id = 0;
		consumeRandomReel_Id = 0;
		vecAvocationComposeNeedMaterialCfg.clear();
		creatList = 0;
		type = 0;
		vecAvocationComposeConsumeReelCfg.clear();
		sonType = 0;
		jobList = 0;
		isName = 0;
		linkId = 0;
		needMoney = 0;

	}
};

typedef unordered_map<int32_t, AvocationComposeCfgInfo> AvocationComposeCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////DropDrop//////////////////////////////////////

struct DropDropItemCfgInfo
{
	int32_t   maxNum; //最大数量  
	int32_t   id; //id  
	int32_t   rand; //概率  

	DropDropItemCfgInfo()
	{
		maxNum = 0;
		id = 0;
		rand = 0;

	}
};
//
typedef vector<DropDropItemCfgInfo> VecDropDropItemCfg;


struct DropDropCfgInfo
{
	int32_t   goldup; //总金币数量上限  
	int32_t   goldlow; //总金币数量下限  
	int32_t   id; //掉落包ID  
	VecDropDropItemCfg   vecDropDropItemCfg; //掉落物品  
	int32_t   gold_heap; //金币掉落堆数  
	int32_t   gold_rand; //金币掉落概率  

	DropDropCfgInfo()
	{
		goldup = 0;
		goldlow = 0;
		id = 0;
		vecDropDropItemCfg.clear();
		gold_heap = 0;
		gold_rand = 0;

	}
};

typedef unordered_map<int32_t, DropDropCfgInfo> DropDropCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////MapMap//////////////////////////////////////



struct MapMapCfgInfo
{
	int32_t   canSupply; //是否可喝药  
	int32_t   mapPk; //PK规则  
	int32_t   mapHeight; //地图高度  
	string   monsterRoad; //怪物寻路点层  
	int32_t   isDirectRevive; //是否允许原地复活  
	int32_t   resMonster; //怪物资源层  
	int32_t   mapId; //地图id  
	string   mapResources; //地图资源  
	int32_t   useShoes; //是否可使用飞鞋传送  
	int32_t   mapType; //地图类型  
	int32_t   deadPunish; //是否有死亡掉落装备物品  
	int32_t   openRace; //地图进入种族限制  
	int32_t   openLv; //地图进入等级  
	int32_t   mapSubType; //地图子类型  
	int32_t   mapWide; //地图宽度  
	int32_t   openVip; //地图进入需VIP等级  

	MapMapCfgInfo()
	{
		canSupply = 0;
		mapPk = 0;
		mapHeight = 0;
		monsterRoad = "";
		isDirectRevive = 0;
		resMonster = 0;
		mapId = 0;
		mapResources = "";
		useShoes = 0;
		mapType = 0;
		deadPunish = 0;
		openRace = 0;
		openLv = 0;
		mapSubType = 0;
		mapWide = 0;
		openVip = 0;

	}
};

typedef unordered_map<int32_t, MapMapCfgInfo> MapMapCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RoleBorn//////////////////////////////////////

struct RoleBornItemCfgInfo
{
	int32_t   name; //名称  
	int32_t   num; //数量  

	RoleBornItemCfgInfo()
	{
		name = 0;
		num = 0;

	}
};
//
typedef vector<RoleBornItemCfgInfo> VecRoleBornItemCfg;


struct RoleBornCfgInfo
{
	int32_t   carryFashionWeapons; //装备时装(武器)  
	int32_t   carryRing2; //装备戒指  
	int32_t   bornID; //主键ID  
	int32_t   mapX; //出生地的X点  
	string   icons; //头像图标  
	int32_t   carryBracer2; //装备护腕  
	int32_t   carryWings; //装备翅膀  
	int32_t   mapID; //出生地图ID  
	int32_t   carryNecklace; //装备项链  
	int32_t   race; //种族  
	int32_t   gender; //性别  
	int32_t   gold; //携带金币  
	int32_t   birthFace; //出生朝向  
	VEC_INT32   vec_actBuff; //生成buff  
	int32_t   bornTitle; //携带称号  
	int32_t   bindGold; //携带绑定金币  
	int32_t   diamond; //携带钻石  
	int32_t   carryArmor; //装备衣服  
	int32_t   professionID; //职业ID  
	int32_t   carryRing1; //装备戒指  
	string   roleAvata; //出生时模型  
	VecRoleBornItemCfg   vecRoleBornItemCfg; //背包物品  
	VEC_INT32   vec_actSkill; //生成技能  
	string   weaponAvata; //出生时武器模型  
	int32_t   mapY; //出生地的Y点  
	string   professionName; //职业名称  
	int32_t   carryFashionArmor; //装备时装(衣服)  
	int32_t   bornLevel; //出生等级  
	int32_t   carryCloak; //装备披风  
	string   placement; //职业介绍  
	int32_t   carryWeapons; //装备武器  
	int32_t   bindDiamond; //携带绑定钻石  
	string   loginAvata; //创角界面模型  
	int32_t   carryShoes; //装备鞋子  
	int32_t   carryAmulet; //装备护符  
	int32_t   mapZ; //出生地的Z点  
	int32_t   carryBracer1; //装备护腕  

	RoleBornCfgInfo()
	{
		carryFashionWeapons = 0;
		carryRing2 = 0;
		bornID = 0;
		mapX = 0;
		icons = "";
		carryBracer2 = 0;
		carryWings = 0;
		mapID = 0;
		carryNecklace = 0;
		race = 0;
		gender = 0;
		gold = 0;
		birthFace = 0;
		vec_actBuff.clear();
		bornTitle = 0;
		bindGold = 0;
		diamond = 0;
		carryArmor = 0;
		professionID = 0;
		carryRing1 = 0;
		roleAvata = "";
		vecRoleBornItemCfg.clear();
		vec_actSkill.clear();
		weaponAvata = "";
		mapY = 0;
		professionName = "";
		carryFashionArmor = 0;
		bornLevel = 0;
		carryCloak = 0;
		placement = "";
		carryWeapons = 0;
		bindDiamond = 0;
		loginAvata = "";
		carryShoes = 0;
		carryAmulet = 0;
		mapZ = 0;
		carryBracer1 = 0;

	}
};

typedef unordered_map<int32_t, RoleBornCfgInfo> RoleBornCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RoleMaster//////////////////////////////////////

struct RoleMasterAttributeCfgInfo
{
	int32_t   Type; //类型  
	int32_t   Value; //值  

	RoleMasterAttributeCfgInfo()
	{
		Type = 0;
		Value = 0;

	}
};
//
typedef vector<RoleMasterAttributeCfgInfo> VecRoleMasterAttributeCfg;


struct RoleMasterCfgInfo
{
	VecRoleMasterAttributeCfg   vecRoleMasterAttributeCfg; //属性  
	int32_t   lv; //玩家等级  
	int32_t   upgradePoint; //升级获得点数  

	RoleMasterCfgInfo()
	{
		vecRoleMasterAttributeCfg.clear();
		lv = 0;
		upgradePoint = 0;

	}
};

typedef unordered_map<int32_t, RoleMasterCfgInfo> RoleMasterCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RoleAssassin//////////////////////////////////////

struct RoleAssassinAttributeCfgInfo
{
	int32_t   Type; //类型  
	int32_t   Value; //值  

	RoleAssassinAttributeCfgInfo()
	{
		Type = 0;
		Value = 0;

	}
};
//
typedef vector<RoleAssassinAttributeCfgInfo> VecRoleAssassinAttributeCfg;


struct RoleAssassinCfgInfo
{
	VecRoleAssassinAttributeCfg   vecRoleAssassinAttributeCfg; //属性  
	int32_t   lv; //玩家等级  
	int32_t   upgradePoint; //升级获得点数  

	RoleAssassinCfgInfo()
	{
		vecRoleAssassinAttributeCfg.clear();
		lv = 0;
		upgradePoint = 0;

	}
};

typedef unordered_map<int32_t, RoleAssassinCfgInfo> RoleAssassinCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RoleExp//////////////////////////////////////



struct RoleExpCfgInfo
{
	int32_t   lv; //等级  
	int32_t   stamina; //体力上限  
	int32_t   exp; //当前等级升级需要经验  

	RoleExpCfgInfo()
	{
		lv = 0;
		stamina = 0;
		exp = 0;

	}
};

typedef unordered_map<int32_t, RoleExpCfgInfo> RoleExpCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RoleShooter//////////////////////////////////////

struct RoleShooterAttributeCfgInfo
{
	int32_t   Type; //类型  
	int32_t   Value; //值  

	RoleShooterAttributeCfgInfo()
	{
		Type = 0;
		Value = 0;

	}
};
//
typedef vector<RoleShooterAttributeCfgInfo> VecRoleShooterAttributeCfg;


struct RoleShooterCfgInfo
{
	VecRoleShooterAttributeCfg   vecRoleShooterAttributeCfg; //属性  
	int32_t   lv; //玩家等级  
	int32_t   upgradePoint; //升级获得点数  

	RoleShooterCfgInfo()
	{
		vecRoleShooterAttributeCfg.clear();
		lv = 0;
		upgradePoint = 0;

	}
};

typedef unordered_map<int32_t, RoleShooterCfgInfo> RoleShooterCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RoleWarrior//////////////////////////////////////

struct RoleWarriorAttributeCfgInfo
{
	int32_t   Type; //类型  
	int32_t   Value; //值  

	RoleWarriorAttributeCfgInfo()
	{
		Type = 0;
		Value = 0;

	}
};
//
typedef vector<RoleWarriorAttributeCfgInfo> VecRoleWarriorAttributeCfg;


struct RoleWarriorCfgInfo
{
	VecRoleWarriorAttributeCfg   vecRoleWarriorAttributeCfg; //属性  
	int32_t   lv; //玩家等级  
	int32_t   upgradePoint; //升级获得点数  

	RoleWarriorCfgInfo()
	{
		vecRoleWarriorAttributeCfg.clear();
		lv = 0;
		upgradePoint = 0;

	}
};

typedef unordered_map<int32_t, RoleWarriorCfgInfo> RoleWarriorCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////MallMall//////////////////////////////////////



struct MallMallCfgInfo
{
	int32_t   openCoolTime; //开放冷却时间  
	int32_t   id; //商品ID  
	int32_t   discount; //折扣  
	int32_t   isClose; //是否下架  
	int32_t   goodsAmount; //供货量  
	int32_t   buyAmount; //可购买数量  
	int32_t   priority; //优先级  
	int32_t   price; //价格  
	int32_t   itemID; //物品ID  
	int32_t   levelLimit; //等级限制  
	int32_t   vipLimit; //VIP等级限制  
	int32_t   sellWaitingTime; //销售等待时间  
	int32_t   refreshTime; //刷新时间周期  
	int32_t   moneyType; //货币类型  
	int32_t   mallType; //商城分类  
	int32_t   openTime; //开放时限  
	int32_t   goodsRefreshTime; //供货刷新周期  

	MallMallCfgInfo()
	{
		openCoolTime = 0;
		id = 0;
		discount = 0;
		isClose = 0;
		goodsAmount = 0;
		buyAmount = 0;
		priority = 0;
		price = 0;
		itemID = 0;
		levelLimit = 0;
		vipLimit = 0;
		sellWaitingTime = 0;
		refreshTime = 0;
		moneyType = 0;
		mallType = 0;
		openTime = 0;
		goodsRefreshTime = 0;

	}
};

typedef unordered_map<int32_t, MallMallCfgInfo> MallMallCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////MallMalltype//////////////////////////////////////



struct MallMalltypeCfgInfo
{
	int32_t   priority; //优先级  
	string   res; //分类名称资源  
	int32_t   id; //分类ID  

	MallMalltypeCfgInfo()
	{
		priority = 0;
		res = "";
		id = 0;

	}
};

typedef unordered_map<int32_t, MallMalltypeCfgInfo> MallMalltypeCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////ItemItem//////////////////////////////////////



struct ItemItemCfgInfo
{
	string   otherRequest; //其他要求  
	int32_t   id; //物品ID  
	int32_t   chantTime; //读条时间  
	int32_t   coolingGroup; //冷却组  
	string   functionValue; //物品功能参数  
	int32_t   sexRequest; //性别要求  
	int32_t   coolingTime; //冷却时间  
	int32_t   isCanStack; //可否堆叠  
	VEC_STRING   vec_source; //物品来源  
	int32_t   coolingType; //冷却类型  
	int32_t   isCanBatchUse; //是否可批量使用  
	int32_t   useEffectAim; //作用目标类型  
	int32_t   itemType; //物品类型  
	int32_t   isUsedDestroy; //使用后是否销毁  
	int32_t   isFightingUse; //是否可在战斗中使用  
	int32_t   functionType; //物品功能类型  
	int32_t   isCanSell; //可否出售  
	int32_t   aimRelation; //目标关系  
	int32_t   isMarket; //可否拍卖  
	string   name; //物品名称  
	int32_t   subType; //物品细分类型  
	int32_t   raceRequest; //种族要求  
	int32_t   isCanUse; //是否可使用  
	int32_t   isGetBind; //是否获得绑定  
	int32_t   levelRequest; //等级要求  
	int32_t   itemLevel; //物品等级  
	int32_t   isDeathFall; //是否死亡掉落  
	int32_t   sellPrice; //出售价格  
	int32_t   careerRequest; //职业要求  
	int32_t   itemQuality; //物品品质  

	ItemItemCfgInfo()
	{
		otherRequest = "";
		id = 0;
		chantTime = 0;
		coolingGroup = 0;
		functionValue = "";
		sexRequest = 0;
		coolingTime = 0;
		isCanStack = 0;
		vec_source.clear();
		coolingType = 0;
		isCanBatchUse = 0;
		useEffectAim = 0;
		itemType = 0;
		isUsedDestroy = 0;
		isFightingUse = 0;
		functionType = 0;
		isCanSell = 0;
		aimRelation = 0;
		isMarket = 0;
		name = "";
		subType = 0;
		raceRequest = 0;
		isCanUse = 0;
		isGetBind = 0;
		levelRequest = 0;
		itemLevel = 0;
		isDeathFall = 0;
		sellPrice = 0;
		careerRequest = 0;
		itemQuality = 0;

	}
};

typedef unordered_map<int32_t, ItemItemCfgInfo> ItemItemCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////TeleportBorn//////////////////////////////////////



struct TeleportBornCfgInfo
{
	int32_t   id; //出生点ID  
	int32_t   type; //点类型  
	int32_t   roleBornRange; //角色出生范围  
	int32_t   camp; //所属阵营  
	int32_t   scene; //所属场景  

	TeleportBornCfgInfo()
	{
		id = 0;
		type = 0;
		roleBornRange = 0;
		camp = 0;
		scene = 0;

	}
};

typedef unordered_map<int32_t, TeleportBornCfgInfo> TeleportBornCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////TeleportSafearea//////////////////////////////////////



struct TeleportSafeareaCfgInfo
{
	int32_t   linkArea; //关联区域  
	int32_t   id; //安全区域ID  
	int32_t   camp; //所属阵营  
	int32_t   scene; //所属场景  

	TeleportSafeareaCfgInfo()
	{
		linkArea = 0;
		id = 0;
		camp = 0;
		scene = 0;

	}
};

typedef unordered_map<int32_t, TeleportSafeareaCfgInfo> TeleportSafeareaCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////TeleportTeleport//////////////////////////////////////



struct TeleportTeleportCfgInfo
{
	int32_t   toSceneID; //目标场景  
	int32_t   standID; //目标点ID  
	int32_t   teleportID; //传送点ID  
	int32_t   isSameScene; //是否同场景  

	TeleportTeleportCfgInfo()
	{
		toSceneID = 0;
		standID = 0;
		teleportID = 0;
		isSameScene = 0;

	}
};

typedef unordered_map<int32_t, TeleportTeleportCfgInfo> TeleportTeleportCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////ComposeCompose//////////////////////////////////////

struct ComposeComposeItemCfgInfo
{
	int32_t   num; //数量  
	int32_t   id; //ID  

	ComposeComposeItemCfgInfo()
	{
		num = 0;
		id = 0;

	}
};
//
typedef vector<ComposeComposeItemCfgInfo> VecComposeComposeItemCfg;


struct ComposeComposeCfgInfo
{
	VecComposeComposeItemCfg   vecComposeComposeItemCfg; //材料  
	int32_t   composeType; //合成类型  
	int32_t   ID; //物品ID  

	ComposeComposeCfgInfo()
	{
		vecComposeComposeItemCfg.clear();
		composeType = 0;
		ID = 0;

	}
};

typedef unordered_map<int32_t, ComposeComposeCfgInfo> ComposeComposeCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////NpcNpc//////////////////////////////////////



struct NpcNpcCfgInfo
{
	int32_t   npcID; //NPC的ID  
	int32_t   npcFightType; //NPC战斗类型  
	int32_t   linkMonster; //关联战斗怪物  
	int32_t   isFunctionNPC; //是否为功能NPC  
	int32_t   npcCamp; //NPC阵营  

	NpcNpcCfgInfo()
	{
		npcID = 0;
		npcFightType = 0;
		linkMonster = 0;
		isFunctionNPC = 0;
		npcCamp = 0;

	}
};

typedef unordered_map<int32_t, NpcNpcCfgInfo> NpcNpcCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////NpcNpcfunction//////////////////////////////////////



struct NpcNpcfunctionCfgInfo
{
	int32_t   functionType; //功能类型  
	int32_t   linkNPC; //关联NPC  
	string   functionParameter; //功能参数  
	int32_t   functionID; //功能项ID  

	NpcNpcfunctionCfgInfo()
	{
		functionType = 0;
		linkNPC = 0;
		functionParameter = "";
		functionID = 0;

	}
};

typedef unordered_map<int32_t, NpcNpcfunctionCfgInfo> NpcNpcfunctionCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////MonsterMonster//////////////////////////////////////



struct MonsterMonsterCfgInfo
{
	int32_t   isBelongToPlayer; //怪物归属是否显示  
	int32_t   monsterAtkType; //普攻方式  
	string   deathTrigger; //死亡触发器  
	int32_t   reduceDamage; //额外免伤  
	int32_t   fastingRes; //禁食抗性  
	int32_t   maxHP; //最大生命值  
	int32_t   isSkin; //是否可剥取  
	int32_t   burnRes; //灼烧抗性  
	int32_t   freezeRes; //冰冻抗性  
	int32_t   funkRes; //恐惧抗性  
	int32_t   isShiftOff; //是否关闭位移  
	int32_t   aSpeed; //攻击速度  
	int32_t   isFloatingOff; //是否关闭浮空  
	int32_t   hit; //命中  
	int32_t   toughness; //韧性  
	int32_t   isFormationOn; //是否开启巡逻阵型  
	int32_t   isAIWorkWhenNobody; //是否无人时启用AI  
	int32_t   critExtraDamage; //暴击额外伤害  
	int32_t   dropDefault; //默认掉落  
	int32_t   dodge; //闪避  
	int32_t   isStiffOff; //是否关闭僵直  
	int32_t   actionRange; //怪物活动范围  
	int32_t   exp; //经验产出  
	int32_t   patrolPath; //巡逻路径  
	int32_t   reduceDamageRate; //免伤率  
	string   deathEffect; //死亡特效  
	int32_t   monsterLV; //怪物等级  
	int32_t   damageRate; //伤害率  
	int32_t   dp; //物理防御  
	int32_t   ap; //物理攻击  
	int32_t   specialAI; //怪物特殊AI  
	int32_t   monsterType; //怪物类型  
	int32_t   monsterFightType; //怪物战斗类型  
	int32_t   patrolType; //巡逻类型  
	int32_t   bodyStayTime; //尸体留存时间  
	int32_t   restWaitTime; //怪物休闲等待时间  
	int32_t   protectTime; //怪物归属保护时间  
	int32_t   isDownOff; //是否关闭击倒  
	string   view; //视野  
	int32_t   extraDamage; //额外伤害  
	int32_t   weakRes; //虚弱抗性  
	int32_t   normalSkillLevel; //普攻技能等级  
	int32_t   crit; //暴击  
	int32_t   critReduceDamage; //暴击额外免伤  
	int32_t   monsterCfgType; //怪物配置类型  
	int32_t   mdp; //魔法防御  
	int32_t   mSpeed; //移动速度  
	int32_t   attackRange; //攻击范围  
	int32_t   skinLink; //剥皮关联  
	int32_t   viewType; //视野类型  
	int32_t   pursueRange; //追击范围  
	int32_t   mat; //魔法攻击  
	int32_t   critRate; //暴击倍率  
	int32_t   monsterID; //怪物ID  
	int32_t   anchor; //特效挂点  
	string   bornTrigger; //出生触发器  
	int32_t   maxMP; //最大魔法值  
	int32_t   monsterRefreshTime; //怪物刷新时间  
	int32_t   normalSkill; //普攻技能  

	MonsterMonsterCfgInfo()
	{
		isBelongToPlayer = 0;
		monsterAtkType = 0;
		deathTrigger = "";
		reduceDamage = 0;
		fastingRes = 0;
		maxHP = 0;
		isSkin = 0;
		burnRes = 0;
		freezeRes = 0;
		funkRes = 0;
		isShiftOff = 0;
		aSpeed = 0;
		isFloatingOff = 0;
		hit = 0;
		toughness = 0;
		isFormationOn = 0;
		isAIWorkWhenNobody = 0;
		critExtraDamage = 0;
		dropDefault = 0;
		dodge = 0;
		isStiffOff = 0;
		actionRange = 0;
		exp = 0;
		patrolPath = 0;
		reduceDamageRate = 0;
		deathEffect = "";
		monsterLV = 0;
		damageRate = 0;
		dp = 0;
		ap = 0;
		specialAI = 0;
		monsterType = 0;
		monsterFightType = 0;
		patrolType = 0;
		bodyStayTime = 0;
		restWaitTime = 0;
		protectTime = 0;
		isDownOff = 0;
		view = "";
		extraDamage = 0;
		weakRes = 0;
		normalSkillLevel = 0;
		crit = 0;
		critReduceDamage = 0;
		monsterCfgType = 0;
		mdp = 0;
		mSpeed = 0;
		attackRange = 0;
		skinLink = 0;
		viewType = 0;
		pursueRange = 0;
		mat = 0;
		critRate = 0;
		monsterID = 0;
		anchor = 0;
		bornTrigger = "";
		maxMP = 0;
		monsterRefreshTime = 0;
		normalSkill = 0;

	}
};

typedef unordered_map<int32_t, MonsterMonsterCfgInfo> MonsterMonsterCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////PetPet//////////////////////////////////////



struct PetPetCfgInfo
{
	int32_t   dp; //物理防御  
	int32_t   ap; //物理攻击  
	int32_t   maxHP; //最大生命值  
	VEC_INT32   vec_costMoney; //消耗金币数量  
	int32_t   petQuality; //精灵品质  
	int32_t   level; //对应等级  
	int32_t   star; //培养星数  
	int32_t   mdp; //魔法防御  
	int32_t   commonSkillId; //普攻ID  
	int32_t   costFragmentNum; //消耗碎片数量  
	int32_t   costStoneNum; //消耗进化石数量  
	int32_t   mat; //魔法攻击  
	int32_t   stoneId; //消耗进化石id  
	int32_t   stage; //阶段  
	int32_t   petId; //精灵ID  
	int32_t   fragmentId; //升星消耗碎片id  
	int32_t   maxMP; //最大魔法值  
	int32_t   evolveId; //进化后id  
	int32_t   trainId; //升星后id  

	PetPetCfgInfo()
	{
		dp = 0;
		ap = 0;
		maxHP = 0;
		vec_costMoney.clear();
		petQuality = 0;
		level = 0;
		star = 0;
		mdp = 0;
		commonSkillId = 0;
		costFragmentNum = 0;
		costStoneNum = 0;
		mat = 0;
		stoneId = 0;
		stage = 0;
		petId = 0;
		fragmentId = 0;
		maxMP = 0;
		evolveId = 0;
		trainId = 0;

	}
};

typedef unordered_map<int32_t, PetPetCfgInfo> PetPetCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////PetPetskill//////////////////////////////////////



struct PetPetskillCfgInfo
{
	int32_t   skillLevel; //技能等级  
	int32_t   bookNum; //技能书数量  
	int32_t   bookId; //消耗技能书id  
	int32_t   skillId; //技能ID  
	int32_t   costMoney; //金币数量  

	PetPetskillCfgInfo()
	{
		skillLevel = 0;
		bookNum = 0;
		bookId = 0;
		skillId = 0;
		costMoney = 0;

	}
};

typedef unordered_map<int32_t, PetPetskillCfgInfo> PetPetskillCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////AchievementAchievement//////////////////////////////////////

struct AchievementAchievementItemRewardCfgInfo
{
	int32_t   ID; //ID  
	int32_t   Value; //数量  

	AchievementAchievementItemRewardCfgInfo()
	{
		ID = 0;
		Value = 0;

	}
};
//
typedef vector<AchievementAchievementItemRewardCfgInfo> VecAchievementAchievementItemRewardCfg;


struct AchievementAchievementCfgInfo
{
	int32_t   achievementLevel; //成就触发等级  
	int32_t   achievementObjectID; //事件目标ID  
	int32_t   achievementDia; //获得绑定钻石数量  
	int32_t   achievementEXP; //获得经验  
	VecAchievementAchievementItemRewardCfg   vecAchievementAchievementItemRewardCfg; //获得物品  
	int32_t   achievementPoint; //获取成就点数量  
	int32_t   achievementGold; //获得金币数量  
	int32_t   beforeAchievement; //前置成就ID  
	int32_t   achievementSubType; //事件类型  
	int32_t   achievementId; //成就ID  
	int32_t   achievementObjectValue; //事件目标完成值  
	int32_t   achievementType; //成就类型  
	int32_t   achievementSubSunType; //事件子类型  

	AchievementAchievementCfgInfo()
	{
		achievementLevel = 0;
		achievementObjectID = 0;
		achievementDia = 0;
		achievementEXP = 0;
		vecAchievementAchievementItemRewardCfg.clear();
		achievementPoint = 0;
		achievementGold = 0;
		beforeAchievement = 0;
		achievementSubType = 0;
		achievementId = 0;
		achievementObjectValue = 0;
		achievementType = 0;
		achievementSubSunType = 0;

	}
};

typedef unordered_map<int32_t, AchievementAchievementCfgInfo> AchievementAchievementCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////AchievementAchievementreward//////////////////////////////////////

struct AchievementAchievementrewardRewardCfgInfo
{
	int32_t   ID; //ID  
	int32_t   Value; //数量  

	AchievementAchievementrewardRewardCfgInfo()
	{
		ID = 0;
		Value = 0;

	}
};
//
typedef vector<AchievementAchievementrewardRewardCfgInfo> VecAchievementAchievementrewardRewardCfg;


struct AchievementAchievementrewardCfgInfo
{
	VecAchievementAchievementrewardRewardCfg   vecAchievementAchievementrewardRewardCfg; //奖励物品  
	int32_t   achievementPointValue; //所需成就点值  
	int32_t   achievementType; //成就类型  
	int32_t   achievementPrizeId; //成就奖励ID  

	AchievementAchievementrewardCfgInfo()
	{
		vecAchievementAchievementrewardRewardCfg.clear();
		achievementPointValue = 0;
		achievementType = 0;
		achievementPrizeId = 0;

	}
};

typedef unordered_map<int32_t, AchievementAchievementrewardCfgInfo> AchievementAchievementrewardCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////EquipFashion//////////////////////////////////////



struct EquipFashionCfgInfo
{
	int32_t   attributeValue; //属性数值  
	int32_t   position; //装备位置  
	int32_t   id; //时装ID  
	int32_t   days; //有效时间  
	int32_t   attributeType; //属性类型  
	int32_t   fashionValue; //时装套件数量  
	string   name; //时装名称  

	EquipFashionCfgInfo()
	{
		attributeValue = 0;
		position = 0;
		id = 0;
		days = 0;
		attributeType = 0;
		fashionValue = 0;
		name = "";

	}
};

typedef unordered_map<int32_t, EquipFashionCfgInfo> EquipFashionCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////EquipSuit//////////////////////////////////////

struct EquipSuitAttributeCfgInfo
{
	int32_t   sctivation; //穿戴数量  
	int32_t   type; //  
	int32_t   value; //数值  

	EquipSuitAttributeCfgInfo()
	{
		sctivation = 0;
		type = 0;
		value = 0;

	}
};
//
typedef vector<EquipSuitAttributeCfgInfo> VecEquipSuitAttributeCfg;


struct EquipSuitCfgInfo
{
	VecEquipSuitAttributeCfg   vecEquipSuitAttributeCfg; //套件激活属性  
	int32_t   id; //套装ID  
	string   name; //套装名称  
	int32_t   suiteValue; //套装套件数量  
	VEC_INT32   vec_equipId; //装备ID  

	EquipSuitCfgInfo()
	{
		vecEquipSuitAttributeCfg.clear();
		id = 0;
		name = "";
		suiteValue = 0;
		vec_equipId.clear();

	}
};

typedef unordered_map<int32_t, EquipSuitCfgInfo> EquipSuitCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////EquipRefine//////////////////////////////////////

struct EquipRefineItemCfgInfo
{
	string   ratio; //系数  
	int32_t   id; //ID  

	EquipRefineItemCfgInfo()
	{
		ratio = "";
		id = 0;

	}
};
//
typedef vector<EquipRefineItemCfgInfo> VecEquipRefineItemCfg;


struct EquipRefineCfgInfo
{
	float   recovery; //回收比例  
	VecEquipRefineItemCfg   vecEquipRefineItemCfg; //物品  
	string   gold; //金币消耗  
	int32_t   id; //装备ID  

	EquipRefineCfgInfo()
	{
		recovery = 0;
		vecEquipRefineItemCfg.clear();
		gold = "";
		id = 0;

	}
};

typedef unordered_map<int32_t, EquipRefineCfgInfo> EquipRefineCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////EquipEquip//////////////////////////////////////

struct EquipEquipAttributeCfgInfo
{
	int32_t   type; //  
	int32_t   valueMax; //最大数值  
	int32_t   valueMin; //最小数值  

	EquipEquipAttributeCfgInfo()
	{
		type = 0;
		valueMax = 0;
		valueMin = 0;

	}
};
//
typedef vector<EquipEquipAttributeCfgInfo> VecEquipEquipAttributeCfg;


struct EquipEquipCfgInfo
{
	VecEquipEquipAttributeCfg   vecEquipEquipAttributeCfg; //基础属性  
	float   strengthenProportion; //强化比例  
	int32_t   holeMin; //初始最小镶嵌孔数  
	int32_t   refineAttributeNum; //随机精炼属性条数  
	VEC_STRING   vec_source; //装备来源  
	int32_t   isDrop; //是否掉落  
	int32_t   profession; //职业限制  
	float   refineProportion; //精炼比例  
	string   refineAttribute_valueMax; //精炼属性最大值  
	int32_t   position; //装备位置  
	int32_t   suitId; //套装ID  
	int32_t   sex; //性别限制  
	string   refineAttribute_valueMin; //精炼属性最小值  
	int32_t   holeMax; //初始最大镶嵌孔数  
	int32_t   id; //装备ID  
	string   desc; //装备描述  
	int32_t   isCanbind; //是否绑定  
	string   refineAttribute_typeLibrary; //随机精炼属性库  
	int32_t   bindType; //绑定类型  
	int32_t   quality; //装备固定品质  
	int32_t   sellPrice; //出售价格  
	int32_t   isCanSell; //是否出售  
	int32_t   wearLevel; //穿戴等级限制  

	EquipEquipCfgInfo()
	{
		vecEquipEquipAttributeCfg.clear();
		strengthenProportion = 0;
		holeMin = 0;
		refineAttributeNum = 0;
		vec_source.clear();
		isDrop = 0;
		profession = 0;
		refineProportion = 0;
		refineAttribute_valueMax = "";
		position = 0;
		suitId = 0;
		sex = 0;
		refineAttribute_valueMin = "";
		holeMax = 0;
		id = 0;
		desc = "";
		isCanbind = 0;
		refineAttribute_typeLibrary = "";
		bindType = 0;
		quality = 0;
		sellPrice = 0;
		isCanSell = 0;
		wearLevel = 0;

	}
};

typedef unordered_map<int32_t, EquipEquipCfgInfo> EquipEquipCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////EquipStrengthen//////////////////////////////////////



struct EquipStrengthenCfgInfo
{
	string   itemRatio; //物品系数  
	string   gold; //金币消耗  
	float   recovery; //回收比例  
	int32_t   id; //装备ID  
	int32_t   itemId; //物品ID  

	EquipStrengthenCfgInfo()
	{
		itemRatio = "";
		gold = "";
		recovery = 0;
		id = 0;
		itemId = 0;

	}
};

typedef unordered_map<int32_t, EquipStrengthenCfgInfo> EquipStrengthenCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////ChatChat//////////////////////////////////////



struct ChatChatCfgInfo
{
	int32_t   chatType; //传闻类型  
	int32_t   chatId; //传闻ID  

	ChatChatCfgInfo()
	{
		chatType = 0;
		chatId = 0;

	}
};

typedef unordered_map<int32_t, ChatChatCfgInfo> ChatChatCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////DuplicateDuplicate//////////////////////////////////////



struct DuplicateDuplicateCfgInfo
{
	int32_t   reviveMaxTimes; //复活次数上限  
	int32_t   groupID; //所属副本组ID  
	int32_t   sceneResource; //场景ID  
	int32_t   rewardLibrary; //普通奖品库  
	int32_t   rewardCoin; //奖励游戏币  
	string   gradeRule; //评级规则  
	int32_t   goodRewardValue; //良品阀  
	int32_t   playerAmountLowerLimit; //人数要求下限  
	int32_t   goodRewardLibrary; //良品库  
	int32_t   duplicateType; //副本内容类型  
	int32_t   playerAmountTopLimit; //人数要求上限  
	int32_t   dropNormalMonster; //普通怪物掉落  
	string   duplicateConditionType; //副本条件类型  
	int32_t   linkDuplicateRequest; //前置副本要求  
	string   bossDesc; //BOSS说明序列  
	int32_t   rewardExp; //奖励经验  
	int32_t   dropEliteMonster; //精英怪物掉落  
	int32_t   levelLimit; //等级要求下限  
	int32_t   playType; //副本玩法类型  
	string   sceneAIScript; //场景AI脚本  
	int32_t   duplicateID; //副本ID  
	int32_t   isAutoFight; //是否允许自动战斗  
	string   rewardItem; //奖励物品  
	string   unlockTask; //解锁任务  
	string   trigEntry; //触发入口  

	DuplicateDuplicateCfgInfo()
	{
		reviveMaxTimes = 0;
		groupID = 0;
		sceneResource = 0;
		rewardLibrary = 0;
		rewardCoin = 0;
		gradeRule = "";
		goodRewardValue = 0;
		playerAmountLowerLimit = 0;
		goodRewardLibrary = 0;
		duplicateType = 0;
		playerAmountTopLimit = 0;
		dropNormalMonster = 0;
		duplicateConditionType = "";
		linkDuplicateRequest = 0;
		bossDesc = "";
		rewardExp = 0;
		dropEliteMonster = 0;
		levelLimit = 0;
		playType = 0;
		sceneAIScript = "";
		duplicateID = 0;
		isAutoFight = 0;
		rewardItem = "";
		unlockTask = "";
		trigEntry = "";

	}
};

typedef unordered_map<int32_t, DuplicateDuplicateCfgInfo> DuplicateDuplicateCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////DuplicateGroup//////////////////////////////////////



struct DuplicateGroupCfgInfo
{
	int32_t   belongToType; //所属类型  
	int32_t   id; //副本组ID  
	int32_t   unlockLevel; //解锁等级  
	int32_t   buyMaxTimes; //最大购买次数  
	int32_t   groupTimesType; //组次数类型  
	string   timesRes; //次数ICON资源  
	int32_t   refreshType; //次数上限刷新类型  
	int32_t   groupType; //组内容类型  
	string   buyPrice; //购买价格序列  
	int32_t   groupTimes; //次数上限值  
	string   openTime; //开放时间  
	string   refreshTime; //限制刷新时间  

	DuplicateGroupCfgInfo()
	{
		belongToType = 0;
		id = 0;
		unlockLevel = 0;
		buyMaxTimes = 0;
		groupTimesType = 0;
		timesRes = "";
		refreshType = 0;
		groupType = 0;
		buyPrice = "";
		groupTimes = 0;
		openTime = "";
		refreshTime = "";

	}
};

typedef unordered_map<int32_t, DuplicateGroupCfgInfo> DuplicateGroupCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////AreaPath//////////////////////////////////////



struct AreaPathCfgInfo
{
	int32_t   belongToSceneID; //所属场景  
	int32_t   id; //路径ID  

	AreaPathCfgInfo()
	{
		belongToSceneID = 0;
		id = 0;

	}
};

typedef unordered_map<int32_t, AreaPathCfgInfo> AreaPathCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////AreaArea//////////////////////////////////////



struct AreaAreaCfgInfo
{
	int32_t   belongToSceneID; //所属场景  
	int32_t   shapeType; //形状类型  
	string   name; //区域名称  
	int32_t   id; //区域ID  
	int32_t   subType; //细分类型  
	int32_t   showType; //显示类型  

	AreaAreaCfgInfo()
	{
		belongToSceneID = 0;
		shapeType = 0;
		name = "";
		id = 0;
		subType = 0;
		showType = 0;

	}
};

typedef unordered_map<int32_t, AreaAreaCfgInfo> AreaAreaCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RandomnameWomanfirst//////////////////////////////////////



struct RandomnameWomanfirstCfgInfo
{
	string   name; //名字  
	int32_t   id; //下标  

	RandomnameWomanfirstCfgInfo()
	{
		name = "";
		id = 0;

	}
};

typedef unordered_map<int32_t, RandomnameWomanfirstCfgInfo> RandomnameWomanfirstCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RandomnameManthird//////////////////////////////////////



struct RandomnameManthirdCfgInfo
{
	string   name; //名字  
	int32_t   id; //下标  

	RandomnameManthirdCfgInfo()
	{
		name = "";
		id = 0;

	}
};

typedef unordered_map<int32_t, RandomnameManthirdCfgInfo> RandomnameManthirdCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RandomnameWomanthird//////////////////////////////////////



struct RandomnameWomanthirdCfgInfo
{
	string   name; //名字  
	int32_t   id; //下标  

	RandomnameWomanthirdCfgInfo()
	{
		name = "";
		id = 0;

	}
};

typedef unordered_map<int32_t, RandomnameWomanthirdCfgInfo> RandomnameWomanthirdCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RandomnameMansecond//////////////////////////////////////



struct RandomnameMansecondCfgInfo
{
	string   name; //名字  
	int32_t   id; //下标  

	RandomnameMansecondCfgInfo()
	{
		name = "";
		id = 0;

	}
};

typedef unordered_map<int32_t, RandomnameMansecondCfgInfo> RandomnameMansecondCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RandomnameManfirst//////////////////////////////////////



struct RandomnameManfirstCfgInfo
{
	string   name; //名字  
	int32_t   id; //下标  

	RandomnameManfirstCfgInfo()
	{
		name = "";
		id = 0;

	}
};

typedef unordered_map<int32_t, RandomnameManfirstCfgInfo> RandomnameManfirstCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////RandomnameWomansecond//////////////////////////////////////



struct RandomnameWomansecondCfgInfo
{
	string   name; //名字  
	int32_t   id; //下标  

	RandomnameWomansecondCfgInfo()
	{
		name = "";
		id = 0;

	}
};

typedef unordered_map<int32_t, RandomnameWomansecondCfgInfo> RandomnameWomansecondCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////ConstantConstant//////////////////////////////////////



struct ConstantConstantCfgInfo
{
	int32_t   constantdata; //数据  
	int32_t   constantid; //配置id  

	ConstantConstantCfgInfo()
	{
		constantdata = 0;
		constantid = 0;

	}
};

typedef unordered_map<int32_t, ConstantConstantCfgInfo> ConstantConstantCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////TasktrackerTasktracker//////////////////////////////////////



struct TasktrackerTasktrackerCfgInfo
{
	string   tracker; //任务追踪说明  
	int32_t   comID; //完成条件类型ID  

	TasktrackerTasktrackerCfgInfo()
	{
		tracker = "";
		comID = 0;

	}
};

typedef unordered_map<int32_t, TasktrackerTasktrackerCfgInfo> TasktrackerTasktrackerCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////BoxDrop//////////////////////////////////////

struct BoxDropItemCfgInfo
{
	int32_t   maxNum; //最大数量  
	int32_t   minNum; //最小数量  
	int32_t   id; //id  
	int32_t   rand; //概率  

	BoxDropItemCfgInfo()
	{
		maxNum = 0;
		minNum = 0;
		id = 0;
		rand = 0;

	}
};
//
typedef vector<BoxDropItemCfgInfo> VecBoxDropItemCfg;


struct BoxDropCfgInfo
{
	int32_t   drop_type; //掉落类型  
	VecBoxDropItemCfg   vecBoxDropItemCfg; //掉落物品  
	int32_t   id; //掉落包ID  

	BoxDropCfgInfo()
	{
		drop_type = 0;
		vecBoxDropItemCfg.clear();
		id = 0;

	}
};

typedef unordered_map<int32_t, BoxDropCfgInfo> BoxDropCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////SkillSummon//////////////////////////////////////

struct SkillSummonSummonCfgInfo
{
	string   Skill; //技能  
	string   SkillLevel; //技能等级  

	SkillSummonSummonCfgInfo()
	{
		Skill = "";
		SkillLevel = "";

	}
};
//
typedef vector<SkillSummonSummonCfgInfo> VecSkillSummonSummonCfg;
struct SkillSummonAttributeCfgInfo
{
	string   Type; //类型  
	string   Value; //值  

	SkillSummonAttributeCfgInfo()
	{
		Type = "";
		Value = "";

	}
};
//
typedef vector<SkillSummonAttributeCfgInfo> VecSkillSummonAttributeCfg;


struct SkillSummonCfgInfo
{
	VecSkillSummonAttributeCfg   vecSkillSummonAttributeCfg; //属性  
	int32_t   viewType; //视野类型  
	int32_t   summonType; //召唤物类型  
	string   summonTime; //召唤物存在时间  
	string   summonLevel; //召唤物等级  
	int32_t   summonID; //召唤物ID  
	string   StopRange; //阻挡范围  
	VecSkillSummonSummonCfg   vecSkillSummonSummonCfg; //携带  
	string   view; //视野  
	int32_t   summonAI; //召唤物AI  
	int32_t   pursueRange; //追击范围  

	SkillSummonCfgInfo()
	{
		vecSkillSummonAttributeCfg.clear();
		viewType = 0;
		summonType = 0;
		summonTime = "";
		summonLevel = "";
		summonID = 0;
		StopRange = "";
		vecSkillSummonSummonCfg.clear();
		view = "";
		summonAI = 0;
		pursueRange = 0;

	}
};

typedef unordered_map<int32_t, SkillSummonCfgInfo> SkillSummonCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////SkillBuff//////////////////////////////////////

struct SkillBuffEffectCfgInfo
{
	int32_t   Type; //类型  
	string   Param; //参数  

	SkillBuffEffectCfgInfo()
	{
		Type = 0;
		Param = "";

	}
};
//
typedef vector<SkillBuffEffectCfgInfo> VecSkillBuffEffectCfg;


struct SkillBuffCfgInfo
{
	int32_t   stateBagID; //附加状态包id  
	string   stateBagName; //状态包名称  
	string   effectResources; //特效路径  
	int32_t   startType; //生效条件  
	string   endType; //常规结束条件  
	string   stateBagIcon; //状态包图标  
	int32_t   stateBagRule; //同一状态包叠加规则  
	int32_t   mask; //32位掩码  
	VecSkillBuffEffectCfg   vecSkillBuffEffectCfg; //效果  
	int32_t   delayTime; //延迟生效时间  

	SkillBuffCfgInfo()
	{
		stateBagID = 0;
		stateBagName = "";
		effectResources = "";
		startType = 0;
		endType = "";
		stateBagIcon = "";
		stateBagRule = 0;
		mask = 0;
		vecSkillBuffEffectCfg.clear();
		delayTime = 0;

	}
};

typedef unordered_map<int32_t, SkillBuffCfgInfo> SkillBuffCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////SkillSkill//////////////////////////////////////

struct SkillSkillStateBagCfgInfo
{
	int32_t   Target; //归属  
	string   Parameter; //参数  
	int32_t   ID; //id  
	string   Time; //持续时间  
	int32_t   Point; //生效点  
	int32_t   Rate; //成功几率  

	SkillSkillStateBagCfgInfo()
	{
		Target = 0;
		Parameter = "";
		ID = 0;
		Time = "";
		Point = 0;
		Rate = 0;

	}
};
//
typedef vector<SkillSkillStateBagCfgInfo> VecSkillSkillStateBagCfg;


struct SkillSkillCfgInfo
{
	string   displaceTime; //位移生效时间点  
	int32_t   skillID; //技能id  
	string   attackValue; //附加攻击力固定值  
	int32_t   flySpeed; //飞行速度  
	int32_t   Relation; //关联技能  
	int32_t   breakType; //被打断类型  
	string   rangeTypeValue; //范围类型值  
	int32_t   cost; //消耗类型  
	int32_t   attackMinDistance; //攻击最小距离  
	string   minLevel; //学习等级  
	string   costValue; //消耗数据  
	string   displaceDistance; //位移距离  
	int32_t   threat; //仇恨值  
	string   breakParameter; //被打断参数  
	int32_t   damageType; //伤害类型  
	int32_t   releaseType; //释放类型  
	int32_t   processTypes; //过程类型  
	int32_t   attackTime; //攻击总时间  
	int32_t   moveCast; //是否移动施法动作  
	int32_t   rangeType; //范围类型  
	VecSkillSkillStateBagCfg   vecSkillSkillStateBagCfg; //状态包  
	string   damageRate; //附加伤害倍率  
	int32_t   goalMaxNum; //目标最大数量  
	string   attackRate; //附加攻击力倍率  
	string   upgradeCost; //升级消耗  
	string   damageTime ; //伤害生效时间点  
	string   damageValue; //附加伤害固定值  
	int32_t   skillMaxLevel; //等级上限  
	int32_t   skillType; //技能类型  
	int32_t   profession; //职业限制  
	int32_t   cd; //cd  
	int32_t   move; //技能释放能否产生位移  
	int32_t   attackDistance; //攻击距离  
	int32_t   readyTime; //准备时间  
	int32_t   towards; //是否可改变朝向  
	int32_t   type; //种类  
	int32_t   warn; //是否预警  
	string   name; //名称  
	int32_t   breakTime; //被打断时机  

	SkillSkillCfgInfo()
	{
		displaceTime = "";
		skillID = 0;
		attackValue = "";
		flySpeed = 0;
		Relation = 0;
		breakType = 0;
		rangeTypeValue = "";
		cost = 0;
		attackMinDistance = 0;
		minLevel = "";
		costValue = "";
		displaceDistance = "";
		threat = 0;
		breakParameter = "";
		damageType = 0;
		releaseType = 0;
		processTypes = 0;
		attackTime = 0;
		moveCast = 0;
		rangeType = 0;
		vecSkillSkillStateBagCfg.clear();
		damageRate = "";
		goalMaxNum = 0;
		attackRate = "";
		upgradeCost = "";
		damageTime  = "";
		damageValue = "";
		skillMaxLevel = 0;
		skillType = 0;
		profession = 0;
		cd = 0;
		move = 0;
		attackDistance = 0;
		readyTime = 0;
		towards = 0;
		type = 0;
		warn = 0;
		name = "";
		breakTime = 0;

	}
};

typedef unordered_map<int32_t, SkillSkillCfgInfo> SkillSkillCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////SrvlistServer//////////////////////////////////////



struct SrvlistServerCfgInfo
{
	int32_t   isnew; //是否新服  
	string   ip; //ip  
	int32_t   id; //标识  
	int32_t   state; //状态  
	int32_t   areaid; //区名  
	string   name; //服务器名  
	int32_t   port; //端口  

	SrvlistServerCfgInfo()
	{
		isnew = 0;
		ip = "";
		id = 0;
		state = 0;
		areaid = 0;
		name = "";
		port = 0;

	}
};

typedef unordered_map<int32_t, SrvlistServerCfgInfo> SrvlistServerCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////SrvlistArea//////////////////////////////////////



struct SrvlistAreaCfgInfo
{
	string   name; //区名  
	int32_t   id; //标识  

	SrvlistAreaCfgInfo()
	{
		name = "";
		id = 0;

	}
};

typedef unordered_map<int32_t, SrvlistAreaCfgInfo> SrvlistAreaCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////AiAi//////////////////////////////////////

struct AiAiHpPeriodCfgInfo
{
	string   RemoveSkills; //移除技能组  
	int32_t   Percentage; //上限百分比  
	string   AddSkills; //添加技能组  

	AiAiHpPeriodCfgInfo()
	{
		RemoveSkills = "";
		Percentage = 0;
		AddSkills = "";

	}
};
//
typedef vector<AiAiHpPeriodCfgInfo> VecAiAiHpPeriodCfg;


struct AiAiCfgInfo
{
	VecAiAiHpPeriodCfg   vecAiAiHpPeriodCfg; //HP阶段  
	int32_t   id; //AI方案ID  
	string   initSkills; //技能池初始技能组  

	AiAiCfgInfo()
	{
		vecAiAiHpPeriodCfg.clear();
		id = 0;
		initSkills = "";

	}
};

typedef unordered_map<int32_t, AiAiCfgInfo> AiAiCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////ThingCollect//////////////////////////////////////

struct ThingCollectGainCfgInfo
{
	int32_t   ItemId; //道具  
	int32_t   rate; //概率  

	ThingCollectGainCfgInfo()
	{
		ItemId = 0;
		rate = 0;

	}
};
//
typedef vector<ThingCollectGainCfgInfo> VecThingCollectGainCfg;


struct ThingCollectCfgInfo
{
	int32_t   gainValue; //获得熟练度  
	int32_t   id; //资源ID  
	int32_t   mapId; //地图Id  
	int32_t   needLevel; //需要副业等级  
	VecThingCollectGainCfg   vecThingCollectGainCfg; //获得  
	int32_t   type; //类型  
	int32_t   quelity; //品质  
	int32_t   makeCount; //生成数量  
	int32_t   needEnergy; //消耗活力  
	int32_t   refreshTime; //刷新时间  

	ThingCollectCfgInfo()
	{
		gainValue = 0;
		id = 0;
		mapId = 0;
		needLevel = 0;
		vecThingCollectGainCfg.clear();
		type = 0;
		quelity = 0;
		makeCount = 0;
		needEnergy = 0;
		refreshTime = 0;

	}
};

typedef unordered_map<int32_t, ThingCollectCfgInfo> ThingCollectCfgMap;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////ThingThing//////////////////////////////////////



struct ThingThingCfgInfo
{
	int32_t   liveTime; //生存时间  
	int32_t   usableTimes; //可用次数  
	int32_t   id; //物件ID  
	int32_t   chantTime; //读条时间  
	int32_t   skill; //关联技能  
	string   res; //物件资源  
	int32_t   drop; //掉落  
	int32_t   trigRange; //触发区域半径  
	int32_t   trigAimType; //触发目标类型  
	string   trigArea; //触发区域  
	int32_t   type; //物件类型  
	int32_t   isRefresh; //死亡后可否刷新  
	int32_t   coolTime; //冷却时间  
	int32_t   refreshTime; //死亡刷新周期  

	ThingThingCfgInfo()
	{
		liveTime = 0;
		usableTimes = 0;
		id = 0;
		chantTime = 0;
		skill = 0;
		res = "";
		drop = 0;
		trigRange = 0;
		trigAimType = 0;
		trigArea = "";
		type = 0;
		isRefresh = 0;
		coolTime = 0;
		refreshTime = 0;

	}
};

typedef unordered_map<int32_t, ThingThingCfgInfo> ThingThingCfgMap;

//////////////////////////////////////////////////////////////////////////
