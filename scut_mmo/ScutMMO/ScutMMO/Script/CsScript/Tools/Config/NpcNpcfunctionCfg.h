
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class NpcNpcfunctionCfg : public ManualSingleton <NpcNpcfunctionCfg>
{
	friend ManualSingleton <NpcNpcfunctionCfg>;
public:
	NpcNpcfunctionCfg();
	~NpcNpcfunctionCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const NpcNpcfunctionCfgInfo *GetNpcNpcfunctionCfgInfo(int32_t functionID);
	const NpcNpcfunctionCfgMap *GetNpcNpcfunctionCfgMap() { return &m_NpcNpcfunctionCfgMap; }
private:
	NpcNpcfunctionCfgMap m_NpcNpcfunctionCfgMap;
};

#define  g_MakeNpcNpcfunctionCfgTable() (NpcNpcfunctionCfg::Instance())
#define  g_GetNpcNpcfunctionCfgTable() (NpcNpcfunctionCfg::GetInstance())
#define  g_DelNpcNpcfunctionCfgTable() (NpcNpcfunctionCfg::Destroy())