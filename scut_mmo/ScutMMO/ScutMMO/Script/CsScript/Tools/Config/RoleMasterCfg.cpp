#include "Common/TableData/RoleMasterCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RoleMasterCfg::RoleMasterCfg()
{

}

RoleMasterCfg::~RoleMasterCfg()
{

}

void RoleMasterCfg::Clear()
{
	m_RoleMasterCfgMap.clear();
}


bool RoleMasterCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 46)
			{
				continue;
			}

			{
				RoleMasterCfgInfo info;
				std::string str = "";

				info.lv = atoi(pRow->at(j++).c_str());	 //玩家等级
				info.upgradePoint = atoi(pRow->at(j++).c_str());	 //升级获得点数
				for (int t=0;t<22;t++) {
					RoleMasterAttributeCfgInfo stRoleMasterAttributeCfgInfo;
					info.vecRoleMasterAttributeCfg.push_back(stRoleMasterAttributeCfgInfo);
				}
				info.vecRoleMasterAttributeCfg[0].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[0].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[1].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[1].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[2].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[2].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[3].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[3].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[4].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[4].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[5].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[5].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[6].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[6].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[7].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[7].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[8].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[8].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[9].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[9].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[10].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[10].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[11].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[11].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[12].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[12].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[13].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[13].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[14].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[14].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[15].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[15].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[16].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[16].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[17].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[17].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[18].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[18].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[19].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[19].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[20].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[20].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleMasterAttributeCfg[21].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleMasterAttributeCfg[21].Value = atoi(pRow->at(j++).c_str());	 //值


				
				if (nullptr != GetRoleMasterCfgInfo(info.lv))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.lv);
					return false;
				}

				m_RoleMasterCfgMap[info.lv] = info;
			}
		}
	}

	return true;
}

bool RoleMasterCfg::UnInit()
{
	Clear();
	return true;
}

const RoleMasterCfgInfo *RoleMasterCfg::GetRoleMasterCfgInfo(int32_t lv)
{
	RoleMasterCfgMap::iterator iter = m_RoleMasterCfgMap.find(lv);
	return (iter != m_RoleMasterCfgMap.end()) ? &iter->second : nullptr;
}
