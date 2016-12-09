
using System.Collections;
using System.Collections.Generic;



public class AttributeSuppressConfig 
{
	public int   maxLvlDiff; // 等级差 
	public int   critSuppress; // 暴击压制率 
	public int   stateSuppress; // 状态压制率 
	public int   hitSuppress; // 命中压制率 

}

public class AttributeSuppressConfigTable 
{
    Dictionary<int, AttributeSuppressConfig> m_configs = 
        new Dictionary<int, AttributeSuppressConfig>();
    public Dictionary<int, AttributeSuppressConfig> configs   
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
        AttributeSuppressConfig rec = new AttributeSuppressConfig();

		rec.maxLvlDiff = Utility.ToInt(rh.Read());	 //等级差
		rec.hitSuppress = Utility.ToInt(rh.Read());	 //命中压制率
		rec.critSuppress = Utility.ToInt(rh.Read());	 //暴击压制率
		rec.stateSuppress = Utility.ToInt(rh.Read());	 //状态压制率

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Attribute_suppress.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            AttributeSuppressConfig ac = ConfigProcess(row) as AttributeSuppressConfig;
            configs.Add(ac.maxLvlDiff, ac);
        }
    }
}
