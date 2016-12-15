
using System.Collections;
using System.Collections.Generic;


public class AvocationComposeNewItemConfig
{
	public int   Id; // ID 
	public int   Rate; // 几率 
}



public class AvocationComposeNeedMaterialConfig
{
	public int   Num; // 数量 
	public int   Id; // id 
}



public class AvocationComposeConsumeReelConfig
{
	public int   Id; // ID 
}




public class AvocationComposeConfig 
{
	public AvocationComposeNewItemConfig[]   newItem; // 合成物 
	public int   id; // 制造id 
	public int   consumeRandomReel_Id; // 随机卷轴ID 
	public AvocationComposeNeedMaterialConfig[]   needMaterial; // 需要材料 
	public int   creatList; // 所在制造列表 
	public int   type; // 类型 
	public AvocationComposeConsumeReelConfig[]   consumeReel; // 卷轴 
	public int   sonType; // 子类型 
	public int   jobList; // 职业列表 
	public int   isName; // 是否铭刻 
	public int   linkId; // 关联id 
	public int   needMoney; // 需要金币 

}

public class AvocationComposeConfigTable 
{
    Dictionary<int, AvocationComposeConfig> m_configs = 
        new Dictionary<int, AvocationComposeConfig>();
    public Dictionary<int, AvocationComposeConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 35)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        AvocationComposeConfig rec = new AvocationComposeConfig();

		rec.id = Utility.ToInt(rh.Read());	 //制造id
		rec.linkId = Utility.ToInt(rh.Read());	 //关联id
		rec.type = Utility.ToInt(rh.Read());	 //类型
		rec.sonType = Utility.ToInt(rh.Read());	 //子类型
		rec.creatList = Utility.ToInt(rh.Read());	 //所在制造列表
		rec.jobList = Utility.ToInt(rh.Read());	 //职业列表
		rec.isName = Utility.ToInt(rh.Read());	 //是否铭刻
		rec.needMoney = Utility.ToInt(rh.Read());	 //需要金币
		rec.consumeRandomReel_Id = Utility.ToInt(rh.Read());	 //随机卷轴ID
		rec.newItem = new AvocationComposeNewItemConfig[6]; 
		for (int i=0;i<6;i++) {
			rec.newItem[i] = new AvocationComposeNewItemConfig();
		}
		rec.newItem[0].Rate = Utility.ToInt(rh.Read());	 //几率
		rec.newItem[0].Id = Utility.ToInt(rh.Read());	 //ID
		rec.newItem[1].Rate = Utility.ToInt(rh.Read());	 //几率
		rec.newItem[1].Id = Utility.ToInt(rh.Read());	 //ID
		rec.newItem[2].Rate = Utility.ToInt(rh.Read());	 //几率
		rec.newItem[2].Id = Utility.ToInt(rh.Read());	 //ID
		rec.newItem[3].Rate = Utility.ToInt(rh.Read());	 //几率
		rec.newItem[3].Id = Utility.ToInt(rh.Read());	 //ID
		rec.newItem[4].Rate = Utility.ToInt(rh.Read());	 //几率
		rec.newItem[4].Id = Utility.ToInt(rh.Read());	 //ID
		rec.newItem[5].Rate = Utility.ToInt(rh.Read());	 //几率
		rec.newItem[5].Id = Utility.ToInt(rh.Read());	 //ID
		rec.needMaterial = new AvocationComposeNeedMaterialConfig[4]; 
		for (int i=0;i<4;i++) {
			rec.needMaterial[i] = new AvocationComposeNeedMaterialConfig();
		}
		rec.needMaterial[0].Num = Utility.ToInt(rh.Read());	 //数量
		rec.needMaterial[0].Id = Utility.ToInt(rh.Read());	 //id
		rec.needMaterial[1].Num = Utility.ToInt(rh.Read());	 //数量
		rec.needMaterial[1].Id = Utility.ToInt(rh.Read());	 //id
		rec.needMaterial[2].Num = Utility.ToInt(rh.Read());	 //数量
		rec.needMaterial[2].Id = Utility.ToInt(rh.Read());	 //id
		rec.needMaterial[3].Num = Utility.ToInt(rh.Read());	 //数量
		rec.needMaterial[3].Id = Utility.ToInt(rh.Read());	 //id
		rec.consumeReel = new AvocationComposeConsumeReelConfig[6]; 
		for (int i=0;i<6;i++) {
			rec.consumeReel[i] = new AvocationComposeConsumeReelConfig();
		}
		rec.consumeReel[0].Id = Utility.ToInt(rh.Read());	 //ID
		rec.consumeReel[1].Id = Utility.ToInt(rh.Read());	 //ID
		rec.consumeReel[2].Id = Utility.ToInt(rh.Read());	 //ID
		rec.consumeReel[3].Id = Utility.ToInt(rh.Read());	 //ID
		rec.consumeReel[4].Id = Utility.ToInt(rh.Read());	 //ID
		rec.consumeReel[5].Id = Utility.ToInt(rh.Read());	 //ID

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Avocation_compose.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            AvocationComposeConfig ac = ConfigProcess(row) as AvocationComposeConfig;
            configs.Add(ac.id, ac);
        }
    }
}
