#include "Common/TableData/SkillSkillCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


SkillSkillCfg::SkillSkillCfg()
{

}

SkillSkillCfg::~SkillSkillCfg()
{

}

void SkillSkillCfg::Clear()
{
	m_SkillSkillCfgMap.clear();
}


bool SkillSkillCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 68)
			{
				continue;
			}

			{
				SkillSkillCfgInfo info;
				std::string str = "";

				info.skillID = atoi(pRow->at(j++).c_str());	 //技能id
				info.name = pRow->at(j++).c_str();	 //名称
				info.profession = atoi(pRow->at(j++).c_str());	 //职业限制
				info.skillType = atoi(pRow->at(j++).c_str());	 //技能类型
				info.Relation = atoi(pRow->at(j++).c_str());	 //关联技能
				info.minLevel = pRow->at(j++).c_str();	 //学习等级
				info.skillMaxLevel = atoi(pRow->at(j++).c_str());	 //等级上限
				info.type = atoi(pRow->at(j++).c_str());	 //种类
				info.cd = atoi(pRow->at(j++).c_str());	 //cd
				info.cost = atoi(pRow->at(j++).c_str());	 //消耗类型
				info.costValue = pRow->at(j++).c_str();	 //消耗数据
				info.upgradeCost = pRow->at(j++).c_str();	 //升级消耗
				info.threat = atoi(pRow->at(j++).c_str());	 //仇恨值
				info.moveCast = atoi(pRow->at(j++).c_str());	 //是否移动施法动作
				info.releaseType = atoi(pRow->at(j++).c_str());	 //释放类型
				info.processTypes = atoi(pRow->at(j++).c_str());	 //过程类型
				info.flySpeed = atoi(pRow->at(j++).c_str());	 //飞行速度
				info.warn = atoi(pRow->at(j++).c_str());	 //是否预警
				info.readyTime = atoi(pRow->at(j++).c_str());	 //准备时间
				info.attackTime = atoi(pRow->at(j++).c_str());	 //攻击总时间
				info.damageTime  = pRow->at(j++).c_str();	 //伤害生效时间点
				info.displaceTime = pRow->at(j++).c_str();	 //位移生效时间点
				info.displaceDistance = pRow->at(j++).c_str();	 //位移距离
				info.move = atoi(pRow->at(j++).c_str());	 //技能释放能否产生位移
				info.towards = atoi(pRow->at(j++).c_str());	 //是否可改变朝向
				info.breakTime = atoi(pRow->at(j++).c_str());	 //被打断时机
				info.breakType = atoi(pRow->at(j++).c_str());	 //被打断类型
				info.breakParameter = pRow->at(j++).c_str();	 //被打断参数
				info.attackDistance = atoi(pRow->at(j++).c_str());	 //攻击距离
				info.rangeType = atoi(pRow->at(j++).c_str());	 //范围类型
				info.rangeTypeValue = pRow->at(j++).c_str();	 //范围类型值
				info.attackMinDistance = atoi(pRow->at(j++).c_str());	 //攻击最小距离
				info.goalMaxNum = atoi(pRow->at(j++).c_str());	 //目标最大数量
				info.damageType = atoi(pRow->at(j++).c_str());	 //伤害类型
				info.attackValue = pRow->at(j++).c_str();	 //附加攻击力固定值
				info.attackRate = pRow->at(j++).c_str();	 //附加攻击力倍率
				info.damageValue = pRow->at(j++).c_str();	 //附加伤害固定值
				info.damageRate = pRow->at(j++).c_str();	 //附加伤害倍率
				for (int t=0;t<5;t++) {
					SkillSkillStateBagCfgInfo stSkillSkillStateBagCfgInfo;
					info.vecSkillSkillStateBagCfg.push_back(stSkillSkillStateBagCfgInfo);
				}
				info.vecSkillSkillStateBagCfg[0].Target = atoi(pRow->at(j++).c_str());	 //归属
				info.vecSkillSkillStateBagCfg[0].Rate = atoi(pRow->at(j++).c_str());	 //成功几率
				info.vecSkillSkillStateBagCfg[0].Parameter = pRow->at(j++).c_str();	 //参数
				info.vecSkillSkillStateBagCfg[0].Time = pRow->at(j++).c_str();	 //持续时间
				info.vecSkillSkillStateBagCfg[0].Point = atoi(pRow->at(j++).c_str());	 //生效点
				info.vecSkillSkillStateBagCfg[0].ID = atoi(pRow->at(j++).c_str());	 //id
				info.vecSkillSkillStateBagCfg[1].Target = atoi(pRow->at(j++).c_str());	 //归属
				info.vecSkillSkillStateBagCfg[1].Rate = atoi(pRow->at(j++).c_str());	 //成功几率
				info.vecSkillSkillStateBagCfg[1].Parameter = pRow->at(j++).c_str();	 //参数
				info.vecSkillSkillStateBagCfg[1].Time = pRow->at(j++).c_str();	 //持续时间
				info.vecSkillSkillStateBagCfg[1].Point = atoi(pRow->at(j++).c_str());	 //生效点
				info.vecSkillSkillStateBagCfg[1].ID = atoi(pRow->at(j++).c_str());	 //id
				info.vecSkillSkillStateBagCfg[2].Target = atoi(pRow->at(j++).c_str());	 //归属
				info.vecSkillSkillStateBagCfg[2].Rate = atoi(pRow->at(j++).c_str());	 //成功几率
				info.vecSkillSkillStateBagCfg[2].Parameter = pRow->at(j++).c_str();	 //参数
				info.vecSkillSkillStateBagCfg[2].Time = pRow->at(j++).c_str();	 //持续时间
				info.vecSkillSkillStateBagCfg[2].Point = atoi(pRow->at(j++).c_str());	 //生效点
				info.vecSkillSkillStateBagCfg[2].ID = atoi(pRow->at(j++).c_str());	 //id
				info.vecSkillSkillStateBagCfg[3].Target = atoi(pRow->at(j++).c_str());	 //归属
				info.vecSkillSkillStateBagCfg[3].Rate = atoi(pRow->at(j++).c_str());	 //成功几率
				info.vecSkillSkillStateBagCfg[3].Parameter = pRow->at(j++).c_str();	 //参数
				info.vecSkillSkillStateBagCfg[3].Time = pRow->at(j++).c_str();	 //持续时间
				info.vecSkillSkillStateBagCfg[3].Point = atoi(pRow->at(j++).c_str());	 //生效点
				info.vecSkillSkillStateBagCfg[3].ID = atoi(pRow->at(j++).c_str());	 //id
				info.vecSkillSkillStateBagCfg[4].Target = atoi(pRow->at(j++).c_str());	 //归属
				info.vecSkillSkillStateBagCfg[4].Rate = atoi(pRow->at(j++).c_str());	 //成功几率
				info.vecSkillSkillStateBagCfg[4].Parameter = pRow->at(j++).c_str();	 //参数
				info.vecSkillSkillStateBagCfg[4].Time = pRow->at(j++).c_str();	 //持续时间
				info.vecSkillSkillStateBagCfg[4].Point = atoi(pRow->at(j++).c_str());	 //生效点
				info.vecSkillSkillStateBagCfg[4].ID = atoi(pRow->at(j++).c_str());	 //id


				
				if (nullptr != GetSkillSkillCfgInfo(info.skillID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.skillID);
					return false;
				}

				m_SkillSkillCfgMap[info.skillID] = info;
			}
		}
	}

	return true;
}

bool SkillSkillCfg::UnInit()
{
	Clear();
	return true;
}

const SkillSkillCfgInfo *SkillSkillCfg::GetSkillSkillCfgInfo(int32_t skillID)
{
	SkillSkillCfgMap::iterator iter = m_SkillSkillCfgMap.find(skillID);
	return (iter != m_SkillSkillCfgMap.end()) ? &iter->second : nullptr;
}
