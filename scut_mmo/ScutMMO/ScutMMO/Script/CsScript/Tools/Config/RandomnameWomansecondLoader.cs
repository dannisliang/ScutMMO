
using System.Collections;
using System.Collections.Generic;



public class RandomnameWomansecondConfig 
{
	public string   name; // 名字 
	public int   id; // 下标 

}

public class RandomnameWomansecondConfigTable 
{
    Dictionary<int, RandomnameWomansecondConfig> m_configs = 
        new Dictionary<int, RandomnameWomansecondConfig>();
    public Dictionary<int, RandomnameWomansecondConfig> configs   
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
        RandomnameWomansecondConfig rec = new RandomnameWomansecondConfig();

		rec.id = Utility.ToInt(rh.Read());	 //下标
		rec.name = rh.Read();	 //名字

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Randomname_womansecond.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            RandomnameWomansecondConfig ac = ConfigProcess(row) as RandomnameWomansecondConfig;
            configs.Add(ac.id, ac);
        }
    }
}
