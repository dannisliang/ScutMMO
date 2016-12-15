#include "Common/TableData/SkillBuffCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


SkillBuffCfg::SkillBuffCfg()
{

}

SkillBuffCfg::~SkillBuffCfg()
{

}

void SkillBuffCfg::Clear()
{
	m_SkillBuffCfgMap.clear();
}


bool SkillBuffCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 19)
			{
				continue;
			}

			{
				SkillBuffCfgInfo info;
				std::string str = "";

				info.stateBagID = atoi(pRow->at(j++).c_str());	 //附加状态包id
				info.stateBagName = pRow->at(j++).c_str();	 //状态包名称
				info.stateBagIcon = pRow->at(j++).c_str();	 //状态包图标
				info.effectResources = pRow->at(j++).c_str();	 //特效路径
				info.startType = atoi(pRow->at(j++).c_str());	 //生效条件
				info.delayTime = atoi(pRow->at(j++).c_str());	 //延迟生效时间
				info.endType = pRow->at(j++).c_str();	 //常规结束条件
				info.stateBagRule = atoi(pRow->at(j++).c_str());	 //同一状态包叠加规则
				info.mask = atoi(pRow->at(j++).c_str());	 //32位掩码
				for (int t=0;t<5;t++) {
					SkillBuffEffectCfgInfo stSkillBuffEffectCfgInfo;
					info.vecSkillBuffEffectCfg.push_back(stSkillBuffEffectCfgInfo);
				}
				info.vecSkillBuffEffectCfg[0].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecSkillBuffEffectCfg[0].Param = pRow->at(j++).c_str();	 //参数
				info.vecSkillBuffEffectCfg[1].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecSkillBuffEffectCfg[1].Param = pRow->at(j++).c_str();	 //参数
				info.vecSkillBuffEffectCfg[2].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecSkillBuffEffectCfg[2].Param = pRow->at(j++).c_str();	 //参数
				info.vecSkillBuffEffectCfg[3].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecSkillBuffEffectCfg[3].Param = pRow->at(j++).c_str();	 //参数
				info.vecSkillBuffEffectCfg[4].Type = atoi(pRow->at(j++).c_str());	 //类型
				info.vecSkillBuffEffectCfg[4].Param = pRow->at(j++).c_str();	 //参数


				
				if (nullptr != GetSkillBuffCfgInfo(info.stateBagID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.stateBagID);
					return false;
				}

				m_SkillBuffCfgMap[info.stateBagID] = info;
			}
		}
	}

	return true;
}

bool SkillBuffCfg::UnInit()
{
	Clear();
	return true;
}

const SkillBuffCfgInfo *SkillBuffCfg::GetSkillBuffCfgInfo(int32_t stateBagID)
{
	SkillBuffCfgMap::iterator iter = m_SkillBuffCfgMap.find(stateBagID);
	return (iter != m_SkillBuffCfgMap.end()) ? &iter->second : nullptr;
}
