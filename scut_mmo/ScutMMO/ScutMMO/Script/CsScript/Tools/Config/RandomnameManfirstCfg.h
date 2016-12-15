
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class RandomnameManfirstCfg : public ManualSingleton <RandomnameManfirstCfg>
{
	friend ManualSingleton <RandomnameManfirstCfg>;
public:
	RandomnameManfirstCfg();
	~RandomnameManfirstCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const RandomnameManfirstCfgInfo *GetRandomnameManfirstCfgInfo(int32_t id);
	const RandomnameManfirstCfgMap *GetRandomnameManfirstCfgMap() { return &m_RandomnameManfirstCfgMap; }
private:
	RandomnameManfirstCfgMap m_RandomnameManfirstCfgMap;
};

#define  g_MakeRandomnameManfirstCfgTable() (RandomnameManfirstCfg::Instance())
#define  g_GetRandomnameManfirstCfgTable() (RandomnameManfirstCfg::GetInstance())
#define  g_DelRandomnameManfirstCfgTable() (RandomnameManfirstCfg::Destroy())