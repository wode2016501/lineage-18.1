#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_REQUEST_NAMESPACE_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_REQUEST_NAMESPACE_H_

#include <android/hardware/identity/RequestDataItem.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace identity {

class RequestNamespace : public ::android::Parcelable {
public:
  inline bool operator!=(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items)!=std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator<(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items)<std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator<=(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items)<=std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator==(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items)==std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator>(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items)>std::tie(rhs.namespaceName, rhs.items);
  }
  inline bool operator>=(const RequestNamespace& rhs) const {
    return std::tie(namespaceName, items)>=std::tie(rhs.namespaceName, rhs.items);
  }
  ::std::string namespaceName;
  ::std::vector<::android::hardware::identity::RequestDataItem> items;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class RequestNamespace

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_REQUEST_NAMESPACE_H_
