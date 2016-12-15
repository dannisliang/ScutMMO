
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class SkillSkillCfg : public ManualSingleton <SkillSkillCfg>
{
	friend ManualSingleton <SkillSkillCfg>;
public:
	SkillSkillCfg();
	~SkillSkillCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const SkillSkillCfgInfo *GetSkillSkillCfgInfo(int32_t skillID);
	const SkillSkillCfgMap *GetSkillSkillCfgMap() { return &m_SkillSkillCfgMap; }
private:
	SkillSkillCfgMap m_SkillSkillCfgMap;
};

#define  g_MakeSkillSkillCfgTable() (SkillSkillCfg::Instance())
#define  g_GetSkillSkillCfgTable() (SkillSkillCfg::GetInstance())
#define  g_DelSkillSkillCfgTable() (SkillSkillCfg::Destroy())