#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_BNHWCOMPLICATED_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_BNHWCOMPLICATED_H

#include <android/hardware/tests/bar/1.0/IHwComplicated.h>

namespace android {
namespace hardware {
namespace tests {
namespace bar {
namespace V1_0 {

struct BnHwComplicated : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwComplicated(const ::android::sp<IComplicated> &_hidl_impl);
    explicit BnHwComplicated(const ::android::sp<IComplicated> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwComplicated();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IComplicated Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IComplicated> getImpl() { return _hidl_mImpl; }

private:
    // Methods from ::android::hardware::tests::foo::V1_0::ISimple follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IComplicated> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace bar
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_BNHWCOMPLICATED_H
