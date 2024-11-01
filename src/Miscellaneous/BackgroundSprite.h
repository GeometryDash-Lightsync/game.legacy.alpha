#pragma once

#include "../Lightsync.hpp"

class BackgroundSprite : public CCNode
{
public:
    CCSprite* m_sprite;
    extension::CCScale9Sprite* m_9Sprite;
    float padding = 35.f;
    bool m_usingSize;
    CCNode* m_background;

    bool init(const char *texture, bool frame, bool usingSize)
    {

        auto size = ccDir->getWinSize();
        m_usingSize = usingSize;

        if (!usingSize)
        {
            m_sprite = (frame) ? CCSprite::createWithSpriteFrameName(texture) : CCSprite::create(texture);

            auto content = m_sprite->getContentSize();
            
            m_sprite->setScaleX(size.width / content.width);
            m_sprite->setScaleY(size.height / content.height);

            m_sprite->setAnchorPoint({0, 0});
            m_background = m_sprite;

            this->addChild(m_sprite);
        }
        else
        {

            m_9Sprite = (frame) ? extension::CCScale9Sprite::createWithSpriteFrameName(texture) : extension::CCScale9Sprite::create(texture);

            auto cSize = m_9Sprite->getContentSize();

            m_9Sprite->setContentSize({size.width - padding, size.height - padding});

            m_9Sprite->setAnchorPoint({0, 0});
            m_9Sprite->setPosition({padding / 2, padding / 2});
            
            m_background = m_9Sprite;

            this->addChild(m_9Sprite);
        }

        return true;
    }

    CCNode *getTexture() {
        return m_background;
    }

    void setOpacity(float s) {
        if (!m_usingSize)
            m_sprite->setOpacity(s);
        else
            m_9Sprite->setOpacity(s);
    }

    void setColor(ccColor3B s) {
        if (!m_usingSize)
            m_sprite->setColor(s);
        else
            m_9Sprite->setColor(s);
    }
    void setOffset(CCPoint s)
    {
        if (!m_usingSize)
        {
            m_sprite->setPosition({m_sprite->getPositionX() + s.x, m_sprite->getPositionY() + s.y});
        }
        else
            m_9Sprite->setPosition({m_9Sprite->getPositionX() + s.x, m_9Sprite->getPositionY() + s.y});
    }
    void setAnchorPoint(CCPoint s)
    {
        if (!m_usingSize)
            m_sprite->setAnchorPoint({s.x, s.y});
        else
            m_9Sprite->setAnchorPoint({s.x, s.y});
    }

    static BackgroundSprite *create(const char *texture, bool spriteFrame, bool usingSize)
    {
        BackgroundSprite *pRet = new BackgroundSprite();

        if (pRet && pRet->init(texture, spriteFrame, usingSize))
        {
            pRet->autorelease();
            return pRet;
        }
        
        
		CC_SAFE_DELETE(pRet);
		return nullptr;
    }

    static BackgroundSprite *create(const char *texture)
    {
        return BackgroundSprite::create(texture, false, false);
    }

    static BackgroundSprite *createWithSpriteFrameName(const char *texture)
    {
        return BackgroundSprite::create(texture, true, false);
    }

    static BackgroundSprite *createWithSize(const char *texture)
    {
        return BackgroundSprite::create(texture, false, true);
    }

    static BackgroundSprite *createWithSizeFrame(const char *texture)
    {
        return BackgroundSprite::create(texture, true, true);
    }

    static BackgroundSprite *createStandarBackground(ccColor3B color) {
        auto bg = BackgroundSprite::create("GJ_gradientBG.png", false, false);
        bg->setColor(color);
        return bg;
    }
};