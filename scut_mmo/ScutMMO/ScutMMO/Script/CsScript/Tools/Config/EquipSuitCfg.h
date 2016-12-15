
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class EquipSuitCfg : public ManualSingleton <EquipSuitCfg>
{
	friend ManualSingleton <EquipSuitCfg>;
public:
	EquipSuitCfg();
	~EquipSuitCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const EquipSuitCfgInfo *GetEquipSuitCfgInfo(int32_t id);
	const EquipSuitCfgMap *GetEquipSuitCfgMap() { return &m_EquipSuitCfgMap; }
private:
	EquipSuitCfgMap m_EquipSuitCfgMap;
};

#define  g_MakeEquipSuitCfgTable() (EquipSuitCfg::Instance())
#define  g_GetEquipSuitCfgTable() (EquipSuitCfg::GetInstance())
#define  g_DelEquipSuitCfgTable() (EquipSuitCfg::Destroy())