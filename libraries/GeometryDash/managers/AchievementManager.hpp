#pragma once

#include <GDLib.h>

class AchievementManager : public cocos2d::CCNode {
public:
	cocos2d::CCArray* m_allAchievements;
	cocos2d::CCDictionary* m_platformAchievements;
	cocos2d::CCDictionary* m_achievementUnlocks;
	void* m_unkPtrUnused;
	cocos2d::CCDictionary* m_reportedAchievements;
	bool m_dontNotify;
	cocos2d::CCArray* m_allAchievementsSorted;
	int m_order;
	cocos2d::CCDictionary* m_unAchieved;

	static AchievementManager* sharedState() {
		return reinterpret_cast<AchievementManager * (__fastcall*)()>(
			redecore::getBase() + 0x7d50
			)();
	}

    
	void addAchievement(std::string achID, std::string title, std::string unlockDesc, std::string lockDesc, std::string reward, int limits) {
		return reinterpret_cast<void(__fastcall*)(
			AchievementManager*, std::string, std::string, std::string, std::string, std::string, int
			)>(
			redecore::getBase() + 0x7ea0
			)(this, achID, title, unlockDesc, lockDesc, reward, limits);
		
	}

	int percentForAchievement(const char* achievement) {
		return m_reportedAchievements->valueForKey(achievement)->intValue();
	}
};