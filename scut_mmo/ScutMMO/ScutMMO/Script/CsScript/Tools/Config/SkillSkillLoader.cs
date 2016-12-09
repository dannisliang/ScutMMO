
using System.Collections;
using System.Collections.Generic;


public class SkillSkillStateBagConfig
{
	public int   Target; // 归属 
	public string   Parameter; // 参数 
	public int   ID; // id 
	public string   Time; // 持续时间 
	public int   Point; // 生效点 
	public int   Rate; // 成功几率 
}




public class SkillSkillConfig 
{
	public string   displaceTime; // 位移生效时间点 
	public int   skillID; // 技能id 
	public string   attackValue; // 附加攻击力固定值 
	public int   flySpeed; // 飞行速度 
	public int   Relation; // 关联技能 
	public int   breakType; // 被打断类型 
	public string   rangeTypeValue; // 范围类型值 
	public int   cost; // 消耗类型 
	public int   attackMinDistance; // 攻击最小距离 
	public string   minLevel; // 学习等级 
	public string   costValue; // 消耗数据 
	public string   displaceDistance; // 位移距离 
	public int   threat; // 仇恨值 
	public string   breakParameter; // 被打断参数 
	public int   damageType; // 伤害类型 
	public int   releaseType; // 释放类型 
	public int   processTypes; // 过程类型 
	public int   attackTime; // 攻击总时间 
	public int   moveCast; // 是否移动施法动作 
	public int   rangeType; // 范围类型 
	public SkillSkillStateBagConfig[]   stateBag; // 状态包 
	public string   damageRate; // 附加伤害倍率 
	public int   goalMaxNum; // 目标最大数量 
	public string   attackRate; // 附加攻击力倍率 
	public string   upgradeCost; // 升级消耗 
	public string   damageTime ; // 伤害生效时间点 
	public string   damageValue; // 附加伤害固定值 
	public int   skillMaxLevel; // 等级上限 
	public int   skillType; // 技能类型 
	public int   profession; // 职业限制 
	public int   cd; // cd 
	public int   move; // 技能释放能否产生位移 
	public int   attackDistance; // 攻击距离 
	public int   readyTime; // 准备时间 
	public int   towards; // 是否可改变朝向 
	public int   type; // 种类 
	public int   warn; // 是否预警 
	public string   name; // 名称 
	public int   breakTime; // 被打断时机 

}

