
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class ItemItemCfg : public ManualSingleton <ItemItemCfg>
{
	friend ManualSingleton <ItemItemCfg>;
public:
	ItemItemCfg();
	~ItemItemCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const ItemItemCfgInfo *GetItemItemCfgInfo(int32_t id);
	const ItemItemCfgMap *GetItemItemCfgMap() { return &m_ItemItemCfgMap; }
private:
	ItemItemCfgMap m_ItemItemCfgMap;
};

#define  g_MakeItemItemCfgTable() (ItemItemCfg::Instance())
#define  g_GetItemItemCfgTable() (ItemItemCfg::GetInstance())
#define  g_DelItemItemCfgTable() (ItemItemCfg::Destroy())