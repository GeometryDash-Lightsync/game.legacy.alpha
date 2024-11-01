#pragma once

#include <GDLib.h>
class AchievementBar : public cocos2d::CCNodeRGBA {
protected:
	PAD(0x24);

public:
	/*
	Doesn't work by it own
	2.200: 0x59350 (fastcall)
	*/
	static AchievementBar* create(const char* title, const char* desc, const char* icon, bool quest);
};
