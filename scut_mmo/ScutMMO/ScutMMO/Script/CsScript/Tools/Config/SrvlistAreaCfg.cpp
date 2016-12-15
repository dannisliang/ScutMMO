#include "Common/TableData/SrvlistAreaCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


SrvlistAreaCfg::SrvlistAreaCfg()
{

}

SrvlistAreaCfg::~SrvlistAreaCfg()
{

}

void SrvlistAreaCfg::Clear()
{
	m_SrvlistAreaCfgMap.clear();
}


bool SrvlistAreaCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				SrvlistAreaCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //标识
				info.name = pRow->at(j++).c_str();	 //区名


				
				if (nullptr != GetSrvlistAreaCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_SrvlistAreaCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool SrvlistAreaCfg::UnInit()
{
	Clear();
	return true;
}

const SrvlistAreaCfgInfo *SrvlistAreaCfg::GetSrvlistAreaCfgInfo(int32_t id)
{
	SrvlistAreaCfgMap::iterator iter = m_SrvlistAreaCfgMap.find(id);
	return (iter != m_SrvlistAreaCfgMap.end()) ? &iter->second : nullptr;
}
