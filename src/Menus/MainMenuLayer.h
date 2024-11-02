#pragma once
#include "../lightsync.h"

class MainMenuLayer : public CCLayer, public FLAlertLayerProtocol {
public:
    CCMenu* m_mainMenu;
    CCMenu* m_bottomMenu;

    float m_buttonScale = .7f;

    CCSprite* m_smallBar;
    CCMenuItemSpriteExtra* m_barButton;
    bool m_btnActivated;
    CCNode* m_bottomBar;

    std::string m_timeString;
    std::string m_dateString;
    std::string m_timeFormatString;
	CCLabelBMFont* m_timeLabel;
	CCLabelBMFont* m_dateLabel;
	CCLabelBMFont* m_timeFormatLabel;


    int m_buttonCount = 5;
    
    CCSprite* m_barSprite;

    CCLayer* m_profileCard;
    CCLabelBMFont* m_achievementsLabel;

    bool init() {

        auto size = ccDir->getWinSize();

        m_btnActivated = false;


        m_mainMenu = CCMenu::create();
        m_mainMenu->setPosition(CCPointZero);
        this->addChild(m_mainMenu);

        /* small bar */
        
		m_smallBar = CCSprite::create("aCircle.png");
		m_smallBar->setPosition({ size.width / 2, 20 });
		this->addChild(m_smallBar);

        this->setupBottomMenu();

        this->createBottomBarBtn();
        m_bottomBar->setPosition(0, -60);

        


        /* top bar */ 


        m_barSprite = CCSprite::createWithSpriteFrameName("barMenu.png");
		m_barSprite->setScale(1.3f);

		m_barSprite->setPosition({ size.width / 2, size.height - 25 });

        this->addChild(m_barSprite);


        /* time and format  */

        m_timeLabel = CCLabelBMFont::create(" ", "bigFont.fnt");
        m_timeLabel->setScale(.55f);

        this->addChild(m_timeLabel);

        m_timeFormatLabel = CCLabelBMFont::create(" ", "goldFont.fnt");
		m_timeFormatLabel->setScale(.55f);


		m_timeFormatLabel->setAnchorPoint({ 0, 0.5f });
		m_timeFormatLabel->setPosition({ size.width / 2 + 3, size.height - 25 });

		this->addChild(m_timeFormatLabel);

        this->updateTimeLabel();

        /*  date  */

        m_dateLabel = CCLabelBMFont::create(" ", "bigFont.fnt");

        m_dateLabel->setScale(.35f);
        m_dateLabel->setAnchorPoint({ 1, .5f });

        m_dateLabel->setPosition({ size.width / 2 + m_barSprite->getContentWidth() / 2 - 15, size.height - 25 });
        this->addChild(m_dateLabel);

        this->updateDateLabel();


        /*  Logo  */

        auto logo = CCSprite::createWithSpriteFrameName("GJ_logo_001.png");
        logo->setScale(.4f);

        logo->setAnchorPoint({ 0, .5f });
        logo->setPosition({ 35, size.height - 75 });

        this->addChild(logo);


        auto logo2 = CCSprite::createWithSpriteFrameName("GJ_logo_02_001.png");
        logo2->setScale(.5f);
        
        logo2->setAnchorPoint({ 0, 1 });
        logo2->setColor({ 175, 175, 175 });
        logo2->setPosition({ 43, size.height - 75 + logo->getScaledContentSize().height });

        this->addChild(logo2);


        auto version = CCLabelBMFont::create(Lightsync->m_version.c_str(), "bigFont.fnt");
        version->setScale(.35f);

        version->setAnchorPoint({ 0, 0.5f });
        version->setPosition({ 25, 25 });
        version->setColor({ 175, 175, 175 });

        this->addChild(version);


        /*   Top bar   */


        auto topBarMenu = CCMenu::create();
        topBarMenu->setPosition(CCPointZero);

        /* Account */

        auto accountSpr = CCSprite::createWithSpriteFrameName("GJ_profileButton_001.png");
        accountSpr->setScale(.4f);

        auto accountBtn = CCMenuItemSpriteExtra::create(

	        accountSpr,
	        this,
	        menu_selector(MainMenuLayer::toggleProfileCard)
        );

        accountBtn->setPosition({ size.width / 2 - m_barSprite->getContentWidth() / 2 - 25, size.height - 25});

        topBarMenu->addChild(accountBtn);

        /*  Settings */

        auto settingsSpr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
        settingsSpr->setScale(.45f);

        settingsSpr->setBlendFunc({ GL_ONE, GL_ONE });

        auto settingsBtn = CCMenuItemSpriteExtra::create(

	        settingsSpr,
	        this,
	        menu_selector(MainMenuLayer::onOptions)
        );

        settingsBtn->setPosition({ size.width / 2 + m_barSprite->getContentWidth() / 2 + 25, size.height - 25 });
        
        topBarMenu->addChild(settingsBtn);

        /* Sound */

        auto musicSpr = CCSprite::createWithSpriteFrameName("btnMusic_001.png");
        musicSpr->setScale(.45f);

        musicSpr->setBlendFunc({ GL_ONE, GL_ONE });

        auto MusicBtn = CCMenuItemSpriteExtra::create(

	        musicSpr,
	        this,
	        menu_selector(MenuLayerExt::onSound)
        );

        MusicBtn->setPosition({ size.width / 2 + m_barSprite->getContentWidth() / 2, size.height - 25 });


		topBarMenu->addChild(MusicBtn);


        /*   User label   */

        auto userName = CCLabelBMFont::create(
	        GJAccountManager::sharedState()->getUsername(),
	        "bigFont.fnt"
        );
        userName->limitLabelWidth(120, .5f, .1f);


        userName->setPosition({ size.width / 2 - m_barSprite->getContentWidth() / 2 - 5, size.height - 25 });
        userName->setAnchorPoint({ 0, 0.5f });


        topBarMenu->addChild(userName);

        this->addChild(topBarMenu);

        this->createProfileCard();


        /*   disabling keypad   */
        this->setTouchEnabled(true);
        this->setKeypadEnabled(true);

        return true;
    }

