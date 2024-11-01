#pragma once

#include <GDLib.h>

class GJCommentListLayer : public cocos2d::CCLayerColor {
public:
	BoomListView* m_list;

	/*
	[Missing]
	2.200: (...)
	*/
	bool init(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, bool blueBorder);

	/*
	2.200: 0x277B40 (cdecl)
	*/
	static GJCommentListLayer* create(BoomListView* listView, char const* title, cocos2d::ccColor4B color, float width, float height, bool blueBorder) {
		return reinterpret_cast<GJCommentListLayer * (__fastcall*)(
			BoomListView*, const char*, cocos2d::ccColor4B, float, float, bool
			)>(redecore::getBase() + 0x27f7a0)(listView, title, color, width, height, blueBorder);
	};

	


};