#pragma once

#include <GDLib.h>

class BoomListView : public cocos2d::CCLayer, public TableViewDelegate  {//TableViewDataSource
public:
    void* unk0;
    void* unk1;
    TableView* m_tableView;
    cocos2d::CCArray* m_entries;
    BoomListType m_type;
    float m_height;
    float m_width;
    float m_itemSeparation;
    int m_currentPage;
    bool m_locked;
};