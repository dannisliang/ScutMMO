#include "Common/TableData/DuplicateGroupCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


DuplicateGroupCfg::DuplicateGroupCfg()
{

}

DuplicateGroupCfg::~DuplicateGroupCfg()
{

}

void DuplicateGroupCfg::Clear()
{
	m_DuplicateGroupCfgMap.clear();
}


bool DuplicateGroupCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 12)
			{
				continue;
			}

			{
				DuplicateGroupCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //副本组ID
				info.unlockLevel = atoi(pRow->at(j++).c_str());	 //解锁等级
				info.belongToType = atoi(pRow->at(j++).c_str());	 //所属类型
				info.openTime = pRow->at(j++).c_str();	 //开放时间
				info.groupType = atoi(pRow->at(j++).c_str());	 //组内容类型
				info.timesRes = pRow->at(j++).c_str();	 //次数ICON资源
				info.groupTimesType = atoi(pRow->at(j++).c_str());	 //组次数类型
				info.groupTimes = atoi(pRow->at(j++).c_str());	 //次数上限值
				info.refreshType = atoi(pRow->at(j++).c_str());	 //次数上限刷新类型
				info.refreshTime = pRow->at(j++).c_str();	 //限制刷新时间
				info.buyPrice = pRow->at(j++).c_str();	 //购买价格序列
				info.buyMaxTimes = atoi(pRow->at(j++).c_str());	 //最大购买次数


				
				if (nullptr != GetDuplicateGroupCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_DuplicateGroupCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool DuplicateGroupCfg::UnInit()
{
	Clear();
	return true;
}

const DuplicateGroupCfgInfo *DuplicateGroupCfg::GetDuplicateGroupCfgInfo(int32_t id)
{
	DuplicateGroupCfgMap::iterator iter = m_DuplicateGroupCfgMap.find(id);
	return (iter != m_DuplicateGroupCfgMap.end()) ? &iter->second : nullptr;
}
