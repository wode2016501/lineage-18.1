#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace dvr {
class IVirtualTouchpadService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IVirtualTouchpadService();
  virtual ~IVirtualTouchpadService();

  static const char* SERVICE_NAME;


  static std::shared_ptr<IVirtualTouchpadService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IVirtualTouchpadService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IVirtualTouchpadService>* instance);
  static bool setDefaultImpl(std::shared_ptr<IVirtualTouchpadService> impl);
  static const std::shared_ptr<IVirtualTouchpadService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus attach() = 0;
  virtual ::ndk::ScopedAStatus detach() = 0;
  virtual ::ndk::ScopedAStatus touch(int32_t in_touchpad, float in_x, float in_y, float in_pressure) = 0;
  virtual ::ndk::ScopedAStatus buttonState(int32_t in_touchpad, int32_t in_buttons) = 0;
  virtual ::ndk::ScopedAStatus scroll(int32_t in_touchpad, float in_x, float in_y) = 0;
private:
  static std::shared_ptr<IVirtualTouchpadService> default_impl;
};
class IVirtualTouchpadServiceDefault : public IVirtualTouchpadService {
public:
  ::ndk::ScopedAStatus attach() override;
  ::ndk::ScopedAStatus detach() override;
  ::ndk::ScopedAStatus touch(int32_t in_touchpad, float in_x, float in_y, float in_pressure) override;
  ::ndk::ScopedAStatus buttonState(int32_t in_touchpad, int32_t in_buttons) override;
  ::ndk::ScopedAStatus scroll(int32_t in_touchpad, float in_x, float in_y) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace dvr
}  // namespace android
}  // namespace aidl
