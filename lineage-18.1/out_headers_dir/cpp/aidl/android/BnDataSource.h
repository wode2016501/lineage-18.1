#pragma once

#include "aidl/android/IDataSource.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
class BnDataSource : public ::ndk::BnCInterface<IDataSource> {
public:
  BnDataSource();
  virtual ~BnDataSource();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace android
}  // namespace aidl
