#pragma once

#include <GDLib.h>

class DialogLayer : public cocos2d::CCLayerColor, public TextAreaDelegate
{
public:

    static DialogLayer* create(DialogObject* p0, int p1) {};

    static DialogLayer* createDialogLayer(DialogObject* p0, cocos2d::CCArray* p1, int p2) {
        auto ret = reinterpret_cast<DialogLayer*(__fastcall*)(DialogObject*, cocos2d::CCArray*, int)>
            (redecore::getBase() + 0xcfcd0)
            (p0, p1, p2);
        //__asm add esp, 0x20
        return ret;
    };

    /**
    * 2.200: 0x9A9D0 (thiscall)
    */
    void animateIn(DialogAnimationType p0) {

    }

    void animateInRandomSide() {
        reinterpret_cast<void(__fastcall*)(
            DialogLayer*
            )>(redecore::getBase() + 0xD09B0)(this);
    }
};