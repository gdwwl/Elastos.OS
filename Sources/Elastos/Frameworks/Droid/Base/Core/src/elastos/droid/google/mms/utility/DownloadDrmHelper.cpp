
#include "elastos/droid/google/mms/utility//DownloadDrmHelper.h"

namespace Elastos {
namespace Droid {
namespace Google {
namespace Mms {
namespace Utility {

//=====================================================================
//                          DownloadDrmHelper
//=====================================================================
const String DownloadDrmHelper::TAG("DownloadDrmHelper");

Boolean DownloadDrmHelper::IsDrmMimeType(
    /* [in] */ IContext* context,
    /* [in] */ const String& mimetype)
{
    Boolean result = FALSE;
    if (context != NULL) {
        // try {
            assert(0 && "TODO");
            // DrmManagerClient drmClient = new DrmManagerClient(context);
            // if (drmClient != NULL && !mimetype.IsNull() && mimetype.GetLength() > 0) {
            //     result = drmClient->CanHandle(String(""), mimetype);
            // }
        // } catch (IllegalArgumentException e) {
        //     Log.w(TAG,
        //             "DrmManagerClient instance could not be created, context is Illegal.");
        // } catch (IllegalStateException e) {
        //     Log.w(TAG, "DrmManagerClient didn't initialize properly.");
        // }
    }
    return result;
}

Boolean DownloadDrmHelper::IsDrmConvertNeeded(
    /* [in] */ const String& mimetype)
{
    return IDownloadDrmHelper::MIMETYPE_DRM_MESSAGE.Equals(mimetype);
}

String DownloadDrmHelper::ModifyDrmFwLockFileExtension(
    /* [in] */ const String& filename)
{
    if (!filename.IsNull()) {
        Int32 extensionIndex = 0;
        extensionIndex = filename.LastIndexOf(".");
        if (extensionIndex != -1) {
            filename = filename.Substring(0, extensionIndex);
        }
        filename = filename.Concat(EXTENSION_INTERNAL_FWDL);
    }
    return filename;
}

String DownloadDrmHelper::GetOriginalMimeType(
    /* [in] */ IContext* context,
    /* [in] */ const String& path,
    /* [in] */ const String& containingMime)
{
    String result(containingMime);
    AutoPtr<IDrmManagerClient> drmClient = new DrmManagerClient(context);
    // try {
        if (drmClient->CanHandle(path, NULL)) {
            drmClient->GetOriginalMimeType(path, &result);
        }
    // } catch (IllegalArgumentException ex) {
    //     Log.w(TAG,
    //             "Can't get original mime type since path is NULL or empty string.");
    // } catch (IllegalStateException ex) {
    //     Log.w(TAG, "DrmManagerClient didn't initialize properly.");
    // }
    return result;
}

} // namespace Utility
} // namespace Mms
} // namespace Google
} // namespace Droid
} // namespace Elastos
