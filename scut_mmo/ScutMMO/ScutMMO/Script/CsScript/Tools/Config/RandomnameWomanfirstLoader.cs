
using System.Collections;
using System.Collections.Generic;



public class RandomnameWomanfirstConfig 
{
	public string   name; // 名字 
	public int   id; // 下标 

}

public class RandomnameWomanfirstConfigTable 
{
    Dictionary<int, RandomnameWomanfirstConfig> m_configs = 
        new Dictionary<int, RandomnameWomanfirstConfig>();
    public Dictionary<int, RandomnameWomanfirstConfig> configs   
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
        RandomnameWomanfirstConfig rec = new RandomnameWomanfirstConfig();

		rec.id = Utility.ToInt(rh.Read());	 //下标
		rec.name = rh.Read();	 //名字

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Randomname_womanfirst.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            RandomnameWomanfirstConfig ac = ConfigProcess(row) as RandomnameWomanfirstConfig;
            configs.Add(ac.id, ac);
        }
    }
}
