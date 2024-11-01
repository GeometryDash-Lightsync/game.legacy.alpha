#pragma once

#include "../Lightsync.hpp"

class LSButtonSprite : public CCSprite {
public:
	extension::CCScale9Sprite* m_square;
	CCLabelBMFont* m_label;
	CCSize* bgSize;
	float bgOpacity;
	CCNode* m_icon;
	CCSize m_iconSize;
	int m_iconPadding = 0;
	CCSize m_size;
	bool m_absolute;
	float m_scale;
	const char* m_caption;
	bool m_isMainButton;

	bool initWithSprite(CCNode* icon, const char* caption, extension::CCScale9Sprite* bgTexture, float width, bool absolute, float height, const char* font, const char* texture, float scale, bool isMainButton) {
		if (!CCSprite::init()) return false;

		m_iconPadding = 0;
		m_size = CCSize{ width, height };
		m_absolute = absolute;
		m_scale = scale;
		m_caption = caption;
		m_isMainButton = isMainButton;


		if (bgTexture != nullptr) m_square = bgTexture;
		else m_square = extension::CCScale9Sprite::create(texture);
		this->addChild(m_square, 0);

		m_label = CCLabelBMFont::create(caption, font);
		m_label->setScale(scale);

		if (icon != nullptr) {
			m_iconSize = icon->getContentSize();
			m_iconPadding = 10 * icon->getScale();
			m_icon = icon;

			m_square->addChild(m_icon);
		}
		else m_iconSize = CCSize(0, 0);

		this->updateBgSize();

		m_square->addChild(m_label);
		m_square->setAnchorPoint({ 0.5f, 0.5f });

		if (isMainButton)
		{
			m_square->setColor({ 10, 10, 10 });
			auto prevBg = CCSprite::create("square02b_001.png");
			prevBg->setColor({ 255, 0, 75 });
			prevBg->setScale(.7f);
			prevBg->setPosition(m_icon->getPosition());
			m_square->addChild(prevBg);
			m_icon->setZOrder(5);
			m_label->limitLabelWidth(prevBg->getContentWidth(), m_label->getScale(), .1f);
		}


		return true;
	}

	CCNode* getTexture() const { return m_square; }

	void setLabelColor(ccColor3B color) { m_label->setColor(color); };

	void setColor(ccColor3B color, bool bg) {
		m_label->setColor(color);
		if (bg) m_square->setColor(color);
		if (m_icon != nullptr) m_icon->runAction(CCTintTo::create(0, color.r, color.g, color.b));
	}

	void setLabel4B(ccColor4B color) {
		m_label->setColor({ color.r, color.g, color.b });
		m_label->setOpacity(color.a);
		if (m_icon != nullptr) m_icon->runAction(CCTintTo::create(0, color.r, color.g, color.b));
	}

	void setIconScale(float s)
	{
		if (m_icon) m_icon->setScale(s);
	}

	void setLabelOffset(CCPoint offset)
	{
		m_label->setPosition(m_label->getPosition() + offset);
	}

	void updateBgSize()
	{
		if (m_isMainButton)
		{
			m_square->setContentSize({ m_size });
			this->setContentSize({ m_square->getContentWidth(), m_square->getContentHeight() });
			m_square->setPosition(m_square->getContentSize() / 2);

			m_label->setPosition(10, 10);
			m_label->setAnchorPoint({ 0, .5f });
			m_icon->setPosition({ m_square->getContentWidth() / 2, m_square->getContentHeight() / 2 + 5 });
		}
		else
		{
			if (m_absolute) {
				m_square->setContentSize({ m_label->getContentWidth() + 35 + m_iconSize.width, m_size.height });

			}
			else {
				m_square->setContentSize({ m_size.width, m_size.height });
				m_label->limitLabelWidth(m_size.width - 5 - m_iconSize.width - m_iconPadding, m_scale, 0);
			}

			if (m_icon != nullptr) m_icon->setPosition({ 20, m_square->getContentSize().height / 2 });

			m_label->setPosition({ m_square->getContentSize().width / 2 + m_iconPadding, m_square->getContentSize().height / 2 + 2 });

			this->setContentSize({ m_square->getContentWidth(), m_size.height });
			m_square->setPosition(m_square->getContentSize() / 2);
		}

	}

	void setString(const char* string) { 
		m_label->setString(string); 
		this->updateBgSize();
	}

	void setLabelAnchorPoint(const CCPoint &var)
	{
		m_label->setAnchorPoint(var);
		if (var.x == .0f)
		{
			m_label->setPositionX({ m_label->getPositionX() - m_square->getContentSize().width / 2 + 5 });
		}
		
	}

	void setBGOpacity(float opacity)
	{
		m_square->setOpacity(opacity);
	}


	static LSButtonSprite* create(CCNode* icon, const char* caption, extension::CCScale9Sprite* sprite, float width, bool absolute, float height, const char* font, const char* texture, float scale, bool mainBtn)
	{
		LSButtonSprite* pRet = new LSButtonSprite();

		if (pRet && pRet->initWithSprite(icon, caption, sprite, width, absolute, height, font, texture, scale, mainBtn))
		{
			pRet->autorelease();
			return pRet;
		}

		CC_SAFE_DELETE(pRet);
		return nullptr;
	}

	static LSButtonSprite* create(const char* caption, float width, bool absolute, float height, const char* font, const char* texture, float scale) {
		return LSButtonSprite::create(nullptr, caption, nullptr, width, absolute, height, font, texture, scale, false);
	}

	static LSButtonSprite* createWithTexture(extension::CCScale9Sprite* sprite, const char* caption, float width, bool absolute, float height, const char* font, float scale) {
		return LSButtonSprite::create(nullptr, caption, sprite, width, absolute, height, font, "GJ_button_01.png", scale, false);
	}

	static LSButtonSprite* createWithIcon(const char* texture, CCNode* icon, const char* caption, float width, bool absolute, float height, const char* font, float scale) {
		return LSButtonSprite::create(icon, caption, nullptr, width, absolute, height, font, texture, scale, false);
	}

	static LSButtonSprite* createMainBtn(CCNode* icon, const char* caption) {
		return LSButtonSprite::create(icon, caption, nullptr, 80, false, 90, "chatFont.fnt", "square02b_001.png", .7f, true);
	}

};
