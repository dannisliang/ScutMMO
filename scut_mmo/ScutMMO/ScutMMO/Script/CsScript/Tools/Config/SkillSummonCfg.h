
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class SkillSummonCfg : public ManualSingleton <SkillSummonCfg>
{
	friend ManualSingleton <SkillSummonCfg>;
public:
	SkillSummonCfg();
	~SkillSummonCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const SkillSummonCfgInfo *GetSkillSummonCfgInfo(int32_t summonID);
	const SkillSummonCfgMap *GetSkillSummonCfgMap() { return &m_SkillSummonCfgMap; }
private:
	SkillSummonCfgMap m_SkillSummonCfgMap;
};

#define  g_MakeSkillSummonCfgTable() (SkillSummonCfg::Instance())
#define  g_GetSkillSummonCfgTable() (SkillSummonCfg::GetInstance())
#define  g_DelSkillSummonCfgTable() (SkillSummonCfg::Destroy())