    void setupBottomMenu() {

        auto size = ccDir->getWinSize();

        m_bottomBar = CCNode::create();
        this->addChild(m_bottomBar);

        auto square = CCLayerColor::create(Utils::grayScaleColor(10, 255), size.width, 45);
        m_bottomBar->addChild(square);

        m_bottomMenu = CCMenu::create();
        m_bottomMenu->setPosition({ size.width / 2, 20 });
        m_bottomBar->addChild(m_bottomMenu);


        const char* texture = "GJ_achBtn_001.png";
        SEL_MenuHandler handler = menu_selector(MainMenuLayer::onShowAchievements);

        for (int i = 0; i < m_buttonCount; i++)
        {
            switch (i)
            {
            case 1:
                texture = "GJ_dailyChestBtn_001.png";

                handler = menu_selector(MenuLayer::onDailyReward);
                break;
                
            case 2:
                texture = "btnNotes_001.png";
                handler = menu_selector(MainMenuLayer::onPatchNotes);
                break;

            case 3:
			    texture = "btnWeb_001.png";
                handler = menu_selector(MainMenuLayer::onWebAlert);
                break;

            case 4:
                texture = "GJ_copyrightBtn_001.png";
			    handler = menu_selector(MainMenuLayer::onShowCredits);
                break;

            }


            auto spr = CCSprite::createWithSpriteFrameName(texture);
            spr->setScale(.5f);

            auto sprSelected = CCSprite::createWithSpriteFrameName(texture);
            sprSelected->setScale(.5f);
            sprSelected->setColor({ 255, 0, 75 });

            if (i == 3) {

	            spr->setScale(.7f);
	            sprSelected->setScale(.7f);
            }
            auto btn = CCMenuItemSpriteExtra::create(spr, this, handler);
            btn->setSelectedImage(sprSelected);
            btn->useAnimationType(MenuAnimationType::Move);
            m_bottomMenu->addChild(btn);
        }

        m_bottomMenu->alignItemsHorizontallyWithPadding(35);
        

    }

    void createBottomBarBtn() {
        auto size = ccDir->getWinSize();

        auto spr = CCSprite::create("aCircle.png");
		spr->setOpacity(0);

        m_barButton = CCMenuItemSpriteExtra::create(
	        spr,
	        this,
	        menu_selector(MainMenuLayer::updateBottomBar)
        );

        m_barButton->setPosition({ size.width / 2, m_btnActivated ? 60.0f : 20.0f });
        m_mainMenu->addChild(m_barButton);
    }


    void updateBottomBar(CCObject*) {
        auto size = ccDir->getWinSize();


        /* avoid clicking a lot */
        m_barButton->runAction(CCRemoveSelf::create());

        this->runAction(
            CCSequence::createWithTwoActions(
                CCDelayTime::create(1), 
                CCCallFunc::create(this, callfunc_selector(MainMenuLayer::createBottomBarBtn))
            )
        );

        ccColor3B tintColor = {255, 255, 255};
        

        if (!m_btnActivated) {

			m_smallBar->runAction(CCEaseElasticOut::create(CCScaleTo::create(0.5f, .5f, 1), .6f));
			m_smallBar->runAction(CCEaseExponentialOut::create(CCMoveTo::create(1, { size.width / 2, 60 })));
			m_bottomBar->runAction(CCEaseExponentialOut::create(CCMoveTo::create(1, { 0, 0 })));

            tintColor = { 255, 0, 75 };
		}
		else {
			m_smallBar->runAction(CCEaseBackInOut::create(CCScaleTo::create(1, 1, 1)));
			m_smallBar->runAction(CCEaseBackInOut::create(CCMoveTo::create(1, { size.width / 2, 20 })));
			m_bottomBar->runAction(CCEaseIn::create(CCMoveTo::create(.7f, { 0, -60 }), 2));
		}

        m_smallBar->runAction(CCTintTo::create(.5f, tintColor.r, tintColor.g, tintColor.b));

        m_btnActivated = !m_btnActivated;

    }

