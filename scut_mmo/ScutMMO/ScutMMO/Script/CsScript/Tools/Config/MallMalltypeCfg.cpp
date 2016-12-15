#include "Common/TableData/MallMalltypeCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


MallMalltypeCfg::MallMalltypeCfg()
{

}

MallMalltypeCfg::~MallMalltypeCfg()
{

}

void MallMalltypeCfg::Clear()
{
	m_MallMalltypeCfgMap.clear();
}


bool MallMalltypeCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 3)
			{
				continue;
			}

			{
				MallMalltypeCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //分类ID
				info.res = pRow->at(j++).c_str();	 //分类名称资源
				info.priority = atoi(pRow->at(j++).c_str());	 //优先级


				
				if (nullptr != GetMallMalltypeCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_MallMalltypeCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool MallMalltypeCfg::UnInit()
{
	Clear();
	return true;
}

const MallMalltypeCfgInfo *MallMalltypeCfg::GetMallMalltypeCfgInfo(int32_t id)
{
	MallMalltypeCfgMap::iterator iter = m_MallMalltypeCfgMap.find(id);
	return (iter != m_MallMalltypeCfgMap.end()) ? &iter->second : nullptr;
}
