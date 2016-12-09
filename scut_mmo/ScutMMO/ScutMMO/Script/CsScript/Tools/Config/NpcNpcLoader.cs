
using System.Collections;
using System.Collections.Generic;



public class NpcNpcConfig 
{
	public int   npcID; // NPC的ID 
	public int   npcFightType; // NPC战斗类型 
	public int   linkMonster; // 关联战斗怪物 
	public int   isFunctionNPC; // 是否为功能NPC 
	public int   npcCamp; // NPC阵营 

}

public class NpcNpcConfigTable 
{
    Dictionary<int, NpcNpcConfig> m_configs = 
        new Dictionary<int, NpcNpcConfig>();
    public Dictionary<int, NpcNpcConfig> configs   
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
        NpcNpcConfig rec = new NpcNpcConfig();

		rec.npcID = Utility.ToInt(rh.Read());	 //NPC的ID
		rec.npcCamp = Utility.ToInt(rh.Read());	 //NPC阵营
		rec.isFunctionNPC = Utility.ToInt(rh.Read());	 //是否为功能NPC
		rec.npcFightType = Utility.ToInt(rh.Read());	 //NPC战斗类型
		rec.linkMonster = Utility.ToInt(rh.Read());	 //关联战斗怪物

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Npc_npc.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            NpcNpcConfig ac = ConfigProcess(row) as NpcNpcConfig;
            configs.Add(ac.npcID, ac);
        }
    }
}
