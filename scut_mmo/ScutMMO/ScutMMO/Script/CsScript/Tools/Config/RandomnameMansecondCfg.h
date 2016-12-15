
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RandomnameMansecondCfg : public ManualSingleton <RandomnameMansecondCfg>
{
	friend ManualSingleton <RandomnameMansecondCfg>;
public:
	RandomnameMansecondCfg();
	~RandomnameMansecondCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RandomnameMansecondCfgInfo *GetRandomnameMansecondCfgInfo(int32_t id);
	const RandomnameMansecondCfgMap *GetRandomnameMansecondCfgMap() { return &m_RandomnameMansecondCfgMap; }
private:
	RandomnameMansecondCfgMap m_RandomnameMansecondCfgMap;
};

#define  g_MakeRandomnameMansecondCfgTable() (RandomnameMansecondCfg::Instance())
#define  g_GetRandomnameMansecondCfgTable() (RandomnameMansecondCfg::GetInstance())
#define  g_DelRandomnameMansecondCfgTable() (RandomnameMansecondCfg::Destroy())