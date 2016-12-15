
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RoleAssassinCfg : public ManualSingleton <RoleAssassinCfg>
{
	friend ManualSingleton <RoleAssassinCfg>;
public:
	RoleAssassinCfg();
	~RoleAssassinCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RoleAssassinCfgInfo *GetRoleAssassinCfgInfo(int32_t lv);
	const RoleAssassinCfgMap *GetRoleAssassinCfgMap() { return &m_RoleAssassinCfgMap; }
private:
	RoleAssassinCfgMap m_RoleAssassinCfgMap;
};

#define  g_MakeRoleAssassinCfgTable() (RoleAssassinCfg::Instance())
#define  g_GetRoleAssassinCfgTable() (RoleAssassinCfg::GetInstance())
#define  g_DelRoleAssassinCfgTable() (RoleAssassinCfg::Destroy())