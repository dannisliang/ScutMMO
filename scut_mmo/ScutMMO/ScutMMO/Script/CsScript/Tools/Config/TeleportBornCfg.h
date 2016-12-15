
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class TeleportBornCfg : public ManualSingleton <TeleportBornCfg>
{
	friend ManualSingleton <TeleportBornCfg>;
public:
	TeleportBornCfg();
	~TeleportBornCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const TeleportBornCfgInfo *GetTeleportBornCfgInfo(int32_t id);
	const TeleportBornCfgMap *GetTeleportBornCfgMap() { return &m_TeleportBornCfgMap; }
private:
	TeleportBornCfgMap m_TeleportBornCfgMap;
};

#define  g_MakeTeleportBornCfgTable() (TeleportBornCfg::Instance())
#define  g_GetTeleportBornCfgTable() (TeleportBornCfg::GetInstance())
#define  g_DelTeleportBornCfgTable() (TeleportBornCfg::Destroy())