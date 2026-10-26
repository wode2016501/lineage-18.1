#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_BPHWSIMPLE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_BPHWSIMPLE_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/foo/1.0/IHwSimple.h>

namespace android {
namespace hardware {
namespace tests {
namespace foo {
namespace V1_0 {

struct BpHwSimple : public ::android::hardware::BpInterface<ISimple>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwSimple(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef ISimple Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::foo::V1_0::ISimple follow.
    static ::android::hardware::Return<int32_t>  _hidl_getCookie(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_customVecInt(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, customVecInt_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_customVecStr(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, customVecStr_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_mystr(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, mystr_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_myhandle(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, myhandle_cb _hidl_cb);

    // Methods from ::android::hardware::tests::foo::V1_0::ISimple follow.
    ::android::hardware::Return<int32_t> getCookie() override;
    ::android::hardware::Return<void> customVecInt(customVecInt_cb _hidl_cb) override;
    ::android::hardware::Return<void> customVecStr(customVecStr_cb _hidl_cb) override;
    ::android::hardware::Return<void> mystr(mystr_cb _hidl_cb) override;
    ::android::hardware::Return<void> myhandle(myhandle_cb _hidl_cb) override;

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

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_BPHWSIMPLE_H
