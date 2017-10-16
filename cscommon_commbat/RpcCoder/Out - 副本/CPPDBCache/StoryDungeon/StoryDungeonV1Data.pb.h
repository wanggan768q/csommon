// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: StoryDungeonV1Data.proto

#ifndef PROTOBUF_StoryDungeonV1Data_2eproto__INCLUDED
#define PROTOBUF_StoryDungeonV1Data_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "PublicStruct.pb.h"
// @@protoc_insertion_point(includes)
class StoryDungeonStoryDungeonObjV1;
class StoryDungeonStoryDungeonObjV1DefaultTypeInternal;
extern StoryDungeonStoryDungeonObjV1DefaultTypeInternal _StoryDungeonStoryDungeonObjV1_default_instance_;
class StoryDungeonStoryDungeonV1;
class StoryDungeonStoryDungeonV1DefaultTypeInternal;
extern StoryDungeonStoryDungeonV1DefaultTypeInternal _StoryDungeonStoryDungeonV1_default_instance_;

namespace protobuf_StoryDungeonV1Data_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_StoryDungeonV1Data_2eproto

// ===================================================================

class StoryDungeonStoryDungeonObjV1 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:StoryDungeonStoryDungeonObjV1) */ {
 public:
  StoryDungeonStoryDungeonObjV1();
  virtual ~StoryDungeonStoryDungeonObjV1();

  StoryDungeonStoryDungeonObjV1(const StoryDungeonStoryDungeonObjV1& from);

