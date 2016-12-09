
using System.Collections;
using System.Collections.Generic;



public class ConstantConstantConfig 
{
	public int   constantdata; // 数据 
	public int   constantid; // 配置id 

}

public class ConstantConstantConfigTable 
{
    Dictionary<int, ConstantConstantConfig> m_configs = 
        new Dictionary<int, ConstantConstantConfig>();
    public Dictionary<int, ConstantConstantConfig> configs   
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
        ConstantConstantConfig rec = new ConstantConstantConfig();

		rec.constantid = Utility.ToInt(rh.Read());	 //配置id
		rec.constantdata = Utility.ToInt(rh.Read());	 //数据

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Constant_constant.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            ConstantConstantConfig ac = ConfigProcess(row) as ConstantConstantConfig;
            configs.Add(ac.constantid, ac);
        }
    }
}
