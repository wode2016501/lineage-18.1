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
#include <aidl/android/bluetooth/IBluetoothGattClientCallback.h>

namespace aidl {
namespace android {
namespace bluetooth {
class IBluetoothGattClient : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBluetoothGattClient();
  virtual ~IBluetoothGattClient();



  static std::shared_ptr<IBluetoothGattClient> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothGattClient>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothGattClient>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBluetoothGattClient> impl);
  static const std::shared_ptr<IBluetoothGattClient>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus RegisterClient(const std::shared_ptr<::aidl::android::bluetooth::IBluetoothGattClientCallback>& in_callback, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus UnregisterClient(int32_t in_client_id) = 0;
  virtual ::ndk::ScopedAStatus UnregisterAll() = 0;
private:
  static std::shared_ptr<IBluetoothGattClient> default_impl;
};
class IBluetoothGattClientDefault : public IBluetoothGattClient {
public:
  ::ndk::ScopedAStatus RegisterClient(const std::shared_ptr<::aidl::android::bluetooth::IBluetoothGattClientCallback>& in_callback, bool* _aidl_return) override;
  ::ndk::ScopedAStatus UnregisterClient(int32_t in_client_id) override;
  ::ndk::ScopedAStatus UnregisterAll() override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
