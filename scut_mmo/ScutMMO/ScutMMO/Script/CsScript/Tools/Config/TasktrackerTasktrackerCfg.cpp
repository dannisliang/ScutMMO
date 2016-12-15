#include "Common/TableData/TasktrackerTasktrackerCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


TasktrackerTasktrackerCfg::TasktrackerTasktrackerCfg()
{

}

TasktrackerTasktrackerCfg::~TasktrackerTasktrackerCfg()
{

}

void TasktrackerTasktrackerCfg::Clear()
{
	m_TasktrackerTasktrackerCfgMap.clear();
}


bool TasktrackerTasktrackerCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 2)
			{
				continue;
			}

			{
				TasktrackerTasktrackerCfgInfo info;
				std::string str = "";

				info.comID = atoi(pRow->at(j++).c_str());	 //完成条件类型ID
				info.tracker = pRow->at(j++).c_str();	 //任务追踪说明


				
				if (nullptr != GetTasktrackerTasktrackerCfgInfo(info.comID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.comID);
					return false;
				}

				m_TasktrackerTasktrackerCfgMap[info.comID] = info;
			}
		}
	}

	return true;
}

bool TasktrackerTasktrackerCfg::UnInit()
{
	Clear();
	return true;
}

const TasktrackerTasktrackerCfgInfo *TasktrackerTasktrackerCfg::GetTasktrackerTasktrackerCfgInfo(int32_t comID)
{
	TasktrackerTasktrackerCfgMap::iterator iter = m_TasktrackerTasktrackerCfgMap.find(comID);
	return (iter != m_TasktrackerTasktrackerCfgMap.end()) ? &iter->second : nullptr;
}
