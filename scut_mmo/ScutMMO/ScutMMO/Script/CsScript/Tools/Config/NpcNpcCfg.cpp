#include "Common/TableData/NpcNpcCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


NpcNpcCfg::NpcNpcCfg()
{

}

NpcNpcCfg::~NpcNpcCfg()
{

}

void NpcNpcCfg::Clear()
{
	m_NpcNpcCfgMap.clear();
}


bool NpcNpcCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
				NpcNpcCfgInfo info;
				std::string str = "";

				info.npcID = atoi(pRow->at(j++).c_str());	 //NPC��ID
				info.npcCamp = atoi(pRow->at(j++).c_str());	 //NPC��Ӫ
				info.isFunctionNPC = atoi(pRow->at(j++).c_str());	 //�Ƿ�Ϊ����NPC
				info.npcFightType = atoi(pRow->at(j++).c_str());	 //NPCս������
				info.linkMonster = atoi(pRow->at(j++).c_str());	 //����ս������


				
				if (nullptr != GetNpcNpcCfgInfo(info.npcID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.npcID);
					return false;
				}

				m_NpcNpcCfgMap[info.npcID] = info;
			}
		}
	}

	return true;
}

bool NpcNpcCfg::UnInit()
{
	Clear();
	return true;
}

const NpcNpcCfgInfo *NpcNpcCfg::GetNpcNpcCfgInfo(int32_t npcID)
{
	NpcNpcCfgMap::iterator iter = m_NpcNpcCfgMap.find(npcID);
	return (iter != m_NpcNpcCfgMap.end()) ? &iter->second : nullptr;
}
