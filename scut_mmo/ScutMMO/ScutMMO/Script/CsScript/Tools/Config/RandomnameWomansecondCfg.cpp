#include "Common/TableData/RandomnameWomansecondCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RandomnameWomansecondCfg::RandomnameWomansecondCfg()
{

}

RandomnameWomansecondCfg::~RandomnameWomansecondCfg()
{

}

void RandomnameWomansecondCfg::Clear()
{
	m_RandomnameWomansecondCfgMap.clear();
}


bool RandomnameWomansecondCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				RandomnameWomansecondCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //ÏÂ±ê
				info.name = pRow->at(j++).c_str();	 //Ãû×Ö


				
				if (nullptr != GetRandomnameWomansecondCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_RandomnameWomansecondCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool RandomnameWomansecondCfg::UnInit()
{
	Clear();
	return true;
}

const RandomnameWomansecondCfgInfo *RandomnameWomansecondCfg::GetRandomnameWomansecondCfgInfo(int32_t id)
{
	RandomnameWomansecondCfgMap::iterator iter = m_RandomnameWomansecondCfgMap.find(id);
	return (iter != m_RandomnameWomansecondCfgMap.end()) ? &iter->second : nullptr;
}
