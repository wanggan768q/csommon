//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: MailRpc.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcMailHeadAsk")]
  public partial class MailRpcMailHeadAsk : global::ProtoBuf.IExtensible
  {
    public MailRpcMailHeadAsk() {}
    
    private int _Count = (int)0;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Count", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int Count
    {
      get { return _Count; }
      set { _Count = value; }
    }
    private long _UId = (long)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"UId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((long)-1)]
    public long UId
    {
      get { return _UId; }
      set { _UId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcMailHeadReply")]
  public partial class MailRpcMailHeadReply : global::ProtoBuf.IExtensible
  {
    public MailRpcMailHeadReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private readonly global::System.Collections.Generic.List<MailHeadObj> _MailHeadList = new global::System.Collections.Generic.List<MailHeadObj>();
    [global::ProtoBuf.ProtoMember(2, Name=@"MailHeadList", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<MailHeadObj> MailHeadList
    {
      get { return _MailHeadList; }
    }
  
    private int _MaxCount = (int)0;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"MaxCount", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int MaxCount
    {
      get { return _MaxCount; }
      set { _MaxCount = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcDelMailAsk")]
  public partial class MailRpcDelMailAsk : global::ProtoBuf.IExtensible
  {
    public MailRpcDelMailAsk() {}
    
    private readonly global::System.Collections.Generic.List<long> _UidList = new global::System.Collections.Generic.List<long>();
    [global::ProtoBuf.ProtoMember(1, Name=@"UidList", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    public global::System.Collections.Generic.List<long> UidList
    {
      get { return _UidList; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcDelMailReply")]
  public partial class MailRpcDelMailReply : global::ProtoBuf.IExtensible
  {
    public MailRpcDelMailReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private readonly global::System.Collections.Generic.List<long> _UidList = new global::System.Collections.Generic.List<long>();
    [global::ProtoBuf.ProtoMember(2, Name=@"UidList", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    public global::System.Collections.Generic.List<long> UidList
    {
      get { return _UidList; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcOpenMailAsk")]
  public partial class MailRpcOpenMailAsk : global::ProtoBuf.IExtensible
  {
    public MailRpcOpenMailAsk() {}
    
    private long _UId = (long)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"UId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((long)-1)]
    public long UId
    {
      get { return _UId; }
      set { _UId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcOpenMailReply")]
  public partial class MailRpcOpenMailReply : global::ProtoBuf.IExtensible
  {
    public MailRpcOpenMailReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private MailBodyObj _MailBody = null;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"MailBody", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public MailBodyObj MailBody
    {
      get { return _MailBody; }
      set { _MailBody = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcGetRewardAsk")]
  public partial class MailRpcGetRewardAsk : global::ProtoBuf.IExtensible
  {
    public MailRpcGetRewardAsk() {}
    
    private long _UId = (long)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"UId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((long)-1)]
    public long UId
    {
      get { return _UId; }
      set { _UId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcGetRewardReply")]
  public partial class MailRpcGetRewardReply : global::ProtoBuf.IExtensible
  {
    public MailRpcGetRewardReply() {}
    
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
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcNewMailNotify")]
  public partial class MailRpcNewMailNotify : global::ProtoBuf.IExtensible
  {
    public MailRpcNewMailNotify() {}
    
    private readonly global::System.Collections.Generic.List<MailHeadObj> _MailHeadList = new global::System.Collections.Generic.List<MailHeadObj>();
    [global::ProtoBuf.ProtoMember(1, Name=@"MailHeadList", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<MailHeadObj> MailHeadList
    {
      get { return _MailHeadList; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcOneKeyGetRewardAsk")]
  public partial class MailRpcOneKeyGetRewardAsk : global::ProtoBuf.IExtensible
  {
    public MailRpcOneKeyGetRewardAsk() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MailRpcOneKeyGetRewardReply")]
  public partial class MailRpcOneKeyGetRewardReply : global::ProtoBuf.IExtensible
  {
    public MailRpcOneKeyGetRewardReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private readonly global::System.Collections.Generic.List<long> _UidList = new global::System.Collections.Generic.List<long>();
    [global::ProtoBuf.ProtoMember(2, Name=@"UidList", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    public global::System.Collections.Generic.List<long> UidList
    {
      get { return _UidList; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}