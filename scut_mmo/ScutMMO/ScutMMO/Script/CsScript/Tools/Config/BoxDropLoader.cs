
using System.Collections;
using System.Collections.Generic;


public class BoxDropItemConfig
{
	public int   maxNum; // 最大数量 
	public int   minNum; // 最小数量 
	public int   id; // id 
	public int   rand; // 概率 
}




public class BoxDropConfig 
{
	public int   drop_type; // 掉落类型 
	public BoxDropItemConfig[]   item; // 掉落物品 
	public int   id; // 掉落包ID 

}

public class BoxDropConfigTable 
{
    Dictionary<int, BoxDropConfig> m_configs = 
        new Dictionary<int, BoxDropConfig>();
    public Dictionary<int, BoxDropConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 82)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        BoxDropConfig rec = new BoxDropConfig();

		rec.id = Utility.ToInt(rh.Read());	 //掉落包ID
		rec.drop_type = Utility.ToInt(rh.Read());	 //掉落类型
		rec.item = new BoxDropItemConfig[20]; 
		for (int i=0;i<20;i++) {
			rec.item[i] = new BoxDropItemConfig();
		}
		rec.item[0].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[0].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[0].id = Utility.ToInt(rh.Read());	 //id
		rec.item[0].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[1].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[1].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[1].id = Utility.ToInt(rh.Read());	 //id
		rec.item[1].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[2].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[2].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[2].id = Utility.ToInt(rh.Read());	 //id
		rec.item[2].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[3].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[3].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[3].id = Utility.ToInt(rh.Read());	 //id
		rec.item[3].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[4].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[4].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[4].id = Utility.ToInt(rh.Read());	 //id
		rec.item[4].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[5].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[5].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[5].id = Utility.ToInt(rh.Read());	 //id
		rec.item[5].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[6].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[6].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[6].id = Utility.ToInt(rh.Read());	 //id
		rec.item[6].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[7].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[7].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[7].id = Utility.ToInt(rh.Read());	 //id
		rec.item[7].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[8].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[8].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[8].id = Utility.ToInt(rh.Read());	 //id
		rec.item[8].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[9].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[9].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[9].id = Utility.ToInt(rh.Read());	 //id
		rec.item[9].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[10].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[10].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[10].id = Utility.ToInt(rh.Read());	 //id
		rec.item[10].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[11].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[11].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[11].id = Utility.ToInt(rh.Read());	 //id
		rec.item[11].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[12].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[12].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[12].id = Utility.ToInt(rh.Read());	 //id
		rec.item[12].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[13].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[13].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[13].id = Utility.ToInt(rh.Read());	 //id
		rec.item[13].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[14].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[14].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[14].id = Utility.ToInt(rh.Read());	 //id
		rec.item[14].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[15].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[15].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[15].id = Utility.ToInt(rh.Read());	 //id
		rec.item[15].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[16].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[16].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[16].id = Utility.ToInt(rh.Read());	 //id
		rec.item[16].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[17].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[17].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[17].id = Utility.ToInt(rh.Read());	 //id
		rec.item[17].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[18].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[18].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[18].id = Utility.ToInt(rh.Read());	 //id
		rec.item[18].minNum = Utility.ToInt(rh.Read());	 //最小数量
		rec.item[19].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[19].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[19].id = Utility.ToInt(rh.Read());	 //id
		rec.item[19].minNum = Utility.ToInt(rh.Read());	 //最小数量

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Box_drop.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            BoxDropConfig ac = ConfigProcess(row) as BoxDropConfig;
            configs.Add(ac.id, ac);
        }
    }
}
