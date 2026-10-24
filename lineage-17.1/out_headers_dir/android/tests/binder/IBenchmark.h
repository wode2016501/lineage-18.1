#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace tests {
namespace binder {
class IBenchmarkDelegator;

class IBenchmark : public ::android::IInterface {
public:
  typedef IBenchmarkDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(Benchmark)
  virtual ::android::binder::Status sendVec(const ::std::vector<uint8_t>& data, ::std::vector<uint8_t>* _aidl_return) = 0;
};  // class IBenchmark

class IBenchmarkDefault : public IBenchmark {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status sendVec(const ::std::vector<uint8_t>& /*data*/, ::std::vector<uint8_t>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBenchmarkDefault
}  // namespace binder
}  // namespace tests
}  // namespace android
