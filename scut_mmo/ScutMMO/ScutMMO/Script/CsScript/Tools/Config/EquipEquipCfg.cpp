#include "Common/TableData/EquipEquipCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


EquipEquipCfg::EquipEquipCfg()
{

}

EquipEquipCfg::~EquipEquipCfg()
{

}

void EquipEquipCfg::Clear()
{
	m_EquipEquipCfgMap.clear();
}


bool EquipEquipCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 31)
			{
				continue;
			}

			{
				EquipEquipCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //装备ID
				info.quality = atoi(pRow->at(j++).c_str());	 //装备固定品质
				info.sex = atoi(pRow->at(j++).c_str());	 //性别限制
				info.profession = atoi(pRow->at(j++).c_str());	 //职业限制
				info.wearLevel = atoi(pRow->at(j++).c_str());	 //穿戴等级限制
				info.suitId = atoi(pRow->at(j++).c_str());	 //套装ID
				info.position = atoi(pRow->at(j++).c_str());	 //装备位置
				info.holeMin = atoi(pRow->at(j++).c_str());	 //初始最小镶嵌孔数
				info.holeMax = atoi(pRow->at(j++).c_str());	 //初始最大镶嵌孔数
				info.isCanbind = atoi(pRow->at(j++).c_str());	 //是否绑定
				info.bindType = atoi(pRow->at(j++).c_str());	 //绑定类型
				info.isCanSell = atoi(pRow->at(j++).c_str());	 //是否出售
				info.sellPrice = atoi(pRow->at(j++).c_str());	 //出售价格
				info.isDrop = atoi(pRow->at(j++).c_str());	 //是否掉落
				info.strengthenProportion = atof(pRow->at(j++).c_str());	 //强化比例
				info.refineAttributeNum = atoi(pRow->at(j++).c_str());	 //随机精炼属性条数
				info.refineAttribute_typeLibrary = pRow->at(j++).c_str();	 //随机精炼属性库
				info.refineAttribute_valueMin = pRow->at(j++).c_str();	 //精炼属性最小值
				info.refineAttribute_valueMax = pRow->at(j++).c_str();	 //精炼属性最大值
				info.refineProportion = atof(pRow->at(j++).c_str());	 //精炼比例
				info.desc = pRow->at(j++).c_str();	 //装备描述
				for (int t=0;t<4;t++) {
					string data;
					info.vec_source.push_back(data);
				}
				info.vec_source[0] = pRow->at(j++).c_str();	 //装备来源
				info.vec_source[1] = pRow->at(j++).c_str();	 //装备来源
				info.vec_source[2] = pRow->at(j++).c_str();	 //装备来源
				info.vec_source[3] = pRow->at(j++).c_str();	 //装备来源
				for (int t=0;t<2;t++) {
					EquipEquipAttributeCfgInfo stEquipEquipAttributeCfgInfo;
					info.vecEquipEquipAttributeCfg.push_back(stEquipEquipAttributeCfgInfo);
				}
				info.vecEquipEquipAttributeCfg[0].type = atoi(pRow->at(j++).c_str());	 //
				info.vecEquipEquipAttributeCfg[0].valueMax = atoi(pRow->at(j++).c_str());	 //最大数值
				info.vecEquipEquipAttributeCfg[0].valueMin = atoi(pRow->at(j++).c_str());	 //最小数值
				info.vecEquipEquipAttributeCfg[1].type = atoi(pRow->at(j++).c_str());	 //
				info.vecEquipEquipAttributeCfg[1].valueMax = atoi(pRow->at(j++).c_str());	 //最大数值
				info.vecEquipEquipAttributeCfg[1].valueMin = atoi(pRow->at(j++).c_str());	 //最小数值


				
				if (nullptr != GetEquipEquipCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_EquipEquipCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool EquipEquipCfg::UnInit()
{
	Clear();
	return true;
}

const EquipEquipCfgInfo *EquipEquipCfg::GetEquipEquipCfgInfo(int32_t id)
{
	EquipEquipCfgMap::iterator iter = m_EquipEquipCfgMap.find(id);
	return (iter != m_EquipEquipCfgMap.end()) ? &iter->second : nullptr;
}
