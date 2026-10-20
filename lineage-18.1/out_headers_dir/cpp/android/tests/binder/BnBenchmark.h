#ifndef AIDL_GENERATED_ANDROID_TESTS_BINDER_BN_BENCHMARK_H_
#define AIDL_GENERATED_ANDROID_TESTS_BINDER_BN_BENCHMARK_H_

#include <binder/IInterface.h>
#include <android/tests/binder/IBenchmark.h>

namespace android {

namespace tests {

namespace binder {

class BnBenchmark : public ::android::BnInterface<IBenchmark> {
public:
  explicit BnBenchmark();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBenchmark

}  // namespace binder

}  // namespace tests

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_TESTS_BINDER_BN_BENCHMARK_H_
