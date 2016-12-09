
using System.Collections;

public class ConfigMgr
{
    private ConfigMgr()
    {

    }

    private ConfigMgr(ref ConfigMgr mgr)
    {

    }

    private ConfigMgr(ConfigMgr mgr)
    {

    }

    private static ConfigMgr _gi;

    public static ConfigMgr Inst()
    {
        if (_gi == null)
        {
            _gi = new ConfigMgr();
        }
        return _gi;
    }
	
	public AttributeSuppressConfigTable      AttributeSuppress;
	public AttributeConvertConfigTable      AttributeConvert;
	public PkmodePkWantedConfigTable      PkmodePkWanted;
	public AvocationAvocationskillConfigTable      AvocationAvocationskill;
	public AvocationComposeConfigTable      AvocationCompose;
	public DropDropConfigTable      DropDrop;
	public AchievementAchievementConfigTable      AchievementAchievement;
	public AchievementAchievementrewardConfigTable      AchievementAchievementreward;
	public RoleBornConfigTable      RoleBorn;
	public RoleMasterConfigTable      RoleMaster;
	public RoleAssassinConfigTable      RoleAssassin;
	public RoleExpConfigTable      RoleExp;
	public RoleShooterConfigTable      RoleShooter;
	public RoleWarriorConfigTable      RoleWarrior;
	public NpcNpcConfigTable      NpcNpc;
	public NpcNpcfunctionConfigTable      NpcNpcfunction;
	public ItemItemConfigTable      ItemItem;
	public TeleportBornConfigTable      TeleportBorn;
	public TeleportSafeareaConfigTable      TeleportSafearea;
	public TeleportTeleportConfigTable      TeleportTeleport;
	public ComposeComposeConfigTable      ComposeCompose;
	public MapMapConfigTable      MapMap;
	public MonsterMonsterConfigTable      MonsterMonster;
	public MallMallConfigTable      MallMall;
	public MallMalltypeConfigTable      MallMalltype;
	public TasktrackerTasktrackerConfigTable      TasktrackerTasktracker;
	public EquipFashionConfigTable      EquipFashion;
	public EquipSuitConfigTable      EquipSuit;
	public EquipRefineConfigTable      EquipRefine;
	public EquipEquipConfigTable      EquipEquip;
	public EquipStrengthenConfigTable      EquipStrengthen;
	public ChatChatConfigTable      ChatChat;
	public DuplicateDuplicateConfigTable      DuplicateDuplicate;
	public DuplicateGroupConfigTable      DuplicateGroup;
	public AreaPathConfigTable      AreaPath;
	public AreaAreaConfigTable      AreaArea;
	public RandomnameWomanfirstConfigTable      RandomnameWomanfirst;
	public RandomnameManthirdConfigTable      RandomnameManthird;
	public RandomnameWomanthirdConfigTable      RandomnameWomanthird;
	public RandomnameMansecondConfigTable      RandomnameMansecond;
	public RandomnameManfirstConfigTable      RandomnameManfirst;
	public RandomnameWomansecondConfigTable      RandomnameWomansecond;
	public ConstantConstantConfigTable      ConstantConstant;
	public BoxDropConfigTable      BoxDrop;
	public SkillSummonConfigTable      SkillSummon;
	public SkillBuffConfigTable      SkillBuff;
	public SkillSkillConfigTable      SkillSkill;
	public SrvlistServerConfigTable      SrvlistServer;
	public SrvlistAreaConfigTable      SrvlistArea;
	public AiAiConfigTable      AiAi;
	public ThingCollectConfigTable      ThingCollect;
	public ThingThingConfigTable      ThingThing;


