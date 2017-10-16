// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ActivityEscapeRpc.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ActivityEscapeRpc.pb.h"

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
class ActivityEscapeRpcSignUpAskDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<ActivityEscapeRpcSignUpAsk>
     _instance;
} _ActivityEscapeRpcSignUpAsk_default_instance_;
class ActivityEscapeRpcSignUpReplyDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<ActivityEscapeRpcSignUpReply>
     _instance;
} _ActivityEscapeRpcSignUpReply_default_instance_;

namespace protobuf_ActivityEscapeRpc_2eproto {


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
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ActivityEscapeRpcSignUpAsk, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ActivityEscapeRpcSignUpAsk, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ActivityEscapeRpcSignUpReply, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ActivityEscapeRpcSignUpReply, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ActivityEscapeRpcSignUpReply, result_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ActivityEscapeRpcSignUpReply, losepeopleid_),
  0,
  ~0u,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 5, sizeof(ActivityEscapeRpcSignUpAsk)},
  { 5, 12, sizeof(ActivityEscapeRpcSignUpReply)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_ActivityEscapeRpcSignUpAsk_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&_ActivityEscapeRpcSignUpReply_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "ActivityEscapeRpc.proto", schemas, file_default_instances, TableStruct::offsets, factory,
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
  _ActivityEscapeRpcSignUpAsk_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_ActivityEscapeRpcSignUpAsk_default_instance_);_ActivityEscapeRpcSignUpReply_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_ActivityEscapeRpcSignUpReply_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\027ActivityEscapeRpc.proto\032\022PublicStruct."
      "proto\"\034\n\032ActivityEscapeRpcSignUpAsk\"K\n\034A"
      "ctivityEscapeRpcSignUpReply\022\025\n\006Result\030\001 "
      "\001(\021:\005-9999\022\024\n\014LosePeopleID\030\002 \003(\022"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 152);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ActivityEscapeRpc.proto", &protobuf_RegisterTypes);
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

}  // namespace protobuf_ActivityEscapeRpc_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ActivityEscapeRpcSignUpAsk::ActivityEscapeRpcSignUpAsk()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_ActivityEscapeRpc_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:ActivityEscapeRpcSignUpAsk)
}
ActivityEscapeRpcSignUpAsk::ActivityEscapeRpcSignUpAsk(const ActivityEscapeRpcSignUpAsk& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:ActivityEscapeRpcSignUpAsk)
}

void ActivityEscapeRpcSignUpAsk::SharedCtor() {
  _cached_size_ = 0;
}

ActivityEscapeRpcSignUpAsk::~ActivityEscapeRpcSignUpAsk() {
  // @@protoc_insertion_point(destructor:ActivityEscapeRpcSignUpAsk)
  SharedDtor();
}

void ActivityEscapeRpcSignUpAsk::SharedDtor() {
}

void ActivityEscapeRpcSignUpAsk::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ActivityEscapeRpcSignUpAsk::descriptor() {
  protobuf_ActivityEscapeRpc_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_ActivityEscapeRpc_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ActivityEscapeRpcSignUpAsk& ActivityEscapeRpcSignUpAsk::default_instance() {
  protobuf_ActivityEscapeRpc_2eproto::InitDefaults();
  return *internal_default_instance();
}

ActivityEscapeRpcSignUpAsk* ActivityEscapeRpcSignUpAsk::New(::google::protobuf::Arena* arena) const {
  ActivityEscapeRpcSignUpAsk* n = new ActivityEscapeRpcSignUpAsk;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ActivityEscapeRpcSignUpAsk::Clear() {
// @@protoc_insertion_point(message_clear_start:ActivityEscapeRpcSignUpAsk)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ActivityEscapeRpcSignUpAsk::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ActivityEscapeRpcSignUpAsk)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, _internal_metadata_.mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:ActivityEscapeRpcSignUpAsk)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ActivityEscapeRpcSignUpAsk)
  return false;
#undef DO_
}

void ActivityEscapeRpcSignUpAsk::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ActivityEscapeRpcSignUpAsk)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:ActivityEscapeRpcSignUpAsk)
}

::google::protobuf::uint8* ActivityEscapeRpcSignUpAsk::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:ActivityEscapeRpcSignUpAsk)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ActivityEscapeRpcSignUpAsk)
  return target;
}

