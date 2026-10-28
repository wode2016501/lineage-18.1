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
class IDataSource : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IDataSource();
  virtual ~IDataSource();



  static std::shared_ptr<IDataSource> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IDataSource>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IDataSource>* instance);
  static bool setDefaultImpl(std::shared_ptr<IDataSource> impl);
  static const std::shared_ptr<IDataSource>& getDefaultImpl();
private:
  static std::shared_ptr<IDataSource> default_impl;
};
class IDataSourceDefault : public IDataSource {
public:
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace android
}  // namespace aidl
