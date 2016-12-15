#include "Common/TableData/ThingThingCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


ThingThingCfg::ThingThingCfg()
{

}

ThingThingCfg::~ThingThingCfg()
{

}

void ThingThingCfg::Clear()
{
	m_ThingThingCfgMap.clear();
}


bool ThingThingCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 14)
			{
				continue;
			}

			{
				ThingThingCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //物件ID
				info.type = atoi(pRow->at(j++).c_str());	 //物件类型
				info.res = pRow->at(j++).c_str();	 //物件资源
				info.usableTimes = atoi(pRow->at(j++).c_str());	 //可用次数
				info.isRefresh = atoi(pRow->at(j++).c_str());	 //死亡后可否刷新
				info.refreshTime = atoi(pRow->at(j++).c_str());	 //死亡刷新周期
				info.chantTime = atoi(pRow->at(j++).c_str());	 //读条时间
				info.coolTime = atoi(pRow->at(j++).c_str());	 //冷却时间
				info.liveTime = atoi(pRow->at(j++).c_str());	 //生存时间
				info.trigAimType = atoi(pRow->at(j++).c_str());	 //触发目标类型
				info.trigRange = atoi(pRow->at(j++).c_str());	 //触发区域半径
				info.trigArea = pRow->at(j++).c_str();	 //触发区域
				info.drop = atoi(pRow->at(j++).c_str());	 //掉落
				info.skill = atoi(pRow->at(j++).c_str());	 //关联技能


				
				if (nullptr != GetThingThingCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_ThingThingCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool ThingThingCfg::UnInit()
{
	Clear();
	return true;
}

const ThingThingCfgInfo *ThingThingCfg::GetThingThingCfgInfo(int32_t id)
{
	ThingThingCfgMap::iterator iter = m_ThingThingCfgMap.find(id);
	return (iter != m_ThingThingCfgMap.end()) ? &iter->second : nullptr;
}
