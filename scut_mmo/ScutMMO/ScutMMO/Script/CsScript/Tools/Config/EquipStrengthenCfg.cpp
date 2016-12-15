#include "Common/TableData/EquipStrengthenCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


EquipStrengthenCfg::EquipStrengthenCfg()
{

}

EquipStrengthenCfg::~EquipStrengthenCfg()
{

}

void EquipStrengthenCfg::Clear()
{
	m_EquipStrengthenCfgMap.clear();
}


bool EquipStrengthenCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				EquipStrengthenCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //装备ID
				info.itemId = atoi(pRow->at(j++).c_str());	 //物品ID
				info.itemRatio = pRow->at(j++).c_str();	 //物品系数
				info.gold = pRow->at(j++).c_str();	 //金币消耗
				info.recovery = atof(pRow->at(j++).c_str());	 //回收比例


				
				if (nullptr != GetEquipStrengthenCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_EquipStrengthenCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool EquipStrengthenCfg::UnInit()
{
	Clear();
	return true;
}

const EquipStrengthenCfgInfo *EquipStrengthenCfg::GetEquipStrengthenCfgInfo(int32_t id)
{
	EquipStrengthenCfgMap::iterator iter = m_EquipStrengthenCfgMap.find(id);
	return (iter != m_EquipStrengthenCfgMap.end()) ? &iter->second : nullptr;
}
