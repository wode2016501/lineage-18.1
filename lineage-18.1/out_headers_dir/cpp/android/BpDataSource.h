#ifndef AIDL_GENERATED_ANDROID_BP_DATA_SOURCE_H_
#define AIDL_GENERATED_ANDROID_BP_DATA_SOURCE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/IDataSource.h>

namespace android {

class BpDataSource : public ::android::BpInterface<IDataSource> {
public:
  explicit BpDataSource(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDataSource() = default;
};  // class BpDataSource

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BP_DATA_SOURCE_H_
