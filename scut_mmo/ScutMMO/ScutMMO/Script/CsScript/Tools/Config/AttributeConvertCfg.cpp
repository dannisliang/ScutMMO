#include "Common/TableData/AttributeConvertCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


AttributeConvertCfg::AttributeConvertCfg()
{

}

AttributeConvertCfg::~AttributeConvertCfg()
{

}

void AttributeConvertCfg::Clear()
{
	m_AttributeConvertCfgMap.clear();
}


bool AttributeConvertCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 9)
			{
				continue;
			}

			{
				AttributeConvertCfgInfo info;
				std::string str = "";

				info.constantID = atoi(pRow->at(j++).c_str());	 //配置ID
				info.professionID = atoi(pRow->at(j++).c_str());	 //职业ID
				info.attribute_Id = atoi(pRow->at(j++).c_str());	 //属性ID
				for (int t=0;t<3;t++) {
					AttributeConvertAttributeCfgInfo stAttributeConvertAttributeCfgInfo;
					info.vecAttributeConvertAttributeCfg.push_back(stAttributeConvertAttributeCfgInfo);
				}
				info.vecAttributeConvertAttributeCfg[0].Type = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAttributeConvertAttributeCfg[0].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecAttributeConvertAttributeCfg[1].Type = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAttributeConvertAttributeCfg[1].Value = atoi(pRow->at(j++).c_str());	 //值
				info.vecAttributeConvertAttributeCfg[2].Type = atoi(pRow->at(j++).c_str());	 //ID
				info.vecAttributeConvertAttributeCfg[2].Value = atoi(pRow->at(j++).c_str());	 //值


				
				if (nullptr != GetAttributeConvertCfgInfo(info.constantID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.constantID);
					return false;
				}

				m_AttributeConvertCfgMap[info.constantID] = info;
			}
		}
	}

	return true;
}

bool AttributeConvertCfg::UnInit()
{
	Clear();
	return true;
}

const AttributeConvertCfgInfo *AttributeConvertCfg::GetAttributeConvertCfgInfo(int32_t constantID)
{
	AttributeConvertCfgMap::iterator iter = m_AttributeConvertCfgMap.find(constantID);
	return (iter != m_AttributeConvertCfgMap.end()) ? &iter->second : nullptr;
}
