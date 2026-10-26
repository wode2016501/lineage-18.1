#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_BPHWBENCHMARKMSGQ_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_BPHWBENCHMARKMSGQ_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/msgq/1.0/IHwBenchmarkMsgQ.h>

namespace android {
namespace hardware {
namespace tests {
namespace msgq {
namespace V1_0 {

struct BpHwBenchmarkMsgQ : public ::android::hardware::BpInterface<IBenchmarkMsgQ>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwBenchmarkMsgQ(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IBenchmarkMsgQ Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ follow.
    static ::android::hardware::Return<void>  _hidl_configureClientInboxSyncReadWrite(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, configureClientInboxSyncReadWrite_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_configureClientOutboxSyncReadWrite(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, configureClientOutboxSyncReadWrite_cb _hidl_cb);
    static ::android::hardware::Return<bool>  _hidl_requestWrite(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t count);
    static ::android::hardware::Return<bool>  _hidl_requestRead(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t count);
    static ::android::hardware::Return<void>  _hidl_benchmarkPingPong(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t numIter);
    static ::android::hardware::Return<void>  _hidl_benchmarkServiceWriteClientRead(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t numIter);
    static ::android::hardware::Return<void>  _hidl_sendTimeData(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<int64_t>& timeData);

    // Methods from ::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ follow.
    ::android::hardware::Return<void> configureClientInboxSyncReadWrite(configureClientInboxSyncReadWrite_cb _hidl_cb) override;
    ::android::hardware::Return<void> configureClientOutboxSyncReadWrite(configureClientOutboxSyncReadWrite_cb _hidl_cb) override;
    ::android::hardware::Return<bool> requestWrite(int32_t count) override;
    ::android::hardware::Return<bool> requestRead(int32_t count) override;
    ::android::hardware::Return<void> benchmarkPingPong(uint32_t numIter) override;
    ::android::hardware::Return<void> benchmarkServiceWriteClientRead(uint32_t numIter) override;
    ::android::hardware::Return<void> sendTimeData(const ::android::hardware::hidl_vec<int64_t>& timeData) override;

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

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_BPHWBENCHMARKMSGQ_H
