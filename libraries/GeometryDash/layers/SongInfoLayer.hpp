#pragma once

#include <GDLib.h>

class SongInfoLayer : public FLAlertLayer {
public:

	bool init(std::string song, std::string author, std::string songUrl, std::string ng, std::string yt, std::string fb, int songID, std::string category, int isNCS)
	{
		return reinterpret_cast<bool(__thiscall*)(
			SongInfoLayer*, std::string, std::string, std::string, std::string, std::string, std::string, int, std::string, int
			)>(redecore::getBase() + 0x466B00)(this, song, author, songUrl, ng, yt, fb, songID, category, isNCS);
	}

	static SongInfoLayer* create(std::string p0, std::string p1, std::string p2, std::string p3, std::string p4, std::string p5, int p6, std::string p7, int p8)
	{
		return reinterpret_cast<SongInfoLayer*(__thiscall*)(
			std::string, std::string, std::string, std::string, std::string, std::string, int, std::string, int
			)>(redecore::getBase() + 0x4667E0)(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	}
	
	//Out of Line
	void show()
	{
		auto m_scene = cocos2d::CCDirector::sharedDirector()->getRunningScene();
		auto order = m_scene->getHighestChildZ();
		auto m_pLayer = reinterpret_cast<cocos2d::CCLayer*>(this->getChildren()->objectAtIndex(0));

		if (order > 105) {
			this->setZOrder(order + 1);
		}
		else {
			this->setZOrder(105);
		}

		m_scene->addChild(this);

		/*m_pLayer->setScale(.0f);
		auto scaleAnim = cocos2d::CCScaleTo::create(0.5, 1.0);
		auto elastic = cocos2d::CCEaseElasticOut::create(scaleAnim, 0.6);
		m_pLayer->runAction(elastic);*/
	}
};