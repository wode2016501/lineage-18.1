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
class IEmpty : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IEmpty();
  virtual ~IEmpty();



  static std::shared_ptr<IEmpty> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IEmpty>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IEmpty>* instance);
  static bool setDefaultImpl(std::shared_ptr<IEmpty> impl);
  static const std::shared_ptr<IEmpty>& getDefaultImpl();
private:
  static std::shared_ptr<IEmpty> default_impl;
};
class IEmptyDefault : public IEmpty {
public:
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace aidl
