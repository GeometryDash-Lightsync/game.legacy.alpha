#pragma once

#include <GDLib.h>

#include "CCAnimatedSprite.hpp"

class GJRobotSprite : public CCAnimatedSprite {
	PAD(8); // 0x244
	cocos2d::ccColor3B m_secondaryColor; // 0x24c
};