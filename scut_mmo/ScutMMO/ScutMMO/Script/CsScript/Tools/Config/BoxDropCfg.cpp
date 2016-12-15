#include "Common/TableData/BoxDropCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


BoxDropCfg::BoxDropCfg()
{

}

BoxDropCfg::~BoxDropCfg()
{

}

void BoxDropCfg::Clear()
{
	m_BoxDropCfgMap.clear();
}


bool BoxDropCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 82)
			{
				continue;
			}

			{
				BoxDropCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //掉落包ID
				info.drop_type = atoi(pRow->at(j++).c_str());	 //掉落类型
				for (int t=0;t<20;t++) {
					BoxDropItemCfgInfo stBoxDropItemCfgInfo;
					info.vecBoxDropItemCfg.push_back(stBoxDropItemCfgInfo);
				}
				info.vecBoxDropItemCfg[0].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[0].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[0].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[0].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[1].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[1].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[1].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[1].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[2].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[2].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[2].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[2].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[3].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[3].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[3].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[3].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[4].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[4].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[4].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[4].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[5].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[5].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[5].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[5].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[6].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[6].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[6].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[6].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[7].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[7].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[7].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[7].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[8].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[8].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[8].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[8].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[9].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[9].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[9].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[9].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[10].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[10].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[10].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[10].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[11].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[11].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[11].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[11].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[12].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[12].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[12].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[12].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[13].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[13].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[13].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[13].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[14].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[14].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[14].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[14].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[15].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[15].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[15].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[15].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[16].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[16].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[16].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[16].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[17].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[17].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[17].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[17].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[18].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[18].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[18].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[18].minNum = atoi(pRow->at(j++).c_str());	 //最小数量
				info.vecBoxDropItemCfg[19].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecBoxDropItemCfg[19].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecBoxDropItemCfg[19].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecBoxDropItemCfg[19].minNum = atoi(pRow->at(j++).c_str());	 //最小数量


				
				if (nullptr != GetBoxDropCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_BoxDropCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool BoxDropCfg::UnInit()
{
	Clear();
	return true;
}

const BoxDropCfgInfo *BoxDropCfg::GetBoxDropCfgInfo(int32_t id)
{
	BoxDropCfgMap::iterator iter = m_BoxDropCfgMap.find(id);
	return (iter != m_BoxDropCfgMap.end()) ? &iter->second : nullptr;
}
