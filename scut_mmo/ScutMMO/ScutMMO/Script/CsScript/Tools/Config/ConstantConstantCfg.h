
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class ConstantConstantCfg : public ManualSingleton <ConstantConstantCfg>
{
	friend ManualSingleton <ConstantConstantCfg>;
public:
	ConstantConstantCfg();
	~ConstantConstantCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const ConstantConstantCfgInfo *GetConstantConstantCfgInfo(int32_t constantid);
	const ConstantConstantCfgMap *GetConstantConstantCfgMap() { return &m_ConstantConstantCfgMap; }
private:
	ConstantConstantCfgMap m_ConstantConstantCfgMap;
};

#define  g_MakeConstantConstantCfgTable() (ConstantConstantCfg::Instance())
#define  g_GetConstantConstantCfgTable() (ConstantConstantCfg::GetInstance())
#define  g_DelConstantConstantCfgTable() (ConstantConstantCfg::Destroy())