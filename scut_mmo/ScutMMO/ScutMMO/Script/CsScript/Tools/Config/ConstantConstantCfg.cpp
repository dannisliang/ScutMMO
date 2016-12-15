#include "Common/TableData/ConstantConstantCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


ConstantConstantCfg::ConstantConstantCfg()
{

}

ConstantConstantCfg::~ConstantConstantCfg()
{

}

void ConstantConstantCfg::Clear()
{
	m_ConstantConstantCfgMap.clear();
}


bool ConstantConstantCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				ConstantConstantCfgInfo info;
				std::string str = "";

				info.constantid = atoi(pRow->at(j++).c_str());	 //ÅäÖÃid
				info.constantdata = atoi(pRow->at(j++).c_str());	 //Êý¾Ý


				
				if (nullptr != GetConstantConstantCfgInfo(info.constantid))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.constantid);
					return false;
				}

				m_ConstantConstantCfgMap[info.constantid] = info;
			}
		}
	}

	return true;
}

bool ConstantConstantCfg::UnInit()
{
	Clear();
	return true;
}

const ConstantConstantCfgInfo *ConstantConstantCfg::GetConstantConstantCfgInfo(int32_t constantid)
{
	ConstantConstantCfgMap::iterator iter = m_ConstantConstantCfgMap.find(constantid);
	return (iter != m_ConstantConstantCfgMap.end()) ? &iter->second : nullptr;
}
