#pragma once
#include "../lightsync.h"

class MenuLayerExt : public MenuLayer, LayerExtProtocol<MenuLayer> {
public:
    BackgroundSprite *m_background;
    CCMenu *m_mainMenu;
    CCMenu *m_exitMenu;

    void onSound(CCObject* sender) {

        Lightsync->m_extraSettingsOpened = false;
        
        this->onSettings(sender);
    }

    void onExtraSettings(cocos2d::CCObject* pSender) {

	    Lightsync->m_extraSettingsOpened = false;

	    this->onSettings(pSender);
    }
};