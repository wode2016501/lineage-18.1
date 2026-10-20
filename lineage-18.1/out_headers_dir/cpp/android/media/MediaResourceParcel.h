#ifndef AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_PARCEL_H_
#define AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_PARCEL_H_

#include <android/media/MediaResourceSubType.h>
#include <android/media/MediaResourceType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace android {

namespace media {

class MediaResourceParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value)!=std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator<(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value)<std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator<=(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value)<=std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator==(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value)==std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator>(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value)>std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  inline bool operator>=(const MediaResourceParcel& rhs) const {
    return std::tie(type, subType, id, value)>=std::tie(rhs.type, rhs.subType, rhs.id, rhs.value);
  }
  ::android::media::MediaResourceType type;
  ::android::media::MediaResourceSubType subType;
  ::std::vector<uint8_t> id;
  int64_t value = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class MediaResourceParcel

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_PARCEL_H_
