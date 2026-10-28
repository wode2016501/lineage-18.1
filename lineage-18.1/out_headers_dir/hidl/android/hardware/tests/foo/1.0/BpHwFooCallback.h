#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_BPHWFOOCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_BPHWFOOCALLBACK_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/foo/1.0/IHwFooCallback.h>

namespace android {
namespace hardware {
namespace tests {
namespace foo {
namespace V1_0 {

struct BpHwFooCallback : public ::android::hardware::BpInterface<IFooCallback>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwFooCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IFooCallback Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::foo::V1_0::IFooCallback follow.
    static ::android::hardware::Return<void>  _hidl_heyItsYou(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb);
    static ::android::hardware::Return<bool>  _hidl_heyItsYouIsntIt(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb);
    static ::android::hardware::Return<void>  _hidl_heyItsTheMeaningOfLife(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint8_t tmol);
    static ::android::hardware::Return<void>  _hidl_reportResults(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int64_t ns, reportResults_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_youBlockedMeFor(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<int64_t, 3>& callerBlockedInfo);

    // Methods from ::android::hardware::tests::foo::V1_0::IFooCallback follow.
    ::android::hardware::Return<void> heyItsYou(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb) override;
    ::android::hardware::Return<bool> heyItsYouIsntIt(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb) override;
    ::android::hardware::Return<void> heyItsTheMeaningOfLife(uint8_t tmol) override;
    ::android::hardware::Return<void> reportResults(int64_t ns, reportResults_cb _hidl_cb) override;
    ::android::hardware::Return<void> youBlockedMeFor(const ::android::hardware::hidl_array<int64_t, 3>& callerBlockedInfo) override;

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
}  // namespace foo
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_BPHWFOOCALLBACK_H
