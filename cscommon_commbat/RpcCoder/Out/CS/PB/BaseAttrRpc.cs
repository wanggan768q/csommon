//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: BaseAttrRpc.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcSyncDataAsk")]
  public partial class BaseAttrRpcSyncDataAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcSyncDataAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcSyncDataReply")]
  public partial class BaseAttrRpcSyncDataReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcSyncDataReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcGetRankRewardAsk")]
  public partial class BaseAttrRpcGetRankRewardAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcGetRankRewardAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcGetRankRewardReply")]
  public partial class BaseAttrRpcGetRankRewardReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcGetRankRewardReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcUpGradeRankAsk")]
  public partial class BaseAttrRpcUpGradeRankAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcUpGradeRankAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcUpGradeRankReply")]
  public partial class BaseAttrRpcUpGradeRankReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcUpGradeRankReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcChooseRoleAsk")]
  public partial class BaseAttrRpcChooseRoleAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcChooseRoleAsk() {}
    
    private int _Prof = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Prof", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Prof
    {
      get { return _Prof; }
      set { _Prof = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcChooseRoleReply")]
  public partial class BaseAttrRpcChooseRoleReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcChooseRoleReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private int _Prof = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Prof", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Prof
    {
      get { return _Prof; }
      set { _Prof = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcLevelUpAsk")]
  public partial class BaseAttrRpcLevelUpAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcLevelUpAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcLevelUpReply")]
  public partial class BaseAttrRpcLevelUpReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcLevelUpReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcGetTimerAsk")]
  public partial class BaseAttrRpcGetTimerAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcGetTimerAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcGetTimerReply")]
  public partial class BaseAttrRpcGetTimerReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcGetTimerReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private long _Timer = (long)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Timer", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((long)-1)]
    public long Timer
    {
      get { return _Timer; }
      set { _Timer = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcReviveAsk")]
  public partial class BaseAttrRpcReviveAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcReviveAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcReviveReply")]
  public partial class BaseAttrRpcReviveReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcReviveReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcQueryEquipAsk")]
  public partial class BaseAttrRpcQueryEquipAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcQueryEquipAsk() {}
    
    private long _UserId = (long)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"UserId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((long)-1)]
    public long UserId
    {
      get { return _UserId; }
      set { _UserId = value; }
    }
    private int _Pos = (int)-1;
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"Pos", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Pos
    {
      get { return _Pos; }
      set { _Pos = value; }
    }
    private int _TemplateID = (int)-1;
    [global::ProtoBuf.ProtoMember(7, IsRequired = false, Name=@"TemplateID", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int TemplateID
    {
      get { return _TemplateID; }
      set { _TemplateID = value; }
    }
    private long _Index = (long)-1;
    [global::ProtoBuf.ProtoMember(8, IsRequired = false, Name=@"Index", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((long)-1)]
    public long Index
    {
      get { return _Index; }
      set { _Index = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcQueryEquipReply")]
  public partial class BaseAttrRpcQueryEquipReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcQueryEquipReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private BagEquipObj _EquipData = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"EquipData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public BagEquipObj EquipData
    {
      get { return _EquipData; }
      set { _EquipData = value; }
    }
    private BaseAttrRpcGridInfo _GridData = null;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"GridData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public BaseAttrRpcGridInfo GridData
    {
      get { return _GridData; }
      set { _GridData = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcUpdateNewbieGuideAsk")]
  public partial class BaseAttrRpcUpdateNewbieGuideAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcUpdateNewbieGuideAsk() {}
    
    private int _GroupId = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"GroupId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int GroupId
    {
      get { return _GroupId; }
      set { _GroupId = value; }
    }
    private int _Step = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Step", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Step
    {
      get { return _Step; }
      set { _Step = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcUpdateNewbieGuideReply")]
  public partial class BaseAttrRpcUpdateNewbieGuideReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcUpdateNewbieGuideReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcGridInfo")]
  public partial class BaseAttrRpcGridInfo : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcGridInfo() {}
    
    private int _TemplateID = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"TemplateID", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int TemplateID
    {
      get { return _TemplateID; }
      set { _TemplateID = value; }
    }
    private int _Num = (int)0;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Num", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int Num
    {
      get { return _Num; }
      set { _Num = value; }
    }
    private int _ItemType = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"ItemType", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int ItemType
    {
      get { return _ItemType; }
      set { _ItemType = value; }
    }
    private int _Pos = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"Pos", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Pos
    {
      get { return _Pos; }
      set { _Pos = value; }
    }
    private int _Value = (int)-1;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"Value", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Value
    {
      get { return _Value; }
      set { _Value = value; }
    }
    private long _Index = (long)-1;
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"Index", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((long)-1)]
    public long Index
    {
      get { return _Index; }
      set { _Index = value; }
    }
    private bool _Bind = (bool)false;
    [global::ProtoBuf.ProtoMember(7, IsRequired = false, Name=@"Bind", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue((bool)false)]
    public bool Bind
    {
      get { return _Bind; }
      set { _Bind = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcSysTipsNotify")]
  public partial class BaseAttrRpcSysTipsNotify : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcSysTipsNotify() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcChangPKStateAsk")]
  public partial class BaseAttrRpcChangPKStateAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcChangPKStateAsk() {}
    
    private int _ChangState = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"ChangState", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int ChangState
    {
      get { return _ChangState; }
      set { _ChangState = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcChangPKStateReply")]
  public partial class BaseAttrRpcChangPKStateReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcChangPKStateReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcChangePKProtectAsk")]
  public partial class BaseAttrRpcChangePKProtectAsk : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcChangePKProtectAsk() {}
    
    private readonly global::System.Collections.Generic.List<KeyValue2IntBool> _ProtectList = new global::System.Collections.Generic.List<KeyValue2IntBool>();
    [global::ProtoBuf.ProtoMember(1, Name=@"ProtectList", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<KeyValue2IntBool> ProtectList
    {
      get { return _ProtectList; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"BaseAttrRpcChangePKProtectReply")]
  public partial class BaseAttrRpcChangePKProtectReply : global::ProtoBuf.IExtensible
  {
    public BaseAttrRpcChangePKProtectReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}