#include "Common/TableData/AchievementAchievementrewardCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


AchievementAchievementrewardCfg::AchievementAchievementrewardCfg()
{

}

AchievementAchievementrewardCfg::~AchievementAchievementrewardCfg()
{

}

void AchievementAchievementrewardCfg::Clear()
{
	m_AchievementAchievementrewardCfgMap.clear();
}


bool AchievementAchievementrewardCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 13)
			{
				continue;
			}

			{
				AchievementAchievementrewardCfgInfo info;
				std::string str = "";

				info.achievementPrizeId = atoi(pRow->at(j++).c_str());	 //成就奖励ID
				info.achievementType = atoi(pRow->at(j++).c_str());	 //成就类型
				info.achievementPointValue = atoi(pRow->at(j++).c_str());	 //所需成就点值
				for (int t=0;t<5;t++) {
					AchievementAchievementrewardRewardCfgInfo stAchievementAchievementrewardRewardCfgInfo;
					info.vecAchievementAchievementrewardRewardCfg.push_back(stAchievementAchievementrewardRewardCfgInfo);
				}
				info.vecAchievementAchievementrewardRewardCfg[0].Value = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAchievementAchievementrewardRewardCfg[0].ID = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAchievementAchievementrewardRewardCfg[1].Value = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAchievementAchievementrewardRewardCfg[1].ID = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAchievementAchievementrewardRewardCfg[2].Value = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAchievementAchievementrewardRewardCfg[2].ID = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAchievementAchievementrewardRewardCfg[3].Value = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAchievementAchievementrewardRewardCfg[3].ID = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAchievementAchievementrewardRewardCfg[4].Value = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAchievementAchievementrewardRewardCfg[4].ID = atoi(pRow->at(j++).c_str());	 //ID


				
				if (nullptr != GetAchievementAchievementrewardCfgInfo(info.achievementPrizeId))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.achievementPrizeId);
					return false;
				}

				m_AchievementAchievementrewardCfgMap[info.achievementPrizeId] = info;
			}
		}
	}

	return true;
}

bool AchievementAchievementrewardCfg::UnInit()
{
	Clear();
	return true;
}

const AchievementAchievementrewardCfgInfo *AchievementAchievementrewardCfg::GetAchievementAchievementrewardCfgInfo(int32_t achievementPrizeId)
{
	AchievementAchievementrewardCfgMap::iterator iter = m_AchievementAchievementrewardCfgMap.find(achievementPrizeId);
	return (iter != m_AchievementAchievementrewardCfgMap.end()) ? &iter->second : nullptr;
}
