#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_BPHWIMPORTRULES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_BPHWIMPORTRULES_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/bar/1.0/IHwImportRules.h>

namespace android {
namespace hardware {
namespace tests {
namespace bar {
namespace V1_0 {

struct BpHwImportRules : public ::android::hardware::BpInterface<IImportRules>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwImportRules(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IImportRules Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::bar::V1_0::IImportRules follow.
    static ::android::hardware::Return<void>  _hidl_rule0a(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o);
    static ::android::hardware::Return<void>  _hidl_rule0a1(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o);
    static ::android::hardware::Return<void>  _hidl_rule0b(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o);
    static ::android::hardware::Return<void>  _hidl_rule0b1(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o);
    static ::android::hardware::Return<void>  _hidl_rule0c(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::foo::V1_0::Outer& o);
    static ::android::hardware::Return<void>  _hidl_rule0d(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::foo::V1_0::Outer& o);
    static ::android::hardware::Return<void>  _hidl_rule0e(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& o);
    static ::android::hardware::Return<void>  _hidl_rule0f(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& o);
    static ::android::hardware::Return<void>  _hidl_rule0g(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::foo::V1_0::Outer::Inner& o);
    static ::android::hardware::Return<void>  _hidl_rule0h(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::foo::V1_0::Outer::Inner& o);
    static ::android::hardware::Return<void>  _hidl_rule1a(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::bar::V1_0::Def& abc);
    static ::android::hardware::Return<void>  _hidl_rule1b(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::foo::V1_0::Def& abc);
    static ::android::hardware::Return<void>  _hidl_rule2a(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::foo::V1_0::Unrelated& related);
    static ::android::hardware::Return<void>  _hidl_rule2b(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& fooCallback);

    // Methods from ::android::hardware::tests::bar::V1_0::IImportRules follow.
    ::android::hardware::Return<void> rule0a(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o) override;
    ::android::hardware::Return<void> rule0a1(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o) override;
    ::android::hardware::Return<void> rule0b(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o) override;
    ::android::hardware::Return<void> rule0b1(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o) override;
    ::android::hardware::Return<void> rule0c(const ::android::hardware::tests::foo::V1_0::Outer& o) override;
    ::android::hardware::Return<void> rule0d(const ::android::hardware::tests::foo::V1_0::Outer& o) override;
    ::android::hardware::Return<void> rule0e(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& o) override;
    ::android::hardware::Return<void> rule0f(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& o) override;
    ::android::hardware::Return<void> rule0g(const ::android::hardware::tests::foo::V1_0::Outer::Inner& o) override;
    ::android::hardware::Return<void> rule0h(const ::android::hardware::tests::foo::V1_0::Outer::Inner& o) override;
    ::android::hardware::Return<void> rule1a(const ::android::hardware::tests::bar::V1_0::Def& abc) override;
    ::android::hardware::Return<void> rule1b(const ::android::hardware::tests::foo::V1_0::Def& abc) override;
    ::android::hardware::Return<void> rule2a(const ::android::hardware::tests::foo::V1_0::Unrelated& related) override;
    ::android::hardware::Return<void> rule2b(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& fooCallback) override;

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
}  // namespace bar
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_BPHWIMPORTRULES_H
