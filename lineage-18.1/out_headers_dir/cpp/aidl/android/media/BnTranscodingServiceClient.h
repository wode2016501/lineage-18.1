#pragma once

#include "aidl/android/media/ITranscodingServiceClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BnTranscodingServiceClient : public ::ndk::BnCInterface<ITranscodingServiceClient> {
public:
  BnTranscodingServiceClient();
  virtual ~BnTranscodingServiceClient();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace media
}  // namespace android
}  // namespace aidl
