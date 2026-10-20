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
class IAudioTrackCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IAudioTrackCallback();
  virtual ~IAudioTrackCallback();



  static std::shared_ptr<IAudioTrackCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IAudioTrackCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IAudioTrackCallback>* instance);
  static bool setDefaultImpl(std::shared_ptr<IAudioTrackCallback> impl);
  static const std::shared_ptr<IAudioTrackCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onCodecFormatChanged(const std::vector<int8_t>& in_audioMetadata) = 0;
private:
  static std::shared_ptr<IAudioTrackCallback> default_impl;
};
class IAudioTrackCallbackDefault : public IAudioTrackCallback {
public:
  ::ndk::ScopedAStatus onCodecFormatChanged(const std::vector<int8_t>& in_audioMetadata) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