size_t ActivityEscapeRpcSignUpAsk::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ActivityEscapeRpcSignUpAsk)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ActivityEscapeRpcSignUpAsk::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ActivityEscapeRpcSignUpAsk)
  GOOGLE_DCHECK_NE(&from, this);
  const ActivityEscapeRpcSignUpAsk* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ActivityEscapeRpcSignUpAsk>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ActivityEscapeRpcSignUpAsk)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ActivityEscapeRpcSignUpAsk)
    MergeFrom(*source);
  }
}

void ActivityEscapeRpcSignUpAsk::MergeFrom(const ActivityEscapeRpcSignUpAsk& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ActivityEscapeRpcSignUpAsk)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

}

void ActivityEscapeRpcSignUpAsk::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ActivityEscapeRpcSignUpAsk)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ActivityEscapeRpcSignUpAsk::CopyFrom(const ActivityEscapeRpcSignUpAsk& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ActivityEscapeRpcSignUpAsk)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ActivityEscapeRpcSignUpAsk::IsInitialized() const {
  return true;
}

void ActivityEscapeRpcSignUpAsk::Swap(ActivityEscapeRpcSignUpAsk* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ActivityEscapeRpcSignUpAsk::InternalSwap(ActivityEscapeRpcSignUpAsk* other) {
  using std::swap;
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ActivityEscapeRpcSignUpAsk::GetMetadata() const {
  protobuf_ActivityEscapeRpc_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_ActivityEscapeRpc_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ActivityEscapeRpcSignUpAsk

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ActivityEscapeRpcSignUpReply::kResultFieldNumber;
const int ActivityEscapeRpcSignUpReply::kLosePeopleIDFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ActivityEscapeRpcSignUpReply::ActivityEscapeRpcSignUpReply()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_ActivityEscapeRpc_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:ActivityEscapeRpcSignUpReply)
}
ActivityEscapeRpcSignUpReply::ActivityEscapeRpcSignUpReply(const ActivityEscapeRpcSignUpReply& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      losepeopleid_(from.losepeopleid_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  result_ = from.result_;
  // @@protoc_insertion_point(copy_constructor:ActivityEscapeRpcSignUpReply)
}

void ActivityEscapeRpcSignUpReply::SharedCtor() {
  _cached_size_ = 0;
  result_ = -9999;
}

ActivityEscapeRpcSignUpReply::~ActivityEscapeRpcSignUpReply() {
  // @@protoc_insertion_point(destructor:ActivityEscapeRpcSignUpReply)
  SharedDtor();
}

void ActivityEscapeRpcSignUpReply::SharedDtor() {
}

void ActivityEscapeRpcSignUpReply::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ActivityEscapeRpcSignUpReply::descriptor() {
  protobuf_ActivityEscapeRpc_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_ActivityEscapeRpc_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ActivityEscapeRpcSignUpReply& ActivityEscapeRpcSignUpReply::default_instance() {
  protobuf_ActivityEscapeRpc_2eproto::InitDefaults();
  return *internal_default_instance();
}

ActivityEscapeRpcSignUpReply* ActivityEscapeRpcSignUpReply::New(::google::protobuf::Arena* arena) const {
  ActivityEscapeRpcSignUpReply* n = new ActivityEscapeRpcSignUpReply;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ActivityEscapeRpcSignUpReply::Clear() {
// @@protoc_insertion_point(message_clear_start:ActivityEscapeRpcSignUpReply)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  losepeopleid_.Clear();
  result_ = -9999;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ActivityEscapeRpcSignUpReply::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ActivityEscapeRpcSignUpReply)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional sint32 Result = 1 [default = -9999];
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_result();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &result_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated sint64 LosePeopleID = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SINT64>(
                 1, 16u, input, this->mutable_losepeopleid())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SINT64>(
                 input, this->mutable_losepeopleid())));
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
  // @@protoc_insertion_point(parse_success:ActivityEscapeRpcSignUpReply)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ActivityEscapeRpcSignUpReply)
  return false;
#undef DO_
}

void ActivityEscapeRpcSignUpReply::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ActivityEscapeRpcSignUpReply)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional sint32 Result = 1 [default = -9999];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(1, this->result(), output);
  }

  // repeated sint64 LosePeopleID = 2;
  for (int i = 0, n = this->losepeopleid_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt64(
      2, this->losepeopleid(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:ActivityEscapeRpcSignUpReply)
}

::google::protobuf::uint8* ActivityEscapeRpcSignUpReply::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:ActivityEscapeRpcSignUpReply)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional sint32 Result = 1 [default = -9999];
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(1, this->result(), target);
  }

  // repeated sint64 LosePeopleID = 2;
  target = ::google::protobuf::internal::WireFormatLite::
    WriteSInt64ToArray(2, this->losepeopleid_, target);

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ActivityEscapeRpcSignUpReply)
  return target;
}

