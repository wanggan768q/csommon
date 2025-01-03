// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TalismanV1Data.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "TalismanV1Data.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
class TalismanDataFabaoV1DefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<TalismanDataFabaoV1>
     _instance;
} _TalismanDataFabaoV1_default_instance_;
class TalismanFabaoInfoV1DefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<TalismanFabaoInfoV1>
     _instance;
} _TalismanFabaoInfoV1_default_instance_;

namespace protobuf_TalismanV1Data_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[2];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanDataFabaoV1, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanDataFabaoV1, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanDataFabaoV1, fabaoarr_),
  ~0u,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanFabaoInfoV1, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanFabaoInfoV1, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanFabaoInfoV1, id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanFabaoInfoV1, lv_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanFabaoInfoV1, isactived_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanFabaoInfoV1, activedcondid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanFabaoInfoV1, exp_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(TalismanFabaoInfoV1, hittype_),
  3,
  4,
  0,
  ~0u,
  1,
  2,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(TalismanDataFabaoV1)},
  { 7, 18, sizeof(TalismanFabaoInfoV1)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_TalismanDataFabaoV1_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&_TalismanFabaoInfoV1_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "TalismanV1Data.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  ::protobuf_PublicStruct_2eproto::InitDefaults();
  _TalismanDataFabaoV1_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_TalismanDataFabaoV1_default_instance_);_TalismanFabaoInfoV1_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_TalismanFabaoInfoV1_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\024TalismanV1Data.proto\032\022PublicStruct.pro"
      "to\"=\n\023TalismanDataFabaoV1\022&\n\010FabaoArr\030\001 "
      "\003(\0132\024.TalismanFabaoInfoV1\"\206\001\n\023TalismanFa"
      "baoInfoV1\022\016\n\002ID\030\001 \001(\021:\002-1\022\r\n\002Lv\030\002 \001(\021:\0011"
      "\022\024\n\tIsActived\030\003 \001(\021:\0010\022\025\n\rActivedCondID\030"
      "\004 \003(\021\022\016\n\003Exp\030\005 \001(\021:\0010\022\023\n\007HitType\030\006 \001(\021:\002"
      "-1"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 242);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "TalismanV1Data.proto", &protobuf_RegisterTypes);
  ::protobuf_PublicStruct_2eproto::AddDescriptors();
}
} // anonymous namespace

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_TalismanV1Data_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int TalismanDataFabaoV1::kFabaoArrFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

TalismanDataFabaoV1::TalismanDataFabaoV1()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_TalismanV1Data_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:TalismanDataFabaoV1)
}
TalismanDataFabaoV1::TalismanDataFabaoV1(const TalismanDataFabaoV1& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      fabaoarr_(from.fabaoarr_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:TalismanDataFabaoV1)
}

void TalismanDataFabaoV1::SharedCtor() {
  _cached_size_ = 0;
}

TalismanDataFabaoV1::~TalismanDataFabaoV1() {
  // @@protoc_insertion_point(destructor:TalismanDataFabaoV1)
  SharedDtor();
}

void TalismanDataFabaoV1::SharedDtor() {
}

void TalismanDataFabaoV1::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TalismanDataFabaoV1::descriptor() {
  protobuf_TalismanV1Data_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_TalismanV1Data_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const TalismanDataFabaoV1& TalismanDataFabaoV1::default_instance() {
  protobuf_TalismanV1Data_2eproto::InitDefaults();
  return *internal_default_instance();
}

TalismanDataFabaoV1* TalismanDataFabaoV1::New(::google::protobuf::Arena* arena) const {
  TalismanDataFabaoV1* n = new TalismanDataFabaoV1;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void TalismanDataFabaoV1::Clear() {
// @@protoc_insertion_point(message_clear_start:TalismanDataFabaoV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  fabaoarr_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool TalismanDataFabaoV1::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:TalismanDataFabaoV1)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .TalismanFabaoInfoV1 FabaoArr = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_fabaoarr()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:TalismanDataFabaoV1)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:TalismanDataFabaoV1)
  return false;
#undef DO_
}

void TalismanDataFabaoV1::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:TalismanDataFabaoV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .TalismanFabaoInfoV1 FabaoArr = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->fabaoarr_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->fabaoarr(static_cast<int>(i)), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:TalismanDataFabaoV1)
}

