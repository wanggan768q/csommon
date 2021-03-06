// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: OneVSOneV1Data.proto

#ifndef PROTOBUF_OneVSOneV1Data_2eproto__INCLUDED
#define PROTOBUF_OneVSOneV1Data_2eproto__INCLUDED

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
class OneVSOneOneVSOneDateV1;
class OneVSOneOneVSOneDateV1DefaultTypeInternal;
extern OneVSOneOneVSOneDateV1DefaultTypeInternal _OneVSOneOneVSOneDateV1_default_instance_;

namespace protobuf_OneVSOneV1Data_2eproto {
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
}  // namespace protobuf_OneVSOneV1Data_2eproto

// ===================================================================

class OneVSOneOneVSOneDateV1 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:OneVSOneOneVSOneDateV1) */ {
 public:
  OneVSOneOneVSOneDateV1();
  virtual ~OneVSOneOneVSOneDateV1();

  OneVSOneOneVSOneDateV1(const OneVSOneOneVSOneDateV1& from);

  inline OneVSOneOneVSOneDateV1& operator=(const OneVSOneOneVSOneDateV1& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  OneVSOneOneVSOneDateV1(OneVSOneOneVSOneDateV1&& from) noexcept
    : OneVSOneOneVSOneDateV1() {
    *this = ::std::move(from);
  }

  inline OneVSOneOneVSOneDateV1& operator=(OneVSOneOneVSOneDateV1&& from) noexcept {
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
  static const OneVSOneOneVSOneDateV1& default_instance();

  static inline const OneVSOneOneVSOneDateV1* internal_default_instance() {
    return reinterpret_cast<const OneVSOneOneVSOneDateV1*>(
               &_OneVSOneOneVSOneDateV1_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(OneVSOneOneVSOneDateV1* other);
  friend void swap(OneVSOneOneVSOneDateV1& a, OneVSOneOneVSOneDateV1& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline OneVSOneOneVSOneDateV1* New() const PROTOBUF_FINAL { return New(NULL); }

  OneVSOneOneVSOneDateV1* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const OneVSOneOneVSOneDateV1& from);
  void MergeFrom(const OneVSOneOneVSOneDateV1& from);
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
  void InternalSwap(OneVSOneOneVSOneDateV1* other);
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

  // repeated .OneSData SkillDate = 4;
  int skilldate_size() const;
  void clear_skilldate();
  static const int kSkillDateFieldNumber = 4;
  const ::OneSData& skilldate(int index) const;
  ::OneSData* mutable_skilldate(int index);
  ::OneSData* add_skilldate();
  ::google::protobuf::RepeatedPtrField< ::OneSData >*
      mutable_skilldate();
  const ::google::protobuf::RepeatedPtrField< ::OneSData >&
      skilldate() const;

  // repeated .ActMessage Log = 5;
  int log_size() const;
  void clear_log();
  static const int kLogFieldNumber = 5;
  const ::ActMessage& log(int index) const;
  ::ActMessage* mutable_log(int index);
  ::ActMessage* add_log();
  ::google::protobuf::RepeatedPtrField< ::ActMessage >*
      mutable_log();
  const ::google::protobuf::RepeatedPtrField< ::ActMessage >&
      log() const;

  // repeated .TimeTop RankingTimes = 10;
  int rankingtimes_size() const;
  void clear_rankingtimes();
  static const int kRankingTimesFieldNumber = 10;
  const ::TimeTop& rankingtimes(int index) const;
  ::TimeTop* mutable_rankingtimes(int index);
  ::TimeTop* add_rankingtimes();
  ::google::protobuf::RepeatedPtrField< ::TimeTop >*
      mutable_rankingtimes();
  const ::google::protobuf::RepeatedPtrField< ::TimeTop >&
      rankingtimes() const;

  // optional sint32 Ranking = 8 [default = 0];
  bool has_ranking() const;
  void clear_ranking();
  static const int kRankingFieldNumber = 8;
  ::google::protobuf::int32 ranking() const;
  void set_ranking(::google::protobuf::int32 value);

  // optional sint32 OneVSOneNum = 6 [default = -1];
  bool has_onevsonenum() const;
  void clear_onevsonenum();
  static const int kOneVSOneNumFieldNumber = 6;
  ::google::protobuf::int32 onevsonenum() const;
  void set_onevsonenum(::google::protobuf::int32 value);

  // optional sint64 SaveTime = 7 [default = -1];
  bool has_savetime() const;
  void clear_savetime();
  static const int kSaveTimeFieldNumber = 7;
  ::google::protobuf::int64 savetime() const;
  void set_savetime(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:OneVSOneOneVSOneDateV1)
 private:
  void set_has_onevsonenum();
  void clear_has_onevsonenum();
  void set_has_savetime();
  void clear_has_savetime();
  void set_has_ranking();
  void clear_has_ranking();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::OneSData > skilldate_;
  ::google::protobuf::RepeatedPtrField< ::ActMessage > log_;
  ::google::protobuf::RepeatedPtrField< ::TimeTop > rankingtimes_;
  ::google::protobuf::int32 ranking_;
  ::google::protobuf::int32 onevsonenum_;
  ::google::protobuf::int64 savetime_;
  friend struct protobuf_OneVSOneV1Data_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// OneVSOneOneVSOneDateV1

// repeated .OneSData SkillDate = 4;
inline int OneVSOneOneVSOneDateV1::skilldate_size() const {
  return skilldate_.size();
}
inline void OneVSOneOneVSOneDateV1::clear_skilldate() {
  skilldate_.Clear();
}
inline const ::OneSData& OneVSOneOneVSOneDateV1::skilldate(int index) const {
  // @@protoc_insertion_point(field_get:OneVSOneOneVSOneDateV1.SkillDate)
  return skilldate_.Get(index);
}
inline ::OneSData* OneVSOneOneVSOneDateV1::mutable_skilldate(int index) {
  // @@protoc_insertion_point(field_mutable:OneVSOneOneVSOneDateV1.SkillDate)
  return skilldate_.Mutable(index);
}
inline ::OneSData* OneVSOneOneVSOneDateV1::add_skilldate() {
  // @@protoc_insertion_point(field_add:OneVSOneOneVSOneDateV1.SkillDate)
  return skilldate_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::OneSData >*
OneVSOneOneVSOneDateV1::mutable_skilldate() {
  // @@protoc_insertion_point(field_mutable_list:OneVSOneOneVSOneDateV1.SkillDate)
  return &skilldate_;
}
inline const ::google::protobuf::RepeatedPtrField< ::OneSData >&
OneVSOneOneVSOneDateV1::skilldate() const {
  // @@protoc_insertion_point(field_list:OneVSOneOneVSOneDateV1.SkillDate)
  return skilldate_;
}

// repeated .ActMessage Log = 5;
inline int OneVSOneOneVSOneDateV1::log_size() const {
  return log_.size();
}
inline void OneVSOneOneVSOneDateV1::clear_log() {
  log_.Clear();
}
inline const ::ActMessage& OneVSOneOneVSOneDateV1::log(int index) const {
  // @@protoc_insertion_point(field_get:OneVSOneOneVSOneDateV1.Log)
  return log_.Get(index);
}
inline ::ActMessage* OneVSOneOneVSOneDateV1::mutable_log(int index) {
  // @@protoc_insertion_point(field_mutable:OneVSOneOneVSOneDateV1.Log)
  return log_.Mutable(index);
}
inline ::ActMessage* OneVSOneOneVSOneDateV1::add_log() {
  // @@protoc_insertion_point(field_add:OneVSOneOneVSOneDateV1.Log)
  return log_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::ActMessage >*
OneVSOneOneVSOneDateV1::mutable_log() {
  // @@protoc_insertion_point(field_mutable_list:OneVSOneOneVSOneDateV1.Log)
  return &log_;
}
inline const ::google::protobuf::RepeatedPtrField< ::ActMessage >&
OneVSOneOneVSOneDateV1::log() const {
  // @@protoc_insertion_point(field_list:OneVSOneOneVSOneDateV1.Log)
  return log_;
}

// optional sint32 OneVSOneNum = 6 [default = -1];
inline bool OneVSOneOneVSOneDateV1::has_onevsonenum() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void OneVSOneOneVSOneDateV1::set_has_onevsonenum() {
  _has_bits_[0] |= 0x00000002u;
}
inline void OneVSOneOneVSOneDateV1::clear_has_onevsonenum() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void OneVSOneOneVSOneDateV1::clear_onevsonenum() {
  onevsonenum_ = -1;
  clear_has_onevsonenum();
}
inline ::google::protobuf::int32 OneVSOneOneVSOneDateV1::onevsonenum() const {
  // @@protoc_insertion_point(field_get:OneVSOneOneVSOneDateV1.OneVSOneNum)
  return onevsonenum_;
}
inline void OneVSOneOneVSOneDateV1::set_onevsonenum(::google::protobuf::int32 value) {
  set_has_onevsonenum();
  onevsonenum_ = value;
  // @@protoc_insertion_point(field_set:OneVSOneOneVSOneDateV1.OneVSOneNum)
}

// optional sint64 SaveTime = 7 [default = -1];
inline bool OneVSOneOneVSOneDateV1::has_savetime() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void OneVSOneOneVSOneDateV1::set_has_savetime() {
  _has_bits_[0] |= 0x00000004u;
}
inline void OneVSOneOneVSOneDateV1::clear_has_savetime() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void OneVSOneOneVSOneDateV1::clear_savetime() {
  savetime_ = GOOGLE_LONGLONG(-1);
  clear_has_savetime();
}
inline ::google::protobuf::int64 OneVSOneOneVSOneDateV1::savetime() const {
  // @@protoc_insertion_point(field_get:OneVSOneOneVSOneDateV1.SaveTime)
  return savetime_;
}
inline void OneVSOneOneVSOneDateV1::set_savetime(::google::protobuf::int64 value) {
  set_has_savetime();
  savetime_ = value;
  // @@protoc_insertion_point(field_set:OneVSOneOneVSOneDateV1.SaveTime)
}

// optional sint32 Ranking = 8 [default = 0];
inline bool OneVSOneOneVSOneDateV1::has_ranking() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void OneVSOneOneVSOneDateV1::set_has_ranking() {
  _has_bits_[0] |= 0x00000001u;
}
inline void OneVSOneOneVSOneDateV1::clear_has_ranking() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void OneVSOneOneVSOneDateV1::clear_ranking() {
  ranking_ = 0;
  clear_has_ranking();
}
inline ::google::protobuf::int32 OneVSOneOneVSOneDateV1::ranking() const {
  // @@protoc_insertion_point(field_get:OneVSOneOneVSOneDateV1.Ranking)
  return ranking_;
}
inline void OneVSOneOneVSOneDateV1::set_ranking(::google::protobuf::int32 value) {
  set_has_ranking();
  ranking_ = value;
  // @@protoc_insertion_point(field_set:OneVSOneOneVSOneDateV1.Ranking)
}

// repeated .TimeTop RankingTimes = 10;
inline int OneVSOneOneVSOneDateV1::rankingtimes_size() const {
  return rankingtimes_.size();
}
inline void OneVSOneOneVSOneDateV1::clear_rankingtimes() {
  rankingtimes_.Clear();
}
inline const ::TimeTop& OneVSOneOneVSOneDateV1::rankingtimes(int index) const {
  // @@protoc_insertion_point(field_get:OneVSOneOneVSOneDateV1.RankingTimes)
  return rankingtimes_.Get(index);
}
inline ::TimeTop* OneVSOneOneVSOneDateV1::mutable_rankingtimes(int index) {
  // @@protoc_insertion_point(field_mutable:OneVSOneOneVSOneDateV1.RankingTimes)
  return rankingtimes_.Mutable(index);
}
inline ::TimeTop* OneVSOneOneVSOneDateV1::add_rankingtimes() {
  // @@protoc_insertion_point(field_add:OneVSOneOneVSOneDateV1.RankingTimes)
  return rankingtimes_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::TimeTop >*
OneVSOneOneVSOneDateV1::mutable_rankingtimes() {
  // @@protoc_insertion_point(field_mutable_list:OneVSOneOneVSOneDateV1.RankingTimes)
  return &rankingtimes_;
}
inline const ::google::protobuf::RepeatedPtrField< ::TimeTop >&
OneVSOneOneVSOneDateV1::rankingtimes() const {
  // @@protoc_insertion_point(field_list:OneVSOneOneVSOneDateV1.RankingTimes)
  return rankingtimes_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_OneVSOneV1Data_2eproto__INCLUDED
