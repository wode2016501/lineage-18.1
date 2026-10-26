#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IHWGRAPH_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IHWGRAPH_H

#include <android/hardware/tests/pointer/1.0/IGraph.h>

#include <android/hidl/base/1.0/BnHwBase.h>
#include <android/hidl/base/1.0/BpHwBase.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {
namespace tests {
namespace pointer {
namespace V1_0 {
::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IGraph::Edge *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IGraph::Edge &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::pointer::V1_0::IGraph::Graph &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::pointer::V1_0::IGraph::Graph &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IGraph::Graph *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IGraph::Graph &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IGraph::Alpha *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IGraph::Alpha &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IGraph::Beta *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IGraph::Beta &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IGraph::Gamma *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IGraph::Gamma &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

}  // namespace V1_0
}  // namespace pointer
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IHWGRAPH_H
