
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class MonsterMonsterCfg : public ManualSingleton <MonsterMonsterCfg>
{
	friend ManualSingleton <MonsterMonsterCfg>;
public:
	MonsterMonsterCfg();
	~MonsterMonsterCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const MonsterMonsterCfgInfo *GetMonsterMonsterCfgInfo(int32_t monsterID);
	const MonsterMonsterCfgMap *GetMonsterMonsterCfgMap() { return &m_MonsterMonsterCfgMap; }
private:
	MonsterMonsterCfgMap m_MonsterMonsterCfgMap;
};

#define  g_MakeMonsterMonsterCfgTable() (MonsterMonsterCfg::Instance())
#define  g_GetMonsterMonsterCfgTable() (MonsterMonsterCfg::GetInstance())
#define  g_DelMonsterMonsterCfgTable() (MonsterMonsterCfg::Destroy())