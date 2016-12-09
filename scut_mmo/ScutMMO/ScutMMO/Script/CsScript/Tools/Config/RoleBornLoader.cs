
using System.Collections;
using System.Collections.Generic;


public class RoleBornItemConfig
{
	public int   name; // 名称 
	public int   num; // 数量 
}




public class RoleBornConfig 
{
	public int   carryFashionWeapons; // 装备时装(武器) 
	public int   carryRing2; // 装备戒指 
	public int   bornID; // 主键ID 
	public int   mapX; // 出生地的X点 
	public string   icons; // 头像图标 
	public int   carryBracer2; // 装备护腕 
	public int   carryWings; // 装备翅膀 
	public int   mapID; // 出生地图ID 
	public int   carryNecklace; // 装备项链 
	public int   race; // 种族 
	public int   gender; // 性别 
	public int   gold; // 携带金币 
	public int   birthFace; // 出生朝向 
	public int[]   actBuff; // 生成buff 
	public int   bornTitle; // 携带称号 
	public int   bindGold; // 携带绑定金币 
	public int   diamond; // 携带钻石 
	public int   carryArmor; // 装备衣服 
	public int   professionID; // 职业ID 
	public int   carryRing1; // 装备戒指 
	public string   roleAvata; // 出生时模型 
	public RoleBornItemConfig[]   item; // 背包物品 
	public int[]   actSkill; // 生成技能 
	public string   weaponAvata; // 出生时武器模型 
	public int   mapY; // 出生地的Y点 
	public string   professionName; // 职业名称 
	public int   carryFashionArmor; // 装备时装(衣服) 
	public int   bornLevel; // 出生等级 
	public int   carryCloak; // 装备披风 
	public string   placement; // 职业介绍 
	public int   carryWeapons; // 装备武器 
	public int   bindDiamond; // 携带绑定钻石 
	public string   loginAvata; // 创角界面模型 
	public int   carryShoes; // 装备鞋子 
	public int   carryAmulet; // 装备护符 
	public int   mapZ; // 出生地的Z点 
	public int   carryBracer1; // 装备护腕 

}

public class RoleBornConfigTable 
{
    Dictionary<int, RoleBornConfig> m_configs = 
        new Dictionary<int, RoleBornConfig>();
    public Dictionary<int, RoleBornConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 106)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        RoleBornConfig rec = new RoleBornConfig();

		rec.bornID = Utility.ToInt(rh.Read());	 //主键ID
		rec.professionID = Utility.ToInt(rh.Read());	 //职业ID
		rec.professionName = rh.Read();	 //职业名称
		rec.placement = rh.Read();	 //职业介绍
		rec.race = Utility.ToInt(rh.Read());	 //种族
		rec.gender = Utility.ToInt(rh.Read());	 //性别
		rec.bornLevel = Utility.ToInt(rh.Read());	 //出生等级
		rec.bornTitle = Utility.ToInt(rh.Read());	 //携带称号
		rec.diamond = Utility.ToInt(rh.Read());	 //携带钻石
		rec.bindDiamond = Utility.ToInt(rh.Read());	 //携带绑定钻石
		rec.gold = Utility.ToInt(rh.Read());	 //携带金币
		rec.bindGold = Utility.ToInt(rh.Read());	 //携带绑定金币
		rec.mapID = Utility.ToInt(rh.Read());	 //出生地图ID
		rec.mapX = Utility.ToInt(rh.Read());	 //出生地的X点
		rec.mapY = Utility.ToInt(rh.Read());	 //出生地的Y点
		rec.mapZ = Utility.ToInt(rh.Read());	 //出生地的Z点
		rec.birthFace = Utility.ToInt(rh.Read());	 //出生朝向
		rec.icons = rh.Read();	 //头像图标
		rec.loginAvata = rh.Read();	 //创角界面模型
		rec.weaponAvata = rh.Read();	 //出生时武器模型
		rec.roleAvata = rh.Read();	 //出生时模型
		rec.carryWeapons = Utility.ToInt(rh.Read());	 //装备武器
		rec.carryArmor = Utility.ToInt(rh.Read());	 //装备衣服
		rec.carryCloak = Utility.ToInt(rh.Read());	 //装备披风
		rec.carryShoes = Utility.ToInt(rh.Read());	 //装备鞋子
		rec.carryNecklace = Utility.ToInt(rh.Read());	 //装备项链
		rec.carryAmulet = Utility.ToInt(rh.Read());	 //装备护符
		rec.carryBracer1 = Utility.ToInt(rh.Read());	 //装备护腕
		rec.carryBracer2 = Utility.ToInt(rh.Read());	 //装备护腕
		rec.carryRing1 = Utility.ToInt(rh.Read());	 //装备戒指
		rec.carryRing2 = Utility.ToInt(rh.Read());	 //装备戒指
		rec.carryFashionWeapons = Utility.ToInt(rh.Read());	 //装备时装(武器)
		rec.carryFashionArmor = Utility.ToInt(rh.Read());	 //装备时装(衣服)
		rec.carryWings = Utility.ToInt(rh.Read());	 //装备翅膀
		rec.actBuff = new int[4]; 
		rec.actBuff[0] = Utility.ToInt(rh.Read());	 //生成buff
		rec.actBuff[1] = Utility.ToInt(rh.Read());	 //生成buff
		rec.actBuff[2] = Utility.ToInt(rh.Read());	 //生成buff
		rec.actBuff[3] = Utility.ToInt(rh.Read());	 //生成buff
		rec.actSkill = new int[6]; 
		rec.actSkill[0] = Utility.ToInt(rh.Read());	 //生成技能
		rec.actSkill[1] = Utility.ToInt(rh.Read());	 //生成技能
		rec.actSkill[2] = Utility.ToInt(rh.Read());	 //生成技能
		rec.actSkill[3] = Utility.ToInt(rh.Read());	 //生成技能
		rec.actSkill[4] = Utility.ToInt(rh.Read());	 //生成技能
		rec.actSkill[5] = Utility.ToInt(rh.Read());	 //生成技能
		rec.item = new RoleBornItemConfig[31]; 
		for (int i=0;i<31;i++) {
			rec.item[i] = new RoleBornItemConfig();
		}
		rec.item[0].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[0].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[1].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[1].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[2].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[2].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[3].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[3].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[4].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[4].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[5].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[5].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[6].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[6].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[7].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[7].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[8].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[8].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[9].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[9].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[10].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[10].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[11].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[11].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[12].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[12].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[13].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[13].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[14].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[14].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[15].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[15].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[16].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[16].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[17].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[17].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[18].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[18].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[19].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[19].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[20].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[20].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[21].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[21].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[22].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[22].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[23].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[23].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[24].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[24].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[25].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[25].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[26].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[26].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[27].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[27].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[28].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[28].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[29].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[29].num = Utility.ToInt(rh.Read());	 //数量
		rec.item[30].name = Utility.ToInt(rh.Read());	 //名称
		rec.item[30].num = Utility.ToInt(rh.Read());	 //数量

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Role_born.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            RoleBornConfig ac = ConfigProcess(row) as RoleBornConfig;
            configs.Add(ac.bornID, ac);
        }
    }
}
