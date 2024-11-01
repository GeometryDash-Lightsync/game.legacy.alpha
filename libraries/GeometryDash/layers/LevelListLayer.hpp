#pragma once
#include <GDLib.h>
class LevelListLayer : public LevelBrowserLayer, public TextInputDelegate {
public:
    void* unk0;
    void* unk1;
    cocos2d::CCMenu* m_buttonMenu;
    std::string m_searchKey1;
    GJLevelList* m_levelList;
    std::string m_searchKey2;
    CCMenuItemSpriteExtra* m_likeButton;
    bool m_exiting;
    CCTextInputNode* m_titleInput;
    int m_editMode;
    cocos2d::CCArray* m_objects;
    cocos2d::CCSprite* m_diffSprite;
    cocos2d::CCSprite* m_featureSprite;
    cocos2d::CCPoint m_rewardPosition;
    bool m_exited;
};