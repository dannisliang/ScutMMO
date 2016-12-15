#include "Common/TableData/DuplicateGroupCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


DuplicateGroupCfg::DuplicateGroupCfg()
{

}

DuplicateGroupCfg::~DuplicateGroupCfg()
{

}

void DuplicateGroupCfg::Clear()
{
	m_DuplicateGroupCfgMap.clear();
}


bool DuplicateGroupCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				DuplicateGroupCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //������ID
				info.unlockLevel = atoi(pRow->at(j++).c_str());	 //�����ȼ�
				info.belongToType = atoi(pRow->at(j++).c_str());	 //��������
				info.openTime = pRow->at(j++).c_str();	 //����ʱ��
				info.groupType = atoi(pRow->at(j++).c_str());	 //����������
				info.timesRes = pRow->at(j++).c_str();	 //����ICON��Դ
				info.groupTimesType = atoi(pRow->at(j++).c_str());	 //���������
				info.groupTimes = atoi(pRow->at(j++).c_str());	 //��������ֵ
				info.refreshType = atoi(pRow->at(j++).c_str());	 //��������ˢ������
				info.refreshTime = pRow->at(j++).c_str();	 //����ˢ��ʱ��
				info.buyPrice = pRow->at(j++).c_str();	 //����۸�����
				info.buyMaxTimes = atoi(pRow->at(j++).c_str());	 //��������


				
				if (nullptr != GetDuplicateGroupCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_DuplicateGroupCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool DuplicateGroupCfg::UnInit()
{
	Clear();
	return true;
}

const DuplicateGroupCfgInfo *DuplicateGroupCfg::GetDuplicateGroupCfgInfo(int32_t id)
{
	DuplicateGroupCfgMap::iterator iter = m_DuplicateGroupCfgMap.find(id);
	return (iter != m_DuplicateGroupCfgMap.end()) ? &iter->second : nullptr;
}
