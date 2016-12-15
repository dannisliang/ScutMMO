#include "Common/TableData/EquipEquipCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


EquipEquipCfg::EquipEquipCfg()
{

}

EquipEquipCfg::~EquipEquipCfg()
{

}

void EquipEquipCfg::Clear()
{
	m_EquipEquipCfgMap.clear();
}


bool EquipEquipCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 31)
			{
				continue;
			}

			{
				EquipEquipCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //װ��ID
				info.quality = atoi(pRow->at(j++).c_str());	 //װ���̶�Ʒ��
				info.sex = atoi(pRow->at(j++).c_str());	 //�Ա�����
				info.profession = atoi(pRow->at(j++).c_str());	 //ְҵ����
				info.wearLevel = atoi(pRow->at(j++).c_str());	 //�����ȼ�����
				info.suitId = atoi(pRow->at(j++).c_str());	 //��װID
				info.position = atoi(pRow->at(j++).c_str());	 //װ��λ��
				info.holeMin = atoi(pRow->at(j++).c_str());	 //��ʼ��С��Ƕ����
				info.holeMax = atoi(pRow->at(j++).c_str());	 //��ʼ�����Ƕ����
				info.isCanbind = atoi(pRow->at(j++).c_str());	 //�Ƿ��
				info.bindType = atoi(pRow->at(j++).c_str());	 //������
				info.isCanSell = atoi(pRow->at(j++).c_str());	 //�Ƿ����
				info.sellPrice = atoi(pRow->at(j++).c_str());	 //���ۼ۸�
				info.isDrop = atoi(pRow->at(j++).c_str());	 //�Ƿ����
				info.strengthenProportion = atof(pRow->at(j++).c_str());	 //ǿ������
				info.refineAttributeNum = atoi(pRow->at(j++).c_str());	 //���������������
				info.refineAttribute_typeLibrary = pRow->at(j++).c_str();	 //����������Կ�
				info.refineAttribute_valueMin = pRow->at(j++).c_str();	 //����������Сֵ
				info.refineAttribute_valueMax = pRow->at(j++).c_str();	 //�����������ֵ
				info.refineProportion = atof(pRow->at(j++).c_str());	 //��������
				info.desc = pRow->at(j++).c_str();	 //װ������
				for (int t=0;t<4;t++) {
					string data;
					info.vec_source.push_back(data);
				}
				info.vec_source[0] = pRow->at(j++).c_str();	 //װ����Դ
				info.vec_source[1] = pRow->at(j++).c_str();	 //װ����Դ
				info.vec_source[2] = pRow->at(j++).c_str();	 //װ����Դ
				info.vec_source[3] = pRow->at(j++).c_str();	 //װ����Դ
				for (int t=0;t<2;t++) {
					EquipEquipAttributeCfgInfo stEquipEquipAttributeCfgInfo;
					info.vecEquipEquipAttributeCfg.push_back(stEquipEquipAttributeCfgInfo);
				}
				info.vecEquipEquipAttributeCfg[0].type = atoi(pRow->at(j++).c_str());	 //
				info.vecEquipEquipAttributeCfg[0].valueMax = atoi(pRow->at(j++).c_str());	 //�����ֵ
				info.vecEquipEquipAttributeCfg[0].valueMin = atoi(pRow->at(j++).c_str());	 //��С��ֵ
				info.vecEquipEquipAttributeCfg[1].type = atoi(pRow->at(j++).c_str());	 //
				info.vecEquipEquipAttributeCfg[1].valueMax = atoi(pRow->at(j++).c_str());	 //�����ֵ
				info.vecEquipEquipAttributeCfg[1].valueMin = atoi(pRow->at(j++).c_str());	 //��С��ֵ


				
				if (nullptr != GetEquipEquipCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_EquipEquipCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool EquipEquipCfg::UnInit()
{
	Clear();
	return true;
}

const EquipEquipCfgInfo *EquipEquipCfg::GetEquipEquipCfgInfo(int32_t id)
{
	EquipEquipCfgMap::iterator iter = m_EquipEquipCfgMap.find(id);
	return (iter != m_EquipEquipCfgMap.end()) ? &iter->second : nullptr;
}
