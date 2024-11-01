#ifndef __TABLEVIEWCELL_HPP__
#define __TABLEVIEWCELL_HPP__
#include <GDLib.h>

class TableView;
class CCIndexPath;

class TableViewCell : public cocos2d::CCLayer {
public:
    void* m_unknown3;
    void* m_unknown4;
    void* m_unknown;
    void* m_tableView;
    CCIndexPath m_indexPath;
    void* m_unknown2;
    std::string m_unknownString;
    float m_width;
    float m_height;
    cocos2d::CCLayerColor* m_backgroundLayer;
    cocos2d::CCLayer* m_mainLayer;
    BoomListType m_listType;

};

#endif