#include "Common/TableData/AttributeSuppressCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


AttributeSuppressCfg::AttributeSuppressCfg()
{

}

AttributeSuppressCfg::~AttributeSuppressCfg()
{

}

void AttributeSuppressCfg::Clear()
{
	m_AttributeSuppressCfgMap.clear();
}


bool AttributeSuppressCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 4)
			{
				continue;
			}

			{
				AttributeSuppressCfgInfo info;
				std::string str = "";

				info.maxLvlDiff = atoi(pRow->at(j++).c_str());	 //等级差
				info.hitSuppress = atoi(pRow->at(j++).c_str());	 //命中压制率
				info.critSuppress = atoi(pRow->at(j++).c_str());	 //暴击压制率
				info.stateSuppress = atoi(pRow->at(j++).c_str());	 //状态压制率


				
				if (nullptr != GetAttributeSuppressCfgInfo(info.maxLvlDiff))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.maxLvlDiff);
					return false;
				}

				m_AttributeSuppressCfgMap[info.maxLvlDiff] = info;
			}
		}
	}

	return true;
}

bool AttributeSuppressCfg::UnInit()
{
	Clear();
	return true;
}

const AttributeSuppressCfgInfo *AttributeSuppressCfg::GetAttributeSuppressCfgInfo(int32_t maxLvlDiff)
{
	AttributeSuppressCfgMap::iterator iter = m_AttributeSuppressCfgMap.find(maxLvlDiff);
	return (iter != m_AttributeSuppressCfgMap.end()) ? &iter->second : nullptr;
}
