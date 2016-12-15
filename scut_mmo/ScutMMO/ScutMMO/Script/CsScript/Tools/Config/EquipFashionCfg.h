
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class EquipFashionCfg : public ManualSingleton <EquipFashionCfg>
{
	friend ManualSingleton <EquipFashionCfg>;
public:
	EquipFashionCfg();
	~EquipFashionCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const EquipFashionCfgInfo *GetEquipFashionCfgInfo(int32_t id);
	const EquipFashionCfgMap *GetEquipFashionCfgMap() { return &m_EquipFashionCfgMap; }
private:
	EquipFashionCfgMap m_EquipFashionCfgMap;
};

#define  g_MakeEquipFashionCfgTable() (EquipFashionCfg::Instance())
#define  g_GetEquipFashionCfgTable() (EquipFashionCfg::GetInstance())
#define  g_DelEquipFashionCfgTable() (EquipFashionCfg::Destroy())