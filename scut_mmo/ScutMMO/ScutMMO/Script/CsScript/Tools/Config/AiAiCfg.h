
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class AiAiCfg : public ManualSingleton <AiAiCfg>
{
	friend ManualSingleton <AiAiCfg>;
public:
	AiAiCfg();
	~AiAiCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const AiAiCfgInfo *GetAiAiCfgInfo(int32_t id);
	const AiAiCfgMap *GetAiAiCfgMap() { return &m_AiAiCfgMap; }
private:
	AiAiCfgMap m_AiAiCfgMap;
};

#define  g_MakeAiAiCfgTable() (AiAiCfg::Instance())
#define  g_GetAiAiCfgTable() (AiAiCfg::GetInstance())
#define  g_DelAiAiCfgTable() (AiAiCfg::Destroy())