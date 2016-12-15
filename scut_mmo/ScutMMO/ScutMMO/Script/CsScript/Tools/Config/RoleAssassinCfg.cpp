#include "Common/TableData/RoleAssassinCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RoleAssassinCfg::RoleAssassinCfg()
{

}

RoleAssassinCfg::~RoleAssassinCfg()
{

}

void RoleAssassinCfg::Clear()
{
	m_RoleAssassinCfgMap.clear();
}


bool RoleAssassinCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				RoleAssassinCfgInfo info;
				std::string str = "";

				info.lv = atoi(pRow->at(j++).c_str());	 //玩家等级
				info.upgradePoint = atoi(pRow->at(j++).c_str());	 //升级获得点数
				for (int t=0;t<22;t++) {
					RoleAssassinAttributeCfgInfo stRoleAssassinAttributeCfgInfo;
					info.vecRoleAssassinAttributeCfg.push_back(stRoleAssassinAttributeCfgInfo);
				}
				info.vecRoleAssassinAttributeCfg[0].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[0].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[1].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[1].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[2].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[2].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[3].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[3].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[4].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[4].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[5].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[5].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[6].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[6].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[7].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[7].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[8].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[8].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[9].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[9].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[10].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[10].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[11].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[11].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[12].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[12].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[13].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[13].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[14].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[14].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[15].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[15].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[16].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[16].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[17].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[17].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[18].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[18].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[19].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[19].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[20].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[20].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleAssassinAttributeCfg[21].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleAssassinAttributeCfg[21].Value = atoi(pRow->at(j++).c_str());	 //值


				
				if (nullptr != GetRoleAssassinCfgInfo(info.lv))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.lv);
					return false;
				}

				m_RoleAssassinCfgMap[info.lv] = info;
			}
		}
	}

	return true;
}

bool RoleAssassinCfg::UnInit()
{
	Clear();
	return true;
}

const RoleAssassinCfgInfo *RoleAssassinCfg::GetRoleAssassinCfgInfo(int32_t lv)
{
	RoleAssassinCfgMap::iterator iter = m_RoleAssassinCfgMap.find(lv);
	return (iter != m_RoleAssassinCfgMap.end()) ? &iter->second : nullptr;
}
