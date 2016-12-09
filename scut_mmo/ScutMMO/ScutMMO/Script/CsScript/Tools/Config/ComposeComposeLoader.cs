
using System.Collections;
using System.Collections.Generic;


public class ComposeComposeItemConfig
{
	public int   num; // 数量 
	public int   id; // ID 
}




public class ComposeComposeConfig 
{
	public ComposeComposeItemConfig[]   item; // 材料 
	public int   composeType; // 合成类型 
	public int   ID; // 物品ID 

}

public class ComposeComposeConfigTable 
{
    Dictionary<int, ComposeComposeConfig> m_configs = 
        new Dictionary<int, ComposeComposeConfig>();
    public Dictionary<int, ComposeComposeConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 10)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        ComposeComposeConfig rec = new ComposeComposeConfig();

		rec.ID = Utility.ToInt(rh.Read());	 //物品ID
		rec.composeType = Utility.ToInt(rh.Read());	 //合成类型
		rec.item = new ComposeComposeItemConfig[4]; 
		for (int i=0;i<4;i++) {
			rec.item[i] = new ComposeComposeItemConfig();
		}
		rec.item[0].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[0].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[1].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[1].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[2].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[2].id = Utility.ToInt(rh.Read());	 //ID
		rec.item[3].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[3].id = Utility.ToInt(rh.Read());	 //ID

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Compose_compose.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            ComposeComposeConfig ac = ConfigProcess(row) as ComposeComposeConfig;
            configs.Add(ac.ID, ac);
        }
    }
}
