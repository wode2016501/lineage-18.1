#ifndef AIDL_GENERATED_ANDROID_DVR_BP_VR_COMPOSER_H_
#define AIDL_GENERATED_ANDROID_DVR_BP_VR_COMPOSER_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/dvr/IVrComposer.h>

namespace android {

namespace dvr {

class BpVrComposer : public ::android::BpInterface<IVrComposer> {
public:
  explicit BpVrComposer(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVrComposer() = default;
  ::android::binder::Status registerObserver(const ::android::sp<::android::dvr::IVrComposerCallback>& callback) override;
  ::android::binder::Status clearObserver() override;
};  // class BpVrComposer

}  // namespace dvr

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_DVR_BP_VR_COMPOSER_H_
