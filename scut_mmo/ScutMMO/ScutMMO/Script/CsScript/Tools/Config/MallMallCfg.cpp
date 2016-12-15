#include "Common/TableData/MallMallCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


MallMallCfg::MallMallCfg()
{

}

MallMallCfg::~MallMallCfg()
{

}

void MallMallCfg::Clear()
{
	m_MallMallCfgMap.clear();
}


bool MallMallCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 17)
			{
				continue;
			}

			{
				MallMallCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //商品ID
				info.itemID = atoi(pRow->at(j++).c_str());	 //物品ID
				info.mallType = atoi(pRow->at(j++).c_str());	 //商城分类
				info.priority = atoi(pRow->at(j++).c_str());	 //优先级
				info.moneyType = atoi(pRow->at(j++).c_str());	 //货币类型
				info.price = atoi(pRow->at(j++).c_str());	 //价格
				info.discount = atoi(pRow->at(j++).c_str());	 //折扣
				info.buyAmount = atoi(pRow->at(j++).c_str());	 //可购买数量
				info.refreshTime = atoi(pRow->at(j++).c_str());	 //刷新时间周期
				info.goodsAmount = atoi(pRow->at(j++).c_str());	 //供货量
				info.goodsRefreshTime = atoi(pRow->at(j++).c_str());	 //供货刷新周期
				info.vipLimit = atoi(pRow->at(j++).c_str());	 //VIP等级限制
				info.levelLimit = atoi(pRow->at(j++).c_str());	 //等级限制
				info.openTime = atoi(pRow->at(j++).c_str());	 //开放时限
				info.openCoolTime = atoi(pRow->at(j++).c_str());	 //开放冷却时间
				info.isClose = atoi(pRow->at(j++).c_str());	 //是否下架
				info.sellWaitingTime = atoi(pRow->at(j++).c_str());	 //销售等待时间


				
				if (nullptr != GetMallMallCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_MallMallCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool MallMallCfg::UnInit()
{
	Clear();
	return true;
}

const MallMallCfgInfo *MallMallCfg::GetMallMallCfgInfo(int32_t id)
{
	MallMallCfgMap::iterator iter = m_MallMallCfgMap.find(id);
	return (iter != m_MallMallCfgMap.end()) ? &iter->second : nullptr;
}
