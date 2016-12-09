
using System.Collections;
using System.Collections.Generic;



public class TeleportTeleportConfig 
{
	public int   toSceneID; // 目标场景 
	public int   standID; // 目标点ID 
	public int   teleportID; // 传送点ID 
	public int   isSameScene; // 是否同场景 

}

public class TeleportTeleportConfigTable 
{
    Dictionary<int, TeleportTeleportConfig> m_configs = 
        new Dictionary<int, TeleportTeleportConfig>();
    public Dictionary<int, TeleportTeleportConfig> configs   
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
        TeleportTeleportConfig rec = new TeleportTeleportConfig();

		rec.teleportID = Utility.ToInt(rh.Read());	 //传送点ID
		rec.isSameScene = Utility.ToInt(rh.Read());	 //是否同场景
		rec.toSceneID = Utility.ToInt(rh.Read());	 //目标场景
		rec.standID = Utility.ToInt(rh.Read());	 //目标点ID

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Teleport_teleport.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            TeleportTeleportConfig ac = ConfigProcess(row) as TeleportTeleportConfig;
            configs.Add(ac.teleportID, ac);
        }
    }
}
