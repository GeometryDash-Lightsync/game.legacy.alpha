#include "../lightsync.h"

bool(__fastcall *MenuLayer_init)(MenuLayerExt *);
bool __fastcall MenuLayer_init_H(MenuLayerExt *_this)
{

    if (!MenuLayer_init(_this))
        return false;

    /*hide the menu on start*/
    _this->setVisible(Lightsync->m_gameInit);

    auto size = ccDir->getWinSize();

    /* icons */

    _this->m_menuGameLayer->setPositionY(-30);

    auto glChildren = _this->m_menuGameLayer->getChildren();

    auto glBackground = reinterpret_cast<CCNode *>(glChildren->objectAtIndex(0));
    glBackground->setVisible(false);

    auto glground = reinterpret_cast<CCNode *>(glChildren->objectAtIndex(1));
    glground->setVisible(false);

    auto glplayer = reinterpret_cast<CCNode *>(glChildren->objectAtIndex(1));

    if (!gm->getGameVariable("Ls-ShowIcons"))
    {

        //_this->m_menuGameLayer->setPositionY(size.height * 5);
    }

    /*   hide other buttons  */
    for (int i = 1; i < _this->getChildrenCount(); i++)
    {

        reinterpret_cast<CCNode *>(_this->getChildren()->objectAtIndex(i))->setVisible(false);
    }

    /* new menu */

    auto background = BackgroundSprite::create("GJ_Gradient03.png");
    background->setColor(Utils::grayScaleColor(25));
    background->setTag(1000);
    

    background->setAnchorPoint({.5f, .5f});
    background->setPosition(size / 2);
    background->setScaleY(background->getScaleY() * 1.2f);

    _this->addChild(background, -1);

    auto mainMenu = CCMenu::create();
    mainMenu->setPosition(CCPointZero);
    mainMenu->setTag(1001);

    /* icons */

    auto icon1 = CCSprite::createWithSpriteFrameName("btnIcon_01.png");
    icon1->setScale(.85f);

    auto icon2 = CCSprite::createWithSpriteFrameName("btnIcon_02.png");
    icon2->setScale(.85f);

    auto icon3 = CCSprite::createWithSpriteFrameName("btnIcon_03.png");
    icon3->setScale(.85f);

    /* buttons */

    /* play Button */


    auto playBtn = CCMenuItemSpriteExtra::create(

        LSButtonSprite::createMainBtn(icon1, "Play"),
        _this,
        menu_selector(MenuLayer::onPlay)
    );


    playBtn->setPosition( size / 2);

    mainMenu->addChild(playBtn);

    /* garage Button */

    auto garageBtn = CCMenuItemSpriteExtra::create(

        LSButtonSprite::createMainBtn(icon2, "Customize"),
        _this,
        menu_selector(MenuLayer::onGarage)
    );

    garageBtn->setPosition({120, size.height / 2 - 10});

    

    auto iconDot = CCSprite::create("aCircle_2.png");
    iconDot->setColor({255, 0, 75});

    auto btnChild = (LSButtonSprite *)garageBtn->getChildren()->objectAtIndex(0);

    iconDot->setPosition(btnChild->getContentSize() - CCSize{5, 5});

    garageBtn->addChild(iconDot);


    mainMenu->addChild(garageBtn);



    /* creator Button */

    auto creatorBtn = CCMenuItemSpriteExtra::create(

        LSButtonSprite::createMainBtn(icon3, "Online"),
        _this,
        menu_selector(MenuLayer::onCreator)
    );

    creatorBtn->setPosition({size.width - 120, size.height / 2 - 10});

    mainMenu->addChild(creatorBtn);

    mainMenu->runAction(
        CCRepeatForever::create(
            CCSequence::createWithTwoActions(
                CCEaseInOut::create(CCMoveTo::create(2.0f, {0, 5}), 1.8f),
                CCEaseInOut::create(CCMoveTo::create(2.0f, {0, 0}), 1.8f)
            )
        )
    );

    _this->addChild(mainMenu);

    auto exitMenu = CCMenu::create();
    exitMenu->setPosition(0, 0);
    exitMenu->setTag(1002);

    auto exitSpr = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
    exitSpr->setScale(.7f);
    exitSpr->setBlendFunc({ GL_ONE, GL_ONE });

    auto exitBtn = CCMenuItemSpriteExtra::create(

        exitSpr,
        _this,
        menu_selector(MenuLayer::onEndGame)
    );

    exitBtn->setPosition({ size.width - 20, size.height - 25 });
    exitMenu->addChild(exitBtn);


    _this->addChild(exitMenu);

    auto main = MainMenuLayer::create();

    _this->addChild(main, 15);

    Lightsync->m_mainLayer = main;
    Lightsync->m_menuLayer = _this;

    if (!Lightsync->m_gameInit) {
        LSIconDataManager::sharedState()->removeSpecialChestRewards();
        mainMenu->setVisible(false);
        exitMenu->setVisible(false);

        Lightsync->m_gameInit = true;
        

    
        _this->runAction(
            CCCallFunc::create(_this, callfunc_selector(HomePage::addToScene))
        );
    }

    if (!Lightsync->isConnectetToInternet()) _this->runAction(
        CCCallFunc::create(_this, callfunc_selector(LightsyncManager::noWifiAlert))
    );
    
    return true;
}