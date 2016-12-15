
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class DropDropCfg : public ManualSingleton <DropDropCfg>
{
	friend ManualSingleton <DropDropCfg>;
public:
	DropDropCfg();
	~DropDropCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const DropDropCfgInfo *GetDropDropCfgInfo(int32_t id);
	const DropDropCfgMap *GetDropDropCfgMap() { return &m_DropDropCfgMap; }
private:
	DropDropCfgMap m_DropDropCfgMap;
};

#define  g_MakeDropDropCfgTable() (DropDropCfg::Instance())
#define  g_GetDropDropCfgTable() (DropDropCfg::GetInstance())
#define  g_DelDropDropCfgTable() (DropDropCfg::Destroy())