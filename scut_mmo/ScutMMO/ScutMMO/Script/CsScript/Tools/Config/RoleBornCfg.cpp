#include "Common/TableData/RoleBornCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RoleBornCfg::RoleBornCfg()
{

}

RoleBornCfg::~RoleBornCfg()
{

}

void RoleBornCfg::Clear()
{
	m_RoleBornCfgMap.clear();
}


bool RoleBornCfg::Init(const char *szCfgFile, const char *szSplitChar)
{
	CfgReader reader;
	if (!reader.LoadCfg(szCfgFile, szSplitChar))
	{
		LogErrFmtPrint("[common] reader config error....cfg:%s ", szCfgFile);
		return false;
	}
	int32_t row = reader.GetRowCount();
	for (int i = 0; i < row; ++i)
	{
		const VecRow *pRow = reader.GetRow(i);
		if (nullptr != pRow)
		{
			int32_t colun = pRow->size();
			int32_t j = 0;
			if (colun < 106)
			{
				continue;
			}

			{
				RoleBornCfgInfo info;
				std::string str = "";

				info.bornID = atoi(pRow->at(j++).c_str());	 //主键ID
				info.professionID = atoi(pRow->at(j++).c_str());	 //职业ID
				info.professionName = pRow->at(j++).c_str();	 //职业名称
				info.placement = pRow->at(j++).c_str();	 //职业介绍
				info.race = atoi(pRow->at(j++).c_str());	 //种族
				info.gender = atoi(pRow->at(j++).c_str());	 //性别
				info.bornLevel = atoi(pRow->at(j++).c_str());	 //出生等级
				info.bornTitle = atoi(pRow->at(j++).c_str());	 //携带称号
				info.diamond = atoi(pRow->at(j++).c_str());	 //携带钻石
				info.bindDiamond = atoi(pRow->at(j++).c_str());	 //携带绑定钻石
				info.gold = atoi(pRow->at(j++).c_str());	 //携带金币
				info.bindGold = atoi(pRow->at(j++).c_str());	 //携带绑定金币
				info.mapID = atoi(pRow->at(j++).c_str());	 //出生地图ID
				info.mapX = atoi(pRow->at(j++).c_str());	 //出生地的X点
				info.mapY = atoi(pRow->at(j++).c_str());	 //出生地的Y点
				info.mapZ = atoi(pRow->at(j++).c_str());	 //出生地的Z点
				info.birthFace = atoi(pRow->at(j++).c_str());	 //出生朝向
				info.icons = pRow->at(j++).c_str();	 //头像图标
				info.loginAvata = pRow->at(j++).c_str();	 //创角界面模型
				info.weaponAvata = pRow->at(j++).c_str();	 //出生时武器模型
				info.roleAvata = pRow->at(j++).c_str();	 //出生时模型
				info.carryWeapons = atoi(pRow->at(j++).c_str());	 //装备武器
				info.carryArmor = atoi(pRow->at(j++).c_str());	 //装备衣服
				info.carryCloak = atoi(pRow->at(j++).c_str());	 //装备披风
				info.carryShoes = atoi(pRow->at(j++).c_str());	 //装备鞋子
				info.carryNecklace = atoi(pRow->at(j++).c_str());	 //装备项链
				info.carryAmulet = atoi(pRow->at(j++).c_str());	 //装备护符
				info.carryBracer1 = atoi(pRow->at(j++).c_str());	 //装备护腕
				info.carryBracer2 = atoi(pRow->at(j++).c_str());	 //装备护腕
				info.carryRing1 = atoi(pRow->at(j++).c_str());	 //装备戒指
				info.carryRing2 = atoi(pRow->at(j++).c_str());	 //装备戒指
				info.carryFashionWeapons = atoi(pRow->at(j++).c_str());	 //装备时装(武器)
				info.carryFashionArmor = atoi(pRow->at(j++).c_str());	 //装备时装(衣服)
				info.carryWings = atoi(pRow->at(j++).c_str());	 //装备翅膀
				for (int t=0;t<4;t++) {
					int32_t data;
					info.vec_actBuff.push_back(data);
				}
				info.vec_actBuff[0] = atoi(pRow->at(j++).c_str());	 //生成buff
				info.vec_actBuff[1] = atoi(pRow->at(j++).c_str());	 //生成buff
				info.vec_actBuff[2] = atoi(pRow->at(j++).c_str());	 //生成buff
				info.vec_actBuff[3] = atoi(pRow->at(j++).c_str());	 //生成buff
				for (int t=0;t<6;t++) {
					int32_t data;
					info.vec_actSkill.push_back(data);
				}
				info.vec_actSkill[0] = atoi(pRow->at(j++).c_str());	 //生成技能
				info.vec_actSkill[1] = atoi(pRow->at(j++).c_str());	 //生成技能
				info.vec_actSkill[2] = atoi(pRow->at(j++).c_str());	 //生成技能
				info.vec_actSkill[3] = atoi(pRow->at(j++).c_str());	 //生成技能
				info.vec_actSkill[4] = atoi(pRow->at(j++).c_str());	 //生成技能
				info.vec_actSkill[5] = atoi(pRow->at(j++).c_str());	 //生成技能
				for (int t=0;t<31;t++) {
					RoleBornItemCfgInfo stRoleBornItemCfgInfo;
					info.vecRoleBornItemCfg.push_back(stRoleBornItemCfgInfo);
				}
				info.vecRoleBornItemCfg[0].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[0].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[1].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[1].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[2].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[2].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[3].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[3].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[4].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[4].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[5].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[5].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[6].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[6].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[7].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[7].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[8].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[8].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[9].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[9].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[10].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[10].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[11].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[11].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[12].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[12].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[13].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[13].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[14].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[14].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[15].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[15].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[16].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[16].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[17].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[17].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[18].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[18].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[19].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[19].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[20].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[20].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[21].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[21].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[22].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[22].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[23].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[23].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[24].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[24].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[25].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[25].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[26].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[26].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[27].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[27].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[28].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[28].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[29].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[29].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecRoleBornItemCfg[30].name = atoi(pRow->at(j++).c_str());	 //名称
				info.vecRoleBornItemCfg[30].num = atoi(pRow->at(j++).c_str());	 //数量


				
				if (nullptr != GetRoleBornCfgInfo(info.bornID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.bornID);
					return false;
				}

				m_RoleBornCfgMap[info.bornID] = info;
			}
		}
	}

	return true;
}

bool RoleBornCfg::UnInit()
{
	Clear();
	return true;
}

const RoleBornCfgInfo *RoleBornCfg::GetRoleBornCfgInfo(int32_t bornID)
{
	RoleBornCfgMap::iterator iter = m_RoleBornCfgMap.find(bornID);
	return (iter != m_RoleBornCfgMap.end()) ? &iter->second : nullptr;
}
