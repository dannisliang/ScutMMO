
using System.Collections;
using System.Collections.Generic;



public class DuplicateGroupConfig 
{
	public int   belongToType; // 所属类型 
	public int   id; // 副本组ID 
	public int   unlockLevel; // 解锁等级 
	public int   buyMaxTimes; // 最大购买次数 
	public int   groupTimesType; // 组次数类型 
	public string   timesRes; // 次数ICON资源 
	public int   refreshType; // 次数上限刷新类型 
	public int   groupType; // 组内容类型 
	public string   buyPrice; // 购买价格序列 
	public int   groupTimes; // 次数上限值 
	public string   openTime; // 开放时间 
	public string   refreshTime; // 限制刷新时间 

}

public class DuplicateGroupConfigTable 
{
    Dictionary<int, DuplicateGroupConfig> m_configs = 
        new Dictionary<int, DuplicateGroupConfig>();
    public Dictionary<int, DuplicateGroupConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 12)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        DuplicateGroupConfig rec = new DuplicateGroupConfig();

		rec.id = Utility.ToInt(rh.Read());	 //副本组ID
		rec.unlockLevel = Utility.ToInt(rh.Read());	 //解锁等级
		rec.belongToType = Utility.ToInt(rh.Read());	 //所属类型
		rec.openTime = rh.Read();	 //开放时间
		rec.groupType = Utility.ToInt(rh.Read());	 //组内容类型
		rec.timesRes = rh.Read();	 //次数ICON资源
		rec.groupTimesType = Utility.ToInt(rh.Read());	 //组次数类型
		rec.groupTimes = Utility.ToInt(rh.Read());	 //次数上限值
		rec.refreshType = Utility.ToInt(rh.Read());	 //次数上限刷新类型
		rec.refreshTime = rh.Read();	 //限制刷新时间
		rec.buyPrice = rh.Read();	 //购买价格序列
		rec.buyMaxTimes = Utility.ToInt(rh.Read());	 //最大购买次数

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Duplicate_group.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            DuplicateGroupConfig ac = ConfigProcess(row) as DuplicateGroupConfig;
            configs.Add(ac.id, ac);
        }
    }
}
