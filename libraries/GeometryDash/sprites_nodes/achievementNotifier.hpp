#pragma once

#include <GDLib.h>

class AchievementBar;

class AchievementNotifier : public cocos2d::CCNode {
protected:

	cocos2d::CCScene* m_pCurrentScene;
	cocos2d::CCArray* m_pQueue;
	AchievementBar* m_pCurrentAchievement;


public:
	/*
	2.200: 0x1C023 (stdcall)
	*/
	static AchievementNotifier* sharedState();

	/*
	2.200: 0x1C0A0 (thiscall)
	*/
	void showNextAchievement();

	/*
	* Inlined on Windows.
	2.200: (...)
	*/
	void notifyAchievement(const char* title, const char* desc, const char* icon, bool quest) {
		m_pQueue->addObject(AchievementBar::create(title, desc, icon, quest));
		if (!m_pCurrentAchievement) {
			this->showNextAchievement();
		}
	};
};