
using System.Collections;
using System.Collections.Generic;



public class RandomnameWomanthirdConfig 
{
	public string   name; // 名字 
	public int   id; // 下标 

}

public class RandomnameWomanthirdConfigTable 
{
    Dictionary<int, RandomnameWomanthirdConfig> m_configs = 
        new Dictionary<int, RandomnameWomanthirdConfig>();
    public Dictionary<int, RandomnameWomanthirdConfig> configs   
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
        RandomnameWomanthirdConfig rec = new RandomnameWomanthirdConfig();

		rec.id = Utility.ToInt(rh.Read());	 //下标
		rec.name = rh.Read();	 //名字

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Randomname_womanthird.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            RandomnameWomanthirdConfig ac = ConfigProcess(row) as RandomnameWomanthirdConfig;
            configs.Add(ac.id, ac);
        }
    }
}
