#include "Common/TableData/SkillSummonCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


SkillSummonCfg::SkillSummonCfg()
{

}

SkillSummonCfg::~SkillSummonCfg()
{

}

void SkillSummonCfg::Clear()
{
	m_SkillSummonCfgMap.clear();
}


bool SkillSummonCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 47)
			{
				continue;
			}

			{
				SkillSummonCfgInfo info;
				std::string str = "";

				info.summonID = atoi(pRow->at(j++).c_str());	 //�ٻ���ID
				info.summonType = atoi(pRow->at(j++).c_str());	 //�ٻ�������
				info.summonLevel = pRow->at(j++).c_str();	 //�ٻ���ȼ�
				info.summonTime = pRow->at(j++).c_str();	 //�ٻ������ʱ��
				info.summonAI = atoi(pRow->at(j++).c_str());	 //�ٻ���AI
				info.viewType = atoi(pRow->at(j++).c_str());	 //��Ұ����
				info.view = pRow->at(j++).c_str();	 //��Ұ
				info.pursueRange = atoi(pRow->at(j++).c_str());	 //׷����Χ
				info.StopRange = pRow->at(j++).c_str();	 //�赲��Χ
				for (int t=0;t<4;t++) {
					SkillSummonSummonCfgInfo stSkillSummonSummonCfgInfo;
					info.vecSkillSummonSummonCfg.push_back(stSkillSummonSummonCfgInfo);
				}
				info.vecSkillSummonSummonCfg[0].Skill = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonSummonCfg[0].SkillLevel = pRow->at(j++).c_str();	 //���ܵȼ�
				info.vecSkillSummonSummonCfg[1].Skill = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonSummonCfg[1].SkillLevel = pRow->at(j++).c_str();	 //���ܵȼ�
				info.vecSkillSummonSummonCfg[2].Skill = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonSummonCfg[2].SkillLevel = pRow->at(j++).c_str();	 //���ܵȼ�
				info.vecSkillSummonSummonCfg[3].Skill = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonSummonCfg[3].SkillLevel = pRow->at(j++).c_str();	 //���ܵȼ�
				for (int t=0;t<15;t++) {
					SkillSummonAttributeCfgInfo stSkillSummonAttributeCfgInfo;
					info.vecSkillSummonAttributeCfg.push_back(stSkillSummonAttributeCfgInfo);
				}
				info.vecSkillSummonAttributeCfg[0].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[0].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[1].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[1].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[2].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[2].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[3].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[3].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[4].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[4].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[5].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[5].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[6].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[6].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[7].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[7].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[8].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[8].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[9].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[9].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[10].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[10].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[11].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[11].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[12].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[12].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[13].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[13].Value = pRow->at(j++).c_str();	 //ֵ
				info.vecSkillSummonAttributeCfg[14].Type = pRow->at(j++).c_str();	 //����
				info.vecSkillSummonAttributeCfg[14].Value = pRow->at(j++).c_str();	 //ֵ


				
				if (nullptr != GetSkillSummonCfgInfo(info.summonID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.summonID);
					return false;
				}

				m_SkillSummonCfgMap[info.summonID] = info;
			}
		}
	}

	return true;
}

bool SkillSummonCfg::UnInit()
{
	Clear();
	return true;
}

const SkillSummonCfgInfo *SkillSummonCfg::GetSkillSummonCfgInfo(int32_t summonID)
{
	SkillSummonCfgMap::iterator iter = m_SkillSummonCfgMap.find(summonID);
	return (iter != m_SkillSummonCfgMap.end()) ? &iter->second : nullptr;
}
