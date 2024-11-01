#pragma once

#include <GDLib.h>

class GJLevelList : public cocos2d::CCNode
{
    std::vector<int> m_levels;
    int m_listID;
    int m_listVersion;
    int m_downloads;
    int m_likes;
    int m_difficulty;
    int m_accountID;
    int m_folder;
    int m_listRevision;
    int m_listOrder;
    int m_original;
    int m_diamonds;
    int m_levelsToClaim;
    bool m_isEditable;
    bool m_unlisted;
    bool m_friendsOnly;
    bool m_uploaded;
    bool m_favorite;
    bool m_featured;
    bool m_k100;
    std::string m_creatorName;
    std::string m_listName;
    std::string m_unkString;
    std::string m_levelsString;
    std::string m_listDesc;
    int m_uploadDate;
    int m_updateDate;
    cocos2d::CCDictionary* m_k97;
    GJLevelType m_listType;
    int m_M_ID;
};