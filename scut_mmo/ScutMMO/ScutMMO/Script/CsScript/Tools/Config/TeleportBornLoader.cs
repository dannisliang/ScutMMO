
using System.Collections;
using System.Collections.Generic;



public class TeleportBornConfig 
{
	public int   id; // 出生点ID 
	public int   type; // 点类型 
	public int   roleBornRange; // 角色出生范围 
	public int   camp; // 所属阵营 
	public int   scene; // 所属场景 

}

public class TeleportBornConfigTable 
{
    Dictionary<int, TeleportBornConfig> m_configs = 
        new Dictionary<int, TeleportBornConfig>();
    public Dictionary<int, TeleportBornConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 5)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        TeleportBornConfig rec = new TeleportBornConfig();

		rec.id = Utility.ToInt(rh.Read());	 //出生点ID
		rec.type = Utility.ToInt(rh.Read());	 //点类型
		rec.scene = Utility.ToInt(rh.Read());	 //所属场景
		rec.camp = Utility.ToInt(rh.Read());	 //所属阵营
		rec.roleBornRange = Utility.ToInt(rh.Read());	 //角色出生范围

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Teleport_born.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            TeleportBornConfig ac = ConfigProcess(row) as TeleportBornConfig;
            configs.Add(ac.id, ac);
        }
    }
}
