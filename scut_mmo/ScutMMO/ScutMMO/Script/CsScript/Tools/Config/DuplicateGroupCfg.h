
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class DuplicateGroupCfg : public ManualSingleton <DuplicateGroupCfg>
{
	friend ManualSingleton <DuplicateGroupCfg>;
public:
	DuplicateGroupCfg();
	~DuplicateGroupCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const DuplicateGroupCfgInfo *GetDuplicateGroupCfgInfo(int32_t id);
	const DuplicateGroupCfgMap *GetDuplicateGroupCfgMap() { return &m_DuplicateGroupCfgMap; }
private:
	DuplicateGroupCfgMap m_DuplicateGroupCfgMap;
};

#define  g_MakeDuplicateGroupCfgTable() (DuplicateGroupCfg::Instance())
#define  g_GetDuplicateGroupCfgTable() (DuplicateGroupCfg::GetInstance())
#define  g_DelDuplicateGroupCfgTable() (DuplicateGroupCfg::Destroy())