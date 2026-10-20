#ifndef HIDL_GENERATED_ANDROID_HARDWARE_SOUNDTRIGGER_V2_2_ISOUNDTRIGGERHW_H
#define HIDL_GENERATED_ANDROID_HARDWARE_SOUNDTRIGGER_V2_2_ISOUNDTRIGGERHW_H

#include <android/hardware/soundtrigger/2.0/types.h>
#include <android/hardware/soundtrigger/2.1/ISoundTriggerHw.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace soundtrigger {
namespace V2_2 {

/**
 * SoundTrigger HAL interface. Used for hardware recognition of hotwords
 * and other sounds.
 */
struct ISoundTriggerHw : public ::android::hardware::soundtrigger::V2_1::ISoundTriggerHw {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.soundtrigger@2.2::ISoundTriggerHw"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getProperties
     */
    using getProperties_cb = std::function<void(int32_t retval, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::Properties& properties)>;
    /**
     * Retrieve implementation properties.
     * @return retval Operation completion status: 0 in case of success,
     *                -ENODEV in case of initialization error.
     * @return properties A Properties structure containing implementation
     *                    description and capabilities.
     */
    virtual ::android::hardware::Return<void> getProperties(getProperties_cb _hidl_cb) = 0;

    /**
     * Return callback for loadSoundModel
     */
    using loadSoundModel_cb = std::function<void(int32_t retval, int32_t modelHandle)>;
    /**
     * Load a sound model. Once loaded, recognition of this model can be
     * started and stopped. Only one active recognition per model at a time.
     * The SoundTrigger service must handle concurrent recognition requests by
     * different users/applications on the same model.
     * The implementation returns a unique handle used by other functions
     * (unloadSoundModel(), startRecognition(), etc...
     * @param soundModel A SoundModel structure describing the sound model to
     *                   load.
     * @param callback The callback interface on which the soundmodelCallback()
     *                 method will be called upon completion.
     * @param cookie The value of the cookie argument passed to the completion
     *               callback. This unique context information is assigned and
     *               used only by the framework.
     * @return retval Operation completion status: 0 in case of success,
     *                -EINVAL in case of invalid sound model (e.g 0 data size),
     *                -ENOSYS in case of invalid operation (e.g max number of
     *                models exceeded),
     *                -ENOMEM in case of memory allocation failure,
     *                -ENODEV in case of initialization error.
     * @return modelHandle A unique handle assigned by the HAL for use by the
     *                framework when controlling activity for this sound model.
     */
    virtual ::android::hardware::Return<void> loadSoundModel(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::SoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie, loadSoundModel_cb _hidl_cb) = 0;

    /**
     * Return callback for loadPhraseSoundModel
     */
    using loadPhraseSoundModel_cb = std::function<void(int32_t retval, int32_t modelHandle)>;
    /**
     * Load a key phrase sound model. Once loaded, recognition of this model can
     * be started and stopped. Only one active recognition per model at a time.
     * The SoundTrigger service must handle concurrent recognition requests by
     * different users/applications on the same model.
     * The implementation returns a unique handle used by other functions
     * (unloadSoundModel(), startRecognition(), etc...
     * @param soundModel A PhraseSoundModel structure describing the sound model
     *                   to load.
     * @param callback The callback interface on which the soundmodelCallback()
     *                 method will be called upon completion.
     * @param cookie The value of the cookie argument passed to the completion
     *               callback. This unique context information is assigned and
     *               used only by the framework.
     * @return retval Operation completion status: 0 in case of success,
     *                -EINVAL in case of invalid sound model (e.g 0 data size),
     *                -ENOSYS in case of invalid operation (e.g max number of
     *                models exceeded),
     *                -ENOMEM in case of memory allocation failure,
     *                -ENODEV in case of initialization error.
     * @return modelHandle A unique handle assigned by the HAL for use by the
     *                framework when controlling activity for this sound model.
     */
    virtual ::android::hardware::Return<void> loadPhraseSoundModel(const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::PhraseSoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie, loadPhraseSoundModel_cb _hidl_cb) = 0;

