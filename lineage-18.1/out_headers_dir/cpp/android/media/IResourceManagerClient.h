#ifndef AIDL_GENERATED_ANDROID_MEDIA_I_RESOURCE_MANAGER_CLIENT_H_
#define AIDL_GENERATED_ANDROID_MEDIA_I_RESOURCE_MANAGER_CLIENT_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace media {

class IResourceManagerClient : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ResourceManagerClient)
  virtual ::android::binder::Status reclaimResource(bool* _aidl_return) = 0;
  virtual ::android::binder::Status getName(::std::string* _aidl_return) = 0;
};  // class IResourceManagerClient

class IResourceManagerClientDefault : public IResourceManagerClient {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status reclaimResource(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getName(::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IResourceManagerClientDefault

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_I_RESOURCE_MANAGER_CLIENT_H_
