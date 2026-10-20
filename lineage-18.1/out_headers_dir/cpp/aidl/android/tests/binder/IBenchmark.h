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
namespace tests {
namespace binder {
class IBenchmark : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBenchmark();
  virtual ~IBenchmark();



  static std::shared_ptr<IBenchmark> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBenchmark>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBenchmark>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBenchmark> impl);
  static const std::shared_ptr<IBenchmark>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus sendVec(const std::vector<int8_t>& in_data, std::vector<int8_t>* _aidl_return) = 0;
private:
  static std::shared_ptr<IBenchmark> default_impl;
};
class IBenchmarkDefault : public IBenchmark {
public:
  ::ndk::ScopedAStatus sendVec(const std::vector<int8_t>& in_data, std::vector<int8_t>* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace binder
}  // namespace tests
}  // namespace android
}  // namespace aidl
