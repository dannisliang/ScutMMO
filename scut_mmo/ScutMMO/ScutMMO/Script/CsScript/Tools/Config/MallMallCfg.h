
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class MallMallCfg : public ManualSingleton <MallMallCfg>
{
	friend ManualSingleton <MallMallCfg>;
public:
	MallMallCfg();
	~MallMallCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const MallMallCfgInfo *GetMallMallCfgInfo(int32_t id);
	const MallMallCfgMap *GetMallMallCfgMap() { return &m_MallMallCfgMap; }
private:
	MallMallCfgMap m_MallMallCfgMap;
};

#define  g_MakeMallMallCfgTable() (MallMallCfg::Instance())
#define  g_GetMallMallCfgTable() (MallMallCfg::GetInstance())
#define  g_DelMallMallCfgTable() (MallMallCfg::Destroy())