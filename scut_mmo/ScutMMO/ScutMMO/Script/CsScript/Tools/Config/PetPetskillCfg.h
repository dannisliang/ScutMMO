
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class PetPetskillCfg : public ManualSingleton <PetPetskillCfg>
{
	friend ManualSingleton <PetPetskillCfg>;
public:
	PetPetskillCfg();
	~PetPetskillCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const PetPetskillCfgInfo *GetPetPetskillCfgInfo(int32_t skillId);
	const PetPetskillCfgMap *GetPetPetskillCfgMap() { return &m_PetPetskillCfgMap; }
private:
	PetPetskillCfgMap m_PetPetskillCfgMap;
};

#define  g_MakePetPetskillCfgTable() (PetPetskillCfg::Instance())
#define  g_GetPetPetskillCfgTable() (PetPetskillCfg::GetInstance())
#define  g_DelPetPetskillCfgTable() (PetPetskillCfg::Destroy())