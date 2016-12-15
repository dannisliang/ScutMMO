#include "Common/TableData/TeleportBornCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


TeleportBornCfg::TeleportBornCfg()
{

}

TeleportBornCfg::~TeleportBornCfg()
{

}

void TeleportBornCfg::Clear()
{
	m_TeleportBornCfgMap.clear();
}


bool TeleportBornCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 5)
			{
				continue;
			}

			{
				TeleportBornCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //出生点ID
				info.type = atoi(pRow->at(j++).c_str());	 //点类型
				info.scene = atoi(pRow->at(j++).c_str());	 //所属场景
				info.camp = atoi(pRow->at(j++).c_str());	 //所属阵营
				info.roleBornRange = atoi(pRow->at(j++).c_str());	 //角色出生范围


				
				if (nullptr != GetTeleportBornCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_TeleportBornCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool TeleportBornCfg::UnInit()
{
	Clear();
	return true;
}

const TeleportBornCfgInfo *TeleportBornCfg::GetTeleportBornCfgInfo(int32_t id)
{
	TeleportBornCfgMap::iterator iter = m_TeleportBornCfgMap.find(id);
	return (iter != m_TeleportBornCfgMap.end()) ? &iter->second : nullptr;
}
