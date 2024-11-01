#pragma once

#include <GDLib.h>

class ButtonSprite : public cocos2d::CCSprite {
public:
    int m_mode;
    float m_width;
    float m_unkFloat;
    float m_scale;
    float m_height;
    bool m_absolute;
    cocos2d::CCLabelBMFont* m_label;
    cocos2d::CCSprite* m_subSprite;
    cocos2d::CCSprite* m_subBGSprite;
    cocos2d::extension::CCScale9Sprite* m_BGSprite;
    cocos2d::CCPoint m_textOffset;
    cocos2d::CCPoint m_spritePosition;
    std::string m_caption;

    static ButtonSprite* create(cocos2d::CCSprite* topSprite, int width, bool absolute, float height, const char* texture, float scale)
    {
        return ButtonSprite::create(topSprite, width, 0, height, scale, absolute, texture, true);

    }

    static ButtonSprite* create(const char* caption, int width, bool absolute, const char* font, const char* texture, float height, float scale) {

        return ButtonSprite::create(caption, width, 0, scale, absolute, font, texture, height);

    }

    static ButtonSprite* create(char const* caption) {

        return ButtonSprite::create(caption, 0, false, "goldFont.fnt", "GJ_button_01.png", .0f, 1.f);

    }

    static ButtonSprite* create(char const* caption, const char* font, const char* texture) {

        return ButtonSprite::create(caption, 0, false, font, texture, .0f, 1.f);

    }

    static ButtonSprite* create(char const* caption, const char* font, const char* texture, float scale) {

        return ButtonSprite::create(caption, 0, false, font, texture, .0f, scale);

    }

    static ButtonSprite* create(char const* caption, float scale) {

        return ButtonSprite::create(caption, 0, false, "goldFont.fnt", "GJ_button_01.png", .0f, scale);

    }

    static ButtonSprite* create(char const* caption, int width, int p2, float scale, bool absolute, char const* font, char const* bg, float height)
    {
        return reinterpret_cast<ButtonSprite * (__thiscall*)(
           const char*, int, int, float, bool, const char*, const char*, float
            )>(redecore::getBase() + 0x3e2d0)(caption, width, p2, scale, absolute, font, bg, height);
    }

    static ButtonSprite* create(cocos2d::CCSprite* topSprite, int width, int unused, float height, float scale, bool absolute, char const* bgSprite, bool noScaleSpriteForBG)
    {
        return reinterpret_cast<ButtonSprite * (__thiscall*)(
            cocos2d::CCSprite*, int, int, float, float, bool, char const*, bool
            )>(redecore::getBase() + 0x3dfc0)(topSprite, width, unused, height, scale, absolute, bgSprite, noScaleSpriteForBG);
    }

    bool init(char const* p0, int p1, int p2, float p3, bool p4, char const* p5, char const* p6, float p7)
    {

    }

    bool init(cocos2d::CCSprite* topSprite, int width, int unused, float height, float scale, bool absolute, char const* bgSprite, bool noScaleSpriteForBG)
    {

    }

    void setColor(const cocos2d::ccColor3B& color)
    {

        if (m_label) m_label->setColor(color);

        if (m_subSprite) m_subSprite->setColor(color);

        if (m_subBGSprite) m_subBGSprite->setColor(color);

        if (m_BGSprite) m_BGSprite->setColor(color);
    }

    void setString(const char* string)
    {
        return reinterpret_cast<void(__fastcall*)(
            ButtonSprite*, const char*
            )>(redecore::getBase() + 0x3ec60)(this, string);
    }

    void updateSpriteBGSize() //0x3e7e0
    {
        return reinterpret_cast<void(__fastcall*)(
            ButtonSprite*
            )>(redecore::getBase() + 0x3e7e0)(this);
    }

    void updateString(const char* string)
    {
        if (m_label) m_label->setString(string);
        //this->updateSpriteBGSize();
    }
};