#pragma once
#include <GDLib.h>	

class GJSongBrowser : public GJDropDownLayer, public FLAlertLayerProtocol {
public:
	static GJSongBrowser* create()
	{
		return reinterpret_cast<GJSongBrowser * (__fastcall*)()>
			(redecore::getBase() + 0x2a4b80)
			();
	}

	void loadPage(int p0)
	{
		reinterpret_cast<void(__thiscall*)(
			GJSongBrowser*, int
			)>(redecore::getBase() + 0x2a5180)(this, p0);
	}

};