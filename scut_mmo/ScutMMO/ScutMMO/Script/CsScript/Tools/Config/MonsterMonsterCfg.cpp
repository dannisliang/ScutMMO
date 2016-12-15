#include "Common/TableData/MonsterMonsterCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


MonsterMonsterCfg::MonsterMonsterCfg()
{

}

MonsterMonsterCfg::~MonsterMonsterCfg()
{

}

void MonsterMonsterCfg::Clear()
{
	m_MonsterMonsterCfgMap.clear();
}


bool MonsterMonsterCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 59)
			{
				continue;
			}

			{
				MonsterMonsterCfgInfo info;
				std::string str = "";

				info.monsterID = atoi(pRow->at(j++).c_str());	 //����ID
				info.monsterLV = atoi(pRow->at(j++).c_str());	 //����ȼ�
				info.monsterCfgType = atoi(pRow->at(j++).c_str());	 //������������
				info.monsterRefreshTime = atoi(pRow->at(j++).c_str());	 //����ˢ��ʱ��
				info.monsterFightType = atoi(pRow->at(j++).c_str());	 //����ս������
				info.monsterType = atoi(pRow->at(j++).c_str());	 //��������
				info.monsterAtkType = atoi(pRow->at(j++).c_str());	 //�չ���ʽ
				info.specialAI = atoi(pRow->at(j++).c_str());	 //��������AI
				info.bodyStayTime = atoi(pRow->at(j++).c_str());	 //ʬ������ʱ��
				info.isSkin = atoi(pRow->at(j++).c_str());	 //�Ƿ�ɰ�ȡ
				info.deathTrigger = pRow->at(j++).c_str();	 //����������
				info.bornTrigger = pRow->at(j++).c_str();	 //����������
				info.actionRange = atoi(pRow->at(j++).c_str());	 //������Χ
				info.viewType = atoi(pRow->at(j++).c_str());	 //��Ұ����
				info.view = pRow->at(j++).c_str();	 //��Ұ
				info.attackRange = atoi(pRow->at(j++).c_str());	 //������Χ
				info.pursueRange = atoi(pRow->at(j++).c_str());	 //׷����Χ
				info.maxHP = atoi(pRow->at(j++).c_str());	 //�������ֵ
				info.maxMP = atoi(pRow->at(j++).c_str());	 //���ħ��ֵ
				info.ap = atoi(pRow->at(j++).c_str());	 //������
				info.mat = atoi(pRow->at(j++).c_str());	 //ħ������
				info.dp = atoi(pRow->at(j++).c_str());	 //�������
				info.mdp = atoi(pRow->at(j++).c_str());	 //ħ������
				info.hit = atoi(pRow->at(j++).c_str());	 //����
				info.dodge = atoi(pRow->at(j++).c_str());	 //����
				info.crit = atoi(pRow->at(j++).c_str());	 //����
				info.toughness = atoi(pRow->at(j++).c_str());	 //����
				info.critRate = atoi(pRow->at(j++).c_str());	 //��������
				info.critExtraDamage = atoi(pRow->at(j++).c_str());	 //���������˺�
				info.critReduceDamage = atoi(pRow->at(j++).c_str());	 //������������
				info.extraDamage = atoi(pRow->at(j++).c_str());	 //�����˺�
				info.reduceDamage = atoi(pRow->at(j++).c_str());	 //��������
				info.damageRate = atoi(pRow->at(j++).c_str());	 //�˺���
				info.reduceDamageRate = atoi(pRow->at(j++).c_str());	 //������
				info.freezeRes = atoi(pRow->at(j++).c_str());	 //��������
				info.burnRes = atoi(pRow->at(j++).c_str());	 //���տ���
				info.weakRes = atoi(pRow->at(j++).c_str());	 //��������
				info.fastingRes = atoi(pRow->at(j++).c_str());	 //��ʳ����
				info.funkRes = atoi(pRow->at(j++).c_str());	 //�־忹��
				info.mSpeed = atoi(pRow->at(j++).c_str());	 //�ƶ��ٶ�
				info.aSpeed = atoi(pRow->at(j++).c_str());	 //�����ٶ�
				info.normalSkill = atoi(pRow->at(j++).c_str());	 //�չ�����
				info.normalSkillLevel = atoi(pRow->at(j++).c_str());	 //�չ����ܵȼ�
				info.dropDefault = atoi(pRow->at(j++).c_str());	 //Ĭ�ϵ���
				info.exp = atoi(pRow->at(j++).c_str());	 //�������
				info.isBelongToPlayer = atoi(pRow->at(j++).c_str());	 //��������Ƿ���ʾ
				info.protectTime = atoi(pRow->at(j++).c_str());	 //�����������ʱ��
				info.restWaitTime = atoi(pRow->at(j++).c_str());	 //�������еȴ�ʱ��
				info.deathEffect = pRow->at(j++).c_str();	 //������Ч
				info.anchor = atoi(pRow->at(j++).c_str());	 //��Ч�ҵ�
				info.skinLink = atoi(pRow->at(j++).c_str());	 //��Ƥ����
				info.patrolType = atoi(pRow->at(j++).c_str());	 //Ѳ������
				info.patrolPath = atoi(pRow->at(j++).c_str());	 //Ѳ��·��
				info.isFormationOn = atoi(pRow->at(j++).c_str());	 //�Ƿ���Ѳ������
				info.isShiftOff = atoi(pRow->at(j++).c_str());	 //�Ƿ�ر�λ��
				info.isFloatingOff = atoi(pRow->at(j++).c_str());	 //�Ƿ�رո���
				info.isStiffOff = atoi(pRow->at(j++).c_str());	 //�Ƿ�رս�ֱ
				info.isDownOff = atoi(pRow->at(j++).c_str());	 //�Ƿ�رջ���
				info.isAIWorkWhenNobody = atoi(pRow->at(j++).c_str());	 //�Ƿ�����ʱ����AI


				
				if (nullptr != GetMonsterMonsterCfgInfo(info.monsterID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.monsterID);
					return false;
				}

				m_MonsterMonsterCfgMap[info.monsterID] = info;
			}
		}
	}

	return true;
}

bool MonsterMonsterCfg::UnInit()
{
	Clear();
	return true;
}

const MonsterMonsterCfgInfo *MonsterMonsterCfg::GetMonsterMonsterCfgInfo(int32_t monsterID)
{
	MonsterMonsterCfgMap::iterator iter = m_MonsterMonsterCfgMap.find(monsterID);
	return (iter != m_MonsterMonsterCfgMap.end()) ? &iter->second : nullptr;
}
