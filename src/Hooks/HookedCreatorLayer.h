#include "../lightsync.h"



bool(__fastcall* CreatorLayer_init)(CreatorLayer*);

bool __fastcall CreatorLayer_init_H(CreatorLayer* _this) {
    if (!CreatorLayer_init(_this)) return false;

    auto size = ccDir->getWinSize();

    auto menu = reinterpret_cast<CCNode*>(_this->getChildren()->objectAtIndex(1));

        for (int i = 0; i < menu->getChildrenCount() - 2; i++) {
        reinterpret_cast<CCNode*>(menu->getChildren()->objectAtIndex(i))->removeFromParentAndCleanup(true);
    }

    /* bye bye background :D*/
    auto oldbg = reinterpret_cast<CCNode*>(_this->getChildren()->objectAtIndex(0));
    oldbg->setVisible(false);


    auto background = BackgroundSprite::createStandarBackground({66, 25, 36});
    background->setTag(1000);

    _this->addChild(background);
    return true;
}