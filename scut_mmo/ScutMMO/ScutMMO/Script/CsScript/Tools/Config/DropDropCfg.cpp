#include "Common/TableData/DropDropCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


DropDropCfg::DropDropCfg()
{

}

DropDropCfg::~DropDropCfg()
{

}

void DropDropCfg::Clear()
{
	m_DropDropCfgMap.clear();
}


bool DropDropCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 113)
			{
				continue;
			}

			{
				DropDropCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //掉落包ID
				info.goldlow = atoi(pRow->at(j++).c_str());	 //总金币数量下限
				info.goldup = atoi(pRow->at(j++).c_str());	 //总金币数量上限
				info.gold_heap = atoi(pRow->at(j++).c_str());	 //金币掉落堆数
				info.gold_rand = atoi(pRow->at(j++).c_str());	 //金币掉落概率
				for (int t=0;t<36;t++) {
					DropDropItemCfgInfo stDropDropItemCfgInfo;
					info.vecDropDropItemCfg.push_back(stDropDropItemCfgInfo);
				}
				info.vecDropDropItemCfg[0].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[0].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[0].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[1].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[1].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[1].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[2].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[2].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[2].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[3].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[3].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[3].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[4].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[4].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[4].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[5].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[5].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[5].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[6].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[6].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[6].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[7].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[7].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[7].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[8].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[8].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[8].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[9].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[9].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[9].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[10].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[10].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[10].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[11].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[11].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[11].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[12].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[12].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[12].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[13].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[13].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[13].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[14].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[14].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[14].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[15].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[15].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[15].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[16].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[16].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[16].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[17].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[17].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[17].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[18].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[18].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[18].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[19].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[19].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[19].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[20].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[20].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[20].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[21].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[21].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[21].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[22].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[22].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[22].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[23].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[23].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[23].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[24].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[24].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[24].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[25].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[25].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[25].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[26].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[26].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[26].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[27].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[27].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[27].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[28].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[28].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[28].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[29].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[29].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[29].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[30].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[30].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[30].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[31].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[31].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[31].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[32].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[32].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[32].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[33].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[33].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[33].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[34].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[34].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[34].id = atoi(pRow->at(j++).c_str());	 //id
				info.vecDropDropItemCfg[35].maxNum = atoi(pRow->at(j++).c_str());	 //最大数量
				info.vecDropDropItemCfg[35].rand = atoi(pRow->at(j++).c_str());	 //概率
				info.vecDropDropItemCfg[35].id = atoi(pRow->at(j++).c_str());	 //id


				
				if (nullptr != GetDropDropCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_DropDropCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool DropDropCfg::UnInit()
{
	Clear();
	return true;
}

const DropDropCfgInfo *DropDropCfg::GetDropDropCfgInfo(int32_t id)
{
	DropDropCfgMap::iterator iter = m_DropDropCfgMap.find(id);
	return (iter != m_DropDropCfgMap.end()) ? &iter->second : nullptr;
}