::google::protobuf::uint8* TalismanDataFabaoV1::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:TalismanDataFabaoV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .TalismanFabaoInfoV1 FabaoArr = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->fabaoarr_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, this->fabaoarr(static_cast<int>(i)), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TalismanDataFabaoV1)
  return target;
}

size_t TalismanDataFabaoV1::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:TalismanDataFabaoV1)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated .TalismanFabaoInfoV1 FabaoArr = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->fabaoarr_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->fabaoarr(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TalismanDataFabaoV1::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:TalismanDataFabaoV1)
  GOOGLE_DCHECK_NE(&from, this);
  const TalismanDataFabaoV1* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const TalismanDataFabaoV1>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:TalismanDataFabaoV1)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:TalismanDataFabaoV1)
    MergeFrom(*source);
  }
}

void TalismanDataFabaoV1::MergeFrom(const TalismanDataFabaoV1& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:TalismanDataFabaoV1)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  fabaoarr_.MergeFrom(from.fabaoarr_);
}

void TalismanDataFabaoV1::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:TalismanDataFabaoV1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TalismanDataFabaoV1::CopyFrom(const TalismanDataFabaoV1& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:TalismanDataFabaoV1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TalismanDataFabaoV1::IsInitialized() const {
  return true;
}

void TalismanDataFabaoV1::Swap(TalismanDataFabaoV1* other) {
  if (other == this) return;
  InternalSwap(other);
}
void TalismanDataFabaoV1::InternalSwap(TalismanDataFabaoV1* other) {
  using std::swap;
  fabaoarr_.InternalSwap(&other->fabaoarr_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata TalismanDataFabaoV1::GetMetadata() const {
  protobuf_TalismanV1Data_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_TalismanV1Data_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// TalismanDataFabaoV1

// repeated .TalismanFabaoInfoV1 FabaoArr = 1;
int TalismanDataFabaoV1::fabaoarr_size() const {
  return fabaoarr_.size();
}
void TalismanDataFabaoV1::clear_fabaoarr() {
  fabaoarr_.Clear();
}
const ::TalismanFabaoInfoV1& TalismanDataFabaoV1::fabaoarr(int index) const {
  // @@protoc_insertion_point(field_get:TalismanDataFabaoV1.FabaoArr)
  return fabaoarr_.Get(index);
}
::TalismanFabaoInfoV1* TalismanDataFabaoV1::mutable_fabaoarr(int index) {
  // @@protoc_insertion_point(field_mutable:TalismanDataFabaoV1.FabaoArr)
  return fabaoarr_.Mutable(index);
}
::TalismanFabaoInfoV1* TalismanDataFabaoV1::add_fabaoarr() {
  // @@protoc_insertion_point(field_add:TalismanDataFabaoV1.FabaoArr)
  return fabaoarr_.Add();
}
::google::protobuf::RepeatedPtrField< ::TalismanFabaoInfoV1 >*
TalismanDataFabaoV1::mutable_fabaoarr() {
  // @@protoc_insertion_point(field_mutable_list:TalismanDataFabaoV1.FabaoArr)
  return &fabaoarr_;
}
const ::google::protobuf::RepeatedPtrField< ::TalismanFabaoInfoV1 >&
TalismanDataFabaoV1::fabaoarr() const {
  // @@protoc_insertion_point(field_list:TalismanDataFabaoV1.FabaoArr)
  return fabaoarr_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int TalismanFabaoInfoV1::kIDFieldNumber;
const int TalismanFabaoInfoV1::kLvFieldNumber;
const int TalismanFabaoInfoV1::kIsActivedFieldNumber;
const int TalismanFabaoInfoV1::kActivedCondIDFieldNumber;
const int TalismanFabaoInfoV1::kExpFieldNumber;
const int TalismanFabaoInfoV1::kHitTypeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

TalismanFabaoInfoV1::TalismanFabaoInfoV1()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_TalismanV1Data_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:TalismanFabaoInfoV1)
}
TalismanFabaoInfoV1::TalismanFabaoInfoV1(const TalismanFabaoInfoV1& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      activedcondid_(from.activedcondid_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&isactived_, &from.isactived_,
    static_cast<size_t>(reinterpret_cast<char*>(&lv_) -
    reinterpret_cast<char*>(&isactived_)) + sizeof(lv_));
  // @@protoc_insertion_point(copy_constructor:TalismanFabaoInfoV1)
}

void TalismanFabaoInfoV1::SharedCtor() {
  _cached_size_ = 0;
  ::memset(&isactived_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&exp_) -
      reinterpret_cast<char*>(&isactived_)) + sizeof(exp_));
  hittype_ = -1;
  id_ = -1;
  lv_ = 1;
}

TalismanFabaoInfoV1::~TalismanFabaoInfoV1() {
  // @@protoc_insertion_point(destructor:TalismanFabaoInfoV1)
  SharedDtor();
}

void TalismanFabaoInfoV1::SharedDtor() {
}

void TalismanFabaoInfoV1::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* TalismanFabaoInfoV1::descriptor() {
  protobuf_TalismanV1Data_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_TalismanV1Data_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const TalismanFabaoInfoV1& TalismanFabaoInfoV1::default_instance() {
  protobuf_TalismanV1Data_2eproto::InitDefaults();
  return *internal_default_instance();
}

TalismanFabaoInfoV1* TalismanFabaoInfoV1::New(::google::protobuf::Arena* arena) const {
  TalismanFabaoInfoV1* n = new TalismanFabaoInfoV1;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void TalismanFabaoInfoV1::Clear() {
// @@protoc_insertion_point(message_clear_start:TalismanFabaoInfoV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  activedcondid_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 31u) {
    ::memset(&isactived_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&exp_) -
        reinterpret_cast<char*>(&isactived_)) + sizeof(exp_));
    hittype_ = -1;
    id_ = -1;
    lv_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool TalismanFabaoInfoV1::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:TalismanFabaoInfoV1)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional sint32 ID = 1 [default = -1];
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_id();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional sint32 Lv = 2 [default = 1];
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_lv();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &lv_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional sint32 IsActived = 3 [default = 0];
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_isactived();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &isactived_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated sint32 ActivedCondID = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 1, 32u, input, this->mutable_activedcondid())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, this->mutable_activedcondid())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional sint32 Exp = 5 [default = 0];
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          set_has_exp();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &exp_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional sint32 HitType = 6 [default = -1];
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          set_has_hittype();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &hittype_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:TalismanFabaoInfoV1)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:TalismanFabaoInfoV1)
  return false;
