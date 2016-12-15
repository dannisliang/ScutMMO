
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class AreaAreaCfg : public ManualSingleton <AreaAreaCfg>
{
	friend ManualSingleton <AreaAreaCfg>;
public:
	AreaAreaCfg();
	~AreaAreaCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const AreaAreaCfgInfo *GetAreaAreaCfgInfo(int32_t id);
	const AreaAreaCfgMap *GetAreaAreaCfgMap() { return &m_AreaAreaCfgMap; }
private:
	AreaAreaCfgMap m_AreaAreaCfgMap;
};

#define  g_MakeAreaAreaCfgTable() (AreaAreaCfg::Instance())
#define  g_GetAreaAreaCfgTable() (AreaAreaCfg::GetInstance())
#define  g_DelAreaAreaCfgTable() (AreaAreaCfg::Destroy())