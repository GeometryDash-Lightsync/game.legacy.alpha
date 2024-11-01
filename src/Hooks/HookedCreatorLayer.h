#include "../lightsync.hpp"



bool(__fastcall* CreatorLayer_init)(CreatorLayerExt*);

bool __fastcall CreatorLayer_init_H(CreatorLayerExt* _this) {
    if (!CreatorLayer_init(_this)) return false;

    auto size = ccDir->getWinSize();

    auto menu = reinterpret_cast<CCNode*>(_this->getChildren()->objectAtIndex(1));

        for (int i = 0; i < menu->getChildrenCount() - 2; i++) {
        reinterpret_cast<CCNode*>(menu->getChildren()->objectAtIndex(i))->removeFromParentAndCleanup(true);
    }

    /* bye bye background :D*/
    auto oldbg = reinterpret_cast<CCNode*>(_this->getChildren()->objectAtIndex(0));
    oldbg->setVisible(false);



    _this->m_background = BackgroundSprite::createStandarBackground({66, 25, 36});
    _this->addChild(_this->m_background);
    return true;
}