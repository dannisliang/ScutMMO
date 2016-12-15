
using System.Collections;
using System.Collections.Generic;



public class PetPetskillConfig 
{
	public int   skillLevel; // 技能等级 
	public int   bookNum; // 技能书数量 
	public int   bookId; // 消耗技能书id 
	public int   skillId; // 技能ID 
	public int   costMoney; // 金币数量 

}

public class PetPetskillConfigTable 
{
    Dictionary<int, PetPetskillConfig> m_configs = 
        new Dictionary<int, PetPetskillConfig>();
    public Dictionary<int, PetPetskillConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 5)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        PetPetskillConfig rec = new PetPetskillConfig();

		rec.skillId = Utility.ToInt(rh.Read());	 //技能ID
		rec.skillLevel = Utility.ToInt(rh.Read());	 //技能等级
		rec.bookId = Utility.ToInt(rh.Read());	 //消耗技能书id
		rec.bookNum = Utility.ToInt(rh.Read());	 //技能书数量
		rec.costMoney = Utility.ToInt(rh.Read());	 //金币数量

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Pet_petskill.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            PetPetskillConfig ac = ConfigProcess(row) as PetPetskillConfig;
            configs.Add(ac.skillId, ac);
        }
    }
}
