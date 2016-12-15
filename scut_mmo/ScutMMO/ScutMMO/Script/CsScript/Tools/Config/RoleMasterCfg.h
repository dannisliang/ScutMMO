
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RoleMasterCfg : public ManualSingleton <RoleMasterCfg>
{
	friend ManualSingleton <RoleMasterCfg>;
public:
	RoleMasterCfg();
	~RoleMasterCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RoleMasterCfgInfo *GetRoleMasterCfgInfo(int32_t lv);
	const RoleMasterCfgMap *GetRoleMasterCfgMap() { return &m_RoleMasterCfgMap; }
private:
	RoleMasterCfgMap m_RoleMasterCfgMap;
};

#define  g_MakeRoleMasterCfgTable() (RoleMasterCfg::Instance())
#define  g_GetRoleMasterCfgTable() (RoleMasterCfg::GetInstance())
#define  g_DelRoleMasterCfgTable() (RoleMasterCfg::Destroy())