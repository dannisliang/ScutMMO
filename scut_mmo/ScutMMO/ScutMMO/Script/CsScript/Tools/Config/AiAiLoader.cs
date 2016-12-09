
using System.Collections;
using System.Collections.Generic;


public class AiAiHpPeriodConfig
{
	public string   RemoveSkills; // 移除技能组 
	public int   Percentage; // 上限百分比 
	public string   AddSkills; // 添加技能组 
}




public class AiAiConfig 
{
	public AiAiHpPeriodConfig[]   hpPeriod; // HP阶段 
	public int   id; // AI方案ID 
	public string   initSkills; // 技能池初始技能组 

}

public class AiAiConfigTable 
{
    Dictionary<int, AiAiConfig> m_configs = 
        new Dictionary<int, AiAiConfig>();
    public Dictionary<int, AiAiConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 14)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        AiAiConfig rec = new AiAiConfig();

		rec.id = Utility.ToInt(rh.Read());	 //AI方案ID
		rec.initSkills = rh.Read();	 //技能池初始技能组
		rec.hpPeriod = new AiAiHpPeriodConfig[4]; 
		for (int i=0;i<4;i++) {
			rec.hpPeriod[i] = new AiAiHpPeriodConfig();
		}
		rec.hpPeriod[0].RemoveSkills = rh.Read();	 //移除技能组
		rec.hpPeriod[0].Percentage = Utility.ToInt(rh.Read());	 //上限百分比
		rec.hpPeriod[0].AddSkills = rh.Read();	 //添加技能组
		rec.hpPeriod[1].RemoveSkills = rh.Read();	 //移除技能组
		rec.hpPeriod[1].Percentage = Utility.ToInt(rh.Read());	 //上限百分比
		rec.hpPeriod[1].AddSkills = rh.Read();	 //添加技能组
		rec.hpPeriod[2].RemoveSkills = rh.Read();	 //移除技能组
		rec.hpPeriod[2].Percentage = Utility.ToInt(rh.Read());	 //上限百分比
		rec.hpPeriod[2].AddSkills = rh.Read();	 //添加技能组
		rec.hpPeriod[3].RemoveSkills = rh.Read();	 //移除技能组
		rec.hpPeriod[3].Percentage = Utility.ToInt(rh.Read());	 //上限百分比
		rec.hpPeriod[3].AddSkills = rh.Read();	 //添加技能组

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Ai_ai.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            AiAiConfig ac = ConfigProcess(row) as AiAiConfig;
            configs.Add(ac.id, ac);
        }
    }
}
