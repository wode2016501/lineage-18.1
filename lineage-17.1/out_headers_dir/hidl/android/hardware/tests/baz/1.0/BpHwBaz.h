#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BPHWBAZ_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BPHWBAZ_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/baz/1.0/IHwBaz.h>

namespace android {
namespace hardware {
namespace tests {
namespace baz {
namespace V1_0 {

struct BpHwBaz : public ::android::hardware::BpInterface<IBaz>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwBaz(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IBaz Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::baz::V1_0::IBaz follow.
    static ::android::hardware::Return<void>  _hidl_doThis(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, float param);
    static ::android::hardware::Return<int32_t>  _hidl_doThatAndReturnSomething(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int64_t param);
    static ::android::hardware::Return<double>  _hidl_doQuiteABit(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t a, int64_t b, float c, double d);
    static ::android::hardware::Return<void>  _hidl_doSomethingElse(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<int32_t, 15>& param, doSomethingElse_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_doStuffAndReturnAString(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, doStuffAndReturnAString_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_mapThisVector(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<int32_t>& param, mapThisVector_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_callMe(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::tests::baz::V1_0::IBazCallback>& cb);
    static ::android::hardware::Return<void>  _hidl_callMeLater(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::tests::baz::V1_0::IBazCallback>& cb);
    static ::android::hardware::Return<void>  _hidl_iAmFreeNow(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_dieNow(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<::android::hardware::tests::baz::V1_0::IBaz::SomeEnum>  _hidl_useAnEnum(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum zzz);
    static ::android::hardware::Return<void>  _hidl_haveSomeStrings(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<::android::hardware::hidl_string, 3>& array, haveSomeStrings_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_haveAStringVec(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& vector, haveAStringVec_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_returnABunchOfStrings(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, returnABunchOfStrings_cb _hidl_cb);
    static ::android::hardware::Return<::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::BitField>>  _hidl_returnABitField(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<uint32_t>  _hidl_size(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t size);
    static ::android::hardware::Return<void>  _hidl_getNestedStructs(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getNestedStructs_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_haveSomeStructWithInterface(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface& swi, haveSomeStructWithInterface_cb _hidl_cb);

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

    // Methods from ::android::hardware::tests::baz::V1_0::IBaz follow.
    ::android::hardware::Return<void> doThis(float param) override;
    ::android::hardware::Return<int32_t> doThatAndReturnSomething(int64_t param) override;
    ::android::hardware::Return<double> doQuiteABit(int32_t a, int64_t b, float c, double d) override;
    ::android::hardware::Return<void> doSomethingElse(const ::android::hardware::hidl_array<int32_t, 15>& param, doSomethingElse_cb _hidl_cb) override;
    ::android::hardware::Return<void> doStuffAndReturnAString(doStuffAndReturnAString_cb _hidl_cb) override;
    ::android::hardware::Return<void> mapThisVector(const ::android::hardware::hidl_vec<int32_t>& param, mapThisVector_cb _hidl_cb) override;
    ::android::hardware::Return<void> callMe(const ::android::sp<::android::hardware::tests::baz::V1_0::IBazCallback>& cb) override;
    ::android::hardware::Return<void> callMeLater(const ::android::sp<::android::hardware::tests::baz::V1_0::IBazCallback>& cb) override;
    ::android::hardware::Return<void> iAmFreeNow() override;
    ::android::hardware::Return<void> dieNow() override;
    ::android::hardware::Return<::android::hardware::tests::baz::V1_0::IBaz::SomeEnum> useAnEnum(::android::hardware::tests::baz::V1_0::IBaz::SomeEnum zzz) override;
    ::android::hardware::Return<void> haveSomeStrings(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 3>& array, haveSomeStrings_cb _hidl_cb) override;
    ::android::hardware::Return<void> haveAStringVec(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& vector, haveAStringVec_cb _hidl_cb) override;
    ::android::hardware::Return<void> returnABunchOfStrings(returnABunchOfStrings_cb _hidl_cb) override;
    ::android::hardware::Return<::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::BitField>> returnABitField() override;
    ::android::hardware::Return<uint32_t> size(uint32_t size) override;
    ::android::hardware::Return<void> getNestedStructs(getNestedStructs_cb _hidl_cb) override;
    ::android::hardware::Return<void> haveSomeStructWithInterface(const ::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface& swi, haveSomeStructWithInterface_cb _hidl_cb) override;

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

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_BPHWBAZ_H
