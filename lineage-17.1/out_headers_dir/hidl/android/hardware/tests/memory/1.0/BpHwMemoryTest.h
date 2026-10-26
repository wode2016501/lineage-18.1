#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V1_0_BPHWMEMORYTEST_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V1_0_BPHWMEMORYTEST_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/memory/1.0/IHwMemoryTest.h>

namespace android {
namespace hardware {
namespace tests {
namespace memory {
namespace V1_0 {

struct BpHwMemoryTest : public ::android::hardware::BpInterface<IMemoryTest>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwMemoryTest(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IMemoryTest Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::memory::V1_0::IMemoryTest follow.
    static ::android::hardware::Return<void>  _hidl_haveSomeMemory(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_memory& mem, haveSomeMemory_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_fillMemory(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_memory& memory_in, uint8_t filler);
    static ::android::hardware::Return<void>  _hidl_haveSomeMemoryBlock(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hidl::memory::block::V1_0::MemoryBlock& blk, haveSomeMemoryBlock_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_set(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_memory& mem);
    static ::android::hardware::Return<::android::sp<::android::hidl::memory::token::V1_0::IMemoryToken>>  _hidl_get(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::android::hardware::tests::memory::V1_0::IMemoryTest follow.
    ::android::hardware::Return<void> haveSomeMemory(const ::android::hardware::hidl_memory& mem, haveSomeMemory_cb _hidl_cb) override;
    ::android::hardware::Return<void> fillMemory(const ::android::hardware::hidl_memory& memory_in, uint8_t filler) override;
    ::android::hardware::Return<void> haveSomeMemoryBlock(const ::android::hidl::memory::block::V1_0::MemoryBlock& blk, haveSomeMemoryBlock_cb _hidl_cb) override;
    ::android::hardware::Return<void> set(const ::android::hardware::hidl_memory& mem) override;
    ::android::hardware::Return<::android::sp<::android::hidl::memory::token::V1_0::IMemoryToken>> get() override;

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
}  // namespace memory
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V1_0_BPHWMEMORYTEST_H
