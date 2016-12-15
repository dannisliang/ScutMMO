
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class AttributeConvertCfg : public ManualSingleton <AttributeConvertCfg>
{
	friend ManualSingleton <AttributeConvertCfg>;
public:
	AttributeConvertCfg();
	~AttributeConvertCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const AttributeConvertCfgInfo *GetAttributeConvertCfgInfo(int32_t constantID);
	const AttributeConvertCfgMap *GetAttributeConvertCfgMap() { return &m_AttributeConvertCfgMap; }
private:
	AttributeConvertCfgMap m_AttributeConvertCfgMap;
};

#define  g_MakeAttributeConvertCfgTable() (AttributeConvertCfg::Instance())
#define  g_GetAttributeConvertCfgTable() (AttributeConvertCfg::GetInstance())
#define  g_DelAttributeConvertCfgTable() (AttributeConvertCfg::Destroy())