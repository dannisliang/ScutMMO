#include "Common/TableData/EquipFashionCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


EquipFashionCfg::EquipFashionCfg()
{

}

EquipFashionCfg::~EquipFashionCfg()
{

}

void EquipFashionCfg::Clear()
{
	m_EquipFashionCfgMap.clear();
}


bool EquipFashionCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				EquipFashionCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //时装ID
				info.name = pRow->at(j++).c_str();	 //时装名称
				info.position = atoi(pRow->at(j++).c_str());	 //装备位置
				info.fashionValue = atoi(pRow->at(j++).c_str());	 //时装套件数量
				info.attributeType = atoi(pRow->at(j++).c_str());	 //属性类型
				info.attributeValue = atoi(pRow->at(j++).c_str());	 //属性数值
				info.days = atoi(pRow->at(j++).c_str());	 //有效时间


				
				if (nullptr != GetEquipFashionCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_EquipFashionCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool EquipFashionCfg::UnInit()
{
	Clear();
	return true;
}

const EquipFashionCfgInfo *EquipFashionCfg::GetEquipFashionCfgInfo(int32_t id)
{
	EquipFashionCfgMap::iterator iter = m_EquipFashionCfgMap.find(id);
	return (iter != m_EquipFashionCfgMap.end()) ? &iter->second : nullptr;
}
