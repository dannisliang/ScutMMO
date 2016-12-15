
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class SrvlistAreaCfg : public ManualSingleton <SrvlistAreaCfg>
{
	friend ManualSingleton <SrvlistAreaCfg>;
public:
	SrvlistAreaCfg();
	~SrvlistAreaCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const SrvlistAreaCfgInfo *GetSrvlistAreaCfgInfo(int32_t id);
	const SrvlistAreaCfgMap *GetSrvlistAreaCfgMap() { return &m_SrvlistAreaCfgMap; }
private:
	SrvlistAreaCfgMap m_SrvlistAreaCfgMap;
};

#define  g_MakeSrvlistAreaCfgTable() (SrvlistAreaCfg::Instance())
#define  g_GetSrvlistAreaCfgTable() (SrvlistAreaCfg::GetInstance())
#define  g_DelSrvlistAreaCfgTable() (SrvlistAreaCfg::Destroy())