
using System.Collections;
using System.Collections.Generic;


public class AchievementAchievementItemRewardConfig
{
	public int   ID; // ID 
	public int   Value; // 数量 
}




public class AchievementAchievementConfig 
{
	public int   achievementLevel; // 成就触发等级 
	public int   achievementObjectID; // 事件目标ID 
	public int   achievementDia; // 获得绑定钻石数量 
	public int   achievementEXP; // 获得经验 
	public AchievementAchievementItemRewardConfig[]   itemReward; // 获得物品 
	public int   achievementPoint; // 获取成就点数量 
	public int   achievementGold; // 获得金币数量 
	public int   beforeAchievement; // 前置成就ID 
	public int   achievementSubType; // 事件类型 
	public int   achievementId; // 成就ID 
	public int   achievementObjectValue; // 事件目标完成值 
	public int   achievementType; // 成就类型 
	public int   achievementSubSunType; // 事件子类型 

}

public class AchievementAchievementConfigTable 
{
    Dictionary<int, AchievementAchievementConfig> m_configs = 
        new Dictionary<int, AchievementAchievementConfig>();
    public Dictionary<int, AchievementAchievementConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 18)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        AchievementAchievementConfig rec = new AchievementAchievementConfig();

		rec.achievementId = Utility.ToInt(rh.Read());	 //成就ID
		rec.achievementLevel = Utility.ToInt(rh.Read());	 //成就触发等级
		rec.beforeAchievement = Utility.ToInt(rh.Read());	 //前置成就ID
		rec.achievementType = Utility.ToInt(rh.Read());	 //成就类型
		rec.achievementSubType = Utility.ToInt(rh.Read());	 //事件类型
		rec.achievementSubSunType = Utility.ToInt(rh.Read());	 //事件子类型
		rec.achievementObjectID = Utility.ToInt(rh.Read());	 //事件目标ID
		rec.achievementObjectValue = Utility.ToInt(rh.Read());	 //事件目标完成值
		rec.achievementDia = Utility.ToInt(rh.Read());	 //获得绑定钻石数量
		rec.achievementGold = Utility.ToInt(rh.Read());	 //获得金币数量
		rec.achievementEXP = Utility.ToInt(rh.Read());	 //获得经验
		rec.achievementPoint = Utility.ToInt(rh.Read());	 //获取成就点数量
		rec.itemReward = new AchievementAchievementItemRewardConfig[3]; 
		for (int i=0;i<3;i++) {
			rec.itemReward[i] = new AchievementAchievementItemRewardConfig();
		}
		rec.itemReward[0].Value = Utility.ToInt(rh.Read());	 //数量
		rec.itemReward[0].ID = Utility.ToInt(rh.Read());	 //ID
		rec.itemReward[1].Value = Utility.ToInt(rh.Read());	 //数量
		rec.itemReward[1].ID = Utility.ToInt(rh.Read());	 //ID
		rec.itemReward[2].Value = Utility.ToInt(rh.Read());	 //数量
		rec.itemReward[2].ID = Utility.ToInt(rh.Read());	 //ID

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Achievement_achievement.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            AchievementAchievementConfig ac = ConfigProcess(row) as AchievementAchievementConfig;
            configs.Add(ac.achievementId, ac);
        }
    }
}
