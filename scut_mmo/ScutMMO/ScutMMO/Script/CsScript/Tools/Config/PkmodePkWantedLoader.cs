
using System.Collections;
using System.Collections.Generic;



public class PkmodePkWantedConfig 
{
	public int   pkRewardNum; // 悬赏令数量 
	public int   bodyEquipMax; // 此玩家死亡后身上装备掉落最大数量 
	public int   minPKNum; // 最小PK值 
	public int   bodyEquipMin; // 此玩家死亡后身上装备掉落最小数量 
	public int   killPkAdd; // 杀死此玩家时获得PK值 
	public int   bagPropMin; // 此玩家死亡后背包物品掉落最少数量 
	public int   bagPropLose; // 此玩家死亡后背包物品掉落几率 
	public int   pkRewardId; // 悬赏令ID 
	public int   bodyEquipLose; // 此玩家死亡后身上装备掉落几率 
	public int   wanteLeveldId; // 通缉等级ID 
	public int   bagPropMax; // 此玩家死亡后背包物品掉落最大数量 
	public int   maxPKNum; // 最大PK值 

}

public class PkmodePkWantedConfigTable 
{
    Dictionary<int, PkmodePkWantedConfig> m_configs = 
        new Dictionary<int, PkmodePkWantedConfig>();
    public Dictionary<int, PkmodePkWantedConfig> configs   
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
        PkmodePkWantedConfig rec = new PkmodePkWantedConfig();

		rec.wanteLeveldId = Utility.ToInt(rh.Read());	 //通缉等级ID
		rec.minPKNum = Utility.ToInt(rh.Read());	 //最小PK值
		rec.maxPKNum = Utility.ToInt(rh.Read());	 //最大PK值
		rec.killPkAdd = Utility.ToInt(rh.Read());	 //杀死此玩家时获得PK值
		rec.bodyEquipLose = Utility.ToInt(rh.Read());	 //此玩家死亡后身上装备掉落几率
		rec.bodyEquipMin = Utility.ToInt(rh.Read());	 //此玩家死亡后身上装备掉落最小数量
		rec.bodyEquipMax = Utility.ToInt(rh.Read());	 //此玩家死亡后身上装备掉落最大数量
		rec.bagPropLose = Utility.ToInt(rh.Read());	 //此玩家死亡后背包物品掉落几率
		rec.bagPropMin = Utility.ToInt(rh.Read());	 //此玩家死亡后背包物品掉落最少数量
		rec.bagPropMax = Utility.ToInt(rh.Read());	 //此玩家死亡后背包物品掉落最大数量
		rec.pkRewardId = Utility.ToInt(rh.Read());	 //悬赏令ID
		rec.pkRewardNum = Utility.ToInt(rh.Read());	 //悬赏令数量

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Pkmode_pkWanted.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            PkmodePkWantedConfig ac = ConfigProcess(row) as PkmodePkWantedConfig;
            configs.Add(ac.wanteLeveldId, ac);
        }
    }
}
