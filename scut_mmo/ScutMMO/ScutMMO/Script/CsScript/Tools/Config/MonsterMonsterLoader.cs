
using System.Collections;
using System.Collections.Generic;



public class MonsterMonsterConfig 
{
	public int   isBelongToPlayer; // 怪物归属是否显示 
	public int   monsterAtkType; // 普攻方式 
	public string   deathTrigger; // 死亡触发器 
	public int   reduceDamage; // 额外免伤 
	public int   fastingRes; // 禁食抗性 
	public int   maxHP; // 最大生命值 
	public int   isSkin; // 是否可剥取 
	public int   burnRes; // 灼烧抗性 
	public int   freezeRes; // 冰冻抗性 
	public int   funkRes; // 恐惧抗性 
	public int   isShiftOff; // 是否关闭位移 
	public int   aSpeed; // 攻击速度 
	public int   isFloatingOff; // 是否关闭浮空 
	public int   hit; // 命中 
	public int   toughness; // 韧性 
	public int   isFormationOn; // 是否开启巡逻阵型 
	public int   isAIWorkWhenNobody; // 是否无人时启用AI 
	public int   critExtraDamage; // 暴击额外伤害 
	public int   dropDefault; // 默认掉落 
	public int   dodge; // 闪避 
	public int   isStiffOff; // 是否关闭僵直 
	public int   actionRange; // 怪物活动范围 
	public int   exp; // 经验产出 
	public int   patrolPath; // 巡逻路径 
	public int   reduceDamageRate; // 免伤率 
	public string   deathEffect; // 死亡特效 
	public int   monsterLV; // 怪物等级 
	public int   damageRate; // 伤害率 
	public int   dp; // 物理防御 
	public int   ap; // 物理攻击 
	public int   specialAI; // 怪物特殊AI 
	public int   monsterType; // 怪物类型 
	public int   monsterFightType; // 怪物战斗类型 
	public int   patrolType; // 巡逻类型 
	public int   bodyStayTime; // 尸体留存时间 
	public int   restWaitTime; // 怪物休闲等待时间 
	public int   protectTime; // 怪物归属保护时间 
	public int   isDownOff; // 是否关闭击倒 
	public string   view; // 视野 
	public int   extraDamage; // 额外伤害 
	public int   weakRes; // 虚弱抗性 
	public int   normalSkillLevel; // 普攻技能等级 
	public int   crit; // 暴击 
	public int   critReduceDamage; // 暴击额外免伤 
	public int   monsterCfgType; // 怪物配置类型 
	public int   mdp; // 魔法防御 
	public int   mSpeed; // 移动速度 
	public int   attackRange; // 攻击范围 
	public int   skinLink; // 剥皮关联 
	public int   viewType; // 视野类型 
	public int   pursueRange; // 追击范围 
	public int   mat; // 魔法攻击 
	public int   critRate; // 暴击倍率 
	public int   monsterID; // 怪物ID 
	public int   anchor; // 特效挂点 
	public string   bornTrigger; // 出生触发器 
	public int   maxMP; // 最大魔法值 
	public int   monsterRefreshTime; // 怪物刷新时间 
	public int   normalSkill; // 普攻技能 

}

