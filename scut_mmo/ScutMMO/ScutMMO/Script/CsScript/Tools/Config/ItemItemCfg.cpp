#include "Common/TableData/ItemItemCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


ItemItemCfg::ItemItemCfg()
{

}

ItemItemCfg::~ItemItemCfg()
{

}

void ItemItemCfg::Clear()
{
	m_ItemItemCfgMap.clear();
}


bool ItemItemCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 37)
			{
				continue;
			}

			{
				ItemItemCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //物品ID
				info.name = pRow->at(j++).c_str();	 //物品名称
				info.itemType = atoi(pRow->at(j++).c_str());	 //物品类型
				info.itemLevel = atoi(pRow->at(j++).c_str());	 //物品等级
				info.itemQuality = atoi(pRow->at(j++).c_str());	 //物品品质
				info.levelRequest = atoi(pRow->at(j++).c_str());	 //等级要求
				info.raceRequest = atoi(pRow->at(j++).c_str());	 //种族要求
				info.sexRequest = atoi(pRow->at(j++).c_str());	 //性别要求
				info.careerRequest = atoi(pRow->at(j++).c_str());	 //职业要求
				info.otherRequest = pRow->at(j++).c_str();	 //其他要求
				info.subType = atoi(pRow->at(j++).c_str());	 //物品细分类型
				info.functionType = atoi(pRow->at(j++).c_str());	 //物品功能类型
				info.functionValue = pRow->at(j++).c_str();	 //物品功能参数
				info.useEffectAim = atoi(pRow->at(j++).c_str());	 //作用目标类型
				info.aimRelation = atoi(pRow->at(j++).c_str());	 //目标关系
				info.chantTime = atoi(pRow->at(j++).c_str());	 //读条时间
				info.isDeathFall = atoi(pRow->at(j++).c_str());	 //是否死亡掉落
				info.isGetBind = atoi(pRow->at(j++).c_str());	 //是否获得绑定
				info.isCanStack = atoi(pRow->at(j++).c_str());	 //可否堆叠
				info.isCanSell = atoi(pRow->at(j++).c_str());	 //可否出售
				info.sellPrice = atoi(pRow->at(j++).c_str());	 //出售价格
				info.isMarket = atoi(pRow->at(j++).c_str());	 //可否拍卖
				info.isCanUse = atoi(pRow->at(j++).c_str());	 //是否可使用
				info.isFightingUse = atoi(pRow->at(j++).c_str());	 //是否可在战斗中使用
				info.isUsedDestroy = atoi(pRow->at(j++).c_str());	 //使用后是否销毁
				info.isCanBatchUse = atoi(pRow->at(j++).c_str());	 //是否可批量使用
				info.coolingType = atoi(pRow->at(j++).c_str());	 //冷却类型
				info.coolingGroup = atoi(pRow->at(j++).c_str());	 //冷却组
				info.coolingTime = atoi(pRow->at(j++).c_str());	 //冷却时间
				for (int t=0;t<8;t++) {
					string data;
					info.vec_source.push_back(data);
				}
				info.vec_source[0] = pRow->at(j++).c_str();	 //物品来源
				info.vec_source[1] = pRow->at(j++).c_str();	 //物品来源
				info.vec_source[2] = pRow->at(j++).c_str();	 //物品来源
				info.vec_source[3] = pRow->at(j++).c_str();	 //物品来源
				info.vec_source[4] = pRow->at(j++).c_str();	 //物品来源
				info.vec_source[5] = pRow->at(j++).c_str();	 //物品来源
				info.vec_source[6] = pRow->at(j++).c_str();	 //物品来源
				info.vec_source[7] = pRow->at(j++).c_str();	 //物品来源


				
				if (nullptr != GetItemItemCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_ItemItemCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool ItemItemCfg::UnInit()
{
	Clear();
	return true;
}

const ItemItemCfgInfo *ItemItemCfg::GetItemItemCfgInfo(int32_t id)
{
	ItemItemCfgMap::iterator iter = m_ItemItemCfgMap.find(id);
	return (iter != m_ItemItemCfgMap.end()) ? &iter->second : nullptr;
}
