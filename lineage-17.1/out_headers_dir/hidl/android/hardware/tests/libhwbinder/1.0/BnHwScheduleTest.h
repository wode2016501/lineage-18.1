#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_LIBHWBINDER_V1_0_BNHWSCHEDULETEST_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_LIBHWBINDER_V1_0_BNHWSCHEDULETEST_H

#include <android/hardware/tests/libhwbinder/1.0/IHwScheduleTest.h>

namespace android {
namespace hardware {
namespace tests {
namespace libhwbinder {
namespace V1_0 {

struct BnHwScheduleTest : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwScheduleTest(const ::android::sp<IScheduleTest> &_hidl_impl);
    explicit BnHwScheduleTest(const ::android::sp<IScheduleTest> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwScheduleTest();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IScheduleTest Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IScheduleTest> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::tests::libhwbinder::V1_0::IScheduleTest follow.
    static ::android::status_t _hidl_send(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::tests::libhwbinder::V1_0::IScheduleTest follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IScheduleTest> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace libhwbinder
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_LIBHWBINDER_V1_0_BNHWSCHEDULETEST_H
