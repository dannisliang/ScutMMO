
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class AvocationComposeCfg : public ManualSingleton <AvocationComposeCfg>
{
	friend ManualSingleton <AvocationComposeCfg>;
public:
	AvocationComposeCfg();
	~AvocationComposeCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const AvocationComposeCfgInfo *GetAvocationComposeCfgInfo(int32_t id);
	const AvocationComposeCfgMap *GetAvocationComposeCfgMap() { return &m_AvocationComposeCfgMap; }
private:
	AvocationComposeCfgMap m_AvocationComposeCfgMap;
};

#define  g_MakeAvocationComposeCfgTable() (AvocationComposeCfg::Instance())
#define  g_GetAvocationComposeCfgTable() (AvocationComposeCfg::GetInstance())
#define  g_DelAvocationComposeCfgTable() (AvocationComposeCfg::Destroy())