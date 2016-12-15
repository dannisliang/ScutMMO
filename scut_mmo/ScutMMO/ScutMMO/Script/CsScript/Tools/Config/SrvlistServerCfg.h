
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class SrvlistServerCfg : public ManualSingleton <SrvlistServerCfg>
{
	friend ManualSingleton <SrvlistServerCfg>;
public:
	SrvlistServerCfg();
	~SrvlistServerCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const SrvlistServerCfgInfo *GetSrvlistServerCfgInfo(int32_t id);
	const SrvlistServerCfgMap *GetSrvlistServerCfgMap() { return &m_SrvlistServerCfgMap; }
private:
	SrvlistServerCfgMap m_SrvlistServerCfgMap;
};

#define  g_MakeSrvlistServerCfgTable() (SrvlistServerCfg::Instance())
#define  g_GetSrvlistServerCfgTable() (SrvlistServerCfg::GetInstance())
#define  g_DelSrvlistServerCfgTable() (SrvlistServerCfg::Destroy())