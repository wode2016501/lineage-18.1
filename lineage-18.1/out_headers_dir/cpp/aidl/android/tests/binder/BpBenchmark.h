#pragma once

#include "aidl/android/tests/binder/IBenchmark.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace tests {
namespace binder {
class BpBenchmark : public ::ndk::BpCInterface<IBenchmark> {
public:
  BpBenchmark(const ::ndk::SpAIBinder& binder);
  virtual ~BpBenchmark();

  ::ndk::ScopedAStatus sendVec(const std::vector<int8_t>& in_data, std::vector<int8_t>* _aidl_return) override;
};
}  // namespace binder
}  // namespace tests
}  // namespace android
}  // namespace aidl
