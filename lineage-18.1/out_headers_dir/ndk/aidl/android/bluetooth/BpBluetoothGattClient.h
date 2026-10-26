#pragma once

#include "aidl/android/bluetooth/IBluetoothGattClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BpBluetoothGattClient : public ::ndk::BpCInterface<IBluetoothGattClient> {
public:
  BpBluetoothGattClient(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothGattClient();

  ::ndk::ScopedAStatus RegisterClient(const std::shared_ptr<::aidl::android::bluetooth::IBluetoothGattClientCallback>& in_callback, bool* _aidl_return) override;
  ::ndk::ScopedAStatus UnregisterClient(int32_t in_client_id) override;
  ::ndk::ScopedAStatus UnregisterAll() override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
