#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/dvr/IVirtualTouchpadService.h>

namespace android {
namespace dvr {
class BpVirtualTouchpadService : public ::android::BpInterface<IVirtualTouchpadService> {
public:
  explicit BpVirtualTouchpadService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVirtualTouchpadService() = default;
  ::android::binder::Status attach() override;
  ::android::binder::Status detach() override;
  ::android::binder::Status touch(int32_t touchpad, float x, float y, float pressure) override;
  ::android::binder::Status buttonState(int32_t touchpad, int32_t buttons) override;
  ::android::binder::Status scroll(int32_t touchpad, float x, float y) override;
};  // class BpVirtualTouchpadService
}  // namespace dvr
}  // namespace android
