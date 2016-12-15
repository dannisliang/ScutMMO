#include "Common/TableData/AchievementAchievementCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


AchievementAchievementCfg::AchievementAchievementCfg()
{

}

AchievementAchievementCfg::~AchievementAchievementCfg()
{

}

void AchievementAchievementCfg::Clear()
{
	m_AchievementAchievementCfgMap.clear();
}


bool AchievementAchievementCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 18)
			{
				continue;
			}

			{
				AchievementAchievementCfgInfo info;
				std::string str = "";

				info.achievementId = atoi(pRow->at(j++).c_str());	 //成就ID
				info.achievementLevel = atoi(pRow->at(j++).c_str());	 //成就触发等级
				info.beforeAchievement = atoi(pRow->at(j++).c_str());	 //前置成就ID
				info.achievementType = atoi(pRow->at(j++).c_str());	 //成就类型
				info.achievementSubType = atoi(pRow->at(j++).c_str());	 //事件类型
				info.achievementSubSunType = atoi(pRow->at(j++).c_str());	 //事件子类型
				info.achievementObjectID = atoi(pRow->at(j++).c_str());	 //事件目标ID
				info.achievementObjectValue = atoi(pRow->at(j++).c_str());	 //事件目标完成值
				info.achievementDia = atoi(pRow->at(j++).c_str());	 //获得绑定钻石数量
				info.achievementGold = atoi(pRow->at(j++).c_str());	 //获得金币数量
				info.achievementEXP = atoi(pRow->at(j++).c_str());	 //获得经验
				info.achievementPoint = atoi(pRow->at(j++).c_str());	 //获取成就点数量
				for (int t=0;t<3;t++) {
					AchievementAchievementItemRewardCfgInfo stAchievementAchievementItemRewardCfgInfo;
					info.vecAchievementAchievementItemRewardCfg.push_back(stAchievementAchievementItemRewardCfgInfo);
				}
				info.vecAchievementAchievementItemRewardCfg[0].Value = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAchievementAchievementItemRewardCfg[0].ID = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAchievementAchievementItemRewardCfg[1].Value = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAchievementAchievementItemRewardCfg[1].ID = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAchievementAchievementItemRewardCfg[2].Value = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAchievementAchievementItemRewardCfg[2].ID = atoi(pRow->at(j++).c_str());	 //ID


				
				if (nullptr != GetAchievementAchievementCfgInfo(info.achievementId))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.achievementId);
					return false;
				}

				m_AchievementAchievementCfgMap[info.achievementId] = info;
			}
		}
	}

	return true;
}

bool AchievementAchievementCfg::UnInit()
{
	Clear();
	return true;
}

const AchievementAchievementCfgInfo *AchievementAchievementCfg::GetAchievementAchievementCfgInfo(int32_t achievementId)
{
	AchievementAchievementCfgMap::iterator iter = m_AchievementAchievementCfgMap.find(achievementId);
	return (iter != m_AchievementAchievementCfgMap.end()) ? &iter->second : nullptr;
}
