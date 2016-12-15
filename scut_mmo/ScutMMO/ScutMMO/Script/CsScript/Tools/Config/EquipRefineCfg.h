
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class EquipRefineCfg : public ManualSingleton <EquipRefineCfg>
{
	friend ManualSingleton <EquipRefineCfg>;
public:
	EquipRefineCfg();
	~EquipRefineCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const EquipRefineCfgInfo *GetEquipRefineCfgInfo(int32_t id);
	const EquipRefineCfgMap *GetEquipRefineCfgMap() { return &m_EquipRefineCfgMap; }
private:
	EquipRefineCfgMap m_EquipRefineCfgMap;
};

#define  g_MakeEquipRefineCfgTable() (EquipRefineCfg::Instance())
#define  g_GetEquipRefineCfgTable() (EquipRefineCfg::GetInstance())
#define  g_DelEquipRefineCfgTable() (EquipRefineCfg::Destroy())