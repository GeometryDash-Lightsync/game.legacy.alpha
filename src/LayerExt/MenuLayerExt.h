#pragma once
#include "../lightsync.h"

class MenuLayerExt : public MenuLayer{
public:

    void onSound(CCObject* sender) {

        Lightsync->m_extraSettingsOpened = false;
        
        this->onSettings(sender);
    }

    void onExtraSettings(cocos2d::CCObject* pSender) {

	    Lightsync->m_extraSettingsOpened = false;

	    this->onSettings(pSender);
    }
};