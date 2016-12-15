
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class ComposeComposeCfg : public ManualSingleton <ComposeComposeCfg>
{
	friend ManualSingleton <ComposeComposeCfg>;
public:
	ComposeComposeCfg();
	~ComposeComposeCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const ComposeComposeCfgInfo *GetComposeComposeCfgInfo(int32_t ID);
	const ComposeComposeCfgMap *GetComposeComposeCfgMap() { return &m_ComposeComposeCfgMap; }
private:
	ComposeComposeCfgMap m_ComposeComposeCfgMap;
};

#define  g_MakeComposeComposeCfgTable() (ComposeComposeCfg::Instance())
#define  g_GetComposeComposeCfgTable() (ComposeComposeCfg::GetInstance())
#define  g_DelComposeComposeCfgTable() (ComposeComposeCfg::Destroy())