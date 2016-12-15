
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RoleBornCfg : public ManualSingleton <RoleBornCfg>
{
	friend ManualSingleton <RoleBornCfg>;
public:
	RoleBornCfg();
	~RoleBornCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RoleBornCfgInfo *GetRoleBornCfgInfo(int32_t bornID);
	const RoleBornCfgMap *GetRoleBornCfgMap() { return &m_RoleBornCfgMap; }
private:
	RoleBornCfgMap m_RoleBornCfgMap;
};

#define  g_MakeRoleBornCfgTable() (RoleBornCfg::Instance())
#define  g_GetRoleBornCfgTable() (RoleBornCfg::GetInstance())
#define  g_DelRoleBornCfgTable() (RoleBornCfg::Destroy())