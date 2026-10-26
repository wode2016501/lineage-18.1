#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_BNHWTHEIRTYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_BNHWTHEIRTYPES_H

#include <android/hardware/tests/foo/1.0/IHwTheirTypes.h>

namespace android {
namespace hardware {
namespace tests {
namespace foo {
namespace V1_0 {

struct BnHwTheirTypes : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwTheirTypes(const ::android::sp<ITheirTypes> &_hidl_impl);
    explicit BnHwTheirTypes(const ::android::sp<ITheirTypes> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwTheirTypes();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ITheirTypes Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ITheirTypes> getImpl() { return _hidl_mImpl; }

private:
    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ITheirTypes> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace foo
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_BNHWTHEIRTYPES_H
