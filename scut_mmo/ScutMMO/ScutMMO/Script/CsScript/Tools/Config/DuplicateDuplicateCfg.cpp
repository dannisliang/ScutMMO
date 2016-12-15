#include "Common/TableData/DuplicateDuplicateCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


DuplicateDuplicateCfg::DuplicateDuplicateCfg()
{

}

DuplicateDuplicateCfg::~DuplicateDuplicateCfg()
{

}

void DuplicateDuplicateCfg::Clear()
{
	m_DuplicateDuplicateCfgMap.clear();
}


bool DuplicateDuplicateCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 25)
			{
				continue;
			}

			{
				DuplicateDuplicateCfgInfo info;
				std::string str = "";

				info.duplicateID = atoi(pRow->at(j++).c_str());	 //����ID
				info.groupID = atoi(pRow->at(j++).c_str());	 //����������ID
				info.duplicateType = atoi(pRow->at(j++).c_str());	 //������������
				info.playType = atoi(pRow->at(j++).c_str());	 //�����淨����
				info.sceneResource = atoi(pRow->at(j++).c_str());	 //����ID
				info.levelLimit = atoi(pRow->at(j++).c_str());	 //�ȼ�Ҫ������
				info.linkDuplicateRequest = atoi(pRow->at(j++).c_str());	 //ǰ�ø���Ҫ��
				info.unlockTask = pRow->at(j++).c_str();	 //��������
				info.playerAmountTopLimit = atoi(pRow->at(j++).c_str());	 //����Ҫ������
				info.playerAmountLowerLimit = atoi(pRow->at(j++).c_str());	 //����Ҫ������
				info.isAutoFight = atoi(pRow->at(j++).c_str());	 //�Ƿ������Զ�ս��
				info.duplicateConditionType = pRow->at(j++).c_str();	 //������������
				info.reviveMaxTimes = atoi(pRow->at(j++).c_str());	 //�����������
				info.gradeRule = pRow->at(j++).c_str();	 //��������
				info.rewardLibrary = atoi(pRow->at(j++).c_str());	 //��ͨ��Ʒ��
				info.goodRewardLibrary = atoi(pRow->at(j++).c_str());	 //��Ʒ��
				info.goodRewardValue = atoi(pRow->at(j++).c_str());	 //��Ʒ��
				info.rewardExp = atoi(pRow->at(j++).c_str());	 //��������
				info.rewardCoin = atoi(pRow->at(j++).c_str());	 //������Ϸ��
				info.rewardItem = pRow->at(j++).c_str();	 //������Ʒ
				info.dropNormalMonster = atoi(pRow->at(j++).c_str());	 //��ͨ�������
				info.dropEliteMonster = atoi(pRow->at(j++).c_str());	 //��Ӣ�������
				info.sceneAIScript = pRow->at(j++).c_str();	 //����AI�ű�
				info.bossDesc = pRow->at(j++).c_str();	 //BOSS˵������
				info.trigEntry = pRow->at(j++).c_str();	 //�������


				
				if (nullptr != GetDuplicateDuplicateCfgInfo(info.duplicateID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.duplicateID);
					return false;
				}

				m_DuplicateDuplicateCfgMap[info.duplicateID] = info;
			}
		}
	}

	return true;
}

bool DuplicateDuplicateCfg::UnInit()
{
	Clear();
	return true;
}

const DuplicateDuplicateCfgInfo *DuplicateDuplicateCfg::GetDuplicateDuplicateCfgInfo(int32_t duplicateID)
{
	DuplicateDuplicateCfgMap::iterator iter = m_DuplicateDuplicateCfgMap.find(duplicateID);
	return (iter != m_DuplicateDuplicateCfgMap.end()) ? &iter->second : nullptr;
}
