#include "Common/TableData/ThingCollectCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


ThingCollectCfg::ThingCollectCfg()
{

}

ThingCollectCfg::~ThingCollectCfg()
{

}

void ThingCollectCfg::Clear()
{
	m_ThingCollectCfgMap.clear();
}


bool ThingCollectCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 13)
			{
				continue;
			}

			{
				ThingCollectCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //��ԴID
				info.type = atoi(pRow->at(j++).c_str());	 //����
				info.quelity = atoi(pRow->at(j++).c_str());	 //Ʒ��
				info.mapId = atoi(pRow->at(j++).c_str());	 //��ͼId
				info.makeCount = atoi(pRow->at(j++).c_str());	 //��������
				info.refreshTime = atoi(pRow->at(j++).c_str());	 //ˢ��ʱ��
				info.needLevel = atoi(pRow->at(j++).c_str());	 //��Ҫ��ҵ�ȼ�
				info.needEnergy = atoi(pRow->at(j++).c_str());	 //���Ļ���
				info.gainValue = atoi(pRow->at(j++).c_str());	 //���������
				for (int t=0;t<2;t++) {
					ThingCollectGainCfgInfo stThingCollectGainCfgInfo;
					info.vecThingCollectGainCfg.push_back(stThingCollectGainCfgInfo);
				}
				info.vecThingCollectGainCfg[0].rate = atoi(pRow->at(j++).c_str());	 //����
				info.vecThingCollectGainCfg[0].ItemId = atoi(pRow->at(j++).c_str());	 //����
				info.vecThingCollectGainCfg[1].rate = atoi(pRow->at(j++).c_str());	 //����
				info.vecThingCollectGainCfg[1].ItemId = atoi(pRow->at(j++).c_str());	 //����


				
				if (nullptr != GetThingCollectCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_ThingCollectCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool ThingCollectCfg::UnInit()
{
	Clear();
	return true;
}

const ThingCollectCfgInfo *ThingCollectCfg::GetThingCollectCfgInfo(int32_t id)
{
	ThingCollectCfgMap::iterator iter = m_ThingCollectCfgMap.find(id);
	return (iter != m_ThingCollectCfgMap.end()) ? &iter->second : nullptr;
}
