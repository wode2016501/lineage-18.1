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
class IOMXNode : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IOMXNode();
  virtual ~IOMXNode();



  static std::shared_ptr<IOMXNode> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IOMXNode>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IOMXNode>* instance);
  static bool setDefaultImpl(std::shared_ptr<IOMXNode> impl);
  static const std::shared_ptr<IOMXNode>& getDefaultImpl();
private:
  static std::shared_ptr<IOMXNode> default_impl;
};
class IOMXNodeDefault : public IOMXNode {
public:
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace android
}  // namespace aidl
