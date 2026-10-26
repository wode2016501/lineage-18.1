#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_V1_0_ISAFEUNION_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_V1_0_ISAFEUNION_H

#include <android/hardware/tests/safeunion/1.0/IOtherInterface.h>
#include <android/hidl/base/1.0/IBase.h>
#include <android/hidl/safe_union/1.0/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tests {
namespace safeunion {
namespace V1_0 {

struct ISafeUnion : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.safeunion@1.0::ISafeUnion"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class BitField : uint8_t;
    struct J;
    struct SmallSafeUnion;
    struct LargeSafeUnion;
    struct InterfaceTypeSafeUnion;
    struct HandleTypeSafeUnion;

    enum class BitField : uint8_t {
        V0 = 1 /* (1 << 0) */,
        V1 = 2 /* (1 << 1) */,
        V2 = 4 /* (1 << 2) */,
        V3 = 8 /* (1 << 3) */,
    };

    struct J final {
        ::android::hardware::hidl_vec<uint32_t> j1 __attribute__ ((aligned(8)));
        ::android::hardware::hidl_array<uint8_t, 65> j2 __attribute__ ((aligned(1)));
        ::android::hardware::hidl_string j3 __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::J, j1) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::J, j2) == 16, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::J, j3) == 88, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::J) == 104, "wrong size");
    static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::J) == 8, "wrong alignment");

    struct SmallSafeUnion final {
        enum class hidl_discriminator : uint8_t {
            noinit = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            a = 1,  // uint8_t
        };

        SmallSafeUnion();
        ~SmallSafeUnion();
        SmallSafeUnion(SmallSafeUnion&&);
        SmallSafeUnion(const SmallSafeUnion&);
        SmallSafeUnion& operator=(SmallSafeUnion&&);
        SmallSafeUnion& operator=(const SmallSafeUnion&);

        void noinit(const ::android::hidl::safe_union::V1_0::Monostate&);
        void noinit(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& noinit();
        const ::android::hidl::safe_union::V1_0::Monostate& noinit() const;

        void a(uint8_t);
        uint8_t& a();
        uint8_t a() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate noinit __attribute__ ((aligned(1)));
            uint8_t a __attribute__ ((aligned(1)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion::hidl_union) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion::hidl_union) == 1, "wrong alignment");
        static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion) == 2, "wrong size");
    static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion) == 1, "wrong alignment");

    struct LargeSafeUnion final {
        // Forward declaration for forward reference support:
        struct K;

        struct K final {
            uint8_t k1 __attribute__ ((aligned(1)));
            uint64_t k2 __attribute__ ((aligned(8)));
        };

        static_assert(offsetof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K, k1) == 0, "wrong offset");
        static_assert(offsetof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K, k2) == 8, "wrong offset");
        static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K) == 16, "wrong size");
        static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K) == 8, "wrong alignment");

        enum class hidl_discriminator : uint8_t {
            noinit = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            a = 1,  // int8_t
            b = 2,  // uint16_t
            c = 3,  // int32_t
            d = 4,  // uint64_t
            e = 5,  // ::android::hardware::hidl_array<int8_t, 13>
            f = 6,  // ::android::hardware::hidl_array<int64_t, 5>
            g = 7,  // ::android::hardware::hidl_string
            h = 8,  // ::android::hardware::hidl_vec<bool>
            i = 9,  // ::android::hardware::hidl_vec<uint64_t>
            j = 10,  // ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J
            k = 11,  // ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K
            l = 12,  // ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion
            m = 13,  // ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField
            n = 14,  // ::android::hardware::hidl_bitfield<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField>
        };

        LargeSafeUnion();
        ~LargeSafeUnion();
        LargeSafeUnion(LargeSafeUnion&&);
        LargeSafeUnion(const LargeSafeUnion&);
        LargeSafeUnion& operator=(LargeSafeUnion&&);
        LargeSafeUnion& operator=(const LargeSafeUnion&);

        void noinit(const ::android::hidl::safe_union::V1_0::Monostate&);
        void noinit(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& noinit();
        const ::android::hidl::safe_union::V1_0::Monostate& noinit() const;

        void a(int8_t);
        int8_t& a();
        int8_t a() const;

        void b(uint16_t);
        uint16_t& b();
        uint16_t b() const;

        void c(int32_t);
        int32_t& c();
        int32_t c() const;

        void d(uint64_t);
        uint64_t& d();
        uint64_t d() const;

        void e(const ::android::hardware::hidl_array<int8_t, 13>&);
        void e(::android::hardware::hidl_array<int8_t, 13>&&);
        ::android::hardware::hidl_array<int8_t, 13>& e();
        const ::android::hardware::hidl_array<int8_t, 13>& e() const;

        void f(const ::android::hardware::hidl_array<int64_t, 5>&);
        void f(::android::hardware::hidl_array<int64_t, 5>&&);
        ::android::hardware::hidl_array<int64_t, 5>& f();
        const ::android::hardware::hidl_array<int64_t, 5>& f() const;

        void g(const ::android::hardware::hidl_string&);
        void g(::android::hardware::hidl_string&&);
        ::android::hardware::hidl_string& g();
        const ::android::hardware::hidl_string& g() const;

        void h(const ::android::hardware::hidl_vec<bool>&);
        void h(::android::hardware::hidl_vec<bool>&&);
        ::android::hardware::hidl_vec<bool>& h();
        const ::android::hardware::hidl_vec<bool>& h() const;

        void i(const ::android::hardware::hidl_vec<uint64_t>&);
        void i(::android::hardware::hidl_vec<uint64_t>&&);
        ::android::hardware::hidl_vec<uint64_t>& i();
        const ::android::hardware::hidl_vec<uint64_t>& i() const;

        void j(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J&);
        void j(::android::hardware::tests::safeunion::V1_0::ISafeUnion::J&&);
        ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& j();
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& j() const;

        void k(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K&);
        void k(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K&&);
        ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& k();
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& k() const;

        void l(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion&);
        void l(::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion&&);
        ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& l();
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& l() const;

        void m(::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField);
        ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField& m();
        ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField m() const;

        void n(::android::hardware::hidl_bitfield<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField>);
        ::android::hardware::hidl_bitfield<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField>& n();
        ::android::hardware::hidl_bitfield<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField> n() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate noinit __attribute__ ((aligned(1)));
            int8_t a __attribute__ ((aligned(1)));
            uint16_t b __attribute__ ((aligned(2)));
            int32_t c __attribute__ ((aligned(4)));
            uint64_t d __attribute__ ((aligned(8)));
            ::android::hardware::hidl_array<int8_t, 13> e __attribute__ ((aligned(1)));
            ::android::hardware::hidl_array<int64_t, 5> f __attribute__ ((aligned(8)));
            ::android::hardware::hidl_string g __attribute__ ((aligned(8)));
            ::android::hardware::hidl_vec<bool> h __attribute__ ((aligned(8)));
            ::android::hardware::hidl_vec<uint64_t> i __attribute__ ((aligned(8)));
            ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J j __attribute__ ((aligned(8)));
            ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K k __attribute__ ((aligned(8)));
            ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion l __attribute__ ((aligned(1)));
            ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField m __attribute__ ((aligned(1)));
            ::android::hardware::hidl_bitfield<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField> n __attribute__ ((aligned(1)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_union) == 104, "wrong size");
        static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion) == 112, "wrong size");
    static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion) == 8, "wrong alignment");

    struct InterfaceTypeSafeUnion final {
        enum class hidl_discriminator : uint8_t {
            noinit = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            a = 1,  // uint32_t
            b = 2,  // ::android::hardware::hidl_array<int8_t, 7>
            c = 3,  // ::android::sp<::android::hardware::tests::safeunion::V1_0::IOtherInterface>
            d = 4,  // ::android::hardware::hidl_string
            e = 5,  // ::android::hardware::hidl_vec<::android::hardware::hidl_string>
            f = 6,  // ::android::hardware::hidl_handle
            g = 7,  // ::android::hardware::hidl_vec<::android::hardware::hidl_handle>
        };

        InterfaceTypeSafeUnion();
        ~InterfaceTypeSafeUnion();
        InterfaceTypeSafeUnion(InterfaceTypeSafeUnion&&);
        InterfaceTypeSafeUnion(const InterfaceTypeSafeUnion&);
        InterfaceTypeSafeUnion& operator=(InterfaceTypeSafeUnion&&);
        InterfaceTypeSafeUnion& operator=(const InterfaceTypeSafeUnion&);

        void noinit(const ::android::hidl::safe_union::V1_0::Monostate&);
        void noinit(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& noinit();
        const ::android::hidl::safe_union::V1_0::Monostate& noinit() const;

        void a(uint32_t);
        uint32_t& a();
        uint32_t a() const;

        void b(const ::android::hardware::hidl_array<int8_t, 7>&);
        void b(::android::hardware::hidl_array<int8_t, 7>&&);
        ::android::hardware::hidl_array<int8_t, 7>& b();
        const ::android::hardware::hidl_array<int8_t, 7>& b() const;

        void c(const ::android::sp<::android::hardware::tests::safeunion::V1_0::IOtherInterface>&);
        void c(::android::sp<::android::hardware::tests::safeunion::V1_0::IOtherInterface>&&);
        ::android::sp<::android::hardware::tests::safeunion::V1_0::IOtherInterface>& c();
        const ::android::sp<::android::hardware::tests::safeunion::V1_0::IOtherInterface>& c() const;

        void d(const ::android::hardware::hidl_string&);
        void d(::android::hardware::hidl_string&&);
        ::android::hardware::hidl_string& d();
        const ::android::hardware::hidl_string& d() const;

        void e(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>&);
        void e(::android::hardware::hidl_vec<::android::hardware::hidl_string>&&);
        ::android::hardware::hidl_vec<::android::hardware::hidl_string>& e();
        const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& e() const;

        void f(const ::android::hardware::hidl_handle&);
        void f(::android::hardware::hidl_handle&&);
        ::android::hardware::hidl_handle& f();
        const ::android::hardware::hidl_handle& f() const;

        void g(const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>&);
        void g(::android::hardware::hidl_vec<::android::hardware::hidl_handle>&&);
        ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& g();
        const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& g() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate noinit __attribute__ ((aligned(1)));
            uint32_t a __attribute__ ((aligned(4)));
            ::android::hardware::hidl_array<int8_t, 7> b __attribute__ ((aligned(1)));
            ::android::sp<::android::hardware::tests::safeunion::V1_0::IOtherInterface> c __attribute__ ((aligned(8)));
            ::android::hardware::hidl_string d __attribute__ ((aligned(8)));
            ::android::hardware::hidl_vec<::android::hardware::hidl_string> e __attribute__ ((aligned(8)));
            ::android::hardware::hidl_handle f __attribute__ ((aligned(8)));
            ::android::hardware::hidl_vec<::android::hardware::hidl_handle> g __attribute__ ((aligned(8)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_union) == 16, "wrong size");
        static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion) == 8, "wrong alignment");

    struct HandleTypeSafeUnion final {
        enum class hidl_discriminator : uint8_t {
            noinit = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            a = 1,  // ::android::hardware::hidl_handle
            b = 2,  // ::android::hardware::hidl_array<::android::hardware::hidl_handle, 5>
            c = 3,  // ::android::hardware::hidl_vec<::android::hardware::hidl_handle>
        };

        HandleTypeSafeUnion();
        ~HandleTypeSafeUnion();
        HandleTypeSafeUnion(HandleTypeSafeUnion&&);
        HandleTypeSafeUnion(const HandleTypeSafeUnion&);
        HandleTypeSafeUnion& operator=(HandleTypeSafeUnion&&);
        HandleTypeSafeUnion& operator=(const HandleTypeSafeUnion&);

        void noinit(const ::android::hidl::safe_union::V1_0::Monostate&);
        void noinit(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& noinit();
        const ::android::hidl::safe_union::V1_0::Monostate& noinit() const;

        void a(const ::android::hardware::hidl_handle&);
        void a(::android::hardware::hidl_handle&&);
        ::android::hardware::hidl_handle& a();
        const ::android::hardware::hidl_handle& a() const;

        void b(const ::android::hardware::hidl_array<::android::hardware::hidl_handle, 5>&);
        void b(::android::hardware::hidl_array<::android::hardware::hidl_handle, 5>&&);
        ::android::hardware::hidl_array<::android::hardware::hidl_handle, 5>& b();
        const ::android::hardware::hidl_array<::android::hardware::hidl_handle, 5>& b() const;

        void c(const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>&);
        void c(::android::hardware::hidl_vec<::android::hardware::hidl_handle>&&);
        ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& c();
        const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& c() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate noinit __attribute__ ((aligned(1)));
            ::android::hardware::hidl_handle a __attribute__ ((aligned(8)));
            ::android::hardware::hidl_array<::android::hardware::hidl_handle, 5> b __attribute__ ((aligned(8)));
            ::android::hardware::hidl_vec<::android::hardware::hidl_handle> c __attribute__ ((aligned(8)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion::hidl_union) == 80, "wrong size");
        static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion) == 88, "wrong size");
    static_assert(__alignof(::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for newLargeSafeUnion
     */
    using newLargeSafeUnion_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> newLargeSafeUnion(newLargeSafeUnion_cb _hidl_cb) = 0;

    /**
     * Return callback for setA
     */
    using setA_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setA(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, int8_t a, setA_cb _hidl_cb) = 0;

    /**
     * Return callback for setB
     */
    using setB_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setB(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, uint16_t b, setB_cb _hidl_cb) = 0;

    /**
     * Return callback for setC
     */
    using setC_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setC(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, int32_t c, setC_cb _hidl_cb) = 0;

    /**
     * Return callback for setD
     */
    using setD_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setD(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, uint64_t d, setD_cb _hidl_cb) = 0;

    /**
     * Return callback for setE
     */
    using setE_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setE(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_array<int8_t, 13>& e, setE_cb _hidl_cb) = 0;

    /**
     * Return callback for setF
     */
    using setF_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setF(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_array<int64_t, 5>& f, setF_cb _hidl_cb) = 0;

    /**
     * Return callback for setG
     */
    using setG_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setG(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_string& g, setG_cb _hidl_cb) = 0;

    /**
     * Return callback for setH
     */
    using setH_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setH(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_vec<bool>& h, setH_cb _hidl_cb) = 0;

    /**
     * Return callback for setI
     */
    using setI_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setI(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::hidl_vec<uint64_t>& i, setI_cb _hidl_cb) = 0;

    /**
     * Return callback for setJ
     */
    using setJ_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setJ(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& j, setJ_cb _hidl_cb) = 0;

    /**
     * Return callback for setK
     */
    using setK_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setK(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& k, setK_cb _hidl_cb) = 0;

    /**
     * Return callback for setL
     */
    using setL_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setL(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& l, setL_cb _hidl_cb) = 0;

    /**
     * Return callback for setM
     */
    using setM_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setM(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField m, setM_cb _hidl_cb) = 0;

    /**
     * Return callback for setN
     */
    using setN_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setN(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& myUnion, ::android::hardware::hidl_bitfield<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField> m, setN_cb _hidl_cb) = 0;

    /**
     * Return callback for newInterfaceTypeSafeUnion
     */
    using newInterfaceTypeSafeUnion_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> newInterfaceTypeSafeUnion(newInterfaceTypeSafeUnion_cb _hidl_cb) = 0;

    /**
     * Return callback for setInterfaceA
     */
    using setInterfaceA_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setInterfaceA(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, uint32_t a, setInterfaceA_cb _hidl_cb) = 0;

    /**
     * Return callback for setInterfaceB
     */
    using setInterfaceB_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setInterfaceB(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_array<int8_t, 7>& b, setInterfaceB_cb _hidl_cb) = 0;

    /**
     * Return callback for setInterfaceC
     */
    using setInterfaceC_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setInterfaceC(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::sp<::android::hardware::tests::safeunion::V1_0::IOtherInterface>& c, setInterfaceC_cb _hidl_cb) = 0;

    /**
     * Return callback for setInterfaceD
     */
    using setInterfaceD_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setInterfaceD(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_string& d, setInterfaceD_cb _hidl_cb) = 0;

    /**
     * Return callback for setInterfaceE
     */
    using setInterfaceE_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setInterfaceE(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& e, setInterfaceE_cb _hidl_cb) = 0;

    /**
     * Return callback for setInterfaceF
     */
    using setInterfaceF_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setInterfaceF(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_handle& f, setInterfaceF_cb _hidl_cb) = 0;

    /**
     * Return callback for setInterfaceG
     */
    using setInterfaceG_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setInterfaceG(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& myUnion, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& g, setInterfaceG_cb _hidl_cb) = 0;

    /**
     * Return callback for newHandleTypeSafeUnion
     */
    using newHandleTypeSafeUnion_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> newHandleTypeSafeUnion(newHandleTypeSafeUnion_cb _hidl_cb) = 0;

    /**
     * Return callback for setHandleA
     */
    using setHandleA_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setHandleA(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion, const ::android::hardware::hidl_handle& a, setHandleA_cb _hidl_cb) = 0;

    /**
     * Return callback for setHandleB
     */
    using setHandleB_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setHandleB(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion, const ::android::hardware::hidl_array<::android::hardware::hidl_handle, 5>& b, setHandleB_cb _hidl_cb) = 0;

    /**
     * Return callback for setHandleC
     */
    using setHandleC_cb = std::function<void(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion)>;
    virtual ::android::hardware::Return<void> setHandleC(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& myUnion, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& c, setHandleC_cb _hidl_cb) = 0;

    /**
     * Return callback for interfaceChain
     */
    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    /**
     * Return callback for interfaceDescriptor
     */
    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    /**
     * Return callback for getHashChain
     */
    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> setHALInstrumentation() override;

    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;

    virtual ::android::hardware::Return<void> ping() override;

    /**
     * Return callback for getDebugInfo
     */
    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;

    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    // cast static functions
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::safeunion::V1_0::ISafeUnion>> castFrom(const ::android::sp<::android::hardware::tests::safeunion::V1_0::ISafeUnion>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::safeunion::V1_0::ISafeUnion>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    // helper methods for interactions with the hwservicemanager
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is currently not available or not in the VINTF manifest on a Trebilized
     * device, this will return nullptr. This is useful when you don't want to block
     * during device boot. If getStub is true, this will try to return an unwrapped
     * passthrough implementation in the same process. This is useful when getting an
     * implementation from the same partition/compilation group.
     * 
     * In general, prefer getService(std::string,bool)
     */
    static ::android::sp<ISafeUnion> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISafeUnion> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISafeUnion> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISafeUnion> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISafeUnion> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISafeUnion> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISafeUnion> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISafeUnion> getService(bool getStub) { return getService("default", getStub); }
    /**
     * Registers a service with the service manager. For Trebilized devices, the service
     * must also be in the VINTF manifest.
     */
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    /**
     * Registers for notifications for when a service is registered.
     */
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

//
// type declarations for package
//

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField o);

constexpr uint8_t operator|(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& o);
static inline bool operator==(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& rhs);
static inline bool operator!=(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& rhs);

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& o);
static inline bool operator==(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& rhs);
static inline bool operator!=(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& rhs);

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& o);
static inline bool operator==(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& rhs);
static inline bool operator!=(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& rhs);

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& o);
static inline bool operator==(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& rhs);
static inline bool operator!=(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& rhs);

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& o);
// operator== and operator!= are not generated for InterfaceTypeSafeUnion

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& o);
// operator== and operator!= are not generated for HandleTypeSafeUnion