  inline StoryDungeonStoryDungeonObjV1& operator=(const StoryDungeonStoryDungeonObjV1& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StoryDungeonStoryDungeonObjV1(StoryDungeonStoryDungeonObjV1&& from) noexcept
    : StoryDungeonStoryDungeonObjV1() {
    *this = ::std::move(from);
  }

  inline StoryDungeonStoryDungeonObjV1& operator=(StoryDungeonStoryDungeonObjV1&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const StoryDungeonStoryDungeonObjV1& default_instance();

  static inline const StoryDungeonStoryDungeonObjV1* internal_default_instance() {
    return reinterpret_cast<const StoryDungeonStoryDungeonObjV1*>(
               &_StoryDungeonStoryDungeonObjV1_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(StoryDungeonStoryDungeonObjV1* other);
  friend void swap(StoryDungeonStoryDungeonObjV1& a, StoryDungeonStoryDungeonObjV1& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StoryDungeonStoryDungeonObjV1* New() const PROTOBUF_FINAL { return New(NULL); }

  StoryDungeonStoryDungeonObjV1* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const StoryDungeonStoryDungeonObjV1& from);
  void MergeFrom(const StoryDungeonStoryDungeonObjV1& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(StoryDungeonStoryDungeonObjV1* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint32 Id = 1 [default = -1];
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // optional bool IsLock = 3 [default = true];
  bool has_islock() const;
  void clear_islock();
  static const int kIsLockFieldNumber = 3;
  bool islock() const;
  void set_islock(bool value);

  // @@protoc_insertion_point(class_scope:StoryDungeonStoryDungeonObjV1)
 private:
  void set_has_id();
  void clear_has_id();
  void set_has_islock();
  void clear_has_islock();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 id_;
  bool islock_;
  friend struct protobuf_StoryDungeonV1Data_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class StoryDungeonStoryDungeonV1 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:StoryDungeonStoryDungeonV1) */ {
 public:
  StoryDungeonStoryDungeonV1();
  virtual ~StoryDungeonStoryDungeonV1();

  StoryDungeonStoryDungeonV1(const StoryDungeonStoryDungeonV1& from);

  inline StoryDungeonStoryDungeonV1& operator=(const StoryDungeonStoryDungeonV1& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StoryDungeonStoryDungeonV1(StoryDungeonStoryDungeonV1&& from) noexcept
    : StoryDungeonStoryDungeonV1() {
    *this = ::std::move(from);
  }

  inline StoryDungeonStoryDungeonV1& operator=(StoryDungeonStoryDungeonV1&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const StoryDungeonStoryDungeonV1& default_instance();

  static inline const StoryDungeonStoryDungeonV1* internal_default_instance() {
    return reinterpret_cast<const StoryDungeonStoryDungeonV1*>(
               &_StoryDungeonStoryDungeonV1_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(StoryDungeonStoryDungeonV1* other);
  friend void swap(StoryDungeonStoryDungeonV1& a, StoryDungeonStoryDungeonV1& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StoryDungeonStoryDungeonV1* New() const PROTOBUF_FINAL { return New(NULL); }

  StoryDungeonStoryDungeonV1* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const StoryDungeonStoryDungeonV1& from);
  void MergeFrom(const StoryDungeonStoryDungeonV1& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(StoryDungeonStoryDungeonV1* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .StoryDungeonStoryDungeonObjV1 StoryDungeon = 1;
  int storydungeon_size() const;
  void clear_storydungeon();
  static const int kStoryDungeonFieldNumber = 1;
  const ::StoryDungeonStoryDungeonObjV1& storydungeon(int index) const;
  ::StoryDungeonStoryDungeonObjV1* mutable_storydungeon(int index);
  ::StoryDungeonStoryDungeonObjV1* add_storydungeon();
  ::google::protobuf::RepeatedPtrField< ::StoryDungeonStoryDungeonObjV1 >*
      mutable_storydungeon();
  const ::google::protobuf::RepeatedPtrField< ::StoryDungeonStoryDungeonObjV1 >&
      storydungeon() const;

  // optional sint32 ChallengeNum = 2 [default = 0];
  bool has_challengenum() const;
  void clear_challengenum();
  static const int kChallengeNumFieldNumber = 2;
  ::google::protobuf::int32 challengenum() const;
  void set_challengenum(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:StoryDungeonStoryDungeonV1)
 private:
  void set_has_challengenum();
  void clear_has_challengenum();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::StoryDungeonStoryDungeonObjV1 > storydungeon_;
  ::google::protobuf::int32 challengenum_;
  friend struct protobuf_StoryDungeonV1Data_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// StoryDungeonStoryDungeonObjV1

// optional sint32 Id = 1 [default = -1];
inline bool StoryDungeonStoryDungeonObjV1::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void StoryDungeonStoryDungeonObjV1::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void StoryDungeonStoryDungeonObjV1::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void StoryDungeonStoryDungeonObjV1::clear_id() {
  id_ = -1;
  clear_has_id();
}
inline ::google::protobuf::int32 StoryDungeonStoryDungeonObjV1::id() const {
  // @@protoc_insertion_point(field_get:StoryDungeonStoryDungeonObjV1.Id)
  return id_;
}
inline void StoryDungeonStoryDungeonObjV1::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:StoryDungeonStoryDungeonObjV1.Id)
}

// optional bool IsLock = 3 [default = true];
inline bool StoryDungeonStoryDungeonObjV1::has_islock() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void StoryDungeonStoryDungeonObjV1::set_has_islock() {
  _has_bits_[0] |= 0x00000002u;
}
inline void StoryDungeonStoryDungeonObjV1::clear_has_islock() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void StoryDungeonStoryDungeonObjV1::clear_islock() {
  islock_ = true;
  clear_has_islock();
}
inline bool StoryDungeonStoryDungeonObjV1::islock() const {
  // @@protoc_insertion_point(field_get:StoryDungeonStoryDungeonObjV1.IsLock)
  return islock_;
}
inline void StoryDungeonStoryDungeonObjV1::set_islock(bool value) {
  set_has_islock();
  islock_ = value;
  // @@protoc_insertion_point(field_set:StoryDungeonStoryDungeonObjV1.IsLock)
}

// -------------------------------------------------------------------

// StoryDungeonStoryDungeonV1

// repeated .StoryDungeonStoryDungeonObjV1 StoryDungeon = 1;
inline int StoryDungeonStoryDungeonV1::storydungeon_size() const {
  return storydungeon_.size();
}
inline void StoryDungeonStoryDungeonV1::clear_storydungeon() {
  storydungeon_.Clear();
}
inline const ::StoryDungeonStoryDungeonObjV1& StoryDungeonStoryDungeonV1::storydungeon(int index) const {
  // @@protoc_insertion_point(field_get:StoryDungeonStoryDungeonV1.StoryDungeon)
  return storydungeon_.Get(index);
}
inline ::StoryDungeonStoryDungeonObjV1* StoryDungeonStoryDungeonV1::mutable_storydungeon(int index) {
  // @@protoc_insertion_point(field_mutable:StoryDungeonStoryDungeonV1.StoryDungeon)
  return storydungeon_.Mutable(index);
}
inline ::StoryDungeonStoryDungeonObjV1* StoryDungeonStoryDungeonV1::add_storydungeon() {
  // @@protoc_insertion_point(field_add:StoryDungeonStoryDungeonV1.StoryDungeon)
  return storydungeon_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::StoryDungeonStoryDungeonObjV1 >*
StoryDungeonStoryDungeonV1::mutable_storydungeon() {
  // @@protoc_insertion_point(field_mutable_list:StoryDungeonStoryDungeonV1.StoryDungeon)
  return &storydungeon_;
}
inline const ::google::protobuf::RepeatedPtrField< ::StoryDungeonStoryDungeonObjV1 >&
StoryDungeonStoryDungeonV1::storydungeon() const {
  // @@protoc_insertion_point(field_list:StoryDungeonStoryDungeonV1.StoryDungeon)
  return storydungeon_;
}

// optional sint32 ChallengeNum = 2 [default = 0];
inline bool StoryDungeonStoryDungeonV1::has_challengenum() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void StoryDungeonStoryDungeonV1::set_has_challengenum() {
  _has_bits_[0] |= 0x00000001u;
}
inline void StoryDungeonStoryDungeonV1::clear_has_challengenum() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void StoryDungeonStoryDungeonV1::clear_challengenum() {
  challengenum_ = 0;
  clear_has_challengenum();
}
inline ::google::protobuf::int32 StoryDungeonStoryDungeonV1::challengenum() const {
  // @@protoc_insertion_point(field_get:StoryDungeonStoryDungeonV1.ChallengeNum)
  return challengenum_;
}
inline void StoryDungeonStoryDungeonV1::set_challengenum(::google::protobuf::int32 value) {
  set_has_challengenum();
  challengenum_ = value;
  // @@protoc_insertion_point(field_set:StoryDungeonStoryDungeonV1.ChallengeNum)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_StoryDungeonV1Data_2eproto__INCLUDED
