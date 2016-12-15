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

				info.id = atoi(pRow->at(j++).c_str());	 //��ƷID
				info.name = pRow->at(j++).c_str();	 //��Ʒ����
				info.itemType = atoi(pRow->at(j++).c_str());	 //��Ʒ����
				info.itemLevel = atoi(pRow->at(j++).c_str());	 //��Ʒ�ȼ�
				info.itemQuality = atoi(pRow->at(j++).c_str());	 //��ƷƷ��
				info.levelRequest = atoi(pRow->at(j++).c_str());	 //�ȼ�Ҫ��
				info.raceRequest = atoi(pRow->at(j++).c_str());	 //����Ҫ��
				info.sexRequest = atoi(pRow->at(j++).c_str());	 //�Ա�Ҫ��
				info.careerRequest = atoi(pRow->at(j++).c_str());	 //ְҵҪ��
				info.otherRequest = pRow->at(j++).c_str();	 //����Ҫ��
				info.subType = atoi(pRow->at(j++).c_str());	 //��Ʒϸ������
				info.functionType = atoi(pRow->at(j++).c_str());	 //��Ʒ��������
				info.functionValue = pRow->at(j++).c_str();	 //��Ʒ���ܲ���
				info.useEffectAim = atoi(pRow->at(j++).c_str());	 //����Ŀ������
				info.aimRelation = atoi(pRow->at(j++).c_str());	 //Ŀ���ϵ
				info.chantTime = atoi(pRow->at(j++).c_str());	 //����ʱ��
				info.isDeathFall = atoi(pRow->at(j++).c_str());	 //�Ƿ���������
				info.isGetBind = atoi(pRow->at(j++).c_str());	 //�Ƿ��ð�
				info.isCanStack = atoi(pRow->at(j++).c_str());	 //�ɷ�ѵ�
				info.isCanSell = atoi(pRow->at(j++).c_str());	 //�ɷ����
				info.sellPrice = atoi(pRow->at(j++).c_str());	 //���ۼ۸�
				info.isMarket = atoi(pRow->at(j++).c_str());	 //�ɷ�����
				info.isCanUse = atoi(pRow->at(j++).c_str());	 //�Ƿ��ʹ��
				info.isFightingUse = atoi(pRow->at(j++).c_str());	 //�Ƿ����ս����ʹ��
				info.isUsedDestroy = atoi(pRow->at(j++).c_str());	 //ʹ�ú��Ƿ�����
				info.isCanBatchUse = atoi(pRow->at(j++).c_str());	 //�Ƿ������ʹ��
				info.coolingType = atoi(pRow->at(j++).c_str());	 //��ȴ����
				info.coolingGroup = atoi(pRow->at(j++).c_str());	 //��ȴ��
				info.coolingTime = atoi(pRow->at(j++).c_str());	 //��ȴʱ��
				for (int t=0;t<8;t++) {
					string data;
					info.vec_source.push_back(data);
				}
				info.vec_source[0] = pRow->at(j++).c_str();	 //��Ʒ��Դ
				info.vec_source[1] = pRow->at(j++).c_str();	 //��Ʒ��Դ
				info.vec_source[2] = pRow->at(j++).c_str();	 //��Ʒ��Դ
				info.vec_source[3] = pRow->at(j++).c_str();	 //��Ʒ��Դ
				info.vec_source[4] = pRow->at(j++).c_str();	 //��Ʒ��Դ
				info.vec_source[5] = pRow->at(j++).c_str();	 //��Ʒ��Դ
				info.vec_source[6] = pRow->at(j++).c_str();	 //��Ʒ��Դ
				info.vec_source[7] = pRow->at(j++).c_str();	 //��Ʒ��Դ


				
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
