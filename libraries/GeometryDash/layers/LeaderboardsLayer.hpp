#pragma once
#include <GDLib.h>
class LeaderboardsLayer : public cocos2d::CCLayer, public FLAlertLayerProtocol {
public:
    void* unk0;
    void* unk1;
    GJListLayer* m_list;
    cocos2d::CCArray* m_userScores;
    LeaderboardState m_state;
    CCMenuItemToggler* m_topBtn;
    CCMenuItemToggler* m_globalBtn;
    CCMenuItemToggler* m_creatorsBtn;
    CCMenuItemToggler* m_friendsBtn;
    LoadingCircle* m_circle;
    TextArea* m_noInternet;
    cocos2d::CCArray* m_tabs;


    void refreshTabs() {
        reinterpret_cast<void(__fastcall*)(
            LeaderboardsLayer*
            )>(redecore::getBase() + 0x2afce0)(this);
    }

    void toggleTabButtons() {
        reinterpret_cast<void(__fastcall*)(
            LeaderboardsLayer*
            )>(redecore::getBase() + 0x2b0060)(this);
    }

    void selectLeaderboard(LeaderboardState p0)
    {
        reinterpret_cast<void(__fastcall*)(
            LeaderboardsLayer*, LeaderboardState
            )>(redecore::getBase() + 0x2afe10)(this, p0);
    }

    void FLAlert_Clicked(FLAlertLayer*, bool btn2)
    {
        if (btn2)
            cocos2d::CCApplication::sharedApplication()
            ->openURL("https://www.robtopgames.com/files/GDLeaderboards.pdf");
    }
    /*
    void FLAlert_Clicked(FLAlertLayer* p0, bool p1)
    {
        reinterpret_cast<void(__fastcall*)(
            LeaderboardsLayer*, FLAlertLayer*, bool
            )>(redecore::getBase() + 0x2b0f00)(this, p0, p1);
    }*/

    void onUpdateLeaderboards(CCObject* sender)
    {
        auto lb = (LeaderboardState)sender->getTag();
        this->selectLeaderboard(lb);
    }
};