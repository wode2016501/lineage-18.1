#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_BPHWEXPRESSIONEXT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_BPHWEXPRESSIONEXT_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/expression/1.0/IHwExpressionExt.h>

namespace android {
namespace hardware {
namespace tests {
namespace expression {
namespace V1_0 {

struct BpHwExpressionExt : public ::android::hardware::BpInterface<IExpressionExt>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwExpressionExt(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IExpressionExt Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::expression::V1_0::IExpressionExt follow.
    static ::android::hardware::Return<void>  _hidl_foo3(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<int32_t, 20 /* IExpression.Constants:MAX_ARRAY_SIZE */>& array);
    static ::android::hardware::Return<void>  _hidl_foo2(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<::android::hardware::tests::expression::V1_0::IExpression::Color, 16 /* (((Constants:MAX_ARRAY_SIZE << 1) - ((AlsoConstants:CONST_FOO + 1) * 8)) >> 1) */>& array);
    static ::android::hardware::Return<void>  _hidl_foo1(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<int32_t, 5 /* (Constants:CONST_FOO + 5) */>& array);

    // Methods from ::android::hardware::tests::expression::V1_0::IExpressionExt follow.
    ::android::hardware::Return<void> foo3(const ::android::hardware::hidl_array<int32_t, 20 /* IExpression.Constants:MAX_ARRAY_SIZE */>& array) override;
    ::android::hardware::Return<void> foo2(const ::android::hardware::hidl_array<::android::hardware::tests::expression::V1_0::IExpression::Color, 16 /* (((Constants:MAX_ARRAY_SIZE << 1) - ((AlsoConstants:CONST_FOO + 1) * 8)) >> 1) */>& array) override;
    ::android::hardware::Return<void> foo1(const ::android::hardware::hidl_array<int32_t, 5 /* (Constants:CONST_FOO + 5) */>& array) override;

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
}  // namespace expression
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_BPHWEXPRESSIONEXT_H
