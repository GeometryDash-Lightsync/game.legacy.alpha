#pragma once

#include <GDLib.h>

#include "../managers/GJGameLevel.hpp"
#include "../sprites_nodes/CCMenuItemSpriteExtra.hpp"
#include "../sprites_nodes/CCMenuItemToggler.hpp"

/*class CCMenuItemSpriteExtra;
class GJGameLevel;
class CCMenuItemToggler;*/

class LevelCell : public TableViewCell {
public:
    CCMenuItemSpriteExtra* m_button;
    GJGameLevel* m_level;
    bool m_cellDrawn;
    CCMenuItemToggler* m_toggler;
    cocos2d::CCPoint m_point;
    cocos2d::CCMenu* m_mainMenu;
    bool m_compactView;
    int m_cellMode;
};