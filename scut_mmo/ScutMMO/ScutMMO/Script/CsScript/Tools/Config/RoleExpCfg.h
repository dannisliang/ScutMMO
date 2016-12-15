
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RoleExpCfg : public ManualSingleton <RoleExpCfg>
{
	friend ManualSingleton <RoleExpCfg>;
public:
	RoleExpCfg();
	~RoleExpCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RoleExpCfgInfo *GetRoleExpCfgInfo(int32_t lv);
	const RoleExpCfgMap *GetRoleExpCfgMap() { return &m_RoleExpCfgMap; }
private:
	RoleExpCfgMap m_RoleExpCfgMap;
};

#define  g_MakeRoleExpCfgTable() (RoleExpCfg::Instance())
#define  g_GetRoleExpCfgTable() (RoleExpCfg::GetInstance())
#define  g_DelRoleExpCfgTable() (RoleExpCfg::Destroy())