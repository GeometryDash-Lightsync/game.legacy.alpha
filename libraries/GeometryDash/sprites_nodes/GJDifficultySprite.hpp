#pragma once

#include <GDLib.h>
class GJDifficultySprite : public cocos2d::CCSprite {
public:
	GJFeatureState m_featureState;
	//0x292e20
	void updateDifficultyFrame(int p0, GJDifficultyName p1)
	{
		reinterpret_cast<void(__fastcall*)(GJDifficultySprite*, int, GJDifficultyName)>(
			redecore::getBase() + 0x292e20
			)(this, p0, p1);
	}

	void updateFeatureState(GJFeatureState p0)
	{
		reinterpret_cast<void(__fastcall*)(GJDifficultySprite*, GJFeatureState)>(
			redecore::getBase() + 0x292f40
			)(this, p0);
	}

	static GJDifficultySprite* create(int p0, GJDifficultyName p1)
	{
		return reinterpret_cast<GJDifficultySprite*(__fastcall*)(int, GJDifficultyName)>(
			redecore::getBase() + 0x292c60
			)(p0, p1);
	}
};