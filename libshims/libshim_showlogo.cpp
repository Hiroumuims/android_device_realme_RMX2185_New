#include <gui/SurfaceComposerClient.h>
#include <gui/SurfaceControl.h>
#include <utils/String8.h>
#include <binder/IBinder.h>

using namespace android;

extern "C" {

// Fix setDisplayProjection (stub safely)
void _ZN7android21SurfaceComposerClient11Transaction20setDisplayProjectionERKNS_2spINS_7IBinderEEEjRKNS_4RectES9_(
    void* /*this*/,
    const sp<IBinder>& /*token*/,
    uint32_t /*orientation*/,
    const Rect& /*layerStackRect*/,
    const Rect& /*displayRect*/) {
    // Do nothing (stub)
}

// Fix createSurface (IMPORTANT)
extern "C" void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlENS_13LayerMetadataEPj(
    void*,
    const android::String8&,
    uint32_t,
    uint32_t,
    int,
    uint32_t,
    android::SurfaceControl*,
    android::LayerMetadata,
    uint32_t*) {


    // Return null to satisfy linker
    return nullptr;
}

// Optional overload (some blobs use this)
extern "C" void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlENS_13LayerMetadataE(
    void*,
    const android::String8&,
    uint32_t,
    uint32_t,
    int,
    uint32_t,
    android::SurfaceControl*,
    android::LayerMetadata) {

    return nullptr;
}

// Fix release()
extern "C" void _ZN7android14SurfaceControl7releaseEv() {
    // Do nothing (stub)
}

}
