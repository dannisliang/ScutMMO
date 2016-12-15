#include "Common/TableData/AvocationAvocationskillCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


AvocationAvocationskillCfg::AvocationAvocationskillCfg()
{

}

AvocationAvocationskillCfg::~AvocationAvocationskillCfg()
{

}

void AvocationAvocationskillCfg::Clear()
{
	m_AvocationAvocationskillCfgMap.clear();
}


bool AvocationAvocationskillCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 7)
			{
				continue;
			}

			{
				AvocationAvocationskillCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //id
				info.classification = atoi(pRow->at(j++).c_str());	 //分类
				info.type = atoi(pRow->at(j++).c_str());	 //类型
				info.level = atoi(pRow->at(j++).c_str());	 //等级
				info.exp = atoi(pRow->at(j++).c_str());	 //经验值
				info.needMoney = atoi(pRow->at(j++).c_str());	 //消耗金币数量
				info.openCreateList = pRow->at(j++).c_str();	 //开启制造列表


				
				if (nullptr != GetAvocationAvocationskillCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_AvocationAvocationskillCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool AvocationAvocationskillCfg::UnInit()
{
	Clear();
	return true;
}

const AvocationAvocationskillCfgInfo *AvocationAvocationskillCfg::GetAvocationAvocationskillCfgInfo(int32_t id)
{
	AvocationAvocationskillCfgMap::iterator iter = m_AvocationAvocationskillCfgMap.find(id);
	return (iter != m_AvocationAvocationskillCfgMap.end()) ? &iter->second : nullptr;
}
