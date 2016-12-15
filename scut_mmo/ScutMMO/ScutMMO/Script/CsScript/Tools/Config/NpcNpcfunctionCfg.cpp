#include "Common/TableData/NpcNpcfunctionCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


NpcNpcfunctionCfg::NpcNpcfunctionCfg()
{

}

NpcNpcfunctionCfg::~NpcNpcfunctionCfg()
{

}

void NpcNpcfunctionCfg::Clear()
{
	m_NpcNpcfunctionCfgMap.clear();
}


bool NpcNpcfunctionCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 4)
			{
				continue;
			}

			{
				NpcNpcfunctionCfgInfo info;
				std::string str = "";

				info.functionID = atoi(pRow->at(j++).c_str());	 //功能项ID
				info.linkNPC = atoi(pRow->at(j++).c_str());	 //关联NPC
				info.functionType = atoi(pRow->at(j++).c_str());	 //功能类型
				info.functionParameter = pRow->at(j++).c_str();	 //功能参数


				
				if (nullptr != GetNpcNpcfunctionCfgInfo(info.functionID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.functionID);
					return false;
				}

				m_NpcNpcfunctionCfgMap[info.functionID] = info;
			}
		}
	}

	return true;
}

bool NpcNpcfunctionCfg::UnInit()
{
	Clear();
	return true;
}

const NpcNpcfunctionCfgInfo *NpcNpcfunctionCfg::GetNpcNpcfunctionCfgInfo(int32_t functionID)
{
	NpcNpcfunctionCfgMap::iterator iter = m_NpcNpcfunctionCfgMap.find(functionID);
	return (iter != m_NpcNpcfunctionCfgMap.end()) ? &iter->second : nullptr;
}
