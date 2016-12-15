
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class PetPetCfg : public ManualSingleton <PetPetCfg>
{
	friend ManualSingleton <PetPetCfg>;
public:
	PetPetCfg();
	~PetPetCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const PetPetCfgInfo *GetPetPetCfgInfo(int32_t petId);
	const PetPetCfgMap *GetPetPetCfgMap() { return &m_PetPetCfgMap; }
private:
	PetPetCfgMap m_PetPetCfgMap;
};

#define  g_MakePetPetCfgTable() (PetPetCfg::Instance())
#define  g_GetPetPetCfgTable() (PetPetCfg::GetInstance())
#define  g_DelPetPetCfgTable() (PetPetCfg::Destroy())