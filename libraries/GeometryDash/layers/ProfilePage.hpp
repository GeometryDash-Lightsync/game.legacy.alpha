#pragma once

#include <GDLib.h>

class ProfilePage : public FLAlertLayer
{
public:
    PAD(3)
    GJUserScore* m_score;
    int m_accountID;
    bool m_ownProfile;
    std::string m_profileKey;
    cocos2d::CCLabelBMFont* m_somethingWentWrong;
    cocos2d::CCLabelBMFont* m_usernameLabel;
    GJCommentListLayer* m_list;
    CCMenuItemSpriteExtra* m_rightArrow;
    CCMenuItemSpriteExtra* m_leftArrow;
    CCMenuItemSpriteExtra* m_followBtn;
    void* m_unk;
    cocos2d::CCArray* m_buttons;
    cocos2d::CCArray* m_arrayWithUsernameLabel;
    int m_itemCount;
    int m_pageStartIdx;
    int m_pageEndIdx;
    int m_page;
    LoadingCircle* m_circle;
    void* m_popupDelegate;
    CCMenuItemSpriteExtra* m_refreshBtn;


    /*
    2.200: 0x2E7270 (fastcall)
    */
    static ProfilePage* create(int accountID, bool idk) {
        return reinterpret_cast<ProfilePage * (__fastcall*)(
            int, bool
            )>(
                redecore::getBase() + 0x2E7270
                )(
                    accountID, idk
                    );
    }

    void onSettings(cocos2d::CCObject* sender) {
        reinterpret_cast<void(__fastcall*)(
            ProfilePage*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x3a1ee0)(this, sender);
    }
};
