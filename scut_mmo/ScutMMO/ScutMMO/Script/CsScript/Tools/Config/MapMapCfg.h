
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class MapMapCfg : public ManualSingleton <MapMapCfg>
{
	friend ManualSingleton <MapMapCfg>;
public:
	MapMapCfg();
	~MapMapCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const MapMapCfgInfo *GetMapMapCfgInfo(int32_t mapId);
	const MapMapCfgMap *GetMapMapCfgMap() { return &m_MapMapCfgMap; }
private:
	MapMapCfgMap m_MapMapCfgMap;
};

#define  g_MakeMapMapCfgTable() (MapMapCfg::Instance())
#define  g_GetMapMapCfgTable() (MapMapCfg::GetInstance())
#define  g_DelMapMapCfgTable() (MapMapCfg::Destroy())