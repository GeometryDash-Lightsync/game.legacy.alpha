#pragma once

#include <GDLib.h>

class CCAnimatedSprite : public cocos2d::CCSprite {
protected:
	std::string m_unkString1;
	std::string m_unkString2;
	void* m_animationManager;
	cocos2d::CCSprite* m_sprite;
	cocos2d::CCSprite* m_fbfSprite;
	CCSprite* m_paSprite;
	spriteMode m_spriteMode;
	std::string m_currentAnim;
	AnimatedSpriteDelegate* m_delegate;
public:
	static CCAnimatedSprite* create(const char* file) {
		return reinterpret_cast<CCAnimatedSprite * (__fastcall*)(const char*)>(
			redecore::getBase() + 0x20C80
			)(file);
	}

	virtual void animationFinished(const char*) {}
	virtual void animationFinishedO(cocos2d::CCObject*) {}

	void runAnimation(std::string name) {
		reinterpret_cast<void(__fastcall*)(CCAnimatedSprite*, std::string)>(redecore::getBase() + 0x3fe00)(this, name);
	}

	void setColor(cocos2d::ccColor3B const& color)
	{
		reinterpret_cast<void(__fastcall*)(CCAnimatedSprite*, cocos2d::ccColor3B)>(redecore::getBase() + 0x40250)(this, color);
	}
};
