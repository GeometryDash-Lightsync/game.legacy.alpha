#include "../lightsync.h"

class LSItemIcon : public CCSprite
{
public:
    int m_id;
    UnlockType m_unlock;

    bool initWithSprite(int id, UnlockType type)
    {
        if (!CCSprite::init()) return false;

        this->initWithSpriteFrameName("playerSquare_001.png");
        this->setOpacity(0);
        m_id = id;
        m_unlock = type;

        CCSprite* sprite;

        if (type == UnlockType::kColor1 || type == UnlockType::kColor2)
        {

            sprite = CCSprite::createWithSpriteFrameName("player_special_01_001.png");

            sprite->setColor(Lightsync->colorForIdx(id));

            auto num = (type == UnlockType::kColor1) ? "1" : "2";
            auto typeLabel = CCLabelBMFont::create(num, "bigFont.fnt");
            typeLabel->setScale(.4f);

            typeLabel->setColor(Utils::grayScaleColor(0));
            if (id == 15)typeLabel->setColor(Utils::grayScaleColor(255));
            
            typeLabel->setAnchorPoint({.5f, .5f});
            typeLabel->setPosition(sprite->getContentSize() / 2);

            sprite->addChild(typeLabel);
            this->addChild(sprite);
        } else if (
            type == UnlockType::kDeathEffect || 
            type == UnlockType::kSpecial || 
            type == UnlockType::kItem || 
            type == UnlockType::kShipFire
        ) {

            const char* texType = "shipfireIcon";

            switch (type)
            {
            case UnlockType::kSpecial: texType = "player_special"; break;
            case UnlockType::kDeathEffect: texType = "explosionIcon"; break;
            case UnlockType::kItem: texType = "gjItem"; break;
            }

            std::string texture = fmt::format("{}_{:02}_001.png", texType, id);

            sprite = CCSprite::createWithSpriteFrameName(texture.c_str());
            this->addChild(sprite);

        } else {
            auto player = SimplePlayer::create(0);

            player->updatePlayerFrame(id, gm->UnlockToIcon(type));
            player->setColor(Lightsync->colorForIdx(17));

            sprite = player;

           this->addChild(sprite);
        }

        sprite->setAnchorPoint({ .5f, .5f });
        sprite->setPosition(this->getContentSize() / 2);

        return true;
    }

    static LSItemIcon* create(int id, UnlockType type)
	{
		LSItemIcon* pRet = new LSItemIcon();

		if (pRet && pRet->initWithSprite(id, type))
		{
			pRet->autorelease();
			return pRet;
		}

		CC_SAFE_DELETE(pRet);
		return nullptr;
    }
};