    /**
     * Unload a sound model. A sound model may be unloaded to make room for a
     * new one to overcome implementation limitations.
     * @param modelHandle the handle of the sound model to unload
     * @return retval Operation completion status: 0 in case of success,
     *                -ENOSYS if the model is not loaded,
     *                -ENODEV in case of initialization error.
     */
    virtual ::android::hardware::Return<int32_t> unloadSoundModel(int32_t modelHandle) = 0;

    /**
     * Start recognition on a given model. Only one recognition active
     * at a time per model. Once recognition succeeds of fails, the callback
     * is called.
     * @param modelHandle the handle of the sound model to use for recognition
     * @param config A RecognitionConfig structure containing attributes of the
     *               recognition to perform
     * @param callback The callback interface on which the recognitionCallback()
     *                 method must be called upon recognition.
     * @param cookie The value of the cookie argument passed to the recognition
     *               callback. This unique context information is assigned and
     *               used only by the framework.
     * @return retval Operation completion status: 0 in case of success,
     *                -EINVAL in case of invalid recognition attributes,
     *                -ENOSYS in case of invalid model handle,
     *                -ENOMEM in case of memory allocation failure,
     *                -ENODEV in case of initialization error.
     */
    virtual ::android::hardware::Return<int32_t> startRecognition(int32_t modelHandle, const ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw::RecognitionConfig& config, const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback>& callback, int32_t cookie) = 0;

    /**
     * Stop recognition on a given model.
     * The implementation must not call the recognition callback when stopped
     * via this method.
     * @param modelHandle The handle of the sound model to use for recognition
     * @return retval Operation completion status: 0 in case of success,
     *                -ENOSYS in case of invalid model handle,
     *                -ENODEV in case of initialization error.
     */
    virtual ::android::hardware::Return<int32_t> stopRecognition(int32_t modelHandle) = 0;

    /**
     * Stop recognition on all models.
     * @return retval Operation completion status: 0 in case of success,
     *                -ENODEV in case of initialization error.
     */
    virtual ::android::hardware::Return<int32_t> stopAllRecognitions() = 0;

    /**
     * Return callback for loadSoundModel_2_1
     */
    using loadSoundModel_2_1_cb = std::function<void(int32_t retval, int32_t modelHandle)>;
    // @callflow(next={"startRecognition_2_1", "unloadSoundModel"})
    /**
     * Load a sound model. Once loaded, recognition of this model can be
     * started and stopped. Only one active recognition per model at a time.
     * The SoundTrigger service must handle concurrent recognition requests by
     * different users/applications on the same model.
     * The implementation returns a unique handle used by other functions
     * (unloadSoundModel(), startRecognition*(), etc...
     * 
     * Must have the exact same semantics as loadSoundModel from
     * ISoundTriggerHw@2.0 except that the SoundModel uses shared memory
     * instead of data.
     * 
     * @param soundModel A SoundModel structure describing the sound model
     *     to load.
     * @param callback The callback interface on which the soundmodelCallback*()
     *     method must be called upon completion.
     * @param cookie The value of the cookie argument passed to the completion
     *     callback. This unique context information is assigned and
     *     used only by the framework.
     * @return retval Operation completion status: 0 in case of success,
     *     -EINVAL in case of invalid sound model (e.g 0 data size),
     *     -ENOSYS in case of invalid operation (e.g max number of models
     *             exceeded),
     *     -ENOMEM in case of memory allocation failure,
     *     -ENODEV in case of initialization error.
     * @return modelHandle A unique handle assigned by the HAL for use by the
     *     framework when controlling activity for this sound model.
     */
    virtual ::android::hardware::Return<void> loadSoundModel_2_1(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHw::SoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback>& callback, int32_t cookie, loadSoundModel_2_1_cb _hidl_cb) = 0;

