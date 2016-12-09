
using System.Collections;
using System.Collections.Generic;



public class MapMapConfig 
{
	public int   canSupply; // 是否可喝药 
	public int   mapPk; // PK规则 
	public int   mapHeight; // 地图高度 
	public string   monsterRoad; // 怪物寻路点层 
	public int   isDirectRevive; // 是否允许原地复活 
	public int   resMonster; // 怪物资源层 
	public int   mapId; // 地图id 
	public string   mapResources; // 地图资源 
	public int   useShoes; // 是否可使用飞鞋传送 
	public int   mapType; // 地图类型 
	public int   deadPunish; // 是否有死亡掉落装备物品 
	public int   openRace; // 地图进入种族限制 
	public int   openLv; // 地图进入等级 
	public int   mapSubType; // 地图子类型 
	public int   mapWide; // 地图宽度 
	public int   openVip; // 地图进入需VIP等级 

}

public class MapMapConfigTable 
{
    Dictionary<int, MapMapConfig> m_configs = 
        new Dictionary<int, MapMapConfig>();
    public Dictionary<int, MapMapConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 16)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        MapMapConfig rec = new MapMapConfig();

		rec.mapId = Utility.ToInt(rh.Read());	 //地图id
		rec.mapWide = Utility.ToInt(rh.Read());	 //地图宽度
		rec.mapHeight = Utility.ToInt(rh.Read());	 //地图高度
		rec.mapType = Utility.ToInt(rh.Read());	 //地图类型
		rec.mapSubType = Utility.ToInt(rh.Read());	 //地图子类型
		rec.openLv = Utility.ToInt(rh.Read());	 //地图进入等级
		rec.openVip = Utility.ToInt(rh.Read());	 //地图进入需VIP等级
		rec.openRace = Utility.ToInt(rh.Read());	 //地图进入种族限制
		rec.mapPk = Utility.ToInt(rh.Read());	 //PK规则
		rec.deadPunish = Utility.ToInt(rh.Read());	 //是否有死亡掉落装备物品
		rec.useShoes = Utility.ToInt(rh.Read());	 //是否可使用飞鞋传送
		rec.canSupply = Utility.ToInt(rh.Read());	 //是否可喝药
		rec.isDirectRevive = Utility.ToInt(rh.Read());	 //是否允许原地复活
		rec.mapResources = rh.Read();	 //地图资源
		rec.resMonster = Utility.ToInt(rh.Read());	 //怪物资源层
		rec.monsterRoad = rh.Read();	 //怪物寻路点层

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Map_map.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            MapMapConfig ac = ConfigProcess(row) as MapMapConfig;
            configs.Add(ac.mapId, ac);
        }
    }
}
