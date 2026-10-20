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
namespace os {
class IDumpstateListener : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IDumpstateListener();
  virtual ~IDumpstateListener();


  enum : int32_t {
    BUGREPORT_ERROR_INVALID_INPUT = 1,
    BUGREPORT_ERROR_RUNTIME_ERROR = 2,
    BUGREPORT_ERROR_USER_DENIED_CONSENT = 3,
    BUGREPORT_ERROR_USER_CONSENT_TIMED_OUT = 4,
    BUGREPORT_ERROR_ANOTHER_REPORT_IN_PROGRESS = 5,
  };

  static std::shared_ptr<IDumpstateListener> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IDumpstateListener>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IDumpstateListener>* instance);
  static bool setDefaultImpl(std::shared_ptr<IDumpstateListener> impl);
  static const std::shared_ptr<IDumpstateListener>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onProgress(int32_t in_progress) = 0;
  virtual ::ndk::ScopedAStatus onError(int32_t in_errorCode) = 0;
  virtual ::ndk::ScopedAStatus onFinished() = 0;
  virtual ::ndk::ScopedAStatus onScreenshotTaken(bool in_success) = 0;
  virtual ::ndk::ScopedAStatus onUiIntensiveBugreportDumpsFinished(const std::string& in_callingPackage) = 0;
private:
  static std::shared_ptr<IDumpstateListener> default_impl;
};
class IDumpstateListenerDefault : public IDumpstateListener {
public:
  ::ndk::ScopedAStatus onProgress(int32_t in_progress) override;
  ::ndk::ScopedAStatus onError(int32_t in_errorCode) override;
  ::ndk::ScopedAStatus onFinished() override;
  ::ndk::ScopedAStatus onScreenshotTaken(bool in_success) override;
  ::ndk::ScopedAStatus onUiIntensiveBugreportDumpsFinished(const std::string& in_callingPackage) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