    /**
     * Return callback for loadPhraseSoundModel_2_1
     */
    using loadPhraseSoundModel_2_1_cb = std::function<void(int32_t retval, int32_t modelHandle)>;
    // @callflow(next={"startRecognition_2_1", "unloadSoundModel"})
    /**
     * Load a key phrase sound model. Once loaded, recognition of this model can
     * be started and stopped. Only one active recognition per model at a time.
     * The SoundTrigger service must handle concurrent recognition requests by
     * different users/applications on the same model.
     * The implementation returns a unique handle used by other functions
     * (unloadSoundModel(), startRecognition*(), etc...
     * 
     * Must have the exact same semantics as loadPhraseSoundModel from
     * ISoundTriggerHw@2.0 except that the PhraseSoundModel uses shared memory
     * instead of data.
     * 
     * @param soundModel A PhraseSoundModel structure describing the sound model
     *     to load.
     * @param callback The callback interface on which the soundmodelCallback*()
     *     method must be called upon completion.
     * @param cookie The value of the cookie argument passed to the completion
     *     callback. This unique context information is assigned and
     *     used only by the framework.
     * @return retval Operation completion status: 0 in case of success,
     *     -EINVAL in case of invalid sound model (e.g 0 data size),
     *     -ENOSYS in case of invalid operation (e.g max number of models
     *             exceeded),
     *     -ENOMEM in case of memory allocation failure,
     *     -ENODEV in case of initialization error.
     * @return modelHandle A unique handle assigned by the HAL for use by the
     *     framework when controlling activity for this sound model.
     */
    virtual ::android::hardware::Return<void> loadPhraseSoundModel_2_1(const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHw::PhraseSoundModel& soundModel, const ::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback>& callback, int32_t cookie, loadPhraseSoundModel_2_1_cb _hidl_cb) = 0;

    // @callflow(next={"stopRecognition", "stopAllRecognitions"})
    /**
     * Start recognition on a given model. Only one recognition active
     * at a time per model. Once recognition succeeds of fails, the callback
     * is called.
     * 
     * Must have the exact same semantics as startRecognition from
     * ISoundTriggerHw@2.0 except that the RecognitionConfig uses shared memory
     * instead of data.
     * 
     * @param modelHandle the handle of the sound model to use for recognition
     * @param config A RecognitionConfig structure containing attributes of the
     *     recognition to perform
     * @param callback The callback interface on which the recognitionCallback()
     *     method must be called upon recognition.
     * @param cookie The value of the cookie argument passed to the recognition
     *     callback. This unique context information is assigned and
     *     used only by the framework.
     * @return retval Operation completion status: 0 in case of success,
     *     -EINVAL in case of invalid recognition attributes,
     *     -ENOSYS in case of invalid model handle,
     *     -ENOMEM in case of memory allocation failure,
     *     -ENODEV in case of initialization error.
     */
    virtual ::android::hardware::Return<int32_t> startRecognition_2_1(int32_t modelHandle, const ::android::hardware::soundtrigger::V2_1::ISoundTriggerHw::RecognitionConfig& config, const ::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHwCallback>& callback, int32_t cookie) = 0;

    /**
     * Get the state of a given model.
     * The model state is returned asynchronously as a RecognitionEvent via
     * the callback that was registered in StartRecognition().
     * @param modelHandle The handle of the sound model whose state is being
     *                    queried.
     * @return retval Operation completion status: 0 in case of success,
     *                -ENOSYS in case of invalid model handle,
     *                -ENOMEM in case of memory allocation failure,
     *                -ENODEV in case of initialization error,
     *                -EINVAL in case where a recognition event is already
     *                        being processed.
     */
    virtual ::android::hardware::Return<int32_t> getModelState(int32_t modelHandle) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_2::ISoundTriggerHw>> castFrom(const ::android::sp<::android::hardware::soundtrigger::V2_2::ISoundTriggerHw>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_2::ISoundTriggerHw>> castFrom(const ::android::sp<::android::hardware::soundtrigger::V2_1::ISoundTriggerHw>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_2::ISoundTriggerHw>> castFrom(const ::android::sp<::android::hardware::soundtrigger::V2_0::ISoundTriggerHw>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::soundtrigger::V2_2::ISoundTriggerHw>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ISoundTriggerHw> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISoundTriggerHw> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISoundTriggerHw> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISoundTriggerHw> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISoundTriggerHw> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISoundTriggerHw> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISoundTriggerHw> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISoundTriggerHw> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::soundtrigger::V2_2::ISoundTriggerHw>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::soundtrigger::V2_2::ISoundTriggerHw>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::soundtrigger::V2_2::ISoundTriggerHw::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_2
}  // namespace soundtrigger
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_SOUNDTRIGGER_V2_2_ISOUNDTRIGGERHW_H
