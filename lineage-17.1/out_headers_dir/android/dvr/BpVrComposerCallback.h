#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/dvr/IVrComposerCallback.h>

namespace android {
namespace dvr {
class BpVrComposerCallback : public ::android::BpInterface<IVrComposerCallback> {
public:
  explicit BpVrComposerCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVrComposerCallback() = default;
  ::android::binder::Status onNewFrame(const ::android::dvr::ParcelableComposerFrame& frame, ::android::dvr::ParcelableUniqueFd* _aidl_return) override;
};  // class BpVrComposerCallback
}  // namespace dvr
}  // namespace android
