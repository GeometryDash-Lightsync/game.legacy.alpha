#pragma once

#include <GDLib.h>

class CCMenuItemToggler : public cocos2d::CCMenuItem {
public:
	CCMenuItemSpriteExtra* m_offButton;
	CCMenuItemSpriteExtra* m_onButton;
	bool m_toggled;
	bool m_notClickable;


	/*
	[Missing]
	2.200: (...)
	*/
	bool init(cocos2d::CCNode* off, cocos2d::CCNode* on, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler handler);

	/*
	[Inlined]
	2.200: (...)
	*/
	CCMenuItemToggler();


	/*
	[Missing]
	2.200: (...)
	*/
	virtual void activate() override;

	/*
	[Missing]
	2.200: (...)
	*/
	virtual void selected() override;

	/*
	[Missing]
	2.200: (...)
	*/
	virtual void unselected();

	/*
	2.200: 0x19930 (thiscall)
	*/
	void setEnabled(bool enabled) {
		reinterpret_cast<void(__thiscall*)(CCMenuItemToggler*, bool)>(
			redecore::getBase() + 0x446b0
			)(this, enabled);
	}


	/*
	2.200: 0x25E50 (fastcall)
	*/
	static CCMenuItemToggler* create(cocos2d::CCNode* off, cocos2d::CCNode* on,
		cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback) {
		auto pRet = reinterpret_cast<CCMenuItemToggler * (__fastcall*)(cocos2d::CCNode*,
			cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler)>(
				redecore::getBase() + 0x44360
				)(off, on, target, callback);
		//__asm add esp, 0x8
		return pRet;
	}

	static CCMenuItemToggler* createWithSize(const char* spr1, const char* spr2, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback, float scale) {
		auto sprOff = cocos2d::CCSprite::createWithSpriteFrameName(spr1);
		auto sprOn = cocos2d::CCSprite::createWithSpriteFrameName(spr2);

		sprOff->setScale(scale);
		sprOn->setScale(scale);

		return create(sprOff, sprOn, target, callback);
	}

	static CCMenuItemToggler* createWithStandardSprites(cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback, float scale = 1.0f) {
		auto sprOff = cocos2d::CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
		auto sprOn = cocos2d::CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");

		sprOff->setScale(scale);
		sprOn->setScale(scale);

		return create(sprOff, sprOn, target, callback);
	}

	inline bool isOn() { return m_toggled; }
	inline bool isToggled() { return m_toggled; }

	void setClickable(bool on) { m_notClickable = !on; }

	/*
	2.200: 0x261E0 (thiscall)
	*/
	void toggle(bool on) {
		return reinterpret_cast<void(__fastcall*)(CCMenuItemToggler*, bool)>(
			redecore::getBase() + 0x44740
			)(this, on);
	}

	void toggleWithCallback(bool on) {
		this->activate();
		this->toggle(on);
	}
};
