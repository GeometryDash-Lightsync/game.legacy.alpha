#pragma once
#include <GDLib.h>
#include "CCMenuItemSpriteExtra.hpp"

class InfoAlertButton : public CCMenuItemSpriteExtra {
public:
	std::string m_title;
	std::string m_description;
	float m_textScale;
	bool m_scroll;
	static InfoAlertButton* create(std::string p0, std::string p1, float p2)
	{
		return reinterpret_cast<InfoAlertButton * (__fastcall*)(std::string, std::string, float)>
			(redecore::getBase() + 0x2a7e50)
			(p0, p1, p2);;
	}
};