
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RandomnameWomansecondCfg : public ManualSingleton <RandomnameWomansecondCfg>
{
	friend ManualSingleton <RandomnameWomansecondCfg>;
public:
	RandomnameWomansecondCfg();
	~RandomnameWomansecondCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RandomnameWomansecondCfgInfo *GetRandomnameWomansecondCfgInfo(int32_t id);
	const RandomnameWomansecondCfgMap *GetRandomnameWomansecondCfgMap() { return &m_RandomnameWomansecondCfgMap; }
private:
	RandomnameWomansecondCfgMap m_RandomnameWomansecondCfgMap;
};

#define  g_MakeRandomnameWomansecondCfgTable() (RandomnameWomansecondCfg::Instance())
#define  g_GetRandomnameWomansecondCfgTable() (RandomnameWomansecondCfg::GetInstance())
#define  g_DelRandomnameWomansecondCfgTable() (RandomnameWomansecondCfg::Destroy())