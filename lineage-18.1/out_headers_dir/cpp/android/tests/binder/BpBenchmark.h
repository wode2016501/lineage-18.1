#ifndef AIDL_GENERATED_ANDROID_TESTS_BINDER_BP_BENCHMARK_H_
#define AIDL_GENERATED_ANDROID_TESTS_BINDER_BP_BENCHMARK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/tests/binder/IBenchmark.h>

namespace android {

namespace tests {

namespace binder {

class BpBenchmark : public ::android::BpInterface<IBenchmark> {
public:
  explicit BpBenchmark(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBenchmark() = default;
  ::android::binder::Status sendVec(const ::std::vector<uint8_t>& data, ::std::vector<uint8_t>* _aidl_return) override;
};  // class BpBenchmark

}  // namespace binder

}  // namespace tests

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_TESTS_BINDER_BP_BENCHMARK_H_
