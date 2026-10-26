#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MULTITHREAD_V1_0_BNHWMULTITHREAD_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MULTITHREAD_V1_0_BNHWMULTITHREAD_H

#include <android/hardware/tests/multithread/1.0/IHwMultithread.h>

namespace android {
namespace hardware {
namespace tests {
namespace multithread {
namespace V1_0 {

struct BnHwMultithread : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwMultithread(const ::android::sp<IMultithread> &_hidl_impl);
    explicit BnHwMultithread(const ::android::sp<IMultithread> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwMultithread();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IMultithread Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IMultithread> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::tests::multithread::V1_0::IMultithread follow.
    static ::android::status_t _hidl_setNumThreads(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_runNewThread(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::tests::multithread::V1_0::IMultithread follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IMultithread> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace multithread
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MULTITHREAD_V1_0_BNHWMULTITHREAD_H
