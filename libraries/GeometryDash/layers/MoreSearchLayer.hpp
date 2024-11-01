#include <GDLib.h>

class MoreSearchLayer : public FLAlertLayer
{
public:
    cocos2d::CCLabelBMFont* m_audioTrackName;
    CCMenuItemSpriteExtra* m_songLeftBtn;
    CCMenuItemSpriteExtra* m_songRightBtn;
    CCMenuItemSpriteExtra* m_normalBtn;
    CCMenuItemSpriteExtra* m_customBtn;
    void* m_enterSongID; //TextInputNode*
    cocos2d::CCArray* m_commonSongNodes;
    cocos2d::CCArray* m_normalSongNodes;
    cocos2d::CCArray* m_customSongNodes;

    bool init();

    void createToggleButton(std::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4)
    {
        return reinterpret_cast<void(__fastcall*)
            (MoreSearchLayer*, std::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint)>
            (redecore::getBase() + 0x2f6c50)
            (this, p0, p1, p2, p3, p4);
    }

    void onEpic(cocos2d::CCObject* sender);

    void onFeatured(cocos2d::CCObject* sender);

    void onLegendary(cocos2d::CCObject* sender);

    void onMythic(cocos2d::CCObject* sender);

	//Custom Filter
	void onDivine(cocos2d::CCObject*)
	{
        /*
		bool selected = GameLevelManager::sharedState()->getBoolForKey("divine_filter") ^ 1;
		GameLevelManager::sharedState()->setBoolForKey(selected, "divine_filter");*/
	}
};