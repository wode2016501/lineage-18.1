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
class IAidlStuff : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IAidlStuff();
  virtual ~IAidlStuff();



  static std::shared_ptr<IAidlStuff> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IAidlStuff>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IAidlStuff>* instance);
  static bool setDefaultImpl(std::shared_ptr<IAidlStuff> impl);
  static const std::shared_ptr<IAidlStuff>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus callLocal() = 0;
  virtual ::ndk::ScopedAStatus call(int32_t in_idx) = 0;
private:
  static std::shared_ptr<IAidlStuff> default_impl;
};
class IAidlStuffDefault : public IAidlStuff {
public:
  ::ndk::ScopedAStatus callLocal() override;
  ::ndk::ScopedAStatus call(int32_t in_idx) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace aidl
