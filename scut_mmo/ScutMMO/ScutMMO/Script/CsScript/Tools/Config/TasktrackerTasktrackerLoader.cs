
using System.Collections;
using System.Collections.Generic;



public class TasktrackerTasktrackerConfig 
{
	public string   tracker; // 任务追踪说明 
	public int   comID; // 完成条件类型ID 

}

public class TasktrackerTasktrackerConfigTable 
{
    Dictionary<int, TasktrackerTasktrackerConfig> m_configs = 
        new Dictionary<int, TasktrackerTasktrackerConfig>();
    public Dictionary<int, TasktrackerTasktrackerConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 2)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        TasktrackerTasktrackerConfig rec = new TasktrackerTasktrackerConfig();

		rec.comID = Utility.ToInt(rh.Read());	 //完成条件类型ID
		rec.tracker = rh.Read();	 //任务追踪说明

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Tasktracker_tasktracker.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            TasktrackerTasktrackerConfig ac = ConfigProcess(row) as TasktrackerTasktrackerConfig;
            configs.Add(ac.comID, ac);
        }
    }
}
