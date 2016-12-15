
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class AvocationAvocationskillCfg : public ManualSingleton <AvocationAvocationskillCfg>
{
	friend ManualSingleton <AvocationAvocationskillCfg>;
public:
	AvocationAvocationskillCfg();
	~AvocationAvocationskillCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const AvocationAvocationskillCfgInfo *GetAvocationAvocationskillCfgInfo(int32_t id);
	const AvocationAvocationskillCfgMap *GetAvocationAvocationskillCfgMap() { return &m_AvocationAvocationskillCfgMap; }
private:
	AvocationAvocationskillCfgMap m_AvocationAvocationskillCfgMap;
};

#define  g_MakeAvocationAvocationskillCfgTable() (AvocationAvocationskillCfg::Instance())
#define  g_GetAvocationAvocationskillCfgTable() (AvocationAvocationskillCfg::GetInstance())
#define  g_DelAvocationAvocationskillCfgTable() (AvocationAvocationskillCfg::Destroy())