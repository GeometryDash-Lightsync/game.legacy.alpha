#pragma once
#include "../lightsync.h"

bool(__fastcall *ItemInfoPopup_init)(CCLayerColor *, int, UnlockType);

bool __fastcall ItemInfoPopup_init_H(CCLayerColor *_this, int id, UnlockType type)
{
    if (!ItemInfoPopup_init(_this, id, type))
        return false;

    _this->setOpacity(225);

    auto layer = dynamic_cast<CCNode *>(_this->getChildren()->objectAtIndex(0));
    layer->removeAllChildren();

    auto size = ccDir->getWinSize();
    /*  Info Label  */
    std::string itemString = fmt::format("{} {:02}", gm->getItemName(type), id);

    auto infoLabel = CCLabelBMFont::create(itemString.c_str(), "bigFont.fnt");
    infoLabel->setScale(.5f);

    infoLabel->setColor(Utils::grayScaleColor(175));
    infoLabel->setAnchorPoint({1, .5f});
    infoLabel->setPosition({size.width - 15, size.height - 15});

    _this->addChild(infoLabel);

    /*  icon preview */
    auto iconPreview = LSItemIcon::create(id, type);

    if (type == UnlockType::kRobot || type == UnlockType::kSpider)
    {
        auto player = (SimplePlayer *)iconPreview->getChildren()->objectAtIndex(0);
        if (player->m_robotSprite) player->m_robotSprite->runAnimation("idle01");
        if (player->m_spiderSprite) player->m_spiderSprite->runAnimation("idle01");
    }

    iconPreview->setPosition({ size.width / 2,  size.height / 2 + 35 });
    iconPreview->setAnchorPoint({ .5f, .5f });

    layer->addChild(iconPreview);



    /* unlock info */
    std::string title = "Not yet!";
    std::string desc = "Coming Soon!";
    std::string smallDesc = " ";
    const char* itemName = gm->getItemName(type);

    switch (rand() % 23 + 1) 
    {
        case 2: title = "Huh"; break;
        case 3: title = "Hehe..."; break;
        case 4: title = "Wait for it"; break;
        case 5: title = "Locked!"; break;
        case 6: title = "Nuh uh"; break;
        case 7: title = "Stay tuned!"; break;
        case 8: title = "Stay tuneado!"; break;
        case 9: title = "Unavailable"; break;
        case 10: title = "Damn another icon locked..."; break;
        case 11: title = "In the oven"; break;
        case 12: title = "Not now"; break;
        case 13: title = "Special chest?"; break;
        case 14: title = "Secret chest?"; break;
        case 15: title = "Islands coming soon!"; break;
        case 16: title = "Coming soon..."; break;
        case 17: title = "It's a secret..."; break;
        case 18: title = "The path leads to an old tower-"; break;
        case 19: title = "It's cooking"; break;
        case 20: title = "Almost there"; break;
        case 21: title = "Soon..."; break;
        case 22: title = "Bug?"; break;
        case 23: title = "???"; break;

       
    }


    /* default */ 

        if (gm->isIconUnlockedByDefault(id, type)) 
    {
         title = "Default";
         desc = fmt::format("This <cg>{}</c> is <cl>unlocked</c> by default.", itemName);
    }



    /*  achievements */
    
    auto iconVar = gm->iconIdentifier(id, type);
    auto achIdentifier = (CCString*)AchievementManager::sharedState()->m_achievementUnlocks->objectForKey(iconVar.c_str());

    if (achIdentifier) {
        CCDictionary *achDictionary = (CCDictionary *)AchievementManager::sharedState()->m_platformAchievements->objectForKey(achIdentifier->getCString());

        auto titleString = (CCString*)achDictionary->objectForKey("title");
        title = titleString->getCString();

        auto descString = (CCString*)achDictionary->objectForKey("achievedDescription");
        desc = fmt::format("{} to <cl>unlock</c> this <cg>{}</c>!", descString->getCString(), itemName);
    } 


    /*  Secret  Chests  */

    auto secretDict = GameStatsManager::sharedState()->m_allTreasureRoomChestItems;
    auto chestItemKey = fmt::format("{}_{}", id, static_cast<int>(type));


    auto chestObject = (CCString*)secretDict->objectForKey(chestItemKey.c_str());
    if (chestObject) {
        title = "Secret Chest";
        desc = fmt::format("You an <cl>find</c> this <cg>{}</c> in a secret <cy>chest</c>!", itemName);

        switch (rand() % 10 + 1)
        {
            case 1: smallDesc = "Nothing happened."; break;
            case 2: smallDesc = "Without a key, it cannot be."; break;
            case 3: smallDesc = "Why you click?"; break;
            case 4: smallDesc = "You are not yet ready."; break;
            case 5: smallDesc = "A key, you must have."; break;
            case 6: smallDesc = "The lock wont budge."; break;
            case 7: smallDesc = "A demon guards it. Find him."; break;
            case 8: smallDesc = "You have no power here."; break;
            case 9: smallDesc = "Forget about this one."; break;
            default: smallDesc = "A key... My kingdom for a key..."; break;
        }
    }

    /*  Special chests  */

    auto specialDict = GameStatsManager::sharedState()->m_allSpecialChestItems;

    auto specialObject = (CCString*)specialDict->objectForKey(chestItemKey.c_str());

    if (specialObject && !std::string(specialObject->getCString()).starts_with("g")) {
        title = "Special Chest";
        desc = fmt::format("You an <cl>find</c> this <cg>{}</c> in a special <cy>chest</c>!", itemName);

        if (std::string(specialObject->getCString()).starts_with("pr")) {

            desc = fmt::format("Complete the Path of {} to <cl>unlock</c> this <cg>{}</c>!",
                gm->nameForPath(LSIconDataManager::sharedState()->rewardToPathType(specialObject->getCString())), 
                itemName
            );
        } else {
            switch (rand() % 10 + 1)
            {
                case 1: smallDesc = "That wont work."; break;
                case 2: smallDesc = "You must do something."; break;
                case 3: smallDesc = "It cannot be done."; break;
                case 4: smallDesc = "Prove that you are worthy."; break;
                case 5: smallDesc = "Need. More. Power."; break;
                case 6: smallDesc = "Player used tap.\nIt's not very effective."; break;
                case 7: smallDesc = "A wild lock appeared!"; break;
                case 8: smallDesc = "You are not ready."; break;
                case 9: smallDesc = "ehehehehehe..."; break;
                default: smallDesc = "IMPOSSIBRU"; break;
            }
        }

    }


    /*  Shops   */
    
    auto storeMap = LSIconDataManager::sharedState()->m_storeIcons;
    int shop = storeMap[iconVar];

    switch (shop)
    {
        
    case 1:
        title = "Shop";
        desc = fmt::format("You can <cl>buy</c> this <cg>{}</c> in the <cy>shop</c>!", itemName);
        break;

    case 2:
        title = "Secret Shop";
        desc = fmt::format("There may or may not exist a <cy>shop</c> where you can <cl>buy</c> this <cg>{}</c>.", itemName);
        break;

    case 3:
        title = "Community Shop";
        desc = fmt::format("You can <cl>buy</c> this <cg>{}</c> in the <cy>community shop</c>!", itemName);
        break;

    case 4:
        title = "Mechanic Shop";
        desc = fmt::format("You can <cl>buy</c> this <cg>{}</c> at the <cp>Mechanic</c>!", itemName);
        break;

    case 5:
        title = "Diamond Shop";
        desc = fmt::format("You can <cl>buy</c> this <cg>{}</c> in the <cy>diamond shop</c>!", itemName);
        break;
    }
    
    /*  Labels  */
    auto author = LSIconDataManager::sharedState()->artistIDForIcon(id, type);

    if (author != -1)
    {
        auto name = fmt::format("By {}",  LSIconDataManager::sharedState()->getArtistName(author));

        auto creditLabel = CCLabelBMFont::create(
            name.c_str(),
            "bigFont.fnt"
        );

        creditLabel->limitLabelWidth(100, .45f, 0);

        creditLabel->setAnchorPoint({ 1, 0 });
        creditLabel->setPosition({ size.width - 20, 20 });

        _this->addChild(creditLabel);
    }


    auto remake = LSIconDataManager::sharedState()->remakeIDForIcon(id, type);

    if (remake != -1)
    {
        auto credit = fmt::format("(Remake By {})", LSIconDataManager::sharedState()->getArtistName(remake));
        auto creditLabel = CCLabelBMFont::create(
            credit.c_str(),
            "bigFont.fnt"
        );

        creditLabel->limitLabelWidth(80, .45f, 0);

        creditLabel->setAnchorPoint({ 1, 0 });
        creditLabel->setPosition({ size.width - 20, 10 });
        creditLabel->setOpacity(175);

        _this->addChild(creditLabel);
    }
    

    auto unlockLabel = CCLabelBMFont::create(
        title.c_str(),
        "goldFont.fnt"
    );
    unlockLabel->limitLabelWidth(120, .6f, .1f);

    unlockLabel->setPosition({
        size.width / 2, size.height / 2 }
    );
    layer->addChild(unlockLabel);



    auto unlockDesc = TextArea::create(
        desc,
        "bigFont.fnt",
        1, 600, { 0.5, 0.5f },
        30,
        false
    );
    unlockDesc->setAnchorPoint({ 0.5f, 0.5f });
    unlockDesc->setScale(.4f);

    unlockDesc->setPosition({ size.width / 2,  size.height / 2 - 35 });
    layer->addChild(unlockDesc);



    auto smallLabel = CCLabelBMFont::create(smallDesc.c_str(), "bigFont.fnt");
    smallLabel->limitLabelWidth(100, .4f, .1f);

    smallLabel->setAnchorPoint({ .5f, .5f });
    smallLabel->setPosition(size.width / 2, 25);
    smallLabel->setColor({ 175, 175, 175 });

    layer->addChild(smallLabel);



    return true;
}