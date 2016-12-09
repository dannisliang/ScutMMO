
using System.Collections;
using System.Collections.Generic;



public class DuplicateDuplicateConfig 
{
	public int   reviveMaxTimes; // 复活次数上限 
	public int   groupID; // 所属副本组ID 
	public int   sceneResource; // 场景ID 
	public int   rewardLibrary; // 普通奖品库 
	public int   rewardCoin; // 奖励游戏币 
	public string   gradeRule; // 评级规则 
	public int   goodRewardValue; // 良品阀 
	public int   playerAmountLowerLimit; // 人数要求下限 
	public int   goodRewardLibrary; // 良品库 
	public int   duplicateType; // 副本内容类型 
	public int   playerAmountTopLimit; // 人数要求上限 
	public int   dropNormalMonster; // 普通怪物掉落 
	public string   duplicateConditionType; // 副本条件类型 
	public int   linkDuplicateRequest; // 前置副本要求 
	public string   bossDesc; // BOSS说明序列 
	public int   rewardExp; // 奖励经验 
	public int   dropEliteMonster; // 精英怪物掉落 
	public int   levelLimit; // 等级要求下限 
	public int   playType; // 副本玩法类型 
	public string   sceneAIScript; // 场景AI脚本 
	public int   duplicateID; // 副本ID 
	public int   isAutoFight; // 是否允许自动战斗 
	public string   rewardItem; // 奖励物品 
	public string   unlockTask; // 解锁任务 
	public string   trigEntry; // 触发入口 

}

public class DuplicateDuplicateConfigTable 
{
    Dictionary<int, DuplicateDuplicateConfig> m_configs = 
        new Dictionary<int, DuplicateDuplicateConfig>();
    public Dictionary<int, DuplicateDuplicateConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 25)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        DuplicateDuplicateConfig rec = new DuplicateDuplicateConfig();

		rec.duplicateID = Utility.ToInt(rh.Read());	 //副本ID
		rec.groupID = Utility.ToInt(rh.Read());	 //所属副本组ID
		rec.duplicateType = Utility.ToInt(rh.Read());	 //副本内容类型
		rec.playType = Utility.ToInt(rh.Read());	 //副本玩法类型
		rec.sceneResource = Utility.ToInt(rh.Read());	 //场景ID
		rec.levelLimit = Utility.ToInt(rh.Read());	 //等级要求下限
		rec.linkDuplicateRequest = Utility.ToInt(rh.Read());	 //前置副本要求
		rec.unlockTask = rh.Read();	 //解锁任务
		rec.playerAmountTopLimit = Utility.ToInt(rh.Read());	 //人数要求上限
		rec.playerAmountLowerLimit = Utility.ToInt(rh.Read());	 //人数要求下限
		rec.isAutoFight = Utility.ToInt(rh.Read());	 //是否允许自动战斗
		rec.duplicateConditionType = rh.Read();	 //副本条件类型
		rec.reviveMaxTimes = Utility.ToInt(rh.Read());	 //复活次数上限
		rec.gradeRule = rh.Read();	 //评级规则
		rec.rewardLibrary = Utility.ToInt(rh.Read());	 //普通奖品库
		rec.goodRewardLibrary = Utility.ToInt(rh.Read());	 //良品库
		rec.goodRewardValue = Utility.ToInt(rh.Read());	 //良品阀
		rec.rewardExp = Utility.ToInt(rh.Read());	 //奖励经验
		rec.rewardCoin = Utility.ToInt(rh.Read());	 //奖励游戏币
		rec.rewardItem = rh.Read();	 //奖励物品
		rec.dropNormalMonster = Utility.ToInt(rh.Read());	 //普通怪物掉落
		rec.dropEliteMonster = Utility.ToInt(rh.Read());	 //精英怪物掉落
		rec.sceneAIScript = rh.Read();	 //场景AI脚本
		rec.bossDesc = rh.Read();	 //BOSS说明序列
		rec.trigEntry = rh.Read();	 //触发入口

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Duplicate_duplicate.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            DuplicateDuplicateConfig ac = ConfigProcess(row) as DuplicateDuplicateConfig;
            configs.Add(ac.duplicateID, ac);
        }
    }
}