    public void InitConfigMgr() 
    {

        {
            AttributeSuppress = new AttributeSuppressConfigTable();
            AttributeSuppress.Load();
            AttributeConvert = new AttributeConvertConfigTable();
            AttributeConvert.Load();
            PkmodePkWanted = new PkmodePkWantedConfigTable();
            PkmodePkWanted.Load();
            AvocationAvocationskill = new AvocationAvocationskillConfigTable();
            AvocationAvocationskill.Load();
            AvocationCompose = new AvocationComposeConfigTable();
            AvocationCompose.Load();
            DropDrop = new DropDropConfigTable();
            DropDrop.Load();
            AchievementAchievement = new AchievementAchievementConfigTable();
            AchievementAchievement.Load();
            AchievementAchievementreward = new AchievementAchievementrewardConfigTable();
            AchievementAchievementreward.Load();
            RoleBorn = new RoleBornConfigTable();
            RoleBorn.Load();
            RoleMaster = new RoleMasterConfigTable();
            RoleMaster.Load();
            RoleAssassin = new RoleAssassinConfigTable();
            RoleAssassin.Load();
            RoleExp = new RoleExpConfigTable();
            RoleExp.Load();
            RoleShooter = new RoleShooterConfigTable();
            RoleShooter.Load();
            RoleWarrior = new RoleWarriorConfigTable();
            RoleWarrior.Load();
            NpcNpc = new NpcNpcConfigTable();
            NpcNpc.Load();
            NpcNpcfunction = new NpcNpcfunctionConfigTable();
            NpcNpcfunction.Load();
            ItemItem = new ItemItemConfigTable();
            ItemItem.Load();
            TeleportBorn = new TeleportBornConfigTable();
            TeleportBorn.Load();
            TeleportSafearea = new TeleportSafeareaConfigTable();
            TeleportSafearea.Load();
            TeleportTeleport = new TeleportTeleportConfigTable();
            TeleportTeleport.Load();
            ComposeCompose = new ComposeComposeConfigTable();
            ComposeCompose.Load();
            MapMap = new MapMapConfigTable();
            MapMap.Load();
            MonsterMonster = new MonsterMonsterConfigTable();
            MonsterMonster.Load();
            MallMall = new MallMallConfigTable();
            MallMall.Load();
            MallMalltype = new MallMalltypeConfigTable();
            MallMalltype.Load();
            TasktrackerTasktracker = new TasktrackerTasktrackerConfigTable();
            TasktrackerTasktracker.Load();
            EquipFashion = new EquipFashionConfigTable();
            EquipFashion.Load();
            EquipSuit = new EquipSuitConfigTable();
            EquipSuit.Load();
            EquipRefine = new EquipRefineConfigTable();
            EquipRefine.Load();
            EquipEquip = new EquipEquipConfigTable();
            EquipEquip.Load();
            EquipStrengthen = new EquipStrengthenConfigTable();
            EquipStrengthen.Load();
            ChatChat = new ChatChatConfigTable();
            ChatChat.Load();
            DuplicateDuplicate = new DuplicateDuplicateConfigTable();
            DuplicateDuplicate.Load();
            DuplicateGroup = new DuplicateGroupConfigTable();
            DuplicateGroup.Load();
            AreaPath = new AreaPathConfigTable();
            AreaPath.Load();
            AreaArea = new AreaAreaConfigTable();
            AreaArea.Load();
            RandomnameWomanfirst = new RandomnameWomanfirstConfigTable();
            RandomnameWomanfirst.Load();
            RandomnameManthird = new RandomnameManthirdConfigTable();
            RandomnameManthird.Load();
            RandomnameWomanthird = new RandomnameWomanthirdConfigTable();
            RandomnameWomanthird.Load();
            RandomnameMansecond = new RandomnameMansecondConfigTable();
            RandomnameMansecond.Load();
            RandomnameManfirst = new RandomnameManfirstConfigTable();
            RandomnameManfirst.Load();
            RandomnameWomansecond = new RandomnameWomansecondConfigTable();
            RandomnameWomansecond.Load();
            ConstantConstant = new ConstantConstantConfigTable();
            ConstantConstant.Load();
            BoxDrop = new BoxDropConfigTable();
            BoxDrop.Load();
            SkillSummon = new SkillSummonConfigTable();
            SkillSummon.Load();
            SkillBuff = new SkillBuffConfigTable();
            SkillBuff.Load();
            SkillSkill = new SkillSkillConfigTable();
            SkillSkill.Load();
            SrvlistServer = new SrvlistServerConfigTable();
            SrvlistServer.Load();
            SrvlistArea = new SrvlistAreaConfigTable();
            SrvlistArea.Load();
            AiAi = new AiAiConfigTable();
            AiAi.Load();
            ThingCollect = new ThingCollectConfigTable();
            ThingCollect.Load();
            ThingThing = new ThingThingConfigTable();
            ThingThing.Load();


        }
    }
	public static AttributeSuppressConfig GetAttributeSuppressCfg(int key) { if(!_gi.AttributeSuppress.configs.ContainsKey(key)) return null; return _gi.AttributeSuppress.configs[key]; }
	public static AttributeConvertConfig GetAttributeConvertCfg(int key) { if(!_gi.AttributeConvert.configs.ContainsKey(key)) return null; return _gi.AttributeConvert.configs[key]; }
	public static PkmodePkWantedConfig GetPkmodePkWantedCfg(int key) { if(!_gi.PkmodePkWanted.configs.ContainsKey(key)) return null; return _gi.PkmodePkWanted.configs[key]; }
	public static AvocationAvocationskillConfig GetAvocationAvocationskillCfg(int key) { if(!_gi.AvocationAvocationskill.configs.ContainsKey(key)) return null; return _gi.AvocationAvocationskill.configs[key]; }
	public static AvocationComposeConfig GetAvocationComposeCfg(int key) { if(!_gi.AvocationCompose.configs.ContainsKey(key)) return null; return _gi.AvocationCompose.configs[key]; }
	public static DropDropConfig GetDropDropCfg(int key) { if(!_gi.DropDrop.configs.ContainsKey(key)) return null; return _gi.DropDrop.configs[key]; }
	public static AchievementAchievementConfig GetAchievementAchievementCfg(int key) { if(!_gi.AchievementAchievement.configs.ContainsKey(key)) return null; return _gi.AchievementAchievement.configs[key]; }
	public static AchievementAchievementrewardConfig GetAchievementAchievementrewardCfg(int key) { if(!_gi.AchievementAchievementreward.configs.ContainsKey(key)) return null; return _gi.AchievementAchievementreward.configs[key]; }
	public static RoleBornConfig GetRoleBornCfg(int key) { if(!_gi.RoleBorn.configs.ContainsKey(key)) return null; return _gi.RoleBorn.configs[key]; }
	public static RoleMasterConfig GetRoleMasterCfg(int key) { if(!_gi.RoleMaster.configs.ContainsKey(key)) return null; return _gi.RoleMaster.configs[key]; }
	public static RoleAssassinConfig GetRoleAssassinCfg(int key) { if(!_gi.RoleAssassin.configs.ContainsKey(key)) return null; return _gi.RoleAssassin.configs[key]; }
	public static RoleExpConfig GetRoleExpCfg(int key) { if(!_gi.RoleExp.configs.ContainsKey(key)) return null; return _gi.RoleExp.configs[key]; }
	public static RoleShooterConfig GetRoleShooterCfg(int key) { if(!_gi.RoleShooter.configs.ContainsKey(key)) return null; return _gi.RoleShooter.configs[key]; }
	public static RoleWarriorConfig GetRoleWarriorCfg(int key) { if(!_gi.RoleWarrior.configs.ContainsKey(key)) return null; return _gi.RoleWarrior.configs[key]; }
	public static NpcNpcConfig GetNpcNpcCfg(int key) { if(!_gi.NpcNpc.configs.ContainsKey(key)) return null; return _gi.NpcNpc.configs[key]; }
	public static NpcNpcfunctionConfig GetNpcNpcfunctionCfg(int key) { if(!_gi.NpcNpcfunction.configs.ContainsKey(key)) return null; return _gi.NpcNpcfunction.configs[key]; }
	public static ItemItemConfig GetItemItemCfg(int key) { if(!_gi.ItemItem.configs.ContainsKey(key)) return null; return _gi.ItemItem.configs[key]; }
	public static TeleportBornConfig GetTeleportBornCfg(int key) { if(!_gi.TeleportBorn.configs.ContainsKey(key)) return null; return _gi.TeleportBorn.configs[key]; }
	public static TeleportSafeareaConfig GetTeleportSafeareaCfg(int key) { if(!_gi.TeleportSafearea.configs.ContainsKey(key)) return null; return _gi.TeleportSafearea.configs[key]; }
	public static TeleportTeleportConfig GetTeleportTeleportCfg(int key) { if(!_gi.TeleportTeleport.configs.ContainsKey(key)) return null; return _gi.TeleportTeleport.configs[key]; }
	public static ComposeComposeConfig GetComposeComposeCfg(int key) { if(!_gi.ComposeCompose.configs.ContainsKey(key)) return null; return _gi.ComposeCompose.configs[key]; }
	public static MapMapConfig GetMapMapCfg(int key) { if(!_gi.MapMap.configs.ContainsKey(key)) return null; return _gi.MapMap.configs[key]; }
	public static MonsterMonsterConfig GetMonsterMonsterCfg(int key) { if(!_gi.MonsterMonster.configs.ContainsKey(key)) return null; return _gi.MonsterMonster.configs[key]; }
	public static MallMallConfig GetMallMallCfg(int key) { if(!_gi.MallMall.configs.ContainsKey(key)) return null; return _gi.MallMall.configs[key]; }
	public static MallMalltypeConfig GetMallMalltypeCfg(int key) { if(!_gi.MallMalltype.configs.ContainsKey(key)) return null; return _gi.MallMalltype.configs[key]; }
	public static TasktrackerTasktrackerConfig GetTasktrackerTasktrackerCfg(int key) { if(!_gi.TasktrackerTasktracker.configs.ContainsKey(key)) return null; return _gi.TasktrackerTasktracker.configs[key]; }
	public static EquipFashionConfig GetEquipFashionCfg(int key) { if(!_gi.EquipFashion.configs.ContainsKey(key)) return null; return _gi.EquipFashion.configs[key]; }
	public static EquipSuitConfig GetEquipSuitCfg(int key) { if(!_gi.EquipSuit.configs.ContainsKey(key)) return null; return _gi.EquipSuit.configs[key]; }
	public static EquipRefineConfig GetEquipRefineCfg(int key) { if(!_gi.EquipRefine.configs.ContainsKey(key)) return null; return _gi.EquipRefine.configs[key]; }
	public static EquipEquipConfig GetEquipEquipCfg(int key) { if(!_gi.EquipEquip.configs.ContainsKey(key)) return null; return _gi.EquipEquip.configs[key]; }
	public static EquipStrengthenConfig GetEquipStrengthenCfg(int key) { if(!_gi.EquipStrengthen.configs.ContainsKey(key)) return null; return _gi.EquipStrengthen.configs[key]; }
	public static ChatChatConfig GetChatChatCfg(int key) { if(!_gi.ChatChat.configs.ContainsKey(key)) return null; return _gi.ChatChat.configs[key]; }
	public static DuplicateDuplicateConfig GetDuplicateDuplicateCfg(int key) { if(!_gi.DuplicateDuplicate.configs.ContainsKey(key)) return null; return _gi.DuplicateDuplicate.configs[key]; }
	public static DuplicateGroupConfig GetDuplicateGroupCfg(int key) { if(!_gi.DuplicateGroup.configs.ContainsKey(key)) return null; return _gi.DuplicateGroup.configs[key]; }
	public static AreaPathConfig GetAreaPathCfg(int key) { if(!_gi.AreaPath.configs.ContainsKey(key)) return null; return _gi.AreaPath.configs[key]; }
	public static AreaAreaConfig GetAreaAreaCfg(int key) { if(!_gi.AreaArea.configs.ContainsKey(key)) return null; return _gi.AreaArea.configs[key]; }
	public static RandomnameWomanfirstConfig GetRandomnameWomanfirstCfg(int key) { if(!_gi.RandomnameWomanfirst.configs.ContainsKey(key)) return null; return _gi.RandomnameWomanfirst.configs[key]; }
	public static RandomnameManthirdConfig GetRandomnameManthirdCfg(int key) { if(!_gi.RandomnameManthird.configs.ContainsKey(key)) return null; return _gi.RandomnameManthird.configs[key]; }
	public static RandomnameWomanthirdConfig GetRandomnameWomanthirdCfg(int key) { if(!_gi.RandomnameWomanthird.configs.ContainsKey(key)) return null; return _gi.RandomnameWomanthird.configs[key]; }
	public static RandomnameMansecondConfig GetRandomnameMansecondCfg(int key) { if(!_gi.RandomnameMansecond.configs.ContainsKey(key)) return null; return _gi.RandomnameMansecond.configs[key]; }
	public static RandomnameManfirstConfig GetRandomnameManfirstCfg(int key) { if(!_gi.RandomnameManfirst.configs.ContainsKey(key)) return null; return _gi.RandomnameManfirst.configs[key]; }
	public static RandomnameWomansecondConfig GetRandomnameWomansecondCfg(int key) { if(!_gi.RandomnameWomansecond.configs.ContainsKey(key)) return null; return _gi.RandomnameWomansecond.configs[key]; }
	public static ConstantConstantConfig GetConstantConstantCfg(int key) { if(!_gi.ConstantConstant.configs.ContainsKey(key)) return null; return _gi.ConstantConstant.configs[key]; }
	public static BoxDropConfig GetBoxDropCfg(int key) { if(!_gi.BoxDrop.configs.ContainsKey(key)) return null; return _gi.BoxDrop.configs[key]; }
	public static SkillSummonConfig GetSkillSummonCfg(int key) { if(!_gi.SkillSummon.configs.ContainsKey(key)) return null; return _gi.SkillSummon.configs[key]; }
	public static SkillBuffConfig GetSkillBuffCfg(int key) { if(!_gi.SkillBuff.configs.ContainsKey(key)) return null; return _gi.SkillBuff.configs[key]; }
	public static SkillSkillConfig GetSkillSkillCfg(int key) { if(!_gi.SkillSkill.configs.ContainsKey(key)) return null; return _gi.SkillSkill.configs[key]; }
	public static SrvlistServerConfig GetSrvlistServerCfg(int key) { if(!_gi.SrvlistServer.configs.ContainsKey(key)) return null; return _gi.SrvlistServer.configs[key]; }
	public static SrvlistAreaConfig GetSrvlistAreaCfg(int key) { if(!_gi.SrvlistArea.configs.ContainsKey(key)) return null; return _gi.SrvlistArea.configs[key]; }
	public static AiAiConfig GetAiAiCfg(int key) { if(!_gi.AiAi.configs.ContainsKey(key)) return null; return _gi.AiAi.configs[key]; }
	public static ThingCollectConfig GetThingCollectCfg(int key) { if(!_gi.ThingCollect.configs.ContainsKey(key)) return null; return _gi.ThingCollect.configs[key]; }
	public static ThingThingConfig GetThingThingCfg(int key) { if(!_gi.ThingThing.configs.ContainsKey(key)) return null; return _gi.ThingThing.configs[key]; }

}
