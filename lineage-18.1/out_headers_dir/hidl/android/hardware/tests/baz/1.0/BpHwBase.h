#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BPHWBASE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BPHWBASE_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/baz/1.0/IHwBase.h>

namespace android {
namespace hardware {
namespace tests {
namespace baz {
namespace V1_0 {

struct BpHwBase : public ::android::hardware::BpInterface<IBase>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwBase(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IBase Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::baz::V1_0::IBase follow.
    static ::android::hardware::Return<void>  _hidl_someBaseMethod(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<bool>  _hidl_someBoolMethod(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool x);
    static ::android::hardware::Return<void>  _hidl_someBoolArrayMethod(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<bool, 3>& x, someBoolArrayMethod_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_someBoolVectorMethod(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<bool>& x, someBoolVectorMethod_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_someOtherBaseMethod(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::baz::V1_0::IBase::Foo& foo, someOtherBaseMethod_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_someMethodWithFooArrays(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<::android::hardware::tests::baz::V1_0::IBase::Foo, 2>& fooInput, someMethodWithFooArrays_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_someMethodWithFooVectors(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::tests::baz::V1_0::IBase::Foo>& fooInput, someMethodWithFooVectors_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_someMethodWithVectorOfArray(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& in, someMethodWithVectorOfArray_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_someMethodTakingAVectorOfArray(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 6>>& in, someMethodTakingAVectorOfArray_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_transpose(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& in, transpose_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_transpose2(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<::android::hardware::hidl_string, 5, 3>& in, transpose2_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_takeAMask(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::baz::V1_0::IBase::BitField bf, ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::BitField> first, const ::android::hardware::tests::baz::V1_0::IBase::MyMask& second, ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::BitField> third, takeAMask_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_testArrays(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& in, testArrays_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_testByteVecs(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 128>>& in, testByteVecs_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_testBooleanVecs(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::hidl_array<bool, 128>>& in, testBooleanVecs_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_testDoubleVecs(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::hidl_array<double, 128>>& in, testDoubleVecs_cb _hidl_cb);

    // Methods from ::android::hardware::tests::baz::V1_0::IBase follow.
    ::android::hardware::Return<void> someBaseMethod() override;
    ::android::hardware::Return<bool> someBoolMethod(bool x) override;
    ::android::hardware::Return<void> someBoolArrayMethod(const ::android::hardware::hidl_array<bool, 3>& x, someBoolArrayMethod_cb _hidl_cb) override;
    ::android::hardware::Return<void> someBoolVectorMethod(const ::android::hardware::hidl_vec<bool>& x, someBoolVectorMethod_cb _hidl_cb) override;
    ::android::hardware::Return<void> someOtherBaseMethod(const ::android::hardware::tests::baz::V1_0::IBase::Foo& foo, someOtherBaseMethod_cb _hidl_cb) override;
    ::android::hardware::Return<void> someMethodWithFooArrays(const ::android::hardware::hidl_array<::android::hardware::tests::baz::V1_0::IBase::Foo, 2>& fooInput, someMethodWithFooArrays_cb _hidl_cb) override;
    ::android::hardware::Return<void> someMethodWithFooVectors(const ::android::hardware::hidl_vec<::android::hardware::tests::baz::V1_0::IBase::Foo>& fooInput, someMethodWithFooVectors_cb _hidl_cb) override;
    ::android::hardware::Return<void> someMethodWithVectorOfArray(const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& in, someMethodWithVectorOfArray_cb _hidl_cb) override;
    ::android::hardware::Return<void> someMethodTakingAVectorOfArray(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 6>>& in, someMethodTakingAVectorOfArray_cb _hidl_cb) override;
    ::android::hardware::Return<void> transpose(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& in, transpose_cb _hidl_cb) override;
    ::android::hardware::Return<void> transpose2(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 5, 3>& in, transpose2_cb _hidl_cb) override;
    ::android::hardware::Return<void> takeAMask(::android::hardware::tests::baz::V1_0::IBase::BitField bf, ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::BitField> first, const ::android::hardware::tests::baz::V1_0::IBase::MyMask& second, ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::BitField> third, takeAMask_cb _hidl_cb) override;
    ::android::hardware::Return<void> testArrays(const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& in, testArrays_cb _hidl_cb) override;
    ::android::hardware::Return<void> testByteVecs(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 128>>& in, testByteVecs_cb _hidl_cb) override;
    ::android::hardware::Return<void> testBooleanVecs(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<bool, 128>>& in, testBooleanVecs_cb _hidl_cb) override;
    ::android::hardware::Return<void> testDoubleVecs(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<double, 128>>& in, testDoubleVecs_cb _hidl_cb) override;

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

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BPHWBASE_H