size_t ActivityEscapeRpcSignUpReply::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ActivityEscapeRpcSignUpReply)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated sint64 LosePeopleID = 2;
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      SInt64Size(this->losepeopleid_);
    total_size += 1 *
                  ::google::protobuf::internal::FromIntSize(this->losepeopleid_size());
    total_size += data_size;
  }

  // optional sint32 Result = 1 [default = -9999];
  if (has_result()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->result());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ActivityEscapeRpcSignUpReply::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ActivityEscapeRpcSignUpReply)
  GOOGLE_DCHECK_NE(&from, this);
  const ActivityEscapeRpcSignUpReply* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ActivityEscapeRpcSignUpReply>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ActivityEscapeRpcSignUpReply)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ActivityEscapeRpcSignUpReply)
    MergeFrom(*source);
  }
}

void ActivityEscapeRpcSignUpReply::MergeFrom(const ActivityEscapeRpcSignUpReply& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ActivityEscapeRpcSignUpReply)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  losepeopleid_.MergeFrom(from.losepeopleid_);
  if (from.has_result()) {
    set_result(from.result());
  }
}

void ActivityEscapeRpcSignUpReply::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ActivityEscapeRpcSignUpReply)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ActivityEscapeRpcSignUpReply::CopyFrom(const ActivityEscapeRpcSignUpReply& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ActivityEscapeRpcSignUpReply)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ActivityEscapeRpcSignUpReply::IsInitialized() const {
  return true;
}

void ActivityEscapeRpcSignUpReply::Swap(ActivityEscapeRpcSignUpReply* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ActivityEscapeRpcSignUpReply::InternalSwap(ActivityEscapeRpcSignUpReply* other) {
  using std::swap;
  losepeopleid_.InternalSwap(&other->losepeopleid_);
  swap(result_, other->result_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ActivityEscapeRpcSignUpReply::GetMetadata() const {
  protobuf_ActivityEscapeRpc_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_ActivityEscapeRpc_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ActivityEscapeRpcSignUpReply

// optional sint32 Result = 1 [default = -9999];
bool ActivityEscapeRpcSignUpReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void ActivityEscapeRpcSignUpReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
void ActivityEscapeRpcSignUpReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
void ActivityEscapeRpcSignUpReply::clear_result() {
  result_ = -9999;
  clear_has_result();
}
::google::protobuf::int32 ActivityEscapeRpcSignUpReply::result() const {
  // @@protoc_insertion_point(field_get:ActivityEscapeRpcSignUpReply.Result)
  return result_;
}
void ActivityEscapeRpcSignUpReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
  // @@protoc_insertion_point(field_set:ActivityEscapeRpcSignUpReply.Result)
}

// repeated sint64 LosePeopleID = 2;
int ActivityEscapeRpcSignUpReply::losepeopleid_size() const {
  return losepeopleid_.size();
}
void ActivityEscapeRpcSignUpReply::clear_losepeopleid() {
  losepeopleid_.Clear();
}
::google::protobuf::int64 ActivityEscapeRpcSignUpReply::losepeopleid(int index) const {
  // @@protoc_insertion_point(field_get:ActivityEscapeRpcSignUpReply.LosePeopleID)
  return losepeopleid_.Get(index);
}
void ActivityEscapeRpcSignUpReply::set_losepeopleid(int index, ::google::protobuf::int64 value) {
  losepeopleid_.Set(index, value);
  // @@protoc_insertion_point(field_set:ActivityEscapeRpcSignUpReply.LosePeopleID)
}
void ActivityEscapeRpcSignUpReply::add_losepeopleid(::google::protobuf::int64 value) {
  losepeopleid_.Add(value);
  // @@protoc_insertion_point(field_add:ActivityEscapeRpcSignUpReply.LosePeopleID)
}
const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
ActivityEscapeRpcSignUpReply::losepeopleid() const {
  // @@protoc_insertion_point(field_list:ActivityEscapeRpcSignUpReply.LosePeopleID)
  return losepeopleid_;
}
::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
ActivityEscapeRpcSignUpReply::mutable_losepeopleid() {
  // @@protoc_insertion_point(field_mutable_list:ActivityEscapeRpcSignUpReply.LosePeopleID)
  return &losepeopleid_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
