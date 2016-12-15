
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class ThingCollectCfg : public ManualSingleton <ThingCollectCfg>
{
	friend ManualSingleton <ThingCollectCfg>;
public:
	ThingCollectCfg();
	~ThingCollectCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const ThingCollectCfgInfo *GetThingCollectCfgInfo(int32_t id);
	const ThingCollectCfgMap *GetThingCollectCfgMap() { return &m_ThingCollectCfgMap; }
private:
	ThingCollectCfgMap m_ThingCollectCfgMap;
};

#define  g_MakeThingCollectCfgTable() (ThingCollectCfg::Instance())
#define  g_GetThingCollectCfgTable() (ThingCollectCfg::GetInstance())
#define  g_DelThingCollectCfgTable() (ThingCollectCfg::Destroy())