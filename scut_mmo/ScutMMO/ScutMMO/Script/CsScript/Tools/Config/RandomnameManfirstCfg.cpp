#include "Common/TableData/RandomnameManfirstCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RandomnameManfirstCfg::RandomnameManfirstCfg()
{

}

RandomnameManfirstCfg::~RandomnameManfirstCfg()
{

}

void RandomnameManfirstCfg::Clear()
{
	m_RandomnameManfirstCfgMap.clear();
}


bool RandomnameManfirstCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				RandomnameManfirstCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //ÏÂ±ê
				info.name = pRow->at(j++).c_str();	 //Ãû×Ö


				
				if (nullptr != GetRandomnameManfirstCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_RandomnameManfirstCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool RandomnameManfirstCfg::UnInit()
{
	Clear();
	return true;
}

const RandomnameManfirstCfgInfo *RandomnameManfirstCfg::GetRandomnameManfirstCfgInfo(int32_t id)
{
	RandomnameManfirstCfgMap::iterator iter = m_RandomnameManfirstCfgMap.find(id);
	return (iter != m_RandomnameManfirstCfgMap.end()) ? &iter->second : nullptr;
}
