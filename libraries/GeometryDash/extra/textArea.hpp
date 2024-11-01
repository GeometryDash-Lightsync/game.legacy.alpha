#pragma once

#include <GDLib.h>

class TextArea : public cocos2d::CCSprite {
public:
	bool m_disableColor;
	MultilineBitmapFont* m_label;
	float m_width;
	int m_unknown;
	std::string m_fontFile;
	float m_height;
	bool m_unkBool;
	cocos2d::CCPoint m_anchorPoint;
	bool m_allShown;
	float m_scale;
	int m_rectHeight;
	int m_rectWidth;
	float m_maxWidth;
	cocos2d::CCPoint m_unkPoint;
	TextAreaDelegate* m_delegate;
	cocos2d::CCDictionary* m_shakeCharacters;
	float m_shakeElapsed;
	/*
	2.206: 0x75960 (vectorcall)
	*/
	static TextArea* create
	(
		std::string caption, 
		const char* font,
		float scale, 
		float width, 
		cocos2d::CCPoint anchor, 
		float lineHeight, 
		bool disableColor
	) {
		auto pRet = reinterpret_cast<TextArea * (__fastcall*)(
			std::string, const char*, float, float, cocos2d::CCPoint, float, bool
			)>(
				redecore::getBase() + 0x75960
				)(caption, font, scale, width, anchor, lineHeight, disableColor);
		//__asm add esp, 0x20
		return pRet;
	}

	static TextArea* create(std::string caption, const char* font, float width, cocos2d::CCPoint anchor, float lineheight)
	{
		return TextArea::create(caption, font, 1.0f, width, anchor, lineheight, false);
	}

	/*
	2.206: 0x75ba0
	*/
	void setString(std::string str) {
		reinterpret_cast<void(__fastcall*)(
			TextArea*, std::string
			)>(redecore::getBase() + 0x75ba0)(this, str);
	}

	/*
	2.206: 0x76110
	*/
	void colorAllCharactersTo(cocos2d::ccColor3B color)
	{
		reinterpret_cast<void(__fastcall*)(
			TextArea*, cocos2d::ccColor3B
			)>(redecore::getBase() + 0x76110)(this, color);
	}

};