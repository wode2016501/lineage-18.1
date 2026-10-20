#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_REQUEST_DATA_ITEM_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_REQUEST_DATA_ITEM_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace identity {

class RequestDataItem : public ::android::Parcelable {
public:
  inline bool operator!=(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds)!=std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator<(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds)<std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator<=(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds)<=std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator==(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds)==std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator>(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds)>std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  inline bool operator>=(const RequestDataItem& rhs) const {
    return std::tie(name, size, accessControlProfileIds)>=std::tie(rhs.name, rhs.size, rhs.accessControlProfileIds);
  }
  ::std::string name;
  int64_t size;
  ::std::vector<int32_t> accessControlProfileIds;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class RequestDataItem

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_REQUEST_DATA_ITEM_H_
