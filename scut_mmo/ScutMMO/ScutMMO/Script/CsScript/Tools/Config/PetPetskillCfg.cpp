#include "Common/TableData/PetPetskillCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


PetPetskillCfg::PetPetskillCfg()
{

}

PetPetskillCfg::~PetPetskillCfg()
{

}

void PetPetskillCfg::Clear()
{
	m_PetPetskillCfgMap.clear();
}


bool PetPetskillCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 5)
			{
				continue;
			}

			{
				PetPetskillCfgInfo info;
				std::string str = "";

				info.skillId = atoi(pRow->at(j++).c_str());	 //技能ID
				info.skillLevel = atoi(pRow->at(j++).c_str());	 //技能等级
				info.bookId = atoi(pRow->at(j++).c_str());	 //消耗技能书id
				info.bookNum = atoi(pRow->at(j++).c_str());	 //技能书数量
				info.costMoney = atoi(pRow->at(j++).c_str());	 //金币数量


				
				if (nullptr != GetPetPetskillCfgInfo(info.skillId))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.skillId);
					return false;
				}

				m_PetPetskillCfgMap[info.skillId] = info;
			}
		}
	}

	return true;
}

bool PetPetskillCfg::UnInit()
{
	Clear();
	return true;
}

const PetPetskillCfgInfo *PetPetskillCfg::GetPetPetskillCfgInfo(int32_t skillId)
{
	PetPetskillCfgMap::iterator iter = m_PetPetskillCfgMap.find(skillId);
	return (iter != m_PetPetskillCfgMap.end()) ? &iter->second : nullptr;
}
