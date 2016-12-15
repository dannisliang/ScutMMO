
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RandomnameManthirdCfg : public ManualSingleton <RandomnameManthirdCfg>
{
	friend ManualSingleton <RandomnameManthirdCfg>;
public:
	RandomnameManthirdCfg();
	~RandomnameManthirdCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RandomnameManthirdCfgInfo *GetRandomnameManthirdCfgInfo(int32_t id);
	const RandomnameManthirdCfgMap *GetRandomnameManthirdCfgMap() { return &m_RandomnameManthirdCfgMap; }
private:
	RandomnameManthirdCfgMap m_RandomnameManthirdCfgMap;
};

#define  g_MakeRandomnameManthirdCfgTable() (RandomnameManthirdCfg::Instance())
#define  g_GetRandomnameManthirdCfgTable() (RandomnameManthirdCfg::GetInstance())
#define  g_DelRandomnameManthirdCfgTable() (RandomnameManthirdCfg::Destroy())