#ifndef HIDL_GENERATED_ANDROID_HARDWARE_BLUETOOTH_AUDIO_V2_0_IBLUETOOTHAUDIOPORT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_BLUETOOTH_AUDIO_V2_0_IBLUETOOTHAUDIOPORT_H

#include <android/hardware/audio/common/5.0/types.h>
#include <android/hardware/bluetooth/audio/2.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
namespace V2_0 {

/**
 * HAL interface from the Audio HAL to the Bluetooth stack
 * 
 * The Audio HAL calls methods in this interface to start, suspend, and stop
 * an audio stream. These calls return immediately and the results, if any,
 * are sent over the IBluetoothAudioProvider interface.
 * 
 * Moreover, the Audio HAL can also get the presentation position of the stream
 * and provide stream metadata.
 * 
 * Note: For HIDL APIs with a "generates" statement, the callback parameter used
 * for return value must be invoked synchronously before the API call returns.
 */
struct IBluetoothAudioPort : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.bluetooth.audio@2.0::IBluetoothAudioPort"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * This indicates that the caller of this method has opened the data path
     * and wants to start an audio stream. The caller must wait for a
     * IBluetoothAudioProvider.streamStarted(Status) call.
     */
    virtual ::android::hardware::Return<void> startStream() = 0;

    /**
     * This indicates that the caller of this method wants to suspend the audio
     * stream. The caller must wait for the Bluetooth process to call
     * IBluetoothAudioProvider.streamSuspended(Status). The caller still keeps
     * the data path open.
     */
    virtual ::android::hardware::Return<void> suspendStream() = 0;

    /**
     * This indicates that the caller of this method wants to stop the audio
     * stream. The data path will be closed after this call. There is no
     * callback from the IBluetoothAudioProvider interface even though the
     * teardown is asynchronous.
     */
    virtual ::android::hardware::Return<void> stopStream() = 0;

    /**
     * Return callback for getPresentationPosition
     */
    using getPresentationPosition_cb = std::function<void(::android::hardware::bluetooth::audio::V2_0::Status status, uint64_t remoteDeviceAudioDelayNanos, uint64_t transmittedOctets, const ::android::hardware::bluetooth::audio::V2_0::TimeSpec& transmittedOctetsTimeStamp)>;
    /**
     * Get the audio presentation position.
     * 
     * @return status the command status
     * @return remoteDeviceAudioDelayNanos the audio delay from when the remote
     *    device (e.g. headset) receives audio data to when the device plays the
     *    sound. If the delay is unknown, the value is set to zero.
     * @return transmittedOctets the number of audio data octets that were sent
     *    to a remote device. This excludes octets that have been written to the
     *    data path but have not been sent to the remote device. The count is
     *    not reset until stopStream() is called. If the software data path is
     *    unused (e.g. A2DP Hardware Offload), the value is set to 0.
     * @return transmittedOctetsTimeStamp the value of CLOCK_MONOTONIC
     *    corresponding to transmittedOctets. If the software data path is
     *    unused (e.g., for A2DP Hardware Offload), the value is set to zero.
     */
    virtual ::android::hardware::Return<void> getPresentationPosition(getPresentationPosition_cb _hidl_cb) = 0;

    /**
     * Called when the metadata of the stream's source has been changed.
     * 
     * @param sourceMetadata Description of the audio that is played by the
     *    clients.
     */
    virtual ::android::hardware::Return<void> updateMetadata(const ::android::hardware::audio::common::V5_0::SourceMetadata& sourceMetadata) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort>> castFrom(const ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IBluetoothAudioPort> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBluetoothAudioPort> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBluetoothAudioPort> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBluetoothAudioPort> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBluetoothAudioPort> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBluetoothAudioPort> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBluetoothAudioPort> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBluetoothAudioPort> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_0
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_BLUETOOTH_AUDIO_V2_0_IBLUETOOTHAUDIOPORT_H
