#pragma once

#include <GDLib.h>

class OptionsLayer : public GJDropDownLayer, public FLAlertLayerProtocol {
public:

	/*
	[Missing]
	2.200: (...)
	*/
	TodoReturn musicSliderChanged(cocos2d::CCObject* p0);

	/*
	2.200: 0x2AC5C0 (thiscall)
	*/
	void onAccount(cocos2d::CCObject* sender) {
		reinterpret_cast<void(__fastcall*)(
			OptionsLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x2AC5C0)(this, sender);
	}
	/*
	[Missing]
	2.200: (...)
	*/
	void onMenuMusic(cocos2d::CCObject* sender);

	/*
	[Missing]
	2.200: 0x2B0F70 (thiscall)
	*/
	void onOptions(cocos2d::CCObject* sender) {
		reinterpret_cast<void(__fastcall*)(
			OptionsLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x3512F0)(this, sender);
	}

	/*
	2.200: 0x2AC1D0 (thiscall)
	*/
	void onSecretVault(cocos2d::CCObject* sender) {
		reinterpret_cast<void(__fastcall*)(
			OptionsLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x2AC1D0)(this, sender);
	}

	/*
	[Missing]
	2.200: (...)
	*/
	void onSoundtracks(cocos2d::CCObject* sender);

	/*
	[Missing]
	2.200: (...)
	*/
	void onSupport(cocos2d::CCObject* sender) {
		reinterpret_cast<void(__fastcall*)(
			OptionsLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x351B80)(this, sender);
	}

	/*
	[Missing]
	2.200: 0x2AC560 (thiscall)
	*/
	void onVideo(cocos2d::CCObject* sender) {
		reinterpret_cast<void(__fastcall*)(
			OptionsLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x351B60)(this, sender);
	}

	/*
	[Missing]
	2.200: (...)
	*/
	TodoReturn sfxSliderChanged(cocos2d::CCObject* p0);

};