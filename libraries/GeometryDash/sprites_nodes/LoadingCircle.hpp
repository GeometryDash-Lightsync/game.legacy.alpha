#pragma once

#include <GDLib.h>

class LoadingCircle : public cocos2d::CCLayerColor {
public:
    void* unk0;
    cocos2d::CCSprite* m_sprite;
    cocos2d::CCLayer* m_parentLayer;
    bool m_fade;

    void setParentLayer(cocos2d::CCLayer* layer) {

        m_parentLayer = layer;

    }
};