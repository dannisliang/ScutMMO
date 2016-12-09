
using System.Collections;
using System.Collections.Generic;


public class DropDropItemConfig
{
	public int   maxNum; // 最大数量 
	public int   id; // id 
	public int   rand; // 概率 
}




public class DropDropConfig 
{
	public int   goldup; // 总金币数量上限 
	public int   goldlow; // 总金币数量下限 
	public int   id; // 掉落包ID 
	public DropDropItemConfig[]   item; // 掉落物品 
	public int   gold_heap; // 金币掉落堆数 
	public int   gold_rand; // 金币掉落概率 

}

public class DropDropConfigTable 
{
    Dictionary<int, DropDropConfig> m_configs = 
        new Dictionary<int, DropDropConfig>();
    public Dictionary<int, DropDropConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 113)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        DropDropConfig rec = new DropDropConfig();

		rec.id = Utility.ToInt(rh.Read());	 //掉落包ID
		rec.goldlow = Utility.ToInt(rh.Read());	 //总金币数量下限
		rec.goldup = Utility.ToInt(rh.Read());	 //总金币数量上限
		rec.gold_heap = Utility.ToInt(rh.Read());	 //金币掉落堆数
		rec.gold_rand = Utility.ToInt(rh.Read());	 //金币掉落概率
		rec.item = new DropDropItemConfig[36]; 
		for (int i=0;i<36;i++) {
			rec.item[i] = new DropDropItemConfig();
		}
		rec.item[0].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[0].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[0].id = Utility.ToInt(rh.Read());	 //id
		rec.item[1].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[1].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[1].id = Utility.ToInt(rh.Read());	 //id
		rec.item[2].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[2].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[2].id = Utility.ToInt(rh.Read());	 //id
		rec.item[3].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[3].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[3].id = Utility.ToInt(rh.Read());	 //id
		rec.item[4].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[4].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[4].id = Utility.ToInt(rh.Read());	 //id
		rec.item[5].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[5].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[5].id = Utility.ToInt(rh.Read());	 //id
		rec.item[6].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[6].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[6].id = Utility.ToInt(rh.Read());	 //id
		rec.item[7].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[7].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[7].id = Utility.ToInt(rh.Read());	 //id
		rec.item[8].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[8].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[8].id = Utility.ToInt(rh.Read());	 //id
		rec.item[9].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[9].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[9].id = Utility.ToInt(rh.Read());	 //id
		rec.item[10].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[10].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[10].id = Utility.ToInt(rh.Read());	 //id
		rec.item[11].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[11].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[11].id = Utility.ToInt(rh.Read());	 //id
		rec.item[12].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[12].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[12].id = Utility.ToInt(rh.Read());	 //id
		rec.item[13].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[13].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[13].id = Utility.ToInt(rh.Read());	 //id
		rec.item[14].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[14].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[14].id = Utility.ToInt(rh.Read());	 //id
		rec.item[15].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[15].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[15].id = Utility.ToInt(rh.Read());	 //id
		rec.item[16].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[16].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[16].id = Utility.ToInt(rh.Read());	 //id
		rec.item[17].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[17].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[17].id = Utility.ToInt(rh.Read());	 //id
		rec.item[18].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[18].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[18].id = Utility.ToInt(rh.Read());	 //id
		rec.item[19].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[19].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[19].id = Utility.ToInt(rh.Read());	 //id
		rec.item[20].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[20].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[20].id = Utility.ToInt(rh.Read());	 //id
		rec.item[21].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[21].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[21].id = Utility.ToInt(rh.Read());	 //id
		rec.item[22].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[22].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[22].id = Utility.ToInt(rh.Read());	 //id
		rec.item[23].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[23].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[23].id = Utility.ToInt(rh.Read());	 //id
		rec.item[24].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[24].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[24].id = Utility.ToInt(rh.Read());	 //id
		rec.item[25].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[25].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[25].id = Utility.ToInt(rh.Read());	 //id
		rec.item[26].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[26].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[26].id = Utility.ToInt(rh.Read());	 //id
		rec.item[27].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[27].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[27].id = Utility.ToInt(rh.Read());	 //id
		rec.item[28].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[28].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[28].id = Utility.ToInt(rh.Read());	 //id
		rec.item[29].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[29].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[29].id = Utility.ToInt(rh.Read());	 //id
		rec.item[30].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[30].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[30].id = Utility.ToInt(rh.Read());	 //id
		rec.item[31].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[31].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[31].id = Utility.ToInt(rh.Read());	 //id
		rec.item[32].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[32].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[32].id = Utility.ToInt(rh.Read());	 //id
		rec.item[33].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[33].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[33].id = Utility.ToInt(rh.Read());	 //id
		rec.item[34].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[34].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[34].id = Utility.ToInt(rh.Read());	 //id
		rec.item[35].maxNum = Utility.ToInt(rh.Read());	 //最大数量
		rec.item[35].rand = Utility.ToInt(rh.Read());	 //概率
		rec.item[35].id = Utility.ToInt(rh.Read());	 //id

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Drop_drop.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            DropDropConfig ac = ConfigProcess(row) as DropDropConfig;
            configs.Add(ac.id, ac);
        }
    }
}
