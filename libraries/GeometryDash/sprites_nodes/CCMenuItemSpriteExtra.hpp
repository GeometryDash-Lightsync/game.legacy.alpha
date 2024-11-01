#pragma once

#include <GDLib.h>

class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite {
public:
	float m_scaleMultiplier;
	float m_baseScale;
	bool m_animationEnabled;
	bool m_colorEnabled;
	float m_unknown1;
    std::string m_activateSound;
    std::string m_selectSound;
	float m_colorDip;
	cocos2d::CCPoint m_destPosition;
	cocos2d::CCPoint m_offset;
	MenuAnimationType m_animationType;
	cocos2d::CCPoint m_startPosition;
	int m_unknown4;


public:

	bool init(cocos2d::CCNode* p0, cocos2d::CCNode* p1, cocos2d::CCObject* p2, cocos2d::SEL_MenuHandler p3) {
		return reinterpret_cast<bool(__fastcall*)(
			CCMenuItemSpriteExtra*, cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler
			)>(
				redecore::getBase() + 0x258F0
				)(
					this, p0, p1, p2, p3
					);
	}


	virtual void activate() {
		reinterpret_cast<void(__fastcall*)(
			CCMenuItemSpriteExtra*
			)>(redecore::getBase() + 0x259D0)(this);
	}

	virtual void selected() {
		reinterpret_cast<void(__fastcall*)(
			CCMenuItemSpriteExtra*
			)>(redecore::getBase() + 0x25AA0)(this);
	}

	virtual void unselected() {
		reinterpret_cast<void(__fastcall*)(
			CCMenuItemSpriteExtra*
			)>(redecore::getBase() + 0x25C80)(this);
	}


	static CCMenuItemSpriteExtra* create(cocos2d::CCNode* p0, cocos2d::CCNode* p1, cocos2d::CCObject* p2, cocos2d::SEL_MenuHandler p3)
	{
		return reinterpret_cast<CCMenuItemSpriteExtra * (__thiscall*)(cocos2d::CCNode*, cocos2d::CCNode*,
			cocos2d::CCObject*, cocos2d::SEL_MenuHandler)>(
				redecore::getBase() + 0x43cc0
				)(p0, p1, p2, p3);
	}

	//Out of line
	static CCMenuItemSpriteExtra* create(cocos2d::CCNode* sprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback) {
		return CCMenuItemSpriteExtra::create(sprite, nullptr, target, callback);
	}


	void setSizeMult(float mult) {
		m_fSizeMult = mult;
	}

	void useAnimationType(MenuAnimationType type) {
		this->m_startPosition = this->getNormalImage()->getPosition();
		this->m_animationType = type;
	}


	void setDestination(cocos2d::CCPoint const& pos) {
		this->m_destPosition = pos;
	}

	void setOffset(cocos2d::CCPoint const& pos) {
		this->m_offset = pos;
	}

	void setScale(float scale) override {
		this->CCMenuItemSprite::setScale(scale);
		this->m_baseScale = scale;
	}
};
