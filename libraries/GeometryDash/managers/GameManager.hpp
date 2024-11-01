#pragma once

#include <GDLib.h>

#define PLAYER_ICON_FUNC(x) void setPlayer##x(int v) { m_player##x = v; __STR_CAT__(m_player##x,Rand1) = v + __STR_CAT__(m_player##x,Rand2); }
#include "../layers/GJBaseGameLayer.hpp"

class PlayLayer;
class LevelEditorLayer;
class MenuLayer;

class GameManager : public GManager {
public:
    cocos2d::CCDictionary* m_unkAnimationDict;
    cocos2d::CCDictionary* m_unkAnimationDict2;
    cocos2d::CCDictionary* m_frameTimeForAnimation;
    cocos2d::CCDictionary* m_framesForAnimation;
    cocos2d::CCDictionary* m_defaultFrames;
    bool m_switchModes;
    bool m_toFullscreen;
    bool m_reloading;
    bool m_unkBool1;
    bool m_unkBool2;
    bool m_vsyncEnabled;
    cocos2d::CCDictionary* m_valueKeeper;
    cocos2d::CCDictionary* m_unlockValueKeeper;
    cocos2d::CCDictionary* m_customObjectDict;
    double m_adTimer;
    double m_adCache;
    bool m_unkBool3;
    int m_unkSize4_1;
    double m_unkDouble2;
    int m_unkSize4_2;
    int m_unkSize4_3;
    bool m_loaded;
    bool m_googlePlaySignedIn;
    std::string m_unknownString;
    int m_unkSize4_4;
    PlayLayer* m_playLayer;
    LevelEditorLayer* m_levelEditorLayer;
    GJBaseGameLayer* m_gameLayer;
    void* m_unkPtr;
    MenuLayer* m_menuLayer;
    bool m_inMenuLayer;
    void* m_unknownVariable;
    bool m_unknownBool3;
    bool m_unknownPlayLayerBool;
    bool m_unknownBool4;
    bool m_unknownBool5;
    std::string m_playerUDID;
    std::string m_playerName;
    bool m_commentsEnabled;
    int m_playerUserIDSeed;
    int m_playerUserIDRand;
    int m_playerUserID;
    float m_bgVolume;
    float m_sfxVolume;
    float m_timeOffset;
    bool m_ratedGame;
    bool m_clickedFacebook;
    bool m_clickedTwitter;
    bool m_clickedYouTube;
    bool m_clickedTwitch;
    bool m_clickedDiscord_;
    bool m_clickedReddit;
    double m_socialsDuration;
    bool m_showedAd;
    bool m_unknownBool;
    bool m_editorEnabled;
    int m_sceneEnum;
    bool m_searchObjectBool;
    int m_playerFrameSeed;
    int m_playerFrameRand;
    int m_playerFrame;
    int m_playerShipSeed;
    int m_playerShipRand;
    int m_playerShip;
    int m_playerBallSeed;
    int m_playerBallRand;
    int m_playerBall;
    int m_playerBirdSeed;
    int m_playerBirdRand;
    int m_playerBird;
    int m_playerDartSeed;
    int m_playerDartRand;
    int m_playerDart;
    int m_playerRobotSeed;
    int m_playerRobotRand;
    int m_playerRobot;
    int m_playerSpiderSeed;
    int m_playerSpiderRand;
    int m_playerSpider;
    int m_playerSwingSeed;
    int m_playerSwingRand;
    int m_playerSwing;
    int m_playerColorSeed;
    int m_playerColorRand;
    int m_playerColor;
    int m_playerColor2Seed;
    int m_playerColor2Rand;
    int m_playerColor2;
    int m_playerGlowColorSeed;
    int m_playerGlowColorRand;
    int m_playerGlowColor;
    int m_playerStreakSeed;
    int m_playerStreakRand;
    int m_playerStreak;
    int m_playerShipFireSeed;
    int m_playerShipFireRand;
    int m_playerShipFire;
    int m_playerDeathEffectSeed;
    int m_playerDeathEffectRand;
    int m_playerDeathEffect;
    int m_playerJetpackSeed;
    int m_playerJetpackRamd;
    int m_playerJetpack;
    int m_chkSeed;
    int m_chkRand;
    int m_secretNumberSeed;
    int m_secretNumberRand;
    bool m_playerGlow;
    IconType m_playerIconType;
    bool m_everyPlaySetup;
    bool m_showSongMarkers;
    bool m_showBPMMarkers;
    bool m_recordGameplay;
    bool m_showProgressBar;
    bool m_performanceMode;
    bool m_unkBool4;
    bool m_clickedGarage;
    bool m_clickedEditor;
    bool m_clickedName;
    bool m_clickedPractice;
    bool m_showedEditorGuide;
    bool m_showedRateDiffDialog;
    bool m_showedRateStarDialog;
    bool m_showedLowDetailDialog;
    void* m_unkPtr2;
    void* m_unkPtr3;
    int m_unkSize4_5;
    int m_unkSize4_6;
    int m_unkSize4_7;
    int m_unkSize4_8;
    int m_loadedBgID;
    int m_loadedGroundID;
    int m_loadedMG;
    int m_loadedFont;
    int m_loadedDeathEffect;
    bool m_loadingBG;
    bool m_loadingG;
    bool m_loadingG1;
    bool m_finishedLoadingG1;
    bool m_shouldLoadG1;
    bool m_finishedLoadingMG1;
    bool m_finishedLoadingMG2;
    bool m_unkBool5;
    int m_unkSize4_9;
    int m_unkSize4_10;
    int m_unkSize4_11;
    int m_bootups;
    bool m_hasRatedGame;
    bool m_unkBool6;
    bool m_shouldLoadUnlockValueKeeper;
    bool m_unkBool7;
    bool m_unkBool8;
    int m_hasRPSeed;
    int m_hasRPRand;
    int m_hasRP;
    bool m_canGetLevelSaveData;
    int m_resolution;
    int m_texQuality;
    bool m_somethingInMenuLayer;
    void* m_unkPtr4;
    bool m_unkBool9;
    int m_unkSize4_12;
    int m_unkSize4_13;
    bool m_unkBool10;
    int m_unkSize4_14;
    bool m_disableThumbstick;
    float m_customFPSTarget;
    bool m_unkBool11;
    int m_customMenuSongID;
    int m_customPracticeSongID;
    std::map<int, int> m_loadIcon;
    std::map<int, std::map<int, int>> m_loadIcon2;
    std::map<int, bool> m_isIconBeingLoaded;
    std::array<int, 9>* m_keyStartForIcon;
    void* m_somethingKeyForIcon;
    void* m_idk;
    std::map<int, std::vector<cocos2d::CCObject*>> m_iconDelegates;
    int m_iconRequestID;
    cocos2d::CCArray* m_unkArray;
    void* m_someAdPointer;
    int m_unkSize4_15;
    int m_unkSize4_16;
    int m_unkSize4_17;
    void* m_dpad1;
    void* m_dpad2;
    void* m_dpad3;
    void* m_dpad4;
    void* m_dpad5;
    std::string m_dpadLayout1;
    std::string m_dpadLayout2;
    std::string m_dpadLayout3;
    std::string m_dpadLayoutDual1;
    std::string m_dpadLayoutDual2;
    std::string m_dpadLayoutDual3;
    int m_unkSize4_18;
    int m_unkSize4_19;
    int m_unkSize4_20;
    bool m_unkBool12;
    float m_practicePosX;
    float m_practicePosY;
    float m_practiceOpacity;
	int getPlayerFrame() { return m_playerFrame; }
	int getPlayerShip() { return m_playerShip; }
	int getPlayerBall() { return m_playerBall; }
	int getPlayerBird() { return m_playerBird; }
	int getPlayerDart() { return m_playerDart; }
	int getPlayerRobot() { return m_playerRobot; }
	int getPlayerSpider() { return m_playerSpider; }
	int getPlayerSwing() { return m_playerSwing; }
	int getPlayerJetpack() { return m_playerJetpack; }
	int getPlayerStreak() { return m_playerStreak; }
	int getPlayerDeathEffect() { return m_playerDeathEffect; }
	int getPlayerShipFire() { return m_playerShipFire; }
	bool getPlayerGlow() { return m_playerGlow; }
	int getPlayerColor() { return m_playerColor; }
	int getPlayerColor2() { return m_playerColor2; }
	int getPlayerColorGlow() { return m_playerGlowColor; }
	IconType getPlayerIconType() { return m_playerIconType; }

