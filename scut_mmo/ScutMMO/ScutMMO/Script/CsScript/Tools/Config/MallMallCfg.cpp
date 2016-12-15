#include "Common/TableData/MallMallCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


MallMallCfg::MallMallCfg()
{

}

MallMallCfg::~MallMallCfg()
{

}

void MallMallCfg::Clear()
{
	m_MallMallCfgMap.clear();
}


bool MallMallCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 17)
			{
				continue;
			}

			{
				MallMallCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //��ƷID
				info.itemID = atoi(pRow->at(j++).c_str());	 //��ƷID
				info.mallType = atoi(pRow->at(j++).c_str());	 //�̳Ƿ���
				info.priority = atoi(pRow->at(j++).c_str());	 //���ȼ�
				info.moneyType = atoi(pRow->at(j++).c_str());	 //��������
				info.price = atoi(pRow->at(j++).c_str());	 //�۸�
				info.discount = atoi(pRow->at(j++).c_str());	 //�ۿ�
				info.buyAmount = atoi(pRow->at(j++).c_str());	 //�ɹ�������
				info.refreshTime = atoi(pRow->at(j++).c_str());	 //ˢ��ʱ������
				info.goodsAmount = atoi(pRow->at(j++).c_str());	 //������
				info.goodsRefreshTime = atoi(pRow->at(j++).c_str());	 //����ˢ������
				info.vipLimit = atoi(pRow->at(j++).c_str());	 //VIP�ȼ�����
				info.levelLimit = atoi(pRow->at(j++).c_str());	 //�ȼ�����
				info.openTime = atoi(pRow->at(j++).c_str());	 //����ʱ��
				info.openCoolTime = atoi(pRow->at(j++).c_str());	 //������ȴʱ��
				info.isClose = atoi(pRow->at(j++).c_str());	 //�Ƿ��¼�
				info.sellWaitingTime = atoi(pRow->at(j++).c_str());	 //���۵ȴ�ʱ��


				
				if (nullptr != GetMallMallCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_MallMallCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool MallMallCfg::UnInit()
{
	Clear();
	return true;
}

const MallMallCfgInfo *MallMallCfg::GetMallMallCfgInfo(int32_t id)
{
	MallMallCfgMap::iterator iter = m_MallMallCfgMap.find(id);
	return (iter != m_MallMallCfgMap.end()) ? &iter->second : nullptr;
}
