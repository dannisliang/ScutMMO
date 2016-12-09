
using System.Collections;
using System.Collections.Generic;


public class EquipEquipAttributeConfig
{
	public int   type; //  
	public int   valueMax; // 最大数值 
	public int   valueMin; // 最小数值 
}




public class EquipEquipConfig 
{
	public EquipEquipAttributeConfig[]   attribute; // 基础属性 
	public float   strengthenProportion; // 强化比例 
	public int   holeMin; // 初始最小镶嵌孔数 
	public int   refineAttributeNum; // 随机精炼属性条数 
	public string[]   source; // 装备来源 
	public int   isDrop; // 是否掉落 
	public int   profession; // 职业限制 
	public float   refineProportion; // 精炼比例 
	public string   refineAttribute_valueMax; // 精炼属性最大值 
	public int   position; // 装备位置 
	public int   suitId; // 套装ID 
	public int   sex; // 性别限制 
	public string   refineAttribute_valueMin; // 精炼属性最小值 
	public int   holeMax; // 初始最大镶嵌孔数 
	public int   id; // 装备ID 
	public string   desc; // 装备描述 
	public int   isCanbind; // 是否绑定 
	public string   refineAttribute_typeLibrary; // 随机精炼属性库 
	public int   bindType; // 绑定类型 
	public int   quality; // 装备固定品质 
	public int   sellPrice; // 出售价格 
	public int   isCanSell; // 是否出售 
	public int   wearLevel; // 穿戴等级限制 

}

public class EquipEquipConfigTable 
{
    Dictionary<int, EquipEquipConfig> m_configs = 
        new Dictionary<int, EquipEquipConfig>();
    public Dictionary<int, EquipEquipConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 31)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        EquipEquipConfig rec = new EquipEquipConfig();

		rec.id = Utility.ToInt(rh.Read());	 //装备ID
		rec.quality = Utility.ToInt(rh.Read());	 //装备固定品质
		rec.sex = Utility.ToInt(rh.Read());	 //性别限制
		rec.profession = Utility.ToInt(rh.Read());	 //职业限制
		rec.wearLevel = Utility.ToInt(rh.Read());	 //穿戴等级限制
		rec.suitId = Utility.ToInt(rh.Read());	 //套装ID
		rec.position = Utility.ToInt(rh.Read());	 //装备位置
		rec.holeMin = Utility.ToInt(rh.Read());	 //初始最小镶嵌孔数
		rec.holeMax = Utility.ToInt(rh.Read());	 //初始最大镶嵌孔数
		rec.isCanbind = Utility.ToInt(rh.Read());	 //是否绑定
		rec.bindType = Utility.ToInt(rh.Read());	 //绑定类型
		rec.isCanSell = Utility.ToInt(rh.Read());	 //是否出售
		rec.sellPrice = Utility.ToInt(rh.Read());	 //出售价格
		rec.isDrop = Utility.ToInt(rh.Read());	 //是否掉落
		rec.strengthenProportion = Utility.ToFloat(rh.Read());	 //强化比例
		rec.refineAttributeNum = Utility.ToInt(rh.Read());	 //随机精炼属性条数
		rec.refineAttribute_typeLibrary = rh.Read();	 //随机精炼属性库
		rec.refineAttribute_valueMin = rh.Read();	 //精炼属性最小值
		rec.refineAttribute_valueMax = rh.Read();	 //精炼属性最大值
		rec.refineProportion = Utility.ToFloat(rh.Read());	 //精炼比例
		rec.desc = rh.Read();	 //装备描述
		rec.source = new string[4]; 
		rec.source[0] = rh.Read();	 //装备来源
		rec.source[1] = rh.Read();	 //装备来源
		rec.source[2] = rh.Read();	 //装备来源
		rec.source[3] = rh.Read();	 //装备来源
		rec.attribute = new EquipEquipAttributeConfig[2]; 
		for (int i=0;i<2;i++) {
			rec.attribute[i] = new EquipEquipAttributeConfig();
		}
		rec.attribute[0].type = Utility.ToInt(rh.Read());	 //
		rec.attribute[0].valueMax = Utility.ToInt(rh.Read());	 //最大数值
		rec.attribute[0].valueMin = Utility.ToInt(rh.Read());	 //最小数值
		rec.attribute[1].type = Utility.ToInt(rh.Read());	 //
		rec.attribute[1].valueMax = Utility.ToInt(rh.Read());	 //最大数值
		rec.attribute[1].valueMin = Utility.ToInt(rh.Read());	 //最小数值

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Equip_equip.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            EquipEquipConfig ac = ConfigProcess(row) as EquipEquipConfig;
            configs.Add(ac.id, ac);
        }
    }
}
