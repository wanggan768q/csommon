// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ActivityScheduleV1Data.proto

#ifndef PROTOBUF_ActivityScheduleV1Data_2eproto__INCLUDED
#define PROTOBUF_ActivityScheduleV1Data_2eproto__INCLUDED

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
class ActivityScheduleActiveDateV1;
class ActivityScheduleActiveDateV1DefaultTypeInternal;
extern ActivityScheduleActiveDateV1DefaultTypeInternal _ActivityScheduleActiveDateV1_default_instance_;
class ActivityScheduleActiveValueV1;
class ActivityScheduleActiveValueV1DefaultTypeInternal;
extern ActivityScheduleActiveValueV1DefaultTypeInternal _ActivityScheduleActiveValueV1_default_instance_;

namespace protobuf_ActivityScheduleV1Data_2eproto {
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
}  // namespace protobuf_ActivityScheduleV1Data_2eproto

// ===================================================================

class ActivityScheduleActiveDateV1 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ActivityScheduleActiveDateV1) */ {
 public:
  ActivityScheduleActiveDateV1();
  virtual ~ActivityScheduleActiveDateV1();

  ActivityScheduleActiveDateV1(const ActivityScheduleActiveDateV1& from);

  inline ActivityScheduleActiveDateV1& operator=(const ActivityScheduleActiveDateV1& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ActivityScheduleActiveDateV1(ActivityScheduleActiveDateV1&& from) noexcept
    : ActivityScheduleActiveDateV1() {
    *this = ::std::move(from);
  }

  inline ActivityScheduleActiveDateV1& operator=(ActivityScheduleActiveDateV1&& from) noexcept {
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
  static const ActivityScheduleActiveDateV1& default_instance();

  static inline const ActivityScheduleActiveDateV1* internal_default_instance() {
    return reinterpret_cast<const ActivityScheduleActiveDateV1*>(
               &_ActivityScheduleActiveDateV1_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ActivityScheduleActiveDateV1* other);
  friend void swap(ActivityScheduleActiveDateV1& a, ActivityScheduleActiveDateV1& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ActivityScheduleActiveDateV1* New() const PROTOBUF_FINAL { return New(NULL); }

  ActivityScheduleActiveDateV1* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ActivityScheduleActiveDateV1& from);
  void MergeFrom(const ActivityScheduleActiveDateV1& from);
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
  void InternalSwap(ActivityScheduleActiveDateV1* other);
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

  // repeated .ActivityScheduleActiveValueV1 Value = 1;
  int value_size() const;
  void clear_value();
  static const int kValueFieldNumber = 1;
  const ::ActivityScheduleActiveValueV1& value(int index) const;
  ::ActivityScheduleActiveValueV1* mutable_value(int index);
  ::ActivityScheduleActiveValueV1* add_value();
  ::google::protobuf::RepeatedPtrField< ::ActivityScheduleActiveValueV1 >*
      mutable_value();
  const ::google::protobuf::RepeatedPtrField< ::ActivityScheduleActiveValueV1 >&
      value() const;

  // optional sint32 Time = 2 [default = -1];
  bool has_time() const;
  void clear_time();
  static const int kTimeFieldNumber = 2;
  ::google::protobuf::int32 time() const;
  void set_time(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ActivityScheduleActiveDateV1)
 private:
  void set_has_time();
  void clear_has_time();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::ActivityScheduleActiveValueV1 > value_;
  ::google::protobuf::int32 time_;
  friend struct protobuf_ActivityScheduleV1Data_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ActivityScheduleActiveValueV1 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ActivityScheduleActiveValueV1) */ {
 public:
  ActivityScheduleActiveValueV1();
  virtual ~ActivityScheduleActiveValueV1();

  ActivityScheduleActiveValueV1(const ActivityScheduleActiveValueV1& from);

  inline ActivityScheduleActiveValueV1& operator=(const ActivityScheduleActiveValueV1& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ActivityScheduleActiveValueV1(ActivityScheduleActiveValueV1&& from) noexcept
    : ActivityScheduleActiveValueV1() {
    *this = ::std::move(from);
  }

  inline ActivityScheduleActiveValueV1& operator=(ActivityScheduleActiveValueV1&& from) noexcept {
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
  static const ActivityScheduleActiveValueV1& default_instance();

  static inline const ActivityScheduleActiveValueV1* internal_default_instance() {
    return reinterpret_cast<const ActivityScheduleActiveValueV1*>(
               &_ActivityScheduleActiveValueV1_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ActivityScheduleActiveValueV1* other);
  friend void swap(ActivityScheduleActiveValueV1& a, ActivityScheduleActiveValueV1& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ActivityScheduleActiveValueV1* New() const PROTOBUF_FINAL { return New(NULL); }

  ActivityScheduleActiveValueV1* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ActivityScheduleActiveValueV1& from);
  void MergeFrom(const ActivityScheduleActiveValueV1& from);
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
  void InternalSwap(ActivityScheduleActiveValueV1* other);
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

  // optional sint32 ID = 1 [default = 0];
  bool has_id() const;
  void clear_id();
  static const int kIDFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // optional sint32 Num = 2 [default = 0];
  bool has_num() const;
  void clear_num();
  static const int kNumFieldNumber = 2;
  ::google::protobuf::int32 num() const;
  void set_num(::google::protobuf::int32 value);

  // optional sint32 Vitality = 3 [default = 0];
  bool has_vitality() const;
  void clear_vitality();
  static const int kVitalityFieldNumber = 3;
  ::google::protobuf::int32 vitality() const;
  void set_vitality(::google::protobuf::int32 value);

  // optional sint32 ActivityMaxNum = 6 [default = -1];
  bool has_activitymaxnum() const;
  void clear_activitymaxnum();
  static const int kActivityMaxNumFieldNumber = 6;
  ::google::protobuf::int32 activitymaxnum() const;
  void set_activitymaxnum(::google::protobuf::int32 value);

  // optional sint32 StartTime = 4 [default = -1];
  bool has_starttime() const;
  void clear_starttime();
  static const int kStartTimeFieldNumber = 4;
  ::google::protobuf::int32 starttime() const;
  void set_starttime(::google::protobuf::int32 value);

  // optional sint32 FinishTime = 5 [default = -1];
  bool has_finishtime() const;
  void clear_finishtime();
  static const int kFinishTimeFieldNumber = 5;
  ::google::protobuf::int32 finishtime() const;
  void set_finishtime(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ActivityScheduleActiveValueV1)
 private:
  void set_has_id();
  void clear_has_id();
  void set_has_num();
  void clear_has_num();
  void set_has_vitality();
  void clear_has_vitality();
  void set_has_starttime();
  void clear_has_starttime();
  void set_has_finishtime();
  void clear_has_finishtime();
  void set_has_activitymaxnum();
  void clear_has_activitymaxnum();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 num_;
  ::google::protobuf::int32 vitality_;
  ::google::protobuf::int32 activitymaxnum_;
  ::google::protobuf::int32 starttime_;
  ::google::protobuf::int32 finishtime_;
  friend struct protobuf_ActivityScheduleV1Data_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ActivityScheduleActiveDateV1

// repeated .ActivityScheduleActiveValueV1 Value = 1;
inline int ActivityScheduleActiveDateV1::value_size() const {
  return value_.size();
}
inline void ActivityScheduleActiveDateV1::clear_value() {
  value_.Clear();
}
inline const ::ActivityScheduleActiveValueV1& ActivityScheduleActiveDateV1::value(int index) const {
  // @@protoc_insertion_point(field_get:ActivityScheduleActiveDateV1.Value)
  return value_.Get(index);
}
inline ::ActivityScheduleActiveValueV1* ActivityScheduleActiveDateV1::mutable_value(int index) {
  // @@protoc_insertion_point(field_mutable:ActivityScheduleActiveDateV1.Value)
  return value_.Mutable(index);
}
inline ::ActivityScheduleActiveValueV1* ActivityScheduleActiveDateV1::add_value() {
  // @@protoc_insertion_point(field_add:ActivityScheduleActiveDateV1.Value)
  return value_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::ActivityScheduleActiveValueV1 >*
ActivityScheduleActiveDateV1::mutable_value() {
  // @@protoc_insertion_point(field_mutable_list:ActivityScheduleActiveDateV1.Value)
  return &value_;
}
inline const ::google::protobuf::RepeatedPtrField< ::ActivityScheduleActiveValueV1 >&
ActivityScheduleActiveDateV1::value() const {
  // @@protoc_insertion_point(field_list:ActivityScheduleActiveDateV1.Value)
  return value_;
}

// optional sint32 Time = 2 [default = -1];
inline bool ActivityScheduleActiveDateV1::has_time() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ActivityScheduleActiveDateV1::set_has_time() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ActivityScheduleActiveDateV1::clear_has_time() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ActivityScheduleActiveDateV1::clear_time() {
  time_ = -1;
  clear_has_time();
}
inline ::google::protobuf::int32 ActivityScheduleActiveDateV1::time() const {
  // @@protoc_insertion_point(field_get:ActivityScheduleActiveDateV1.Time)
  return time_;
}
inline void ActivityScheduleActiveDateV1::set_time(::google::protobuf::int32 value) {
  set_has_time();
  time_ = value;
  // @@protoc_insertion_point(field_set:ActivityScheduleActiveDateV1.Time)
}

// -------------------------------------------------------------------

// ActivityScheduleActiveValueV1

// optional sint32 ID = 1 [default = 0];
inline bool ActivityScheduleActiveValueV1::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ActivityScheduleActiveValueV1::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ActivityScheduleActiveValueV1::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ActivityScheduleActiveValueV1::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 ActivityScheduleActiveValueV1::id() const {
  // @@protoc_insertion_point(field_get:ActivityScheduleActiveValueV1.ID)
  return id_;
}
inline void ActivityScheduleActiveValueV1::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:ActivityScheduleActiveValueV1.ID)
}

// optional sint32 Num = 2 [default = 0];
inline bool ActivityScheduleActiveValueV1::has_num() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ActivityScheduleActiveValueV1::set_has_num() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ActivityScheduleActiveValueV1::clear_has_num() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ActivityScheduleActiveValueV1::clear_num() {
  num_ = 0;
  clear_has_num();
}
inline ::google::protobuf::int32 ActivityScheduleActiveValueV1::num() const {
  // @@protoc_insertion_point(field_get:ActivityScheduleActiveValueV1.Num)
  return num_;
}
inline void ActivityScheduleActiveValueV1::set_num(::google::protobuf::int32 value) {
  set_has_num();
  num_ = value;
  // @@protoc_insertion_point(field_set:ActivityScheduleActiveValueV1.Num)
}

// optional sint32 Vitality = 3 [default = 0];
inline bool ActivityScheduleActiveValueV1::has_vitality() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ActivityScheduleActiveValueV1::set_has_vitality() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ActivityScheduleActiveValueV1::clear_has_vitality() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ActivityScheduleActiveValueV1::clear_vitality() {
  vitality_ = 0;
  clear_has_vitality();
}
inline ::google::protobuf::int32 ActivityScheduleActiveValueV1::vitality() const {
  // @@protoc_insertion_point(field_get:ActivityScheduleActiveValueV1.Vitality)
  return vitality_;
}
inline void ActivityScheduleActiveValueV1::set_vitality(::google::protobuf::int32 value) {
  set_has_vitality();
  vitality_ = value;
  // @@protoc_insertion_point(field_set:ActivityScheduleActiveValueV1.Vitality)
}

// optional sint32 StartTime = 4 [default = -1];
inline bool ActivityScheduleActiveValueV1::has_starttime() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ActivityScheduleActiveValueV1::set_has_starttime() {
  _has_bits_[0] |= 0x00000010u;
}
inline void ActivityScheduleActiveValueV1::clear_has_starttime() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void ActivityScheduleActiveValueV1::clear_starttime() {
  starttime_ = -1;
  clear_has_starttime();
}
inline ::google::protobuf::int32 ActivityScheduleActiveValueV1::starttime() const {
  // @@protoc_insertion_point(field_get:ActivityScheduleActiveValueV1.StartTime)
  return starttime_;
}
inline void ActivityScheduleActiveValueV1::set_starttime(::google::protobuf::int32 value) {
  set_has_starttime();
  starttime_ = value;
  // @@protoc_insertion_point(field_set:ActivityScheduleActiveValueV1.StartTime)
}

// optional sint32 FinishTime = 5 [default = -1];
inline bool ActivityScheduleActiveValueV1::has_finishtime() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ActivityScheduleActiveValueV1::set_has_finishtime() {
  _has_bits_[0] |= 0x00000020u;
}
inline void ActivityScheduleActiveValueV1::clear_has_finishtime() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void ActivityScheduleActiveValueV1::clear_finishtime() {
  finishtime_ = -1;
  clear_has_finishtime();
}
inline ::google::protobuf::int32 ActivityScheduleActiveValueV1::finishtime() const {
  // @@protoc_insertion_point(field_get:ActivityScheduleActiveValueV1.FinishTime)
  return finishtime_;
}
inline void ActivityScheduleActiveValueV1::set_finishtime(::google::protobuf::int32 value) {
  set_has_finishtime();
  finishtime_ = value;
  // @@protoc_insertion_point(field_set:ActivityScheduleActiveValueV1.FinishTime)
}

// optional sint32 ActivityMaxNum = 6 [default = -1];
inline bool ActivityScheduleActiveValueV1::has_activitymaxnum() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ActivityScheduleActiveValueV1::set_has_activitymaxnum() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ActivityScheduleActiveValueV1::clear_has_activitymaxnum() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ActivityScheduleActiveValueV1::clear_activitymaxnum() {
  activitymaxnum_ = -1;
  clear_has_activitymaxnum();
}
inline ::google::protobuf::int32 ActivityScheduleActiveValueV1::activitymaxnum() const {
  // @@protoc_insertion_point(field_get:ActivityScheduleActiveValueV1.ActivityMaxNum)
  return activitymaxnum_;
}
inline void ActivityScheduleActiveValueV1::set_activitymaxnum(::google::protobuf::int32 value) {
  set_has_activitymaxnum();
  activitymaxnum_ = value;
  // @@protoc_insertion_point(field_set:ActivityScheduleActiveValueV1.ActivityMaxNum)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ActivityScheduleV1Data_2eproto__INCLUDED
