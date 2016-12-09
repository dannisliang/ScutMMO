
using System.Collections;
using System.Collections.Generic;



public class AreaPathConfig 
{
	public int   belongToSceneID; // 所属场景 
	public int   id; // 路径ID 

}

public class AreaPathConfigTable 
{
    Dictionary<int, AreaPathConfig> m_configs = 
        new Dictionary<int, AreaPathConfig>();
    public Dictionary<int, AreaPathConfig> configs   
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
        AreaPathConfig rec = new AreaPathConfig();

		rec.id = Utility.ToInt(rh.Read());	 //路径ID
		rec.belongToSceneID = Utility.ToInt(rh.Read());	 //所属场景

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Area_path.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            AreaPathConfig ac = ConfigProcess(row) as AreaPathConfig;
            configs.Add(ac.id, ac);
        }
    }
}
