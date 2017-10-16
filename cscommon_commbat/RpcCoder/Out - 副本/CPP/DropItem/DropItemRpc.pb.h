// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DropItemRpc.proto

#ifndef PROTOBUF_DropItemRpc_2eproto__INCLUDED
#define PROTOBUF_DropItemRpc_2eproto__INCLUDED

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
class DropItemRpcDelDropItemNotify;
class DropItemRpcDelDropItemNotifyDefaultTypeInternal;
extern DropItemRpcDelDropItemNotifyDefaultTypeInternal _DropItemRpcDelDropItemNotify_default_instance_;
class DropItemRpcDropItemNoticeNotify;
class DropItemRpcDropItemNoticeNotifyDefaultTypeInternal;
extern DropItemRpcDropItemNoticeNotifyDefaultTypeInternal _DropItemRpcDropItemNoticeNotify_default_instance_;
class DropItemRpcPickupItemAsk;
class DropItemRpcPickupItemAskDefaultTypeInternal;
extern DropItemRpcPickupItemAskDefaultTypeInternal _DropItemRpcPickupItemAsk_default_instance_;
class DropItemRpcPickupItemReply;
class DropItemRpcPickupItemReplyDefaultTypeInternal;
extern DropItemRpcPickupItemReplyDefaultTypeInternal _DropItemRpcPickupItemReply_default_instance_;

namespace protobuf_DropItemRpc_2eproto {
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
}  // namespace protobuf_DropItemRpc_2eproto

// ===================================================================

class DropItemRpcDropItemNoticeNotify : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DropItemRpcDropItemNoticeNotify) */ {
 public:
  DropItemRpcDropItemNoticeNotify();
  virtual ~DropItemRpcDropItemNoticeNotify();

  DropItemRpcDropItemNoticeNotify(const DropItemRpcDropItemNoticeNotify& from);

