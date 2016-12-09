
using System.Collections;
using System.Collections.Generic;


public class EquipSuitAttributeConfig
{
	public int   sctivation; // 穿戴数量 
	public int   type; //  
	public int   value; // 数值 
}




public class EquipSuitConfig 
{
	public EquipSuitAttributeConfig[]   attribute; // 套件激活属性 
	public int   id; // 套装ID 
	public string   name; // 套装名称 
	public int   suiteValue; // 套装套件数量 
	public int[]   equipId; // 装备ID 

}

public class EquipSuitConfigTable 
{
    Dictionary<int, EquipSuitConfig> m_configs = 
        new Dictionary<int, EquipSuitConfig>();
    public Dictionary<int, EquipSuitConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 28)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        EquipSuitConfig rec = new EquipSuitConfig();

		rec.id = Utility.ToInt(rh.Read());	 //套装ID
		rec.name = rh.Read();	 //套装名称
		rec.suiteValue = Utility.ToInt(rh.Read());	 //套装套件数量
		rec.equipId = new int[10]; 
		rec.equipId[0] = Utility.ToInt(rh.Read());	 //装备ID
		rec.equipId[1] = Utility.ToInt(rh.Read());	 //装备ID
		rec.equipId[2] = Utility.ToInt(rh.Read());	 //装备ID
		rec.equipId[3] = Utility.ToInt(rh.Read());	 //装备ID
		rec.equipId[4] = Utility.ToInt(rh.Read());	 //装备ID
		rec.equipId[5] = Utility.ToInt(rh.Read());	 //装备ID
		rec.equipId[6] = Utility.ToInt(rh.Read());	 //装备ID
		rec.equipId[7] = Utility.ToInt(rh.Read());	 //装备ID
		rec.equipId[8] = Utility.ToInt(rh.Read());	 //装备ID
		rec.equipId[9] = Utility.ToInt(rh.Read());	 //装备ID
		rec.attribute = new EquipSuitAttributeConfig[5]; 
		for (int i=0;i<5;i++) {
			rec.attribute[i] = new EquipSuitAttributeConfig();
		}
		rec.attribute[0].sctivation = Utility.ToInt(rh.Read());	 //穿戴数量
		rec.attribute[0].type = Utility.ToInt(rh.Read());	 //
		rec.attribute[0].value = Utility.ToInt(rh.Read());	 //数值
		rec.attribute[1].sctivation = Utility.ToInt(rh.Read());	 //穿戴数量
		rec.attribute[1].type = Utility.ToInt(rh.Read());	 //
		rec.attribute[1].value = Utility.ToInt(rh.Read());	 //数值
		rec.attribute[2].sctivation = Utility.ToInt(rh.Read());	 //穿戴数量
		rec.attribute[2].type = Utility.ToInt(rh.Read());	 //
		rec.attribute[2].value = Utility.ToInt(rh.Read());	 //数值
		rec.attribute[3].sctivation = Utility.ToInt(rh.Read());	 //穿戴数量
		rec.attribute[3].type = Utility.ToInt(rh.Read());	 //
		rec.attribute[3].value = Utility.ToInt(rh.Read());	 //数值
		rec.attribute[4].sctivation = Utility.ToInt(rh.Read());	 //穿戴数量
		rec.attribute[4].type = Utility.ToInt(rh.Read());	 //
		rec.attribute[4].value = Utility.ToInt(rh.Read());	 //数值

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Equip_suit.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            EquipSuitConfig ac = ConfigProcess(row) as EquipSuitConfig;
            configs.Add(ac.id, ac);
        }
    }
}
