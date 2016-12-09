
using System.Collections;
using System.Collections.Generic;



public class RoleExpConfig 
{
	public int   lv; // 等级 
	public int   stamina; // 体力上限 
	public int   exp; // 当前等级升级需要经验 

}

public class RoleExpConfigTable 
{
    Dictionary<int, RoleExpConfig> m_configs = 
        new Dictionary<int, RoleExpConfig>();
    public Dictionary<int, RoleExpConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 3)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        RoleExpConfig rec = new RoleExpConfig();

		rec.lv = Utility.ToInt(rh.Read());	 //等级
		rec.exp = Utility.ToInt(rh.Read());	 //当前等级升级需要经验
		rec.stamina = Utility.ToInt(rh.Read());	 //体力上限

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Role_exp.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            RoleExpConfig ac = ConfigProcess(row) as RoleExpConfig;
            configs.Add(ac.lv, ac);
        }
    }
}