public class MonsterMonsterConfigTable 
{
    Dictionary<int, MonsterMonsterConfig> m_configs = 
        new Dictionary<int, MonsterMonsterConfig>();
    public Dictionary<int, MonsterMonsterConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 59)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        MonsterMonsterConfig rec = new MonsterMonsterConfig();

		rec.monsterID = Utility.ToInt(rh.Read());	 //怪物ID
		rec.monsterLV = Utility.ToInt(rh.Read());	 //怪物等级
		rec.monsterCfgType = Utility.ToInt(rh.Read());	 //怪物配置类型
		rec.monsterRefreshTime = Utility.ToInt(rh.Read());	 //怪物刷新时间
		rec.monsterFightType = Utility.ToInt(rh.Read());	 //怪物战斗类型
		rec.monsterType = Utility.ToInt(rh.Read());	 //怪物类型
		rec.monsterAtkType = Utility.ToInt(rh.Read());	 //普攻方式
		rec.specialAI = Utility.ToInt(rh.Read());	 //怪物特殊AI
		rec.bodyStayTime = Utility.ToInt(rh.Read());	 //尸体留存时间
		rec.isSkin = Utility.ToInt(rh.Read());	 //是否可剥取
		rec.deathTrigger = rh.Read();	 //死亡触发器
		rec.bornTrigger = rh.Read();	 //出生触发器
		rec.actionRange = Utility.ToInt(rh.Read());	 //怪物活动范围
		rec.viewType = Utility.ToInt(rh.Read());	 //视野类型
		rec.view = rh.Read();	 //视野
		rec.attackRange = Utility.ToInt(rh.Read());	 //攻击范围
		rec.pursueRange = Utility.ToInt(rh.Read());	 //追击范围
		rec.maxHP = Utility.ToInt(rh.Read());	 //最大生命值
		rec.maxMP = Utility.ToInt(rh.Read());	 //最大魔法值
		rec.ap = Utility.ToInt(rh.Read());	 //物理攻击
		rec.mat = Utility.ToInt(rh.Read());	 //魔法攻击
		rec.dp = Utility.ToInt(rh.Read());	 //物理防御
		rec.mdp = Utility.ToInt(rh.Read());	 //魔法防御
		rec.hit = Utility.ToInt(rh.Read());	 //命中
		rec.dodge = Utility.ToInt(rh.Read());	 //闪避
		rec.crit = Utility.ToInt(rh.Read());	 //暴击
		rec.toughness = Utility.ToInt(rh.Read());	 //韧性
		rec.critRate = Utility.ToInt(rh.Read());	 //暴击倍率
		rec.critExtraDamage = Utility.ToInt(rh.Read());	 //暴击额外伤害
		rec.critReduceDamage = Utility.ToInt(rh.Read());	 //暴击额外免伤
		rec.extraDamage = Utility.ToInt(rh.Read());	 //额外伤害
		rec.reduceDamage = Utility.ToInt(rh.Read());	 //额外免伤
		rec.damageRate = Utility.ToInt(rh.Read());	 //伤害率
		rec.reduceDamageRate = Utility.ToInt(rh.Read());	 //免伤率
		rec.freezeRes = Utility.ToInt(rh.Read());	 //冰冻抗性
		rec.burnRes = Utility.ToInt(rh.Read());	 //灼烧抗性
		rec.weakRes = Utility.ToInt(rh.Read());	 //虚弱抗性
		rec.fastingRes = Utility.ToInt(rh.Read());	 //禁食抗性
		rec.funkRes = Utility.ToInt(rh.Read());	 //恐惧抗性
		rec.mSpeed = Utility.ToInt(rh.Read());	 //移动速度
		rec.aSpeed = Utility.ToInt(rh.Read());	 //攻击速度
		rec.normalSkill = Utility.ToInt(rh.Read());	 //普攻技能
		rec.normalSkillLevel = Utility.ToInt(rh.Read());	 //普攻技能等级
		rec.dropDefault = Utility.ToInt(rh.Read());	 //默认掉落
		rec.exp = Utility.ToInt(rh.Read());	 //经验产出
		rec.isBelongToPlayer = Utility.ToInt(rh.Read());	 //怪物归属是否显示
		rec.protectTime = Utility.ToInt(rh.Read());	 //怪物归属保护时间
		rec.restWaitTime = Utility.ToInt(rh.Read());	 //怪物休闲等待时间
		rec.deathEffect = rh.Read();	 //死亡特效
		rec.anchor = Utility.ToInt(rh.Read());	 //特效挂点
		rec.skinLink = Utility.ToInt(rh.Read());	 //剥皮关联
		rec.patrolType = Utility.ToInt(rh.Read());	 //巡逻类型
		rec.patrolPath = Utility.ToInt(rh.Read());	 //巡逻路径
		rec.isFormationOn = Utility.ToInt(rh.Read());	 //是否开启巡逻阵型
		rec.isShiftOff = Utility.ToInt(rh.Read());	 //是否关闭位移
		rec.isFloatingOff = Utility.ToInt(rh.Read());	 //是否关闭浮空
		rec.isStiffOff = Utility.ToInt(rh.Read());	 //是否关闭僵直
		rec.isDownOff = Utility.ToInt(rh.Read());	 //是否关闭击倒
		rec.isAIWorkWhenNobody = Utility.ToInt(rh.Read());	 //是否无人时启用AI

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Monster_monster.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            MonsterMonsterConfig ac = ConfigProcess(row) as MonsterMonsterConfig;
            configs.Add(ac.monsterID, ac);
        }
    }
}
