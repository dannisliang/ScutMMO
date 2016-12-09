
using System.Collections;
using System.Collections.Generic;



public class RandomnameMansecondConfig 
{
	public string   name; // 名字 
	public int   id; // 下标 

}

public class RandomnameMansecondConfigTable 
{
    Dictionary<int, RandomnameMansecondConfig> m_configs = 
        new Dictionary<int, RandomnameMansecondConfig>();
    public Dictionary<int, RandomnameMansecondConfig> configs   
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
        RandomnameMansecondConfig rec = new RandomnameMansecondConfig();

		rec.id = Utility.ToInt(rh.Read());	 //下标
		rec.name = rh.Read();	 //名字

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Randomname_mansecond.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            RandomnameMansecondConfig ac = ConfigProcess(row) as RandomnameMansecondConfig;
            configs.Add(ac.id, ac);
        }
    }
}
