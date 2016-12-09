
using System.Collections;
using System.Collections.Generic;


public class SkillBuffEffectConfig
{
	public int   Type; // 类型 
	public string   Param; // 参数 
}




public class SkillBuffConfig 
{
	public int   stateBagID; // 附加状态包id 
	public string   stateBagName; // 状态包名称 
	public string   effectResources; // 特效路径 
	public int   startType; // 生效条件 
	public string   endType; // 常规结束条件 
	public string   stateBagIcon; // 状态包图标 
	public int   stateBagRule; // 同一状态包叠加规则 
	public int   mask; // 32位掩码 
	public SkillBuffEffectConfig[]   effect; // 效果 
	public int   delayTime; // 延迟生效时间 

}

public class SkillBuffConfigTable 
{
    Dictionary<int, SkillBuffConfig> m_configs = 
        new Dictionary<int, SkillBuffConfig>();
    public Dictionary<int, SkillBuffConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 19)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        SkillBuffConfig rec = new SkillBuffConfig();

		rec.stateBagID = Utility.ToInt(rh.Read());	 //附加状态包id
		rec.stateBagName = rh.Read();	 //状态包名称
		rec.stateBagIcon = rh.Read();	 //状态包图标
		rec.effectResources = rh.Read();	 //特效路径
		rec.startType = Utility.ToInt(rh.Read());	 //生效条件
		rec.delayTime = Utility.ToInt(rh.Read());	 //延迟生效时间
		rec.endType = rh.Read();	 //常规结束条件
		rec.stateBagRule = Utility.ToInt(rh.Read());	 //同一状态包叠加规则
		rec.mask = Utility.ToInt(rh.Read());	 //32位掩码
		rec.effect = new SkillBuffEffectConfig[5]; 
		for (int i=0;i<5;i++) {
			rec.effect[i] = new SkillBuffEffectConfig();
		}
		rec.effect[0].Type = Utility.ToInt(rh.Read());	 //类型
		rec.effect[0].Param = rh.Read();	 //参数
		rec.effect[1].Type = Utility.ToInt(rh.Read());	 //类型
		rec.effect[1].Param = rh.Read();	 //参数
		rec.effect[2].Type = Utility.ToInt(rh.Read());	 //类型
		rec.effect[2].Param = rh.Read();	 //参数
		rec.effect[3].Type = Utility.ToInt(rh.Read());	 //类型
		rec.effect[3].Param = rh.Read();	 //参数
		rec.effect[4].Type = Utility.ToInt(rh.Read());	 //类型
		rec.effect[4].Param = rh.Read();	 //参数

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Skill_buff.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            SkillBuffConfig ac = ConfigProcess(row) as SkillBuffConfig;
            configs.Add(ac.stateBagID, ac);
        }
    }
}
