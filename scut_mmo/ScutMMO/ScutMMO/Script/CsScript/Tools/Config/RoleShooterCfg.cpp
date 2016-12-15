#include "Common/TableData/RoleShooterCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RoleShooterCfg::RoleShooterCfg()
{

}

RoleShooterCfg::~RoleShooterCfg()
{

}

void RoleShooterCfg::Clear()
{
	m_RoleShooterCfgMap.clear();
}


bool RoleShooterCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				RoleShooterCfgInfo info;
				std::string str = "";

				info.lv = atoi(pRow->at(j++).c_str());	 //玩家等级
				info.upgradePoint = atoi(pRow->at(j++).c_str());	 //升级获得点数
				for (int t=0;t<22;t++) {
					RoleShooterAttributeCfgInfo stRoleShooterAttributeCfgInfo;
					info.vecRoleShooterAttributeCfg.push_back(stRoleShooterAttributeCfgInfo);
				}
				info.vecRoleShooterAttributeCfg[0].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[0].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[1].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[1].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[2].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[2].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[3].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[3].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[4].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[4].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[5].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[5].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[6].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[6].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[7].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[7].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[8].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[8].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[9].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[9].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[10].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[10].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[11].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[11].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[12].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[12].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[13].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[13].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[14].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[14].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[15].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[15].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[16].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[16].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[17].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[17].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[18].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[18].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[19].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[19].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[20].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[20].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleShooterAttributeCfg[21].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleShooterAttributeCfg[21].Value = atoi(pRow->at(j++).c_str());	 //值


				
				if (nullptr != GetRoleShooterCfgInfo(info.lv))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.lv);
					return false;
				}

				m_RoleShooterCfgMap[info.lv] = info;
			}
		}
	}

	return true;
}

bool RoleShooterCfg::UnInit()
{
	Clear();
	return true;
}

const RoleShooterCfgInfo *RoleShooterCfg::GetRoleShooterCfgInfo(int32_t lv)
{
	RoleShooterCfgMap::iterator iter = m_RoleShooterCfgMap.find(lv);
	return (iter != m_RoleShooterCfgMap.end()) ? &iter->second : nullptr;
}