	/*PLAYER_ICON_FUNC(Frame)
		PLAYER_ICON_FUNC(Ship)
		PLAYER_ICON_FUNC(Ball)
		PLAYER_ICON_FUNC(Bird)
		PLAYER_ICON_FUNC(Dart)
		PLAYER_ICON_FUNC(Robot)
		PLAYER_ICON_FUNC(Spider)
		PLAYER_ICON_FUNC(Swing)
		PLAYER_ICON_FUNC(DeathEffect)
		PLAYER_ICON_FUNC(Color)
		PLAYER_ICON_FUNC(Color2)*/

	void setPlayerGlow(bool v) { m_playerGlow = v; }
	void setPlayerIconType(IconType v) { m_playerIconType = v; }

#undef FUCK_THIS

	static GameManager* sharedState() {
		return reinterpret_cast<GameManager * (__thiscall*)()>(
			redecore::getBase() + 0x172b30
			)();
	}
	void setQuality(cocos2d::TextureQuality quality) {
		m_texQuality = quality;
	}

    cocos2d::ccColor3B colorForIdx(int _id) {
        auto ret = reinterpret_cast<cocos2d::ccColor3B(__thiscall*)(
            GameManager*, int
            )>(redecore::getBase() + 0x1784b0)(this, _id);

        return ret;
    }


