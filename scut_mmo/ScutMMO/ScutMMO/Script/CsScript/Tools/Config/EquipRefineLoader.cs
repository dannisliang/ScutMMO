
using System.Collections;
using System.Collections.Generic;


public class EquipRefineItemConfig
{
	public string   ratio; // 系数 
	public int   id; // ID 
}




public class EquipRefineConfig 
{
	public float   recovery; // 回收比例 
	public EquipRefineItemConfig[]   item; // 物品 
	public string   gold; // 金币消耗 
	public int   id; // 装备ID 

}

public class EquipRefineConfigTable 
{
    Dictionary<int, EquipRefineConfig> m_configs = 
        new Dictionary<int, EquipRefineConfig>();
    public Dictionary<int, EquipRefineConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 19)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        EquipRefineConfig rec = new EquipRefineConfig();

		rec.id = Utility.ToInt(rh.Read());	 //装备ID
		rec.gold = rh.Read();	 //金币消耗
		rec.recovery = Utility.ToFloat(rh.Read());	 //回收比例
		rec.item = new EquipRefineItemConfig[8]; 
		for (int i=0;i<8;i++) {
			rec.item[i] = new EquipRefineItemConfig();
		}
		rec.item[0].ratio = rh.Read();	 //系数
		rec.item[0].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[1].ratio = rh.Read();	 //系数
		rec.item[1].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[2].ratio = rh.Read();	 //系数
		rec.item[2].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[3].ratio = rh.Read();	 //系数
		rec.item[3].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[4].ratio = rh.Read();	 //系数
		rec.item[4].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[5].ratio = rh.Read();	 //系数
		rec.item[5].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[6].ratio = rh.Read();	 //系数
		rec.item[6].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[7].ratio = rh.Read();	 //系数
		rec.item[7].id = Utility.ToInt(rh.Read());	 //ID

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Equip_refine.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            EquipRefineConfig ac = ConfigProcess(row) as EquipRefineConfig;
            configs.Add(ac.id, ac);
        }
    }
}
