#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_INHERITANCE_V1_0_BNHWPARENT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_INHERITANCE_V1_0_BNHWPARENT_H

#include <android/hardware/tests/inheritance/1.0/IHwParent.h>

namespace android {
namespace hardware {
namespace tests {
namespace inheritance {
namespace V1_0 {

struct BnHwParent : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwParent(const ::android::sp<IParent> &_hidl_impl);
    explicit BnHwParent(const ::android::sp<IParent> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwParent();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IParent Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IParent> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::tests::inheritance::V1_0::IParent follow.
    static ::android::status_t _hidl_doParent(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::tests::inheritance::V1_0::IGrandparent follow.

    // Methods from ::android::hardware::tests::inheritance::V1_0::IParent follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IParent> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace inheritance
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_INHERITANCE_V1_0_BNHWPARENT_H