    void onShowAchievements(CCObject*) { }

    void onPatchNotes(CCObject*) { Lightsync->showPatchNotes(); }

    void onWebAlert(CCObject*) {
        FLAlertLayer::create(
	        this, 
	        "Webpage", 
	        "Want to visit our webpage and find some interesting stuff?",
	        "NO", "YES", 300
        )->show();

    }

    void onShowCredits(CCObject*) { }

    void showProfile(CCObject* sender) {
        
        if (!Lightsync->hasAccount()) 
            FLAlertLayer::create(
                "Account Needed", 
                "You need an <cg>account</c> to see your <cy>profile</c>.\nYou can create one on the <cr>settings menu</c>.", 
                360
            )->show();

        else 
            Lightsync->m_menuLayer->onProfile(sender);

    }

    void onOptions(CCObject*) { }

    void FLAlert_Clicked(FLAlertLayer*, bool btn2) {
		if (btn2) CCApplication::sharedApplication()->openURL(Lightsync->m_gdpsUrl.c_str());
	};

    void updateTimeLabel() {

	auto size = ccDir->getWinSize();
	    std::vector<int> systemTime = Utils::getSystemTime();
	    auto hour = systemTime[0];

	    if (gm->getGameVariable("LS-ClockFormat"))
	    {
		    m_timeString = fmt::format("{:02}:{:02}", systemTime[0], systemTime[1]);


		
		    m_timeLabel->setAnchorPoint({ 0.5f, 0.5f });
		    m_timeLabel->setPosition({ size.width / 2, size.height - 25 });
		    m_timeLabel->setColor({ 255, 0, 75 });



    		m_timeFormatLabel->setVisible(false);
	    }
	    else {
		    m_timeLabel->setAnchorPoint({ 1, 0.5f });

            int hourFormat = systemTime[0]; 
            if (hourFormat > 12) hourFormat -= 12;
            m_timeFormatString = fmt::format("{}", (systemTime[0] > 11) ? "PM" : "AM" );

            if (hourFormat == 0) hourFormat == 12;

		    m_timeString = fmt::format("{}:{:02}", hourFormat, systemTime[1]);

		    

		    m_timeFormatLabel->setString(m_timeFormatString.c_str());
		    m_timeFormatLabel->setVisible(true);
		
		    m_timeLabel->setPosition({ size.width / 2 - 3, size.height - 25 });
		    m_timeLabel->setColor({ 255, 255, 255 });
	    }
	    m_timeLabel->setString(m_timeString.c_str());
    }

    void updateDateLabel() {
        auto month = Utils::getCurrentMonth();
        auto day = Utils::getCurrentDay();
        auto year = Utils::getCurrentYear() + 1900;
    
	    if (gm->getGameVariable("LS-dateOrder"))
            m_dateString = fmt::format("{}/{:02}/{}", day, month, year);
	    else
            m_dateString = fmt::format("{}/{}/{}", month, day, year);
	

	    m_dateLabel->setString(m_dateString.c_str());
    }

    void onTimeSequence() {
		this->runAction(
			CCSequence::create(
				CCDelayTime::create(60 - Utils::getSystemTime()[2]),
				CCCallFunc::create(this, callfunc_selector(MainMenuLayer::updateTimeLabel)),
				CCCallFunc::create(this, callfunc_selector(MainMenuLayer::onTimeSequence)),
				0
			)
		);

        this->updateDateLabel();
	}

    void toggleProfileCard(CCObject*) { 

	if (m_profileCard->isVisible())
	{

		m_profileCard->setVisible(false);
		FMODAudioEngine::sharedEngine()->playEffect("a_menu02.ogg");
	}
	else
	{

		FMODAudioEngine::sharedEngine()->playEffect("a_menu03.ogg");

        /*      Profile card anim   */

		m_profileCard->setPositionY(m_profileCard->getPositionY() + 75);

		m_profileCard->runAction(
			CCEaseExponentialOut::create(
                CCMoveTo::create(.5f, { m_profileCard->getPositionX(), m_profileCard->getPositionY() - 75 })
            )
		);

		m_profileCard->setVisible(true);

        /*  Update Achievements */

		m_achievementsLabel->setString(fmt::format("Achievements Completed: {}", 0).c_str());

        /*  Fading all objects */

		for (int i = 0; i < m_profileCard->getChildrenCount(); i++)
		{
			auto obj = reinterpret_cast<CCNode*>(m_profileCard->getChildren()->objectAtIndex(i));
			obj->runAction(
				CCSequence::createWithTwoActions(
					CCFadeTo::create(0, 0),
					CCFadeTo::create(.25f, 255)
				)
			);
		}
	}


}



