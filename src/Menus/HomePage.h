#pragma once
#include "../lightsync.h"

class HomePage : public CCLayer, FLAlertLayerProtocol {
public:
    CCLayer* m_mainLayer;
    CCMenu* m_mainMenu;

    CCLabelBMFont* m_smallLabel;
    CCLabelBMFont* m_infoLabel;

    bool m_canPressKey;
    bool m_updatePending;

    bool init() {


        /* enabling keypad & mouse events */
        this->setTouchEnabled(true);
        this->setKeypadEnabled(true);
        this->setTouchPriority(500);
        m_canPressKey = true;
        /*    background    */
        
        auto bg = CCLayerColor::create({ Utils::grayScaleColor(20, 255) });
        this->addChild(bg);

        auto size = ccDir->getWinSize();


        /* setitng up main class members  */

        m_mainLayer = CCLayer::create();
        this->addChild(m_mainLayer);


        m_mainMenu = CCMenu::create();
        m_mainMenu->setPosition(CCPointZero);

        /*  Welcome Label   */

        std::string wlc = "Welcome";
        if (Lightsync->hasAccount()) wlc += " back";
        
        std::string welcomeString = fmt::format("{}, <cr>{}</c>!", wlc, gm->m_playerName);

        auto welcomeLabel = TextArea::create(welcomeString.c_str(), "bigFont.fnt",  320, { .5f, .5f }, 20);
        welcomeLabel->setScale(.8f);

        welcomeLabel->setPosition({ size.width / 2, size.height / 2 + 60 });

        m_mainLayer->addChild(welcomeLabel);


        /*   Icon Preview   */

        auto icon = SimplePlayer::create(0);

        if (gm->getGameVariable("Ls-CubeOnPage")) 

            icon->updatePlayerFrame(gm->getIconID(gm->getPlayerIconType()), gm->getPlayerIconType());
        
        icon->setPosition({ size.width / 2, size.height / 2 + 15 });


        icon->setColor(Lightsync->colorForIdx(gm->getPlayerColor())); //
        icon->setSecondColor(Lightsync->colorForIdx(gm->getPlayerColor2()));
        icon->setGlowOutline(gm->getPlayerGlow());
        icon->enableCustomGlowColor(Lightsync->colorForIdx(gm->getPlayerColorGlow()));

        m_mainLayer->addChild(icon);

        /*    key label  */

        m_infoLabel = CCLabelBMFont::create("Press any key screen to start", "chatFont.fnt");
        m_infoLabel->setScale(.7f);

        m_infoLabel->setPosition({ size.width / 2, size.height / 2 - 45 });
        m_infoLabel->setOpacity(0);

        m_mainLayer->addChild(m_infoLabel);

        m_infoLabel->runAction(
            CCRepeatForever::create(
                CCSequence::createWithTwoActions(
                    CCFadeTo::create(1, 255),
                    CCFadeTo::create(1, 0)
                )
            )
        );

        /*  Popups */
        
        if ((Lightsync->m_needUpdate || Lightsync->m_updateCallbackResponse != 0) && Lightsync->isConnectetToInternet())
            this->runAction(CCCallFunc::create(this, callfunc_selector(HomePage::showUpdatePopup)));

        if (Lightsync->m_screenEnabled) this->runAction(CCCallFunc::create(this, callfunc_selector(HomePage::showMofiedPopup)));


        std::ifstream file;

        file.open("hackpro.dll");
		if (file) runAction(CCCallFunc::create(this, callfunc_selector(HomePage::showCheatScreen)));
		file.close();

		file.open("hackproldr.dll");
		if (file) runAction(CCCallFunc::create(this, callfunc_selector(HomePage::showCheatScreen)));
		file.close();

        return true;
    }

    void addToScene() {

        ccDir->getRunningScene()->addChild(HomePage::create(), 105);
    }

    void keyDown(cocos2d::enumKeyCodes key) {

        if (key != enumKeyCodes::KEY_Escape && m_canPressKey) this->startGame();
    }

    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override {
        cocos2d::CCPoint location = touch->getLocation();
        fmt::print("x {} y {}\n", location.x, location.y);

        //cocos2d::CCLog("Mouse click or touch began at x: %f, y: %f", location.x, location.y);
        return true;
    }

