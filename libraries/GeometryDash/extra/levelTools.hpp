#pragma once 

#include <GDLib.h>

class LevelTools : public cocos2d::CCNode {
public:

	/*
		ArtisForAudio: 0x308880
		getAudioFileName: 0x307cb0
		getAudioTitle: 0x307130
		getLevel: 0x304880
		nameForArtist: 0x308950
		ngURLForArtist: 0x309f70
		urlForAudio: 0x308c50
		ArtisForAudio: 0x30a410
		ytURLForArtist: 0x308880
		fbURLForArtist: 0x30a990
	*/

	static GJGameLevel* getLevel(int id, bool unk) 
	{
		return reinterpret_cast<GJGameLevel* (__fastcall*)(int, bool)>(
			redecore::getBase() + 0x304880
			)(id, unk);
	}
};