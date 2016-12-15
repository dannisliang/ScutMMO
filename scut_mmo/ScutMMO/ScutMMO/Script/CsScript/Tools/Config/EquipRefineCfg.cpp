#include "Common/TableData/EquipRefineCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


EquipRefineCfg::EquipRefineCfg()
{

}

EquipRefineCfg::~EquipRefineCfg()
{

}

void EquipRefineCfg::Clear()
{
	m_EquipRefineCfgMap.clear();
}


bool EquipRefineCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 19)
			{
				continue;
			}

			{
				EquipRefineCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //装备ID
				info.gold = pRow->at(j++).c_str();	 //金币消耗
				info.recovery = atof(pRow->at(j++).c_str());	 //回收比例
				for (int t=0;t<8;t++) {
					EquipRefineItemCfgInfo stEquipRefineItemCfgInfo;
					info.vecEquipRefineItemCfg.push_back(stEquipRefineItemCfgInfo);
				}
				info.vecEquipRefineItemCfg[0].ratio = pRow->at(j++).c_str();	 //系数
				info.vecEquipRefineItemCfg[0].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecEquipRefineItemCfg[1].ratio = pRow->at(j++).c_str();	 //系数
				info.vecEquipRefineItemCfg[1].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecEquipRefineItemCfg[2].ratio = pRow->at(j++).c_str();	 //系数
				info.vecEquipRefineItemCfg[2].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecEquipRefineItemCfg[3].ratio = pRow->at(j++).c_str();	 //系数
				info.vecEquipRefineItemCfg[3].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecEquipRefineItemCfg[4].ratio = pRow->at(j++).c_str();	 //系数
				info.vecEquipRefineItemCfg[4].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecEquipRefineItemCfg[5].ratio = pRow->at(j++).c_str();	 //系数
				info.vecEquipRefineItemCfg[5].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecEquipRefineItemCfg[6].ratio = pRow->at(j++).c_str();	 //系数
				info.vecEquipRefineItemCfg[6].id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecEquipRefineItemCfg[7].ratio = pRow->at(j++).c_str();	 //系数
				info.vecEquipRefineItemCfg[7].id = atoi(pRow->at(j++).c_str());	 //ID


				
				if (nullptr != GetEquipRefineCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_EquipRefineCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool EquipRefineCfg::UnInit()
{
	Clear();
	return true;
}

const EquipRefineCfgInfo *EquipRefineCfg::GetEquipRefineCfgInfo(int32_t id)
{
	EquipRefineCfgMap::iterator iter = m_EquipRefineCfgMap.find(id);
	return (iter != m_EquipRefineCfgMap.end()) ? &iter->second : nullptr;
}
