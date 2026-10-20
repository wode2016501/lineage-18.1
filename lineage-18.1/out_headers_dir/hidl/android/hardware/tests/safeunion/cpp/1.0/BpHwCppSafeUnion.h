#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_CPP_V1_0_BPHWCPPSAFEUNION_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_CPP_V1_0_BPHWCPPSAFEUNION_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/safeunion/cpp/1.0/IHwCppSafeUnion.h>

namespace android {
namespace hardware {
namespace tests {
namespace safeunion {
namespace cpp {
namespace V1_0 {

struct BpHwCppSafeUnion : public ::android::hardware::BpInterface<ICppSafeUnion>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwCppSafeUnion(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef ICppSafeUnion Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion follow.
    static ::android::hardware::Return<void>  _hidl_repeatPointerFmqSafeUnion(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion::PointerFmqSafeUnion& fmq, repeatPointerFmqSafeUnion_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_repeatFmqSafeUnion(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion::FmqSafeUnion& fmq, repeatFmqSafeUnion_cb _hidl_cb);

    // Methods from ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion follow.
    ::android::hardware::Return<void> repeatPointerFmqSafeUnion(const ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion::PointerFmqSafeUnion& fmq, repeatPointerFmqSafeUnion_cb _hidl_cb) override;
    ::android::hardware::Return<void> repeatFmqSafeUnion(const ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion::FmqSafeUnion& fmq, repeatFmqSafeUnion_cb _hidl_cb) override;

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
}  // namespace cpp
}  // namespace safeunion
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_CPP_V1_0_BPHWCPPSAFEUNION_H
