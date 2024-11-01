#pragma once
#include <GDLib.h>
#include "../layers/CCScrollLayerExt.hpp"

class CCScrollLayerExtDelegate {
    /**
    * Out of line
    */
    virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt* p0);

    /**
     * Out of line
     */
    virtual void scrollViewDidEndDecelerating(CCScrollLayerExt* p0);

    /**
     * Out of line
     */
    virtual void scrollViewTouchMoving(CCScrollLayerExt* p0);

    /**
     * Out of line
     */
    virtual void scrollViewDidEndMoving(CCScrollLayerExt* p0);

    /**
     * Out of line
     */
    virtual void scrollViewTouchBegin(CCScrollLayerExt* p0);

    /**
     * Out of line
     */
    virtual void scrollViewTouchEnd(CCScrollLayerExt* p0);
};