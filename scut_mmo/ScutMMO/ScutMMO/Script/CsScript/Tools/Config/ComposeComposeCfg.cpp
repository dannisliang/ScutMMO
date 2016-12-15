#include "Common/TableData/ComposeComposeCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


ComposeComposeCfg::ComposeComposeCfg()
{

}

ComposeComposeCfg::~ComposeComposeCfg()
{

}

void ComposeComposeCfg::Clear()
{
	m_ComposeComposeCfgMap.clear();
}


bool ComposeComposeCfg::Init(const char *szCfgFile, const char *szSplitChar)
{
	CfgReader reader;
	if (!reader.LoadCfg(szCfgFile, szSplitChar))
	{
		LogErrFmtPrint("[common] reader config error....cfg:%s ", szCfgFile);
		return false;
	}
	int32_t row = reader.GetRowCount();
	for (int i = 0; i < row; ++i)
	{
		const VecRow *pRow = reader.GetRow(i);
		if (nullptr != pRow)
		{
			int32_t colun = pRow->size();
			int32_t j = 0;
			if (colun < 10)
			{
				continue;
			}

			{
				ComposeComposeCfgInfo info;
				std::string str = "";

				info.ID = atoi(pRow->at(j++).c_str());	 //物品ID
				info.composeType = atoi(pRow->at(j++).c_str());	 //合成类型
				for (int t=0;t<4;t++) {
					ComposeComposeItemCfgInfo stComposeComposeItemCfgInfo;
					info.vecComposeComposeItemCfg.push_back(stComposeComposeItemCfgInfo);
				}
				info.vecComposeComposeItemCfg[0].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecComposeComposeItemCfg[0].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecComposeComposeItemCfg[1].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecComposeComposeItemCfg[1].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecComposeComposeItemCfg[2].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecComposeComposeItemCfg[2].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecComposeComposeItemCfg[3].num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecComposeComposeItemCfg[3].id = atoi(pRow->at(j++).c_str());	 //ID


				
				if (nullptr != GetComposeComposeCfgInfo(info.ID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.ID);
					return false;
				}

				m_ComposeComposeCfgMap[info.ID] = info;
			}
		}
	}

	return true;
}

bool ComposeComposeCfg::UnInit()
{
	Clear();
	return true;
}

const ComposeComposeCfgInfo *ComposeComposeCfg::GetComposeComposeCfgInfo(int32_t ID)
{
	ComposeComposeCfgMap::iterator iter = m_ComposeComposeCfgMap.find(ID);
	return (iter != m_ComposeComposeCfgMap.end()) ? &iter->second : nullptr;
}
