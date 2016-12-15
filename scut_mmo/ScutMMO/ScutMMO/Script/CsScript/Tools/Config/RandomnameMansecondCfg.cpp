#include "Common/TableData/RandomnameMansecondCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RandomnameMansecondCfg::RandomnameMansecondCfg()
{

}

RandomnameMansecondCfg::~RandomnameMansecondCfg()
{

}

void RandomnameMansecondCfg::Clear()
{
	m_RandomnameMansecondCfgMap.clear();
}


bool RandomnameMansecondCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				RandomnameMansecondCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //ÏÂ±ê
				info.name = pRow->at(j++).c_str();	 //Ãû×Ö


				
				if (nullptr != GetRandomnameMansecondCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_RandomnameMansecondCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool RandomnameMansecondCfg::UnInit()
{
	Clear();
	return true;
}

const RandomnameMansecondCfgInfo *RandomnameMansecondCfg::GetRandomnameMansecondCfgInfo(int32_t id)
{
	RandomnameMansecondCfgMap::iterator iter = m_RandomnameMansecondCfgMap.find(id);
	return (iter != m_RandomnameMansecondCfgMap.end()) ? &iter->second : nullptr;
}
