
using System.Collections;
using System.Collections.Generic;



public class TeleportSafeareaConfig 
{
	public int   linkArea; // 关联区域 
	public int   id; // 安全区域ID 
	public int   camp; // 所属阵营 
	public int   scene; // 所属场景 

}

public class TeleportSafeareaConfigTable 
{
    Dictionary<int, TeleportSafeareaConfig> m_configs = 
        new Dictionary<int, TeleportSafeareaConfig>();
    public Dictionary<int, TeleportSafeareaConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 4)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        TeleportSafeareaConfig rec = new TeleportSafeareaConfig();

		rec.id = Utility.ToInt(rh.Read());	 //安全区域ID
		rec.scene = Utility.ToInt(rh.Read());	 //所属场景
		rec.camp = Utility.ToInt(rh.Read());	 //所属阵营
		rec.linkArea = Utility.ToInt(rh.Read());	 //关联区域

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Teleport_safearea.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            TeleportSafeareaConfig ac = ConfigProcess(row) as TeleportSafeareaConfig;
            configs.Add(ac.id, ac);
        }
    }
}
