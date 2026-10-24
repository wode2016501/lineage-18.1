#pragma once

#include <binder/IInterface.h>
#include <android/os/IInstalld.h>
#include <android/os/BnInstalld.h>
#include <binder/Delegate.h>


namespace android {
namespace os {
class BnInstalld : public ::android::BnInterface<IInstalld> {
public:
  static constexpr uint32_t TRANSACTION_createUserData = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_destroyUserData = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_createAppData = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_restoreconAppData = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_migrateAppData = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_clearAppData = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_destroyAppData = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_fixupAppData = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_getAppSize = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_getUserSize = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getExternalSize = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_setAppQuota = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_moveCompleteApp = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_dexopt = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_compileLayouts = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_rmdex = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_mergeProfiles = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_dumpProfiles = ::android::IBinder::FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_copySystemProfile = ::android::IBinder::FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_clearAppProfiles = ::android::IBinder::FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_destroyAppProfiles = ::android::IBinder::FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_createProfileSnapshot = ::android::IBinder::FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_destroyProfileSnapshot = ::android::IBinder::FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_idmap = ::android::IBinder::FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_removeIdmap = ::android::IBinder::FIRST_CALL_TRANSACTION + 24;
  static constexpr uint32_t TRANSACTION_rmPackageDir = ::android::IBinder::FIRST_CALL_TRANSACTION + 25;
  static constexpr uint32_t TRANSACTION_freeCache = ::android::IBinder::FIRST_CALL_TRANSACTION + 26;
  static constexpr uint32_t TRANSACTION_linkNativeLibraryDirectory = ::android::IBinder::FIRST_CALL_TRANSACTION + 27;
  static constexpr uint32_t TRANSACTION_createOatDir = ::android::IBinder::FIRST_CALL_TRANSACTION + 28;
  static constexpr uint32_t TRANSACTION_linkFile = ::android::IBinder::FIRST_CALL_TRANSACTION + 29;
  static constexpr uint32_t TRANSACTION_moveAb = ::android::IBinder::FIRST_CALL_TRANSACTION + 30;
  static constexpr uint32_t TRANSACTION_deleteOdex = ::android::IBinder::FIRST_CALL_TRANSACTION + 31;
  static constexpr uint32_t TRANSACTION_installApkVerity = ::android::IBinder::FIRST_CALL_TRANSACTION + 32;
  static constexpr uint32_t TRANSACTION_assertFsverityRootHashMatches = ::android::IBinder::FIRST_CALL_TRANSACTION + 33;
  static constexpr uint32_t TRANSACTION_reconcileSecondaryDexFile = ::android::IBinder::FIRST_CALL_TRANSACTION + 34;
  static constexpr uint32_t TRANSACTION_hashSecondaryDexFile = ::android::IBinder::FIRST_CALL_TRANSACTION + 35;
  static constexpr uint32_t TRANSACTION_invalidateMounts = ::android::IBinder::FIRST_CALL_TRANSACTION + 36;
  static constexpr uint32_t TRANSACTION_isQuotaSupported = ::android::IBinder::FIRST_CALL_TRANSACTION + 37;
  static constexpr uint32_t TRANSACTION_prepareAppProfile = ::android::IBinder::FIRST_CALL_TRANSACTION + 38;
  static constexpr uint32_t TRANSACTION_snapshotAppData = ::android::IBinder::FIRST_CALL_TRANSACTION + 39;
  static constexpr uint32_t TRANSACTION_restoreAppDataSnapshot = ::android::IBinder::FIRST_CALL_TRANSACTION + 40;
  static constexpr uint32_t TRANSACTION_destroyAppDataSnapshot = ::android::IBinder::FIRST_CALL_TRANSACTION + 41;
  static constexpr uint32_t TRANSACTION_migrateLegacyObbData = ::android::IBinder::FIRST_CALL_TRANSACTION + 42;
  explicit BnInstalld();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnInstalld

class IInstalldDelegator : public BnInstalld {
public:
  explicit IInstalldDelegator(const ::android::sp<IInstalld> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IInstalld> getImpl() { return _aidl_delegate; }
  ::android::binder::Status createUserData(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t userSerial, int32_t flags) override {
    return _aidl_delegate->createUserData(uuid, userId, userSerial, flags);
  }
  ::android::binder::Status destroyUserData(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t flags) override {
    return _aidl_delegate->destroyUserData(uuid, userId, flags);
  }
  ::android::binder::Status createAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int32_t appId, const ::std::string& seInfo, int32_t targetSdkVersion, int64_t* _aidl_return) override {
    return _aidl_delegate->createAppData(uuid, packageName, userId, flags, appId, seInfo, targetSdkVersion, _aidl_return);
  }
  ::android::binder::Status restoreconAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int32_t appId, const ::std::string& seInfo) override {
    return _aidl_delegate->restoreconAppData(uuid, packageName, userId, flags, appId, seInfo);
  }
  ::android::binder::Status migrateAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags) override {
    return _aidl_delegate->migrateAppData(uuid, packageName, userId, flags);
  }
  ::android::binder::Status clearAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int64_t ceDataInode) override {
    return _aidl_delegate->clearAppData(uuid, packageName, userId, flags, ceDataInode);
  }
  ::android::binder::Status destroyAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t flags, int64_t ceDataInode) override {
    return _aidl_delegate->destroyAppData(uuid, packageName, userId, flags, ceDataInode);
  }
  ::android::binder::Status fixupAppData(const ::std::optional<::std::string>& uuid, int32_t flags) override {
    return _aidl_delegate->fixupAppData(uuid, flags);
  }
  ::android::binder::Status getAppSize(const ::std::optional<::std::string>& uuid, const ::std::vector<::std::string>& packageNames, int32_t userId, int32_t flags, int32_t appId, const ::std::vector<int64_t>& ceDataInodes, const ::std::vector<::std::string>& codePaths, ::std::vector<int64_t>* _aidl_return) override {
    return _aidl_delegate->getAppSize(uuid, packageNames, userId, flags, appId, ceDataInodes, codePaths, _aidl_return);
  }
  ::android::binder::Status getUserSize(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t flags, const ::std::vector<int32_t>& appIds, ::std::vector<int64_t>* _aidl_return) override {
    return _aidl_delegate->getUserSize(uuid, userId, flags, appIds, _aidl_return);
  }
  ::android::binder::Status getExternalSize(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t flags, const ::std::vector<int32_t>& appIds, ::std::vector<int64_t>* _aidl_return) override {
    return _aidl_delegate->getExternalSize(uuid, userId, flags, appIds, _aidl_return);
  }
  ::android::binder::Status setAppQuota(const ::std::optional<::std::string>& uuid, int32_t userId, int32_t appId, int64_t cacheQuota) override {
    return _aidl_delegate->setAppQuota(uuid, userId, appId, cacheQuota);
  }
  ::android::binder::Status moveCompleteApp(const ::std::optional<::std::string>& fromUuid, const ::std::optional<::std::string>& toUuid, const ::std::string& packageName, const ::std::string& dataAppName, int32_t appId, const ::std::string& seInfo, int32_t targetSdkVersion) override {
    return _aidl_delegate->moveCompleteApp(fromUuid, toUuid, packageName, dataAppName, appId, seInfo, targetSdkVersion);
  }
  ::android::binder::Status dexopt(const ::std::string& apkPath, int32_t uid, const ::std::optional<::std::string>& packageName, const ::std::string& instructionSet, int32_t dexoptNeeded, const ::std::optional<::std::string>& outputPath, int32_t dexFlags, const ::std::string& compilerFilter, const ::std::optional<::std::string>& uuid, const ::std::optional<::std::string>& sharedLibraries, const ::std::optional<::std::string>& seInfo, bool downgrade, int32_t targetSdkVersion, const ::std::optional<::std::string>& profileName, const ::std::optional<::std::string>& dexMetadataPath, const ::std::optional<::std::string>& compilationReason) override {
    return _aidl_delegate->dexopt(apkPath, uid, packageName, instructionSet, dexoptNeeded, outputPath, dexFlags, compilerFilter, uuid, sharedLibraries, seInfo, downgrade, targetSdkVersion, profileName, dexMetadataPath, compilationReason);
  }
  ::android::binder::Status compileLayouts(const ::std::string& apkPath, const ::std::string& packageName, const ::std::string& outDexFile, int32_t uid, bool* _aidl_return) override {
    return _aidl_delegate->compileLayouts(apkPath, packageName, outDexFile, uid, _aidl_return);
  }
  ::android::binder::Status rmdex(const ::std::string& codePath, const ::std::string& instructionSet) override {
    return _aidl_delegate->rmdex(codePath, instructionSet);
  }
  ::android::binder::Status mergeProfiles(int32_t uid, const ::std::string& packageName, const ::std::string& profileName, bool* _aidl_return) override {
    return _aidl_delegate->mergeProfiles(uid, packageName, profileName, _aidl_return);
  }
  ::android::binder::Status dumpProfiles(int32_t uid, const ::std::string& packageName, const ::std::string& profileName, const ::std::string& codePath, bool* _aidl_return) override {
    return _aidl_delegate->dumpProfiles(uid, packageName, profileName, codePath, _aidl_return);
  }
  ::android::binder::Status copySystemProfile(const ::std::string& systemProfile, int32_t uid, const ::std::string& packageName, const ::std::string& profileName, bool* _aidl_return) override {
    return _aidl_delegate->copySystemProfile(systemProfile, uid, packageName, profileName, _aidl_return);
  }
  ::android::binder::Status clearAppProfiles(const ::std::string& packageName, const ::std::string& profileName) override {
    return _aidl_delegate->clearAppProfiles(packageName, profileName);
  }
  ::android::binder::Status destroyAppProfiles(const ::std::string& packageName) override {
    return _aidl_delegate->destroyAppProfiles(packageName);
  }
  ::android::binder::Status createProfileSnapshot(int32_t appId, const ::std::string& packageName, const ::std::string& profileName, const ::std::string& classpath, bool* _aidl_return) override {
    return _aidl_delegate->createProfileSnapshot(appId, packageName, profileName, classpath, _aidl_return);
  }
  ::android::binder::Status destroyProfileSnapshot(const ::std::string& packageName, const ::std::string& profileName) override {
    return _aidl_delegate->destroyProfileSnapshot(packageName, profileName);
  }
  ::android::binder::Status idmap(const ::std::string& targetApkPath, const ::std::string& overlayApkPath, int32_t uid) override {
    return _aidl_delegate->idmap(targetApkPath, overlayApkPath, uid);
  }
  ::android::binder::Status removeIdmap(const ::std::string& overlayApkPath) override {
    return _aidl_delegate->removeIdmap(overlayApkPath);
  }
  ::android::binder::Status rmPackageDir(const ::std::string& packageDir) override {
    return _aidl_delegate->rmPackageDir(packageDir);
  }
  ::android::binder::Status freeCache(const ::std::optional<::std::string>& uuid, int64_t targetFreeBytes, int64_t cacheReservedBytes, int32_t flags) override {
    return _aidl_delegate->freeCache(uuid, targetFreeBytes, cacheReservedBytes, flags);
  }
  ::android::binder::Status linkNativeLibraryDirectory(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, const ::std::string& nativeLibPath32, int32_t userId) override {
    return _aidl_delegate->linkNativeLibraryDirectory(uuid, packageName, nativeLibPath32, userId);
  }
  ::android::binder::Status createOatDir(const ::std::string& oatDir, const ::std::string& instructionSet) override {
    return _aidl_delegate->createOatDir(oatDir, instructionSet);
  }
  ::android::binder::Status linkFile(const ::std::string& relativePath, const ::std::string& fromBase, const ::std::string& toBase) override {
    return _aidl_delegate->linkFile(relativePath, fromBase, toBase);
  }
  ::android::binder::Status moveAb(const ::std::string& apkPath, const ::std::string& instructionSet, const ::std::string& outputPath) override {
    return _aidl_delegate->moveAb(apkPath, instructionSet, outputPath);
  }
  ::android::binder::Status deleteOdex(const ::std::string& apkPath, const ::std::string& instructionSet, const ::std::optional<::std::string>& outputPath) override {
    return _aidl_delegate->deleteOdex(apkPath, instructionSet, outputPath);
  }
  ::android::binder::Status installApkVerity(const ::std::string& filePath, ::android::base::unique_fd verityInput, int32_t contentSize) override {
    return _aidl_delegate->installApkVerity(filePath, std::move(verityInput), contentSize);
  }
  ::android::binder::Status assertFsverityRootHashMatches(const ::std::string& filePath, const ::std::vector<uint8_t>& expectedHash) override {
    return _aidl_delegate->assertFsverityRootHashMatches(filePath, expectedHash);
  }
  ::android::binder::Status reconcileSecondaryDexFile(const ::std::string& dexPath, const ::std::string& pkgName, int32_t uid, const ::std::vector<::std::string>& isas, const ::std::optional<::std::string>& volume_uuid, int32_t storage_flag, bool* _aidl_return) override {
    return _aidl_delegate->reconcileSecondaryDexFile(dexPath, pkgName, uid, isas, volume_uuid, storage_flag, _aidl_return);
  }
  ::android::binder::Status hashSecondaryDexFile(const ::std::string& dexPath, const ::std::string& pkgName, int32_t uid, const ::std::optional<::std::string>& volumeUuid, int32_t storageFlag, ::std::vector<uint8_t>* _aidl_return) override {
    return _aidl_delegate->hashSecondaryDexFile(dexPath, pkgName, uid, volumeUuid, storageFlag, _aidl_return);
  }
  ::android::binder::Status invalidateMounts() override {
    return _aidl_delegate->invalidateMounts();
  }
  ::android::binder::Status isQuotaSupported(const ::std::optional<::std::string>& uuid, bool* _aidl_return) override {
    return _aidl_delegate->isQuotaSupported(uuid, _aidl_return);
  }
  ::android::binder::Status prepareAppProfile(const ::std::string& packageName, int32_t userId, int32_t appId, const ::std::string& profileName, const ::std::string& codePath, const ::std::optional<::std::string>& dexMetadata, bool* _aidl_return) override {
    return _aidl_delegate->prepareAppProfile(packageName, userId, appId, profileName, codePath, dexMetadata, _aidl_return);
  }
  ::android::binder::Status snapshotAppData(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int32_t snapshotId, int32_t storageFlags, int64_t* _aidl_return) override {
    return _aidl_delegate->snapshotAppData(uuid, packageName, userId, snapshotId, storageFlags, _aidl_return);
  }
  ::android::binder::Status restoreAppDataSnapshot(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t appId, const ::std::string& seInfo, int32_t user, int32_t snapshotId, int32_t storageflags) override {
    return _aidl_delegate->restoreAppDataSnapshot(uuid, packageName, appId, seInfo, user, snapshotId, storageflags);
  }
  ::android::binder::Status destroyAppDataSnapshot(const ::std::optional<::std::string>& uuid, const ::std::string& packageName, int32_t userId, int64_t ceSnapshotInode, int32_t snapshotId, int32_t storageFlags) override {
    return _aidl_delegate->destroyAppDataSnapshot(uuid, packageName, userId, ceSnapshotInode, snapshotId, storageFlags);
  }
  ::android::binder::Status migrateLegacyObbData() override {
    return _aidl_delegate->migrateLegacyObbData();
  }
private:
  ::android::sp<IInstalld> _aidl_delegate;
};  // class IInstalldDelegator
}  // namespace os
}  // namespace android
