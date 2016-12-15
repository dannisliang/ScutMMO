
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class BoxDropCfg : public ManualSingleton <BoxDropCfg>
{
	friend ManualSingleton <BoxDropCfg>;
public:
	BoxDropCfg();
	~BoxDropCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const BoxDropCfgInfo *GetBoxDropCfgInfo(int32_t id);
	const BoxDropCfgMap *GetBoxDropCfgMap() { return &m_BoxDropCfgMap; }
private:
	BoxDropCfgMap m_BoxDropCfgMap;
};

#define  g_MakeBoxDropCfgTable() (BoxDropCfg::Instance())
#define  g_GetBoxDropCfgTable() (BoxDropCfg::GetInstance())
#define  g_DelBoxDropCfgTable() (BoxDropCfg::Destroy())