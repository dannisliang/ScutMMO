//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: ProtoBuffer/Achievement.proto
// Note: requires additional types generated from: ProtoBuffer/ComProtocol.proto
// Note: requires additional types generated from: ProtoBuffer/ClientToServerCmd.proto
// Note: requires additional types generated from: Common/ComDefine.proto
namespace ProtoBuf
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"CGGetAchievementInfoReq")]
  public partial class CGGetAchievementInfoReq : global::ProtoBuf.IExtensible
  {
    public CGGetAchievementInfoReq() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ClientAchievementSortInfo")]
  public partial class ClientAchievementSortInfo : global::ProtoBuf.IExtensible
  {
    public ClientAchievementSortInfo() {}
    
    private uint _sortType = default(uint);
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"sortType", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint sortType
    {
      get { return _sortType; }
      set { _sortType = value; }
    }
    private readonly global::System.Collections.Generic.List<ProtoBuf.ClientAchievementInfo> _achievementInfoList = new global::System.Collections.Generic.List<ProtoBuf.ClientAchievementInfo>();
    [global::ProtoBuf.ProtoMember(2, Name=@"achievementInfoList", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ProtoBuf.ClientAchievementInfo> achievementInfoList
    {
      get { return _achievementInfoList; }
    }
  
    private uint _achievementProgress = default(uint);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"achievementProgress", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint achievementProgress
    {
      get { return _achievementProgress; }
      set { _achievementProgress = value; }
    }
    private uint _achievementReward = default(uint);
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"achievementReward", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint achievementReward
    {
      get { return _achievementReward; }
      set { _achievementReward = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"GCGetAchievementInfoRsp")]
  public partial class GCGetAchievementInfoRsp : global::ProtoBuf.IExtensible
  {
    public GCGetAchievementInfoRsp() {}
    
    private readonly global::System.Collections.Generic.List<ProtoBuf.ClientAchievementSortInfo> _achievementList = new global::System.Collections.Generic.List<ProtoBuf.ClientAchievementSortInfo>();
    [global::ProtoBuf.ProtoMember(1, Name=@"achievementList", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ProtoBuf.ClientAchievementSortInfo> achievementList
    {
      get { return _achievementList; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"CGGetAchievementRewardReq")]
  public partial class CGGetAchievementRewardReq : global::ProtoBuf.IExtensible
  {
    public CGGetAchievementRewardReq() {}
    
    private uint _sortType = default(uint);
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"sortType", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint sortType
    {
      get { return _sortType; }
      set { _sortType = value; }
    }
    private uint _achievementId = default(uint);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"achievementId", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint achievementId
    {
      get { return _achievementId; }
      set { _achievementId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"GCGetAchievementRewardRsp")]
  public partial class GCGetAchievementRewardRsp : global::ProtoBuf.IExtensible
  {
    public GCGetAchievementRewardRsp() {}
    
    private uint _sortType = default(uint);
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"sortType", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint sortType
    {
      get { return _sortType; }
      set { _sortType = value; }
    }
    private uint _achievementId = default(uint);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"achievementId", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint achievementId
    {
      get { return _achievementId; }
      set { _achievementId = value; }
    }
    private uint _ret = default(uint);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"ret", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint ret
    {
      get { return _ret; }
      set { _ret = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"CGGetAchievementBoxRewardReq")]
  public partial class CGGetAchievementBoxRewardReq : global::ProtoBuf.IExtensible
  {
    public CGGetAchievementBoxRewardReq() {}
    
    private uint _prizeId = default(uint);
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"prizeId", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint prizeId
    {
      get { return _prizeId; }
      set { _prizeId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"CGGetAchievementBoxRewardRsp")]
  public partial class CGGetAchievementBoxRewardRsp : global::ProtoBuf.IExtensible
  {
    public CGGetAchievementBoxRewardRsp() {}
    
    private uint _prizeId = default(uint);
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"prizeId", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint prizeId
    {
      get { return _prizeId; }
      set { _prizeId = value; }
    }
    private uint _ret = default(uint);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"ret", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint ret
    {
      get { return _ret; }
      set { _ret = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ClientAchievementInfo")]
  public partial class ClientAchievementInfo : global::ProtoBuf.IExtensible
  {
    public ClientAchievementInfo() {}
    
    private uint _id = default(uint);
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint id
    {
      get { return _id; }
      set { _id = value; }
    }
    private uint _status = default(uint);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"status", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint status
    {
      get { return _status; }
      set { _status = value; }
    }
    private uint _completeCount = default(uint);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"completeCount", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint completeCount
    {
      get { return _completeCount; }
      set { _completeCount = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"GCAchievementNotify")]
  public partial class GCAchievementNotify : global::ProtoBuf.IExtensible
  {
    public GCAchievementNotify() {}
    
    private readonly global::System.Collections.Generic.List<ProtoBuf.ClientAchievementInfo> _changeAchievementList = new global::System.Collections.Generic.List<ProtoBuf.ClientAchievementInfo>();
    [global::ProtoBuf.ProtoMember(1, Name=@"changeAchievementList", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ProtoBuf.ClientAchievementInfo> changeAchievementList
    {
      get { return _changeAchievementList; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"WGAchievementNotify")]
  public partial class WGAchievementNotify : global::ProtoBuf.IExtensible
  {
    public WGAchievementNotify() {}
    
    private uint _charId = default(uint);
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"charId", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint charId
    {
      get { return _charId; }
      set { _charId = value; }
    }
    private uint _type = default(uint);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint type
    {
      get { return _type; }
      set { _type = value; }
    }
    private uint _parameterType = default(uint);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"parameterType", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint parameterType
    {
      get { return _parameterType; }
      set { _parameterType = value; }
    }
    private uint _parameter = default(uint);
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"parameter", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint parameter
    {
      get { return _parameter; }
      set { _parameter = value; }
    }
    private uint _count = default(uint);
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"count", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint count
    {
      get { return _count; }
      set { _count = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}