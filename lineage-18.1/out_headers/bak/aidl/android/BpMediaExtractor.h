#pragma once

#include "aidl/android/IMediaExtractor.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
class BpMediaExtractor : public ::ndk::BpCInterface<IMediaExtractor> {
public:
  BpMediaExtractor(const ::ndk::SpAIBinder& binder);
  virtual ~BpMediaExtractor();

};
}  // namespace android
}  // namespace aidl
