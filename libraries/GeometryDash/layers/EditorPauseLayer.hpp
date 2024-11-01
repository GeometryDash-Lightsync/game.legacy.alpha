#pragma once

#include <GDLib.h>
#include "LevelEditorLayer.hpp"

#include <iomanip>
#include <fstream>
#include <iostream>
#include <stdlib.h>


class EditorPauseLayer : public CCBlockLayer, public FLAlertLayerProtocol {
public:
    void* padding;
    void* padding0;
    bool m_saved;
    CCMenuItemSpriteExtra* m_guidelinesOffButton;
    CCMenuItemSpriteExtra* m_guidelinesOnButton;
    LevelEditorLayer* m_editorLayer;
    PAD(32);

	void onOptions(cocos2d::CCObject* sender)
	{
		reinterpret_cast<void(__fastcall*)(
			EditorPauseLayer*, cocos2d::CCObject*
			)>(redecore::getBase() + 0xD8F90)(this, sender);
	}

    void onSaveString(cocos2d::CCObject* sender)
    {
        
        auto fileName = cocos2d::CCString::createWithFormat("./%s.txt", m_editorLayer->m_level->m_levelName.c_str())->getCString();
        std::ifstream fileCreated(fileName);

        if (fileCreated) {
            std::cout << "A file for the level '" << m_editorLayer->m_level->m_levelName << "' already exist!" << std::endl;
        }
        else
        {
            std::ofstream file;

            file.open(fileName);

            file << m_editorLayer->m_level->m_levelString.c_str() << std::endl;
            file.close();
            std::cout << "File created!" << std::endl;
        }
    }
};