//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: StoryDungeonV1Data.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"StoryDungeonStoryDungeonObjV1")]
  public partial class StoryDungeonStoryDungeonObjV1 : global::ProtoBuf.IExtensible
  {
    public StoryDungeonStoryDungeonObjV1() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private bool _IsLock = (bool)true;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"IsLock", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue((bool)true)]
    public bool IsLock
    {
      get { return _IsLock; }
      set { _IsLock = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"StoryDungeonStoryDungeonV1")]
  public partial class StoryDungeonStoryDungeonV1 : global::ProtoBuf.IExtensible
  {
    public StoryDungeonStoryDungeonV1() {}
    
    private readonly global::System.Collections.Generic.List<StoryDungeonStoryDungeonObjV1> _StoryDungeon = new global::System.Collections.Generic.List<StoryDungeonStoryDungeonObjV1>();
    [global::ProtoBuf.ProtoMember(1, Name=@"StoryDungeon", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<StoryDungeonStoryDungeonObjV1> StoryDungeon
    {
      get { return _StoryDungeon; }
    }
  
    private int _ChallengeNum = (int)0;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"ChallengeNum", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int ChallengeNum
    {
      get { return _ChallengeNum; }
      set { _ChallengeNum = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}