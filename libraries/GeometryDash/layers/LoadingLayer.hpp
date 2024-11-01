#include <GDLib.h>

class LoadingLayer : public cocos2d::CCLayer
{
public:
    bool m_unknown;
    bool m_unknown2;
    int m_loadStep;
    cocos2d::CCLabelBMFont* m_caption;
    TextArea* m_textArea;
    cocos2d::CCSprite* m_sliderBar;
    float m_sliderGrooveXPos;
    float m_sliderGrooveHeight;
    bool m_fromRefresh;

    void loadAssets()
    {
        reinterpret_cast<void(__fastcall*)(
            LoadingLayer*
            )>(redecore::getBase() + 0x30e400)(this);
    }
};