
using System.Collections;
using System.Collections.Generic;



public class ItemItemConfig 
{
	public string   otherRequest; // 其他要求 
	public int   id; // 物品ID 
	public int   chantTime; // 读条时间 
	public string   functionValue; // 物品功能参数 
	public int   sexRequest; // 性别要求 
	public int   coolingTime; // 冷却时间 
	public int   isCanStack; // 可否堆叠 
	public string[]   source; // 物品来源 
	public int   coolingType; // 冷却类型 
	public int   coolingGroup; // 冷却组 
	public int   useEffectAim; // 作用目标类型 
	public int   itemType; // 物品类型 
	public int   isCanBatchUse; // 是否可批量使用 
	public int   isFightingUse; // 是否可在战斗中使用 
	public int   functionType; // 物品功能类型 
	public int   isUsedDestroy; // 使用后是否销毁 
	public int   aimRelation; // 目标关系 
	public int   levelRequest; // 等级要求 
	public int   isMarket; // 可否拍卖 
	public int   subType; // 物品细分类型 
	public int   raceRequest; // 种族要求 
	public int   isCanUse; // 是否可使用 
	public int   isCanSell; // 可否出售 
	public int   isDeathFall; // 是否死亡掉落 
	public int   itemLevel; // 物品等级 
	public int   isGetBind; // 是否获得绑定 
	public int   sellPrice; // 出售价格 
	public int   careerRequest; // 职业要求 
	public int   itemQuality; // 物品品质 

}

public class ItemItemConfigTable 
{
    Dictionary<int, ItemItemConfig> m_configs = 
        new Dictionary<int, ItemItemConfig>();
    public Dictionary<int, ItemItemConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 36)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        ItemItemConfig rec = new ItemItemConfig();

		rec.id = Utility.ToInt(rh.Read());	 //物品ID
		rec.itemType = Utility.ToInt(rh.Read());	 //物品类型
		rec.itemLevel = Utility.ToInt(rh.Read());	 //物品等级
		rec.itemQuality = Utility.ToInt(rh.Read());	 //物品品质
		rec.levelRequest = Utility.ToInt(rh.Read());	 //等级要求
		rec.raceRequest = Utility.ToInt(rh.Read());	 //种族要求
		rec.sexRequest = Utility.ToInt(rh.Read());	 //性别要求
		rec.careerRequest = Utility.ToInt(rh.Read());	 //职业要求
		rec.otherRequest = rh.Read();	 //其他要求
		rec.subType = Utility.ToInt(rh.Read());	 //物品细分类型
		rec.functionType = Utility.ToInt(rh.Read());	 //物品功能类型
		rec.functionValue = rh.Read();	 //物品功能参数
		rec.useEffectAim = Utility.ToInt(rh.Read());	 //作用目标类型
		rec.aimRelation = Utility.ToInt(rh.Read());	 //目标关系
		rec.chantTime = Utility.ToInt(rh.Read());	 //读条时间
		rec.isDeathFall = Utility.ToInt(rh.Read());	 //是否死亡掉落
		rec.isGetBind = Utility.ToInt(rh.Read());	 //是否获得绑定
		rec.isCanStack = Utility.ToInt(rh.Read());	 //可否堆叠
		rec.isCanSell = Utility.ToInt(rh.Read());	 //可否出售
		rec.sellPrice = Utility.ToInt(rh.Read());	 //出售价格
		rec.isMarket = Utility.ToInt(rh.Read());	 //可否拍卖
		rec.isCanUse = Utility.ToInt(rh.Read());	 //是否可使用
		rec.isFightingUse = Utility.ToInt(rh.Read());	 //是否可在战斗中使用
		rec.isUsedDestroy = Utility.ToInt(rh.Read());	 //使用后是否销毁
		rec.isCanBatchUse = Utility.ToInt(rh.Read());	 //是否可批量使用
		rec.coolingType = Utility.ToInt(rh.Read());	 //冷却类型
		rec.coolingGroup = Utility.ToInt(rh.Read());	 //冷却组
		rec.coolingTime = Utility.ToInt(rh.Read());	 //冷却时间
		rec.source = new string[8]; 
		rec.source[0] = rh.Read();	 //物品来源
		rec.source[1] = rh.Read();	 //物品来源
		rec.source[2] = rh.Read();	 //物品来源
		rec.source[3] = rh.Read();	 //物品来源
		rec.source[4] = rh.Read();	 //物品来源
		rec.source[5] = rh.Read();	 //物品来源
		rec.source[6] = rh.Read();	 //物品来源
		rec.source[7] = rh.Read();	 //物品来源

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Item_item.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            ItemItemConfig ac = ConfigProcess(row) as ItemItemConfig;
            configs.Add(ac.id, ac);
        }
    }
}
