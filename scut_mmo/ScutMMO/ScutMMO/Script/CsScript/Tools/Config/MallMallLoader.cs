
using System.Collections;
using System.Collections.Generic;



public class MallMallConfig 
{
	public int   openCoolTime; // 开放冷却时间 
	public int   id; // 商品ID 
	public int   discount; // 折扣 
	public int   isClose; // 是否下架 
	public int   goodsAmount; // 供货量 
	public int   buyAmount; // 可购买数量 
	public int   priority; // 优先级 
	public int   price; // 价格 
	public int   itemID; // 物品ID 
	public int   levelLimit; // 等级限制 
	public int   vipLimit; // VIP等级限制 
	public int   sellWaitingTime; // 销售等待时间 
	public int   refreshTime; // 刷新时间周期 
	public int   moneyType; // 货币类型 
	public int   mallType; // 商城分类 
	public int   openTime; // 开放时限 
	public int   goodsRefreshTime; // 供货刷新周期 

}

public class MallMallConfigTable 
{
    Dictionary<int, MallMallConfig> m_configs = 
        new Dictionary<int, MallMallConfig>();
    public Dictionary<int, MallMallConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 17)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        MallMallConfig rec = new MallMallConfig();

		rec.id = Utility.ToInt(rh.Read());	 //商品ID
		rec.itemID = Utility.ToInt(rh.Read());	 //物品ID
		rec.mallType = Utility.ToInt(rh.Read());	 //商城分类
		rec.priority = Utility.ToInt(rh.Read());	 //优先级
		rec.moneyType = Utility.ToInt(rh.Read());	 //货币类型
		rec.price = Utility.ToInt(rh.Read());	 //价格
		rec.discount = Utility.ToInt(rh.Read());	 //折扣
		rec.buyAmount = Utility.ToInt(rh.Read());	 //可购买数量
		rec.refreshTime = Utility.ToInt(rh.Read());	 //刷新时间周期
		rec.goodsAmount = Utility.ToInt(rh.Read());	 //供货量
		rec.goodsRefreshTime = Utility.ToInt(rh.Read());	 //供货刷新周期
		rec.vipLimit = Utility.ToInt(rh.Read());	 //VIP等级限制
		rec.levelLimit = Utility.ToInt(rh.Read());	 //等级限制
		rec.openTime = Utility.ToInt(rh.Read());	 //开放时限
		rec.openCoolTime = Utility.ToInt(rh.Read());	 //开放冷却时间
		rec.isClose = Utility.ToInt(rh.Read());	 //是否下架
		rec.sellWaitingTime = Utility.ToInt(rh.Read());	 //销售等待时间

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Mall_mall.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            MallMallConfig ac = ConfigProcess(row) as MallMallConfig;
            configs.Add(ac.id, ac);
        }
    }
}
