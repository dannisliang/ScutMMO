#include "Common/TableData/AiAiCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


AiAiCfg::AiAiCfg()
{

}

AiAiCfg::~AiAiCfg()
{

}

void AiAiCfg::Clear()
{
	m_AiAiCfgMap.clear();
}


bool AiAiCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 14)
			{
				continue;
			}

			{
				AiAiCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //AI����ID
				info.initSkills = pRow->at(j++).c_str();	 //���ܳس�ʼ������
				for (int t=0;t<4;t++) {
					AiAiHpPeriodCfgInfo stAiAiHpPeriodCfgInfo;
					info.vecAiAiHpPeriodCfg.push_back(stAiAiHpPeriodCfgInfo);
				}
				info.vecAiAiHpPeriodCfg[0].RemoveSkills = pRow->at(j++).c_str();	 //�Ƴ�������
				info.vecAiAiHpPeriodCfg[0].Percentage = atoi(pRow->at(j++).c_str());	 //���ްٷֱ�
				info.vecAiAiHpPeriodCfg[0].AddSkills = pRow->at(j++).c_str();	 //��Ӽ�����
				info.vecAiAiHpPeriodCfg[1].RemoveSkills = pRow->at(j++).c_str();	 //�Ƴ�������
				info.vecAiAiHpPeriodCfg[1].Percentage = atoi(pRow->at(j++).c_str());	 //���ްٷֱ�
				info.vecAiAiHpPeriodCfg[1].AddSkills = pRow->at(j++).c_str();	 //��Ӽ�����
				info.vecAiAiHpPeriodCfg[2].RemoveSkills = pRow->at(j++).c_str();	 //�Ƴ�������
				info.vecAiAiHpPeriodCfg[2].Percentage = atoi(pRow->at(j++).c_str());	 //���ްٷֱ�
				info.vecAiAiHpPeriodCfg[2].AddSkills = pRow->at(j++).c_str();	 //��Ӽ�����
				info.vecAiAiHpPeriodCfg[3].RemoveSkills = pRow->at(j++).c_str();	 //�Ƴ�������
				info.vecAiAiHpPeriodCfg[3].Percentage = atoi(pRow->at(j++).c_str());	 //���ްٷֱ�
				info.vecAiAiHpPeriodCfg[3].AddSkills = pRow->at(j++).c_str();	 //��Ӽ�����


				
				if (nullptr != GetAiAiCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_AiAiCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool AiAiCfg::UnInit()
{
	Clear();
	return true;
}

const AiAiCfgInfo *AiAiCfg::GetAiAiCfgInfo(int32_t id)
{
	AiAiCfgMap::iterator iter = m_AiAiCfgMap.find(id);
	return (iter != m_AiAiCfgMap.end()) ? &iter->second : nullptr;
}
