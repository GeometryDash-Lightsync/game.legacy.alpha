#pragma once

#include <GDLib.h>

class MenuGameLayer : public cocos2d::CCLayer
{
public:
    bool m_videoOptionsOpen;
    float m_deltaCount;
    bool m_isDestroyingPlayer;
    int m_initCount;
    cocos2d::CCPoint m_unused1;
    PlayerObject* m_playerObject;
    cocos2d::CCSprite* m_backgroundSprite;
    cocos2d::CCLayer* m_groundLayer;
    float m_backgroundSpeed;
};