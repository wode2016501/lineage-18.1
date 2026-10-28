#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_BPHWTESTMSGQ_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_BPHWTESTMSGQ_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/msgq/1.0/IHwTestMsgQ.h>

namespace android {
namespace hardware {
namespace tests {
namespace msgq {
namespace V1_0 {

struct BpHwTestMsgQ : public ::android::hardware::BpInterface<ITestMsgQ>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwTestMsgQ(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef ITestMsgQ Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::msgq::V1_0::ITestMsgQ follow.
    static ::android::hardware::Return<bool>  _hidl_configureFmqSyncReadWrite(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::MQDescriptorSync<uint16_t>& mqDesc);
    static ::android::hardware::Return<void>  _hidl_getFmqUnsyncWrite(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool configureFmq, getFmqUnsyncWrite_cb _hidl_cb);
    static ::android::hardware::Return<bool>  _hidl_requestWriteFmqSync(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t count);
    static ::android::hardware::Return<bool>  _hidl_requestReadFmqSync(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t count);
    static ::android::hardware::Return<bool>  _hidl_requestWriteFmqUnsync(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t count);
    static ::android::hardware::Return<bool>  _hidl_requestReadFmqUnsync(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t count);
    static ::android::hardware::Return<void>  _hidl_requestBlockingRead(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t count);
    static ::android::hardware::Return<void>  _hidl_requestBlockingReadDefaultEventFlagBits(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t count);
    static ::android::hardware::Return<void>  _hidl_requestBlockingReadRepeat(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t count, int32_t numIter);

    // Methods from ::android::hardware::tests::msgq::V1_0::ITestMsgQ follow.
    ::android::hardware::Return<bool> configureFmqSyncReadWrite(const ::android::hardware::MQDescriptorSync<uint16_t>& mqDesc) override;
    ::android::hardware::Return<void> getFmqUnsyncWrite(bool configureFmq, getFmqUnsyncWrite_cb _hidl_cb) override;
    ::android::hardware::Return<bool> requestWriteFmqSync(int32_t count) override;
    ::android::hardware::Return<bool> requestReadFmqSync(int32_t count) override;
    ::android::hardware::Return<bool> requestWriteFmqUnsync(int32_t count) override;
    ::android::hardware::Return<bool> requestReadFmqUnsync(int32_t count) override;
    ::android::hardware::Return<void> requestBlockingRead(int32_t count) override;
    ::android::hardware::Return<void> requestBlockingReadDefaultEventFlagBits(int32_t count) override;
    ::android::hardware::Return<void> requestBlockingReadRepeat(int32_t count, int32_t numIter) override;

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
}  // namespace msgq
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_BPHWTESTMSGQ_H
