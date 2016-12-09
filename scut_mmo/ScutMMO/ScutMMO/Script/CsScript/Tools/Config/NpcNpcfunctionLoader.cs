
using System.Collections;
using System.Collections.Generic;



public class NpcNpcfunctionConfig 
{
	public int   functionType; // 功能类型 
	public int   linkNPC; // 关联NPC 
	public string   functionParameter; // 功能参数 
	public int   functionID; // 功能项ID 

}

public class NpcNpcfunctionConfigTable 
{
    Dictionary<int, NpcNpcfunctionConfig> m_configs = 
        new Dictionary<int, NpcNpcfunctionConfig>();
    public Dictionary<int, NpcNpcfunctionConfig> configs   
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
        NpcNpcfunctionConfig rec = new NpcNpcfunctionConfig();

		rec.functionID = Utility.ToInt(rh.Read());	 //功能项ID
		rec.linkNPC = Utility.ToInt(rh.Read());	 //关联NPC
		rec.functionType = Utility.ToInt(rh.Read());	 //功能类型
		rec.functionParameter = rh.Read();	 //功能参数

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Npc_npcfunction.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            NpcNpcfunctionConfig ac = ConfigProcess(row) as NpcNpcfunctionConfig;
            configs.Add(ac.functionID, ac);
        }
    }
}
