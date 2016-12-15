
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class EquipStrengthenCfg : public ManualSingleton <EquipStrengthenCfg>
{
	friend ManualSingleton <EquipStrengthenCfg>;
public:
	EquipStrengthenCfg();
	~EquipStrengthenCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const EquipStrengthenCfgInfo *GetEquipStrengthenCfgInfo(int32_t id);
	const EquipStrengthenCfgMap *GetEquipStrengthenCfgMap() { return &m_EquipStrengthenCfgMap; }
private:
	EquipStrengthenCfgMap m_EquipStrengthenCfgMap;
};

#define  g_MakeEquipStrengthenCfgTable() (EquipStrengthenCfg::Instance())
#define  g_GetEquipStrengthenCfgTable() (EquipStrengthenCfg::GetInstance())
#define  g_DelEquipStrengthenCfgTable() (EquipStrengthenCfg::Destroy())