
using System.Collections;
using System.Collections.Generic;



public class RandomnameManthirdConfig 
{
	public string   name; // 名字 
	public int   id; // 下标 

}

public class RandomnameManthirdConfigTable 
{
    Dictionary<int, RandomnameManthirdConfig> m_configs = 
        new Dictionary<int, RandomnameManthirdConfig>();
    public Dictionary<int, RandomnameManthirdConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 2)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        RandomnameManthirdConfig rec = new RandomnameManthirdConfig();

		rec.id = Utility.ToInt(rh.Read());	 //下标
		rec.name = rh.Read();	 //名字

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Randomname_manthird.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            RandomnameManthirdConfig ac = ConfigProcess(row) as RandomnameManthirdConfig;
            configs.Add(ac.id, ac);
        }
    }
}
