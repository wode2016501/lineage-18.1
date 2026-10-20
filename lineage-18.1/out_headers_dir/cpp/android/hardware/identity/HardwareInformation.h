#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_HARDWARE_INFORMATION_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_HARDWARE_INFORMATION_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace identity {

class HardwareInformation : public ::android::Parcelable {
public:
  inline bool operator!=(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes)!=std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator<(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes)<std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator<=(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes)<=std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator==(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes)==std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator>(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes)>std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  inline bool operator>=(const HardwareInformation& rhs) const {
    return std::tie(credentialStoreName, credentialStoreAuthorName, dataChunkSize, isDirectAccess, supportedDocTypes)>=std::tie(rhs.credentialStoreName, rhs.credentialStoreAuthorName, rhs.dataChunkSize, rhs.isDirectAccess, rhs.supportedDocTypes);
  }
  ::std::string credentialStoreName;
  ::std::string credentialStoreAuthorName;
  int32_t dataChunkSize;
  bool isDirectAccess;
  ::std::vector<::std::string> supportedDocTypes;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class HardwareInformation

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_HARDWARE_INFORMATION_H_
