#pragma once

#include "ComTypeDefine.h"

////////////////////////////////////AttributeSuppress//////////////////////////////////////



struct AttributeSuppressCfgInfo
{
	int32_t   maxLvlDiff; //�ȼ���  
	int32_t   critSuppress; //����ѹ����  
	int32_t   stateSuppress; //״̬ѹ����  
	int32_t   hitSuppress; //����ѹ����  

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
	int32_t   Value; //ֵ  

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
	int32_t   attribute_Id; //����ID  
	VecAttributeConvertAttributeCfg   vecAttributeConvertAttributeCfg; //����  
	int32_t   constantID; //����ID  
	int32_t   professionID; //ְҵID  

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
	int32_t   pkRewardNum; //����������  
	int32_t   bodyEquipMax; //���������������װ�������������  
	int32_t   minPKNum; //��СPKֵ  
	int32_t   bodyEquipMin; //���������������װ��������С����  
	int32_t   killPkAdd; //ɱ�������ʱ���PKֵ  
	int32_t   bagPropMin; //����������󱳰���Ʒ������������  
	int32_t   bagPropLose; //����������󱳰���Ʒ���伸��  
	int32_t   pkRewardId; //������ID  
	int32_t   bodyEquipLose; //���������������װ�����伸��  
	int32_t   wanteLeveldId; //ͨ���ȼ�ID  
	int32_t   bagPropMax; //����������󱳰���Ʒ�����������  
	int32_t   maxPKNum; //���PKֵ  

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
	int32_t   level; //�ȼ�  
	string   openCreateList; //���������б�  
	int32_t   id; //id  
	int32_t   classification; //����  
	int32_t   type; //����  
	int32_t   exp; //����ֵ  
	int32_t   needMoney; //���Ľ������  

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
	int32_t   Rate; //����  

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
	int32_t   Num; //����  
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
	VecAvocationComposeNewItemCfg   vecAvocationComposeNewItemCfg; //�ϳ���  
	int32_t   id; //����id  
	int32_t   consumeRandomReel_Id; //�������ID  
	VecAvocationComposeNeedMaterialCfg   vecAvocationComposeNeedMaterialCfg; //��Ҫ����  
	int32_t   creatList; //���������б�  
	int32_t   type; //����  
	VecAvocationComposeConsumeReelCfg   vecAvocationComposeConsumeReelCfg; //����  
	int32_t   sonType; //������  
	int32_t   jobList; //ְҵ�б�  
	int32_t   isName; //�Ƿ�����  
	int32_t   linkId; //����id  
	int32_t   needMoney; //��Ҫ���  

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
	int32_t   maxNum; //�������  
	int32_t   id; //id  
	int32_t   rand; //����  

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
	int32_t   goldup; //�ܽ����������  
	int32_t   goldlow; //�ܽ����������  
	int32_t   id; //�����ID  
	VecDropDropItemCfg   vecDropDropItemCfg; //������Ʒ  
	int32_t   gold_heap; //��ҵ������  
	int32_t   gold_rand; //��ҵ������  

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
	int32_t   canSupply; //�Ƿ�ɺ�ҩ  
	int32_t   mapPk; //PK����  
	int32_t   mapHeight; //��ͼ�߶�  
	string   monsterRoad; //����Ѱ·���  
	int32_t   isDirectRevive; //�Ƿ�����ԭ�ظ���  
	int32_t   resMonster; //������Դ��  
	int32_t   mapId; //��ͼid  
	string   mapResources; //��ͼ��Դ  
	int32_t   useShoes; //�Ƿ��ʹ�÷�Ь����  
	int32_t   mapType; //��ͼ����  
	int32_t   deadPunish; //�Ƿ�����������װ����Ʒ  
	int32_t   openRace; //��ͼ������������  
	int32_t   openLv; //��ͼ����ȼ�  
	int32_t   mapSubType; //��ͼ������  
	int32_t   mapWide; //��ͼ���  
	int32_t   openVip; //��ͼ������VIP�ȼ�  

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
	int32_t   name; //����  
	int32_t   num; //����  

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
	int32_t   carryFashionWeapons; //װ��ʱװ(����)  
	int32_t   carryRing2; //װ����ָ  
	int32_t   bornID; //����ID  
	int32_t   mapX; //�����ص�X��  
	string   icons; //ͷ��ͼ��  
	int32_t   carryBracer2; //װ������  
	int32_t   carryWings; //װ�����  
	int32_t   mapID; //������ͼID  
	int32_t   carryNecklace; //װ������  
	int32_t   race; //����  
	int32_t   gender; //�Ա�  
	int32_t   gold; //Я�����  
	int32_t   birthFace; //��������  
	VEC_INT32   vec_actBuff; //����buff  
	int32_t   bornTitle; //Я���ƺ�  
	int32_t   bindGold; //Я���󶨽��  
	int32_t   diamond; //Я����ʯ  
	int32_t   carryArmor; //װ���·�  
	int32_t   professionID; //ְҵID  
	int32_t   carryRing1; //װ����ָ  
	string   roleAvata; //����ʱģ��  
	VecRoleBornItemCfg   vecRoleBornItemCfg; //������Ʒ  
	VEC_INT32   vec_actSkill; //���ɼ���  
	string   weaponAvata; //����ʱ����ģ��  
	int32_t   mapY; //�����ص�Y��  
	string   professionName; //ְҵ����  
	int32_t   carryFashionArmor; //װ��ʱװ(�·�)  
	int32_t   bornLevel; //�����ȼ�  
	int32_t   carryCloak; //װ������  
	string   placement; //ְҵ����  
	int32_t   carryWeapons; //װ������  
	int32_t   bindDiamond; //Я������ʯ  
	string   loginAvata; //���ǽ���ģ��  
	int32_t   carryShoes; //װ��Ь��  
	int32_t   carryAmulet; //װ������  
	int32_t   mapZ; //�����ص�Z��  
	int32_t   carryBracer1; //װ������  

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
	int32_t   Type; //����  
	int32_t   Value; //ֵ  

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
	VecRoleMasterAttributeCfg   vecRoleMasterAttributeCfg; //����  
	int32_t   lv; //��ҵȼ�  
	int32_t   upgradePoint; //������õ���  

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
	int32_t   Type; //����  
	int32_t   Value; //ֵ  

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
	VecRoleAssassinAttributeCfg   vecRoleAssassinAttributeCfg; //����  
	int32_t   lv; //��ҵȼ�  
	int32_t   upgradePoint; //������õ���  

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
	int32_t   lv; //�ȼ�  
	int32_t   stamina; //��������  
	int32_t   exp; //��ǰ�ȼ�������Ҫ����  

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
	int32_t   Type; //����  
	int32_t   Value; //ֵ  

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
	VecRoleShooterAttributeCfg   vecRoleShooterAttributeCfg; //����  
	int32_t   lv; //��ҵȼ�  
	int32_t   upgradePoint; //������õ���  

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
	int32_t   Type; //����  
	int32_t   Value; //ֵ  

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
	VecRoleWarriorAttributeCfg   vecRoleWarriorAttributeCfg; //����  
	int32_t   lv; //��ҵȼ�  
	int32_t   upgradePoint; //������õ���  

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
	int32_t   openCoolTime; //������ȴʱ��  
	int32_t   id; //��ƷID  
	int32_t   discount; //�ۿ�  
	int32_t   isClose; //�Ƿ��¼�  
	int32_t   goodsAmount; //������  
	int32_t   buyAmount; //�ɹ�������  
	int32_t   priority; //���ȼ�  
	int32_t   price; //�۸�  
	int32_t   itemID; //��ƷID  
	int32_t   levelLimit; //�ȼ�����  
	int32_t   vipLimit; //VIP�ȼ�����  
	int32_t   sellWaitingTime; //���۵ȴ�ʱ��  
	int32_t   refreshTime; //ˢ��ʱ������  
	int32_t   moneyType; //��������  
	int32_t   mallType; //�̳Ƿ���  
	int32_t   openTime; //����ʱ��  
	int32_t   goodsRefreshTime; //����ˢ������  

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
	int32_t   priority; //���ȼ�  
	string   res; //����������Դ  
	int32_t   id; //����ID  

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
	string   otherRequest; //����Ҫ��  
	int32_t   id; //��ƷID  
	int32_t   chantTime; //����ʱ��  
	int32_t   coolingGroup; //��ȴ��  
	string   functionValue; //��Ʒ���ܲ���  
	int32_t   sexRequest; //�Ա�Ҫ��  
	int32_t   coolingTime; //��ȴʱ��  
	int32_t   isCanStack; //�ɷ�ѵ�  
	VEC_STRING   vec_source; //��Ʒ��Դ  
	int32_t   coolingType; //��ȴ����  
	int32_t   isCanBatchUse; //�Ƿ������ʹ��  
	int32_t   useEffectAim; //����Ŀ������  
	int32_t   itemType; //��Ʒ����  
	int32_t   isUsedDestroy; //ʹ�ú��Ƿ�����  
	int32_t   isFightingUse; //�Ƿ����ս����ʹ��  
	int32_t   functionType; //��Ʒ��������  
	int32_t   isCanSell; //�ɷ����  
	int32_t   aimRelation; //Ŀ���ϵ  
	int32_t   isMarket; //�ɷ�����  
	string   name; //��Ʒ����  
	int32_t   subType; //��Ʒϸ������  
	int32_t   raceRequest; //����Ҫ��  
	int32_t   isCanUse; //�Ƿ��ʹ��  
	int32_t   isGetBind; //�Ƿ��ð�  
	int32_t   levelRequest; //�ȼ�Ҫ��  
	int32_t   itemLevel; //��Ʒ�ȼ�  
	int32_t   isDeathFall; //�Ƿ���������  
	int32_t   sellPrice; //���ۼ۸�  
	int32_t   careerRequest; //ְҵҪ��  
	int32_t   itemQuality; //��ƷƷ��  

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
	int32_t   id; //������ID  
	int32_t   type; //������  
	int32_t   roleBornRange; //��ɫ������Χ  
	int32_t   camp; //������Ӫ  
	int32_t   scene; //��������  

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
	int32_t   linkArea; //��������  
	int32_t   id; //��ȫ����ID  
	int32_t   camp; //������Ӫ  
	int32_t   scene; //��������  

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
	int32_t   toSceneID; //Ŀ�곡��  
	int32_t   standID; //Ŀ���ID  
	int32_t   teleportID; //���͵�ID  
	int32_t   isSameScene; //�Ƿ�ͬ����  

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
	int32_t   num; //����  
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
	VecComposeComposeItemCfg   vecComposeComposeItemCfg; //����  
	int32_t   composeType; //�ϳ�����  
	int32_t   ID; //��ƷID  

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
	int32_t   npcID; //NPC��ID  
	int32_t   npcFightType; //NPCս������  
	int32_t   linkMonster; //����ս������  
	int32_t   isFunctionNPC; //�Ƿ�Ϊ����NPC  
	int32_t   npcCamp; //NPC��Ӫ  

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
	int32_t   functionType; //��������  
	int32_t   linkNPC; //����NPC  
	string   functionParameter; //���ܲ���  
	int32_t   functionID; //������ID  

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
	int32_t   isBelongToPlayer; //��������Ƿ���ʾ  
	int32_t   monsterAtkType; //�չ���ʽ  
	string   deathTrigger; //����������  
	int32_t   reduceDamage; //��������  
	int32_t   fastingRes; //��ʳ����  
	int32_t   maxHP; //�������ֵ  
	int32_t   isSkin; //�Ƿ�ɰ�ȡ  
	int32_t   burnRes; //���տ���  
	int32_t   freezeRes; //��������  
	int32_t   funkRes; //�־忹��  
	int32_t   isShiftOff; //�Ƿ�ر�λ��  
	int32_t   aSpeed; //�����ٶ�  
	int32_t   isFloatingOff; //�Ƿ�رո���  
	int32_t   hit; //����  
	int32_t   toughness; //����  
	int32_t   isFormationOn; //�Ƿ���Ѳ������  
	int32_t   isAIWorkWhenNobody; //�Ƿ�����ʱ����AI  
	int32_t   critExtraDamage; //���������˺�  
	int32_t   dropDefault; //Ĭ�ϵ���  
	int32_t   dodge; //����  
	int32_t   isStiffOff; //�Ƿ�رս�ֱ  
	int32_t   actionRange; //������Χ  
	int32_t   exp; //�������  
	int32_t   patrolPath; //Ѳ��·��  
	int32_t   reduceDamageRate; //������  
	string   deathEffect; //������Ч  
	int32_t   monsterLV; //����ȼ�  
	int32_t   damageRate; //�˺���  
	int32_t   dp; //�������  
	int32_t   ap; //������  
	int32_t   specialAI; //��������AI  
	int32_t   monsterType; //��������  
	int32_t   monsterFightType; //����ս������  
	int32_t   patrolType; //Ѳ������  
	int32_t   bodyStayTime; //ʬ������ʱ��  
	int32_t   restWaitTime; //�������еȴ�ʱ��  
	int32_t   protectTime; //�����������ʱ��  
	int32_t   isDownOff; //�Ƿ�رջ���  
	string   view; //��Ұ  
	int32_t   extraDamage; //�����˺�  
	int32_t   weakRes; //��������  
	int32_t   normalSkillLevel; //�չ����ܵȼ�  
	int32_t   crit; //����  
	int32_t   critReduceDamage; //������������  
	int32_t   monsterCfgType; //������������  
	int32_t   mdp; //ħ������  
	int32_t   mSpeed; //�ƶ��ٶ�  
	int32_t   attackRange; //������Χ  
	int32_t   skinLink; //��Ƥ����  
	int32_t   viewType; //��Ұ����  
	int32_t   pursueRange; //׷����Χ  
	int32_t   mat; //ħ������  
	int32_t   critRate; //��������  
	int32_t   monsterID; //����ID  
	int32_t   anchor; //��Ч�ҵ�  
	string   bornTrigger; //����������  
	int32_t   maxMP; //���ħ��ֵ  
	int32_t   monsterRefreshTime; //����ˢ��ʱ��  
	int32_t   normalSkill; //�չ�����  

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
	int32_t   dp; //�������  
	int32_t   ap; //������  
	int32_t   maxHP; //�������ֵ  
	VEC_INT32   vec_costMoney; //���Ľ������  
	int32_t   petQuality; //����Ʒ��  
	int32_t   level; //��Ӧ�ȼ�  
	int32_t   star; //��������  
	int32_t   mdp; //ħ������  
	int32_t   commonSkillId; //�չ�ID  
	int32_t   costFragmentNum; //������Ƭ����  
	int32_t   costStoneNum; //���Ľ���ʯ����  
	int32_t   mat; //ħ������  
	int32_t   stoneId; //���Ľ���ʯid  
	int32_t   stage; //�׶�  
	int32_t   petId; //����ID  
	int32_t   fragmentId; //����������Ƭid  
	int32_t   maxMP; //���ħ��ֵ  
	int32_t   evolveId; //������id  
	int32_t   trainId; //���Ǻ�id  

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
	int32_t   skillLevel; //���ܵȼ�  
	int32_t   bookNum; //����������  
	int32_t   bookId; //���ļ�����id  
	int32_t   skillId; //����ID  
	int32_t   costMoney; //�������  

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
	int32_t   Value; //����  

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
	int32_t   achievementLevel; //�ɾʹ����ȼ�  
	int32_t   achievementObjectID; //�¼�Ŀ��ID  
	int32_t   achievementDia; //��ð���ʯ����  
	int32_t   achievementEXP; //��þ���  
	VecAchievementAchievementItemRewardCfg   vecAchievementAchievementItemRewardCfg; //�����Ʒ  
	int32_t   achievementPoint; //��ȡ�ɾ͵�����  
	int32_t   achievementGold; //��ý������  
	int32_t   beforeAchievement; //ǰ�óɾ�ID  
	int32_t   achievementSubType; //�¼�����  
	int32_t   achievementId; //�ɾ�ID  
	int32_t   achievementObjectValue; //�¼�Ŀ�����ֵ  
	int32_t   achievementType; //�ɾ�����  
	int32_t   achievementSubSunType; //�¼�������  

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
	int32_t   Value; //����  

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
	VecAchievementAchievementrewardRewardCfg   vecAchievementAchievementrewardRewardCfg; //������Ʒ  
	int32_t   achievementPointValue; //����ɾ͵�ֵ  
	int32_t   achievementType; //�ɾ�����  
	int32_t   achievementPrizeId; //�ɾͽ���ID  

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
	int32_t   attributeValue; //������ֵ  
	int32_t   position; //װ��λ��  
	int32_t   id; //ʱװID  
	int32_t   days; //��Чʱ��  
	int32_t   attributeType; //��������  
	int32_t   fashionValue; //ʱװ�׼�����  
	string   name; //ʱװ����  

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
	int32_t   sctivation; //��������  
	int32_t   type; //  
	int32_t   value; //��ֵ  

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
	VecEquipSuitAttributeCfg   vecEquipSuitAttributeCfg; //�׼���������  
	int32_t   id; //��װID  
	string   name; //��װ����  
	int32_t   suiteValue; //��װ�׼�����  
	VEC_INT32   vec_equipId; //װ��ID  

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
	string   ratio; //ϵ��  
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
	float   recovery; //���ձ���  
	VecEquipRefineItemCfg   vecEquipRefineItemCfg; //��Ʒ  
	string   gold; //�������  
	int32_t   id; //װ��ID  

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
	int32_t   valueMax; //�����ֵ  
	int32_t   valueMin; //��С��ֵ  

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
	VecEquipEquipAttributeCfg   vecEquipEquipAttributeCfg; //��������  
	float   strengthenProportion; //ǿ������  
	int32_t   holeMin; //��ʼ��С��Ƕ����  
	int32_t   refineAttributeNum; //���������������  
	VEC_STRING   vec_source; //װ����Դ  
	int32_t   isDrop; //�Ƿ����  
	int32_t   profession; //ְҵ����  
	float   refineProportion; //��������  
	string   refineAttribute_valueMax; //�����������ֵ  
	int32_t   position; //װ��λ��  
	int32_t   suitId; //��װID  
	int32_t   sex; //�Ա�����  
	string   refineAttribute_valueMin; //����������Сֵ  
	int32_t   holeMax; //��ʼ�����Ƕ����  
	int32_t   id; //װ��ID  
	string   desc; //װ������  
	int32_t   isCanbind; //�Ƿ��  
	string   refineAttribute_typeLibrary; //����������Կ�  
	int32_t   bindType; //������  
	int32_t   quality; //װ���̶�Ʒ��  
	int32_t   sellPrice; //���ۼ۸�  
	int32_t   isCanSell; //�Ƿ����  
	int32_t   wearLevel; //�����ȼ�����  

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
	string   itemRatio; //��Ʒϵ��  
	string   gold; //�������  
	float   recovery; //���ձ���  
	int32_t   id; //װ��ID  
	int32_t   itemId; //��ƷID  

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
	int32_t   chatType; //��������  
	int32_t   chatId; //����ID  

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
	int32_t   reviveMaxTimes; //�����������  
	int32_t   groupID; //����������ID  
	int32_t   sceneResource; //����ID  
	int32_t   rewardLibrary; //��ͨ��Ʒ��  
	int32_t   rewardCoin; //������Ϸ��  
	string   gradeRule; //��������  
	int32_t   goodRewardValue; //��Ʒ��  
	int32_t   playerAmountLowerLimit; //����Ҫ������  
	int32_t   goodRewardLibrary; //��Ʒ��  
	int32_t   duplicateType; //������������  
	int32_t   playerAmountTopLimit; //����Ҫ������  
	int32_t   dropNormalMonster; //��ͨ�������  
	string   duplicateConditionType; //������������  
	int32_t   linkDuplicateRequest; //ǰ�ø���Ҫ��  
	string   bossDesc; //BOSS˵������  
	int32_t   rewardExp; //��������  
	int32_t   dropEliteMonster; //��Ӣ�������  
	int32_t   levelLimit; //�ȼ�Ҫ������  
	int32_t   playType; //�����淨����  
	string   sceneAIScript; //����AI�ű�  
	int32_t   duplicateID; //����ID  
	int32_t   isAutoFight; //�Ƿ������Զ�ս��  
	string   rewardItem; //������Ʒ  
	string   unlockTask; //��������  
	string   trigEntry; //�������  

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
	int32_t   belongToType; //��������  
	int32_t   id; //������ID  
	int32_t   unlockLevel; //�����ȼ�  
	int32_t   buyMaxTimes; //��������  
	int32_t   groupTimesType; //���������  
	string   timesRes; //����ICON��Դ  
	int32_t   refreshType; //��������ˢ������  
	int32_t   groupType; //����������  
	string   buyPrice; //����۸�����  
	int32_t   groupTimes; //��������ֵ  
	string   openTime; //����ʱ��  
	string   refreshTime; //����ˢ��ʱ��  

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
	int32_t   belongToSceneID; //��������  
	int32_t   id; //·��ID  

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
	int32_t   belongToSceneID; //��������  
	int32_t   shapeType; //��״����  
	string   name; //��������  
	int32_t   id; //����ID  
	int32_t   subType; //ϸ������  
	int32_t   showType; //��ʾ����  

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
	string   name; //����  
	int32_t   id; //�±�  

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
	string   name; //����  
	int32_t   id; //�±�  

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
	string   name; //����  
	int32_t   id; //�±�  

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
	string   name; //����  
	int32_t   id; //�±�  

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
	string   name; //����  
	int32_t   id; //�±�  

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
	string   name; //����  
	int32_t   id; //�±�  

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
	int32_t   constantdata; //����  
	int32_t   constantid; //����id  

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
	string   tracker; //����׷��˵��  
	int32_t   comID; //�����������ID  

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
	int32_t   maxNum; //�������  
	int32_t   minNum; //��С����  
	int32_t   id; //id  
	int32_t   rand; //����  

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
	int32_t   drop_type; //��������  
	VecBoxDropItemCfg   vecBoxDropItemCfg; //������Ʒ  
	int32_t   id; //�����ID  

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
	string   Skill; //����  
	string   SkillLevel; //���ܵȼ�  

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
	string   Type; //����  
	string   Value; //ֵ  

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
	VecSkillSummonAttributeCfg   vecSkillSummonAttributeCfg; //����  
	int32_t   viewType; //��Ұ����  
	int32_t   summonType; //�ٻ�������  
	string   summonTime; //�ٻ������ʱ��  
	string   summonLevel; //�ٻ���ȼ�  
	int32_t   summonID; //�ٻ���ID  
	string   StopRange; //�赲��Χ  
	VecSkillSummonSummonCfg   vecSkillSummonSummonCfg; //Я��  
	string   view; //��Ұ  
	int32_t   summonAI; //�ٻ���AI  
	int32_t   pursueRange; //׷����Χ  

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
	int32_t   Type; //����  
	string   Param; //����  

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
	int32_t   stateBagID; //����״̬��id  
	string   stateBagName; //״̬������  
	string   effectResources; //��Ч·��  
	int32_t   startType; //��Ч����  
	string   endType; //�����������  
	string   stateBagIcon; //״̬��ͼ��  
	int32_t   stateBagRule; //ͬһ״̬�����ӹ���  
	int32_t   mask; //32λ����  
	VecSkillBuffEffectCfg   vecSkillBuffEffectCfg; //Ч��  
	int32_t   delayTime; //�ӳ���Чʱ��  

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
	int32_t   Target; //����  
	string   Parameter; //����  
	int32_t   ID; //id  
	string   Time; //����ʱ��  
	int32_t   Point; //��Ч��  
	int32_t   Rate; //�ɹ�����  

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
	string   displaceTime; //λ����Чʱ���  
	int32_t   skillID; //����id  
	string   attackValue; //���ӹ������̶�ֵ  
	int32_t   flySpeed; //�����ٶ�  
	int32_t   Relation; //��������  
	int32_t   breakType; //���������  
	string   rangeTypeValue; //��Χ����ֵ  
	int32_t   cost; //��������  
	int32_t   attackMinDistance; //������С����  
	string   minLevel; //ѧϰ�ȼ�  
	string   costValue; //��������  
	string   displaceDistance; //λ�ƾ���  
	int32_t   threat; //���ֵ  
	string   breakParameter; //����ϲ���  
	int32_t   damageType; //�˺�����  
	int32_t   releaseType; //�ͷ�����  
	int32_t   processTypes; //��������  
	int32_t   attackTime; //������ʱ��  
	int32_t   moveCast; //�Ƿ��ƶ�ʩ������  
	int32_t   rangeType; //��Χ����  
	VecSkillSkillStateBagCfg   vecSkillSkillStateBagCfg; //״̬��  
	string   damageRate; //�����˺�����  
	int32_t   goalMaxNum; //Ŀ���������  
	string   attackRate; //���ӹ���������  
	string   upgradeCost; //��������  
	string   damageTime ; //�˺���Чʱ���  
	string   damageValue; //�����˺��̶�ֵ  
	int32_t   skillMaxLevel; //�ȼ�����  
	int32_t   skillType; //��������  
	int32_t   profession; //ְҵ����  
	int32_t   cd; //cd  
	int32_t   move; //�����ͷ��ܷ����λ��  
	int32_t   attackDistance; //��������  
	int32_t   readyTime; //׼��ʱ��  
	int32_t   towards; //�Ƿ�ɸı䳯��  
	int32_t   type; //����  
	int32_t   warn; //�Ƿ�Ԥ��  
	string   name; //����  
	int32_t   breakTime; //�����ʱ��  

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
	int32_t   isnew; //�Ƿ��·�  
	string   ip; //ip  
	int32_t   id; //��ʶ  
	int32_t   state; //״̬  
	int32_t   areaid; //����  
	string   name; //��������  
	int32_t   port; //�˿�  

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
	string   name; //����  
	int32_t   id; //��ʶ  

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
	string   RemoveSkills; //�Ƴ�������  
	int32_t   Percentage; //���ްٷֱ�  
	string   AddSkills; //��Ӽ�����  

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
	VecAiAiHpPeriodCfg   vecAiAiHpPeriodCfg; //HP�׶�  
	int32_t   id; //AI����ID  
	string   initSkills; //���ܳس�ʼ������  

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
	int32_t   ItemId; //����  
	int32_t   rate; //����  

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
	int32_t   gainValue; //���������  
	int32_t   id; //��ԴID  
	int32_t   mapId; //��ͼId  
	int32_t   needLevel; //��Ҫ��ҵ�ȼ�  
	VecThingCollectGainCfg   vecThingCollectGainCfg; //���  
	int32_t   type; //����  
	int32_t   quelity; //Ʒ��  
	int32_t   makeCount; //��������  
	int32_t   needEnergy; //���Ļ���  
	int32_t   refreshTime; //ˢ��ʱ��  

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
	int32_t   liveTime; //����ʱ��  
	int32_t   usableTimes; //���ô���  
	int32_t   id; //���ID  
	int32_t   chantTime; //����ʱ��  
	int32_t   skill; //��������  
	string   res; //�����Դ  
	int32_t   drop; //����  
	int32_t   trigRange; //��������뾶  
	int32_t   trigAimType; //����Ŀ������  
	string   trigArea; //��������  
	int32_t   type; //�������  
	int32_t   isRefresh; //������ɷ�ˢ��  
	int32_t   coolTime; //��ȴʱ��  
	int32_t   refreshTime; //����ˢ������  

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
