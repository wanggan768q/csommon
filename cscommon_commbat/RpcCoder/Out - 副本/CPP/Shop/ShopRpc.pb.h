// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ShopRpc.proto

#ifndef PROTOBUF_ShopRpc_2eproto__INCLUDED
#define PROTOBUF_ShopRpc_2eproto__INCLUDED

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
class ShopRpcBuyAsk;
class ShopRpcBuyAskDefaultTypeInternal;
extern ShopRpcBuyAskDefaultTypeInternal _ShopRpcBuyAsk_default_instance_;
class ShopRpcBuyReply;
class ShopRpcBuyReplyDefaultTypeInternal;
extern ShopRpcBuyReplyDefaultTypeInternal _ShopRpcBuyReply_default_instance_;
class ShopRpcRefreshItemAsk;
class ShopRpcRefreshItemAskDefaultTypeInternal;
extern ShopRpcRefreshItemAskDefaultTypeInternal _ShopRpcRefreshItemAsk_default_instance_;
class ShopRpcRefreshItemReply;
class ShopRpcRefreshItemReplyDefaultTypeInternal;
extern ShopRpcRefreshItemReplyDefaultTypeInternal _ShopRpcRefreshItemReply_default_instance_;
class ShopRpcSyncDataAsk;
class ShopRpcSyncDataAskDefaultTypeInternal;
extern ShopRpcSyncDataAskDefaultTypeInternal _ShopRpcSyncDataAsk_default_instance_;
class ShopRpcSyncDataReply;
class ShopRpcSyncDataReplyDefaultTypeInternal;
extern ShopRpcSyncDataReplyDefaultTypeInternal _ShopRpcSyncDataReply_default_instance_;

namespace protobuf_ShopRpc_2eproto {
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
}  // namespace protobuf_ShopRpc_2eproto

// ===================================================================

class ShopRpcSyncDataAsk : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ShopRpcSyncDataAsk) */ {
 public:
  ShopRpcSyncDataAsk();
  virtual ~ShopRpcSyncDataAsk();

  ShopRpcSyncDataAsk(const ShopRpcSyncDataAsk& from);

