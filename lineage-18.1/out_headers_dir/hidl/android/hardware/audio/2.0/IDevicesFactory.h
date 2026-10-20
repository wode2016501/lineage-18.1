#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_V2_0_IDEVICESFACTORY_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_V2_0_IDEVICESFACTORY_H

#include <android/hardware/audio/2.0/IDevice.h>
#include <android/hardware/audio/2.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace audio {
namespace V2_0 {

struct IDevicesFactory : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.audio@2.0::IDevicesFactory"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class Device : int32_t;

    typedef ::android::hardware::audio::V2_0::Result Result;

    enum class Device : int32_t {
        PRIMARY = 0,
        A2DP = 1 /* (::android::hardware::audio::V2_0::IDevicesFactory::Device.PRIMARY implicitly + 1) */,
        USB = 2 /* (::android::hardware::audio::V2_0::IDevicesFactory::Device.A2DP implicitly + 1) */,
        R_SUBMIX = 3 /* (::android::hardware::audio::V2_0::IDevicesFactory::Device.USB implicitly + 1) */,
        STUB = 4 /* (::android::hardware::audio::V2_0::IDevicesFactory::Device.R_SUBMIX implicitly + 1) */,
    };

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for openDevice
     */
    using openDevice_cb = std::function<void(::android::hardware::audio::V2_0::Result retval, const ::android::sp<::android::hardware::audio::V2_0::IDevice>& result)>;
    /**
     * Opens an audio device. To close the device, it is necessary to release
     * references to the returned device object.
     * 
     * @param device device type.
     * @return retval operation completion status. Returns INVALID_ARGUMENTS
     *         if there is no corresponding hardware module found,
     *         NOT_INITIALIZED if an error occured while opening the hardware
     *         module.
     * @return result the interface for the created device.
     */
    virtual ::android::hardware::Return<void> openDevice(::android::hardware::audio::V2_0::IDevicesFactory::Device device, openDevice_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::audio::V2_0::IDevicesFactory>> castFrom(const ::android::sp<::android::hardware::audio::V2_0::IDevicesFactory>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::audio::V2_0::IDevicesFactory>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IDevicesFactory> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IDevicesFactory> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IDevicesFactory> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IDevicesFactory> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IDevicesFactory> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IDevicesFactory> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IDevicesFactory> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IDevicesFactory> getService(bool getStub) { return getService("default", getStub); }
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

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::audio::V2_0::IDevicesFactory::Device o);

constexpr int32_t operator|(const ::android::hardware::audio::V2_0::IDevicesFactory::Device lhs, const ::android::hardware::audio::V2_0::IDevicesFactory::Device rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::audio::V2_0::IDevicesFactory::Device rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::audio::V2_0::IDevicesFactory::Device lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::audio::V2_0::IDevicesFactory::Device lhs, const ::android::hardware::audio::V2_0::IDevicesFactory::Device rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::audio::V2_0::IDevicesFactory::Device rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::audio::V2_0::IDevicesFactory::Device lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::audio::V2_0::IDevicesFactory::Device e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::audio::V2_0::IDevicesFactory::Device e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::sp<::android::hardware::audio::V2_0::IDevicesFactory>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::audio::V2_0::IDevicesFactory::Device>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::audio::V2_0::IDevicesFactory::Device> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::audio::V2_0::IDevicesFactory::Device::PRIMARY) == static_cast<int32_t>(::android::hardware::audio::V2_0::IDevicesFactory::Device::PRIMARY)) {
        os += (first ? "" : " | ");
        os += "PRIMARY";
        first = false;
        flipped |= ::android::hardware::audio::V2_0::IDevicesFactory::Device::PRIMARY;
    }
    if ((o & ::android::hardware::audio::V2_0::IDevicesFactory::Device::A2DP) == static_cast<int32_t>(::android::hardware::audio::V2_0::IDevicesFactory::Device::A2DP)) {
        os += (first ? "" : " | ");
        os += "A2DP";
        first = false;
        flipped |= ::android::hardware::audio::V2_0::IDevicesFactory::Device::A2DP;
    }
    if ((o & ::android::hardware::audio::V2_0::IDevicesFactory::Device::USB) == static_cast<int32_t>(::android::hardware::audio::V2_0::IDevicesFactory::Device::USB)) {
        os += (first ? "" : " | ");
        os += "USB";
        first = false;
        flipped |= ::android::hardware::audio::V2_0::IDevicesFactory::Device::USB;
    }
    if ((o & ::android::hardware::audio::V2_0::IDevicesFactory::Device::R_SUBMIX) == static_cast<int32_t>(::android::hardware::audio::V2_0::IDevicesFactory::Device::R_SUBMIX)) {
        os += (first ? "" : " | ");
        os += "R_SUBMIX";
        first = false;
        flipped |= ::android::hardware::audio::V2_0::IDevicesFactory::Device::R_SUBMIX;
    }
    if ((o & ::android::hardware::audio::V2_0::IDevicesFactory::Device::STUB) == static_cast<int32_t>(::android::hardware::audio::V2_0::IDevicesFactory::Device::STUB)) {
        os += (first ? "" : " | ");
        os += "STUB";
        first = false;
        flipped |= ::android::hardware::audio::V2_0::IDevicesFactory::Device::STUB;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::audio::V2_0::IDevicesFactory::Device o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::audio::V2_0::IDevicesFactory::Device::PRIMARY) {
        return "PRIMARY";
    }
    if (o == ::android::hardware::audio::V2_0::IDevicesFactory::Device::A2DP) {
        return "A2DP";
    }
    if (o == ::android::hardware::audio::V2_0::IDevicesFactory::Device::USB) {
        return "USB";
    }
    if (o == ::android::hardware::audio::V2_0::IDevicesFactory::Device::R_SUBMIX) {
        return "R_SUBMIX";
    }
    if (o == ::android::hardware::audio::V2_0::IDevicesFactory::Device::STUB) {
        return "STUB";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline std::string toString(const ::android::sp<::android::hardware::audio::V2_0::IDevicesFactory>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::audio::V2_0::IDevicesFactory::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_0
}  // namespace audio
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::audio::V2_0::IDevicesFactory::Device, 5> hidl_enum_values<::android::hardware::audio::V2_0::IDevicesFactory::Device> = {
    ::android::hardware::audio::V2_0::IDevicesFactory::Device::PRIMARY,
    ::android::hardware::audio::V2_0::IDevicesFactory::Device::A2DP,
    ::android::hardware::audio::V2_0::IDevicesFactory::Device::USB,
    ::android::hardware::audio::V2_0::IDevicesFactory::Device::R_SUBMIX,
    ::android::hardware::audio::V2_0::IDevicesFactory::Device::STUB,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_V2_0_IDEVICESFACTORY_H
