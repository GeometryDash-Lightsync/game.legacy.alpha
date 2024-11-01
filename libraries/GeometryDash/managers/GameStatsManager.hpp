#pragma once

#include <GDLib.h>

class GameStatsManager : cocos2d::CCNode
{
public:
    bool m_usePlayerStatsCCDictionary;
    cocos2d::CCString* m_trueString;
    cocos2d::CCDictionary* m_allStoreItems;
    cocos2d::CCDictionary* m_storeItems;
    cocos2d::CCDictionary* m_allTreasureRoomChests;
    cocos2d::CCDictionary* m_allTreasureRoomChestItems;
    cocos2d::CCDictionary* m_allSpecialChests;
    cocos2d::CCDictionary* m_allSpecialChestItems;
    std::unordered_map<int, std::string> m_specialRewardDescriptions;
    std::unordered_map<int, std::string> m_createSpecialChestItemsMap;
    cocos2d::CCDictionary* m_specialChestsLite;
    cocos2d::CCArray* m_storeItemArray;
    cocos2d::CCDictionary* m_rewardItems;
    cocos2d::CCDictionary* m_dailyChests;
    cocos2d::CCDictionary* m_worldAdvertChests;
    cocos2d::CCDictionary* m_activeChallenges;
    cocos2d::CCDictionary* m_upcomingChallenges;
    double m_challengeTime;
    cocos2d::CCDictionary* m_playerStats;
    std::unordered_map<int, int> m_playerStatsRandMap;
    std::unordered_map<int, int> m_playerStatsSeedMap;
    cocos2d::CCDictionary* m_completedLevels;
    cocos2d::CCDictionary* m_verifiedUserCoins;
    cocos2d::CCDictionary* m_pendingUserCoins;
    cocos2d::CCDictionary* m_purchasedItems;
    cocos2d::CCDictionary* m_onlineCurrencyScores;
    cocos2d::CCDictionary* m_mainCurrencyScores;
    cocos2d::CCDictionary* m_gauntletCurrencyScores;
    cocos2d::CCDictionary* m_timelyCurrencyScores;
    cocos2d::CCDictionary* m_onlineStars;
    cocos2d::CCDictionary* m_timelyStars;
    cocos2d::CCDictionary* m_gauntletDiamondScores;
    cocos2d::CCDictionary* m_timelyDiamondScores;
    cocos2d::CCDictionary* m_unusedCurrencyAwardDict;
    cocos2d::CCDictionary* m_challengeDiamonds;
    cocos2d::CCDictionary* m_completedMappacks;
    cocos2d::CCDictionary* m_completedLists;
    cocos2d::CCDictionary* m_weeklyChest;
    cocos2d::CCDictionary* m_treasureRoomChests;
    int m_bonusKeySeed;
    int m_bonusKeyRand;
    int m_bonusKey;
    cocos2d::CCDictionary* m_miscChests;
    cocos2d::CCDictionary* m_enabledItems;
    bool m_unkBoolIncrementStat;
    cocos2d::CCDictionary* m_unkDict;
    cocos2d::CCDictionary* m_unlockedItems;
    std::map<int, UnlockType> m_accountIDForIcon;
    std::map<int, std::string> m_usernameForAccountID;
    bool m_GS29;
    int m_activePath;

	static GameStatsManager* sharedState() {
		return reinterpret_cast<GameStatsManager * (__stdcall*)()>(
			redecore::getBase() + 0x1c6e60
			)();
	}
	/**
	* Adds an item in to a specific shop
	*
	* Price cant be lower than 500 in the case of the orbs
	* For avoid ID issues use bigger article IDs
	*
	*/
	void addStoreItem(int articleID, int ID, UnlockType itemType, int price, int shop) {
		reinterpret_cast<void(__fastcall*)(
			GameStatsManager*, int, int, UnlockType, int, int
			)>(redecore::getBase() + 0x1ca0b0)(this, articleID, ID, itemType, price, shop);
	}

	/**
	* Returns a boolean var if the item is unlocked or not.
	*/
	bool isItemUnlocked(UnlockType type, int id) {
		return reinterpret_cast<bool(__fastcall*)(
			GameStatsManager*, UnlockType, int
			)>(
				redecore::getBase() + 0x1dabe0
				)(
					this, type, id
					);
	}

    bool isStoreItemUnlocked(int id) {
        return reinterpret_cast<bool(__fastcall*)(
            GameStatsManager*, int
            )>(
                redecore::getBase() + 0x1dec10
                )(
                    this, id
                    );
    }

    //
    GJChallengeItem* getChallenge(int id)
    {
        return reinterpret_cast<GJChallengeItem*(__fastcall*)(
            GameStatsManager*, int
            )>(
                redecore::getBase() + 0x1d76f0
                )(
                    this, id
                    );
    }


    int getCollectedCoinsForLevel(GJGameLevel* p0)
    {
        return reinterpret_cast<int(__fastcall*)(
            GameStatsManager*, GJGameLevel*
            )>(
                redecore::getBase() + 0x1d37d0
                )(
                    this, p0
                    );
    }
};
