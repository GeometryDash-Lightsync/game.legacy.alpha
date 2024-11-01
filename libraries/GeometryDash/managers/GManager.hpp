#pragma once
#include <GDLib.h>

class DS_Dictionary;

class GManager : public cocos2d::CCNode {
public:
	std::string m_fileName;
	bool m_setup;
	bool m_saved;
	bool m_quickSave;
public:
	void save() {}
	void setup() {}
	virtual void encodeDataTo(DS_Dictionary* data) {}
	virtual void dataLoaded(DS_Dictionary* data) {}
	virtual void firstLoad() {}
};