static inline std::string toString(const ::android::sp<::android::hardware::tests::safeunion::V1_0::ISafeUnion>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V0) == static_cast<uint8_t>(::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V0)) {
        os += (first ? "" : " | ");
        os += "V0";
        first = false;
        flipped |= ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V0;
    }
    if ((o & ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V1) == static_cast<uint8_t>(::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V1)) {
        os += (first ? "" : " | ");
        os += "V1";
        first = false;
        flipped |= ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V1;
    }
    if ((o & ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V2) == static_cast<uint8_t>(::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V2)) {
        os += (first ? "" : " | ");
        os += "V2";
        first = false;
        flipped |= ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V2;
    }
    if ((o & ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V3) == static_cast<uint8_t>(::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V3)) {
        os += (first ? "" : " | ");
        os += "V3";
        first = false;
        flipped |= ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V3;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V0) {
        return "V0";
    }
    if (o == ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V1) {
        return "V1";
    }
    if (o == ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V2) {
        return "V2";
    }
    if (o == ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V3) {
        return "V3";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".j1 = ";
    os += ::android::hardware::toString(o.j1);
    os += ", .j2 = ";
    os += ::android::hardware::toString(o.j2);
    os += ", .j3 = ";
    os += ::android::hardware::toString(o.j3);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& rhs) {
    if (lhs.j1 != rhs.j1) {
        return false;
    }
    if (lhs.j2 != rhs.j2) {
        return false;
    }
    if (lhs.j3 != rhs.j3) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion::hidl_discriminator::noinit: {
            os += ".noinit = ";
            os += toString(o.noinit());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion::hidl_discriminator::a: {
            os += ".a = ";
            os += toString(o.a());
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) o.getDiscriminator()) + ").").c_str());
        }
    }
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion::hidl_discriminator::noinit: {
            return (lhs.noinit() == rhs.noinit());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion::hidl_discriminator::a: {
            return (lhs.a() == rhs.a());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::SmallSafeUnion& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".k1 = ";
    os += ::android::hardware::toString(o.k1);
    os += ", .k2 = ";
    os += ::android::hardware::toString(o.k2);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& rhs) {
    if (lhs.k1 != rhs.k1) {
        return false;
    }
    if (lhs.k2 != rhs.k2) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::K& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::noinit: {
            os += ".noinit = ";
            os += toString(o.noinit());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::a: {
            os += ".a = ";
            os += toString(o.a());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::b: {
            os += ".b = ";
            os += toString(o.b());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::c: {
            os += ".c = ";
            os += toString(o.c());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::d: {
            os += ".d = ";
            os += toString(o.d());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::e: {
            os += ".e = ";
            os += toString(o.e());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::f: {
            os += ".f = ";
            os += toString(o.f());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::g: {
            os += ".g = ";
            os += toString(o.g());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::h: {
            os += ".h = ";
            os += toString(o.h());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::i: {
            os += ".i = ";
            os += toString(o.i());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::j: {
            os += ".j = ";
            os += toString(o.j());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::k: {
            os += ".k = ";
            os += toString(o.k());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::l: {
            os += ".l = ";
            os += toString(o.l());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::m: {
            os += ".m = ";
            os += toString(o.m());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::n: {
            os += ".n = ";
            os += toString(o.n());
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) o.getDiscriminator()) + ").").c_str());
        }
    }
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::noinit: {
            return (lhs.noinit() == rhs.noinit());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::a: {
            return (lhs.a() == rhs.a());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::b: {
            return (lhs.b() == rhs.b());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::c: {
            return (lhs.c() == rhs.c());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::d: {
            return (lhs.d() == rhs.d());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::e: {
            return (lhs.e() == rhs.e());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::f: {
            return (lhs.f() == rhs.f());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::g: {
            return (lhs.g() == rhs.g());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::h: {
            return (lhs.h() == rhs.h());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::i: {
            return (lhs.i() == rhs.i());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::j: {
            return (lhs.j() == rhs.j());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::k: {
            return (lhs.k() == rhs.k());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::l: {
            return (lhs.l() == rhs.l());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::m: {
            return (lhs.m() == rhs.m());
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion::hidl_discriminator::n: {
            return (lhs.n() == rhs.n());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& lhs, const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator::noinit: {
            os += ".noinit = ";
            os += toString(o.noinit());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator::a: {
            os += ".a = ";
            os += toString(o.a());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator::b: {
            os += ".b = ";
            os += toString(o.b());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator::c: {
            os += ".c = ";
            os += toString(o.c());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator::d: {
            os += ".d = ";
            os += toString(o.d());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator::e: {
            os += ".e = ";
            os += toString(o.e());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator::f: {
            os += ".f = ";
            os += toString(o.f());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion::hidl_discriminator::g: {
            os += ".g = ";
            os += toString(o.g());
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) o.getDiscriminator()) + ").").c_str());
        }
    }
    os += "}"; return os;
}

// operator== and operator!= are not generated for InterfaceTypeSafeUnion

static inline std::string toString(const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion::hidl_discriminator::noinit: {
            os += ".noinit = ";
            os += toString(o.noinit());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion::hidl_discriminator::a: {
            os += ".a = ";
            os += toString(o.a());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion::hidl_discriminator::b: {
            os += ".b = ";
            os += toString(o.b());
            break;
        }
        case ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion::hidl_discriminator::c: {
            os += ".c = ";
            os += toString(o.c());
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) o.getDiscriminator()) + ").").c_str());
        }
    }
    os += "}"; return os;
}

// operator== and operator!= are not generated for HandleTypeSafeUnion

static inline std::string toString(const ::android::sp<::android::hardware::tests::safeunion::V1_0::ISafeUnion>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::safeunion::V1_0::ISafeUnion::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace safeunion
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField, 4> hidl_enum_values<::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField> = {
    ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V0,
    ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V1,
    ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V2,
    ::android::hardware::tests::safeunion::V1_0::ISafeUnion::BitField::V3,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_V1_0_ISAFEUNION_H