    void startGame() {
        m_canPressKey = false;

        m_infoLabel->setString("Enjoy!");
        m_infoLabel->stopAllActions();
        m_infoLabel->setOpacity(255);

        m_mainLayer->runAction(
	        CCEaseBackIn::create(
		        CCScaleTo::create(1.7f, .0f)
	        )
        );

        auto blackScreen = CCLayerColor::create(Utils::grayScaleColor(0, 0));
        this->addChild(blackScreen);

        blackScreen->runAction(
	    CCSequence::create(
		    CCFadeTo::create(1.7f, 255),
		    CCCallFunc::create(this, callfunc_selector(HomePage::prepareMenuLayer)),
		    CCFadeTo::create(.5f, 0),
		    NULL
	        )
        );

        this->runAction(
			CCSequence::createWithTwoActions(
				CCDelayTime::create(3),
				CCCallFunc::create(this, callfunc_selector(HomePage::removeLayer))
			)
		);
    }

    void prepareMenuLayer() {
        Lightsync->m_menuLayer->setVisible(true);

        auto ext = (MenuLayerExt*)Lightsync->m_menuLayer;


        /*  scaling the bg */
        reinterpret_cast<CCNode*>(ext->getChildByTag(1000))->runAction(CCScaleTo::create(0, 2));


		this->runAction(
			CCSequence::createWithTwoActions(
				CCDelayTime::create(.25f),
				CCCallFunc::create(this, callfunc_selector(HomePage::runMenulayerEnterAnimation))
			)
		);

        /* hidding the menu */
		for (int i = 0; i < this->getChildrenCount() - 1; i++) {
			reinterpret_cast<CCNode*>(this->getChildren()->objectAtIndex(i))->setVisible(false);
		}

    }

    void showMofiedPopup() {
        FLAlertLayer::create(
	        HomePage::create(),
	        "Oopsie...",
	        "It seems that some important files are corrupted or had been modified.\n"
	        "Please open the repair assistant and relaunch the game.",
	        "OK", nullptr
        )->show(); 
    }

    void showCheatScreen()	{
		FLAlertLayer::create(
			HomePage::create(),
			"Get out of here cheater!",
			"It seems we detected one or more files related to <cr>cheats</c> on the game,"
			"please delete these files, otherwise you will not be able to play :)",
			"OK", nullptr
		)->show();
	}

    void showUpdatePopup() {

        const char* title = "Update requiered";
        std::string desc = fmt::format("<cy>A new update has been released!</c>\n"
        "Please update your game in the launcher for continue playing.\n\n"
        "New version: {}",
        Lightsync->m_updateCheckVersion
        );
        FLAlertLayerProtocol* protocol = nullptr;

        if (Lightsync->m_updateCallbackResponse != 0) {
            title = "Oh no...";
            desc = fmt::format("An error occured while checking for updates, please try it again later."
            " It could be a connection problem.\n\n"
            "Error code: {}",
            Lightsync->m_updateCallbackResponse
            );
        }

        if (Lightsync->m_needUpdate) protocol = HomePage::create();

        FLAlertLayer::create(
            protocol,
            title,
            desc,
            "OK", nullptr
        )->show();

    }

    void FLAlert_Clicked(FLAlertLayer*, bool btn2) { ccDir->end(); }

    void runMenulayerEnterAnimation() {
        /*  enter animation */
        auto ext = (MenuLayerExt*)Lightsync->m_menuLayer;

        auto background = (CCSprite*)ext->getChildByTag(1000);
        auto mainMenu = (CCMenu*)ext->getChildByTag(1001);
        auto exitMenu = (CCMenu*)ext->getChildByTag(1002);

        for (int i = 0; i < mainMenu->getChildrenCount(); i++) {

            auto children = reinterpret_cast<CCNode*>(mainMenu->getChildren()->objectAtIndex(i));
            auto pos = children->getPositionY();

            children->runAction(CCFadeTo::create(0, 0));
            children->setPositionY(pos - 50);

            children->runAction(CCFadeTo::create(.5f, 255));
            children->runAction(CCEaseExponentialOut::create(CCMoveTo::create(1.5, { children->getPositionX(), pos })));
        }

        /*  showin menus */

        mainMenu->setVisible(true);

        exitMenu->setVisible(true);

        /*  bg anim    */

        background->runAction(CCEaseExponentialOut::create(CCScaleTo::create(5, 1, 1.2f)));


        /*  first time the game was opened */
        gm->setGameVariable("LS-firstLoad", true);

        Lightsync->playMenuAudio(false);


        /*  Patch notes */

        if (gm->getIntGameVariable("LS-notes") != 1) {

			Lightsync->showPatchNotes();
			gm->setIntGameVariable("LS-notes", 1);
		}


        /*  Rewards Pending */
    }

    void removeLayer() { this->removeFromParentAndCleanup(true); }

    CREATE_FUNC(HomePage)
};
