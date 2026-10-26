#ifndef HIDL_GENERATED_ANDROID_HARDWARE_MEMTRACK_V1_0_IMEMTRACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_MEMTRACK_V1_0_IMEMTRACK_H

#include <android/hardware/memtrack/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace memtrack {
namespace V1_0 {

/**
 * The Memory Tracker HAL is designed to return information about
 * device-specific memory usage.
 * The primary goal is to be able to track memory that is not
 * trackable in any other way, for example texture memory that is allocated by
 * a process, but not mapped in to that process's address space.
 * A secondary goal is to be able to categorize memory used by a process into
 * GL, graphics, etc. All memory sizes must be in real memory usage,
 * accounting for stride, bit depth, rounding up to page size, etc.
 * 
 * Constructor for the interface should be used to perform memtrack management
 * setup actions and is called once before any calls to getMemory().
 */
struct IMemtrack : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.memtrack@1.0::IMemtrack"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getMemory
     */
    using getMemory_cb = std::function<void(::android::hardware::memtrack::V1_0::MemtrackStatus retval, const ::android::hardware::hidl_vec<::android::hardware::memtrack::V1_0::MemtrackRecord>& records)>;
    /**
     * getMemory() populates MemtrackRecord vector with the sizes of memory
     * plus associated flags for that memory.
     * 
     * This function must be thread-safe, it may get called from multiple
     * threads at the same time.
     * 
     * A process collecting memory statistics will call getMemory for each
     * combination of pid and memory type. For each memory type that it
     * recognizes, the HAL must fill out an array of memtrack_record
     * structures breaking down the statistics of that memory type as much as
     * possible. For example,
     * getMemory(<pid>, GL) might return:
     * { { 4096,  ACCOUNTED | PRIVATE | SYSTEM },
     *   { 40960, UNACCOUNTED | PRIVATE | SYSTEM },
     *   { 8192,  ACCOUNTED | PRIVATE | DEDICATED },
     *   { 8192,  UNACCOUNTED | PRIVATE | DEDICATED } }
     * If the HAL cannot differentiate between SYSTEM and DEDICATED memory, it
     * could return:
     * { { 12288,  ACCOUNTED | PRIVATE },
     *   { 49152,  UNACCOUNTED | PRIVATE } }
     * 
     * Memory must not overlap between types. For example, a graphics buffer
     * that has been mapped into the GPU as a surface must show up when
     * GRAPHICS is requested and not when GL
     * is requested.
     * 
     * @param pid process for which memory information is requested
     * @param type memory type that information is being requested about
     * @return records vector of MemtrackRecord containing memory information
     * @return retval SUCCESS on success, TYPE_NOT_FOUND if the type is not
     * supported.
     */
    virtual ::android::hardware::Return<void> getMemory(int32_t pid, ::android::hardware::memtrack::V1_0::MemtrackType type, getMemory_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::memtrack::V1_0::IMemtrack>> castFrom(const ::android::sp<::android::hardware::memtrack::V1_0::IMemtrack>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::memtrack::V1_0::IMemtrack>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IMemtrack> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IMemtrack> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IMemtrack> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IMemtrack> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IMemtrack> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IMemtrack> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IMemtrack> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IMemtrack> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::memtrack::V1_0::IMemtrack>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::memtrack::V1_0::IMemtrack>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::memtrack::V1_0::IMemtrack::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace memtrack
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_MEMTRACK_V1_0_IMEMTRACK_H
