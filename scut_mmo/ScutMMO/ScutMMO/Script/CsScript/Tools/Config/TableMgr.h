#pragma once

#include <stdint.h>
#include "base/core/singleton.h"

class TableMgr : public ManualSingleton<TableMgr> 
{
    friend class ManualSingleton<TableMgr>;

public:
    bool Init();
    bool UnInit();

public:
    TableMgr();
    ~TableMgr();
};

#define  g_MakeTableDataMgr() (TableMgr::Instance())
#define  g_GetTableDataMgr()  (TableMgr::GetInstance())
#define  g_DelTableDataMgr()  (TableMgr::Destroy())