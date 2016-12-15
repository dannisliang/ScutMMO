
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RoleWarriorCfg : public ManualSingleton <RoleWarriorCfg>
{
	friend ManualSingleton <RoleWarriorCfg>;
public:
	RoleWarriorCfg();
	~RoleWarriorCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RoleWarriorCfgInfo *GetRoleWarriorCfgInfo(int32_t lv);
	const RoleWarriorCfgMap *GetRoleWarriorCfgMap() { return &m_RoleWarriorCfgMap; }
private:
	RoleWarriorCfgMap m_RoleWarriorCfgMap;
};

#define  g_MakeRoleWarriorCfgTable() (RoleWarriorCfg::Instance())
#define  g_GetRoleWarriorCfgTable() (RoleWarriorCfg::GetInstance())
#define  g_DelRoleWarriorCfgTable() (RoleWarriorCfg::Destroy())