	bool isIconUnlocked(int _id, IconType _type) {
		return reinterpret_cast<bool(__thiscall*)(
			GameManager*, int, IconType
			)>(
				redecore::getBase() + 0x173800
				)(
					this, _id, _type
					);
	}

    bool achievementCompleted(std::string achievement) {
        return reinterpret_cast<bool(__thiscall*)(
            GameManager*, std::string
            )>(
                redecore::getBase() + 0x120D30
                )(
                    this, achievement
                    );
    }


	bool isColorUnlocked(int _id, UnlockType _type) {
		return reinterpret_cast<bool(__fastcall*)(
			GameManager*, int, UnlockType
			)>(
				redecore::getBase() + 0x173ba0
				)(
					this, _id, _type
					);
	}

	bool getGameVariable(const char* key) {
		return reinterpret_cast<bool(__fastcall*)(GameManager*, const char*)>(
			redecore::getBase() + 0x17a0e0
			)(this, key);
	}
	void setGameVariable(const char* key, bool value) {
		return reinterpret_cast<void(__fastcall*)(GameManager*, const char*, bool)>(
			redecore::getBase() + 0x179e80
			)(this, key, value);
	}
	int getIntGameVariable(const char* key) {
		return reinterpret_cast<int(__fastcall*)(GameManager*, const char*)>(
			redecore::getBase() + 0x17a6e0
			)(this, key);
	}
	void setIntGameVariable(const char* key, int value) {
		return reinterpret_cast<void(__fastcall*)(GameManager*, const char*, int)>(
			redecore::getBase() + 0x17a5e0
			)(this, key, value);
	}
	static void toggleGameVariable(const char* key);

	bool getUGV(const char* key); //0x17a470

    void setUGV(const char* key, bool value) {
        return reinterpret_cast<void(__fastcall*)(GameManager*, const char*, bool)>(
            redecore::getBase() + 0x17a310
            )(this, key, value);
    }

	bool getGameVariableDefault(const char* key, bool defaultValue) {
		auto object = reinterpret_cast<cocos2d::CCString*>(m_valueKeeper->objectForKey(std::string("gv_") + key));
		if (object == nullptr)
			return defaultValue;
		return object->boolValue();
	}

