//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: RefreshDataV1Data.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"RefreshDataRefreshDataV1")]
  public partial class RefreshDataRefreshDataV1 : global::ProtoBuf.IExtensible
  {
    public RefreshDataRefreshDataV1() {}
    
    private int _LastRefreshTime = (int)0;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"LastRefreshTime", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int LastRefreshTime
    {
      get { return _LastRefreshTime; }
      set { _LastRefreshTime = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}