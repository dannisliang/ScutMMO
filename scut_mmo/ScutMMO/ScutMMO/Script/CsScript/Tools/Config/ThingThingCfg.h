
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class ThingThingCfg : public ManualSingleton <ThingThingCfg>
{
	friend ManualSingleton <ThingThingCfg>;
public:
	ThingThingCfg();
	~ThingThingCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const ThingThingCfgInfo *GetThingThingCfgInfo(int32_t id);
	const ThingThingCfgMap *GetThingThingCfgMap() { return &m_ThingThingCfgMap; }
private:
	ThingThingCfgMap m_ThingThingCfgMap;
};

#define  g_MakeThingThingCfgTable() (ThingThingCfg::Instance())
#define  g_GetThingThingCfgTable() (ThingThingCfg::GetInstance())
#define  g_DelThingThingCfgTable() (ThingThingCfg::Destroy())