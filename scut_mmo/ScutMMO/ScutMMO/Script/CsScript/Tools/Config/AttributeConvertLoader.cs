
using System.Collections;
using System.Collections.Generic;


public class AttributeConvertAttributeConfig
{
	public int   Type; // ID 
	public int   Value; // 值 
}




public class AttributeConvertConfig 
{
	public int   attribute_Id; // 属性ID 
	public AttributeConvertAttributeConfig[]   attribute; // 属性 
	public int   constantID; // 配置ID 
	public int   professionID; // 职业ID 

}

public class AttributeConvertConfigTable 
{
    Dictionary<int, AttributeConvertConfig> m_configs = 
        new Dictionary<int, AttributeConvertConfig>();
    public Dictionary<int, AttributeConvertConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 9)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        AttributeConvertConfig rec = new AttributeConvertConfig();

		rec.constantID = Utility.ToInt(rh.Read());	 //配置ID
		rec.professionID = Utility.ToInt(rh.Read());	 //职业ID
		rec.attribute_Id = Utility.ToInt(rh.Read());	 //属性ID
		rec.attribute = new AttributeConvertAttributeConfig[3]; 
		for (int i=0;i<3;i++) {
			rec.attribute[i] = new AttributeConvertAttributeConfig();
		}
		rec.attribute[0].Type = Utility.ToInt(rh.Read());	 //ID
		rec.attribute[0].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[1].Type = Utility.ToInt(rh.Read());	 //ID
		rec.attribute[1].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[2].Type = Utility.ToInt(rh.Read());	 //ID
		rec.attribute[2].Value = Utility.ToInt(rh.Read());	 //值

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Attribute_convert.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            AttributeConvertConfig ac = ConfigProcess(row) as AttributeConvertConfig;
            configs.Add(ac.constantID, ac);
        }
    }
}
