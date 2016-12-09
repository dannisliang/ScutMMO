
using System.Collections;
using System.Collections.Generic;


public class AchievementAchievementrewardRewardConfig
{
	public int   ID; // ID 
	public int   Value; // 数量 
}




public class AchievementAchievementrewardConfig 
{
	public AchievementAchievementrewardRewardConfig[]   Reward; // 奖励物品 
	public int   achievementPointValue; // 所需成就点值 
	public int   achievementType; // 成就类型 
	public int   achievementPrizeId; // 成就奖励ID 

}

public class AchievementAchievementrewardConfigTable 
{
    Dictionary<int, AchievementAchievementrewardConfig> m_configs = 
        new Dictionary<int, AchievementAchievementrewardConfig>();
    public Dictionary<int, AchievementAchievementrewardConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 13)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        AchievementAchievementrewardConfig rec = new AchievementAchievementrewardConfig();

		rec.achievementPrizeId = Utility.ToInt(rh.Read());	 //成就奖励ID
		rec.achievementType = Utility.ToInt(rh.Read());	 //成就类型
		rec.achievementPointValue = Utility.ToInt(rh.Read());	 //所需成就点值
		rec.Reward = new AchievementAchievementrewardRewardConfig[5]; 
		for (int i=0;i<5;i++) {
			rec.Reward[i] = new AchievementAchievementrewardRewardConfig();
		}
		rec.Reward[0].Value = Utility.ToInt(rh.Read());	 //数量
		rec.Reward[0].ID = Utility.ToInt(rh.Read());	 //ID
		rec.Reward[1].Value = Utility.ToInt(rh.Read());	 //数量
		rec.Reward[1].ID = Utility.ToInt(rh.Read());	 //ID
		rec.Reward[2].Value = Utility.ToInt(rh.Read());	 //数量
		rec.Reward[2].ID = Utility.ToInt(rh.Read());	 //ID
		rec.Reward[3].Value = Utility.ToInt(rh.Read());	 //数量
		rec.Reward[3].ID = Utility.ToInt(rh.Read());	 //ID
		rec.Reward[4].Value = Utility.ToInt(rh.Read());	 //数量
		rec.Reward[4].ID = Utility.ToInt(rh.Read());	 //ID

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Achievement_achievementreward.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            AchievementAchievementrewardConfig ac = ConfigProcess(row) as AchievementAchievementrewardConfig;
            configs.Add(ac.achievementPrizeId, ac);
        }
    }
}
