
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class PkmodePkWantedCfg : public ManualSingleton <PkmodePkWantedCfg>
{
	friend ManualSingleton <PkmodePkWantedCfg>;
public:
	PkmodePkWantedCfg();
	~PkmodePkWantedCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const PkmodePkWantedCfgInfo *GetPkmodePkWantedCfgInfo(int32_t wanteLeveldId);
	const PkmodePkWantedCfgMap *GetPkmodePkWantedCfgMap() { return &m_PkmodePkWantedCfgMap; }
private:
	PkmodePkWantedCfgMap m_PkmodePkWantedCfgMap;
};

#define  g_MakePkmodePkWantedCfgTable() (PkmodePkWantedCfg::Instance())
#define  g_GetPkmodePkWantedCfgTable() (PkmodePkWantedCfg::GetInstance())
#define  g_DelPkmodePkWantedCfgTable() (PkmodePkWantedCfg::Destroy())