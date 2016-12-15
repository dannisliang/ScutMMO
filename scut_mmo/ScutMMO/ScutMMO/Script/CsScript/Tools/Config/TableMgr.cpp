#include "base/core/os/string.h"
#include "Common/TableData/TableMgr.h"
#include "Common/TableData/AttributeSuppressCfg.h"
#include "Common/TableData/AttributeConvertCfg.h"
#include "Common/TableData/PkmodePkWantedCfg.h"
#include "Common/TableData/AvocationAvocationskillCfg.h"
#include "Common/TableData/AvocationComposeCfg.h"
#include "Common/TableData/DropDropCfg.h"
#include "Common/TableData/MapMapCfg.h"
#include "Common/TableData/RoleBornCfg.h"
#include "Common/TableData/RoleMasterCfg.h"
#include "Common/TableData/RoleAssassinCfg.h"
#include "Common/TableData/RoleExpCfg.h"
#include "Common/TableData/RoleShooterCfg.h"
#include "Common/TableData/RoleWarriorCfg.h"
#include "Common/TableData/MallMallCfg.h"
#include "Common/TableData/MallMalltypeCfg.h"
#include "Common/TableData/ItemItemCfg.h"
#include "Common/TableData/TeleportBornCfg.h"
#include "Common/TableData/TeleportSafeareaCfg.h"
#include "Common/TableData/TeleportTeleportCfg.h"
#include "Common/TableData/ComposeComposeCfg.h"
#include "Common/TableData/NpcNpcCfg.h"
#include "Common/TableData/NpcNpcfunctionCfg.h"
#include "Common/TableData/MonsterMonsterCfg.h"
#include "Common/TableData/PetPetCfg.h"
#include "Common/TableData/PetPetskillCfg.h"
#include "Common/TableData/AchievementAchievementCfg.h"
#include "Common/TableData/AchievementAchievementrewardCfg.h"
#include "Common/TableData/EquipFashionCfg.h"
#include "Common/TableData/EquipSuitCfg.h"
#include "Common/TableData/EquipRefineCfg.h"
#include "Common/TableData/EquipEquipCfg.h"
#include "Common/TableData/EquipStrengthenCfg.h"
#include "Common/TableData/ChatChatCfg.h"
#include "Common/TableData/DuplicateDuplicateCfg.h"
#include "Common/TableData/DuplicateGroupCfg.h"
#include "Common/TableData/AreaPathCfg.h"
#include "Common/TableData/AreaAreaCfg.h"
#include "Common/TableData/RandomnameWomanfirstCfg.h"
#include "Common/TableData/RandomnameManthirdCfg.h"
#include "Common/TableData/RandomnameWomanthirdCfg.h"
#include "Common/TableData/RandomnameMansecondCfg.h"
#include "Common/TableData/RandomnameManfirstCfg.h"
#include "Common/TableData/RandomnameWomansecondCfg.h"
#include "Common/TableData/ConstantConstantCfg.h"
#include "Common/TableData/TasktrackerTasktrackerCfg.h"
#include "Common/TableData/BoxDropCfg.h"
#include "Common/TableData/SkillSummonCfg.h"
#include "Common/TableData/SkillBuffCfg.h"
#include "Common/TableData/SkillSkillCfg.h"
#include "Common/TableData/SrvlistServerCfg.h"
#include "Common/TableData/SrvlistAreaCfg.h"
#include "Common/TableData/AiAiCfg.h"
#include "Common/TableData/ThingCollectCfg.h"
#include "Common/TableData/ThingThingCfg.h"


TableMgr::TableMgr()
{}

TableMgr::~TableMgr()
{}

