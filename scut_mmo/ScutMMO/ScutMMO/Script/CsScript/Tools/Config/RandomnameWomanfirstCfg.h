
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RandomnameWomanfirstCfg : public ManualSingleton <RandomnameWomanfirstCfg>
{
	friend ManualSingleton <RandomnameWomanfirstCfg>;
public:
	RandomnameWomanfirstCfg();
	~RandomnameWomanfirstCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RandomnameWomanfirstCfgInfo *GetRandomnameWomanfirstCfgInfo(int32_t id);
	const RandomnameWomanfirstCfgMap *GetRandomnameWomanfirstCfgMap() { return &m_RandomnameWomanfirstCfgMap; }
private:
	RandomnameWomanfirstCfgMap m_RandomnameWomanfirstCfgMap;
};

#define  g_MakeRandomnameWomanfirstCfgTable() (RandomnameWomanfirstCfg::Instance())
#define  g_GetRandomnameWomanfirstCfgTable() (RandomnameWomanfirstCfg::GetInstance())
#define  g_DelRandomnameWomanfirstCfgTable() (RandomnameWomanfirstCfg::Destroy())