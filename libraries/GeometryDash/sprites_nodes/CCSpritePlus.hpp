#pragma once
#include <GDLib.h>

class CCSpritePlus : public cocos2d::CCSprite {
public:
    cocos2d::CCArray* m_followers;
    CCSpritePlus* m_followingSprite;
    bool m_hasFollower;
    bool m_propagateScaleChanges;
    bool m_propagateFlipChanges;
    PAD(1);
};