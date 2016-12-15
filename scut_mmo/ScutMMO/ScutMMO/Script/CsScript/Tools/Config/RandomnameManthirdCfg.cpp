#include "Common/TableData/RandomnameManthirdCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RandomnameManthirdCfg::RandomnameManthirdCfg()
{

}

RandomnameManthirdCfg::~RandomnameManthirdCfg()
{

}

void RandomnameManthirdCfg::Clear()
{
	m_RandomnameManthirdCfgMap.clear();
}


bool RandomnameManthirdCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				RandomnameManthirdCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //ÏÂ±ê
				info.name = pRow->at(j++).c_str();	 //Ãû×Ö


				
				if (nullptr != GetRandomnameManthirdCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_RandomnameManthirdCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool RandomnameManthirdCfg::UnInit()
{
	Clear();
	return true;
}

const RandomnameManthirdCfgInfo *RandomnameManthirdCfg::GetRandomnameManthirdCfgInfo(int32_t id)
{
	RandomnameManthirdCfgMap::iterator iter = m_RandomnameManthirdCfgMap.find(id);
	return (iter != m_RandomnameManthirdCfgMap.end()) ? &iter->second : nullptr;
}
