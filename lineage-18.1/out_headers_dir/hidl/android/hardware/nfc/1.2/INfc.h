#ifndef HIDL_GENERATED_ANDROID_HARDWARE_NFC_V1_2_INFC_H
#define HIDL_GENERATED_ANDROID_HARDWARE_NFC_V1_2_INFC_H

#include <android/hardware/nfc/1.1/INfc.h>
#include <android/hardware/nfc/1.2/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace nfc {
namespace V1_2 {

struct INfc : public ::android::hardware::nfc::V1_1::INfc {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.nfc@1.2::INfc"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    // @entry @callflow(next={"write", "coreInitialized", "prediscover", "powerCycle", "controlGranted"})
    /**
     * Opens the NFC controller device and performs initialization.
     * This may include patch download and other vendor-specific initialization.
     * 
     * If open completes successfully, the controller should be ready to perform
     * NCI initialization - ie accept CORE_RESET and subsequent commands through
     * the write() call.
     * 
     * If open() returns NfcStatus::OK, the NCI stack will wait for a
     * NfcEvent.OPEN_CPLT before continuing.
     * 
     * If open() returns NfcStatus::FAILED, the NCI stack will stop.
     * 
     */
    virtual ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> open(const ::android::sp<::android::hardware::nfc::V1_0::INfcClientCallback>& clientCallback) = 0;

    // @callflow(next={"write", "prediscover", "coreInitialized", "close", "powerCycle", "controlGranted"})
    /**
     * Performs an NCI write.
     * 
     * This method may queue writes and return immediately. The only
     * requirement is that the writes are executed in order.
     * 
     * @return number of bytes written to the NFCC
     */
    virtual ::android::hardware::Return<uint32_t> write(const ::android::hardware::hidl_vec<uint8_t>& data) = 0;

    // @callflow(next={"write", "prediscover", "close"})
    /**
     * coreInitialized() is called after the CORE_INIT_RSP is received from the
     * NFCC. At this time, the HAL can do any chip-specific configuration.
     * 
     * If coreInitialized() returns NfcStatus::OK, the NCI stack will wait for a
     * NfcEvent.POST_INIT_CPLT before continuing.
     * 
     * If coreInitialized() returns NfcStatus::FAILED, the NCI stack will
     * continue immediately.
     */
    virtual ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> coreInitialized(const ::android::hardware::hidl_vec<uint8_t>& data) = 0;

    // @callflow(next={"write", "close", "coreInitialized", "powerCycle", "controlGranted"})
    /**
     * prediscover is called every time before starting RF discovery.
     * It is a good place to do vendor-specific configuration that must be
     * performed every time RF discovery is about to be started.
     * 
     * If prediscover() returns NfcStatus::OK, the NCI stack will wait for a
     * NfcEvent.PREDISCOVER_CPLT before continuing.
     * 
     * If prediscover() returns NfcStatus::FAILED, the NCI stack will start
     * RF discovery immediately.
     */
    virtual ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> prediscover() = 0;

    // @exit
    /**
     * Close the NFC controller. Should free all resources.
     * 
     * @return NfcStatus::OK on success and NfcStatus::FAILED on error.
     */
    virtual ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> close() = 0;

    // @callflow(next={"write", "close", "prediscover", "coreInitialized", "powerCycle"})
    /**
     * Grant HAL the exclusive control to send NCI commands.
     * Called in response to NfcEvent.REQUEST_CONTROL.
     * Must only be called when there are no NCI commands pending.
     * NfcEvent.RELEASE_CONTROL will notify when HAL no longer needs exclusive control.
     * 
     * @return NfcStatus::OK on success and NfcStatus::FAILED on error.
     */
    virtual ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> controlGranted() = 0;

    // @callflow(next={"write", "coreInitialized", "prediscover", "controlGranted", "close"})
    /**
     * Restart controller by power cyle;
     * NfcEvent.OPEN_CPLT will notify when operation is complete.
     * 
     * @return NfcStatus::OK on success and NfcStatus::FAILED on error.
     */
    virtual ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> powerCycle() = 0;

    /**
     * Clears the NFC chip.
     * 
     * Must be called during factory reset and/or before the first time the HAL is
     * initialized after a factory reset
     */
    virtual ::android::hardware::Return<void> factoryReset() = 0;

    /**
     * Enable Power off use cases and close the NFC controller.
     * Should free all resources.
     * 
     * This call must enable NFC functionality for off host usecases in power
     * off use cases, if the device supports power off use cases. If the
     * device doesn't support power off use cases, this call should be same as
     * close()
     * 
     * @return NfcStatus::OK on success and NfcStatus::FAILED on error.
     */
    virtual ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> closeForPowerOffCase() = 0;

    /**
     * Open call to take the @1.1::INfcClientCallback
     * 
     * @param clientCallback for sending events and data to client.
     * @return status NfcStatus::FAILED in case of error,
     *                NfcStatus::SUCCESS otherwise.
     */
    virtual ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> open_1_1(const ::android::sp<::android::hardware::nfc::V1_1::INfcClientCallback>& clientCallback) = 0;

    /**
     * Return callback for getConfig
     */
    using getConfig_cb = std::function<void(const ::android::hardware::nfc::V1_1::NfcConfig& config)>;
    /**
     * Fetches vendor specific configurations.
     * @return config indicates support for certain features and
     *     populates the vendor specific configs
     */
    virtual ::android::hardware::Return<void> getConfig(getConfig_cb _hidl_cb) = 0;

    /**
     * Return callback for getConfig_1_2
     */
    using getConfig_1_2_cb = std::function<void(const ::android::hardware::nfc::V1_2::NfcConfig& config)>;
    /**
     * Fetches vendor specific configurations.
     * @return config indicates support for certain features and
     *     populates the vendor specific configs
     */
    virtual ::android::hardware::Return<void> getConfig_1_2(getConfig_1_2_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::nfc::V1_2::INfc>> castFrom(const ::android::sp<::android::hardware::nfc::V1_2::INfc>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::nfc::V1_2::INfc>> castFrom(const ::android::sp<::android::hardware::nfc::V1_1::INfc>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::nfc::V1_2::INfc>> castFrom(const ::android::sp<::android::hardware::nfc::V1_0::INfc>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::nfc::V1_2::INfc>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<INfc> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<INfc> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<INfc> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<INfc> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<INfc> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<INfc> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<INfc> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<INfc> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::nfc::V1_2::INfc>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::nfc::V1_2::INfc>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::nfc::V1_2::INfc::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_2
}  // namespace nfc
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_NFC_V1_2_INFC_H
