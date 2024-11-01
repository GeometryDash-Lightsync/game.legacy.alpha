#pragma once

#include <GDLib.h>

class DialogObject : public cocos2d::CCObject {

protected:
    char pad_0x00[0x60]; // 0x00

    std::string m_content; // 0x32
    std::string m_title; // 0x56
    int type; // 0x80
    cocos2d::_ccColor3B color; // 9x84
    char pad_0x87[0x01]; // 0x87
    float m_unknown; // 0x88
    char pad_0x92[0x04]; // 0x92
    bool m_unknown_2; // 0x96
public:
    /**
    * @note[short] Windows: 0x3BE50
    * @note[short] Android
    */
    bool init(std::string p0, std::string p1, int p2, float p3, bool p4, cocos2d::ccColor3B p5)
    {
        return reinterpret_cast<bool(__fastcall*)(
            DialogObject*, std::string, std::string, int, float, bool, cocos2d::ccColor3B
            )>(
                redecore::getBase() + 0x3BE50
                )(
                    this, p0, p1, p2, p3, p4, p5
                    );
    }

    /**
     * @note[short] Windows: 0xcfb10
     * @note[short] Android
     */
    static DialogObject* create(std::string p0, std::string p1, int p2, float p3, bool p4, cocos2d::ccColor3B p5)
    {
        return reinterpret_cast<DialogObject * (__fastcall*)(
           std::string, std::string, int, float, bool, cocos2d::ccColor3B
            )>(
                redecore::getBase() + 0xcfb10
                )(
                    p0, p1, p2, p3, p4, p5
                    );
    }



    static DialogObject* createCustom(std::string title, std::string text, int type, float text_scale, bool is_unskippable, cocos2d::_ccColor3B textColor) {
        DialogObject* obj = new DialogObject();
        if (obj && obj->init(title, text, type, text_scale, is_unskippable, textColor))
        {
            obj->autorelease();
            return obj;
        }

        CC_SAFE_DELETE(obj);
        return nullptr;
    }

};