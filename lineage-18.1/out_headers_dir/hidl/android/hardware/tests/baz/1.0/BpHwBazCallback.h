#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BPHWBAZCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BPHWBAZCALLBACK_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/baz/1.0/IHwBazCallback.h>

namespace android {
namespace hardware {
namespace tests {
namespace baz {
namespace V1_0 {

struct BpHwBazCallback : public ::android::hardware::BpInterface<IBazCallback>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwBazCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IBazCallback Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::baz::V1_0::IBazCallback follow.
    static ::android::hardware::Return<void>  _hidl_heyItsMe(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::tests::baz::V1_0::IBazCallback>& cb);
    static ::android::hardware::Return<void>  _hidl_hey(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::android::hardware::tests::baz::V1_0::IBazCallback follow.
    ::android::hardware::Return<void> heyItsMe(const ::android::sp<::android::hardware::tests::baz::V1_0::IBazCallback>& cb) override;
    ::android::hardware::Return<void> hey() override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V1_0
}  // namespace baz
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BPHWBAZCALLBACK_H
