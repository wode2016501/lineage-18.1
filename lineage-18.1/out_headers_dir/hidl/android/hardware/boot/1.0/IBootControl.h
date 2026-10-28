#ifndef HIDL_GENERATED_ANDROID_HARDWARE_BOOT_V1_0_IBOOTCONTROL_H
#define HIDL_GENERATED_ANDROID_HARDWARE_BOOT_V1_0_IBOOTCONTROL_H

#include <android/hardware/boot/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace boot {
namespace V1_0 {

/**
 * The Boot Control HAL is designed to allow for managing sets of redundant
 * partitions, called slots, that can be booted from independently. Slots
 * are sets of partitions whose names differ only by a given suffix.
 * They are identified here by a 0 indexed number and associated with their
 * suffix, which is appended to the base name for any particular partition
 * to find the one associated with that slot.
 * The primary use of this set up is to allow for background updates while
 * the device is running, and to provide a fallback in the event that the
 * update fails.
 */
struct IBootControl : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.boot@1.0::IBootControl"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * getNumberSlots() returns the number of available slots.
     * For instance, a system with a single set of partitions must return
     * 1, a system with A/B must return 2, A/B/C -> 3 and so on. A system with
     * less than two slots doesn't support background updates, for example if
     * running from a virtual machine with only one copy of each partition for the
     * purpose of testing.
     */
    virtual ::android::hardware::Return<uint32_t> getNumberSlots() = 0;

    /**
     * getCurrentSlot() returns the slot number of that the current boot is booted
     * from, for example slot number 0 (Slot A). It is assumed that if the current
     * slot is A, then the block devices underlying B can be accessed directly
     * without any risk of corruption.
     * The returned value is always guaranteed to be strictly less than the
     * value returned by getNumberSlots. Slots start at 0 and finish at
     * getNumberSlots() - 1. The value returned here must match the suffix passed
     * from the bootloader, regardless of which slot is active or successful.
     */
    virtual ::android::hardware::Return<uint32_t> getCurrentSlot() = 0;

    /**
     * Return callback for markBootSuccessful
     */
    using markBootSuccessful_cb = std::function<void(const ::android::hardware::boot::V1_0::CommandResult& error)>;
    /**
     * markBootSuccessful() marks the current slot as having booted successfully.
     * 
     * Returns whether the command succeeded.
     */
    virtual ::android::hardware::Return<void> markBootSuccessful(markBootSuccessful_cb _hidl_cb) = 0;

    /**
     * Return callback for setActiveBootSlot
     */
    using setActiveBootSlot_cb = std::function<void(const ::android::hardware::boot::V1_0::CommandResult& error)>;
    /**
     * setActiveBootSlot() marks the slot passed in parameter as the active boot
     * slot (see getCurrentSlot for an explanation of the "slot" parameter). This
     * overrides any previous call to setSlotAsUnbootable.
     * Returns whether the command succeeded.
     */
    virtual ::android::hardware::Return<void> setActiveBootSlot(uint32_t slot, setActiveBootSlot_cb _hidl_cb) = 0;

    /**
     * Return callback for setSlotAsUnbootable
     */
    using setSlotAsUnbootable_cb = std::function<void(const ::android::hardware::boot::V1_0::CommandResult& error)>;
    /**
     * setSlotAsUnbootable() marks the slot passed in parameter as
     * an unbootable. This can be used while updating the contents of the slot's
     * partitions, so that the system must not attempt to boot a known bad set up.
     * Returns whether the command succeeded.
     */
    virtual ::android::hardware::Return<void> setSlotAsUnbootable(uint32_t slot, setSlotAsUnbootable_cb _hidl_cb) = 0;

    /**
     * isSlotBootable() returns if the slot passed in parameter is bootable. Note
     * that slots can be made unbootable by both the bootloader and by the OS
     * using setSlotAsUnbootable.
     * Returns TRUE if the slot is bootable, FALSE if it's not, and INVALID_SLOT
     * if slot does not exist.
     */
    virtual ::android::hardware::Return<::android::hardware::boot::V1_0::BoolResult> isSlotBootable(uint32_t slot) = 0;

    /**
     * isSlotMarkedSucessful() returns if the slot passed in parameter has been
     * marked as successful using markBootSuccessful. Note that only the current
     * slot can be marked as successful but any slot can be queried.
     * Returns TRUE if the slot has been marked as successful, FALSE if it has
     * not, and INVALID_SLOT if the slot does not exist.
     */
    virtual ::android::hardware::Return<::android::hardware::boot::V1_0::BoolResult> isSlotMarkedSuccessful(uint32_t slot) = 0;

    /**
     * Return callback for getSuffix
     */
    using getSuffix_cb = std::function<void(const ::android::hardware::hidl_string& slotSuffix)>;
    /**
     * getSuffix() returns the string suffix used by partitions that correspond to
     * the slot number passed in as a parameter. The bootloader must pass the
     * suffix of the currently active slot either through a kernel command line
     * property at androidboot.slot_suffix, or the device tree at
     * /firmware/android/slot_suffix.
     * Returns the empty string "" if slot does not match an existing slot.
     */
    virtual ::android::hardware::Return<void> getSuffix(uint32_t slot, getSuffix_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::boot::V1_0::IBootControl>> castFrom(const ::android::sp<::android::hardware::boot::V1_0::IBootControl>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::boot::V1_0::IBootControl>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IBootControl> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBootControl> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBootControl> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBootControl> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBootControl> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBootControl> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBootControl> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBootControl> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::boot::V1_0::IBootControl>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::boot::V1_0::IBootControl>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::boot::V1_0::IBootControl::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace boot
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_BOOT_V1_0_IBOOTCONTROL_H
