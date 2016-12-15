#include "Common/TableData/RoleExpCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RoleExpCfg::RoleExpCfg()
{

}

RoleExpCfg::~RoleExpCfg()
{

}

void RoleExpCfg::Clear()
{
	m_RoleExpCfgMap.clear();
}


bool RoleExpCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 3)
			{
				continue;
			}

			{
				RoleExpCfgInfo info;
				std::string str = "";

				info.lv = atoi(pRow->at(j++).c_str());	 //�ȼ�
				info.exp = atoi(pRow->at(j++).c_str());	 //��ǰ�ȼ�������Ҫ����
				info.stamina = atoi(pRow->at(j++).c_str());	 //��������


				
				if (nullptr != GetRoleExpCfgInfo(info.lv))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.lv);
					return false;
				}

				m_RoleExpCfgMap[info.lv] = info;
			}
		}
	}

	return true;
}

bool RoleExpCfg::UnInit()
{
	Clear();
	return true;
}

const RoleExpCfgInfo *RoleExpCfg::GetRoleExpCfgInfo(int32_t lv)
{
	RoleExpCfgMap::iterator iter = m_RoleExpCfgMap.find(lv);
	return (iter != m_RoleExpCfgMap.end()) ? &iter->second : nullptr;
}
