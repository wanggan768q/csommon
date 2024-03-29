// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RefreshDataV1Data.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "RefreshDataV1Data.pb.h"

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
class RefreshDataRefreshDataV1DefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<RefreshDataRefreshDataV1>
     _instance;
} _RefreshDataRefreshDataV1_default_instance_;

namespace protobuf_RefreshDataV1Data_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];

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
};

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RefreshDataRefreshDataV1, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RefreshDataRefreshDataV1, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RefreshDataRefreshDataV1, lastrefreshtime_),
  0,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(RefreshDataRefreshDataV1)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_RefreshDataRefreshDataV1_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "RefreshDataV1Data.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  ::protobuf_PublicStruct_2eproto::InitDefaults();
  _RefreshDataRefreshDataV1_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_RefreshDataRefreshDataV1_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\027RefreshDataV1Data.proto\032\022PublicStruct."
      "proto\"6\n\030RefreshDataRefreshDataV1\022\032\n\017Las"
      "tRefreshTime\030\001 \001(\021:\0010"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 101);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "RefreshDataV1Data.proto", &protobuf_RegisterTypes);
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

}  // namespace protobuf_RefreshDataV1Data_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int RefreshDataRefreshDataV1::kLastRefreshTimeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

RefreshDataRefreshDataV1::RefreshDataRefreshDataV1()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_RefreshDataV1Data_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:RefreshDataRefreshDataV1)
}
RefreshDataRefreshDataV1::RefreshDataRefreshDataV1(const RefreshDataRefreshDataV1& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  lastrefreshtime_ = from.lastrefreshtime_;
  // @@protoc_insertion_point(copy_constructor:RefreshDataRefreshDataV1)
}

void RefreshDataRefreshDataV1::SharedCtor() {
  _cached_size_ = 0;
  lastrefreshtime_ = 0;
}

RefreshDataRefreshDataV1::~RefreshDataRefreshDataV1() {
  // @@protoc_insertion_point(destructor:RefreshDataRefreshDataV1)
  SharedDtor();
}

void RefreshDataRefreshDataV1::SharedDtor() {
}

void RefreshDataRefreshDataV1::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RefreshDataRefreshDataV1::descriptor() {
  protobuf_RefreshDataV1Data_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_RefreshDataV1Data_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const RefreshDataRefreshDataV1& RefreshDataRefreshDataV1::default_instance() {
  protobuf_RefreshDataV1Data_2eproto::InitDefaults();
  return *internal_default_instance();
}

RefreshDataRefreshDataV1* RefreshDataRefreshDataV1::New(::google::protobuf::Arena* arena) const {
  RefreshDataRefreshDataV1* n = new RefreshDataRefreshDataV1;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void RefreshDataRefreshDataV1::Clear() {
// @@protoc_insertion_point(message_clear_start:RefreshDataRefreshDataV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  lastrefreshtime_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool RefreshDataRefreshDataV1::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:RefreshDataRefreshDataV1)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional sint32 LastRefreshTime = 1 [default = 0];
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_lastrefreshtime();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &lastrefreshtime_)));
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
  // @@protoc_insertion_point(parse_success:RefreshDataRefreshDataV1)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:RefreshDataRefreshDataV1)
  return false;
#undef DO_
}

void RefreshDataRefreshDataV1::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:RefreshDataRefreshDataV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional sint32 LastRefreshTime = 1 [default = 0];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(1, this->lastrefreshtime(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:RefreshDataRefreshDataV1)
}

::google::protobuf::uint8* RefreshDataRefreshDataV1::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:RefreshDataRefreshDataV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional sint32 LastRefreshTime = 1 [default = 0];
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(1, this->lastrefreshtime(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:RefreshDataRefreshDataV1)
  return target;
}

size_t RefreshDataRefreshDataV1::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:RefreshDataRefreshDataV1)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // optional sint32 LastRefreshTime = 1 [default = 0];
  if (has_lastrefreshtime()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->lastrefreshtime());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RefreshDataRefreshDataV1::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:RefreshDataRefreshDataV1)
  GOOGLE_DCHECK_NE(&from, this);
  const RefreshDataRefreshDataV1* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const RefreshDataRefreshDataV1>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:RefreshDataRefreshDataV1)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:RefreshDataRefreshDataV1)
    MergeFrom(*source);
  }
}

void RefreshDataRefreshDataV1::MergeFrom(const RefreshDataRefreshDataV1& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:RefreshDataRefreshDataV1)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_lastrefreshtime()) {
    set_lastrefreshtime(from.lastrefreshtime());
  }
}

void RefreshDataRefreshDataV1::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:RefreshDataRefreshDataV1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RefreshDataRefreshDataV1::CopyFrom(const RefreshDataRefreshDataV1& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:RefreshDataRefreshDataV1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RefreshDataRefreshDataV1::IsInitialized() const {
  return true;
}

void RefreshDataRefreshDataV1::Swap(RefreshDataRefreshDataV1* other) {
  if (other == this) return;
  InternalSwap(other);
}
void RefreshDataRefreshDataV1::InternalSwap(RefreshDataRefreshDataV1* other) {
  using std::swap;
  swap(lastrefreshtime_, other->lastrefreshtime_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata RefreshDataRefreshDataV1::GetMetadata() const {
  protobuf_RefreshDataV1Data_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_RefreshDataV1Data_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// RefreshDataRefreshDataV1

// optional sint32 LastRefreshTime = 1 [default = 0];
bool RefreshDataRefreshDataV1::has_lastrefreshtime() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void RefreshDataRefreshDataV1::set_has_lastrefreshtime() {
  _has_bits_[0] |= 0x00000001u;
}
void RefreshDataRefreshDataV1::clear_has_lastrefreshtime() {
  _has_bits_[0] &= ~0x00000001u;
}
void RefreshDataRefreshDataV1::clear_lastrefreshtime() {
  lastrefreshtime_ = 0;
  clear_has_lastrefreshtime();
}
::google::protobuf::int32 RefreshDataRefreshDataV1::lastrefreshtime() const {
  // @@protoc_insertion_point(field_get:RefreshDataRefreshDataV1.LastRefreshTime)
  return lastrefreshtime_;
}
void RefreshDataRefreshDataV1::set_lastrefreshtime(::google::protobuf::int32 value) {
  set_has_lastrefreshtime();
  lastrefreshtime_ = value;
  // @@protoc_insertion_point(field_set:RefreshDataRefreshDataV1.LastRefreshTime)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
