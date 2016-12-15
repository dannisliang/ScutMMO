
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class AchievementAchievementCfg : public ManualSingleton <AchievementAchievementCfg>
{
	friend ManualSingleton <AchievementAchievementCfg>;
public:
	AchievementAchievementCfg();
	~AchievementAchievementCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const AchievementAchievementCfgInfo *GetAchievementAchievementCfgInfo(int32_t achievementId);
	const AchievementAchievementCfgMap *GetAchievementAchievementCfgMap() { return &m_AchievementAchievementCfgMap; }
private:
	AchievementAchievementCfgMap m_AchievementAchievementCfgMap;
};

#define  g_MakeAchievementAchievementCfgTable() (AchievementAchievementCfg::Instance())
#define  g_GetAchievementAchievementCfgTable() (AchievementAchievementCfg::GetInstance())
#define  g_DelAchievementAchievementCfgTable() (AchievementAchievementCfg::Destroy())