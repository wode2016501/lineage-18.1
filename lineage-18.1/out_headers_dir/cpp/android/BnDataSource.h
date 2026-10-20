#ifndef AIDL_GENERATED_ANDROID_BN_DATA_SOURCE_H_
#define AIDL_GENERATED_ANDROID_BN_DATA_SOURCE_H_

#include <binder/IInterface.h>
#include <android/IDataSource.h>

namespace android {

class BnDataSource : public ::android::BnInterface<IDataSource> {
public:
  explicit BnDataSource();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDataSource

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BN_DATA_SOURCE_H_
