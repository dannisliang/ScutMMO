
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class AttributeSuppressCfg : public ManualSingleton <AttributeSuppressCfg>
{
	friend ManualSingleton <AttributeSuppressCfg>;
public:
	AttributeSuppressCfg();
	~AttributeSuppressCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const AttributeSuppressCfgInfo *GetAttributeSuppressCfgInfo(int32_t maxLvlDiff);
	const AttributeSuppressCfgMap *GetAttributeSuppressCfgMap() { return &m_AttributeSuppressCfgMap; }
private:
	AttributeSuppressCfgMap m_AttributeSuppressCfgMap;
};

#define  g_MakeAttributeSuppressCfgTable() (AttributeSuppressCfg::Instance())
#define  g_GetAttributeSuppressCfgTable() (AttributeSuppressCfg::GetInstance())
#define  g_DelAttributeSuppressCfgTable() (AttributeSuppressCfg::Destroy())