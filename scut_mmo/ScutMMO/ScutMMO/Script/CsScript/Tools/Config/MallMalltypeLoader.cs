
using System.Collections;
using System.Collections.Generic;



public class MallMalltypeConfig 
{
	public int   priority; // 优先级 
	public string   res; // 分类名称资源 
	public int   id; // 分类ID 

}

public class MallMalltypeConfigTable 
{
    Dictionary<int, MallMalltypeConfig> m_configs = 
        new Dictionary<int, MallMalltypeConfig>();
    public Dictionary<int, MallMalltypeConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 3)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        MallMalltypeConfig rec = new MallMalltypeConfig();

		rec.id = Utility.ToInt(rh.Read());	 //分类ID
		rec.res = rh.Read();	 //分类名称资源
		rec.priority = Utility.ToInt(rh.Read());	 //优先级

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Mall_malltype.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            MallMalltypeConfig ac = ConfigProcess(row) as MallMalltypeConfig;
            configs.Add(ac.id, ac);
        }
    }
}
