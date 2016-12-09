
using System.Collections;
using System.Collections.Generic;



public class ThingThingConfig 
{
	public int   liveTime; // 生存时间 
	public int   usableTimes; // 可用次数 
	public int   id; // 物件ID 
	public int   chantTime; // 读条时间 
	public int   skill; // 关联技能 
	public string   res; // 物件资源 
	public int   drop; // 掉落 
	public int   trigRange; // 触发区域半径 
	public int   trigAimType; // 触发目标类型 
	public string   trigArea; // 触发区域 
	public int   type; // 物件类型 
	public int   isRefresh; // 死亡后可否刷新 
	public int   coolTime; // 冷却时间 
	public int   refreshTime; // 死亡刷新周期 

}

public class ThingThingConfigTable 
{
    Dictionary<int, ThingThingConfig> m_configs = 
        new Dictionary<int, ThingThingConfig>();
    public Dictionary<int, ThingThingConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 14)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        ThingThingConfig rec = new ThingThingConfig();

		rec.id = Utility.ToInt(rh.Read());	 //物件ID
		rec.type = Utility.ToInt(rh.Read());	 //物件类型
		rec.res = rh.Read();	 //物件资源
		rec.usableTimes = Utility.ToInt(rh.Read());	 //可用次数
		rec.isRefresh = Utility.ToInt(rh.Read());	 //死亡后可否刷新
		rec.refreshTime = Utility.ToInt(rh.Read());	 //死亡刷新周期
		rec.chantTime = Utility.ToInt(rh.Read());	 //读条时间
		rec.coolTime = Utility.ToInt(rh.Read());	 //冷却时间
		rec.liveTime = Utility.ToInt(rh.Read());	 //生存时间
		rec.trigAimType = Utility.ToInt(rh.Read());	 //触发目标类型
		rec.trigRange = Utility.ToInt(rh.Read());	 //触发区域半径
		rec.trigArea = rh.Read();	 //触发区域
		rec.drop = Utility.ToInt(rh.Read());	 //掉落
		rec.skill = Utility.ToInt(rh.Read());	 //关联技能

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Thing_thing.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            ThingThingConfig ac = ConfigProcess(row) as ThingThingConfig;
            configs.Add(ac.id, ac);
        }
    }
}
