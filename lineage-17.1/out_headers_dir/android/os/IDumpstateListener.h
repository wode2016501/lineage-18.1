#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>

namespace android {
namespace os {
class IDumpstateListenerDelegator;

class IDumpstateListener : public ::android::IInterface {
public:
  typedef IDumpstateListenerDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(DumpstateListener)
  enum : int32_t { BUGREPORT_ERROR_INVALID_INPUT = 1 };
  enum : int32_t { BUGREPORT_ERROR_RUNTIME_ERROR = 2 };
  enum : int32_t { BUGREPORT_ERROR_USER_DENIED_CONSENT = 3 };
  enum : int32_t { BUGREPORT_ERROR_USER_CONSENT_TIMED_OUT = 4 };
  enum : int32_t { BUGREPORT_ERROR_ANOTHER_REPORT_IN_PROGRESS = 5 };
  virtual ::android::binder::Status onProgress(int32_t progress) = 0;
  virtual ::android::binder::Status onError(int32_t errorCode) = 0;
  virtual ::android::binder::Status onFinished() = 0;
  virtual ::android::binder::Status onProgressUpdated(int32_t progress) = 0;
  virtual ::android::binder::Status onMaxProgressUpdated(int32_t maxProgress) = 0;
  virtual ::android::binder::Status onSectionComplete(const ::std::string& name, int32_t status, int32_t size, int32_t durationMs) = 0;
};  // class IDumpstateListener

class IDumpstateListenerDefault : public IDumpstateListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onProgress(int32_t /*progress*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onError(int32_t /*errorCode*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onFinished() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onProgressUpdated(int32_t /*progress*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onMaxProgressUpdated(int32_t /*maxProgress*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onSectionComplete(const ::std::string& /*name*/, int32_t /*status*/, int32_t /*size*/, int32_t /*durationMs*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IDumpstateListenerDefault
}  // namespace os
}  // namespace android
