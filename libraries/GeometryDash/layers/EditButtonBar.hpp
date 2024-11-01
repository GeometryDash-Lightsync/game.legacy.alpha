#include <GDLib.h>

class EditButtonBar : public cocos2d::CCNode {
public:
    cocos2d::CCPoint m_position;
    int m_unknown;
    bool m_unknownBool;
    cocos2d::CCArray* m_buttonArray;
    cocos2d::CCLayer* m_scrollLayer;
    cocos2d::CCArray* m_pagesArray;

    void loadFromItems(cocos2d::CCArray* p0, int p1, int p2, bool p3)
    {
        return reinterpret_cast<void(__fastcall*)(
            EditButtonBar*, cocos2d::CCArray*, int, int, bool
            )>(redecore::getBase() + 0xd0e10)(this, p0, p1, p2, p3);
    }

    void reloadItems(int rowCount, int columnCount)
    {
        if (m_buttonArray)
            this->loadFromItems(m_buttonArray, rowCount, columnCount, false);
    }

};