
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class NpcNpcCfg : public ManualSingleton <NpcNpcCfg>
{
	friend ManualSingleton <NpcNpcCfg>;
public:
	NpcNpcCfg();
	~NpcNpcCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const NpcNpcCfgInfo *GetNpcNpcCfgInfo(int32_t npcID);
	const NpcNpcCfgMap *GetNpcNpcCfgMap() { return &m_NpcNpcCfgMap; }
private:
	NpcNpcCfgMap m_NpcNpcCfgMap;
};

#define  g_MakeNpcNpcCfgTable() (NpcNpcCfg::Instance())
#define  g_GetNpcNpcCfgTable() (NpcNpcCfg::GetInstance())
#define  g_DelNpcNpcCfgTable() (NpcNpcCfg::Destroy())