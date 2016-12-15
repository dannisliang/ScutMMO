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

				info.mapId = atoi(pRow->at(j++).c_str());	 //��ͼid
				info.mapWide = atoi(pRow->at(j++).c_str());	 //��ͼ���
				info.mapHeight = atoi(pRow->at(j++).c_str());	 //��ͼ�߶�
				info.mapType = atoi(pRow->at(j++).c_str());	 //��ͼ����
				info.mapSubType = atoi(pRow->at(j++).c_str());	 //��ͼ������
				info.openLv = atoi(pRow->at(j++).c_str());	 //��ͼ����ȼ�
				info.openVip = atoi(pRow->at(j++).c_str());	 //��ͼ������VIP�ȼ�
				info.openRace = atoi(pRow->at(j++).c_str());	 //��ͼ������������
				info.mapPk = atoi(pRow->at(j++).c_str());	 //PK����
				info.deadPunish = atoi(pRow->at(j++).c_str());	 //�Ƿ�����������װ����Ʒ
				info.useShoes = atoi(pRow->at(j++).c_str());	 //�Ƿ��ʹ�÷�Ь����
				info.canSupply = atoi(pRow->at(j++).c_str());	 //�Ƿ�ɺ�ҩ
				info.isDirectRevive = atoi(pRow->at(j++).c_str());	 //�Ƿ�����ԭ�ظ���
				info.mapResources = pRow->at(j++).c_str();	 //��ͼ��Դ
				info.resMonster = atoi(pRow->at(j++).c_str());	 //������Դ��
				info.monsterRoad = pRow->at(j++).c_str();	 //����Ѱ·���


				
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
