#pragma once

#include <GDLib.h>
class ButtonSprite;
class ScrollingLayer;
class FLAlertLayerProtocol;

class FLAlertLayer : public cocos2d::CCLayerColor {
public:
    void* unk0;
    cocos2d::CCMenu* m_buttonMenu;
    FLAlertLayerProtocol* m_alertProtocol;
    cocos2d::CCNode* m_scene;
    bool m_reverseKeyBack;
    cocos2d::ccColor3B m_color;
    cocos2d::CCLayer* m_mainLayer;
    int m_ZOrder;
    bool m_noElasticity;
    cocos2d::ccColor3B m_color2;
    ButtonSprite* m_button1;
    ButtonSprite* m_button2;
    ScrollingLayer* m_scrollingLayer;
    int m_controlConnected;
    bool m_containsBorder;
    bool m_noAction;
    int m_joystickConnected;
    bool m_forcePrioRegistered;
public:

    /*
    [Inlined]
    2.200: (...)
    */
    ~FLAlertLayer();

    /*
    [Inlined]
    2.200: (...)
    */
    FLAlertLayer();

    static FLAlertLayer* create(FLAlertLayerProtocol* delegate, char const* title, std::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale)
    {
        return reinterpret_cast<FLAlertLayer * (__fastcall*)
            (FLAlertLayerProtocol*, const char*, std::string, const char*, const char*, float, bool, float, float)>
            (redecore::getBase() + 0x50ac0)
            (delegate, title, desc, btn1, btn2, width, scroll, height, textScale);
    }

    static FLAlertLayer* create(FLAlertLayerProtocol* delegate, char const* title, std::string desc, char const* btn1, char const* btn2, float width) {
        return reinterpret_cast<FLAlertLayer * (__fastcall*)
            (FLAlertLayerProtocol*, const char*, std::string, const char*, const char*, float)>
            (redecore::getBase() + 0x50a10)
            (delegate, title, desc, btn1, btn2, width);
    }

    static FLAlertLayer* create(FLAlertLayerProtocol* delegate, char const* title, std::string desc, char const* btn1, char const* btn2) {

        return FLAlertLayer::create(delegate, title, desc, btn1, btn2, 300.0);

    }


    static FLAlertLayer* create(char const* title, const std::string& desc, char const* btn) {

        return FLAlertLayer::create(nullptr, title, desc, btn, nullptr, 300.0);

    }


    static FLAlertLayer* create(char const* title, const std::string& desc, float width) {

        return FLAlertLayer::create(nullptr, title, desc, "OK", nullptr, width);

    }

    static FLAlertLayer* create(char const* title, const std::string& desc) {

        return FLAlertLayer::create(nullptr, title, desc, "OK", nullptr, 300.0);

    }

    static FLAlertLayer* create(char const* title, const std::string& desc, char const* btn, float width) {

        return FLAlertLayer::create(nullptr, title, desc, btn, nullptr, width);

    }

    void onBtn1(cocos2d::CCObject* sender) {
        return reinterpret_cast<void(__fastcall*)(FLAlertLayer*, cocos2d::CCObject*)>(
            redecore::getBase() + 0x51ac0
            )(this, sender);
    }

    void onBtn2(cocos2d::CCObject* sender) {
        return reinterpret_cast<void(__fastcall*)(FLAlertLayer*, cocos2d::CCObject*)>(
            redecore::getBase() + 0x51b20
            )(this, sender);
    }

    void show() {
        return reinterpret_cast<void(__fastcall*)(FLAlertLayer*)>(
            redecore::getBase() + 0x51d10
            )(this);
    }
};