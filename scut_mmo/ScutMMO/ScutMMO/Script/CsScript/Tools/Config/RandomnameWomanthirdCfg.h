
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RandomnameWomanthirdCfg : public ManualSingleton <RandomnameWomanthirdCfg>
{
	friend ManualSingleton <RandomnameWomanthirdCfg>;
public:
	RandomnameWomanthirdCfg();
	~RandomnameWomanthirdCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RandomnameWomanthirdCfgInfo *GetRandomnameWomanthirdCfgInfo(int32_t id);
	const RandomnameWomanthirdCfgMap *GetRandomnameWomanthirdCfgMap() { return &m_RandomnameWomanthirdCfgMap; }
private:
	RandomnameWomanthirdCfgMap m_RandomnameWomanthirdCfgMap;
};

#define  g_MakeRandomnameWomanthirdCfgTable() (RandomnameWomanthirdCfg::Instance())
#define  g_GetRandomnameWomanthirdCfgTable() (RandomnameWomanthirdCfg::GetInstance())
#define  g_DelRandomnameWomanthirdCfgTable() (RandomnameWomanthirdCfg::Destroy())