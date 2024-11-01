#pragma once

#include <GDLib.h>

class GJRobotSprite;
class GJSpiderSprite;

class SimplePlayer : public cocos2d::CCSprite {
public:
	cocos2d::CCSprite* m_firstLayer;
	cocos2d::CCSprite* m_secondLayer;
	cocos2d::CCSprite* m_birdDome;
	cocos2d::CCSprite* m_outlineSprite;
	cocos2d::CCSprite* m_detailSprite;
	GJRobotSprite* m_robotSprite;
	GJSpiderSprite* m_spiderSprite;
	int m_unknown;
	bool m_hasGlowOutline;
	PAD(7);
	bool m_hasCustomGlowColor;
	cocos2d::ccColor3B m_glowColor;
	PAD(4);

	virtual bool init(int iconID) {
		return reinterpret_cast<bool(__fastcall*)(SimplePlayer*, int)>(
			redecore::getBase() + 0x2673c0)(this, iconID);
	}
public:
	static auto create(int iconID) {
		return reinterpret_cast<SimplePlayer * (__fastcall*)(int)>(
			redecore::getBase() + 0x2672d0)(iconID);
	}

	void updatePlayerFrame(int iconID, IconType iconType) {
		reinterpret_cast<void(__fastcall*)(SimplePlayer*, int, IconType)>(
			redecore::getBase() + 0x267f20)(this, iconID, iconType);
	}

	void updateColors() {
		reinterpret_cast<void(__fastcall*)(SimplePlayer*)>(
			redecore::getBase() + 0x267b60)(this);
	}

	void setColor(const cocos2d::ccColor3B& color) {
		reinterpret_cast<void(__fastcall*)(SimplePlayer*, const cocos2d::ccColor3B&)>(
			redecore::getBase() + 0x267b30)(this, color);
	}

	void setSecondColor(const cocos2d::ccColor3B& color) {
		// this function is inlined on windows
		m_secondLayer->setColor(color);
		updateColors();
	}

	inline void disableCustomGlowColor() {

		m_hasCustomGlowColor = false;

	}
	inline void enableCustomGlowColor(cocos2d::_ccColor3B const& color) {

		m_hasCustomGlowColor = true;

		m_glowColor = color;

	}


	virtual void setOpacity(unsigned char opacity) {
		reinterpret_cast<void(__fastcall*)(SimplePlayer*, unsigned char)>(
			redecore::getBase() + 0x268680)
			(reinterpret_cast<SimplePlayer*>(reinterpret_cast<char*>(this) + 0xec), opacity);
	}

	// custom functions

	bool hasGlowOutline() { return m_hasGlowOutline; }
	void setGlowOutline(bool value) {

		m_hasGlowOutline = value;
		updateColors();
	}
};
