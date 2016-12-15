#include "Common/TableData/AreaAreaCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


AreaAreaCfg::AreaAreaCfg()
{

}

AreaAreaCfg::~AreaAreaCfg()
{

}

void AreaAreaCfg::Clear()
{
	m_AreaAreaCfgMap.clear();
}


bool AreaAreaCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 6)
			{
				continue;
			}

			{
				AreaAreaCfgInfo info;
				std::string str = "";

				info.id = atoi(pRow->at(j++).c_str());	 //����ID
				info.name = pRow->at(j++).c_str();	 //��������
				info.shapeType = atoi(pRow->at(j++).c_str());	 //��״����
				info.subType = atoi(pRow->at(j++).c_str());	 //ϸ������
				info.showType = atoi(pRow->at(j++).c_str());	 //��ʾ����
				info.belongToSceneID = atoi(pRow->at(j++).c_str());	 //��������


				
				if (nullptr != GetAreaAreaCfgInfo(info.id))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.id);
					return false;
				}

				m_AreaAreaCfgMap[info.id] = info;
			}
		}
	}

	return true;
}

bool AreaAreaCfg::UnInit()
{
	Clear();
	return true;
}

const AreaAreaCfgInfo *AreaAreaCfg::GetAreaAreaCfgInfo(int32_t id)
{
	AreaAreaCfgMap::iterator iter = m_AreaAreaCfgMap.find(id);
	return (iter != m_AreaAreaCfgMap.end()) ? &iter->second : nullptr;
}
