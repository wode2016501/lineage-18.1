#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_TRIE_V1_0_BPHWTRIE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_TRIE_V1_0_BPHWTRIE_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/trie/1.0/IHwTrie.h>

namespace android {
namespace hardware {
namespace tests {
namespace trie {
namespace V1_0 {

struct BpHwTrie : public ::android::hardware::BpInterface<ITrie>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwTrie(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef ITrie Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::trie::V1_0::ITrie follow.
    static ::android::hardware::Return<void>  _hidl_newTrie(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, newTrie_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_addStrings(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::trie::V1_0::TrieNode& trie, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& strings, addStrings_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_containsStrings(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::trie::V1_0::TrieNode& trie, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& strings, containsStrings_cb _hidl_cb);

    // Methods from ::android::hardware::tests::trie::V1_0::ITrie follow.
    ::android::hardware::Return<void> newTrie(newTrie_cb _hidl_cb) override;
    ::android::hardware::Return<void> addStrings(const ::android::hardware::tests::trie::V1_0::TrieNode& trie, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& strings, addStrings_cb _hidl_cb) override;
    ::android::hardware::Return<void> containsStrings(const ::android::hardware::tests::trie::V1_0::TrieNode& trie, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& strings, containsStrings_cb _hidl_cb) override;

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
}  // namespace trie
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_TRIE_V1_0_BPHWTRIE_H
