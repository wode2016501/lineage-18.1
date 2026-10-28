#ifndef HIDL_GENERATED_ANDROID_HARDWARE_BROADCASTRADIO_V1_1_ITUNERCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_BROADCASTRADIO_V1_1_ITUNERCALLBACK_H

#include <android/hardware/broadcastradio/1.0/ITunerCallback.h>
#include <android/hardware/broadcastradio/1.1/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace broadcastradio {
namespace V1_1 {

/**
 * Some methods of @1.1::ITunerCallback are updated versions of those from
 * @1.0:ITunerCallback. All 1.1 HAL implementations must call both
 * (eg. tuneComplete and tuneComplete_1_1), while 1.1 clients may ignore 1.0
 * ones, to avoid receiving a callback twice.
 */
struct ITunerCallback : public ::android::hardware::broadcastradio::V1_0::ITunerCallback {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.broadcastradio@1.1::ITunerCallback"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Method called by the HAL when a HW failure occurs.
     * The framework MUST close the ITuner interface and open a new one.
     */
    virtual ::android::hardware::Return<void> hardwareFailure() = 0;

    /**
     * Method called by the HAL when a new configuration is applied
     * in response to IDevice.openTuner() or ITuner.setConfiguration().
     * @param result OK if the configuration has been applied,
     *               INVALID_ARGUMENTS if not or TIMEOUT in case of time out.
     * @param config A BandConfig structure describing the new configuration
     *               applied.
     */
    virtual ::android::hardware::Return<void> configChange(::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_0::BandConfig& config) = 0;

    /**
     * Method called by the HAL when a tuning operation completes
     * following a step(), scan() or tune() command.
     * @param result OK if tune succeeded or TIMEOUT in case of time out.
     * @param info A ProgramInfo structure describing the tuned station.
     */
    virtual ::android::hardware::Return<void> tuneComplete(::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_0::ProgramInfo& info) = 0;

    /**
     * Method called by the HAL when a frequency switch occurs.
     * @param info A ProgramInfo structure describing the new tuned station.
     */
    virtual ::android::hardware::Return<void> afSwitch(const ::android::hardware::broadcastradio::V1_0::ProgramInfo& info) = 0;

    /**
     * Method called by the HAL when the antenna connection state changes.
     * @param connected True if the antenna is connected, false otherwise.
     */
    virtual ::android::hardware::Return<void> antennaStateChange(bool connected) = 0;

    /**
     * Method called by the HAL when a traffic announcement starts or
     * stops.
     * @param active True if the announcement starts, false if it stops.
     */
    virtual ::android::hardware::Return<void> trafficAnnouncement(bool active) = 0;

    /**
     * Method called by the HAL when an emergency announcement starts
     * or stops.
     * @param active True if the announcement starts, false if it stops.
     */
    virtual ::android::hardware::Return<void> emergencyAnnouncement(bool active) = 0;

    /**
     * Method called by the HAL when metadata for current station
     * are updated.
     * @param channel The channel the metadata is associated with.
     * @param subChannel The sub channel the metadata is associated with.
     * @param metadata A list of all updated metada.
     */
    virtual ::android::hardware::Return<void> newMetadata(uint32_t channel, uint32_t subChannel, const ::android::hardware::hidl_vec<::android::hardware::broadcastradio::V1_0::MetaData>& metadata) = 0;

    /**
     * Method called by the HAL when a tuning operation completes
     * following a step(), scan() or tune() command.
     * 
     * This callback supersedes V1_0::tuneComplete.
     * The 1.0 callback must not be called when HAL implementation detects
     * 1.1 client (by casting V1_0::ITunerCallback to V1_1::ITunerCallback).
     * 
     * In case of success, currentProgramInfoChanged must be called too.
     * It means the success case may (or may not) be handled by the client in
     * currentProgramInfoChanged, instead of here.
     * 
     * @param result OK if tune succeeded or TIMEOUT in case of time out.
     * @param selector A ProgramSelector structure describing the tuned station.
     */
    virtual ::android::hardware::Return<void> tuneComplete_1_1(::android::hardware::broadcastradio::V1_0::Result result, const ::android::hardware::broadcastradio::V1_1::ProgramSelector& selector) = 0;

    /**
     * Called by the HAL when background scan feature becomes available or not.
     * 
     * @param isAvailable true, if the tuner turned temporarily background-
     *                    capable, false in the other case.
     */
    virtual ::android::hardware::Return<void> backgroundScanAvailable(bool isAvailable) = 0;

    /**
     * Called by the HAL when background scan initiated by startBackgroundScan
     * finishes. If the list was changed, programListChanged must be called too.
     * @param result OK if the scan succeeded, client may retrieve the actual
     *               list with ITuner::getProgramList.
     *               UNAVAILABLE if the scan was interrupted due to
     *               hardware becoming temporarily unavailable.
     *               NOT_INITIALIZED other error, ie. HW failure.
     */
    virtual ::android::hardware::Return<void> backgroundScanComplete(::android::hardware::broadcastradio::V1_1::ProgramListResult result) = 0;

    /**
     * Called each time the internally cached program list changes. HAL may not
     * call it immediately, ie. it may wait for a short time to accumulate
     * multiple list change notifications into a single event.
     * 
     * This callback is only for notifying about insertions and deletions,
     * not about metadata changes.
     * 
     * It may be triggered either by an explicitly issued background scan,
     * or a scan issued by the device internally.
     * 
     * Client may retrieve the actual list with ITuner::getProgramList.
     */
    virtual ::android::hardware::Return<void> programListChanged() = 0;

    /**
     * Method called by the HAL when current program information (including
     * metadata) is updated.
     * 
     * Client may retrieve the actual program info with
     * ITuner::getProgramInformation_1_1.
     * 
     * This may be called together with tuneComplete_1_1 or afSwitch_1_1.
     * 
     * This callback supersedes V1_0::newMetadata and V1_0::afSwitch;
     * partly V1_0::tuneComplete.
     * 1.0 callbacks must not be called when HAL implementation detects
     * 1.1 client (by casting V1_0::ITunerCallback to V1_1::ITunerCallback).
     * 
     * @param info current program information
     */
    virtual ::android::hardware::Return<void> currentProgramInfoChanged(const ::android::hardware::broadcastradio::V1_1::ProgramInfo& info) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>> castFrom(const ::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>> castFrom(const ::android::sp<::android::hardware::broadcastradio::V1_0::ITunerCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ITunerCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ITunerCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ITunerCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ITunerCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ITunerCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ITunerCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ITunerCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ITunerCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::broadcastradio::V1_1::ITunerCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::broadcastradio::V1_1::ITunerCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_1
}  // namespace broadcastradio
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_BROADCASTRADIO_V1_1_ITUNERCALLBACK_H
