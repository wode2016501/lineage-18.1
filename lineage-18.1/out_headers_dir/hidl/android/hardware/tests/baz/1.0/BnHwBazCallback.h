#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BNHWBAZCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BNHWBAZCALLBACK_H

#include <android/hardware/tests/baz/1.0/IHwBazCallback.h>

namespace android {
namespace hardware {
namespace tests {
namespace baz {
namespace V1_0 {

struct BnHwBazCallback : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwBazCallback(const ::android::sp<IBazCallback> &_hidl_impl);
    explicit BnHwBazCallback(const ::android::sp<IBazCallback> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwBazCallback();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IBazCallback Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IBazCallback> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::tests::baz::V1_0::IBazCallback follow.
    static ::android::status_t _hidl_heyItsMe(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_hey(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::tests::baz::V1_0::IBazCallback follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IBazCallback> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace baz
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BNHWBAZCALLBACK_H
