#include "Common/TableData/PetPetCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


PetPetCfg::PetPetCfg()
{

}

PetPetCfg::~PetPetCfg()
{

}

void PetPetCfg::Clear()
{
	m_PetPetCfgMap.clear();
}


bool PetPetCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 20)
			{
				continue;
			}

			{
				PetPetCfgInfo info;
				std::string str = "";

				info.petId = atoi(pRow->at(j++).c_str());	 //����ID
				info.level = atoi(pRow->at(j++).c_str());	 //��Ӧ�ȼ�
				info.star = atoi(pRow->at(j++).c_str());	 //��������
				info.maxHP = atoi(pRow->at(j++).c_str());	 //�������ֵ
				info.maxMP = atoi(pRow->at(j++).c_str());	 //���ħ��ֵ
				info.ap = atoi(pRow->at(j++).c_str());	 //������
				info.mat = atoi(pRow->at(j++).c_str());	 //ħ������
				info.dp = atoi(pRow->at(j++).c_str());	 //�������
				info.mdp = atoi(pRow->at(j++).c_str());	 //ħ������
				info.fragmentId = atoi(pRow->at(j++).c_str());	 //����������Ƭid
				info.costFragmentNum = atoi(pRow->at(j++).c_str());	 //������Ƭ����
				info.trainId = atoi(pRow->at(j++).c_str());	 //���Ǻ�id
				info.evolveId = atoi(pRow->at(j++).c_str());	 //������id
				info.stage = atoi(pRow->at(j++).c_str());	 //�׶�
				info.petQuality = atoi(pRow->at(j++).c_str());	 //����Ʒ��
				info.stoneId = atoi(pRow->at(j++).c_str());	 //���Ľ���ʯid
				info.costStoneNum = atoi(pRow->at(j++).c_str());	 //���Ľ���ʯ����
				info.commonSkillId = atoi(pRow->at(j++).c_str());	 //�չ�ID
				for (int t=0;t<2;t++) {
					int32_t data;
					info.vec_costMoney.push_back(data);
				}
				info.vec_costMoney[0] = atoi(pRow->at(j++).c_str());	 //���Ľ������
				info.vec_costMoney[1] = atoi(pRow->at(j++).c_str());	 //���Ľ������


				
				if (nullptr != GetPetPetCfgInfo(info.petId))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.petId);
					return false;
				}

				m_PetPetCfgMap[info.petId] = info;
			}
		}
	}

	return true;
}

bool PetPetCfg::UnInit()
{
	Clear();
	return true;
}

const PetPetCfgInfo *PetPetCfg::GetPetPetCfgInfo(int32_t petId)
{
	PetPetCfgMap::iterator iter = m_PetPetCfgMap.find(petId);
	return (iter != m_PetPetCfgMap.end()) ? &iter->second : nullptr;
}
