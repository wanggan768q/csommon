// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GuildV1Data.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "GuildV1Data.pb.h"

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
class GuildGuildListV1DefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<GuildGuildListV1>
     _instance;
} _GuildGuildListV1_default_instance_;

namespace protobuf_GuildV1Data_2eproto {


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
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GuildGuildListV1, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GuildGuildListV1, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GuildGuildListV1, guilddata_),
  0,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(GuildGuildListV1)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_GuildGuildListV1_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "GuildV1Data.proto", schemas, file_default_instances, TableStruct::offsets, factory,
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
  _GuildGuildListV1_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_GuildGuildListV1_default_instance_);_GuildGuildListV1_default_instance_._instance.get_mutable()->guilddata_ = const_cast< ::GuildInfoObj*>(
      ::GuildInfoObj::internal_default_instance());
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\021GuildV1Data.proto\032\022PublicStruct.proto\""
      "4\n\020GuildGuildListV1\022 \n\tGuildData\030\001 \001(\0132\r"
      ".GuildInfoObj"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 93);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "GuildV1Data.proto", &protobuf_RegisterTypes);
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

}  // namespace protobuf_GuildV1Data_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GuildGuildListV1::kGuildDataFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GuildGuildListV1::GuildGuildListV1()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_GuildV1Data_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:GuildGuildListV1)
}
GuildGuildListV1::GuildGuildListV1(const GuildGuildListV1& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_guilddata()) {
    guilddata_ = new ::GuildInfoObj(*from.guilddata_);
  } else {
    guilddata_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:GuildGuildListV1)
}

void GuildGuildListV1::SharedCtor() {
  _cached_size_ = 0;
  guilddata_ = NULL;
}

GuildGuildListV1::~GuildGuildListV1() {
  // @@protoc_insertion_point(destructor:GuildGuildListV1)
  SharedDtor();
}

void GuildGuildListV1::SharedDtor() {
  if (this != internal_default_instance()) delete guilddata_;
}

void GuildGuildListV1::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GuildGuildListV1::descriptor() {
  protobuf_GuildV1Data_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GuildV1Data_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GuildGuildListV1& GuildGuildListV1::default_instance() {
  protobuf_GuildV1Data_2eproto::InitDefaults();
  return *internal_default_instance();
}

GuildGuildListV1* GuildGuildListV1::New(::google::protobuf::Arena* arena) const {
  GuildGuildListV1* n = new GuildGuildListV1;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GuildGuildListV1::Clear() {
// @@protoc_insertion_point(message_clear_start:GuildGuildListV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (has_guilddata()) {
    GOOGLE_DCHECK(guilddata_ != NULL);
    guilddata_->::GuildInfoObj::Clear();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool GuildGuildListV1::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:GuildGuildListV1)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .GuildInfoObj GuildData = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_guilddata()));
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
  // @@protoc_insertion_point(parse_success:GuildGuildListV1)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:GuildGuildListV1)
  return false;
#undef DO_
}

void GuildGuildListV1::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:GuildGuildListV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .GuildInfoObj GuildData = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->guilddata_, output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:GuildGuildListV1)
}

::google::protobuf::uint8* GuildGuildListV1::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:GuildGuildListV1)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .GuildInfoObj GuildData = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, *this->guilddata_, deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GuildGuildListV1)
  return target;
}

size_t GuildGuildListV1::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:GuildGuildListV1)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // optional .GuildInfoObj GuildData = 1;
  if (has_guilddata()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->guilddata_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GuildGuildListV1::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:GuildGuildListV1)
  GOOGLE_DCHECK_NE(&from, this);
  const GuildGuildListV1* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GuildGuildListV1>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:GuildGuildListV1)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:GuildGuildListV1)
    MergeFrom(*source);
  }
}

void GuildGuildListV1::MergeFrom(const GuildGuildListV1& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:GuildGuildListV1)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_guilddata()) {
    mutable_guilddata()->::GuildInfoObj::MergeFrom(from.guilddata());
  }
}

void GuildGuildListV1::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:GuildGuildListV1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GuildGuildListV1::CopyFrom(const GuildGuildListV1& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:GuildGuildListV1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GuildGuildListV1::IsInitialized() const {
  return true;
}

void GuildGuildListV1::Swap(GuildGuildListV1* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GuildGuildListV1::InternalSwap(GuildGuildListV1* other) {
  using std::swap;
  swap(guilddata_, other->guilddata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GuildGuildListV1::GetMetadata() const {
  protobuf_GuildV1Data_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_GuildV1Data_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GuildGuildListV1

// optional .GuildInfoObj GuildData = 1;
bool GuildGuildListV1::has_guilddata() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void GuildGuildListV1::set_has_guilddata() {
  _has_bits_[0] |= 0x00000001u;
}
void GuildGuildListV1::clear_has_guilddata() {
  _has_bits_[0] &= ~0x00000001u;
}
void GuildGuildListV1::clear_guilddata() {
  if (guilddata_ != NULL) guilddata_->::GuildInfoObj::Clear();
  clear_has_guilddata();
}
const ::GuildInfoObj& GuildGuildListV1::guilddata() const {
  const ::GuildInfoObj* p = guilddata_;
  // @@protoc_insertion_point(field_get:GuildGuildListV1.GuildData)
  return p != NULL ? *p : *reinterpret_cast<const ::GuildInfoObj*>(
      &::_GuildInfoObj_default_instance_);
}
::GuildInfoObj* GuildGuildListV1::mutable_guilddata() {
  set_has_guilddata();
  if (guilddata_ == NULL) {
    guilddata_ = new ::GuildInfoObj;
  }
  // @@protoc_insertion_point(field_mutable:GuildGuildListV1.GuildData)
  return guilddata_;
}
::GuildInfoObj* GuildGuildListV1::release_guilddata() {
  // @@protoc_insertion_point(field_release:GuildGuildListV1.GuildData)
  clear_has_guilddata();
  ::GuildInfoObj* temp = guilddata_;
  guilddata_ = NULL;
  return temp;
}
void GuildGuildListV1::set_allocated_guilddata(::GuildInfoObj* guilddata) {
  delete guilddata_;
  guilddata_ = guilddata;
  if (guilddata) {
    set_has_guilddata();
  } else {
    clear_has_guilddata();
  }
  // @@protoc_insertion_point(field_set_allocated:GuildGuildListV1.GuildData)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
