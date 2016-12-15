#include "Common/TableData/TeleportSafeareaCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


TeleportSafeareaCfg::TeleportSafeareaCfg()
{

}

TeleportSafeareaCfg::~TeleportSafeareaCfg()
{

}

void TeleportSafeareaCfg::Clear()
{
	m_TeleportSafeareaCfgMap.clear();
}


bool TeleportSafeareaCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				TeleportSafeareaCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //安全区域ID
				info.scene = atoi(pRow->at(j++).c_str());	 //所属场景
				info.camp = atoi(pRow->at(j++).c_str());	 //所属阵营
				info.linkArea = atoi(pRow->at(j++).c_str());	 //关联区域


				
				if (nullptr != GetTeleportSafeareaCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_TeleportSafeareaCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool TeleportSafeareaCfg::UnInit()
{
	Clear();
	return true;
}

const TeleportSafeareaCfgInfo *TeleportSafeareaCfg::GetTeleportSafeareaCfgInfo(int32_t id)
{
	TeleportSafeareaCfgMap::iterator iter = m_TeleportSafeareaCfgMap.find(id);
	return (iter != m_TeleportSafeareaCfgMap.end()) ? &iter->second : nullptr;
}
