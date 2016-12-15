#include "Common/TableData/RandomnameWomanthirdCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RandomnameWomanthirdCfg::RandomnameWomanthirdCfg()
{

}

RandomnameWomanthirdCfg::~RandomnameWomanthirdCfg()
{

}

void RandomnameWomanthirdCfg::Clear()
{
	m_RandomnameWomanthirdCfgMap.clear();
}


bool RandomnameWomanthirdCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				RandomnameWomanthirdCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //ÏÂ±ê
				info.name = pRow->at(j++).c_str();	 //Ãû×Ö


				
				if (nullptr != GetRandomnameWomanthirdCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_RandomnameWomanthirdCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool RandomnameWomanthirdCfg::UnInit()
{
	Clear();
	return true;
}

const RandomnameWomanthirdCfgInfo *RandomnameWomanthirdCfg::GetRandomnameWomanthirdCfgInfo(int32_t id)
{
	RandomnameWomanthirdCfgMap::iterator iter = m_RandomnameWomanthirdCfgMap.find(id);
	return (iter != m_RandomnameWomanthirdCfgMap.end()) ? &iter->second : nullptr;
}
