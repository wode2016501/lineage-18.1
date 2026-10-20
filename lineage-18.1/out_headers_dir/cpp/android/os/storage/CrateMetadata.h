#ifndef AIDL_GENERATED_ANDROID_OS_STORAGE_CRATE_METADATA_H_
#define AIDL_GENERATED_ANDROID_OS_STORAGE_CRATE_METADATA_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>

namespace android {

namespace os {

namespace storage {

class CrateMetadata : public ::android::Parcelable {
public:
  inline bool operator!=(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id)!=std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator<(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id)<std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator<=(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id)<=std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator==(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id)==std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator>(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id)>std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator>=(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id)>=std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  int32_t uid;
  ::std::string packageName;
  ::std::string id;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class CrateMetadata

}  // namespace storage

}  // namespace os

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_OS_STORAGE_CRATE_METADATA_H_
