
using System.Collections;
using System.Collections.Generic;



public class PetPetConfig 
{
	public int   dp; // 物理防御 
	public int   ap; // 物理攻击 
	public int   maxHP; // 最大生命值 
	public int[]   costMoney; // 消耗金币数量 
	public int   petQuality; // 精灵品质 
	public int   level; // 对应等级 
	public int   star; // 培养星数 
	public int   mdp; // 魔法防御 
	public int   commonSkillId; // 普攻ID 
	public int   costFragmentNum; // 消耗碎片数量 
	public int   costStoneNum; // 消耗进化石数量 
	public int   mat; // 魔法攻击 
	public int   stoneId; // 消耗进化石id 
	public int   stage; // 阶段 
	public int   petId; // 精灵ID 
	public int   fragmentId; // 升星消耗碎片id 
	public int   maxMP; // 最大魔法值 
	public int   evolveId; // 进化后id 
	public int   trainId; // 升星后id 

}

public class PetPetConfigTable 
{
    Dictionary<int, PetPetConfig> m_configs = 
        new Dictionary<int, PetPetConfig>();
    public Dictionary<int, PetPetConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 20)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        PetPetConfig rec = new PetPetConfig();

		rec.petId = Utility.ToInt(rh.Read());	 //精灵ID
		rec.level = Utility.ToInt(rh.Read());	 //对应等级
		rec.star = Utility.ToInt(rh.Read());	 //培养星数
		rec.maxHP = Utility.ToInt(rh.Read());	 //最大生命值
		rec.maxMP = Utility.ToInt(rh.Read());	 //最大魔法值
		rec.ap = Utility.ToInt(rh.Read());	 //物理攻击
		rec.mat = Utility.ToInt(rh.Read());	 //魔法攻击
		rec.dp = Utility.ToInt(rh.Read());	 //物理防御
		rec.mdp = Utility.ToInt(rh.Read());	 //魔法防御
		rec.fragmentId = Utility.ToInt(rh.Read());	 //升星消耗碎片id
		rec.costFragmentNum = Utility.ToInt(rh.Read());	 //消耗碎片数量
		rec.trainId = Utility.ToInt(rh.Read());	 //升星后id
		rec.evolveId = Utility.ToInt(rh.Read());	 //进化后id
		rec.stage = Utility.ToInt(rh.Read());	 //阶段
		rec.petQuality = Utility.ToInt(rh.Read());	 //精灵品质
		rec.stoneId = Utility.ToInt(rh.Read());	 //消耗进化石id
		rec.costStoneNum = Utility.ToInt(rh.Read());	 //消耗进化石数量
		rec.commonSkillId = Utility.ToInt(rh.Read());	 //普攻ID
		rec.costMoney = new int[2]; 
		rec.costMoney[0] = Utility.ToInt(rh.Read());	 //消耗金币数量
		rec.costMoney[1] = Utility.ToInt(rh.Read());	 //消耗金币数量

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Pet_pet.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            PetPetConfig ac = ConfigProcess(row) as PetPetConfig;
            configs.Add(ac.petId, ac);
        }
    }
}
