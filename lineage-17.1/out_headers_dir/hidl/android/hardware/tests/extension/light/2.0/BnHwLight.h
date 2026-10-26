#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_LIGHT_V2_0_BNHWLIGHT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_LIGHT_V2_0_BNHWLIGHT_H

#include <android/hardware/tests/extension/light/2.0/IHwLight.h>

namespace android {
namespace hardware {
namespace tests {
namespace extension {
namespace light {
namespace V2_0 {

struct BnHwLight : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwLight(const ::android::sp<ILight> &_hidl_impl);
    explicit BnHwLight(const ::android::sp<ILight> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwLight();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ILight Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ILight> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::tests::extension::light::V2_0::ILight follow.
    static ::android::status_t _hidl_setLightExt(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::light::V2_0::ILight follow.

    // Methods from ::android::hardware::tests::extension::light::V2_0::ILight follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ILight> _hidl_mImpl;
};

}  // namespace V2_0
}  // namespace light
}  // namespace extension
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_LIGHT_V2_0_BNHWLIGHT_H
