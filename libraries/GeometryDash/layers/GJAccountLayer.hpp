#pragma once

#include <GDLib.h>

#include "GJDropDownLayer.hpp"
class GJDropDownLayer;

class GJAccountLayer : public GJDropDownLayer {
public:
	void onLogin(cocos2d::CCObject* sender) {
		reinterpret_cast<void(__fastcall*)(
			GJAccountLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x7C820)(this, sender);
	}

	void onRefresh(CCObject* sender)
	{
		reinterpret_cast<void(__fastcall*)(
			GJAccountLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x7E3A0)(this, sender);
	}

	static GJAccountLayer* create() {
		return reinterpret_cast<GJAccountLayer*(__thiscall*)()>(
			redecore::getBase() + 0x7BF70)(); //cocos2d::CCObject *sub_457170()
	}

	static GJAccountLayer* addToScene() {
		auto layer = GJAccountLayer::create();
		cocos2d::CCDirector::sharedDirector()
			->getRunningScene()
			->addChild(layer);
		layer->showLayer(false);
		return layer;
	}
};