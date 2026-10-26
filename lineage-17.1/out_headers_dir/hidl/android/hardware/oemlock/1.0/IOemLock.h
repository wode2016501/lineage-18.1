#ifndef HIDL_GENERATED_ANDROID_HARDWARE_OEMLOCK_V1_0_IOEMLOCK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_OEMLOCK_V1_0_IOEMLOCK_H

#include <android/hardware/oemlock/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace oemlock {
namespace V1_0 {

struct IOemLock : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.oemlock@1.0::IOemLock"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getName
     */
    using getName_cb = std::function<void(::android::hardware::oemlock::V1_0::OemLockStatus status, const ::android::hardware::hidl_string& name)>;
    /**
     * Returns a vendor specific identifier of the HAL.
     * 
     * The name returned must not be interpreted by the framework but must be
     * passed to vendor code which may use it to identify the security protocol
     * used by setOemUnlockAllowedByCarrier. This allows the vendor to identify
     * the protocol without having to maintain a device-to-protocol mapping.
     * 
     * @return name of the implementation.
     */
    virtual ::android::hardware::Return<void> getName(getName_cb _hidl_cb) = 0;

    /**
     * Updates whether OEM unlock is allowed by the carrier.
     * 
     * The implementation may require a vendor defined signature to prove the
     * validity of this request in order to harden its security.
     * 
     * @param allowed is the new value of the flag.
     * @param signature to prove validity of this request or empty if not
     *        required.
     * @return status is OK if the flag was successfully updated,
     *         INVALID_SIGNATURE if a signature is required but the wrong one
     *         was provided or FAILED if the update was otherwise unsuccessful.
     */
    virtual ::android::hardware::Return<::android::hardware::oemlock::V1_0::OemLockSecureStatus> setOemUnlockAllowedByCarrier(bool allowed, const ::android::hardware::hidl_vec<uint8_t>& signature) = 0;

    /**
     * Return callback for isOemUnlockAllowedByCarrier
     */
    using isOemUnlockAllowedByCarrier_cb = std::function<void(::android::hardware::oemlock::V1_0::OemLockStatus status, bool allowed)>;
    /**
     * Returns whether OEM unlock is allowed by the carrier.
     * 
     * @return status is OK if the flag was successfully read.
     * @return allowed is the current state of the flag.
     */
    virtual ::android::hardware::Return<void> isOemUnlockAllowedByCarrier(isOemUnlockAllowedByCarrier_cb _hidl_cb) = 0;

    /**
     * Updates whether OEM unlock is allowed by the device.
     * 
     * @param allowed is the new value of the flag.
     * @return status is OK if the flag was successfully updated.
     */
    virtual ::android::hardware::Return<::android::hardware::oemlock::V1_0::OemLockStatus> setOemUnlockAllowedByDevice(bool allowed) = 0;

    /**
     * Return callback for isOemUnlockAllowedByDevice
     */
    using isOemUnlockAllowedByDevice_cb = std::function<void(::android::hardware::oemlock::V1_0::OemLockStatus status, bool allowed)>;
    /**
     * Returns whether OEM unlock ia allowed by the device.
     * 
     * @return status is OK if the flag was successfully read.
     * @return allowed is the current state of the flag.
     */
    virtual ::android::hardware::Return<void> isOemUnlockAllowedByDevice(isOemUnlockAllowedByDevice_cb _hidl_cb) = 0;

    /**
     * Return callback for interfaceChain
     */
    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    /**
     * Return callback for interfaceDescriptor
     */
    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    /**
     * Return callback for getHashChain
     */
    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> setHALInstrumentation() override;

    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;

    virtual ::android::hardware::Return<void> ping() override;

    /**
     * Return callback for getDebugInfo
     */
    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;

    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    // cast static functions
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::oemlock::V1_0::IOemLock>> castFrom(const ::android::sp<::android::hardware::oemlock::V1_0::IOemLock>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::oemlock::V1_0::IOemLock>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    // helper methods for interactions with the hwservicemanager
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is currently not available or not in the VINTF manifest on a Trebilized
     * device, this will return nullptr. This is useful when you don't want to block
     * during device boot. If getStub is true, this will try to return an unwrapped
     * passthrough implementation in the same process. This is useful when getting an
     * implementation from the same partition/compilation group.
     * 
     * In general, prefer getService(std::string,bool)
     */
    static ::android::sp<IOemLock> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IOemLock> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IOemLock> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IOemLock> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IOemLock> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IOemLock> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IOemLock> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IOemLock> getService(bool getStub) { return getService("default", getStub); }
    /**
     * Registers a service with the service manager. For Trebilized devices, the service
     * must also be in the VINTF manifest.
     */
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    /**
     * Registers for notifications for when a service is registered.
     */
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

//
// type declarations for package
//

static inline std::string toString(const ::android::sp<::android::hardware::oemlock::V1_0::IOemLock>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::oemlock::V1_0::IOemLock>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::oemlock::V1_0::IOemLock::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace oemlock
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_OEMLOCK_V1_0_IOEMLOCK_H
