
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class AchievementAchievementrewardCfg : public ManualSingleton <AchievementAchievementrewardCfg>
{
	friend ManualSingleton <AchievementAchievementrewardCfg>;
public:
	AchievementAchievementrewardCfg();
	~AchievementAchievementrewardCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const AchievementAchievementrewardCfgInfo *GetAchievementAchievementrewardCfgInfo(int32_t achievementPrizeId);
	const AchievementAchievementrewardCfgMap *GetAchievementAchievementrewardCfgMap() { return &m_AchievementAchievementrewardCfgMap; }
private:
	AchievementAchievementrewardCfgMap m_AchievementAchievementrewardCfgMap;
};

#define  g_MakeAchievementAchievementrewardCfgTable() (AchievementAchievementrewardCfg::Instance())
#define  g_GetAchievementAchievementrewardCfgTable() (AchievementAchievementrewardCfg::GetInstance())
#define  g_DelAchievementAchievementrewardCfgTable() (AchievementAchievementrewardCfg::Destroy())