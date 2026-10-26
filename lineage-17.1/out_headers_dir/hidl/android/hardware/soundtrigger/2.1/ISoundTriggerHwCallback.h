#ifndef HIDL_GENERATED_ANDROID_HARDWARE_SOUNDTRIGGER_V2_1_ISOUNDTRIGGERHWCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_SOUNDTRIGGER_V2_1_ISOUNDTRIGGERHWCALLBACK_H

#include <android/hardware/soundtrigger/2.0/ISoundTriggerHwCallback.h>
#include <android/hardware/soundtrigger/2.0/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace soundtrigger {
namespace V2_1 {

/**
 * SoundTrigger HAL Callback interface. Obtained during SoundTrigger setup.
 */
struct ISoundTriggerHwCallback : public ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.soundtrigger@2.1::ISoundTriggerHwCallback"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct RecognitionEvent;
    struct PhraseRecognitionEvent;
    struct ModelEvent;

    /**
     * Generic recognition event sent via recognition callback.
     */
    struct RecognitionEvent final {
        ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent header __attribute__ ((aligned(8)));
        ::android::hardware::hidl_memory data __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::RecognitionEvent, header) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::RecognitionEvent, data) == 120, "wrong offset");
    static_assert(sizeof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::RecognitionEvent) == 160, "wrong size");
    static_assert(__alignof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::RecognitionEvent) == 8, "wrong alignment");

    /**
     * Specialized recognition event for key phrase recognitions.
     */
    struct PhraseRecognitionEvent final {
        ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::RecognitionEvent common __attribute__ ((aligned(8)));
        ::android::hardware::hidl_vec<::android::hardware::soundtrigger::V2_0::PhraseRecognitionExtra> phraseExtras __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::PhraseRecognitionEvent, common) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::PhraseRecognitionEvent, phraseExtras) == 160, "wrong offset");
    static_assert(sizeof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::PhraseRecognitionEvent) == 176, "wrong size");
    static_assert(__alignof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::PhraseRecognitionEvent) == 8, "wrong alignment");

    /**
     * Event sent via load sound model callback.
     */
    struct ModelEvent final {
        ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::ModelEvent header __attribute__ ((aligned(8)));
        ::android::hardware::hidl_memory data __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::ModelEvent, header) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::ModelEvent, data) == 24, "wrong offset");
    static_assert(sizeof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::ModelEvent) == 64, "wrong size");
    static_assert(__alignof(::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::ModelEvent) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Callback method called by the HAL when the sound recognition triggers
     * @param event A RecognitionEvent structure containing detailed results
     *              of the recognition triggered
     * @param cookie The cookie passed by the framework when recognition was
     *               started (see ISoundtriggerHw.startRecognition()
     */
    virtual ::android::hardware::Return<void> recognitionCallback(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::RecognitionEvent& event, int32_t cookie) = 0;

    /**
     * Callback method called by the HAL when the sound recognition triggers
     * for a key phrase sound model.
     * @param event A RecognitionEvent structure containing detailed results
     *              of the recognition triggered
     * @param cookie The cookie passed by the framework when recognition was
     *               started (see ISoundtriggerHw.startRecognition()
     */
    virtual ::android::hardware::Return<void> phraseRecognitionCallback(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::PhraseRecognitionEvent& event, int32_t cookie) = 0;

    /**
     * Callback method called by the HAL when the sound model loading completes
     * @param event A ModelEvent structure containing detailed results of the
     *              model loading operation
     * @param cookie The cookie passed by the framework when loading was
     *               initiated (see ISoundtriggerHw.loadSoundModel()
     */
    virtual ::android::hardware::Return<void> soundModelCallback(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback::ModelEvent& event, int32_t cookie) = 0;

    /**
     * Callback method called by the HAL when the sound recognition triggers.
     * 
     * @param event A RecognitionEvent structure containing detailed results
     *     of the recognition triggered
     * @param cookie The cookie passed by the framework when recognition was
     *     started (see ISoundtriggerHw.startRecognition*())
     */
    virtual ::android::hardware::Return<void> recognitionCallback_2_1(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::RecognitionEvent& event, int32_t cookie) = 0;

    /**
     * Callback method called by the HAL when the sound recognition triggers
     * for a key phrase sound model.
     * 
     * @param event A RecognitionEvent structure containing detailed results
     *     of the recognition triggered
     * @param cookie The cookie passed by the framework when recognition was
     *     started (see ISoundtriggerHw.startRecognition*())
     */
    virtual ::android::hardware::Return<void> phraseRecognitionCallback_2_1(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::PhraseRecognitionEvent& event, int32_t cookie) = 0;

    /**
     * Callback method called by the HAL when the sound model loading completes.
     * 
     * @param event A ModelEvent structure containing detailed results of the
     *     model loading operation
     * @param cookie The cookie passed by the framework when loading was
     *     initiated (see ISoundtriggerHw.loadSoundModel*())
     */
    virtual ::android::hardware::Return<void> soundModelCallback_2_1(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::ModelEvent& event, int32_t cookie) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback>> castFrom(const ::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback>> castFrom(const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ISoundTriggerHwCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISoundTriggerHwCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISoundTriggerHwCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISoundTriggerHwCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISoundTriggerHwCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISoundTriggerHwCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISoundTriggerHwCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISoundTriggerHwCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::RecognitionEvent& o);
// operator== and operator!= are not generated for RecognitionEvent

static inline std::string toString(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::PhraseRecognitionEvent& o);
// operator== and operator!= are not generated for PhraseRecognitionEvent

static inline std::string toString(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::ModelEvent& o);
// operator== and operator!= are not generated for ModelEvent

static inline std::string toString(const ::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::RecognitionEvent& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".header = ";
    os += ::android::hardware::soundtrigger::V2_0::toString(o.header);
    os += ", .data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

// operator== and operator!= are not generated for RecognitionEvent

static inline std::string toString(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::PhraseRecognitionEvent& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".common = ";
    os += ::android::hardware::soundtrigger::V2_1::toString(o.common);
    os += ", .phraseExtras = ";
    os += ::android::hardware::toString(o.phraseExtras);
    os += "}"; return os;
}

// operator== and operator!= are not generated for PhraseRecognitionEvent

static inline std::string toString(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::ModelEvent& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".header = ";
    os += ::android::hardware::soundtrigger::V2_0::toString(o.header);
    os += ", .data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

// operator== and operator!= are not generated for ModelEvent

static inline std::string toString(const ::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_1
}  // namespace soundtrigger
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_SOUNDTRIGGER_V2_1_ISOUNDTRIGGERHWCALLBACK_H
