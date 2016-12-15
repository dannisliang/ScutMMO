
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class DuplicateDuplicateCfg : public ManualSingleton <DuplicateDuplicateCfg>
{
	friend ManualSingleton <DuplicateDuplicateCfg>;
public:
	DuplicateDuplicateCfg();
	~DuplicateDuplicateCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const DuplicateDuplicateCfgInfo *GetDuplicateDuplicateCfgInfo(int32_t duplicateID);
	const DuplicateDuplicateCfgMap *GetDuplicateDuplicateCfgMap() { return &m_DuplicateDuplicateCfgMap; }
private:
	DuplicateDuplicateCfgMap m_DuplicateDuplicateCfgMap;
};

#define  g_MakeDuplicateDuplicateCfgTable() (DuplicateDuplicateCfg::Instance())
#define  g_GetDuplicateDuplicateCfgTable() (DuplicateDuplicateCfg::GetInstance())
#define  g_DelDuplicateDuplicateCfgTable() (DuplicateDuplicateCfg::Destroy())