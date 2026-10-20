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
class IMediaExtractor : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IMediaExtractor();
  virtual ~IMediaExtractor();



  static std::shared_ptr<IMediaExtractor> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IMediaExtractor>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IMediaExtractor>* instance);
  static bool setDefaultImpl(std::shared_ptr<IMediaExtractor> impl);
  static const std::shared_ptr<IMediaExtractor>& getDefaultImpl();
private:
  static std::shared_ptr<IMediaExtractor> default_impl;
};
class IMediaExtractorDefault : public IMediaExtractor {
public:
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace android
}  // namespace aidl