public class SkillSkillConfigTable 
{
    Dictionary<int, SkillSkillConfig> m_configs = 
        new Dictionary<int, SkillSkillConfig>();
    public Dictionary<int, SkillSkillConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 68)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        SkillSkillConfig rec = new SkillSkillConfig();

		rec.skillID = Utility.ToInt(rh.Read());	 //技能id
		rec.name = rh.Read();	 //名称
		rec.profession = Utility.ToInt(rh.Read());	 //职业限制
		rec.skillType = Utility.ToInt(rh.Read());	 //技能类型
		rec.Relation = Utility.ToInt(rh.Read());	 //关联技能
		rec.minLevel = rh.Read();	 //学习等级
		rec.skillMaxLevel = Utility.ToInt(rh.Read());	 //等级上限
		rec.type = Utility.ToInt(rh.Read());	 //种类
		rec.cd = Utility.ToInt(rh.Read());	 //cd
		rec.cost = Utility.ToInt(rh.Read());	 //消耗类型
		rec.costValue = rh.Read();	 //消耗数据
		rec.upgradeCost = rh.Read();	 //升级消耗
		rec.threat = Utility.ToInt(rh.Read());	 //仇恨值
		rec.moveCast = Utility.ToInt(rh.Read());	 //是否移动施法动作
		rec.releaseType = Utility.ToInt(rh.Read());	 //释放类型
		rec.processTypes = Utility.ToInt(rh.Read());	 //过程类型
		rec.flySpeed = Utility.ToInt(rh.Read());	 //飞行速度
		rec.warn = Utility.ToInt(rh.Read());	 //是否预警
		rec.readyTime = Utility.ToInt(rh.Read());	 //准备时间
		rec.attackTime = Utility.ToInt(rh.Read());	 //攻击总时间
		rec.damageTime  = rh.Read();	 //伤害生效时间点
		rec.displaceTime = rh.Read();	 //位移生效时间点
		rec.displaceDistance = rh.Read();	 //位移距离
		rec.move = Utility.ToInt(rh.Read());	 //技能释放能否产生位移
		rec.towards = Utility.ToInt(rh.Read());	 //是否可改变朝向
		rec.breakTime = Utility.ToInt(rh.Read());	 //被打断时机
		rec.breakType = Utility.ToInt(rh.Read());	 //被打断类型
		rec.breakParameter = rh.Read();	 //被打断参数
		rec.attackDistance = Utility.ToInt(rh.Read());	 //攻击距离
		rec.rangeType = Utility.ToInt(rh.Read());	 //范围类型
		rec.rangeTypeValue = rh.Read();	 //范围类型值
		rec.attackMinDistance = Utility.ToInt(rh.Read());	 //攻击最小距离
		rec.goalMaxNum = Utility.ToInt(rh.Read());	 //目标最大数量
		rec.damageType = Utility.ToInt(rh.Read());	 //伤害类型
		rec.attackValue = rh.Read();	 //附加攻击力固定值
		rec.attackRate = rh.Read();	 //附加攻击力倍率
		rec.damageValue = rh.Read();	 //附加伤害固定值
		rec.damageRate = rh.Read();	 //附加伤害倍率
		rec.stateBag = new SkillSkillStateBagConfig[5]; 
		for (int i=0;i<5;i++) {
			rec.stateBag[i] = new SkillSkillStateBagConfig();
		}
		rec.stateBag[0].Target = Utility.ToInt(rh.Read());	 //归属
		rec.stateBag[0].Rate = Utility.ToInt(rh.Read());	 //成功几率
		rec.stateBag[0].Parameter = rh.Read();	 //参数
		rec.stateBag[0].Time = rh.Read();	 //持续时间
		rec.stateBag[0].Point = Utility.ToInt(rh.Read());	 //生效点
		rec.stateBag[0].ID = Utility.ToInt(rh.Read());	 //id
		rec.stateBag[1].Target = Utility.ToInt(rh.Read());	 //归属
		rec.stateBag[1].Rate = Utility.ToInt(rh.Read());	 //成功几率
		rec.stateBag[1].Parameter = rh.Read();	 //参数
		rec.stateBag[1].Time = rh.Read();	 //持续时间
		rec.stateBag[1].Point = Utility.ToInt(rh.Read());	 //生效点
		rec.stateBag[1].ID = Utility.ToInt(rh.Read());	 //id
		rec.stateBag[2].Target = Utility.ToInt(rh.Read());	 //归属
		rec.stateBag[2].Rate = Utility.ToInt(rh.Read());	 //成功几率
		rec.stateBag[2].Parameter = rh.Read();	 //参数
		rec.stateBag[2].Time = rh.Read();	 //持续时间
		rec.stateBag[2].Point = Utility.ToInt(rh.Read());	 //生效点
		rec.stateBag[2].ID = Utility.ToInt(rh.Read());	 //id
		rec.stateBag[3].Target = Utility.ToInt(rh.Read());	 //归属
		rec.stateBag[3].Rate = Utility.ToInt(rh.Read());	 //成功几率
		rec.stateBag[3].Parameter = rh.Read();	 //参数
		rec.stateBag[3].Time = rh.Read();	 //持续时间
		rec.stateBag[3].Point = Utility.ToInt(rh.Read());	 //生效点
		rec.stateBag[3].ID = Utility.ToInt(rh.Read());	 //id
		rec.stateBag[4].Target = Utility.ToInt(rh.Read());	 //归属
		rec.stateBag[4].Rate = Utility.ToInt(rh.Read());	 //成功几率
		rec.stateBag[4].Parameter = rh.Read();	 //参数
		rec.stateBag[4].Time = rh.Read();	 //持续时间
		rec.stateBag[4].Point = Utility.ToInt(rh.Read());	 //生效点
		rec.stateBag[4].ID = Utility.ToInt(rh.Read());	 //id

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Skill_skill.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            SkillSkillConfig ac = ConfigProcess(row) as SkillSkillConfig;
            configs.Add(ac.skillID, ac);
        }
    }
}
