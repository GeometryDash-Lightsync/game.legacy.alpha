#include <GDLib.h>


class GameLevelManager : public cocos2d::CCNode {
public:
    PAD(16);
    cocos2d::CCDictionary* m_mainLevels;
    cocos2d::CCDictionary* m_searchFilters;
    cocos2d::CCDictionary* m_onlineLevels;
    cocos2d::CCDictionary* m_unkDict;
    cocos2d::CCDictionary* m_followedCreators;
    cocos2d::CCDictionary* m_favoriteLists;
    cocos2d::CCDictionary* m_downloadedLevels;
    cocos2d::CCDictionary* m_likedLevels;
    cocos2d::CCDictionary* m_ratedLevels;
    cocos2d::CCDictionary* m_ratedDemons;
    cocos2d::CCDictionary* m_reportedLevels;
    cocos2d::CCDictionary* m_onlineFolders;
    cocos2d::CCDictionary* m_localLevelsFolders;
    cocos2d::CCDictionary* m_dailyLevels;
    int m_dailyTimeLeft;
    int m_dailyID;
    int m_dailyIDUnk;
    int m_weeklyTimeLeft;
    int m_weeklyID;
    int m_weeklyIDUnk;
    int m_eventTimeLeft;
    int m_eventID;
    int m_eventIDUnk;
    cocos2d::CCDictionary* m_gauntletLevels;
    std::map<std::string, bool> m_availableFilters;
    cocos2d::CCDictionary* m_timerDict;
    cocos2d::CCDictionary* m_knownUsers;
    cocos2d::CCDictionary* m_accountIDtoUserIDDict;
    cocos2d::CCDictionary* m_userIDtoAccountIDDict;
    cocos2d::CCDictionary* m_storedLevels;
    cocos2d::CCDictionary* m_pageInfo;
    cocos2d::CCDictionary* m_unkDict20;
    cocos2d::CCDictionary* m_savedPacks;
    cocos2d::CCDictionary* m_savedGauntlets;
    cocos2d::CCDictionary* m_downloadObjects;
    cocos2d::CCDictionary* m_friendReqAndUserBlocks;
    cocos2d::CCDictionary* m_storedUserInfo;
    cocos2d::CCDictionary* m_friendRequests;
    cocos2d::CCDictionary* m_userMessages;
    cocos2d::CCDictionary* m_userReplies;
    std::string m_searchSceneStr;
    std::string m_searchType9Str;
    LeaderboardState m_leaderboardState;
    bool m_unkEditLevelLayerOnBack;
    void* m_levelManagerDelegate;
    void* m_levelDownloadDelegate;
    void* m_levelCommentDelegate;
    void* m_commentUploadDelegate;
    void* m_levelUploadDelegate;
    void* m_listUploadDelegate;
    void* m_levelUpdateDelegate;
    void* m_leaderboardManagerDelegate;
    void* m_levelDeleteDelegate;
    void* m_levelListDeleteDelegate;
    void* m_userInfoDelegate;
    UploadPopupDelegate* m_uploadPopupDelegate;
    void* m_userListDelegate;
    void* m_friendRequestDelegate;
    void* m_messageListDelegate;
    void* m_downloadMessageDelegate;
    void* m_uploadMessageDelegate;
    void* m_GJRewardDelegate;
    void* m_GJChallengeDelegate;
    void* m_GJDailyLevelDelegate;
    void* m_onlineListDelegate;
    int m_unkDownload;
    PAD(4);
    std::string m_unkStr3;
    cocos2d::CCString* m_unkStr4;

	static GameLevelManager* sharedState()
	{
		return reinterpret_cast<GameLevelManager * (__thiscall*)()>(
			redecore::getBase() + 0x13e1e0
			)();
	}

	bool getBoolForKey(char const* key)
	{
		return m_searchFilters->valueForKey(key)->boolValue();
	}

    void setBoolForKey(bool value, const char* key)
    {
        auto str = cocos2d::CCString::createWithFormat("%i", value);

        m_searchFilters->setObject(str, key);
    }

    GJGameLevel* getMainLevel(int levelID, bool dontGetLevelString)
    {
        return reinterpret_cast<GJGameLevel * (__fastcall*)(GameLevelManager*, int, bool)>(
            redecore::getBase() + 0x13fa40
            )(this, levelID, dontGetLevelString);
    }
};