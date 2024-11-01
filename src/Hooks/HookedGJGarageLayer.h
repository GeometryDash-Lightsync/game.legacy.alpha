#include "../lightsync.h"

bool(__fastcall* GJGarageLayer_init)(CCLayer*);
bool __fastcall GJGarageLayer_init_H(CCLayer* _this) {
    if (GJGarageLayer_init(_this)) return false;


    /*  background  */
    auto background = reinterpret_cast<CCSprite*>(_this->getChildren()->objectAtIndex(0));
    background->setColor(Utils::grayScaleColor(35));

    /* cosmetics */

    auto menu = CCMenu::create();
    menu->setPosition(CCPointZero);

    auto icon = CCSprite::createWithSpriteFrameName("GJ_cosmeticIcon_001.png");
    icon->setScale(.7f);

    auto btn = CCMenuItemSpriteExtra::create(
        icon,
        _this,
        nullptr
    );

    btn->setPosition(30, 30);
    
    menu->addChild(btn);

    _this->addChild(menu, 15);

    return true;
}