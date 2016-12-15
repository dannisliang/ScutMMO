
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RoleShooterCfg : public ManualSingleton <RoleShooterCfg>
{
	friend ManualSingleton <RoleShooterCfg>;
public:
	RoleShooterCfg();
	~RoleShooterCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RoleShooterCfgInfo *GetRoleShooterCfgInfo(int32_t lv);
	const RoleShooterCfgMap *GetRoleShooterCfgMap() { return &m_RoleShooterCfgMap; }
private:
	RoleShooterCfgMap m_RoleShooterCfgMap;
};

#define  g_MakeRoleShooterCfgTable() (RoleShooterCfg::Instance())
#define  g_GetRoleShooterCfgTable() (RoleShooterCfg::GetInstance())
#define  g_DelRoleShooterCfgTable() (RoleShooterCfg::Destroy())