	int getIntGameVariableDefault(const char* key, int defaultValue) {
		auto object = reinterpret_cast<cocos2d::CCString*>(m_valueKeeper->objectForKey(std::string("gv_") + key));
		if (object == nullptr)
			return defaultValue;
		return object->intValue();
	}
	PlayLayer* getPlayLayer() { return m_playLayer; }
	LevelEditorLayer* getEditorLayer() { return m_levelEditorLayer; }

	void updateGameVariable(const char* gmV) {

		if (this->getGameVariable(gmV)) {
			GameManager::setGameVariable(gmV, false);
		}
		else {
			GameManager::setGameVariable(gmV, true);
		}
	}

    void fadeInMusic(std::string filename)
    {
        return reinterpret_cast<void(__fastcall*)(GameManager*, std::string)>(
            redecore::getBase() + 0x126AC0
            )(this, filename);
    }


	void reloadAll(bool switchingModes, bool toFullscreen, bool borderless, bool unused)
	{
		return reinterpret_cast<void(__fastcall*)(GameManager*, bool, bool, bool, bool)>(
			redecore::getBase() + 0x1807b0
			)(this, switchingModes, toFullscreen, borderless, unused);
	}

    void reloadAll()
    {
        return this->reloadAll(false, m_toFullscreen, false, false);
    }

	void unlockObject(int _id, UnlockType _icon)
	{
		return reinterpret_cast<void(__fastcall*)(GameManager*, int, UnlockType)>(
			redecore::getBase() + 0x174480
			    )(this, _id, _icon);
	}


    cocos2d::CCTexture2D* loadIcon(int id, int type, int p2) {
        return reinterpret_cast<cocos2d::CCTexture2D*(__fastcall*)(GameManager*, int, int, int)>(
            redecore::getBase() + 0x178e70
            )(this, id, type, p2);
    }


    //174480

    const char* iconNameValue(IconType var)
    {
        switch (var)
        {
        case IconType::Cube:
            return "i_";
        case IconType::Ship:
            return "ship_";
        case IconType::Ball:
            return "ball_";
        case IconType::Ufo:
            return "bird_";
        case IconType::Wave:
            return "dart_";
        case IconType::Robot:
            return "robot_";
        case IconType::Spider:
            return "spider_";
        case IconType::Swing:
            return "swing_";
        case IconType::Jetpack:
            return "jetpack_";
        case IconType::DeathEffect:
            return "death_";
        case IconType::Special:
            return "special_";
        case IconType::ShipFire:
            return "shipstreak_";
        default:
            return "item_";
        }
    }

    const char* objectIdentifier(UnlockType var)
    {
        switch (var)
        {
        case UnlockType::kUnknown:
            return " ";
        case UnlockType::kCube:
            return "icon_";
        case UnlockType::kColor1:
            return "color_";
        case UnlockType::kColor2:
            return "color2_";
        case UnlockType::kShip:
            return "ship_";
        case UnlockType::kBall:
            return "ball_";
        case UnlockType::kUfo:
            return "bird_";
        case UnlockType::kWave:
            return "dart_";
        case UnlockType::kRobot:
            return "robot_";
        case UnlockType::kSpider:
            return "spider_";
        case UnlockType::kSpecial:
            return "special_";
        case UnlockType::kDeathEffect:
            return "death_";
        case UnlockType::kItem:
            return "item_";
        case UnlockType::kSwing:
            return "swing_";
        case UnlockType::kJetPack:
            return "jetpack_";
        case UnlockType::kShipFire:
            return "shipstreak_";
        default:
            return " _";
        }
    }

    std::string iconKey(int id, IconType type)
    {
        return cocos2d::CCString::createWithFormat("%s%i", iconNameValue(type), id)->getCString();
    }

    void unlockIcon(int _id, IconType _type)
    {
        
        auto key = this->iconKey(_id, _type);
        auto obj = cocos2d::CCString::createWithFormat("%i", true);
        this->m_valueKeeper->setObject(obj, key);
        
    }

    void unlockColor(int _id, bool _secondary)
    {

        auto key = cocos2d::CCString::createWithFormat("%s%i_%i", "c", _secondary, _id)->getCString();
        auto obj = cocos2d::CCString::createWithFormat("%i", true);
        this->m_valueKeeper->setObject(obj, key);

    }

