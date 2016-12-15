#include "Common/TableData/TeleportTeleportCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


TeleportTeleportCfg::TeleportTeleportCfg()
{

}

TeleportTeleportCfg::~TeleportTeleportCfg()
{

}

void TeleportTeleportCfg::Clear()
{
	m_TeleportTeleportCfgMap.clear();
}


bool TeleportTeleportCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				TeleportTeleportCfgInfo info;
				std::string str = "";

				info.teleportID = atoi(pRow->at(j++).c_str());	 //传送点ID
				info.isSameScene = atoi(pRow->at(j++).c_str());	 //是否同场景
				info.toSceneID = atoi(pRow->at(j++).c_str());	 //目标场景
				info.standID = atoi(pRow->at(j++).c_str());	 //目标点ID


				
				if (nullptr != GetTeleportTeleportCfgInfo(info.teleportID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.teleportID);
					return false;
				}

				m_TeleportTeleportCfgMap[info.teleportID] = info;
			}
		}
	}

	return true;
}

bool TeleportTeleportCfg::UnInit()
{
	Clear();
	return true;
}

const TeleportTeleportCfgInfo *TeleportTeleportCfg::GetTeleportTeleportCfgInfo(int32_t teleportID)
{
	TeleportTeleportCfgMap::iterator iter = m_TeleportTeleportCfgMap.find(teleportID);
	return (iter != m_TeleportTeleportCfgMap.end()) ? &iter->second : nullptr;
}
