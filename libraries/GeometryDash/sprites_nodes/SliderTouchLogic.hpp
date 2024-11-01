#pragma once
#include <GDLib.h>

class SliderTouchLogic : public cocos2d::CCMenu {
public:
    float m_unknownUnused;
    float m_length;
    cocos2d::CCMenuItemImage* m_thumb;
    cocos2d::CCSprite* m_slider;
    bool m_activateThumb;
    cocos2d::CCPoint m_position;
    bool m_rotated;

};