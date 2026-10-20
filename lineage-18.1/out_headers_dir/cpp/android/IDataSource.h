#ifndef AIDL_GENERATED_ANDROID_I_DATA_SOURCE_H_
#define AIDL_GENERATED_ANDROID_I_DATA_SOURCE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

class IDataSource : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(DataSource)
};  // class IDataSource

class IDataSourceDefault : public IDataSource {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
};  // class IDataSourceDefault

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_I_DATA_SOURCE_H_
