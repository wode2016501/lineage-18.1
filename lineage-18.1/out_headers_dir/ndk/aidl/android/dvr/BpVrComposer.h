#pragma once

#include "aidl/android/dvr/IVrComposer.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace dvr {
class BpVrComposer : public ::ndk::BpCInterface<IVrComposer> {
public:
  BpVrComposer(const ::ndk::SpAIBinder& binder);
  virtual ~BpVrComposer();

  ::ndk::ScopedAStatus registerObserver(const std::shared_ptr<::aidl::android::dvr::IVrComposerCallback>& in_callback) override;
  ::ndk::ScopedAStatus clearObserver() override;
};
}  // namespace dvr
}  // namespace android
}  // namespace aidl