  inline ShopRpcSyncDataAsk& operator=(const ShopRpcSyncDataAsk& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ShopRpcSyncDataAsk(ShopRpcSyncDataAsk&& from) noexcept
    : ShopRpcSyncDataAsk() {
    *this = ::std::move(from);
  }

  inline ShopRpcSyncDataAsk& operator=(ShopRpcSyncDataAsk&& from) noexcept {
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
  static const ShopRpcSyncDataAsk& default_instance();

  static inline const ShopRpcSyncDataAsk* internal_default_instance() {
    return reinterpret_cast<const ShopRpcSyncDataAsk*>(
               &_ShopRpcSyncDataAsk_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ShopRpcSyncDataAsk* other);
  friend void swap(ShopRpcSyncDataAsk& a, ShopRpcSyncDataAsk& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ShopRpcSyncDataAsk* New() const PROTOBUF_FINAL { return New(NULL); }

  ShopRpcSyncDataAsk* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ShopRpcSyncDataAsk& from);
  void MergeFrom(const ShopRpcSyncDataAsk& from);
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
  void InternalSwap(ShopRpcSyncDataAsk* other);
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

  // @@protoc_insertion_point(class_scope:ShopRpcSyncDataAsk)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend struct protobuf_ShopRpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ShopRpcSyncDataReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ShopRpcSyncDataReply) */ {
 public:
  ShopRpcSyncDataReply();
  virtual ~ShopRpcSyncDataReply();

  ShopRpcSyncDataReply(const ShopRpcSyncDataReply& from);

  inline ShopRpcSyncDataReply& operator=(const ShopRpcSyncDataReply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ShopRpcSyncDataReply(ShopRpcSyncDataReply&& from) noexcept
    : ShopRpcSyncDataReply() {
    *this = ::std::move(from);
  }

  inline ShopRpcSyncDataReply& operator=(ShopRpcSyncDataReply&& from) noexcept {
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
  static const ShopRpcSyncDataReply& default_instance();

  static inline const ShopRpcSyncDataReply* internal_default_instance() {
    return reinterpret_cast<const ShopRpcSyncDataReply*>(
               &_ShopRpcSyncDataReply_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ShopRpcSyncDataReply* other);
  friend void swap(ShopRpcSyncDataReply& a, ShopRpcSyncDataReply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ShopRpcSyncDataReply* New() const PROTOBUF_FINAL { return New(NULL); }

  ShopRpcSyncDataReply* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ShopRpcSyncDataReply& from);
  void MergeFrom(const ShopRpcSyncDataReply& from);
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
  void InternalSwap(ShopRpcSyncDataReply* other);
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

  // @@protoc_insertion_point(class_scope:ShopRpcSyncDataReply)
 private:
  void set_has_result();
  void clear_has_result();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 result_;
  friend struct protobuf_ShopRpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ShopRpcBuyAsk : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ShopRpcBuyAsk) */ {
 public:
  ShopRpcBuyAsk();
  virtual ~ShopRpcBuyAsk();

  ShopRpcBuyAsk(const ShopRpcBuyAsk& from);

  inline ShopRpcBuyAsk& operator=(const ShopRpcBuyAsk& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ShopRpcBuyAsk(ShopRpcBuyAsk&& from) noexcept
    : ShopRpcBuyAsk() {
    *this = ::std::move(from);
  }

  inline ShopRpcBuyAsk& operator=(ShopRpcBuyAsk&& from) noexcept {
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
  static const ShopRpcBuyAsk& default_instance();

  static inline const ShopRpcBuyAsk* internal_default_instance() {
    return reinterpret_cast<const ShopRpcBuyAsk*>(
               &_ShopRpcBuyAsk_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(ShopRpcBuyAsk* other);
  friend void swap(ShopRpcBuyAsk& a, ShopRpcBuyAsk& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ShopRpcBuyAsk* New() const PROTOBUF_FINAL { return New(NULL); }

  ShopRpcBuyAsk* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ShopRpcBuyAsk& from);
  void MergeFrom(const ShopRpcBuyAsk& from);
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
  void InternalSwap(ShopRpcBuyAsk* other);
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

  // optional sint32 Pos = 3 [default = -1];
  bool has_pos() const;
  void clear_pos();
  static const int kPosFieldNumber = 3;
  ::google::protobuf::int32 pos() const;
  void set_pos(::google::protobuf::int32 value);

  // optional sint32 ShopType = 1 [default = -1];
  bool has_shoptype() const;
  void clear_shoptype();
  static const int kShopTypeFieldNumber = 1;
  ::google::protobuf::int32 shoptype() const;
  void set_shoptype(::google::protobuf::int32 value);

  // optional sint32 ItemId = 2 [default = -1];
  bool has_itemid() const;
  void clear_itemid();
  static const int kItemIdFieldNumber = 2;
  ::google::protobuf::int32 itemid() const;
  void set_itemid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ShopRpcBuyAsk)
 private:
  void set_has_shoptype();
  void clear_has_shoptype();
  void set_has_itemid();
  void clear_has_itemid();
  void set_has_pos();
  void clear_has_pos();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 pos_;
  ::google::protobuf::int32 shoptype_;
  ::google::protobuf::int32 itemid_;
  friend struct protobuf_ShopRpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ShopRpcBuyReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ShopRpcBuyReply) */ {
 public:
  ShopRpcBuyReply();
  virtual ~ShopRpcBuyReply();

  ShopRpcBuyReply(const ShopRpcBuyReply& from);

  inline ShopRpcBuyReply& operator=(const ShopRpcBuyReply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ShopRpcBuyReply(ShopRpcBuyReply&& from) noexcept
    : ShopRpcBuyReply() {
    *this = ::std::move(from);
  }

  inline ShopRpcBuyReply& operator=(ShopRpcBuyReply&& from) noexcept {
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
  static const ShopRpcBuyReply& default_instance();

  static inline const ShopRpcBuyReply* internal_default_instance() {
    return reinterpret_cast<const ShopRpcBuyReply*>(
               &_ShopRpcBuyReply_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(ShopRpcBuyReply* other);
  friend void swap(ShopRpcBuyReply& a, ShopRpcBuyReply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ShopRpcBuyReply* New() const PROTOBUF_FINAL { return New(NULL); }

  ShopRpcBuyReply* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ShopRpcBuyReply& from);
  void MergeFrom(const ShopRpcBuyReply& from);
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
  void InternalSwap(ShopRpcBuyReply* other);
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

  // optional sint32 ShopType = 2 [default = -1];
  bool has_shoptype() const;
  void clear_shoptype();
  static const int kShopTypeFieldNumber = 2;
  ::google::protobuf::int32 shoptype() const;
  void set_shoptype(::google::protobuf::int32 value);

  // optional sint32 ItemId = 3 [default = -1];
  bool has_itemid() const;
  void clear_itemid();
  static const int kItemIdFieldNumber = 3;
  ::google::protobuf::int32 itemid() const;
  void set_itemid(::google::protobuf::int32 value);

  // optional sint32 Pos = 4 [default = -1];
  bool has_pos() const;
  void clear_pos();
  static const int kPosFieldNumber = 4;
  ::google::protobuf::int32 pos() const;
  void set_pos(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ShopRpcBuyReply)
 private:
  void set_has_result();
  void clear_has_result();
  void set_has_shoptype();
  void clear_has_shoptype();
  void set_has_itemid();
  void clear_has_itemid();
  void set_has_pos();
  void clear_has_pos();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 result_;
  ::google::protobuf::int32 shoptype_;
  ::google::protobuf::int32 itemid_;
  ::google::protobuf::int32 pos_;
  friend struct protobuf_ShopRpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ShopRpcRefreshItemAsk : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ShopRpcRefreshItemAsk) */ {
 public:
  ShopRpcRefreshItemAsk();
  virtual ~ShopRpcRefreshItemAsk();

  ShopRpcRefreshItemAsk(const ShopRpcRefreshItemAsk& from);

  inline ShopRpcRefreshItemAsk& operator=(const ShopRpcRefreshItemAsk& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ShopRpcRefreshItemAsk(ShopRpcRefreshItemAsk&& from) noexcept
    : ShopRpcRefreshItemAsk() {
    *this = ::std::move(from);
  }

  inline ShopRpcRefreshItemAsk& operator=(ShopRpcRefreshItemAsk&& from) noexcept {
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
  static const ShopRpcRefreshItemAsk& default_instance();

  static inline const ShopRpcRefreshItemAsk* internal_default_instance() {
    return reinterpret_cast<const ShopRpcRefreshItemAsk*>(
               &_ShopRpcRefreshItemAsk_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(ShopRpcRefreshItemAsk* other);
  friend void swap(ShopRpcRefreshItemAsk& a, ShopRpcRefreshItemAsk& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ShopRpcRefreshItemAsk* New() const PROTOBUF_FINAL { return New(NULL); }

  ShopRpcRefreshItemAsk* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ShopRpcRefreshItemAsk& from);
  void MergeFrom(const ShopRpcRefreshItemAsk& from);
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
  void InternalSwap(ShopRpcRefreshItemAsk* other);
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

  // optional sint32 ShopType = 2 [default = -1];
  bool has_shoptype() const;
  void clear_shoptype();
  static const int kShopTypeFieldNumber = 2;
  ::google::protobuf::int32 shoptype() const;
  void set_shoptype(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ShopRpcRefreshItemAsk)
 private:
  void set_has_shoptype();
  void clear_has_shoptype();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 shoptype_;
  friend struct protobuf_ShopRpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ShopRpcRefreshItemReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ShopRpcRefreshItemReply) */ {
 public:
  ShopRpcRefreshItemReply();
  virtual ~ShopRpcRefreshItemReply();

  ShopRpcRefreshItemReply(const ShopRpcRefreshItemReply& from);

  inline ShopRpcRefreshItemReply& operator=(const ShopRpcRefreshItemReply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ShopRpcRefreshItemReply(ShopRpcRefreshItemReply&& from) noexcept
    : ShopRpcRefreshItemReply() {
    *this = ::std::move(from);
  }

  inline ShopRpcRefreshItemReply& operator=(ShopRpcRefreshItemReply&& from) noexcept {
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
  static const ShopRpcRefreshItemReply& default_instance();

  static inline const ShopRpcRefreshItemReply* internal_default_instance() {
    return reinterpret_cast<const ShopRpcRefreshItemReply*>(
               &_ShopRpcRefreshItemReply_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    5;

  void Swap(ShopRpcRefreshItemReply* other);
  friend void swap(ShopRpcRefreshItemReply& a, ShopRpcRefreshItemReply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ShopRpcRefreshItemReply* New() const PROTOBUF_FINAL { return New(NULL); }

  ShopRpcRefreshItemReply* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ShopRpcRefreshItemReply& from);
  void MergeFrom(const ShopRpcRefreshItemReply& from);
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
  void InternalSwap(ShopRpcRefreshItemReply* other);
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

  // optional sint32 ShopType = 2 [default = -1];
  bool has_shoptype() const;
  void clear_shoptype();
  static const int kShopTypeFieldNumber = 2;
  ::google::protobuf::int32 shoptype() const;
  void set_shoptype(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ShopRpcRefreshItemReply)
 private:
  void set_has_result();
  void clear_has_result();
  void set_has_shoptype();
  void clear_has_shoptype();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 result_;
  ::google::protobuf::int32 shoptype_;
  friend struct protobuf_ShopRpc_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ShopRpcSyncDataAsk

// -------------------------------------------------------------------

// ShopRpcSyncDataReply

// optional sint32 Result = 1 [default = -9999];
inline bool ShopRpcSyncDataReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ShopRpcSyncDataReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ShopRpcSyncDataReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ShopRpcSyncDataReply::clear_result() {
  result_ = -9999;
  clear_has_result();
}
inline ::google::protobuf::int32 ShopRpcSyncDataReply::result() const {
  // @@protoc_insertion_point(field_get:ShopRpcSyncDataReply.Result)
  return result_;
}
inline void ShopRpcSyncDataReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcSyncDataReply.Result)
}

// -------------------------------------------------------------------

// ShopRpcBuyAsk

// optional sint32 ShopType = 1 [default = -1];
inline bool ShopRpcBuyAsk::has_shoptype() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ShopRpcBuyAsk::set_has_shoptype() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ShopRpcBuyAsk::clear_has_shoptype() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ShopRpcBuyAsk::clear_shoptype() {
  shoptype_ = -1;
  clear_has_shoptype();
}
inline ::google::protobuf::int32 ShopRpcBuyAsk::shoptype() const {
  // @@protoc_insertion_point(field_get:ShopRpcBuyAsk.ShopType)
  return shoptype_;
}
inline void ShopRpcBuyAsk::set_shoptype(::google::protobuf::int32 value) {
  set_has_shoptype();
  shoptype_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcBuyAsk.ShopType)
}

// optional sint32 ItemId = 2 [default = -1];
inline bool ShopRpcBuyAsk::has_itemid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ShopRpcBuyAsk::set_has_itemid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ShopRpcBuyAsk::clear_has_itemid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ShopRpcBuyAsk::clear_itemid() {
  itemid_ = -1;
  clear_has_itemid();
}
inline ::google::protobuf::int32 ShopRpcBuyAsk::itemid() const {
  // @@protoc_insertion_point(field_get:ShopRpcBuyAsk.ItemId)
  return itemid_;
}
inline void ShopRpcBuyAsk::set_itemid(::google::protobuf::int32 value) {
  set_has_itemid();
  itemid_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcBuyAsk.ItemId)
}

// optional sint32 Pos = 3 [default = -1];
inline bool ShopRpcBuyAsk::has_pos() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ShopRpcBuyAsk::set_has_pos() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ShopRpcBuyAsk::clear_has_pos() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ShopRpcBuyAsk::clear_pos() {
  pos_ = -1;
  clear_has_pos();
}
inline ::google::protobuf::int32 ShopRpcBuyAsk::pos() const {
  // @@protoc_insertion_point(field_get:ShopRpcBuyAsk.Pos)
  return pos_;
}
inline void ShopRpcBuyAsk::set_pos(::google::protobuf::int32 value) {
  set_has_pos();
  pos_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcBuyAsk.Pos)
}

// -------------------------------------------------------------------

// ShopRpcBuyReply

// optional sint32 Result = 1 [default = -9999];
inline bool ShopRpcBuyReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ShopRpcBuyReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ShopRpcBuyReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ShopRpcBuyReply::clear_result() {
  result_ = -9999;
  clear_has_result();
}
inline ::google::protobuf::int32 ShopRpcBuyReply::result() const {
  // @@protoc_insertion_point(field_get:ShopRpcBuyReply.Result)
  return result_;
}
inline void ShopRpcBuyReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcBuyReply.Result)
}

// optional sint32 ShopType = 2 [default = -1];
inline bool ShopRpcBuyReply::has_shoptype() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ShopRpcBuyReply::set_has_shoptype() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ShopRpcBuyReply::clear_has_shoptype() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ShopRpcBuyReply::clear_shoptype() {
  shoptype_ = -1;
  clear_has_shoptype();
}
inline ::google::protobuf::int32 ShopRpcBuyReply::shoptype() const {
  // @@protoc_insertion_point(field_get:ShopRpcBuyReply.ShopType)
  return shoptype_;
}
inline void ShopRpcBuyReply::set_shoptype(::google::protobuf::int32 value) {
  set_has_shoptype();
  shoptype_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcBuyReply.ShopType)
}

// optional sint32 ItemId = 3 [default = -1];
inline bool ShopRpcBuyReply::has_itemid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ShopRpcBuyReply::set_has_itemid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ShopRpcBuyReply::clear_has_itemid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ShopRpcBuyReply::clear_itemid() {
  itemid_ = -1;
  clear_has_itemid();
}
inline ::google::protobuf::int32 ShopRpcBuyReply::itemid() const {
  // @@protoc_insertion_point(field_get:ShopRpcBuyReply.ItemId)
  return itemid_;
}
inline void ShopRpcBuyReply::set_itemid(::google::protobuf::int32 value) {
  set_has_itemid();
  itemid_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcBuyReply.ItemId)
}

// optional sint32 Pos = 4 [default = -1];
inline bool ShopRpcBuyReply::has_pos() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ShopRpcBuyReply::set_has_pos() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ShopRpcBuyReply::clear_has_pos() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ShopRpcBuyReply::clear_pos() {
  pos_ = -1;
  clear_has_pos();
}
inline ::google::protobuf::int32 ShopRpcBuyReply::pos() const {
  // @@protoc_insertion_point(field_get:ShopRpcBuyReply.Pos)
  return pos_;
}
inline void ShopRpcBuyReply::set_pos(::google::protobuf::int32 value) {
  set_has_pos();
  pos_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcBuyReply.Pos)
}

// -------------------------------------------------------------------

// ShopRpcRefreshItemAsk

// optional sint32 ShopType = 2 [default = -1];
inline bool ShopRpcRefreshItemAsk::has_shoptype() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ShopRpcRefreshItemAsk::set_has_shoptype() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ShopRpcRefreshItemAsk::clear_has_shoptype() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ShopRpcRefreshItemAsk::clear_shoptype() {
  shoptype_ = -1;
  clear_has_shoptype();
}
inline ::google::protobuf::int32 ShopRpcRefreshItemAsk::shoptype() const {
  // @@protoc_insertion_point(field_get:ShopRpcRefreshItemAsk.ShopType)
  return shoptype_;
}
inline void ShopRpcRefreshItemAsk::set_shoptype(::google::protobuf::int32 value) {
  set_has_shoptype();
  shoptype_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcRefreshItemAsk.ShopType)
}

// -------------------------------------------------------------------

// ShopRpcRefreshItemReply

// optional sint32 Result = 1 [default = -9999];
inline bool ShopRpcRefreshItemReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ShopRpcRefreshItemReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ShopRpcRefreshItemReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ShopRpcRefreshItemReply::clear_result() {
  result_ = -9999;
  clear_has_result();
}
inline ::google::protobuf::int32 ShopRpcRefreshItemReply::result() const {
  // @@protoc_insertion_point(field_get:ShopRpcRefreshItemReply.Result)
  return result_;
}
inline void ShopRpcRefreshItemReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcRefreshItemReply.Result)
}

// optional sint32 ShopType = 2 [default = -1];
inline bool ShopRpcRefreshItemReply::has_shoptype() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ShopRpcRefreshItemReply::set_has_shoptype() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ShopRpcRefreshItemReply::clear_has_shoptype() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ShopRpcRefreshItemReply::clear_shoptype() {
  shoptype_ = -1;
  clear_has_shoptype();
}
inline ::google::protobuf::int32 ShopRpcRefreshItemReply::shoptype() const {
  // @@protoc_insertion_point(field_get:ShopRpcRefreshItemReply.ShopType)
  return shoptype_;
}
inline void ShopRpcRefreshItemReply::set_shoptype(::google::protobuf::int32 value) {
  set_has_shoptype();
  shoptype_ = value;
  // @@protoc_insertion_point(field_set:ShopRpcRefreshItemReply.ShopType)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ShopRpc_2eproto__INCLUDED
