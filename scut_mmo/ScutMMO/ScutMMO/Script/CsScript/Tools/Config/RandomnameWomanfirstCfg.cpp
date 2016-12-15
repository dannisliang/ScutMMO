#include "Common/TableData/RandomnameWomanfirstCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RandomnameWomanfirstCfg::RandomnameWomanfirstCfg()
{

}

RandomnameWomanfirstCfg::~RandomnameWomanfirstCfg()
{

}

void RandomnameWomanfirstCfg::Clear()
{
	m_RandomnameWomanfirstCfgMap.clear();
}


bool RandomnameWomanfirstCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				RandomnameWomanfirstCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //ÏÂ±ê
				info.name = pRow->at(j++).c_str();	 //Ãû×Ö


				
				if (nullptr != GetRandomnameWomanfirstCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_RandomnameWomanfirstCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool RandomnameWomanfirstCfg::UnInit()
{
	Clear();
	return true;
}

const RandomnameWomanfirstCfgInfo *RandomnameWomanfirstCfg::GetRandomnameWomanfirstCfgInfo(int32_t id)
{
	RandomnameWomanfirstCfgMap::iterator iter = m_RandomnameWomanfirstCfgMap.find(id);
	return (iter != m_RandomnameWomanfirstCfgMap.end()) ? &iter->second : nullptr;
}
