#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_BPHWBAR_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_BPHWBAR_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/bar/1.0/IHwBar.h>

namespace android {
namespace hardware {
namespace tests {
namespace bar {
namespace V1_0 {

struct BpHwBar : public ::android::hardware::BpInterface<IBar>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwBar(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IBar Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::bar::V1_0::IBar follow.
    static ::android::hardware::Return<void>  _hidl_thisIsNew(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);
    static ::android::hardware::Return<void>  _hidl_expectNullHandle(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_handle& h, const ::android::hardware::tests::foo::V1_0::Abc& xyz, expectNullHandle_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_takeAMask(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::foo::V1_0::IFoo::BitField bf, ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> first, const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& second, ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> third, takeAMask_cb _hidl_cb);
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::foo::V1_0::ISimple>>  _hidl_haveAInterface(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::tests::foo::V1_0::ISimple>& i);

    // Methods from ::android::hardware::tests::foo::V1_0::IFoo follow.
    ::android::hardware::Return<void> convertToBoolIfSmall(::android::hardware::tests::foo::V1_0::IFoo::Discriminator d, const ::android::hardware::hidl_vec<::android::hardware::tests::foo::V1_0::IFoo::Union>& u, convertToBoolIfSmall_cb _hidl_cb) override;
    ::android::hardware::Return<void> doThis(float param) override;
    ::android::hardware::Return<int32_t> doThatAndReturnSomething(int64_t param) override;
    ::android::hardware::Return<double> doQuiteABit(int32_t a, int64_t b, float c, double d) override;
    ::android::hardware::Return<void> doSomethingElse(const ::android::hardware::hidl_array<int32_t, 15>& param, doSomethingElse_cb _hidl_cb) override;
    ::android::hardware::Return<void> doStuffAndReturnAString(doStuffAndReturnAString_cb _hidl_cb) override;
    ::android::hardware::Return<void> mapThisVector(const ::android::hardware::hidl_vec<int32_t>& param, mapThisVector_cb _hidl_cb) override;
    ::android::hardware::Return<void> callMe(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb) override;
    ::android::hardware::Return<::android::hardware::tests::foo::V1_0::IFoo::SomeEnum> useAnEnum(::android::hardware::tests::foo::V1_0::IFoo::SomeEnum zzz) override;
    ::android::hardware::Return<void> haveAGooberVec(const ::android::hardware::hidl_vec<::android::hardware::tests::foo::V1_0::IFoo::Goober>& param) override;
    ::android::hardware::Return<void> haveAGoober(const ::android::hardware::tests::foo::V1_0::IFoo::Goober& g) override;
    ::android::hardware::Return<void> haveAGooberArray(const ::android::hardware::hidl_array<::android::hardware::tests::foo::V1_0::IFoo::Goober, 20>& lots) override;
    ::android::hardware::Return<void> haveATypeFromAnotherFile(const ::android::hardware::tests::foo::V1_0::Abc& def) override;
    ::android::hardware::Return<void> haveSomeStrings(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 3>& array, haveSomeStrings_cb _hidl_cb) override;
    ::android::hardware::Return<void> haveAStringVec(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& vector, haveAStringVec_cb _hidl_cb) override;
    ::android::hardware::Return<void> transposeMe(const ::android::hardware::hidl_array<float, 3, 5>& in, transposeMe_cb _hidl_cb) override;
    ::android::hardware::Return<void> callingDrWho(const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& in, callingDrWho_cb _hidl_cb) override;
    ::android::hardware::Return<void> transpose(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& in, transpose_cb _hidl_cb) override;
    ::android::hardware::Return<void> transpose2(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 5, 3>& in, transpose2_cb _hidl_cb) override;
    ::android::hardware::Return<void> sendVec(const ::android::hardware::hidl_vec<uint8_t>& data, sendVec_cb _hidl_cb) override;
    ::android::hardware::Return<void> sendVecVec(sendVecVec_cb _hidl_cb) override;
    ::android::hardware::Return<void> haveAVectorOfInterfaces(const ::android::hardware::hidl_vec<::android::sp<::android::hardware::tests::foo::V1_0::ISimple>>& in, haveAVectorOfInterfaces_cb _hidl_cb) override;
    ::android::hardware::Return<void> haveAVectorOfGenericInterfaces(const ::android::hardware::hidl_vec<::android::sp<::android::hidl::base::V1_0::IBase>>& in, haveAVectorOfGenericInterfaces_cb _hidl_cb) override;
    ::android::hardware::Return<void> echoNullInterface(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb, echoNullInterface_cb _hidl_cb) override;
    ::android::hardware::Return<void> createMyHandle(createMyHandle_cb _hidl_cb) override;
    ::android::hardware::Return<void> createHandles(uint32_t size, createHandles_cb _hidl_cb) override;
    ::android::hardware::Return<void> closeHandles() override;
    ::android::hardware::Return<void> repeatWithFmq(const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq& withFmq, repeatWithFmq_cb _hidl_cb) override;

    // Methods from ::android::hardware::tests::bar::V1_0::IBar follow.
    ::android::hardware::Return<void> thisIsNew() override;
    ::android::hardware::Return<void> expectNullHandle(const ::android::hardware::hidl_handle& h, const ::android::hardware::tests::foo::V1_0::Abc& xyz, expectNullHandle_cb _hidl_cb) override;
    ::android::hardware::Return<void> takeAMask(::android::hardware::tests::foo::V1_0::IFoo::BitField bf, ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> first, const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& second, ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> third, takeAMask_cb _hidl_cb) override;
    ::android::hardware::Return<::android::sp<::android::hardware::tests::foo::V1_0::ISimple>> haveAInterface(const ::android::sp<::android::hardware::tests::foo::V1_0::ISimple>& i) override;

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

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_BPHWBAR_H
