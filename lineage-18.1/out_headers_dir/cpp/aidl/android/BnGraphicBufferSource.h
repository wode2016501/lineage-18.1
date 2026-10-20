#pragma once

#include "aidl/android/IGraphicBufferSource.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
class BnGraphicBufferSource : public ::ndk::BnCInterface<IGraphicBufferSource> {
public:
  BnGraphicBufferSource();
  virtual ~BnGraphicBufferSource();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace android
}  // namespace aidl
