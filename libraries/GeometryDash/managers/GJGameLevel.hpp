#pragma once

#include <GDLib.h>

class GJGameLevel : public cocos2d::CCNode {
public:
    cocos2d::CCDictionary* m_lastBuildSave;   // 0xec
    int m_levelID_rand; // 0xf0
    int m_levelID_seed; // 0xf4 
    int m_levelID;      // 0xf8
    std::string m_levelName;       // 0xfc
    std::string m_levelDesc;       // 0x114
    std::string m_levelString;     // 0x12c
    std::string m_creatorName;     // 0x144
    std::string m_recordString;    // 0x15c
    std::string m_uploadDate; // 0x174
    std::string m_updateDate; // 0x18c
    std::string m_unkString1;
    std::string m_unkString2;
    cocos2d::CCPoint m_unkPoint;
    int m_userID_rand;     // 0x1a4
    int m_userID_seed;     // 0x1a8
    int m_userID;          // 0x1ac 0
    int m_accountID_rand;  // 0x1b0
    int m_accountID_seed;  // 0x1b4
    int m_accountID;       // 0x1b8 15
    int m_difficulty;
    int m_audioTrack;
    int m_songID;
    int m_levelRev;
    bool m_unlisted;
    bool m_friendsOnly;
    int m_objectCount_rand;// 0x1d0
    int m_objectCount_seed;// 0x1d4
    int m_objectCount;     // 0x1d8
    int m_levelIndex;
    int m_ratings;
    int m_ratingsSum;
    int m_downloads;
    bool m_isEditable;
    bool m_gauntletLevel;
    bool m_gauntletLevel2;
    int m_workingTime;
    int m_workingTime2;
    bool m_lowDetailMode;
    bool m_lowDetailModeToggled;
    bool m_k112;
    bool m_selected;
    bool m_localOrSaved;
    bool m_disableShake;
    int m_isVerified_rand; // 0x1fc
    int m_isVerified_seed; // 0x200
    bool m_isVerifiedRaw;
    bool m_isUploaded;
    bool m_hasBeenModified;
    int m_levelVersion;
    int m_gameVersion;
    int m_attempts_rand;   // 0x210
    int m_attempts_seed;   // 0x214
    int m_attempts;        // 0x218 attr
    int m_jumps_rand;      // 0x21c atts
    int m_jumps_seed;      // 0x220 att
    int m_jumps;           // 0x224 jumpr
    int m_clicks_rand;     // 0x228 jumps
    int m_clicks_seed;     // 0x22c jump
    int m_clicks;          // 0x230 clicksrand
    int m_attemptTime_rand;// 0x234 clicksseed
    int m_attemptTime_seed;// 0x238 clicks
    int m_attemptTime;     // 0x23c attrand
    int m_chk;             // 0x240 attseed
    bool m_isChkValid;     // 0x244 atttime
    bool m_isCompletionLegitimate; // 0x245 chk
    int m_normalPercent_rand;   // 0x248, yes, it is out of order ischkv
    int m_normalPercent_seed;  // 0x24c isCl
    int m_normalPercent;  // 0x250 np
    int m_orbCompletion_rand;  // 0x254 nps
    int m_orbCompletion_seed;  // 0x258 npr
    int m_orbCompletion;       // 0x25c ocr
    int m_newNormalPercent2_rand;  // 0x260 ocs
    int m_newNormalPercent2_seed;  // 0x264 oc
    int m_newNormalPercent2;       // 0x268 2r
    int m_practicePercent; // 0x26c 2s
    int m_likes;           // 0x270 695???? 2
    int m_dislikes;        // 0x274 0 //p percent
    int m_levelLength;     // 0x278 0 likes
    int m_featured;        // 0x27c 0 dislikes
    int m_isEpic;         // 0x280 0 0
    int m_levelFavorited; // 0x281 0
    int m_levelFolder;     // 0x284 0
    int m_dailyID_rand;    // 0x288
    int m_dailyID_seed;    // 0x28c
    int m_dailyID;         // 0x290
    int m_demon_rand;      // 0x294
    int m_demon_seed;      // 0x298
    int m_demon;           // 0x29c
    int m_demonDifficulty; // 0x2a0
    int m_stars_rand;      // 0x2a4
    int m_stars_seed;      // 0x2a8
    int m_stars;           // 0x2ac
    bool m_autoLevel;      // 0x2b0
    int m_coins;           // 0x2b4
    int m_coinsVerified_rand;  // 0x2b8
    int m_coinsVerified_seed;  // 0x2bc
    int m_coinsVerified;       // 0x2c0
    int m_password_rand;       // 0x2c4
    int m_password_seed;
    int m_originalLevel_rand;  // 0x2cc
    int m_originalLevel_seed;  // 0x2d0
    int m_originalLevel;       // 0x2d4
    bool m_twoPlayerMode;      // 0x2d8
    int m_failedPasswordAttempts;  // 0x2dc
    int m_firstCoinVerified_rand;  // 0x2e0
    int m_firstCoinVerified_seed;  // 0x2e4
    int m_firstCoinVerified;       // 0x2e8
    int m_secondCoinVerified_rand; // 0x2ec
    int m_secondCoinVerified_seed; // 0x2f0
    int m_secondCoinVerified;      // 0x2f4
    int m_thirdCoinVerified_rand;  // 0x2f8
    int m_thirdCoinVerified_seed;  // 0x2fc
    int m_thirdCoinVerified;   // 0x300
    int m_starsRequested;      // 0x304
    bool m_showedSongWarning;  // 0x308
    int m_starRatings;         // 0x30c
    int m_starRatingsSum;      // 0x310
    int m_maxStarRatings;      // 0x314
    int m_minStarRatings;      // 0x318
    int m_demonVotes;          // 0x31c
    int m_rateStars;           // 0x320
    int m_rateFeature;         // 0x324
    std::string m_rateUser;    // 0x328
    bool m_dontSave;           // 0x340
    bool m_levelNotDownloaded; // 0x341
    int m_requiredCoins;       // 0x344
    bool m_isUnlocked;         // 0x348
    cocos2d::CCPoint m_lastCameraPos; // 0x34c
    float m_lastEditorZoom;    // 0x354
    int m_lastBuildTab;        // 0x358
    int m_lastBuildPage;       // 0x35c
    int m_lastBuildGroupID;    // 0x360
    GJLevelType m_levelType;   // 0x364
    int m_m_ID;                // 0x368
    std::string m_tempName;    // 0x36c
    std::string m_capacityString;  // 0x384
    bool m_highObjectsEnabled;     // 0x39c
    std::string m_personalBests;   // 0x3a0
    int m_timestamp;
    int m_unkInt;
    std::string m_songIDs;
    std::string m_sfxIDs;
    int m_54;
    int m_bestTime;
    int m_bestPoints;
    int m_k111;
    std::string m_unkString3;
    std::string m_unkString4;