#undef DO_
}

void TalismanFabaoInfoV1::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:TalismanFabaoInfoV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional sint32 ID = 1 [default = -1];
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(1, this->id(), output);
  }

  // optional sint32 Lv = 2 [default = 1];
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(2, this->lv(), output);
  }

  // optional sint32 IsActived = 3 [default = 0];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(3, this->isactived(), output);
  }

  // repeated sint32 ActivedCondID = 4;
  for (int i = 0, n = this->activedcondid_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(
      4, this->activedcondid(i), output);
  }

  // optional sint32 Exp = 5 [default = 0];
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(5, this->exp(), output);
  }

  // optional sint32 HitType = 6 [default = -1];
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(6, this->hittype(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:TalismanFabaoInfoV1)
}

::google::protobuf::uint8* TalismanFabaoInfoV1::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:TalismanFabaoInfoV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional sint32 ID = 1 [default = -1];
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(1, this->id(), target);
  }

  // optional sint32 Lv = 2 [default = 1];
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(2, this->lv(), target);
  }

  // optional sint32 IsActived = 3 [default = 0];
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(3, this->isactived(), target);
  }

  // repeated sint32 ActivedCondID = 4;
  target = ::google::protobuf::internal::WireFormatLite::
    WriteSInt32ToArray(4, this->activedcondid_, target);

  // optional sint32 Exp = 5 [default = 0];
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(5, this->exp(), target);
  }

  // optional sint32 HitType = 6 [default = -1];
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(6, this->hittype(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TalismanFabaoInfoV1)
  return target;
}

