//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: DungeonRpc.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"DungeonRpcEnterAsk")]
  public partial class DungeonRpcEnterAsk : global::ProtoBuf.IExtensible
  {
    public DungeonRpcEnterAsk() {}
    
    private int _DungeonId = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"DungeonId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int DungeonId
    {
      get { return _DungeonId; }
      set { _DungeonId = value; }
    }
    private int _DungeonType = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"DungeonType", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int DungeonType
    {
      get { return _DungeonType; }
      set { _DungeonType = value; }
    }
    private int _BirthPoint = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"BirthPoint", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int BirthPoint
    {
      get { return _BirthPoint; }
      set { _BirthPoint = value; }
    }
    private int _FaceDir = (int)-1;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"FaceDir", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int FaceDir
    {
      get { return _FaceDir; }
      set { _FaceDir = value; }
    }
    private int _GuildId = (int)-1;
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"GuildId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int GuildId
    {
      get { return _GuildId; }
      set { _GuildId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"DungeonRpcEnterReply")]
  public partial class DungeonRpcEnterReply : global::ProtoBuf.IExtensible
  {
    public DungeonRpcEnterReply() {}
    
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
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"DungeonRpcOpenNotify")]
  public partial class DungeonRpcOpenNotify : global::ProtoBuf.IExtensible
  {
    public DungeonRpcOpenNotify() {}
    
    private string _DungeonKey = "";
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"DungeonKey", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue("")]
    public string DungeonKey
    {
      get { return _DungeonKey; }
      set { _DungeonKey = value; }
    }
    private string _Host = "";
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Host", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue("")]
    public string Host
    {
      get { return _Host; }
      set { _Host = value; }
    }
    private int _Port = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Port", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Port
    {
      get { return _Port; }
      set { _Port = value; }
    }
    private int _DungeonId = (int)-1;
    [global::ProtoBuf.ProtoMember(9, IsRequired = false, Name=@"DungeonId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int DungeonId
    {
      get { return _DungeonId; }
      set { _DungeonId = value; }
    }
    private int _DungeonType = (int)-1;
    [global::ProtoBuf.ProtoMember(10, IsRequired = false, Name=@"DungeonType", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int DungeonType
    {
      get { return _DungeonType; }
      set { _DungeonType = value; }
    }
    private int _GuildId = (int)-1;
    [global::ProtoBuf.ProtoMember(11, IsRequired = false, Name=@"GuildId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int GuildId
    {
      get { return _GuildId; }
      set { _GuildId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"DungeonRpcTryEnterAsk")]
  public partial class DungeonRpcTryEnterAsk : global::ProtoBuf.IExtensible
  {
    public DungeonRpcTryEnterAsk() {}
    
    private int _DungeonId = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"DungeonId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int DungeonId
    {
      get { return _DungeonId; }
      set { _DungeonId = value; }
    }
    private int _BirthPoint = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"BirthPoint", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int BirthPoint
    {
      get { return _BirthPoint; }
      set { _BirthPoint = value; }
    }
    private int _FaceDir = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"FaceDir", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int FaceDir
    {
      get { return _FaceDir; }
      set { _FaceDir = value; }
    }
    private int _GuildId = (int)-1;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"GuildId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int GuildId
    {
      get { return _GuildId; }
      set { _GuildId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"DungeonRpcTryEnterReply")]
  public partial class DungeonRpcTryEnterReply : global::ProtoBuf.IExtensible
  {
    public DungeonRpcTryEnterReply() {}
    
    private int _Result = (int)-9999;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Result", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-9999)]
    public int Result
    {
      get { return _Result; }
      set { _Result = value; }
    }
    private int _DungeonId = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"DungeonId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int DungeonId
    {
      get { return _DungeonId; }
      set { _DungeonId = value; }
    }
    private int _BirthPoint = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"BirthPoint", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int BirthPoint
    {
      get { return _BirthPoint; }
      set { _BirthPoint = value; }
    }
    private int _FaceDir = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"FaceDir", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int FaceDir
    {
      get { return _FaceDir; }
      set { _FaceDir = value; }
    }
    private int _GuildId = (int)-1;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"GuildId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int GuildId
    {
      get { return _GuildId; }
      set { _GuildId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"DungeonRpcTransferNotify")]
  public partial class DungeonRpcTransferNotify : global::ProtoBuf.IExtensible
  {
    public DungeonRpcTransferNotify() {}
    
    private int _DungeonId = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"DungeonId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int DungeonId
    {
      get { return _DungeonId; }
      set { _DungeonId = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}