  inline DropItemRpcDropItemNoticeNotify& operator=(const DropItemRpcDropItemNoticeNotify& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DropItemRpcDropItemNoticeNotify(DropItemRpcDropItemNoticeNotify&& from) noexcept
    : DropItemRpcDropItemNoticeNotify() {
    *this = ::std::move(from);
  }

  inline DropItemRpcDropItemNoticeNotify& operator=(DropItemRpcDropItemNoticeNotify&& from) noexcept {
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
  static const DropItemRpcDropItemNoticeNotify& default_instance();

  static inline const DropItemRpcDropItemNoticeNotify* internal_default_instance() {
    return reinterpret_cast<const DropItemRpcDropItemNoticeNotify*>(
               &_DropItemRpcDropItemNoticeNotify_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(DropItemRpcDropItemNoticeNotify* other);
  friend void swap(DropItemRpcDropItemNoticeNotify& a, DropItemRpcDropItemNoticeNotify& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DropItemRpcDropItemNoticeNotify* New() const PROTOBUF_FINAL { return New(NULL); }

  DropItemRpcDropItemNoticeNotify* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const DropItemRpcDropItemNoticeNotify& from);
  void MergeFrom(const DropItemRpcDropItemNoticeNotify& from);
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
  void InternalSwap(DropItemRpcDropItemNoticeNotify* other);
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

  // repeated .DropItemObj DropItem = 1;
  int dropitem_size() const;
  void clear_dropitem();
  static const int kDropItemFieldNumber = 1;
  const ::DropItemObj& dropitem(int index) const;
  ::DropItemObj* mutable_dropitem(int index);
  ::DropItemObj* add_dropitem();
  ::google::protobuf::RepeatedPtrField< ::DropItemObj >*
      mutable_dropitem();
  const ::google::protobuf::RepeatedPtrField< ::DropItemObj >&
      dropitem() const;

  // @@protoc_insertion_point(class_scope:DropItemRpcDropItemNoticeNotify)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::DropItemObj > dropitem_;
  friend struct protobuf_DropItemRpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class DropItemRpcPickupItemAsk : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DropItemRpcPickupItemAsk) */ {
 public:
  DropItemRpcPickupItemAsk();
  virtual ~DropItemRpcPickupItemAsk();

  DropItemRpcPickupItemAsk(const DropItemRpcPickupItemAsk& from);

  inline DropItemRpcPickupItemAsk& operator=(const DropItemRpcPickupItemAsk& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DropItemRpcPickupItemAsk(DropItemRpcPickupItemAsk&& from) noexcept
    : DropItemRpcPickupItemAsk() {
    *this = ::std::move(from);
  }

  inline DropItemRpcPickupItemAsk& operator=(DropItemRpcPickupItemAsk&& from) noexcept {
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
  static const DropItemRpcPickupItemAsk& default_instance();

  static inline const DropItemRpcPickupItemAsk* internal_default_instance() {
    return reinterpret_cast<const DropItemRpcPickupItemAsk*>(
               &_DropItemRpcPickupItemAsk_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(DropItemRpcPickupItemAsk* other);
  friend void swap(DropItemRpcPickupItemAsk& a, DropItemRpcPickupItemAsk& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DropItemRpcPickupItemAsk* New() const PROTOBUF_FINAL { return New(NULL); }

  DropItemRpcPickupItemAsk* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const DropItemRpcPickupItemAsk& from);
  void MergeFrom(const DropItemRpcPickupItemAsk& from);
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
  void InternalSwap(DropItemRpcPickupItemAsk* other);
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

  // optional sint32 UId = 2 [default = -1];
  bool has_uid() const;
  void clear_uid();
  static const int kUIdFieldNumber = 2;
  ::google::protobuf::int32 uid() const;
  void set_uid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:DropItemRpcPickupItemAsk)
 private:
  void set_has_uid();
  void clear_has_uid();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 uid_;
  friend struct protobuf_DropItemRpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class DropItemRpcPickupItemReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DropItemRpcPickupItemReply) */ {
 public:
  DropItemRpcPickupItemReply();
  virtual ~DropItemRpcPickupItemReply();

  DropItemRpcPickupItemReply(const DropItemRpcPickupItemReply& from);

  inline DropItemRpcPickupItemReply& operator=(const DropItemRpcPickupItemReply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DropItemRpcPickupItemReply(DropItemRpcPickupItemReply&& from) noexcept
    : DropItemRpcPickupItemReply() {
    *this = ::std::move(from);
  }

  inline DropItemRpcPickupItemReply& operator=(DropItemRpcPickupItemReply&& from) noexcept {
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
  static const DropItemRpcPickupItemReply& default_instance();

  static inline const DropItemRpcPickupItemReply* internal_default_instance() {
    return reinterpret_cast<const DropItemRpcPickupItemReply*>(
               &_DropItemRpcPickupItemReply_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(DropItemRpcPickupItemReply* other);
  friend void swap(DropItemRpcPickupItemReply& a, DropItemRpcPickupItemReply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DropItemRpcPickupItemReply* New() const PROTOBUF_FINAL { return New(NULL); }

  DropItemRpcPickupItemReply* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const DropItemRpcPickupItemReply& from);
  void MergeFrom(const DropItemRpcPickupItemReply& from);
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
  void InternalSwap(DropItemRpcPickupItemReply* other);
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

  // optional sint32 Result = 1 [default = -9999];
  bool has_result() const;
  void clear_result();
  static const int kResultFieldNumber = 1;
  ::google::protobuf::int32 result() const;
  void set_result(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:DropItemRpcPickupItemReply)
 private:
  void set_has_result();
  void clear_has_result();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 result_;
  friend struct protobuf_DropItemRpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class DropItemRpcDelDropItemNotify : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DropItemRpcDelDropItemNotify) */ {
 public:
  DropItemRpcDelDropItemNotify();
  virtual ~DropItemRpcDelDropItemNotify();

  DropItemRpcDelDropItemNotify(const DropItemRpcDelDropItemNotify& from);

  inline DropItemRpcDelDropItemNotify& operator=(const DropItemRpcDelDropItemNotify& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DropItemRpcDelDropItemNotify(DropItemRpcDelDropItemNotify&& from) noexcept
    : DropItemRpcDelDropItemNotify() {
    *this = ::std::move(from);
  }

  inline DropItemRpcDelDropItemNotify& operator=(DropItemRpcDelDropItemNotify&& from) noexcept {
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
  static const DropItemRpcDelDropItemNotify& default_instance();

  static inline const DropItemRpcDelDropItemNotify* internal_default_instance() {
    return reinterpret_cast<const DropItemRpcDelDropItemNotify*>(
               &_DropItemRpcDelDropItemNotify_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(DropItemRpcDelDropItemNotify* other);
  friend void swap(DropItemRpcDelDropItemNotify& a, DropItemRpcDelDropItemNotify& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DropItemRpcDelDropItemNotify* New() const PROTOBUF_FINAL { return New(NULL); }

  DropItemRpcDelDropItemNotify* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const DropItemRpcDelDropItemNotify& from);
  void MergeFrom(const DropItemRpcDelDropItemNotify& from);
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
  void InternalSwap(DropItemRpcDelDropItemNotify* other);
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

  // optional sint32 UId = 1 [default = -1];
  bool has_uid() const;
  void clear_uid();
  static const int kUIdFieldNumber = 1;
  ::google::protobuf::int32 uid() const;
  void set_uid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:DropItemRpcDelDropItemNotify)
 private:
  void set_has_uid();
  void clear_has_uid();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 uid_;
  friend struct protobuf_DropItemRpc_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DropItemRpcDropItemNoticeNotify

// repeated .DropItemObj DropItem = 1;
inline int DropItemRpcDropItemNoticeNotify::dropitem_size() const {
  return dropitem_.size();
}
inline void DropItemRpcDropItemNoticeNotify::clear_dropitem() {
  dropitem_.Clear();
}
inline const ::DropItemObj& DropItemRpcDropItemNoticeNotify::dropitem(int index) const {
  // @@protoc_insertion_point(field_get:DropItemRpcDropItemNoticeNotify.DropItem)
  return dropitem_.Get(index);
}
inline ::DropItemObj* DropItemRpcDropItemNoticeNotify::mutable_dropitem(int index) {
  // @@protoc_insertion_point(field_mutable:DropItemRpcDropItemNoticeNotify.DropItem)
  return dropitem_.Mutable(index);
}
inline ::DropItemObj* DropItemRpcDropItemNoticeNotify::add_dropitem() {
  // @@protoc_insertion_point(field_add:DropItemRpcDropItemNoticeNotify.DropItem)
  return dropitem_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::DropItemObj >*
DropItemRpcDropItemNoticeNotify::mutable_dropitem() {
  // @@protoc_insertion_point(field_mutable_list:DropItemRpcDropItemNoticeNotify.DropItem)
  return &dropitem_;
}
inline const ::google::protobuf::RepeatedPtrField< ::DropItemObj >&
DropItemRpcDropItemNoticeNotify::dropitem() const {
  // @@protoc_insertion_point(field_list:DropItemRpcDropItemNoticeNotify.DropItem)
  return dropitem_;
}

// -------------------------------------------------------------------

// DropItemRpcPickupItemAsk

// optional sint32 UId = 2 [default = -1];
inline bool DropItemRpcPickupItemAsk::has_uid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DropItemRpcPickupItemAsk::set_has_uid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DropItemRpcPickupItemAsk::clear_has_uid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DropItemRpcPickupItemAsk::clear_uid() {
  uid_ = -1;
  clear_has_uid();
}
inline ::google::protobuf::int32 DropItemRpcPickupItemAsk::uid() const {
  // @@protoc_insertion_point(field_get:DropItemRpcPickupItemAsk.UId)
  return uid_;
}
inline void DropItemRpcPickupItemAsk::set_uid(::google::protobuf::int32 value) {
  set_has_uid();
  uid_ = value;
  // @@protoc_insertion_point(field_set:DropItemRpcPickupItemAsk.UId)
}

// -------------------------------------------------------------------

// DropItemRpcPickupItemReply

// optional sint32 Result = 1 [default = -9999];
inline bool DropItemRpcPickupItemReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DropItemRpcPickupItemReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DropItemRpcPickupItemReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DropItemRpcPickupItemReply::clear_result() {
  result_ = -9999;
  clear_has_result();
}
inline ::google::protobuf::int32 DropItemRpcPickupItemReply::result() const {
  // @@protoc_insertion_point(field_get:DropItemRpcPickupItemReply.Result)
  return result_;
}
inline void DropItemRpcPickupItemReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
  // @@protoc_insertion_point(field_set:DropItemRpcPickupItemReply.Result)
}

// -------------------------------------------------------------------

// DropItemRpcDelDropItemNotify

// optional sint32 UId = 1 [default = -1];
inline bool DropItemRpcDelDropItemNotify::has_uid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DropItemRpcDelDropItemNotify::set_has_uid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DropItemRpcDelDropItemNotify::clear_has_uid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DropItemRpcDelDropItemNotify::clear_uid() {
  uid_ = -1;
  clear_has_uid();
}
inline ::google::protobuf::int32 DropItemRpcDelDropItemNotify::uid() const {
  // @@protoc_insertion_point(field_get:DropItemRpcDelDropItemNotify.UId)
  return uid_;
}
inline void DropItemRpcDelDropItemNotify::set_uid(::google::protobuf::int32 value) {
  set_has_uid();
  uid_ = value;
  // @@protoc_insertion_point(field_set:DropItemRpcDelDropItemNotify.UId)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_DropItemRpc_2eproto__INCLUDED
