
using System.Collections;
using System.Collections.Generic;



public class RandomnameManfirstConfig 
{
	public string   name; // 名字 
	public int   id; // 下标 

}

public class RandomnameManfirstConfigTable 
{
    Dictionary<int, RandomnameManfirstConfig> m_configs = 
        new Dictionary<int, RandomnameManfirstConfig>();
    public Dictionary<int, RandomnameManfirstConfig> configs   
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
        RandomnameManfirstConfig rec = new RandomnameManfirstConfig();

		rec.id = Utility.ToInt(rh.Read());	 //下标
		rec.name = rh.Read();	 //名字

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Randomname_manfirst.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            RandomnameManfirstConfig ac = ConfigProcess(row) as RandomnameManfirstConfig;
            configs.Add(ac.id, ac);
        }
    }
}
