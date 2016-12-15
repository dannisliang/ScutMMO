
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class TeleportSafeareaCfg : public ManualSingleton <TeleportSafeareaCfg>
{
	friend ManualSingleton <TeleportSafeareaCfg>;
public:
	TeleportSafeareaCfg();
	~TeleportSafeareaCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const TeleportSafeareaCfgInfo *GetTeleportSafeareaCfgInfo(int32_t id);
	const TeleportSafeareaCfgMap *GetTeleportSafeareaCfgMap() { return &m_TeleportSafeareaCfgMap; }
private:
	TeleportSafeareaCfgMap m_TeleportSafeareaCfgMap;
};

#define  g_MakeTeleportSafeareaCfgTable() (TeleportSafeareaCfg::Instance())
#define  g_GetTeleportSafeareaCfgTable() (TeleportSafeareaCfg::GetInstance())
#define  g_DelTeleportSafeareaCfgTable() (TeleportSafeareaCfg::Destroy())