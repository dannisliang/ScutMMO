#include "Common/TableData/RoleWarriorCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


RoleWarriorCfg::RoleWarriorCfg()
{

}

RoleWarriorCfg::~RoleWarriorCfg()
{

}

void RoleWarriorCfg::Clear()
{
	m_RoleWarriorCfgMap.clear();
}


bool RoleWarriorCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				RoleWarriorCfgInfo info;
				std::string str = "";

				info.lv = atoi(pRow->at(j++).c_str());	 //玩家等级
				info.upgradePoint = atoi(pRow->at(j++).c_str());	 //升级获得点数
				for (int t=0;t<22;t++) {
					RoleWarriorAttributeCfgInfo stRoleWarriorAttributeCfgInfo;
					info.vecRoleWarriorAttributeCfg.push_back(stRoleWarriorAttributeCfgInfo);
				}
				info.vecRoleWarriorAttributeCfg[0].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[0].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[1].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[1].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[2].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[2].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[3].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[3].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[4].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[4].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[5].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[5].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[6].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[6].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[7].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[7].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[8].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[8].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[9].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[9].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[10].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[10].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[11].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[11].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[12].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[12].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[13].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[13].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[14].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[14].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[15].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[15].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[16].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[16].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[17].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[17].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[18].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[18].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[19].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[19].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[20].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[20].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecRoleWarriorAttributeCfg[21].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecRoleWarriorAttributeCfg[21].Value = atoi(pRow->at(j++).c_str());	 //值


				
				if (nullptr != GetRoleWarriorCfgInfo(info.lv))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.lv);
					return false;
				}

				m_RoleWarriorCfgMap[info.lv] = info;
			}
		}
	}

	return true;
}

bool RoleWarriorCfg::UnInit()
{
	Clear();
	return true;
}

const RoleWarriorCfgInfo *RoleWarriorCfg::GetRoleWarriorCfgInfo(int32_t lv)
{
	RoleWarriorCfgMap::iterator iter = m_RoleWarriorCfgMap.find(lv);
	return (iter != m_RoleWarriorCfgMap.end()) ? &iter->second : nullptr;
}
