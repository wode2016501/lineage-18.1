#pragma once

#include "aidl/android/IDataSource.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
class BpDataSource : public ::ndk::BpCInterface<IDataSource> {
public:
  BpDataSource(const ::ndk::SpAIBinder& binder);
  virtual ~BpDataSource();

};
}  // namespace android
}  // namespace aidl
