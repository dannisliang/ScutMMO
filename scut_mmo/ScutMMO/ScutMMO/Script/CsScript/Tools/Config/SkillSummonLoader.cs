
using System.Collections;
using System.Collections.Generic;


public class SkillSummonSummonConfig
{
	public string   Skill; // 技能 
	public string   SkillLevel; // 技能等级 
}



public class SkillSummonAttributeConfig
{
	public string   Type; // 类型 
	public string   Value; // 值 
}




public class SkillSummonConfig 
{
	public SkillSummonAttributeConfig[]   attribute; // 属性 
	public int   viewType; // 视野类型 
	public int   summonType; // 召唤物类型 
	public string   summonTime; // 召唤物存在时间 
	public string   summonLevel; // 召唤物等级 
	public int   summonID; // 召唤物ID 
	public string   StopRange; // 阻挡范围 
	public SkillSummonSummonConfig[]   summon; // 携带 
	public string   view; // 视野 
	public int   summonAI; // 召唤物AI 
	public int   pursueRange; // 追击范围 

}

public class SkillSummonConfigTable 
{
    Dictionary<int, SkillSummonConfig> m_configs = 
        new Dictionary<int, SkillSummonConfig>();
    public Dictionary<int, SkillSummonConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 47)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        SkillSummonConfig rec = new SkillSummonConfig();

		rec.summonID = Utility.ToInt(rh.Read());	 //召唤物ID
		rec.summonType = Utility.ToInt(rh.Read());	 //召唤物类型
		rec.summonLevel = rh.Read();	 //召唤物等级
		rec.summonTime = rh.Read();	 //召唤物存在时间
		rec.summonAI = Utility.ToInt(rh.Read());	 //召唤物AI
		rec.viewType = Utility.ToInt(rh.Read());	 //视野类型
		rec.view = rh.Read();	 //视野
		rec.pursueRange = Utility.ToInt(rh.Read());	 //追击范围
		rec.StopRange = rh.Read();	 //阻挡范围
		rec.summon = new SkillSummonSummonConfig[4]; 
		for (int i=0;i<4;i++) {
			rec.summon[i] = new SkillSummonSummonConfig();
		}
		rec.summon[0].Skill = rh.Read();	 //技能
		rec.summon[0].SkillLevel = rh.Read();	 //技能等级
		rec.summon[1].Skill = rh.Read();	 //技能
		rec.summon[1].SkillLevel = rh.Read();	 //技能等级
		rec.summon[2].Skill = rh.Read();	 //技能
		rec.summon[2].SkillLevel = rh.Read();	 //技能等级
		rec.summon[3].Skill = rh.Read();	 //技能
		rec.summon[3].SkillLevel = rh.Read();	 //技能等级
		rec.attribute = new SkillSummonAttributeConfig[15]; 
		for (int i=0;i<15;i++) {
			rec.attribute[i] = new SkillSummonAttributeConfig();
		}
		rec.attribute[0].Type = rh.Read();	 //类型
		rec.attribute[0].Value = rh.Read();	 //值
		rec.attribute[1].Type = rh.Read();	 //类型
		rec.attribute[1].Value = rh.Read();	 //值
		rec.attribute[2].Type = rh.Read();	 //类型
		rec.attribute[2].Value = rh.Read();	 //值
		rec.attribute[3].Type = rh.Read();	 //类型
		rec.attribute[3].Value = rh.Read();	 //值
		rec.attribute[4].Type = rh.Read();	 //类型
		rec.attribute[4].Value = rh.Read();	 //值
		rec.attribute[5].Type = rh.Read();	 //类型
		rec.attribute[5].Value = rh.Read();	 //值
		rec.attribute[6].Type = rh.Read();	 //类型
		rec.attribute[6].Value = rh.Read();	 //值
		rec.attribute[7].Type = rh.Read();	 //类型
		rec.attribute[7].Value = rh.Read();	 //值
		rec.attribute[8].Type = rh.Read();	 //类型
		rec.attribute[8].Value = rh.Read();	 //值
		rec.attribute[9].Type = rh.Read();	 //类型
		rec.attribute[9].Value = rh.Read();	 //值
		rec.attribute[10].Type = rh.Read();	 //类型
		rec.attribute[10].Value = rh.Read();	 //值
		rec.attribute[11].Type = rh.Read();	 //类型
		rec.attribute[11].Value = rh.Read();	 //值
		rec.attribute[12].Type = rh.Read();	 //类型
		rec.attribute[12].Value = rh.Read();	 //值
		rec.attribute[13].Type = rh.Read();	 //类型
		rec.attribute[13].Value = rh.Read();	 //值
		rec.attribute[14].Type = rh.Read();	 //类型
		rec.attribute[14].Value = rh.Read();	 //值

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Skill_summon.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            SkillSummonConfig ac = ConfigProcess(row) as SkillSummonConfig;
            configs.Add(ac.summonID, ac);
        }
    }
}
