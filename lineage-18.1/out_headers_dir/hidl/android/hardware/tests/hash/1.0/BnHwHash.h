#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_HASH_V1_0_BNHWHASH_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_HASH_V1_0_BNHWHASH_H

#include <android/hardware/tests/hash/1.0/IHwHash.h>

namespace android {
namespace hardware {
namespace tests {
namespace hash {
namespace V1_0 {

struct BnHwHash : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwHash(const ::android::sp<IHash> &_hidl_impl);
    explicit BnHwHash(const ::android::sp<IHash> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwHash();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IHash Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IHash> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::tests::hash::V1_0::IHash follow.
    static ::android::status_t _hidl_dummy(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_functions(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::tests::hash::V1_0::IHash follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IHash> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace hash
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_HASH_V1_0_BNHWHASH_H
