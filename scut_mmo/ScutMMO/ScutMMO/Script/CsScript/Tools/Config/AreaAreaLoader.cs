
using System.Collections;
using System.Collections.Generic;



public class AreaAreaConfig 
{
	public int   shapeType; // 形状类型 
	public int   belongToSceneID; // 所属场景 
	public string   name; // 区域名称 
	public int   id; // 区域ID 

}

public class AreaAreaConfigTable 
{
    Dictionary<int, AreaAreaConfig> m_configs = 
        new Dictionary<int, AreaAreaConfig>();
    public Dictionary<int, AreaAreaConfig> configs   
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
        AreaAreaConfig rec = new AreaAreaConfig();

		rec.id = Utility.ToInt(rh.Read());	 //区域ID
		rec.name = rh.Read();	 //区域名称
		rec.shapeType = Utility.ToInt(rh.Read());	 //形状类型
		rec.belongToSceneID = Utility.ToInt(rh.Read());	 //所属场景

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Area_area.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            AreaAreaConfig ac = ConfigProcess(row) as AreaAreaConfig;
            configs.Add(ac.id, ac);
        }
    }
}
