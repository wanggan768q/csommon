//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: GodWeaponV1Data.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"GodWeaponGodWeaponDataV1")]
  public partial class GodWeaponGodWeaponDataV1 : global::ProtoBuf.IExtensible
  {
    public GodWeaponGodWeaponDataV1() {}
    
    private readonly global::System.Collections.Generic.List<GodWeaponGodWeaponObjV1> _GodWeaponArray = new global::System.Collections.Generic.List<GodWeaponGodWeaponObjV1>();
    [global::ProtoBuf.ProtoMember(1, Name=@"GodWeaponArray", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<GodWeaponGodWeaponObjV1> GodWeaponArray
    {
      get { return _GodWeaponArray; }
    }
  
    private readonly global::System.Collections.Generic.List<GodWeaponGemGridObjV1> _GemBagArray = new global::System.Collections.Generic.List<GodWeaponGemGridObjV1>();
    [global::ProtoBuf.ProtoMember(2, Name=@"GemBagArray", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<GodWeaponGemGridObjV1> GemBagArray
    {
      get { return _GemBagArray; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"GodWeaponGemGridObjV1")]
  public partial class GodWeaponGemGridObjV1 : global::ProtoBuf.IExtensible
  {
    public GodWeaponGemGridObjV1() {}
    
    private int _GemId = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"GemId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int GemId
    {
      get { return _GemId; }
      set { _GemId = value; }
    }
    private int _Count = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Count", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Count
    {
      get { return _Count; }
      set { _Count = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"GodWeaponGemObjV1")]
  public partial class GodWeaponGemObjV1 : global::ProtoBuf.IExtensible
  {
    public GodWeaponGemObjV1() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _Pos = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Pos", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Pos
    {
      get { return _Pos; }
      set { _Pos = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"GodWeaponGodWeaponObjV1")]
  public partial class GodWeaponGodWeaponObjV1 : global::ProtoBuf.IExtensible
  {
    public GodWeaponGodWeaponObjV1() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _Quality = (int)0;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Quality", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int Quality
    {
      get { return _Quality; }
      set { _Quality = value; }
    }
    private int _Star = (int)0;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Star", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int Star
    {
      get { return _Star; }
      set { _Star = value; }
    }
    private readonly global::System.Collections.Generic.List<GodWeaponGemObjV1> _GemArray = new global::System.Collections.Generic.List<GodWeaponGemObjV1>();
    [global::ProtoBuf.ProtoMember(4, Name=@"GemArray", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<GodWeaponGemObjV1> GemArray
    {
      get { return _GemArray; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}