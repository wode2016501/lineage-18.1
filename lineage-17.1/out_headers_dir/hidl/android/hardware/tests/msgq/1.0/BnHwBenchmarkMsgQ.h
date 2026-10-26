#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_BNHWBENCHMARKMSGQ_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_BNHWBENCHMARKMSGQ_H

#include <android/hardware/tests/msgq/1.0/IHwBenchmarkMsgQ.h>

namespace android {
namespace hardware {
namespace tests {
namespace msgq {
namespace V1_0 {

struct BnHwBenchmarkMsgQ : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwBenchmarkMsgQ(const ::android::sp<IBenchmarkMsgQ> &_hidl_impl);
    explicit BnHwBenchmarkMsgQ(const ::android::sp<IBenchmarkMsgQ> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwBenchmarkMsgQ();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IBenchmarkMsgQ Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IBenchmarkMsgQ> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ follow.
    static ::android::status_t _hidl_configureClientInboxSyncReadWrite(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_configureClientOutboxSyncReadWrite(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_requestWrite(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_requestRead(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_benchmarkPingPong(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_benchmarkServiceWriteClientRead(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_sendTimeData(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IBenchmarkMsgQ> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace msgq
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_BNHWBENCHMARKMSGQ_H
