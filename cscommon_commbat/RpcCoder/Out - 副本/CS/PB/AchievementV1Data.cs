//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: AchievementV1Data.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"AchievementAchiObjV1")]
  public partial class AchievementAchiObjV1 : global::ProtoBuf.IExtensible
  {
    public AchievementAchiObjV1() {}
    
    private int _GroupId = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"GroupId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int GroupId
    {
      get { return _GroupId; }
      set { _GroupId = value; }
    }
    private int _Star = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Star", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Star
    {
      get { return _Star; }
      set { _Star = value; }
    }
    private int _Status = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"Status", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Status
    {
      get { return _Status; }
      set { _Status = value; }
    }
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _Type = (int)-1;
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"Type", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Type
    {
      get { return _Type; }
      set { _Type = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"AchievementAchiDataV1")]
  public partial class AchievementAchiDataV1 : global::ProtoBuf.IExtensible
  {
    public AchievementAchiDataV1() {}
    
    private readonly global::System.Collections.Generic.List<AchievementAchiObjV1> _AchiData = new global::System.Collections.Generic.List<AchievementAchiObjV1>();
    [global::ProtoBuf.ProtoMember(1, Name=@"AchiData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<AchievementAchiObjV1> AchiData
    {
      get { return _AchiData; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}