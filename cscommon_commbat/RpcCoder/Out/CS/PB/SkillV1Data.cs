//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: SkillV1Data.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillSkillObjV1")]
  public partial class SkillSkillObjV1 : global::ProtoBuf.IExtensible
  {
    public SkillSkillObjV1() {}
    
    private int _SkillId = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"SkillId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int SkillId
    {
      get { return _SkillId; }
      set { _SkillId = value; }
    }
    private int _Lv = (int)1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Lv", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)1)]
    public int Lv
    {
      get { return _Lv; }
      set { _Lv = value; }
    }
    private bool _IsLearn = (bool)false;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"IsLearn", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue((bool)false)]
    public bool IsLearn
    {
      get { return _IsLearn; }
      set { _IsLearn = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillSkillDataV1")]
  public partial class SkillSkillDataV1 : global::ProtoBuf.IExtensible
  {
    public SkillSkillDataV1() {}
    
    private readonly global::System.Collections.Generic.List<SkillSkillObjV1> _SkillArray = new global::System.Collections.Generic.List<SkillSkillObjV1>();
    [global::ProtoBuf.ProtoMember(1, Name=@"SkillArray", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<SkillSkillObjV1> SkillArray
    {
      get { return _SkillArray; }
    }
  
    private readonly global::System.Collections.Generic.List<SkillShortcutObjV1> _ShortcutArray = new global::System.Collections.Generic.List<SkillShortcutObjV1>();
    [global::ProtoBuf.ProtoMember(2, Name=@"ShortcutArray", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<SkillShortcutObjV1> ShortcutArray
    {
      get { return _ShortcutArray; }
    }
  
    private int _ShortcutId = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"ShortcutId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int ShortcutId
    {
      get { return _ShortcutId; }
      set { _ShortcutId = value; }
    }
    private readonly global::System.Collections.Generic.List<SkillTalentSlotV1> _TalentSkill = new global::System.Collections.Generic.List<SkillTalentSlotV1>();
    [global::ProtoBuf.ProtoMember(4, Name=@"TalentSkill", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<SkillTalentSlotV1> TalentSkill
    {
      get { return _TalentSkill; }
    }
  
    private int _TotalCostExp = (int)0;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"TotalCostExp", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int TotalCostExp
    {
      get { return _TotalCostExp; }
      set { _TotalCostExp = value; }
    }
    private int _TalentLevel = (int)0;
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"TalentLevel", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int TalentLevel
    {
      get { return _TalentLevel; }
      set { _TalentLevel = value; }
    }
    private int _TalentPoint = (int)0;
    [global::ProtoBuf.ProtoMember(7, IsRequired = false, Name=@"TalentPoint", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int TalentPoint
    {
      get { return _TalentPoint; }
      set { _TalentPoint = value; }
    }
    private readonly global::System.Collections.Generic.List<SkillSkillObjV1> _LifeSkillArray = new global::System.Collections.Generic.List<SkillSkillObjV1>();
    [global::ProtoBuf.ProtoMember(8, Name=@"LifeSkillArray", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<SkillSkillObjV1> LifeSkillArray
    {
      get { return _LifeSkillArray; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillShortcutObjV1")]
  public partial class SkillShortcutObjV1 : global::ProtoBuf.IExtensible
  {
    public SkillShortcutObjV1() {}
    
    private readonly global::System.Collections.Generic.List<int> _SkillId = new global::System.Collections.Generic.List<int>();
    [global::ProtoBuf.ProtoMember(1, Name=@"SkillId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    public global::System.Collections.Generic.List<int> SkillId
    {
      get { return _SkillId; }
    }
  
    private int _Type = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Type", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
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
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillTalentSlotV1")]
  public partial class SkillTalentSlotV1 : global::ProtoBuf.IExtensible
  {
    public SkillTalentSlotV1() {}
    
    private int _SkillId = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"SkillId", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int SkillId
    {
      get { return _SkillId; }
      set { _SkillId = value; }
    }
    private int _Level = (int)0;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Level", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int Level
    {
      get { return _Level; }
      set { _Level = value; }
    }
    private bool _IsLock = (bool)true;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"IsLock", DataFormat = global::ProtoBuf.DataFormat.Default)]
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
  
}