size_t TalismanFabaoInfoV1::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:TalismanFabaoInfoV1)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated sint32 ActivedCondID = 4;
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      SInt32Size(this->activedcondid_);
    total_size += 1 *
                  ::google::protobuf::internal::FromIntSize(this->activedcondid_size());
    total_size += data_size;
  }

  if (_has_bits_[0 / 32] & 31u) {
    // optional sint32 IsActived = 3 [default = 0];
    if (has_isactived()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->isactived());
    }

    // optional sint32 Exp = 5 [default = 0];
    if (has_exp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->exp());
    }

    // optional sint32 HitType = 6 [default = -1];
    if (has_hittype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->hittype());
    }

    // optional sint32 ID = 1 [default = -1];
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->id());
    }

    // optional sint32 Lv = 2 [default = 1];
    if (has_lv()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->lv());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TalismanFabaoInfoV1::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:TalismanFabaoInfoV1)
  GOOGLE_DCHECK_NE(&from, this);
  const TalismanFabaoInfoV1* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const TalismanFabaoInfoV1>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:TalismanFabaoInfoV1)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:TalismanFabaoInfoV1)
    MergeFrom(*source);
  }
}

void TalismanFabaoInfoV1::MergeFrom(const TalismanFabaoInfoV1& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:TalismanFabaoInfoV1)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  activedcondid_.MergeFrom(from.activedcondid_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 31u) {
    if (cached_has_bits & 0x00000001u) {
      isactived_ = from.isactived_;
    }
    if (cached_has_bits & 0x00000002u) {
      exp_ = from.exp_;
    }
    if (cached_has_bits & 0x00000004u) {
      hittype_ = from.hittype_;
    }
    if (cached_has_bits & 0x00000008u) {
      id_ = from.id_;
    }
    if (cached_has_bits & 0x00000010u) {
      lv_ = from.lv_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void TalismanFabaoInfoV1::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:TalismanFabaoInfoV1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TalismanFabaoInfoV1::CopyFrom(const TalismanFabaoInfoV1& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:TalismanFabaoInfoV1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TalismanFabaoInfoV1::IsInitialized() const {
  return true;
}

void TalismanFabaoInfoV1::Swap(TalismanFabaoInfoV1* other) {
  if (other == this) return;
  InternalSwap(other);
}
void TalismanFabaoInfoV1::InternalSwap(TalismanFabaoInfoV1* other) {
  using std::swap;
  activedcondid_.InternalSwap(&other->activedcondid_);
  swap(isactived_, other->isactived_);
  swap(exp_, other->exp_);
  swap(hittype_, other->hittype_);
  swap(id_, other->id_);
  swap(lv_, other->lv_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata TalismanFabaoInfoV1::GetMetadata() const {
  protobuf_TalismanV1Data_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_TalismanV1Data_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// TalismanFabaoInfoV1

// optional sint32 ID = 1 [default = -1];
bool TalismanFabaoInfoV1::has_id() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
void TalismanFabaoInfoV1::set_has_id() {
  _has_bits_[0] |= 0x00000008u;
}
void TalismanFabaoInfoV1::clear_has_id() {
  _has_bits_[0] &= ~0x00000008u;
}
void TalismanFabaoInfoV1::clear_id() {
  id_ = -1;
  clear_has_id();
}
::google::protobuf::int32 TalismanFabaoInfoV1::id() const {
  // @@protoc_insertion_point(field_get:TalismanFabaoInfoV1.ID)
  return id_;
}
void TalismanFabaoInfoV1::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:TalismanFabaoInfoV1.ID)
}

// optional sint32 Lv = 2 [default = 1];
bool TalismanFabaoInfoV1::has_lv() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
void TalismanFabaoInfoV1::set_has_lv() {
  _has_bits_[0] |= 0x00000010u;
}
void TalismanFabaoInfoV1::clear_has_lv() {
  _has_bits_[0] &= ~0x00000010u;
}
void TalismanFabaoInfoV1::clear_lv() {
  lv_ = 1;
  clear_has_lv();
}
::google::protobuf::int32 TalismanFabaoInfoV1::lv() const {
  // @@protoc_insertion_point(field_get:TalismanFabaoInfoV1.Lv)
  return lv_;
}
void TalismanFabaoInfoV1::set_lv(::google::protobuf::int32 value) {
  set_has_lv();
  lv_ = value;
  // @@protoc_insertion_point(field_set:TalismanFabaoInfoV1.Lv)
}

// optional sint32 IsActived = 3 [default = 0];
bool TalismanFabaoInfoV1::has_isactived() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void TalismanFabaoInfoV1::set_has_isactived() {
  _has_bits_[0] |= 0x00000001u;
}
void TalismanFabaoInfoV1::clear_has_isactived() {
  _has_bits_[0] &= ~0x00000001u;
}
void TalismanFabaoInfoV1::clear_isactived() {
  isactived_ = 0;
  clear_has_isactived();
}
::google::protobuf::int32 TalismanFabaoInfoV1::isactived() const {
  // @@protoc_insertion_point(field_get:TalismanFabaoInfoV1.IsActived)
  return isactived_;
}
void TalismanFabaoInfoV1::set_isactived(::google::protobuf::int32 value) {
  set_has_isactived();
  isactived_ = value;
  // @@protoc_insertion_point(field_set:TalismanFabaoInfoV1.IsActived)
}

// repeated sint32 ActivedCondID = 4;
int TalismanFabaoInfoV1::activedcondid_size() const {
  return activedcondid_.size();
}
void TalismanFabaoInfoV1::clear_activedcondid() {
  activedcondid_.Clear();
}
::google::protobuf::int32 TalismanFabaoInfoV1::activedcondid(int index) const {
  // @@protoc_insertion_point(field_get:TalismanFabaoInfoV1.ActivedCondID)
  return activedcondid_.Get(index);
}
void TalismanFabaoInfoV1::set_activedcondid(int index, ::google::protobuf::int32 value) {
  activedcondid_.Set(index, value);
  // @@protoc_insertion_point(field_set:TalismanFabaoInfoV1.ActivedCondID)
}
void TalismanFabaoInfoV1::add_activedcondid(::google::protobuf::int32 value) {
  activedcondid_.Add(value);
  // @@protoc_insertion_point(field_add:TalismanFabaoInfoV1.ActivedCondID)
}
const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
TalismanFabaoInfoV1::activedcondid() const {
  // @@protoc_insertion_point(field_list:TalismanFabaoInfoV1.ActivedCondID)
  return activedcondid_;
}
::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
TalismanFabaoInfoV1::mutable_activedcondid() {
  // @@protoc_insertion_point(field_mutable_list:TalismanFabaoInfoV1.ActivedCondID)
  return &activedcondid_;
}

// optional sint32 Exp = 5 [default = 0];
bool TalismanFabaoInfoV1::has_exp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void TalismanFabaoInfoV1::set_has_exp() {
  _has_bits_[0] |= 0x00000002u;
}
void TalismanFabaoInfoV1::clear_has_exp() {
  _has_bits_[0] &= ~0x00000002u;
}
void TalismanFabaoInfoV1::clear_exp() {
  exp_ = 0;
  clear_has_exp();
}
::google::protobuf::int32 TalismanFabaoInfoV1::exp() const {
  // @@protoc_insertion_point(field_get:TalismanFabaoInfoV1.Exp)
  return exp_;
}
void TalismanFabaoInfoV1::set_exp(::google::protobuf::int32 value) {
  set_has_exp();
  exp_ = value;
  // @@protoc_insertion_point(field_set:TalismanFabaoInfoV1.Exp)
}

// optional sint32 HitType = 6 [default = -1];
bool TalismanFabaoInfoV1::has_hittype() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void TalismanFabaoInfoV1::set_has_hittype() {
  _has_bits_[0] |= 0x00000004u;
}
void TalismanFabaoInfoV1::clear_has_hittype() {
  _has_bits_[0] &= ~0x00000004u;
}
void TalismanFabaoInfoV1::clear_hittype() {
  hittype_ = -1;
  clear_has_hittype();
}
::google::protobuf::int32 TalismanFabaoInfoV1::hittype() const {
  // @@protoc_insertion_point(field_get:TalismanFabaoInfoV1.HitType)
  return hittype_;
}
void TalismanFabaoInfoV1::set_hittype(::google::protobuf::int32 value) {
  set_has_hittype();
  hittype_ = value;
  // @@protoc_insertion_point(field_set:TalismanFabaoInfoV1.HitType)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
