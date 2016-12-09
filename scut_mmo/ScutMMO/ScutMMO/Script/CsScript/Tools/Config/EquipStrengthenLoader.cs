
using System.Collections;
using System.Collections.Generic;



public class EquipStrengthenConfig 
{
	public string   itemRatio; // 物品系数 
	public string   gold; // 金币消耗 
	public float   recovery; // 回收比例 
	public int   id; // 装备ID 
	public int   itemId; // 物品ID 

}

public class EquipStrengthenConfigTable 
{
    Dictionary<int, EquipStrengthenConfig> m_configs = 
        new Dictionary<int, EquipStrengthenConfig>();
    public Dictionary<int, EquipStrengthenConfig> configs   
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
        EquipStrengthenConfig rec = new EquipStrengthenConfig();

		rec.id = Utility.ToInt(rh.Read());	 //装备ID
		rec.itemId = Utility.ToInt(rh.Read());	 //物品ID
		rec.itemRatio = rh.Read();	 //物品系数
		rec.gold = rh.Read();	 //金币消耗
		rec.recovery = Utility.ToFloat(rh.Read());	 //回收比例

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Equip_strengthen.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            EquipStrengthenConfig ac = ConfigProcess(row) as EquipStrengthenConfig;
            configs.Add(ac.id, ac);
        }
    }
}