    /*
    2.200: 0x112540 (stdcall)
    */
    static GJGameLevel* create() {
        return reinterpret_cast<GJGameLevel * (__stdcall*)()>(
            redecore::getBase() + 0x1642d0
            )();
    }

    void setStars(int stars)
    {
        //m_stars = -stars;
        int seed = (rand() / 32767.0) * 1000;
        m_stars_rand = -seed;
        m_stars_seed = -stars + -seed;
    }

    bool isPlatformer()
    {
        return m_levelLength == 5;
    }

    int getAverageDifficulty() {
        return this->m_ratingsSum / this->m_ratings;
    }

    int getLevelDifficulty()
    {
        if (m_levelType == GJLevelType::Saved)
        {
            if (this->m_stars > 0)
            {
                switch (this->m_stars)
                {
                case 2: return 1;
                case 3: return 2;
                case 4:
                case 5: return 3;
                case 6:
                case 7: return 4;
                case 8:
                case 9: return 5;
                case 10:
                    switch (this->m_demonDifficulty)
                    {
                    case 3: return 7;
                    case 4: return 8;
                    case 5: return 9;
                    case 6: return 10;
                    default: return 6;
                    }
                default: return -1;
                }
            }
            else return getAverageDifficulty();

        }
        else return m_difficulty;
       
        
    }

    GJFeatureState getLevelFeatureState()
    {
        
        switch (m_isEpic)
        {
        case 1: return GJFeatureState::Epic;
        case 2: return GJFeatureState::Legendary;
        case 3: return GJFeatureState::Mythic;
        case 4: return GJFeatureState::Divine;
        }
        if (m_featured > 0) return GJFeatureState::Featured;

        return GJFeatureState::None;
    }

};