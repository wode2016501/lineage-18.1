#ifndef HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_3_IDRMFACTORY_H
#define HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_3_IDRMFACTORY_H

#include <android/hardware/drm/1.2/IDrmFactory.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_3 {

/**
 * IDrmFactory is the main entry point for interacting with a vendor's
 * drm HAL to create drm plugin instances. A drm plugin instance
 * creates drm sessions which are used to obtain keys for a crypto
 * session so it can decrypt protected video content.
 * 
 * The 1.3 factory must always create 1.2 IDrmPlugin interfaces, which are
 * returned via the 1.0 createPlugin method.
 */
struct IDrmFactory : public ::android::hardware::drm::V1_2::IDrmFactory {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.drm@1.3::IDrmFactory"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Determine if a crypto scheme is supported by this HAL
     * 
     * @param uuid identifies the crypto scheme in question
     * @return isSupported must be true only if the scheme is supported
     */
    virtual ::android::hardware::Return<bool> isCryptoSchemeSupported(const ::android::hardware::hidl_array<uint8_t, 16>& uuid) = 0;

    /**
     * Determine if the HAL factory is able to construct plugins that support a
     * given media container format specified by mimeType
     * 
     * @param mimeType identifies the mime type in question
     * @return isSupported must be true only if the scheme is supported
     */
    virtual ::android::hardware::Return<bool> isContentTypeSupported(const ::android::hardware::hidl_string& mimeType) = 0;

    /**
     * Return callback for createPlugin
     */
    using createPlugin_cb = std::function<void(::android::hardware::drm::V1_0::Status status, const ::android::sp<::android::hardware::drm::V1_0::IDrmPlugin>& drmPlugin)>;
    /**
     * Create a drm plugin instance for the specified uuid and scheme-specific
     * initialization data.
     * 
     * @param uuid uniquely identifies the drm scheme. See
     * http://dashif.org/identifiers/protection for uuid assignments
     * @param appPackageName identifies the package name of the calling
     * application.
     * @return status the status of the call. The HAL implementation must return
     * OK if the plugin is created and ERROR_DRM_CANNOT_HANDLE if the plugin
     * cannot be created.
     */
    virtual ::android::hardware::Return<void> createPlugin(const ::android::hardware::hidl_array<uint8_t, 16>& uuid, const ::android::hardware::hidl_string& appPackageName, createPlugin_cb _hidl_cb) = 0;

    /**
     * Determine if a specific security level is supported by the device.
     * This method only differs from @1.0 isCryptoSchemeSupported
     * by the addition of a security level.
     * 
     * @param uuid identifies the crypto scheme in question
     * @param mimeType identifies the mime type in question
     * @param securityLevel specifies the security level required
     * @return isSupported must be true only if the scheme is supported
     */
    virtual ::android::hardware::Return<bool> isCryptoSchemeSupported_1_2(const ::android::hardware::hidl_array<uint8_t, 16>& uuid, const ::android::hardware::hidl_string& mimeType, ::android::hardware::drm::V1_1::SecurityLevel securityLevel) = 0;

    /**
     * Return callback for getSupportedCryptoSchemes
     */
    using getSupportedCryptoSchemes_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 16>>& schemes)>;
    /**
     * Return vector of uuids identifying crypto schemes supported by this HAL.
     * 
     * @return schemes Vector of uuids for which isCryptoSchemeSupported is true;
     *                 each uuid can be used as input to createPlugin.
     */
    virtual ::android::hardware::Return<void> getSupportedCryptoSchemes(getSupportedCryptoSchemes_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_3::IDrmFactory>> castFrom(const ::android::sp<::android::hardware::drm::V1_3::IDrmFactory>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_3::IDrmFactory>> castFrom(const ::android::sp<::android::hardware::drm::V1_2::IDrmFactory>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_3::IDrmFactory>> castFrom(const ::android::sp<::android::hardware::drm::V1_1::IDrmFactory>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_3::IDrmFactory>> castFrom(const ::android::sp<::android::hardware::drm::V1_0::IDrmFactory>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_3::IDrmFactory>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IDrmFactory> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IDrmFactory> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IDrmFactory> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IDrmFactory> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IDrmFactory> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IDrmFactory> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IDrmFactory> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IDrmFactory> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::drm::V1_3::IDrmFactory>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::drm::V1_3::IDrmFactory>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::drm::V1_3::IDrmFactory::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_3
}  // namespace drm
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_3_IDRMFACTORY_H