bool TableMgr::Init()
{
	bool result = false;
	bool retCode = true;

    retCode = g_MakeAttributeSuppressCfgTable()->Init("./data/config/Attribute_suppress.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeAttributeConvertCfgTable()->Init("./data/config/Attribute_convert.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakePkmodePkWantedCfgTable()->Init("./data/config/Pkmode_pkWanted.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeAvocationAvocationskillCfgTable()->Init("./data/config/Avocation_avocationskill.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeAvocationComposeCfgTable()->Init("./data/config/Avocation_compose.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeDropDropCfgTable()->Init("./data/config/Drop_drop.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeMapMapCfgTable()->Init("./data/config/Map_map.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRoleBornCfgTable()->Init("./data/config/Role_born.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRoleMasterCfgTable()->Init("./data/config/Role_master.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRoleAssassinCfgTable()->Init("./data/config/Role_assassin.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRoleExpCfgTable()->Init("./data/config/Role_exp.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRoleShooterCfgTable()->Init("./data/config/Role_shooter.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRoleWarriorCfgTable()->Init("./data/config/Role_warrior.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeMallMallCfgTable()->Init("./data/config/Mall_mall.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeMallMalltypeCfgTable()->Init("./data/config/Mall_malltype.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeItemItemCfgTable()->Init("./data/config/Item_item.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeTeleportBornCfgTable()->Init("./data/config/Teleport_born.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeTeleportSafeareaCfgTable()->Init("./data/config/Teleport_safearea.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeTeleportTeleportCfgTable()->Init("./data/config/Teleport_teleport.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeComposeComposeCfgTable()->Init("./data/config/Compose_compose.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeNpcNpcCfgTable()->Init("./data/config/Npc_npc.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeNpcNpcfunctionCfgTable()->Init("./data/config/Npc_npcfunction.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeMonsterMonsterCfgTable()->Init("./data/config/Monster_monster.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakePetPetCfgTable()->Init("./data/config/Pet_pet.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakePetPetskillCfgTable()->Init("./data/config/Pet_petskill.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeAchievementAchievementCfgTable()->Init("./data/config/Achievement_achievement.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeAchievementAchievementrewardCfgTable()->Init("./data/config/Achievement_achievementreward.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeEquipFashionCfgTable()->Init("./data/config/Equip_fashion.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeEquipSuitCfgTable()->Init("./data/config/Equip_suit.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeEquipRefineCfgTable()->Init("./data/config/Equip_refine.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeEquipEquipCfgTable()->Init("./data/config/Equip_equip.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeEquipStrengthenCfgTable()->Init("./data/config/Equip_strengthen.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeChatChatCfgTable()->Init("./data/config/Chat_chat.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeDuplicateDuplicateCfgTable()->Init("./data/config/Duplicate_duplicate.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeDuplicateGroupCfgTable()->Init("./data/config/Duplicate_group.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeAreaPathCfgTable()->Init("./data/config/Area_path.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeAreaAreaCfgTable()->Init("./data/config/Area_area.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRandomnameWomanfirstCfgTable()->Init("./data/config/Randomname_womanfirst.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRandomnameManthirdCfgTable()->Init("./data/config/Randomname_manthird.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRandomnameWomanthirdCfgTable()->Init("./data/config/Randomname_womanthird.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRandomnameMansecondCfgTable()->Init("./data/config/Randomname_mansecond.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRandomnameManfirstCfgTable()->Init("./data/config/Randomname_manfirst.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeRandomnameWomansecondCfgTable()->Init("./data/config/Randomname_womansecond.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeConstantConstantCfgTable()->Init("./data/config/Constant_constant.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeTasktrackerTasktrackerCfgTable()->Init("./data/config/Tasktracker_tasktracker.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeBoxDropCfgTable()->Init("./data/config/Box_drop.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeSkillSummonCfgTable()->Init("./data/config/Skill_summon.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeSkillBuffCfgTable()->Init("./data/config/Skill_buff.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeSkillSkillCfgTable()->Init("./data/config/Skill_skill.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeSrvlistServerCfgTable()->Init("./data/config/Srvlist_server.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeSrvlistAreaCfgTable()->Init("./data/config/Srvlist_area.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeAiAiCfgTable()->Init("./data/config/Ai_ai.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeThingCollectCfgTable()->Init("./data/config/Thing_collect.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);
    retCode = g_MakeThingThingCfgTable()->Init("./data/config/Thing_thing.txt","#");
	MMOLOG_PROCESS_ERROR(retCode);



	result = true;
Exit0:
	return result;
}

bool TableMgr::UnInit()
{
    g_GetAttributeSuppressCfgTable()->UnInit();
	g_DelAttributeSuppressCfgTable();
    g_GetAttributeConvertCfgTable()->UnInit();
	g_DelAttributeConvertCfgTable();
    g_GetPkmodePkWantedCfgTable()->UnInit();
	g_DelPkmodePkWantedCfgTable();
    g_GetAvocationAvocationskillCfgTable()->UnInit();
	g_DelAvocationAvocationskillCfgTable();
    g_GetAvocationComposeCfgTable()->UnInit();
	g_DelAvocationComposeCfgTable();
    g_GetDropDropCfgTable()->UnInit();
	g_DelDropDropCfgTable();
    g_GetMapMapCfgTable()->UnInit();
	g_DelMapMapCfgTable();
    g_GetRoleBornCfgTable()->UnInit();
	g_DelRoleBornCfgTable();
    g_GetRoleMasterCfgTable()->UnInit();
	g_DelRoleMasterCfgTable();
    g_GetRoleAssassinCfgTable()->UnInit();
	g_DelRoleAssassinCfgTable();
    g_GetRoleExpCfgTable()->UnInit();
	g_DelRoleExpCfgTable();
    g_GetRoleShooterCfgTable()->UnInit();
	g_DelRoleShooterCfgTable();
    g_GetRoleWarriorCfgTable()->UnInit();
	g_DelRoleWarriorCfgTable();
    g_GetMallMallCfgTable()->UnInit();
	g_DelMallMallCfgTable();
    g_GetMallMalltypeCfgTable()->UnInit();
	g_DelMallMalltypeCfgTable();
    g_GetItemItemCfgTable()->UnInit();
	g_DelItemItemCfgTable();
    g_GetTeleportBornCfgTable()->UnInit();
	g_DelTeleportBornCfgTable();
    g_GetTeleportSafeareaCfgTable()->UnInit();
	g_DelTeleportSafeareaCfgTable();
    g_GetTeleportTeleportCfgTable()->UnInit();
	g_DelTeleportTeleportCfgTable();
    g_GetComposeComposeCfgTable()->UnInit();
	g_DelComposeComposeCfgTable();
    g_GetNpcNpcCfgTable()->UnInit();
	g_DelNpcNpcCfgTable();
    g_GetNpcNpcfunctionCfgTable()->UnInit();
	g_DelNpcNpcfunctionCfgTable();
    g_GetMonsterMonsterCfgTable()->UnInit();
	g_DelMonsterMonsterCfgTable();
    g_GetPetPetCfgTable()->UnInit();
	g_DelPetPetCfgTable();
    g_GetPetPetskillCfgTable()->UnInit();
	g_DelPetPetskillCfgTable();
    g_GetAchievementAchievementCfgTable()->UnInit();
	g_DelAchievementAchievementCfgTable();
    g_GetAchievementAchievementrewardCfgTable()->UnInit();
	g_DelAchievementAchievementrewardCfgTable();
    g_GetEquipFashionCfgTable()->UnInit();
	g_DelEquipFashionCfgTable();
    g_GetEquipSuitCfgTable()->UnInit();
	g_DelEquipSuitCfgTable();
    g_GetEquipRefineCfgTable()->UnInit();
	g_DelEquipRefineCfgTable();
    g_GetEquipEquipCfgTable()->UnInit();
	g_DelEquipEquipCfgTable();
    g_GetEquipStrengthenCfgTable()->UnInit();
	g_DelEquipStrengthenCfgTable();
    g_GetChatChatCfgTable()->UnInit();
	g_DelChatChatCfgTable();
    g_GetDuplicateDuplicateCfgTable()->UnInit();
	g_DelDuplicateDuplicateCfgTable();
    g_GetDuplicateGroupCfgTable()->UnInit();
	g_DelDuplicateGroupCfgTable();
    g_GetAreaPathCfgTable()->UnInit();
	g_DelAreaPathCfgTable();
    g_GetAreaAreaCfgTable()->UnInit();
	g_DelAreaAreaCfgTable();
    g_GetRandomnameWomanfirstCfgTable()->UnInit();
	g_DelRandomnameWomanfirstCfgTable();
    g_GetRandomnameManthirdCfgTable()->UnInit();
	g_DelRandomnameManthirdCfgTable();
    g_GetRandomnameWomanthirdCfgTable()->UnInit();
	g_DelRandomnameWomanthirdCfgTable();
    g_GetRandomnameMansecondCfgTable()->UnInit();
	g_DelRandomnameMansecondCfgTable();
    g_GetRandomnameManfirstCfgTable()->UnInit();
	g_DelRandomnameManfirstCfgTable();
    g_GetRandomnameWomansecondCfgTable()->UnInit();
	g_DelRandomnameWomansecondCfgTable();
    g_GetConstantConstantCfgTable()->UnInit();
	g_DelConstantConstantCfgTable();
    g_GetTasktrackerTasktrackerCfgTable()->UnInit();
	g_DelTasktrackerTasktrackerCfgTable();
    g_GetBoxDropCfgTable()->UnInit();
	g_DelBoxDropCfgTable();
    g_GetSkillSummonCfgTable()->UnInit();
	g_DelSkillSummonCfgTable();
    g_GetSkillBuffCfgTable()->UnInit();
	g_DelSkillBuffCfgTable();
    g_GetSkillSkillCfgTable()->UnInit();
	g_DelSkillSkillCfgTable();
    g_GetSrvlistServerCfgTable()->UnInit();
	g_DelSrvlistServerCfgTable();
    g_GetSrvlistAreaCfgTable()->UnInit();
	g_DelSrvlistAreaCfgTable();
    g_GetAiAiCfgTable()->UnInit();
	g_DelAiAiCfgTable();
    g_GetThingCollectCfgTable()->UnInit();
	g_DelThingCollectCfgTable();
    g_GetThingThingCfgTable()->UnInit();
	g_DelThingThingCfgTable();


	return true;
}
