
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class AreaPathCfg : public ManualSingleton <AreaPathCfg>
{
	friend ManualSingleton <AreaPathCfg>;
public:
	AreaPathCfg();
	~AreaPathCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const AreaPathCfgInfo *GetAreaPathCfgInfo(int32_t id);
	const AreaPathCfgMap *GetAreaPathCfgMap() { return &m_AreaPathCfgMap; }
private:
	AreaPathCfgMap m_AreaPathCfgMap;
};

#define  g_MakeAreaPathCfgTable() (AreaPathCfg::Instance())
#define  g_GetAreaPathCfgTable() (AreaPathCfg::GetInstance())
#define  g_DelAreaPathCfgTable() (AreaPathCfg::Destroy())