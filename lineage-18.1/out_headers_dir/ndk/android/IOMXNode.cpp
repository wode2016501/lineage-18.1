#include <android/binder_parcel_utils.h>
#include <aidl/android/BpOMXNode.h>
#include <aidl/android/BnOMXNode.h>
#include <aidl/android/IOMXNode.h>

namespace aidl {
namespace android {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  (void)_aidl_binder;
  (void)_aidl_code;
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IOMXNode::descriptor, _aidl_onTransact);

BpOMXNode::BpOMXNode(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpOMXNode::~BpOMXNode() {}

// Source for BnOMXNode
BnOMXNode::BnOMXNode() {}
BnOMXNode::~BnOMXNode() {}
::ndk::SpAIBinder BnOMXNode::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IOMXNode
const char* IOMXNode::descriptor = "android.IOMXNode";
IOMXNode::IOMXNode() {}
IOMXNode::~IOMXNode() {}


std::shared_ptr<IOMXNode> IOMXNode::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IOMXNode>(interface);
  }
  return ::ndk::SharedRefBase::make<BpOMXNode>(binder);
}

binder_status_t IOMXNode::writeToParcel(AParcel* parcel, const std::shared_ptr<IOMXNode>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IOMXNode::readFromParcel(const AParcel* parcel, std::shared_ptr<IOMXNode>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IOMXNode::fromBinder(binder);
  return STATUS_OK;
}
bool IOMXNode::setDefaultImpl(std::shared_ptr<IOMXNode> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IOMXNode::default_impl);
  if (impl) {
    IOMXNode::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IOMXNode>& IOMXNode::getDefaultImpl() {
  return IOMXNode::default_impl;
}
std::shared_ptr<IOMXNode> IOMXNode::default_impl = nullptr;
::ndk::SpAIBinder IOMXNodeDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IOMXNodeDefault::isRemote() {
  return false;
}
}  // namespace android
}  // namespace aidl
