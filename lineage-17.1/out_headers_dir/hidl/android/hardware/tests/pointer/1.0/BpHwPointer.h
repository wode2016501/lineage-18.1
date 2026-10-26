#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_BPHWPOINTER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_BPHWPOINTER_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/pointer/1.0/IHwPointer.h>

namespace android {
namespace hardware {
namespace tests {
namespace pointer {
namespace V1_0 {

struct BpHwPointer : public ::android::hardware::BpInterface<IPointer>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwPointer(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IPointer Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::pointer::V1_0::IPointer follow.
    static ::android::hardware::Return<void>  _hidl_foo1(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, ::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr);
    static ::android::hardware::Return<void>  _hidl_foo2(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a);
    static ::android::hardware::Return<void>  _hidl_foo3(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a, const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& b);
    static ::android::hardware::Return<void>  _hidl_foo4(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr);
    static ::android::hardware::Return<void>  _hidl_foo5(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a, const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& b);
    static ::android::hardware::Return<void>  _hidl_foo6(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::pointer::V1_0::IPointer::Ada const* a_ptr);
    static ::android::hardware::Return<void>  _hidl_foo7(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::pointer::V1_0::IPointer::Ada const* a_ptr, ::android::hardware::tests::pointer::V1_0::IPointer::Bob const* b_ptr);
    static ::android::hardware::Return<void>  _hidl_foo8(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::pointer::V1_0::IPointer::Dom& d);
    static ::android::hardware::Return<void>  _hidl_foo9(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::hidl_string const* str_ref);
    static ::android::hardware::Return<void>  _hidl_foo10(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*>& s_ptr_vec);
    static ::android::hardware::Return<void>  _hidl_foo11(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam> const* s_vec_ptr);
    static ::android::hardware::Return<void>  _hidl_foo12(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Sam, 5> const* s_array_ref);
    static ::android::hardware::Return<void>  _hidl_foo13(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*, 5>& s_ref_array);
    static ::android::hardware::Return<void>  _hidl_foo14(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::pointer::V1_0::IPointer::Sam const* const* const* s_3ptr);
    static ::android::hardware::Return<void>  _hidl_foo15(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t const* const* const* i_3ptr);
    static ::android::hardware::Return<void>  _hidl_foo16(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::pointer::V1_0::IPointer::Ptr& p);
    static ::android::hardware::Return<void>  _hidl_foo17(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::pointer::V1_0::IPointer::Ptr const* p);
    static ::android::hardware::Return<void>  _hidl_foo18(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::hidl_string const* str_ref, ::android::hardware::hidl_string const* str_ref2, const ::android::hardware::hidl_string& str);
    static ::android::hardware::Return<void>  _hidl_foo19(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada> const* a_vec_ref, const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada>& a_vec, ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada> const* a_vec_ref2);
    static ::android::hardware::Return<void>  _hidl_foo20(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*>& s_ptr_vec);
    static ::android::hardware::Return<void>  _hidl_foo21(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada, 1, 2, 3> const* a_array_ptr);
    static ::android::hardware::Return<void>  _hidl_foo22(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada const*, 1, 2, 3>& a_ptr_array);
    static ::android::hardware::Return<void>  _hidl_bar1(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar1_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar2(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar2_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar3(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar3_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar4(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar4_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar5(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar5_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar6(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar6_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar7(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar7_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar8(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar8_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar9(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar9_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar10(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar10_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar11(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar11_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar12(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar12_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar13(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar13_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar14(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar14_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar15(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar15_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar16(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar16_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar17(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar17_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar18(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar18_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar19(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar19_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar20(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar20_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar21(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar21_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_bar22(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bar22_cb _hidl_cb);
    static ::android::hardware::Return<int32_t>  _hidl_getErrors(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::android::hardware::tests::pointer::V1_0::IPointer follow.
    ::android::hardware::Return<void> foo1(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, ::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr) override;
    ::android::hardware::Return<void> foo2(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a) override;
    ::android::hardware::Return<void> foo3(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a, const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& b) override;
    ::android::hardware::Return<void> foo4(::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr) override;
    ::android::hardware::Return<void> foo5(const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a, const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& b) override;
    ::android::hardware::Return<void> foo6(::android::hardware::tests::pointer::V1_0::IPointer::Ada const* a_ptr) override;
    ::android::hardware::Return<void> foo7(::android::hardware::tests::pointer::V1_0::IPointer::Ada const* a_ptr, ::android::hardware::tests::pointer::V1_0::IPointer::Bob const* b_ptr) override;
    ::android::hardware::Return<void> foo8(const ::android::hardware::tests::pointer::V1_0::IPointer::Dom& d) override;
    ::android::hardware::Return<void> foo9(::android::hardware::hidl_string const* str_ref) override;
    ::android::hardware::Return<void> foo10(const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*>& s_ptr_vec) override;
    ::android::hardware::Return<void> foo11(::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam> const* s_vec_ptr) override;
    ::android::hardware::Return<void> foo12(::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Sam, 5> const* s_array_ref) override;
    ::android::hardware::Return<void> foo13(const ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*, 5>& s_ref_array) override;
    ::android::hardware::Return<void> foo14(::android::hardware::tests::pointer::V1_0::IPointer::Sam const* const* const* s_3ptr) override;
    ::android::hardware::Return<void> foo15(int32_t const* const* const* i_3ptr) override;
    ::android::hardware::Return<void> foo16(const ::android::hardware::tests::pointer::V1_0::IPointer::Ptr& p) override;
    ::android::hardware::Return<void> foo17(::android::hardware::tests::pointer::V1_0::IPointer::Ptr const* p) override;
    ::android::hardware::Return<void> foo18(::android::hardware::hidl_string const* str_ref, ::android::hardware::hidl_string const* str_ref2, const ::android::hardware::hidl_string& str) override;
    ::android::hardware::Return<void> foo19(::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada> const* a_vec_ref, const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada>& a_vec, ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada> const* a_vec_ref2) override;
    ::android::hardware::Return<void> foo20(const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*>& s_ptr_vec) override;
    ::android::hardware::Return<void> foo21(::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada, 1, 2, 3> const* a_array_ptr) override;
    ::android::hardware::Return<void> foo22(const ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada const*, 1, 2, 3>& a_ptr_array) override;
    ::android::hardware::Return<void> bar1(bar1_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar2(bar2_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar3(bar3_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar4(bar4_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar5(bar5_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar6(bar6_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar7(bar7_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar8(bar8_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar9(bar9_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar10(bar10_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar11(bar11_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar12(bar12_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar13(bar13_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar14(bar14_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar15(bar15_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar16(bar16_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar17(bar17_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar18(bar18_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar19(bar19_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar20(bar20_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar21(bar21_cb _hidl_cb) override;
    ::android::hardware::Return<void> bar22(bar22_cb _hidl_cb) override;
    ::android::hardware::Return<int32_t> getErrors() override;

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
}  // namespace pointer
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_BPHWPOINTER_H
