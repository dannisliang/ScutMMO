#include "Common/TableData/SkillSkillCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


SkillSkillCfg::SkillSkillCfg()
{

}

SkillSkillCfg::~SkillSkillCfg()
{

}

void SkillSkillCfg::Clear()
{
	m_SkillSkillCfgMap.clear();
}


bool SkillSkillCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 68)
			{
				continue;
			}

			{
				SkillSkillCfgInfo info;
				std::string str = "";

				info.skillID = atoi(pRow->at(j++).c_str());	 //����id
				info.name = pRow->at(j++).c_str();	 //����
				info.profession = atoi(pRow->at(j++).c_str());	 //ְҵ����
				info.skillType = atoi(pRow->at(j++).c_str());	 //��������
				info.Relation = atoi(pRow->at(j++).c_str());	 //��������
				info.minLevel = pRow->at(j++).c_str();	 //ѧϰ�ȼ�
				info.skillMaxLevel = atoi(pRow->at(j++).c_str());	 //�ȼ�����
				info.type = atoi(pRow->at(j++).c_str());	 //����
				info.cd = atoi(pRow->at(j++).c_str());	 //cd
				info.cost = atoi(pRow->at(j++).c_str());	 //��������
				info.costValue = pRow->at(j++).c_str();	 //��������
				info.upgradeCost = pRow->at(j++).c_str();	 //��������
				info.threat = atoi(pRow->at(j++).c_str());	 //���ֵ
				info.moveCast = atoi(pRow->at(j++).c_str());	 //�Ƿ��ƶ�ʩ������
				info.releaseType = atoi(pRow->at(j++).c_str());	 //�ͷ�����
				info.processTypes = atoi(pRow->at(j++).c_str());	 //��������
				info.flySpeed = atoi(pRow->at(j++).c_str());	 //�����ٶ�
				info.warn = atoi(pRow->at(j++).c_str());	 //�Ƿ�Ԥ��
				info.readyTime = atoi(pRow->at(j++).c_str());	 //׼��ʱ��
				info.attackTime = atoi(pRow->at(j++).c_str());	 //������ʱ��
				info.damageTime  = pRow->at(j++).c_str();	 //�˺���Чʱ���
				info.displaceTime = pRow->at(j++).c_str();	 //λ����Чʱ���
				info.displaceDistance = pRow->at(j++).c_str();	 //λ�ƾ���
				info.move = atoi(pRow->at(j++).c_str());	 //�����ͷ��ܷ����λ��
				info.towards = atoi(pRow->at(j++).c_str());	 //�Ƿ�ɸı䳯��
				info.breakTime = atoi(pRow->at(j++).c_str());	 //�����ʱ��
				info.breakType = atoi(pRow->at(j++).c_str());	 //���������
				info.breakParameter = pRow->at(j++).c_str();	 //����ϲ���
				info.attackDistance = atoi(pRow->at(j++).c_str());	 //��������
				info.rangeType = atoi(pRow->at(j++).c_str());	 //��Χ����
				info.rangeTypeValue = pRow->at(j++).c_str();	 //��Χ����ֵ
				info.attackMinDistance = atoi(pRow->at(j++).c_str());	 //������С����
				info.goalMaxNum = atoi(pRow->at(j++).c_str());	 //Ŀ���������
				info.damageType = atoi(pRow->at(j++).c_str());	 //�˺�����
				info.attackValue = pRow->at(j++).c_str();	 //���ӹ������̶�ֵ
				info.attackRate = pRow->at(j++).c_str();	 //���ӹ���������
				info.damageValue = pRow->at(j++).c_str();	 //�����˺��̶�ֵ
				info.damageRate = pRow->at(j++).c_str();	 //�����˺�����
				for (int t=0;t<5;t++) {
					SkillSkillStateBagCfgInfo stSkillSkillStateBagCfgInfo;
					info.vecSkillSkillStateBagCfg.push_back(stSkillSkillStateBagCfgInfo);
				}
				info.vecSkillSkillStateBagCfg[0].Target = atoi(pRow->at(j++).c_str());	 //����
				info.vecSkillSkillStateBagCfg[0].Rate = atoi(pRow->at(j++).c_str());	 //�ɹ�����
				info.vecSkillSkillStateBagCfg[0].Parameter = pRow->at(j++).c_str();	 //����
				info.vecSkillSkillStateBagCfg[0].Time = pRow->at(j++).c_str();	 //����ʱ��
				info.vecSkillSkillStateBagCfg[0].Point = atoi(pRow->at(j++).c_str());	 //��Ч��
				info.vecSkillSkillStateBagCfg[0].ID = atoi(pRow->at(j++).c_str());	 //id
				info.vecSkillSkillStateBagCfg[1].Target = atoi(pRow->at(j++).c_str());	 //����
				info.vecSkillSkillStateBagCfg[1].Rate = atoi(pRow->at(j++).c_str());	 //�ɹ�����
				info.vecSkillSkillStateBagCfg[1].Parameter = pRow->at(j++).c_str();	 //����
				info.vecSkillSkillStateBagCfg[1].Time = pRow->at(j++).c_str();	 //����ʱ��
				info.vecSkillSkillStateBagCfg[1].Point = atoi(pRow->at(j++).c_str());	 //��Ч��
				info.vecSkillSkillStateBagCfg[1].ID = atoi(pRow->at(j++).c_str());	 //id
				info.vecSkillSkillStateBagCfg[2].Target = atoi(pRow->at(j++).c_str());	 //����
				info.vecSkillSkillStateBagCfg[2].Rate = atoi(pRow->at(j++).c_str());	 //�ɹ�����
				info.vecSkillSkillStateBagCfg[2].Parameter = pRow->at(j++).c_str();	 //����
				info.vecSkillSkillStateBagCfg[2].Time = pRow->at(j++).c_str();	 //����ʱ��
				info.vecSkillSkillStateBagCfg[2].Point = atoi(pRow->at(j++).c_str());	 //��Ч��
				info.vecSkillSkillStateBagCfg[2].ID = atoi(pRow->at(j++).c_str());	 //id
				info.vecSkillSkillStateBagCfg[3].Target = atoi(pRow->at(j++).c_str());	 //����
				info.vecSkillSkillStateBagCfg[3].Rate = atoi(pRow->at(j++).c_str());	 //�ɹ�����
				info.vecSkillSkillStateBagCfg[3].Parameter = pRow->at(j++).c_str();	 //����
				info.vecSkillSkillStateBagCfg[3].Time = pRow->at(j++).c_str();	 //����ʱ��
				info.vecSkillSkillStateBagCfg[3].Point = atoi(pRow->at(j++).c_str());	 //��Ч��
				info.vecSkillSkillStateBagCfg[3].ID = atoi(pRow->at(j++).c_str());	 //id
				info.vecSkillSkillStateBagCfg[4].Target = atoi(pRow->at(j++).c_str());	 //����
				info.vecSkillSkillStateBagCfg[4].Rate = atoi(pRow->at(j++).c_str());	 //�ɹ�����
				info.vecSkillSkillStateBagCfg[4].Parameter = pRow->at(j++).c_str();	 //����
				info.vecSkillSkillStateBagCfg[4].Time = pRow->at(j++).c_str();	 //����ʱ��
				info.vecSkillSkillStateBagCfg[4].Point = atoi(pRow->at(j++).c_str());	 //��Ч��
				info.vecSkillSkillStateBagCfg[4].ID = atoi(pRow->at(j++).c_str());	 //id


				
				if (nullptr != GetSkillSkillCfgInfo(info.skillID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.skillID);
					return false;
				}

				m_SkillSkillCfgMap[info.skillID] = info;
			}
		}
	}

	return true;
}

bool SkillSkillCfg::UnInit()
{
	Clear();
	return true;
}

const SkillSkillCfgInfo *SkillSkillCfg::GetSkillSkillCfgInfo(int32_t skillID)
{
	SkillSkillCfgMap::iterator iter = m_SkillSkillCfgMap.find(skillID);
	return (iter != m_SkillSkillCfgMap.end()) ? &iter->second : nullptr;
}
