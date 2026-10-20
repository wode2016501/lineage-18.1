#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V1_0_BNHWMEMORYTEST_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V1_0_BNHWMEMORYTEST_H

#include <android/hardware/tests/memory/1.0/IHwMemoryTest.h>

namespace android {
namespace hardware {
namespace tests {
namespace memory {
namespace V1_0 {

struct BnHwMemoryTest : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwMemoryTest(const ::android::sp<IMemoryTest> &_hidl_impl);
    explicit BnHwMemoryTest(const ::android::sp<IMemoryTest> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwMemoryTest();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    /**
     * The pure class is what this class wraps.
     */
    typedef IMemoryTest Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'native' class.
     */
    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IMemoryTest> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::tests::memory::V1_0::IMemoryTest follow.
    static ::android::status_t _hidl_haveSomeMemory(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_fillMemory(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_haveSomeMemoryBlock(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_set(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);


    static ::android::status_t _hidl_get(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::tests::memory::V1_0::IMemoryTest follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IMemoryTest> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace memory
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V1_0_BNHWMEMORYTEST_H
