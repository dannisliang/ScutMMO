#include "Common/TableData/AvocationComposeCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


AvocationComposeCfg::AvocationComposeCfg()
{

}

AvocationComposeCfg::~AvocationComposeCfg()
{

}

void AvocationComposeCfg::Clear()
{
	m_AvocationComposeCfgMap.clear();
}


bool AvocationComposeCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 35)
			{
				continue;
			}

			{
				AvocationComposeCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //制造id
				info.linkId = atoi(pRow->at(j++).c_str());	 //关联id
				info.type = atoi(pRow->at(j++).c_str());	 //类型
				info.sonType = atoi(pRow->at(j++).c_str());	 //子类型
				info.creatList = atoi(pRow->at(j++).c_str());	 //所在制造列表
				info.jobList = atoi(pRow->at(j++).c_str());	 //职业列表
				info.isName = atoi(pRow->at(j++).c_str());	 //是否铭刻
				info.needMoney = atoi(pRow->at(j++).c_str());	 //需要金币
				info.consumeRandomReel_Id = atoi(pRow->at(j++).c_str());	 //随机卷轴ID
				for (int t=0;t<6;t++) {
					AvocationComposeNewItemCfgInfo stAvocationComposeNewItemCfgInfo;
					info.vecAvocationComposeNewItemCfg.push_back(stAvocationComposeNewItemCfgInfo);
				}
				info.vecAvocationComposeNewItemCfg[0].Rate = atoi(pRow->at(j++).c_str());	 //几率
				info.vecAvocationComposeNewItemCfg[0].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeNewItemCfg[1].Rate = atoi(pRow->at(j++).c_str());	 //几率
				info.vecAvocationComposeNewItemCfg[1].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeNewItemCfg[2].Rate = atoi(pRow->at(j++).c_str());	 //几率
				info.vecAvocationComposeNewItemCfg[2].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeNewItemCfg[3].Rate = atoi(pRow->at(j++).c_str());	 //几率
				info.vecAvocationComposeNewItemCfg[3].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeNewItemCfg[4].Rate = atoi(pRow->at(j++).c_str());	 //几率
				info.vecAvocationComposeNewItemCfg[4].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeNewItemCfg[5].Rate = atoi(pRow->at(j++).c_str());	 //几率
				info.vecAvocationComposeNewItemCfg[5].Id = atoi(pRow->at(j++).c_str());	 //ID
				for (int t=0;t<4;t++) {
					AvocationComposeNeedMaterialCfgInfo stAvocationComposeNeedMaterialCfgInfo;
					info.vecAvocationComposeNeedMaterialCfg.push_back(stAvocationComposeNeedMaterialCfgInfo);
				}
				info.vecAvocationComposeNeedMaterialCfg[0].Num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAvocationComposeNeedMaterialCfg[0].Id = atoi(pRow->at(j++).c_str());	 //id
				info.vecAvocationComposeNeedMaterialCfg[1].Num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAvocationComposeNeedMaterialCfg[1].Id = atoi(pRow->at(j++).c_str());	 //id
				info.vecAvocationComposeNeedMaterialCfg[2].Num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAvocationComposeNeedMaterialCfg[2].Id = atoi(pRow->at(j++).c_str());	 //id
				info.vecAvocationComposeNeedMaterialCfg[3].Num = atoi(pRow->at(j++).c_str());	 //数量
				info.vecAvocationComposeNeedMaterialCfg[3].Id = atoi(pRow->at(j++).c_str());	 //id
				for (int t=0;t<6;t++) {
					AvocationComposeConsumeReelCfgInfo stAvocationComposeConsumeReelCfgInfo;
					info.vecAvocationComposeConsumeReelCfg.push_back(stAvocationComposeConsumeReelCfgInfo);
				}
				info.vecAvocationComposeConsumeReelCfg[0].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeConsumeReelCfg[1].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeConsumeReelCfg[2].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeConsumeReelCfg[3].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeConsumeReelCfg[4].Id = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAvocationComposeConsumeReelCfg[5].Id = atoi(pRow->at(j++).c_str());	 //ID


				
				if (nullptr != GetAvocationComposeCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_AvocationComposeCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool AvocationComposeCfg::UnInit()
{
	Clear();
	return true;
}

const AvocationComposeCfgInfo *AvocationComposeCfg::GetAvocationComposeCfgInfo(int32_t id)
{
	AvocationComposeCfgMap::iterator iter = m_AvocationComposeCfgMap.find(id);
	return (iter != m_AvocationComposeCfgMap.end()) ? &iter->second : nullptr;
}
