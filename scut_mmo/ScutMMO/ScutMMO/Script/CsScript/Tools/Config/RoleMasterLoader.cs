
using System.Collections;
using System.Collections.Generic;


public class RoleMasterAttributeConfig
{
	public int   Type; // 类型 
	public int   Value; // 值 
}




public class RoleMasterConfig 
{
	public RoleMasterAttributeConfig[]   attribute; // 属性 
	public int   lv; // 玩家等级 
	public int   upgradePoint; // 升级获得点数 

}

public class RoleMasterConfigTable 
{
    Dictionary<int, RoleMasterConfig> m_configs = 
        new Dictionary<int, RoleMasterConfig>();
    public Dictionary<int, RoleMasterConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 46)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        RoleMasterConfig rec = new RoleMasterConfig();

		rec.lv = Utility.ToInt(rh.Read());	 //玩家等级
		rec.upgradePoint = Utility.ToInt(rh.Read());	 //升级获得点数
		rec.attribute = new RoleMasterAttributeConfig[22]; 
		for (int i=0;i<22;i++) {
			rec.attribute[i] = new RoleMasterAttributeConfig();
		}
		rec.attribute[0].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[0].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[1].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[1].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[2].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[2].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[3].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[3].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[4].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[4].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[5].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[5].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[6].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[6].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[7].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[7].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[8].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[8].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[9].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[9].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[10].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[10].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[11].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[11].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[12].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[12].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[13].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[13].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[14].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[14].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[15].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[15].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[16].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[16].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[17].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[17].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[18].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[18].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[19].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[19].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[20].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[20].Value = Utility.ToInt(rh.Read());	 //值
		rec.attribute[21].Type = Utility.ToInt(rh.Read());	 //类型
		rec.attribute[21].Value = Utility.ToInt(rh.Read());	 //值

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Role_master.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            RoleMasterConfig ac = ConfigProcess(row) as RoleMasterConfig;
            configs.Add(ac.lv, ac);
        }
    }
}
