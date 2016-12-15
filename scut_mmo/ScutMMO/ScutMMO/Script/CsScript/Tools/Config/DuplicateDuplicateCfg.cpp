#include "Common/TableData/DuplicateDuplicateCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


DuplicateDuplicateCfg::DuplicateDuplicateCfg()
{

}

DuplicateDuplicateCfg::~DuplicateDuplicateCfg()
{

}

void DuplicateDuplicateCfg::Clear()
{
	m_DuplicateDuplicateCfgMap.clear();
}


bool DuplicateDuplicateCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 25)
			{
				continue;
			}

			{
				DuplicateDuplicateCfgInfo info;
				std::string str = "";

				info.duplicateID = atoi(pRow->at(j++).c_str());	 //副本ID
				info.groupID = atoi(pRow->at(j++).c_str());	 //所属副本组ID
				info.duplicateType = atoi(pRow->at(j++).c_str());	 //副本内容类型
				info.playType = atoi(pRow->at(j++).c_str());	 //副本玩法类型
				info.sceneResource = atoi(pRow->at(j++).c_str());	 //场景ID
				info.levelLimit = atoi(pRow->at(j++).c_str());	 //等级要求下限
				info.linkDuplicateRequest = atoi(pRow->at(j++).c_str());	 //前置副本要求
				info.unlockTask = pRow->at(j++).c_str();	 //解锁任务
				info.playerAmountTopLimit = atoi(pRow->at(j++).c_str());	 //人数要求上限
				info.playerAmountLowerLimit = atoi(pRow->at(j++).c_str());	 //人数要求下限
				info.isAutoFight = atoi(pRow->at(j++).c_str());	 //是否允许自动战斗
				info.duplicateConditionType = pRow->at(j++).c_str();	 //副本条件类型
				info.reviveMaxTimes = atoi(pRow->at(j++).c_str());	 //复活次数上限
				info.gradeRule = pRow->at(j++).c_str();	 //评级规则
				info.rewardLibrary = atoi(pRow->at(j++).c_str());	 //普通奖品库
				info.goodRewardLibrary = atoi(pRow->at(j++).c_str());	 //良品库
				info.goodRewardValue = atoi(pRow->at(j++).c_str());	 //良品阀
				info.rewardExp = atoi(pRow->at(j++).c_str());	 //奖励经验
				info.rewardCoin = atoi(pRow->at(j++).c_str());	 //奖励游戏币
				info.rewardItem = pRow->at(j++).c_str();	 //奖励物品
				info.dropNormalMonster = atoi(pRow->at(j++).c_str());	 //普通怪物掉落
				info.dropEliteMonster = atoi(pRow->at(j++).c_str());	 //精英怪物掉落
				info.sceneAIScript = pRow->at(j++).c_str();	 //场景AI脚本
				info.bossDesc = pRow->at(j++).c_str();	 //BOSS说明序列
				info.trigEntry = pRow->at(j++).c_str();	 //触发入口


				
				if (nullptr != GetDuplicateDuplicateCfgInfo(info.duplicateID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.duplicateID);
					return false;
				}

				m_DuplicateDuplicateCfgMap[info.duplicateID] = info;
			}
		}
	}

	return true;
}

bool DuplicateDuplicateCfg::UnInit()
{
	Clear();
	return true;
}

const DuplicateDuplicateCfgInfo *DuplicateDuplicateCfg::GetDuplicateDuplicateCfgInfo(int32_t duplicateID)
{
	DuplicateDuplicateCfgMap::iterator iter = m_DuplicateDuplicateCfgMap.find(duplicateID);
	return (iter != m_DuplicateDuplicateCfgMap.end()) ? &iter->second : nullptr;
}
