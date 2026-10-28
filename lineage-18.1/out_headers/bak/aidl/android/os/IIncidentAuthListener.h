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
class IIncidentAuthListener : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IIncidentAuthListener();
  virtual ~IIncidentAuthListener();



  static std::shared_ptr<IIncidentAuthListener> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IIncidentAuthListener>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IIncidentAuthListener>* instance);
  static bool setDefaultImpl(std::shared_ptr<IIncidentAuthListener> impl);
  static const std::shared_ptr<IIncidentAuthListener>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onReportApproved() = 0;
  virtual ::ndk::ScopedAStatus onReportDenied() = 0;
private:
  static std::shared_ptr<IIncidentAuthListener> default_impl;
};
class IIncidentAuthListenerDefault : public IIncidentAuthListener {
public:
  ::ndk::ScopedAStatus onReportApproved() override;
  ::ndk::ScopedAStatus onReportDenied() override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
