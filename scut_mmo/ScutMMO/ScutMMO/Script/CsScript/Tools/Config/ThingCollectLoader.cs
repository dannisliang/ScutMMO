
using System.Collections;
using System.Collections.Generic;


public class ThingCollectGainConfig
{
	public int   ItemId; // 道具 
	public int   rate; // 概率 
}




public class ThingCollectConfig 
{
	public int   gainValue; // 获得熟练度 
	public int   id; // 资源ID 
	public int   mapId; // 地图Id 
	public int   needLevel; // 需要副业等级 
	public ThingCollectGainConfig[]   gain; // 获得 
	public int   type; // 类型 
	public int   quelity; // 品质 
	public int   makeCount; // 生成数量 
	public int   needEnergy; // 消耗活力 
	public int   refreshTime; // 刷新时间 

}

public class ThingCollectConfigTable 
{
    Dictionary<int, ThingCollectConfig> m_configs = 
        new Dictionary<int, ThingCollectConfig>();
    public Dictionary<int, ThingCollectConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 13)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        ThingCollectConfig rec = new ThingCollectConfig();

		rec.id = Utility.ToInt(rh.Read());	 //资源ID
		rec.type = Utility.ToInt(rh.Read());	 //类型
		rec.quelity = Utility.ToInt(rh.Read());	 //品质
		rec.mapId = Utility.ToInt(rh.Read());	 //地图Id
		rec.makeCount = Utility.ToInt(rh.Read());	 //生成数量
		rec.refreshTime = Utility.ToInt(rh.Read());	 //刷新时间
		rec.needLevel = Utility.ToInt(rh.Read());	 //需要副业等级
		rec.needEnergy = Utility.ToInt(rh.Read());	 //消耗活力
		rec.gainValue = Utility.ToInt(rh.Read());	 //获得熟练度
		rec.gain = new ThingCollectGainConfig[2]; 
		for (int i=0;i<2;i++) {
			rec.gain[i] = new ThingCollectGainConfig();
		}
		rec.gain[0].rate = Utility.ToInt(rh.Read());	 //概率
		rec.gain[0].ItemId = Utility.ToInt(rh.Read());	 //道具
		rec.gain[1].rate = Utility.ToInt(rh.Read());	 //概率
		rec.gain[1].ItemId = Utility.ToInt(rh.Read());	 //道具

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Thing_collect.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            ThingCollectConfig ac = ConfigProcess(row) as ThingCollectConfig;
            configs.Add(ac.id, ac);
        }
    }
}