    void reportAchievementWithID(char const* identifier, int percentage, bool unk)
    {
        return reinterpret_cast<void(__fastcall*)(GameManager*, const char*, int, bool)>(
            redecore::getBase() + 0x175280
            )(this, identifier, percentage, unk);
    }

    std::string sheetNameForIcon(int p0, int p1)
    {
        //
        return reinterpret_cast<std::string(__fastcall*)(GameManager*, int, int)>(
            redecore::getBase() + 0x179460
            )(this, p0, p1);
    }

	void returnToLastScene(GJGameLevel* level);

    int getIconID(IconType type) {
        switch (type)
        {
        case IconType::Ship:
            return getPlayerShip();
        case IconType::Ball:
            return getPlayerBall();
        case IconType::Ufo:
            return getPlayerBird();
        case IconType::Wave:
            return getPlayerDart();
        case IconType::Robot:
            return getPlayerRobot();
        case IconType::Spider:
            return getPlayerSpider();
        case IconType::Swing:
            return getPlayerSwing();
        case IconType::Jetpack:
            return getPlayerJetpack();
        default:
            return getPlayerFrame();
        }
    }


    const char* getItemName(UnlockType item) {
        switch (item)
        {
        case UnlockType::kCube:
            return "Cube";
        case UnlockType::kColor1:
            return "Main Color";
        case UnlockType::kColor2:
            return "Secondary Color";
        case UnlockType::kShip:
            return "Ship";
        case UnlockType::kBall:
            return "Ball";
        case UnlockType::kUfo:
            return "Ufo";
        case UnlockType::kWave:
            return "Wave";
        case UnlockType::kRobot:
            return "Robot";
        case UnlockType::kSpider:
            return "Spider";
        case UnlockType::kSpecial:
            return "Trail";
        case UnlockType::kDeathEffect:
            return "Death effect";
        case UnlockType::kItem:
            return "Item";
        case UnlockType::kSwing:
            return "Swing";
        case UnlockType::kJetPack:
            return "Jetpack";
        case UnlockType::kShipFire:
            return "Ship Fire";
        default:
            return "Object";
        }
    }

    IconType UnlockToIcon(UnlockType var) {
        switch (var)
        {
        case UnlockType::kShip:
            return IconType::Ship;
        case UnlockType::kBall:
            return IconType::Ball;
        case UnlockType::kUfo:
            return IconType::Ufo;
        case UnlockType::kWave:
            return IconType::Wave;
        case UnlockType::kRobot:
            return IconType::Robot;
        case UnlockType::kSpider:
            return IconType::Spider;
        case UnlockType::kSpecial:
            return IconType::Special;
        case UnlockType::kDeathEffect:
            return IconType::DeathEffect;
        case UnlockType::kSwing:
            return IconType::Swing;
        case UnlockType::kJetPack:
            return IconType::Jetpack;
        case UnlockType::kShipFire:
            return IconType::ShipFire;
        default:
            return IconType::Cube;
        }
    }

    UnlockType IconToUnlock(IconType var) {
        switch (var)
        {
        case IconType::Ship:
            return UnlockType::kShip;
            break;
        case IconType::Ball:
            return UnlockType::kBall;
            break;
        case IconType::Ufo:
            return UnlockType::kUfo;
            break;
        case IconType::Wave:
            return UnlockType::kWave;
            break;
        case IconType::Robot:
            return UnlockType::kRobot;
            break;
        case IconType::Spider:
            return UnlockType::kSpider;
            break;
        case IconType::Swing:
            return UnlockType::kSwing;
            break;
        case IconType::Jetpack:
            return UnlockType::kJetPack;
            break;
        case IconType::DeathEffect:
            return UnlockType::kDeathEffect;
            break;
        case IconType::Special:
            return UnlockType::kSpecial;
            break;
        case IconType::ShipFire:
            return UnlockType::kShipFire;
            break;
        default:
            return UnlockType::kCube;
            break;
        }
    }

};

#define gm GameManager::sharedState()

;
