#ifndef HIDL_GENERATED_ANDROID_HARDWARE_RADIO_V1_0_ISAPCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_RADIO_V1_0_ISAPCALLBACK_H

#include <android/hardware/radio/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_0 {

struct ISapCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.radio@1.0::ISapCallback"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * CONNECT_RESP from SAP 1.1 spec 5.1.2
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     * @param sapConnectRsp Connection Status
     * @param maxMsgSize MaxMsgSize supported by server if request cannot be fulfilled.
     *        Valid only if connectResponse is SapConnectResponse:MSG_SIZE_TOO_LARGE.
     */
    virtual ::android::hardware::Return<void> connectResponse(int32_t token, ::android::hardware::radio::V1_0::SapConnectRsp sapConnectRsp, int32_t maxMsgSize) = 0;

    /**
     * DISCONNECT_RESP from SAP 1.1 spec 5.1.4
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     */
    virtual ::android::hardware::Return<void> disconnectResponse(int32_t token) = 0;

    /**
     * DISCONNECT_IND from SAP 1.1 spec 5.1.5
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     * @param disconnectType Disconnect Type to indicate if shutdown is graceful or immediate
     */
    virtual ::android::hardware::Return<void> disconnectIndication(int32_t token, ::android::hardware::radio::V1_0::SapDisconnectType disconnectType) = 0;

    /**
     * TRANSFER_APDU_RESP from SAP 1.1 spec 5.1.7
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     * @param resultCode ResultCode to indicate if command was processed correctly
     *        Possible values:
     *        SapResultCode:SUCCESS,
     *        SapResultCode:GENERIC_FAILURE,
     *        SapResultCode:CARD_NOT_ACCESSSIBLE,
     *        SapResultCode:CARD_ALREADY_POWERED_OFF,
     *        SapResultCode:CARD_REMOVED
     * @param apduRsp APDU Response. Valid only if command was processed correctly and no error
     *        occurred.
     */
    virtual ::android::hardware::Return<void> apduResponse(int32_t token, ::android::hardware::radio::V1_0::SapResultCode resultCode, const ::android::hardware::hidl_vec<uint8_t>& apduRsp) = 0;

    /**
     * TRANSFER_ATR_RESP from SAP 1.1 spec 5.1.9
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     * @param resultCode ResultCode to indicate if command was processed correctly
     *        Possible values:
     *        SapResultCode:SUCCESS,
     *        SapResultCode:GENERIC_FAILURE,
     *        SapResultCode:CARD_ALREADY_POWERED_OFF,
     *        SapResultCode:CARD_REMOVED,
     *        SapResultCode:DATA_NOT_AVAILABLE
     * @param atr Answer to Reset from the subscription module. Included only if no error occurred,
     *        otherwise empty.
     */
    virtual ::android::hardware::Return<void> transferAtrResponse(int32_t token, ::android::hardware::radio::V1_0::SapResultCode resultCode, const ::android::hardware::hidl_vec<uint8_t>& atr) = 0;

    /**
     * POWER_SIM_OFF_RESP and POWER_SIM_ON_RESP from SAP 1.1 spec 5.1.11 + 5.1.13
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     * @param resultCode ResultCode to indicate if command was processed correctly
     *        Possible values:
     *        SapResultCode:SUCCESS,
     *        SapResultCode:GENERIC_FAILURE,
     *        SapResultCode:CARD_NOT_ACCESSSIBLE, (possible only for power on req)
     *        SapResultCode:CARD_ALREADY_POWERED_OFF, (possible only for power off req)
     *        SapResultCode:CARD_REMOVED,
     *        SapResultCode:CARD_ALREADY_POWERED_ON (possible only for power on req)
     */
    virtual ::android::hardware::Return<void> powerResponse(int32_t token, ::android::hardware::radio::V1_0::SapResultCode resultCode) = 0;

    /**
     * RESET_SIM_RESP from SAP 1.1 spec 5.1.15
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     * @param resultCode ResultCode to indicate if command was processed correctly
     *        Possible values:
     *        SapResultCode:SUCCESS,
     *        SapResultCode:GENERIC_FAILURE,
     *        SapResultCode:CARD_NOT_ACCESSSIBLE,
     *        SapResultCode:CARD_ALREADY_POWERED_OFF,
     *        SapResultCode:CARD_REMOVED
     */
    virtual ::android::hardware::Return<void> resetSimResponse(int32_t token, ::android::hardware::radio::V1_0::SapResultCode resultCode) = 0;

    /**
     * STATUS_IND from SAP 1.1 spec 5.1.16
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     * @param status Parameter to indicate reason for the status change.
     */
    virtual ::android::hardware::Return<void> statusIndication(int32_t token, ::android::hardware::radio::V1_0::SapStatus status) = 0;

    /**
     * TRANSFER_CARD_READER_STATUS_REQ from SAP 1.1 spec 5.1.18
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     * @param resultCode ResultCode to indicate if command was processed correctly
     *        Possible values:
     *        SapResultCode:SUCCESS,
     *        SapResultCode:GENERIC_FAILURE
     *        SapResultCode:DATA_NOT_AVAILABLE
     * @param cardReaderStatus Card Reader Status coded as described in 3GPP TS 11.14 Section 12.33
     *        and TS 31.111 Section 8.33
     */
    virtual ::android::hardware::Return<void> transferCardReaderStatusResponse(int32_t token, ::android::hardware::radio::V1_0::SapResultCode resultCode, int32_t cardReaderStatus) = 0;

    /**
     * ERROR_RESP from SAP 1.1 spec 5.1.19
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     */
    virtual ::android::hardware::Return<void> errorResponse(int32_t token) = 0;

    /**
     * SET_TRANSPORT_PROTOCOL_RESP from SAP 1.1 spec 5.1.21
     * 
     * @param token Id to match req-resp. Value must match the one in req.
     * @param resultCode ResultCode to indicate if command was processed correctly
     *        Possible values:
     *        SapResultCode:SUCCESS
     *        SapResultCode:NOT_SUPPORTED
     */
    virtual ::android::hardware::Return<void> transferProtocolResponse(int32_t token, ::android::hardware::radio::V1_0::SapResultCode resultCode) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::V1_0::ISapCallback>> castFrom(const ::android::sp<::android::hardware::radio::V1_0::ISapCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::V1_0::ISapCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ISapCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISapCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISapCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISapCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISapCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISapCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISapCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISapCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::radio::V1_0::ISapCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::radio::V1_0::ISapCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::radio::V1_0::ISapCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace radio
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_RADIO_V1_0_ISAPCALLBACK_H
