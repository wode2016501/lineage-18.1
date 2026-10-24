#pragma once

#include <binder/IInterface.h>
#include <android/tests/binder/IBenchmark.h>
#include <android/tests/binder/BnBenchmark.h>
#include <binder/Delegate.h>


namespace android {
namespace tests {
namespace binder {
class BnBenchmark : public ::android::BnInterface<IBenchmark> {
public:
  static constexpr uint32_t TRANSACTION_sendVec = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnBenchmark();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBenchmark

class IBenchmarkDelegator : public BnBenchmark {
public:
  explicit IBenchmarkDelegator(const ::android::sp<IBenchmark> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBenchmark> getImpl() { return _aidl_delegate; }
  ::android::binder::Status sendVec(const ::std::vector<uint8_t>& data, ::std::vector<uint8_t>* _aidl_return) override {
    return _aidl_delegate->sendVec(data, _aidl_return);
  }
private:
  ::android::sp<IBenchmark> _aidl_delegate;
};  // class IBenchmarkDelegator
}  // namespace binder
}  // namespace tests
}  // namespace android
