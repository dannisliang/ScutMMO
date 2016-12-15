
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class SkillBuffCfg : public ManualSingleton <SkillBuffCfg>
{
	friend ManualSingleton <SkillBuffCfg>;
public:
	SkillBuffCfg();
	~SkillBuffCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const SkillBuffCfgInfo *GetSkillBuffCfgInfo(int32_t stateBagID);
	const SkillBuffCfgMap *GetSkillBuffCfgMap() { return &m_SkillBuffCfgMap; }
private:
	SkillBuffCfgMap m_SkillBuffCfgMap;
};

#define  g_MakeSkillBuffCfgTable() (SkillBuffCfg::Instance())
#define  g_GetSkillBuffCfgTable() (SkillBuffCfg::GetInstance())
#define  g_DelSkillBuffCfgTable() (SkillBuffCfg::Destroy())