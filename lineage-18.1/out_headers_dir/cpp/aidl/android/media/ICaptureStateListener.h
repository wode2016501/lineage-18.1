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
namespace media {
class ICaptureStateListener : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ICaptureStateListener();
  virtual ~ICaptureStateListener();



  static std::shared_ptr<ICaptureStateListener> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ICaptureStateListener>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ICaptureStateListener>* instance);
  static bool setDefaultImpl(std::shared_ptr<ICaptureStateListener> impl);
  static const std::shared_ptr<ICaptureStateListener>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus setCaptureState(bool in_active) = 0;
private:
  static std::shared_ptr<ICaptureStateListener> default_impl;
};
class ICaptureStateListenerDefault : public ICaptureStateListener {
public:
  ::ndk::ScopedAStatus setCaptureState(bool in_active) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
