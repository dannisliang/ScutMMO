//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: ProtoBuffer/Mall.proto
// Note: requires additional types generated from: ProtoBuffer/ComProtocol.proto
// Note: requires additional types generated from: ProtoBuffer/ClientToServerCmd.proto
// Note: requires additional types generated from: Common/ComDefine.proto
namespace ProtoBuf
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Mall_AskData")]
  public partial class Mall_AskData : global::ProtoBuf.IExtensible
  {
    public Mall_AskData() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MallProtoInfo")]
  public partial class MallProtoInfo : global::ProtoBuf.IExtensible
  {
    public MallProtoInfo() {}
    
    private uint _mall_id = default(uint);
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"mall_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint mall_id
    {
      get { return _mall_id; }
      set { _mall_id = value; }
    }
    private uint _amount = default(uint);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"amount", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint amount
    {
      get { return _amount; }
      set { _amount = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Mall_AskDataRsp")]
  public partial class Mall_AskDataRsp : global::ProtoBuf.IExtensible
  {
    public Mall_AskDataRsp() {}
    
    private readonly global::System.Collections.Generic.List<ProtoBuf.MallProtoInfo> _data = new global::System.Collections.Generic.List<ProtoBuf.MallProtoInfo>();
    [global::ProtoBuf.ProtoMember(1, Name=@"data", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ProtoBuf.MallProtoInfo> data
    {
      get { return _data; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Mall_GetTimeReq")]
  public partial class Mall_GetTimeReq : global::ProtoBuf.IExtensible
  {
    public Mall_GetTimeReq() {}
    
    private uint _mall_id;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"mall_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public uint mall_id
    {
      get { return _mall_id; }
      set { _mall_id = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Mall_GetTimeRsp")]
  public partial class Mall_GetTimeRsp : global::ProtoBuf.IExtensible
  {
    public Mall_GetTimeRsp() {}
    
    private uint _mall_id;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"mall_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public uint mall_id
    {
      get { return _mall_id; }
      set { _mall_id = value; }
    }
    private ulong _time = default(ulong);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"time", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(ulong))]
    public ulong time
    {
      get { return _time; }
      set { _time = value; }
    }
    private ulong _open_time = default(ulong);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"open_time", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(ulong))]
    public ulong open_time
    {
      get { return _open_time; }
      set { _open_time = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Mall_BuyReq")]
  public partial class Mall_BuyReq : global::ProtoBuf.IExtensible
  {
    public Mall_BuyReq() {}
    
    private uint _mall_id;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"mall_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public uint mall_id
    {
      get { return _mall_id; }
      set { _mall_id = value; }
    }
    private uint _count = default(uint);
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"count", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
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
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Mall_BuyRsp")]
  public partial class Mall_BuyRsp : global::ProtoBuf.IExtensible
  {
    public Mall_BuyRsp() {}
    
    private int _retcode;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"retcode", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int retcode
    {
      get { return _retcode; }
      set { _retcode = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Mall_Buy_VerifyReq")]
  public partial class Mall_Buy_VerifyReq : global::ProtoBuf.IExtensible
  {
    public Mall_Buy_VerifyReq() {}
    
    private uint _char_id = default(uint);
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"char_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint char_id
    {
      get { return _char_id; }
      set { _char_id = value; }
    }
    private uint _mall_id;
    [global::ProtoBuf.ProtoMember(2, IsRequired = true, Name=@"mall_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public uint mall_id
    {
      get { return _mall_id; }
      set { _mall_id = value; }
    }
    private uint _count = default(uint);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"count", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
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
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Mall_Buy_VerifyRsp")]
  public partial class Mall_Buy_VerifyRsp : global::ProtoBuf.IExtensible
  {
    public Mall_Buy_VerifyRsp() {}
    
    private uint _char_id;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"char_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public uint char_id
    {
      get { return _char_id; }
      set { _char_id = value; }
    }
    private int _result;
    [global::ProtoBuf.ProtoMember(2, IsRequired = true, Name=@"result", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int result
    {
      get { return _result; }
      set { _result = value; }
    }
    private uint _mall_id = default(uint);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"mall_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint mall_id
    {
      get { return _mall_id; }
      set { _mall_id = value; }
    }
    private uint _count = default(uint);
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"count", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
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
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"Mall_Chang_Notify")]
  public partial class Mall_Chang_Notify : global::ProtoBuf.IExtensible
  {
    public Mall_Chang_Notify() {}
    
    private uint _operate_type;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"operate_type", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public uint operate_type
    {
      get { return _operate_type; }
      set { _operate_type = value; }
    }
    private uint _char_id;
    [global::ProtoBuf.ProtoMember(2, IsRequired = true, Name=@"char_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public uint char_id
    {
      get { return _char_id; }
      set { _char_id = value; }
    }
    private uint _mall_id = default(uint);
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"mall_id", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint mall_id
    {
      get { return _mall_id; }
      set { _mall_id = value; }
    }
    private uint _count = default(uint);
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"count", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(uint))]
    public uint count
    {
      get { return _count; }
      set { _count = value; }
    }
    private ulong _time = default(ulong);
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"time", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(ulong))]
    public ulong time
    {
      get { return _time; }
      set { _time = value; }
    }
    private ulong _open_time = default(ulong);
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"open_time", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    [global::System.ComponentModel.DefaultValue(default(ulong))]
    public ulong open_time
    {
      get { return _open_time; }
      set { _open_time = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}