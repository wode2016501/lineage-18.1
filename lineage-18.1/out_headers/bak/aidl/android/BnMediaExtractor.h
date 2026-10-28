#pragma once

#include "aidl/android/IMediaExtractor.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
class BnMediaExtractor : public ::ndk::BnCInterface<IMediaExtractor> {
public:
  BnMediaExtractor();
  virtual ~BnMediaExtractor();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace android
}  // namespace aidl
