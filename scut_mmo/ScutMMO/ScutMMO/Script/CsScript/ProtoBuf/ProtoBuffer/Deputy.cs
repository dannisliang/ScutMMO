//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: ProtoBuffer/Deputy.proto
// Note: requires additional types generated from: ProtoBuffer/ComProtocol.proto
// Note: requires additional types generated from: ProtoBuffer/ClientToServerCmd.proto
// Note: requires additional types generated from: Common/ComDefine.proto
namespace ProtoBuf
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_CollectSkillInfoReq")]
  public partial class Deputy_CollectSkillInfoReq : global::ProtoBuf.IExtensible
  {
    public Deputy_CollectSkillInfoReq() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_CollectSkillInfoRsp")]
  public partial class Deputy_CollectSkillInfoRsp : global::ProtoBuf.IExtensible
  {
    public Deputy_CollectSkillInfoRsp() {}
    
    private readonly global::System.Collections.Generic.List<ProtoBuf.SingleDeputyDBData> _data = new global::System.Collections.Generic.List<ProtoBuf.SingleDeputyDBData>();
    [global::ProtoBuf.ProtoMember(1, Name=@"data", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ProtoBuf.SingleDeputyDBData> data
    {
      get { return _data; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_MakeSkillInfoReq")]
  public partial class Deputy_MakeSkillInfoReq : global::ProtoBuf.IExtensible
  {
    public Deputy_MakeSkillInfoReq() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_MakeSkillInfoRsp")]
  public partial class Deputy_MakeSkillInfoRsp : global::ProtoBuf.IExtensible
  {
    public Deputy_MakeSkillInfoRsp() {}
    
    private readonly global::System.Collections.Generic.List<ProtoBuf.SingleDeputyDBData> _data = new global::System.Collections.Generic.List<ProtoBuf.SingleDeputyDBData>();
    [global::ProtoBuf.ProtoMember(1, Name=@"data", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ProtoBuf.SingleDeputyDBData> data
    {
      get { return _data; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_UpgradeCollectSkillReq")]
  public partial class Deputy_UpgradeCollectSkillReq : global::ProtoBuf.IExtensible
  {
    public Deputy_UpgradeCollectSkillReq() {}
    
    private int _collect_type;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"collect_type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int collect_type
    {
      get { return _collect_type; }
      set { _collect_type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_UpgradeCollectSkillRsp")]
  public partial class Deputy_UpgradeCollectSkillRsp : global::ProtoBuf.IExtensible
  {
    public Deputy_UpgradeCollectSkillRsp() {}
    
    private int _retcode;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"retcode", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int retcode
    {
      get { return _retcode; }
      set { _retcode = value; }
    }
    private int _collect_type = default(int);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"collect_type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int collect_type
    {
      get { return _collect_type; }
      set { _collect_type = value; }
    }
    private int _level = default(int);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"level", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int level
    {
      get { return _level; }
      set { _level = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_RefineMakeSkillReq")]
  public partial class Deputy_RefineMakeSkillReq : global::ProtoBuf.IExtensible
  {
    public Deputy_RefineMakeSkillReq() {}
    
    private int _make_type;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"make_type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int make_type
    {
      get { return _make_type; }
      set { _make_type = value; }
    }
    private int _refine_type;
    [global::ProtoBuf.ProtoMember(2, IsRequired = true, Name=@"refine_type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int refine_type
    {
      get { return _refine_type; }
      set { _refine_type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_RefineMakeSkillRsp")]
  public partial class Deputy_RefineMakeSkillRsp : global::ProtoBuf.IExtensible
  {
    public Deputy_RefineMakeSkillRsp() {}
    
    private int _retcode;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"retcode", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int retcode
    {
      get { return _retcode; }
      set { _retcode = value; }
    }
    private int _make_type = default(int);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"make_type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int make_type
    {
      get { return _make_type; }
      set { _make_type = value; }
    }
    private int _level = default(int);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"level", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int level
    {
      get { return _level; }
      set { _level = value; }
    }
    private int _exp = default(int);
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"exp", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int exp
    {
      get { return _exp; }
      set { _exp = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_CollectOperateReq")]
  public partial class Deputy_CollectOperateReq : global::ProtoBuf.IExtensible
  {
    public Deputy_CollectOperateReq() {}
    
    private uint _collect_cid;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"collect_cid", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public uint collect_cid
    {
      get { return _collect_cid; }
      set { _collect_cid = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_CollectOperateRsp")]
  public partial class Deputy_CollectOperateRsp : global::ProtoBuf.IExtensible
  {
    public Deputy_CollectOperateRsp() {}
    
    private int _retcode;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"retcode", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int retcode
    {
      get { return _retcode; }
      set { _retcode = value; }
    }
    private int _collect_type = default(int);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"collect_type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int collect_type
    {
      get { return _collect_type; }
      set { _collect_type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_MakeOperateReq")]
  public partial class Deputy_MakeOperateReq : global::ProtoBuf.IExtensible
  {
    public Deputy_MakeOperateReq() {}
    
    private int _make_id;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"make_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int make_id
    {
      get { return _make_id; }
      set { _make_id = value; }
    }
    private int _reel_id = default(int);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"reel_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int reel_id
    {
      get { return _reel_id; }
      set { _reel_id = value; }
    }
    private int _make_num = default(int);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"make_num", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int make_num
    {
      get { return _make_num; }
      set { _make_num = value; }
    }
    private int _item_idx = default(int);
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"item_idx", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int item_idx
    {
      get { return _item_idx; }
      set { _item_idx = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_MakeOperateRsp")]
  public partial class Deputy_MakeOperateRsp : global::ProtoBuf.IExtensible
  {
    public Deputy_MakeOperateRsp() {}
    
    private int _retcode;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"retcode", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int retcode
    {
      get { return _retcode; }
      set { _retcode = value; }
    }
    private int _make_id = default(int);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"make_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(int))]
    public int make_id
    {
      get { return _make_id; }
      set { _make_id = value; }
    }
    private uint _item_id = default(uint);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"item_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint item_id
    {
      get { return _item_id; }
      set { _item_id = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_CollectNotify")]
  public partial class Deputy_CollectNotify : global::ProtoBuf.IExtensible
  {
    public Deputy_CollectNotify() {}
    
    private int _collect_type;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"collect_type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int collect_type
    {
      get { return _collect_type; }
      set { _collect_type = value; }
    }
    private int _state;
    [global::ProtoBuf.ProtoMember(2, IsRequired = true, Name=@"state", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int state
    {
      get { return _state; }
      set { _state = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Deputy_CollectEnergyUpdate")]
  public partial class Deputy_CollectEnergyUpdate : global::ProtoBuf.IExtensible
  {
    public Deputy_CollectEnergyUpdate() {}
    
    private int _collect_type;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"collect_type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int collect_type
    {
      get { return _collect_type; }
      set { _collect_type = value; }
    }
    private int _energy;
    [global::ProtoBuf.ProtoMember(2, IsRequired = true, Name=@"energy", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int energy
    {
      get { return _energy; }
      set { _energy = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}