#include "Common/TableData/PetPetCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


PetPetCfg::PetPetCfg()
{

}

PetPetCfg::~PetPetCfg()
{

}

void PetPetCfg::Clear()
{
	m_PetPetCfgMap.clear();
}


bool PetPetCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 20)
			{
				continue;
			}

			{
				PetPetCfgInfo info;
				std::string str = "";

				info.petId = atoi(pRow->at(j++).c_str());	 //精灵ID
				info.level = atoi(pRow->at(j++).c_str());	 //对应等级
				info.star = atoi(pRow->at(j++).c_str());	 //培养星数
				info.maxHP = atoi(pRow->at(j++).c_str());	 //最大生命值
				info.maxMP = atoi(pRow->at(j++).c_str());	 //最大魔法值
				info.ap = atoi(pRow->at(j++).c_str());	 //物理攻击
				info.mat = atoi(pRow->at(j++).c_str());	 //魔法攻击
				info.dp = atoi(pRow->at(j++).c_str());	 //物理防御
				info.mdp = atoi(pRow->at(j++).c_str());	 //魔法防御
				info.fragmentId = atoi(pRow->at(j++).c_str());	 //升星消耗碎片id
				info.costFragmentNum = atoi(pRow->at(j++).c_str());	 //消耗碎片数量
				info.trainId = atoi(pRow->at(j++).c_str());	 //升星后id
				info.evolveId = atoi(pRow->at(j++).c_str());	 //进化后id
				info.stage = atoi(pRow->at(j++).c_str());	 //阶段
				info.petQuality = atoi(pRow->at(j++).c_str());	 //精灵品质
				info.stoneId = atoi(pRow->at(j++).c_str());	 //消耗进化石id
				info.costStoneNum = atoi(pRow->at(j++).c_str());	 //消耗进化石数量
				info.commonSkillId = atoi(pRow->at(j++).c_str());	 //普攻ID
				for (int t=0;t<2;t++) {
					int32_t data;
					info.vec_costMoney.push_back(data);
				}
				info.vec_costMoney[0] = atoi(pRow->at(j++).c_str());	 //消耗金币数量
				info.vec_costMoney[1] = atoi(pRow->at(j++).c_str());	 //消耗金币数量


				
				if (nullptr != GetPetPetCfgInfo(info.petId))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.petId);
					return false;
				}

				m_PetPetCfgMap[info.petId] = info;
			}
		}
	}

	return true;
}

bool PetPetCfg::UnInit()
{
	Clear();
	return true;
}

const PetPetCfgInfo *PetPetCfg::GetPetPetCfgInfo(int32_t petId)
{
	PetPetCfgMap::iterator iter = m_PetPetCfgMap.find(petId);
	return (iter != m_PetPetCfgMap.end()) ? &iter->second : nullptr;
}
