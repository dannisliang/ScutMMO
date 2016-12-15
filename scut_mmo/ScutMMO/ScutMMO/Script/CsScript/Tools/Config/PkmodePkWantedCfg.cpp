#include "Common/TableData/PkmodePkWantedCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


PkmodePkWantedCfg::PkmodePkWantedCfg()
{

}

PkmodePkWantedCfg::~PkmodePkWantedCfg()
{

}

void PkmodePkWantedCfg::Clear()
{
	m_PkmodePkWantedCfgMap.clear();
}


bool PkmodePkWantedCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				PkmodePkWantedCfgInfo info;
				std::string str = "";

				info.wanteLeveldId = atoi(pRow->at(j++).c_str());	 //ͨ���ȼ�ID
				info.minPKNum = atoi(pRow->at(j++).c_str());	 //��СPKֵ
				info.maxPKNum = atoi(pRow->at(j++).c_str());	 //���PKֵ
				info.killPkAdd = atoi(pRow->at(j++).c_str());	 //ɱ�������ʱ���PKֵ
				info.bodyEquipLose = atoi(pRow->at(j++).c_str());	 //���������������װ�����伸��
				info.bodyEquipMin = atoi(pRow->at(j++).c_str());	 //���������������װ��������С����
				info.bodyEquipMax = atoi(pRow->at(j++).c_str());	 //���������������װ�������������
				info.bagPropLose = atoi(pRow->at(j++).c_str());	 //����������󱳰���Ʒ���伸��
				info.bagPropMin = atoi(pRow->at(j++).c_str());	 //����������󱳰���Ʒ������������
				info.bagPropMax = atoi(pRow->at(j++).c_str());	 //����������󱳰���Ʒ�����������
				info.pkRewardId = atoi(pRow->at(j++).c_str());	 //������ID
				info.pkRewardNum = atoi(pRow->at(j++).c_str());	 //����������


				
				if (nullptr != GetPkmodePkWantedCfgInfo(info.wanteLeveldId))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.wanteLeveldId);
					return false;
				}

				m_PkmodePkWantedCfgMap[info.wanteLeveldId] = info;
			}
		}
	}

	return true;
}

bool PkmodePkWantedCfg::UnInit()
{
	Clear();
	return true;
}

const PkmodePkWantedCfgInfo *PkmodePkWantedCfg::GetPkmodePkWantedCfgInfo(int32_t wanteLeveldId)
{
	PkmodePkWantedCfgMap::iterator iter = m_PkmodePkWantedCfgMap.find(wanteLeveldId);
	return (iter != m_PkmodePkWantedCfgMap.end()) ? &iter->second : nullptr;
}
