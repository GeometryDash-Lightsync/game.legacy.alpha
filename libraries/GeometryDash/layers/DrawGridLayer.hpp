#pragma once
#include <GDLib.h>

class LevelEditorLayer;

class DrawGridLayer : public cocos2d::CCLayer {
public:
    LevelEditorLayer* m_editorLayer;
    PAD(108);
    float m_gridSize;
};
