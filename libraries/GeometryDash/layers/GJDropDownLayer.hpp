#pragma once

#include <GDLib.h>

class GJDropDownLayer : public cocos2d::CCLayerColor {
public:
    cocos2d::CCPoint m_endPosition;
    cocos2d::CCPoint m_startPosition;
    cocos2d::CCMenu* m_buttonMenu;
    void* m_listLayer;
    cocos2d::CCLayer* m_mainLayer;
    bool m_hidden;
    void* m_delegate;
    bool m_fastMenu;

    GJDropDownLayer() {

        m_endPosition = cocos2d::CCPointMake(0.f, 0.f);

        m_startPosition = cocos2d::CCPointMake(0.f, 0.f);

        m_buttonMenu = nullptr;

        m_listLayer = nullptr;

        m_mainLayer = nullptr;

        m_hidden = false;

        m_delegate = nullptr;

        m_fastMenu = false;
    }

    bool init(char const* p0, float p1, bool p2)
    {
        return reinterpret_cast<bool(__fastcall*)(
            GJDropDownLayer*, char const*, float, bool
            )>(redecore::getBase() + 0x2454f0)(this, p0, p1, p2);
    }

    bool init(char const* title) {

        return init(title, 220.0f, false);

    }

    static GJDropDownLayer* create(const char* title, float height, bool p2) {

        GJDropDownLayer* pRet = new GJDropDownLayer();

        if (pRet && pRet->init(title, height, p2)) {

            pRet->autorelease();

            return pRet;

        }

        CC_SAFE_DELETE(pRet);

        return nullptr;

    }

    static GJDropDownLayer* create(const char* title) {

        GJDropDownLayer* pRet = new GJDropDownLayer();

        if (pRet && pRet->init(title)) {

            pRet->autorelease();

            return pRet;

        }

        CC_SAFE_DELETE(pRet);

        return nullptr;

    }


    void showLayer(bool transition) {
        reinterpret_cast<void(__fastcall*)(
            GJDropDownLayer*, bool
            )>(redecore::getBase() + 0x2459d0)(this, transition);
    }
};