#include <GDLib.h>

class MoreOptionsLayer : public FLAlertLayer, public GJDropDownLayerDelegate {
public:
	void onAudioDebug(CCObject* pSender)
	{
		reinterpret_cast<void(__fastcall*)(
			MoreOptionsLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x354B10)(this, pSender);	
	}

	void onKeys(CCObject* pSender)
	{
		reinterpret_cast<void(__fastcall*)(
			MoreOptionsLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0xD9640)(this, pSender);
	}

	void onSavedSongs(CCObject* pSender)
	{
		reinterpret_cast<void(__fastcall*)(
			MoreOptionsLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0x354AA0)(this, pSender);
	}

	//
};