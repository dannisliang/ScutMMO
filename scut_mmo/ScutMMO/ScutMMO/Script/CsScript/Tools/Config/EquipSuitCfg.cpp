#include "Common/TableData/EquipSuitCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


EquipSuitCfg::EquipSuitCfg()
{

}

EquipSuitCfg::~EquipSuitCfg()
{

}

void EquipSuitCfg::Clear()
{
	m_EquipSuitCfgMap.clear();
}


bool EquipSuitCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 28)
			{
				continue;
			}

			{
				EquipSuitCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //套装ID
				info.name = pRow->at(j++).c_str();	 //套装名称
				info.suiteValue = atoi(pRow->at(j++).c_str());	 //套装套件数量
				for (int t=0;t<10;t++) {
					int32_t data;
					info.vec_equipId.push_back(data);
				}
				info.vec_equipId[0] = atoi(pRow->at(j++).c_str());	 //装备ID
				info.vec_equipId[1] = atoi(pRow->at(j++).c_str());	 //装备ID
				info.vec_equipId[2] = atoi(pRow->at(j++).c_str());	 //装备ID
				info.vec_equipId[3] = atoi(pRow->at(j++).c_str());	 //装备ID
				info.vec_equipId[4] = atoi(pRow->at(j++).c_str());	 //装备ID
				info.vec_equipId[5] = atoi(pRow->at(j++).c_str());	 //装备ID
				info.vec_equipId[6] = atoi(pRow->at(j++).c_str());	 //装备ID
				info.vec_equipId[7] = atoi(pRow->at(j++).c_str());	 //装备ID
				info.vec_equipId[8] = atoi(pRow->at(j++).c_str());	 //装备ID
				info.vec_equipId[9] = atoi(pRow->at(j++).c_str());	 //装备ID
				for (int t=0;t<5;t++) {
					EquipSuitAttributeCfgInfo stEquipSuitAttributeCfgInfo;
					info.vecEquipSuitAttributeCfg.push_back(stEquipSuitAttributeCfgInfo);
				}
				info.vecEquipSuitAttributeCfg[0].sctivation = atoi(pRow->at(j++).c_str());	 //穿戴数量
				info.vecEquipSuitAttributeCfg[0].type = atoi(pRow->at(j++).c_str());	 //
				info.vecEquipSuitAttributeCfg[0].value = atoi(pRow->at(j++).c_str());	 //数值
				info.vecEquipSuitAttributeCfg[1].sctivation = atoi(pRow->at(j++).c_str());	 //穿戴数量
				info.vecEquipSuitAttributeCfg[1].type = atoi(pRow->at(j++).c_str());	 //
				info.vecEquipSuitAttributeCfg[1].value = atoi(pRow->at(j++).c_str());	 //数值
				info.vecEquipSuitAttributeCfg[2].sctivation = atoi(pRow->at(j++).c_str());	 //穿戴数量
				info.vecEquipSuitAttributeCfg[2].type = atoi(pRow->at(j++).c_str());	 //
				info.vecEquipSuitAttributeCfg[2].value = atoi(pRow->at(j++).c_str());	 //数值
				info.vecEquipSuitAttributeCfg[3].sctivation = atoi(pRow->at(j++).c_str());	 //穿戴数量
				info.vecEquipSuitAttributeCfg[3].type = atoi(pRow->at(j++).c_str());	 //
				info.vecEquipSuitAttributeCfg[3].value = atoi(pRow->at(j++).c_str());	 //数值
				info.vecEquipSuitAttributeCfg[4].sctivation = atoi(pRow->at(j++).c_str());	 //穿戴数量
				info.vecEquipSuitAttributeCfg[4].type = atoi(pRow->at(j++).c_str());	 //
				info.vecEquipSuitAttributeCfg[4].value = atoi(pRow->at(j++).c_str());	 //数值


				
				if (nullptr != GetEquipSuitCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_EquipSuitCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool EquipSuitCfg::UnInit()
{
	Clear();
	return true;
}

const EquipSuitCfgInfo *EquipSuitCfg::GetEquipSuitCfgInfo(int32_t id)
{
	EquipSuitCfgMap::iterator iter = m_EquipSuitCfgMap.find(id);
	return (iter != m_EquipSuitCfgMap.end()) ? &iter->second : nullptr;
}
