
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class MallMalltypeCfg : public ManualSingleton <MallMalltypeCfg>
{
	friend ManualSingleton <MallMalltypeCfg>;
public:
	MallMalltypeCfg();
	~MallMalltypeCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const MallMalltypeCfgInfo *GetMallMalltypeCfgInfo(int32_t id);
	const MallMalltypeCfgMap *GetMallMalltypeCfgMap() { return &m_MallMalltypeCfgMap; }
private:
	MallMalltypeCfgMap m_MallMalltypeCfgMap;
};

#define  g_MakeMallMalltypeCfgTable() (MallMalltypeCfg::Instance())
#define  g_GetMallMalltypeCfgTable() (MallMalltypeCfg::GetInstance())
#define  g_DelMallMalltypeCfgTable() (MallMalltypeCfg::Destroy())