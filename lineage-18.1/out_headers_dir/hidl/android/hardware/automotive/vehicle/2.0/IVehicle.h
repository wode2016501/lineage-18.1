#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_VEHICLE_V2_0_IVEHICLE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_VEHICLE_V2_0_IVEHICLE_H

#include <android/hardware/automotive/vehicle/2.0/IVehicleCallback.h>
#include <android/hardware/automotive/vehicle/2.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace automotive {
namespace vehicle {
namespace V2_0 {

struct IVehicle : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.automotive.vehicle@2.0::IVehicle"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getAllPropConfigs
     */
    using getAllPropConfigs_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::automotive::vehicle::V2_0::VehiclePropConfig>& propConfigs)>;
    /**
     * Returns a list of all property configurations supported by this vehicle
     * HAL.
     */
    virtual ::android::hardware::Return<void> getAllPropConfigs(getAllPropConfigs_cb _hidl_cb) = 0;

    /**
     * Return callback for getPropConfigs
     */
    using getPropConfigs_cb = std::function<void(::android::hardware::automotive::vehicle::V2_0::StatusCode status, const ::android::hardware::hidl_vec<::android::hardware::automotive::vehicle::V2_0::VehiclePropConfig>& propConfigs)>;
    /**
     * Returns a list of property configurations for given properties.
     * 
     * If requested VehicleProperty wasn't found it must return
     * StatusCode::INVALID_ARG, otherwise a list of vehicle property
     * configurations with StatusCode::OK
     */
    virtual ::android::hardware::Return<void> getPropConfigs(const ::android::hardware::hidl_vec<int32_t>& props, getPropConfigs_cb _hidl_cb) = 0;

    /**
     * Return callback for get
     */
    using get_cb = std::function<void(::android::hardware::automotive::vehicle::V2_0::StatusCode status, const ::android::hardware::automotive::vehicle::V2_0::VehiclePropValue& propValue)>;
    /**
     * Get a vehicle property value.
     * 
     * For VehiclePropertyChangeMode::STATIC properties, this method must always
     * return the same value always.
     * For VehiclePropertyChangeMode::ON_CHANGE properties, it must return the
     * latest available value.
     * 
     * Some properties like RADIO_PRESET requires to pass additional data in
     * GET request in VehiclePropValue object.
     * 
     * If there is no data available yet, which can happen during initial stage,
     * this call must return immediately with an error code of
     * StatusCode::TRY_AGAIN.
     */
    virtual ::android::hardware::Return<void> get(const ::android::hardware::automotive::vehicle::V2_0::VehiclePropValue& requestedPropValue, get_cb _hidl_cb) = 0;

    /**
     * Set a vehicle property value.
     * 
     * Timestamp of data must be ignored for set operation.
     * 
     * Setting some properties require having initial state available. If initial
     * data is not available yet this call must return StatusCode::TRY_AGAIN.
     * For a property with separate power control this call must return
     * StatusCode::NOT_AVAILABLE error if property is not powered on.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::vehicle::V2_0::StatusCode> set(const ::android::hardware::automotive::vehicle::V2_0::VehiclePropValue& propValue) = 0;

    /**
     * Subscribes to property events.
     * 
     * Clients must be able to subscribe to multiple properties at a time
     * depending on data provided in options argument.
     * 
     * @param listener This client must be called on appropriate event.
     * @param options List of options to subscribe. SubscribeOption contains
     *                information such as property Id, area Id, sample rate, etc.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::vehicle::V2_0::StatusCode> subscribe(const ::android::sp<::android::hardware::automotive::vehicle::V2_0::IVehicleCallback>& callback, const ::android::hardware::hidl_vec<::android::hardware::automotive::vehicle::V2_0::SubscribeOptions>& options) = 0;

    /**
     * Unsubscribes from property events.
     * 
     * If this client wasn't subscribed to the given property, this method
     * must return StatusCode::INVALID_ARG.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::vehicle::V2_0::StatusCode> unsubscribe(const ::android::sp<::android::hardware::automotive::vehicle::V2_0::IVehicleCallback>& callback, int32_t propId) = 0;

    /**
     * Return callback for debugDump
     */
    using debugDump_cb = std::function<void(const ::android::hardware::hidl_string& s)>;
    /**
     * Print out debugging state for the vehicle hal.
     * 
     * The text must be in ASCII encoding only.
     * 
     * Performance requirements:
     * 
     * The HAL must return from this call in less than 10ms. This call must avoid
     * deadlocks, as it may be called at any point of operation. Any synchronization
     * primitives used (such as mutex locks or semaphores) must be acquired
     * with a timeout.
     * 
     */
    virtual ::android::hardware::Return<void> debugDump(debugDump_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::vehicle::V2_0::IVehicle>> castFrom(const ::android::sp<::android::hardware::automotive::vehicle::V2_0::IVehicle>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::vehicle::V2_0::IVehicle>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IVehicle> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IVehicle> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IVehicle> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IVehicle> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IVehicle> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IVehicle> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IVehicle> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IVehicle> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::automotive::vehicle::V2_0::IVehicle>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::automotive::vehicle::V2_0::IVehicle>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::automotive::vehicle::V2_0::IVehicle::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_0
}  // namespace vehicle
}  // namespace automotive
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_VEHICLE_V2_0_IVEHICLE_H
