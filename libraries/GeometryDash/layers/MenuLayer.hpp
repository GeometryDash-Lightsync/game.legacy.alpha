#pragma once

#include <GDLib.h>

class MenuLayer : public cocos2d::CCLayer, public FLAlertLayerProtocol, public GooglePlayDelegate { 
public:
	bool m_showingTOS;
	cocos2d::CCSprite* m_gpSprite;
	cocos2d::CCSprite* m_viewProfileSprite;
	cocos2d::CCLabelBMFont* m_profileLabel;
	CCMenuItemSpriteExtra* m_profileButton;
	void* m_unknown;
	MenuGameLayer* m_menuGameLayer;

	void keyDown(cocos2d::enumKeyCodes p0);

	void FLAlert_Clicked(FLAlertLayer* p0, bool p1);

	static MenuLayer* get() { return gm->m_menuLayer; }

	bool init() {

		return reinterpret_cast<bool(__thiscall*)(
			MenuLayer*
			)>(redecore::getBase() + 0x3130f0)(this);
	}

	void keyBackClicked();

	void onEndGame(CCObject* pSender) {
		reinterpret_cast<void(__fastcall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x3155f0)(this, pSender);
	}

	/*
	2.200: 0x277B40 (thiscall)
	*/
	void onPlay(cocos2d::CCObject* pSender) {
		reinterpret_cast<void(__thiscall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x315030)(this, pSender);
	}

	/*
	2.200: 0x277B40 (thiscall)
	*/
	void onGarage(cocos2d::CCObject* pSender) {
		reinterpret_cast<void(__thiscall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x315420)(this, pSender);
	}

	/*
	2.200: 0x277C80 (thiscall)
	*/
	void onCreator(cocos2d::CCObject* pSender) {
		reinterpret_cast<void(__thiscall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x315390)(this, pSender);
	}

	/*
	2.200: 0x277AE0 (thiscall)
	*/
	void onAchievements(cocos2d::CCObject* pSender) {
		reinterpret_cast<void(__thiscall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x314e80)(this, pSender);
	}

	/*
	2.200: 0x277C80 (thiscall)
	*/
	void onSettings(cocos2d::CCObject* pSender)
	{
		reinterpret_cast<void(__fastcall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x3150d0)(this, pSender);
	}

	void onSound(cocos2d::CCObject* pSender) {
		gm->setGameVariable("LS-extraSettings", false);
		this->onSettings(pSender);
	}

	void onExtraSettings(cocos2d::CCObject* pSender)
	{
		gm->setGameVariable("LS-extraSettings", true);
		this->onSettings(pSender);
	}

	void onStats(cocos2d::CCObject* pSender) {
		reinterpret_cast<void(__thiscall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x315270)(this, pSender);
	}


	void onNewgrounds(cocos2d::CCObject* pSender) {
		reinterpret_cast<void(__thiscall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x277D90)(this, pSender);
	}


	void onMoreGames(cocos2d::CCObject* pSender) {
		reinterpret_cast<void(__thiscall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x277A50)(this, pSender);
	}

	void onProfile(cocos2d::CCObject* pSender) {
		reinterpret_cast<void(__thiscall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x314c40)(this, pSender);
	}

	void onDailyReward(cocos2d::CCObject* pSender) {
		reinterpret_cast<void(__thiscall*)(
			MenuLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x314700)(this, pSender);
	}

};