    void createProfileCard() {

        auto size = ccDir->getWinSize();

        m_profileCard = CCLayer::create();

		m_profileCard->setPosition({ size.width / 2 - m_barSprite->getContentWidth() / 2 - 43, size.height - 50 });

        /*   background   */

        auto bg = extension::CCScale9Sprite::create("square02b_001.png");
        bg->setContentSize({ m_barSprite->getContentWidth() / 2 + 20, 110 });

        bg->setColor({ 34, 34, 34 });
        bg->setAnchorPoint({ 0, 1 });

        m_profileCard->addChild(bg);

        /* Icon (CUBE) */

        auto iconPrev = SimplePlayer::create(gm->getPlayerFrame());
        iconPrev->setScale(.9f);

        iconPrev->setPosition({ 25, -25 });

        iconPrev->setColor(Lightsync->colorForIdx(gm->getPlayerColor()));
        iconPrev->setSecondColor(Lightsync->colorForIdx(gm->getPlayerColor2()));
        iconPrev->enableCustomGlowColor(Lightsync->colorForIdx(gm->getPlayerColorGlow()));
        iconPrev->setGlowOutline(gm->getPlayerGlow());

        m_profileCard->addChild(iconPrev);

        /* black line for icons */

        auto iconBg = extension::CCScale9Sprite::create("square02b_small.png");

        iconBg->setColor({ 10, 10, 10 });

        iconBg->setContentSize({ bg->getContentWidth() / 2 + 30, 20 });
        iconBg->setAnchorPoint({ 0, .5f });
        iconBg->setPosition({ 10, -55 });


        m_profileCard->addChild(iconBg);

        /*   Profile Label (Another?)   */

        auto profileLabel = CCLabelBMFont::create(
	        GJAccountManager::sharedState()->getUsername(),
	        "bigFont.fnt"
        );
        profileLabel->limitLabelWidth(100, .7f, .1f);

        profileLabel->setAnchorPoint({ 0, .5f });
        profileLabel->setPosition({ 45, -25 });

        m_profileCard->addChild(profileLabel);

        /*  Container with the vehicles */

        auto iconNode = CCNode::create();

        iconNode->setPosition(iconBg->getPosition());

        m_profileCard->addChild(iconNode);

        /*   Icons   */

        for (int i = 0; i < 8; i++) {

	        auto vehicle = SimplePlayer::create(0);
            vehicle->setScale(.3f);

	        auto frame = static_cast<IconType>(i + 1);

	        vehicle->updatePlayerFrame(gm->getIconID(frame), frame);
	        
	        vehicle->setPosition({ 10.f + 17.f * i ,0 });


	        vehicle->setColor(Lightsync->colorForIdx(gm->getPlayerColor()));
	        vehicle->setSecondColor(Lightsync->colorForIdx(gm->getPlayerColor2()));
	        vehicle->enableCustomGlowColor(Lightsync->colorForIdx(gm->getPlayerColorGlow()));
	        vehicle->setGlowOutline(gm->getPlayerGlow());


	        iconNode->addChild(vehicle);
        }


        /* Achievement Label */

        m_achievementsLabel = CCLabelBMFont::create("", "goldFont.fnt");
        m_achievementsLabel->setScale(.3f);

        m_achievementsLabel->setPosition({ 15, -bg->getContentHeight() + 10 });
        m_achievementsLabel->setAnchorPoint({ 0, .5f });
        
        m_profileCard->addChild(m_achievementsLabel);

        /*  Profile Button  */

        auto menu = CCMenu::create();
        menu->setPosition(CCPointZero);

        auto profileSpr = CCSprite::createWithSpriteFrameName("GJ_profileButton_001.png");
        profileSpr->setScale(.55f);

        auto profileBtn = CCMenuItemSpriteExtra::create(
        	profileSpr,
	        this,
	        menu_selector(MainMenuLayer::showProfile)
        );
        profileBtn->setPosition({ bg->getContentWidth() - 25, -bg->getContentHeight() + 25 });


        menu->addChild(profileBtn);

        m_profileCard->addChild(menu);


        /*  Adding the menu */

        this->addChild(m_profileCard, 10);
        m_profileCard->setVisible(false);       
    }



    CREATE_FUNC(MainMenuLayer);
};