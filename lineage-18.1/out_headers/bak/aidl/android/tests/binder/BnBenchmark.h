#pragma once

#include "aidl/android/tests/binder/IBenchmark.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace tests {
namespace binder {
class BnBenchmark : public ::ndk::BnCInterface<IBenchmark> {
public:
  BnBenchmark();
  virtual ~BnBenchmark();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace binder
}  // namespace tests
}  // namespace android
}  // namespace aidl
