#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_BNHWEXPRESSIONEXT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_BNHWEXPRESSIONEXT_H

#include <android/hardware/tests/expression/1.0/IHwExpressionExt.h>

namespace android {
namespace hardware {
namespace tests {
namespace expression {
namespace V1_0 {

struct BnHwExpressionExt : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwExpressionExt(const ::android::sp<IExpressionExt> &_hidl_impl);
    explicit BnHwExpressionExt(const ::android::sp<IExpressionExt> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwExpressionExt();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IExpressionExt Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IExpressionExt> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::tests::expression::V1_0::IExpressionExt follow.
    static ::android::status_t _hidl_foo3(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_foo2(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_foo1(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::tests::expression::V1_0::IExpressionExt follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IExpressionExt> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace expression
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_BNHWEXPRESSIONEXT_H
