
using System.Collections;
using System.Collections.Generic;



public class AvocationAvocationskillConfig 
{
	public int   level; // 等级 
	public string   openCreateList; // 开启制造列表 
	public int   id; // id 
	public int   classification; // 分类 
	public int   type; // 类型 
	public int   exp; // 经验值 
	public int   needMoney; // 消耗金币数量 

}

public class AvocationAvocationskillConfigTable 
{
    Dictionary<int, AvocationAvocationskillConfig> m_configs = 
        new Dictionary<int, AvocationAvocationskillConfig>();
    public Dictionary<int, AvocationAvocationskillConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 7)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        AvocationAvocationskillConfig rec = new AvocationAvocationskillConfig();

		rec.id = Utility.ToInt(rh.Read());	 //id
		rec.classification = Utility.ToInt(rh.Read());	 //分类
		rec.type = Utility.ToInt(rh.Read());	 //类型
		rec.level = Utility.ToInt(rh.Read());	 //等级
		rec.exp = Utility.ToInt(rh.Read());	 //经验值
		rec.needMoney = Utility.ToInt(rh.Read());	 //消耗金币数量
		rec.openCreateList = rh.Read();	 //开启制造列表

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Avocation_avocationskill.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            AvocationAvocationskillConfig ac = ConfigProcess(row) as AvocationAvocationskillConfig;
            configs.Add(ac.id, ac);
        }
    }
}
