
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class EquipEquipCfg : public ManualSingleton <EquipEquipCfg>
{
	friend ManualSingleton <EquipEquipCfg>;
public:
	EquipEquipCfg();
	~EquipEquipCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const EquipEquipCfgInfo *GetEquipEquipCfgInfo(int32_t id);
	const EquipEquipCfgMap *GetEquipEquipCfgMap() { return &m_EquipEquipCfgMap; }
private:
	EquipEquipCfgMap m_EquipEquipCfgMap;
};

#define  g_MakeEquipEquipCfgTable() (EquipEquipCfg::Instance())
#define  g_GetEquipEquipCfgTable() (EquipEquipCfg::GetInstance())
#define  g_DelEquipEquipCfgTable() (EquipEquipCfg::Destroy())