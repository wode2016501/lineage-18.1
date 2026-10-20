#ifndef AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_POLICY_PARCEL_H_
#define AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_POLICY_PARCEL_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>

namespace android {

namespace media {

class MediaResourcePolicyParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value)!=std::tie(rhs.type, rhs.value);
  }
  inline bool operator<(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value)<std::tie(rhs.type, rhs.value);
  }
  inline bool operator<=(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value)<=std::tie(rhs.type, rhs.value);
  }
  inline bool operator==(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value)==std::tie(rhs.type, rhs.value);
  }
  inline bool operator>(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value)>std::tie(rhs.type, rhs.value);
  }
  inline bool operator>=(const MediaResourcePolicyParcel& rhs) const {
    return std::tie(type, value)>=std::tie(rhs.type, rhs.value);
  }
  ::std::string type;
  ::std::string value;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class MediaResourcePolicyParcel

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_POLICY_PARCEL_H_
