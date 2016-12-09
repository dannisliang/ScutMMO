
using System.Collections;
using System.Collections.Generic;



public class EquipFashionConfig 
{
	public int   attributeValue; // 属性数值 
	public int   position; // 装备位置 
	public int   id; // 时装ID 
	public int   days; // 有效时间 
	public int   attributeType; // 属性类型 
	public int   fashionValue; // 时装套件数量 
	public string   name; // 时装名称 

}

public class EquipFashionConfigTable 
{
    Dictionary<int, EquipFashionConfig> m_configs = 
        new Dictionary<int, EquipFashionConfig>();
    public Dictionary<int, EquipFashionConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 7)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        EquipFashionConfig rec = new EquipFashionConfig();

		rec.id = Utility.ToInt(rh.Read());	 //时装ID
		rec.name = rh.Read();	 //时装名称
		rec.position = Utility.ToInt(rh.Read());	 //装备位置
		rec.fashionValue = Utility.ToInt(rh.Read());	 //时装套件数量
		rec.attributeType = Utility.ToInt(rh.Read());	 //属性类型
		rec.attributeValue = Utility.ToInt(rh.Read());	 //属性数值
		rec.days = Utility.ToInt(rh.Read());	 //有效时间

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Equip_fashion.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            EquipFashionConfig ac = ConfigProcess(row) as EquipFashionConfig;
            configs.Add(ac.id, ac);
        }
    }
}
