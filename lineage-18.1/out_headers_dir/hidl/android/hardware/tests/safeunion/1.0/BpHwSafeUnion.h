#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_V1_0_BPHWSAFEUNION_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_V1_0_BPHWSAFEUNION_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/safeunion/1.0/IHwSafeUnion.h>

namespace android {
namespace hardware {
namespace tests {
namespace safeunion {
namespace V1_0 {

struct BpHwSafeUnion : public ::android::hardware::BpInterface<ISafeUnion>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwSafeUnion(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef ISafeUnion Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::safeunion::V1_0::ISafeUnion follow.
    static ::android::hardware::Return<void>  _hidl_newLargeSafeUnion(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, newLargeSafeUnion_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setA(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, int8_t a, setA_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setB(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, uint16_t b, setB_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setC(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, int32_t c, setC_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setD(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, uint64_t d, setD_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setE(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_array<int8_t, 13>& e, setE_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setF(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_array<int64_t, 5>& f, setF_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setG(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_string& g, setG_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setH(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_vec<bool>& h, setH_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setI(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_vec<uint64_t>& i, setI_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setJ(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& j, setJ_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setK(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& k, setK_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setL(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& l, setL_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setM(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField m, setM_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setN(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, ::android::hardware::hidl_bitfield<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField> m, setN_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_newInterfaceTypeSafeUnion(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, newInterfaceTypeSafeUnion_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setInterfaceA(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, uint32_t a, setInterfaceA_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setInterfaceB(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_array<int8_t, 7>& b, setInterfaceB_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setInterfaceC(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::sp<::android::hardware::tests::safeunion::V1_0::IOtherInterface>& c, setInterfaceC_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setInterfaceD(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_string& d, setInterfaceD_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setInterfaceE(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& e, setInterfaceE_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setInterfaceF(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_handle& f, setInterfaceF_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setInterfaceG(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& g, setInterfaceG_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_newHandleTypeSafeUnion(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, newHandleTypeSafeUnion_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setHandleA(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion, const ::android::hardware::hidl_handle& a, setHandleA_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setHandleB(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion, const ::android::hardware::hidl_array<::android::hardware::hidl_handle, 5>& b, setHandleB_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_setHandleC(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& c, setHandleC_cb _hidl_cb);

    // Methods from ::android::hardware::tests::safeunion::V1_0::ISafeUnion follow.
    ::android::hardware::Return<void> newLargeSafeUnion(newLargeSafeUnion_cb _hidl_cb) override;
    ::android::hardware::Return<void> setA(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, int8_t a, setA_cb _hidl_cb) override;
    ::android::hardware::Return<void> setB(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, uint16_t b, setB_cb _hidl_cb) override;
    ::android::hardware::Return<void> setC(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, int32_t c, setC_cb _hidl_cb) override;
    ::android::hardware::Return<void> setD(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, uint64_t d, setD_cb _hidl_cb) override;
    ::android::hardware::Return<void> setE(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_array<int8_t, 13>& e, setE_cb _hidl_cb) override;
    ::android::hardware::Return<void> setF(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_array<int64_t, 5>& f, setF_cb _hidl_cb) override;
    ::android::hardware::Return<void> setG(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_string& g, setG_cb _hidl_cb) override;
    ::android::hardware::Return<void> setH(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_vec<bool>& h, setH_cb _hidl_cb) override;
    ::android::hardware::Return<void> setI(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_vec<uint64_t>& i, setI_cb _hidl_cb) override;
    ::android::hardware::Return<void> setJ(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& j, setJ_cb _hidl_cb) override;
    ::android::hardware::Return<void> setK(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& k, setK_cb _hidl_cb) override;
    ::android::hardware::Return<void> setL(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& l, setL_cb _hidl_cb) override;
    ::android::hardware::Return<void> setM(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField m, setM_cb _hidl_cb) override;
    ::android::hardware::Return<void> setN(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, ::android::hardware::hidl_bitfield<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField> m, setN_cb _hidl_cb) override;
    ::android::hardware::Return<void> newInterfaceTypeSafeUnion(newInterfaceTypeSafeUnion_cb _hidl_cb) override;
    ::android::hardware::Return<void> setInterfaceA(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, uint32_t a, setInterfaceA_cb _hidl_cb) override;
    ::android::hardware::Return<void> setInterfaceB(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_array<int8_t, 7>& b, setInterfaceB_cb _hidl_cb) override;
    ::android::hardware::Return<void> setInterfaceC(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::sp<::android::hardware::tests::safeunion::V1_0::IOtherInterface>& c, setInterfaceC_cb _hidl_cb) override;
    ::android::hardware::Return<void> setInterfaceD(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_string& d, setInterfaceD_cb _hidl_cb) override;
    ::android::hardware::Return<void> setInterfaceE(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& e, setInterfaceE_cb _hidl_cb) override;
    ::android::hardware::Return<void> setInterfaceF(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_handle& f, setInterfaceF_cb _hidl_cb) override;
    ::android::hardware::Return<void> setInterfaceG(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& g, setInterfaceG_cb _hidl_cb) override;
    ::android::hardware::Return<void> newHandleTypeSafeUnion(newHandleTypeSafeUnion_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHandleA(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion, const ::android::hardware::hidl_handle& a, setHandleA_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHandleB(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion, const ::android::hardware::hidl_array<::android::hardware::hidl_handle, 5>& b, setHandleB_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHandleC(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& c, setHandleC_cb _hidl_cb) override;

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
}  // namespace safeunion
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_V1_0_BPHWSAFEUNION_H
