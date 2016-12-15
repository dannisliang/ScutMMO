
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class TasktrackerTasktrackerCfg : public ManualSingleton <TasktrackerTasktrackerCfg>
{
	friend ManualSingleton <TasktrackerTasktrackerCfg>;
public:
	TasktrackerTasktrackerCfg();
	~TasktrackerTasktrackerCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const TasktrackerTasktrackerCfgInfo *GetTasktrackerTasktrackerCfgInfo(int32_t comID);
	const TasktrackerTasktrackerCfgMap *GetTasktrackerTasktrackerCfgMap() { return &m_TasktrackerTasktrackerCfgMap; }
private:
	TasktrackerTasktrackerCfgMap m_TasktrackerTasktrackerCfgMap;
};

#define  g_MakeTasktrackerTasktrackerCfgTable() (TasktrackerTasktrackerCfg::Instance())
#define  g_GetTasktrackerTasktrackerCfgTable() (TasktrackerTasktrackerCfg::GetInstance())
#define  g_DelTasktrackerTasktrackerCfgTable() (TasktrackerTasktrackerCfg::Destroy())