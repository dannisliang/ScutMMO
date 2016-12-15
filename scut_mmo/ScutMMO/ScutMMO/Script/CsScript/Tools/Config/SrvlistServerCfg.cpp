#include "Common/TableData/SrvlistServerCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


SrvlistServerCfg::SrvlistServerCfg()
{

}

SrvlistServerCfg::~SrvlistServerCfg()
{

}

void SrvlistServerCfg::Clear()
{
	m_SrvlistServerCfgMap.clear();
}


bool SrvlistServerCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 7)
			{
				continue;
			}

			{
				SrvlistServerCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //标识
				info.areaid = atoi(pRow->at(j++).c_str());	 //区名
				info.name = pRow->at(j++).c_str();	 //服务器名
				info.ip = pRow->at(j++).c_str();	 //ip
				info.port = atoi(pRow->at(j++).c_str());	 //端口
				info.state = atoi(pRow->at(j++).c_str());	 //状态
				info.isnew = atoi(pRow->at(j++).c_str());	 //是否新服


				
				if (nullptr != GetSrvlistServerCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_SrvlistServerCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool SrvlistServerCfg::UnInit()
{
	Clear();
	return true;
}

const SrvlistServerCfgInfo *SrvlistServerCfg::GetSrvlistServerCfgInfo(int32_t id)
{
	SrvlistServerCfgMap::iterator iter = m_SrvlistServerCfgMap.find(id);
	return (iter != m_SrvlistServerCfgMap.end()) ? &iter->second : nullptr;
}
