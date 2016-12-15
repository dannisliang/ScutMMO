#include "Common/TableData/AreaPathCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


AreaPathCfg::AreaPathCfg()
{

}

AreaPathCfg::~AreaPathCfg()
{

}

void AreaPathCfg::Clear()
{
	m_AreaPathCfgMap.clear();
}


bool AreaPathCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 2)
			{
				continue;
			}

			{
				AreaPathCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //Â·¾¶ID
				info.belongToSceneID = atoi(pRow->at(j++).c_str());	 //ËùÊô³¡¾°


				
				if (nullptr != GetAreaPathCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_AreaPathCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool AreaPathCfg::UnInit()
{
	Clear();
	return true;
}

const AreaPathCfgInfo *AreaPathCfg::GetAreaPathCfgInfo(int32_t id)
{
	AreaPathCfgMap::iterator iter = m_AreaPathCfgMap.find(id);
	return (iter != m_AreaPathCfgMap.end()) ? &iter->second : nullptr;
}
