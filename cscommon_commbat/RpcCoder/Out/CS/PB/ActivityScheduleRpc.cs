//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: ActivityScheduleRpc.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcSyncDataAsk")]
  public partial class ActivityScheduleRpcSyncDataAsk : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcSyncDataAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcSyncDataReply")]
  public partial class ActivityScheduleRpcSyncDataReply : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcSyncDataReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private readonly global::System.Collections.Generic.List<ActivityNpcData> _ThiefData = new global::System.Collections.Generic.List<ActivityNpcData>();
    [global::ProtoBuf.ProtoMember(2, Name=@"ThiefData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ActivityNpcData> ThiefData
    {
      get { return _ThiefData; }
    }
  
    private readonly global::System.Collections.Generic.List<ActivityNpcData> _SubdueMonsterData = new global::System.Collections.Generic.List<ActivityNpcData>();
    [global::ProtoBuf.ProtoMember(3, Name=@"SubdueMonsterData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ActivityNpcData> SubdueMonsterData
    {
      get { return _SubdueMonsterData; }
    }
  
    private readonly global::System.Collections.Generic.List<WorldBossObj> _WorldBossData = new global::System.Collections.Generic.List<WorldBossObj>();
    [global::ProtoBuf.ProtoMember(4, Name=@"WorldBossData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<WorldBossObj> WorldBossData
    {
      get { return _WorldBossData; }
    }
  
    private readonly global::System.Collections.Generic.List<WorldBossRankObj> _WorldBossRank = new global::System.Collections.Generic.List<WorldBossRankObj>();
    [global::ProtoBuf.ProtoMember(5, Name=@"WorldBossRank", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<WorldBossRankObj> WorldBossRank
    {
      get { return _WorldBossRank; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcThiefBeOpenedNotify")]
  public partial class ActivityScheduleRpcThiefBeOpenedNotify : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcThiefBeOpenedNotify() {}
    
    private ActivityNpcData _ThiefData = null;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"ThiefData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public ActivityNpcData ThiefData
    {
      get { return _ThiefData; }
      set { _ThiefData = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcThiefRefreshNotify")]
  public partial class ActivityScheduleRpcThiefRefreshNotify : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcThiefRefreshNotify() {}
    
    private readonly global::System.Collections.Generic.List<ActivityNpcData> _ThiefData = new global::System.Collections.Generic.List<ActivityNpcData>();
    [global::ProtoBuf.ProtoMember(1, Name=@"ThiefData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ActivityNpcData> ThiefData
    {
      get { return _ThiefData; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcThiefOpenMonsterAsk")]
  public partial class ActivityScheduleRpcThiefOpenMonsterAsk : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcThiefOpenMonsterAsk() {}
    
    private ActivityNpcData _ThiefData = null;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"ThiefData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public ActivityNpcData ThiefData
    {
      get { return _ThiefData; }
      set { _ThiefData = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcThiefOpenMonsterReply")]
  public partial class ActivityScheduleRpcThiefOpenMonsterReply : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcThiefOpenMonsterReply() {}
    
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
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcSubdueMonsterEnterAsk")]
  public partial class ActivityScheduleRpcSubdueMonsterEnterAsk : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcSubdueMonsterEnterAsk() {}
    
    private ActivityNpcData _SubdueMonsterData = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"SubdueMonsterData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public ActivityNpcData SubdueMonsterData
    {
      get { return _SubdueMonsterData; }
      set { _SubdueMonsterData = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcSubdueMonsterEnterReply")]
  public partial class ActivityScheduleRpcSubdueMonsterEnterReply : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcSubdueMonsterEnterReply() {}
    
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
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcSubdueMonsterBeOpenedNotify")]
  public partial class ActivityScheduleRpcSubdueMonsterBeOpenedNotify : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcSubdueMonsterBeOpenedNotify() {}
    
    private ActivityNpcData _SubdueMonsterData = null;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"SubdueMonsterData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public ActivityNpcData SubdueMonsterData
    {
      get { return _SubdueMonsterData; }
      set { _SubdueMonsterData = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcSubdueMonsterRefreshNotify")]
  public partial class ActivityScheduleRpcSubdueMonsterRefreshNotify : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcSubdueMonsterRefreshNotify() {}
    
    private readonly global::System.Collections.Generic.List<ActivityNpcData> _SubdueMonsterData = new global::System.Collections.Generic.List<ActivityNpcData>();
    [global::ProtoBuf.ProtoMember(1, Name=@"SubdueMonsterData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<ActivityNpcData> SubdueMonsterData
    {
      get { return _SubdueMonsterData; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcWorldBossEnterDungeonAsk")]
  public partial class ActivityScheduleRpcWorldBossEnterDungeonAsk : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcWorldBossEnterDungeonAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcWorldBossEnterDungeonReply")]
  public partial class ActivityScheduleRpcWorldBossEnterDungeonReply : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcWorldBossEnterDungeonReply() {}
    
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
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcWorldBossSyncDataAsk")]
  public partial class ActivityScheduleRpcWorldBossSyncDataAsk : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcWorldBossSyncDataAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"ActivityScheduleRpcWorldBossSyncDataReply")]
  public partial class ActivityScheduleRpcWorldBossSyncDataReply : global::ProtoBuf.IExtensible
  {
    public ActivityScheduleRpcWorldBossSyncDataReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private readonly global::System.Collections.Generic.List<WorldBossObj> _WorldBossData = new global::System.Collections.Generic.List<WorldBossObj>();
    [global::ProtoBuf.ProtoMember(2, Name=@"WorldBossData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<WorldBossObj> WorldBossData
    {
      get { return _WorldBossData; }
    }
  
    private readonly global::System.Collections.Generic.List<WorldBossRankObj> _WorldBossRank = new global::System.Collections.Generic.List<WorldBossRankObj>();
    [global::ProtoBuf.ProtoMember(3, Name=@"WorldBossRank", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<WorldBossRankObj> WorldBossRank
    {
      get { return _WorldBossRank; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}