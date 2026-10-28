#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_LAZY_V1_0_BNHWLAZY_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_LAZY_V1_0_BNHWLAZY_H

#include <android/hardware/tests/lazy/1.0/IHwLazy.h>

namespace android {
namespace hardware {
namespace tests {
namespace lazy {
namespace V1_0 {

struct BnHwLazy : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwLazy(const ::android::sp<ILazy> &_hidl_impl);
    explicit BnHwLazy(const ::android::sp<ILazy> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwLazy();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef ILazy Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<ILazy> getImpl() { return _hidl_mImpl; }

private:
    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<ILazy> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace lazy
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_LAZY_V1_0_BNHWLAZY_H
