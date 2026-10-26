#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_BPHWGRAPH_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_BPHWGRAPH_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/tests/pointer/1.0/IHwGraph.h>

namespace android {
namespace hardware {
namespace tests {
namespace pointer {
namespace V1_0 {

struct BpHwGraph : public ::android::hardware::BpInterface<IGraph>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwGraph(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    /**
     * The pure class is what this class wraps.
     */
    typedef IGraph Pure;

    /**
     * Type tag for use in template logic that indicates this is a 'proxy' class.
     */
    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::tests::pointer::V1_0::IGraph follow.
    static ::android::hardware::Return<void>  _hidl_passANode(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::pointer::V1_0::IGraph::Node& n);
    static ::android::hardware::Return<void>  _hidl_passAGraph(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::pointer::V1_0::IGraph::Graph& g);
    static ::android::hardware::Return<void>  _hidl_passTwoGraphs(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::pointer::V1_0::IGraph::Graph const* g1, ::android::hardware::tests::pointer::V1_0::IGraph::Graph const* g2);
    static ::android::hardware::Return<void>  _hidl_giveAGraph(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, giveAGraph_cb _hidl_cb);
    static ::android::hardware::Return<void>  _hidl_passAGamma(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::tests::pointer::V1_0::IGraph::Gamma& c);
    static ::android::hardware::Return<void>  _hidl_passASimpleRef(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::pointer::V1_0::IGraph::Alpha const* a);
    static ::android::hardware::Return<void>  _hidl_passASimpleRefS(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::tests::pointer::V1_0::IGraph::Theta const* s);
    static ::android::hardware::Return<void>  _hidl_giveASimpleRef(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, giveASimpleRef_cb _hidl_cb);
    static ::android::hardware::Return<int32_t>  _hidl_getErrors(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::android::hardware::tests::pointer::V1_0::IGraph follow.
    ::android::hardware::Return<void> passANode(const ::android::hardware::tests::pointer::V1_0::IGraph::Node& n) override;
    ::android::hardware::Return<void> passAGraph(const ::android::hardware::tests::pointer::V1_0::IGraph::Graph& g) override;
    ::android::hardware::Return<void> passTwoGraphs(::android::hardware::tests::pointer::V1_0::IGraph::Graph const* g1, ::android::hardware::tests::pointer::V1_0::IGraph::Graph const* g2) override;
    ::android::hardware::Return<void> giveAGraph(giveAGraph_cb _hidl_cb) override;
    ::android::hardware::Return<void> passAGamma(const ::android::hardware::tests::pointer::V1_0::IGraph::Gamma& c) override;
    ::android::hardware::Return<void> passASimpleRef(::android::hardware::tests::pointer::V1_0::IGraph::Alpha const* a) override;
    ::android::hardware::Return<void> passASimpleRefS(::android::hardware::tests::pointer::V1_0::IGraph::Theta const* s) override;
    ::android::hardware::Return<void> giveASimpleRef(giveASimpleRef_cb _hidl_cb) override;
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

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_BPHWGRAPH_H
