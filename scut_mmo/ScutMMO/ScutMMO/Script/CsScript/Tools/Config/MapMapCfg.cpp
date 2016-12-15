#include "Common/TableData/MapMapCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


MapMapCfg::MapMapCfg()
{

}

MapMapCfg::~MapMapCfg()
{

}

void MapMapCfg::Clear()
{
	m_MapMapCfgMap.clear();
}


bool MapMapCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 16)
			{
				continue;
			}

			{
				MapMapCfgInfo info;
				std::string str = "";

				info.mapId = atoi(pRow->at(j++).c_str());	 //地图id
				info.mapWide = atoi(pRow->at(j++).c_str());	 //地图宽度
				info.mapHeight = atoi(pRow->at(j++).c_str());	 //地图高度
				info.mapType = atoi(pRow->at(j++).c_str());	 //地图类型
				info.mapSubType = atoi(pRow->at(j++).c_str());	 //地图子类型
				info.openLv = atoi(pRow->at(j++).c_str());	 //地图进入等级
				info.openVip = atoi(pRow->at(j++).c_str());	 //地图进入需VIP等级
				info.openRace = atoi(pRow->at(j++).c_str());	 //地图进入种族限制
				info.mapPk = atoi(pRow->at(j++).c_str());	 //PK规则
				info.deadPunish = atoi(pRow->at(j++).c_str());	 //是否有死亡掉落装备物品
				info.useShoes = atoi(pRow->at(j++).c_str());	 //是否可使用飞鞋传送
				info.canSupply = atoi(pRow->at(j++).c_str());	 //是否可喝药
				info.isDirectRevive = atoi(pRow->at(j++).c_str());	 //是否允许原地复活
				info.mapResources = pRow->at(j++).c_str();	 //地图资源
				info.resMonster = atoi(pRow->at(j++).c_str());	 //怪物资源层
				info.monsterRoad = pRow->at(j++).c_str();	 //怪物寻路点层


				
				if (nullptr != GetMapMapCfgInfo(info.mapId))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.mapId);
					return false;
				}

				m_MapMapCfgMap[info.mapId] = info;
			}
		}
	}

	return true;
}

bool MapMapCfg::UnInit()
{
	Clear();
	return true;
}

const MapMapCfgInfo *MapMapCfg::GetMapMapCfgInfo(int32_t mapId)
{
	MapMapCfgMap::iterator iter = m_MapMapCfgMap.find(mapId);
	return (iter != m_MapMapCfgMap.end()) ? &iter->second : nullptr;
}
