#include <GDLib.h>

class PauseLayer : public CCBlockLayer, public FLAlertLayerProtocol {
public:

	void onEdit(CCObject* sender) {
		return reinterpret_cast<void(__fastcall*)(PauseLayer*, cocos2d::CCObject*)>(
			redecore::getBase() + 0x35c8f0
			)(this, sender);
	}

	void onNormalMode(CCObject* sender) {
		return reinterpret_cast<void(__fastcall*)(PauseLayer*, cocos2d::CCObject*)>(
			redecore::getBase() + 0x35c640
			)(this, sender);
	}

	void onPracticeMode(CCObject* sender) {
		return reinterpret_cast<void(__fastcall*)(PauseLayer*, cocos2d::CCObject*)>(
			redecore::getBase() + 0x35c560
			)(this, sender);
	}

	void onQuit(CCObject* sender) {
		return reinterpret_cast<void(__fastcall*)(PauseLayer*, cocos2d::CCObject*)>(
			redecore::getBase() + 0x35cd70
			)(this, sender);
	}

	void onRestart(CCObject* sender) {
		return reinterpret_cast<void(__fastcall*)(PauseLayer*, cocos2d::CCObject*)>(
			redecore::getBase() + 0x35c7b0
			)(this, sender);
	}

	void onRestartFull(CCObject* sender) {
		return reinterpret_cast<void(__fastcall*)(PauseLayer*, cocos2d::CCObject*)>(
			redecore::getBase() + 0x35c850
			)(this, sender);
	}

	void onResume(CCObject* sender) {
		return reinterpret_cast<void(__fastcall*)(PauseLayer*, cocos2d::CCObject*)>(
			redecore::getBase() + 0x35c720
			)(this, sender);
	}

	void onSettings(CCObject* sender) {
		return reinterpret_cast<void(__fastcall*)(PauseLayer*, cocos2d::CCObject*)>(
			redecore::getBase() + 0x35b8e0
			)(this, sender);
	}

	void tryQuit(CCObject* sender) {
		return reinterpret_cast<void(__fastcall*)(PauseLayer*, cocos2d::CCObject*)>(
			redecore::getBase() + 0x35cb90
			)(this, sender);
	}
};