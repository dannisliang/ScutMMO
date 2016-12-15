
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class TeleportTeleportCfg : public ManualSingleton <TeleportTeleportCfg>
{
	friend ManualSingleton <TeleportTeleportCfg>;
public:
	TeleportTeleportCfg();
	~TeleportTeleportCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const TeleportTeleportCfgInfo *GetTeleportTeleportCfgInfo(int32_t teleportID);
	const TeleportTeleportCfgMap *GetTeleportTeleportCfgMap() { return &m_TeleportTeleportCfgMap; }
private:
	TeleportTeleportCfgMap m_TeleportTeleportCfgMap;
};

#define  g_MakeTeleportTeleportCfgTable() (TeleportTeleportCfg::Instance())
#define  g_GetTeleportTeleportCfgTable() (TeleportTeleportCfg::GetInstance())
#define  g_DelTeleportTeleportCfgTable() (TeleportTeleportCfg::Destroy())