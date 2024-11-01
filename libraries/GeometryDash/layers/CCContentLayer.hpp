#pragma once

#include <GDLib.h>

class CCContentLayer : public cocos2d::CCLayerColor {
    inline CCContentLayer() {}

    /**
     * 
     */
    static CCContentLayer* create(cocos2d::ccColor4B const& p0, float p1, float p2);

    /**
     *
     */
    virtual void setPosition(cocos2d::CCPoint const& p0);
};