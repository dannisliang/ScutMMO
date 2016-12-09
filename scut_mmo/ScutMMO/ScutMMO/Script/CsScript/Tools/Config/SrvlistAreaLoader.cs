
using System.Collections;
using System.Collections.Generic;



public class SrvlistAreaConfig 
{
	public string   name; // 区名 
	public int   id; // 标识 

}

public class SrvlistAreaConfigTable 
{
    Dictionary<int, SrvlistAreaConfig> m_configs = 
        new Dictionary<int, SrvlistAreaConfig>();
    public Dictionary<int, SrvlistAreaConfig> configs   
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
        SrvlistAreaConfig rec = new SrvlistAreaConfig();

		rec.id = Utility.ToInt(rh.Read());	 //标识
		rec.name = rh.Read();	 //区名

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Srvlist_area.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            SrvlistAreaConfig ac = ConfigProcess(row) as SrvlistAreaConfig;
            configs.Add(ac.id, ac);
        }
    }
}
