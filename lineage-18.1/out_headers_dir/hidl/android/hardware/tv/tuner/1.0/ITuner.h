#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TV_TUNER_V1_0_ITUNER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TV_TUNER_V1_0_ITUNER_H

#include <android/hardware/tv/tuner/1.0/IDemux.h>
#include <android/hardware/tv/tuner/1.0/IDescrambler.h>
#include <android/hardware/tv/tuner/1.0/IFrontend.h>
#include <android/hardware/tv/tuner/1.0/ILnb.h>
#include <android/hardware/tv/tuner/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tv {
namespace tuner {
namespace V1_0 {

/**
 * Top level interface to manage Frontend, Demux and Decrambler hardware
 * resouces which are needed for Android TV.
 */
struct ITuner : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tv.tuner@1.0::ITuner"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getFrontendIds
     */
    using getFrontendIds_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, const ::android::hardware::hidl_vec<uint32_t>& frontendIds)>;
    /**
     * Get Frontend IDs
     * 
     * It is used by the client to get all available frontends' IDs.
     * 
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNKNOWN_ERROR if tuning failed for other reasons.
     * @return frontendIds an array of FrontendId for the available frontends.
     */
    virtual ::android::hardware::Return<void> getFrontendIds(getFrontendIds_cb _hidl_cb) = 0;

    /**
     * Return callback for openFrontendById
     */
    using openFrontendById_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, const ::android::sp<::android::hardware::tv::tuner::V1_0::IFrontend>& frontend)>;
    /**
     * Create a new instance of Frontend given a frontendId.
     * 
     * It is used by the client to create a frontend instance.
     * 
     * @param frontendId the id of the frontend to be opened.
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNAVAILABLE if no resource.
     *         UNKNOWN_ERROR if creation failed for other reasons.
     * @return frontend the newly created frontend interface.
     */
    virtual ::android::hardware::Return<void> openFrontendById(uint32_t frontendId, openFrontendById_cb _hidl_cb) = 0;

    /**
     * Return callback for openDemux
     */
    using openDemux_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, uint32_t demuxId, const ::android::sp<::android::hardware::tv::tuner::V1_0::IDemux>& demux)>;
    /**
     * Create a new instance of Demux.
     * 
     * It is used by the client to create a Demux instance.
     * 
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNKNOWN_ERROR if creation failed for other reasons.
     * @return demuxId newly created demux id.
     * @return demux the newly created demux interface.
     */
    virtual ::android::hardware::Return<void> openDemux(openDemux_cb _hidl_cb) = 0;

    /**
     * Return callback for getDemuxCaps
     */
    using getDemuxCaps_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, const ::android::hardware::tv::tuner::V1_0::DemuxCapabilities& caps)>;
    /**
     * Retrieve the Demux's Capabilities.
     * 
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNKNOWN_ERROR if the inquiry failed for other reasons.
     * @return caps the Demux's Capabilities.
     */
    virtual ::android::hardware::Return<void> getDemuxCaps(getDemuxCaps_cb _hidl_cb) = 0;

    /**
     * Return callback for openDescrambler
     */
    using openDescrambler_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, const ::android::sp<::android::hardware::tv::tuner::V1_0::IDescrambler>& descrambler)>;
    /**
     * Create a new instance of Descrambler.
     * 
     * It is used by the client to create a Descrambler instance.
     * 
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNKNOWN_ERROR if creation failed for other reasons.
     * @return descrambler the newly created descrambler interface.
     */
    virtual ::android::hardware::Return<void> openDescrambler(openDescrambler_cb _hidl_cb) = 0;

    /**
     * Return callback for getFrontendInfo
     */
    using getFrontendInfo_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, const ::android::hardware::tv::tuner::V1_0::FrontendInfo& info)>;
    /**
     * Retrieve the frontend's information.
     * 
     * @param frontendId the id of the frontend to be inquiried.
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNKNOWN_ERROR if the inquiry failed for other reasons.
     * @return info the frontend's information.
     */
    virtual ::android::hardware::Return<void> getFrontendInfo(uint32_t frontendId, getFrontendInfo_cb _hidl_cb) = 0;

    /**
     * Return callback for getLnbIds
     */
    using getLnbIds_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, const ::android::hardware::hidl_vec<uint32_t>& lnbIds)>;
    /**
     * Get low-noise block downconverter (LNB) IDs.
     * 
     * It is used by the client to get all available LNBs' IDs.
     * 
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNKNOWN_ERROR if tuning failed for other reasons.
     * @return frontendIds an array of LnbId for the available LNBs.
     */
    virtual ::android::hardware::Return<void> getLnbIds(getLnbIds_cb _hidl_cb) = 0;

    /**
     * Return callback for openLnbById
     */
    using openLnbById_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, const ::android::sp<::android::hardware::tv::tuner::V1_0::ILnb>& lnb)>;
    /**
     * Create a new instance of Lnb given a lnbId.
     * 
     * It is used by the client to create a Lnb instance for satellite Frontend.
     * 
     * @param lnbId the id of the LNB to be opened.
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNAVAILABLE if no resource.
     *         UNKNOWN_ERROR if creation failed for other reasons.
     * @return lnb the newly created Lnb interface.
     */
    virtual ::android::hardware::Return<void> openLnbById(uint32_t lnbId, openLnbById_cb _hidl_cb) = 0;

    /**
     * Return callback for openLnbByName
     */
    using openLnbByName_cb = std::function<void(::android::hardware::tv::tuner::V1_0::Result result, uint32_t lnbId, const ::android::sp<::android::hardware::tv::tuner::V1_0::ILnb>& lnb)>;
    /**
     * Create a new instance of Lnb given a LNB name.
     * 
     * It is used by the client to create a LNB instance for external device.
     * 
     * @param lnbName the name for an external LNB to be opened. The app
     *        provides the name. Frammework doesn't depend on the name, instead
     *        use lnbId return from this call.
     * @return result Result status of the operation.
     *         SUCCESS if successful,
     *         UNAVAILABLE if no resource.
     *         UNKNOWN_ERROR if creation failed for other reasons.
     * @return lnbId the id of the LNB to be opened.
     * @return lnb the newly created Lnb interface.
     */
    virtual ::android::hardware::Return<void> openLnbByName(const ::android::hardware::hidl_string& lnbName, openLnbByName_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tv::tuner::V1_0::ITuner>> castFrom(const ::android::sp<::android::hardware::tv::tuner::V1_0::ITuner>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tv::tuner::V1_0::ITuner>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ITuner> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ITuner> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ITuner> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ITuner> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ITuner> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ITuner> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ITuner> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ITuner> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::tv::tuner::V1_0::ITuner>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::tv::tuner::V1_0::ITuner>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tv::tuner::V1_0::ITuner::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace tuner
}  // namespace tv
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TV_TUNER_V1_0_ITUNER_H
