#pragma once
#include <GDLib.h>
class TableView;
class TableViewCell;

class TableViewDelegate
{

    virtual void willTweenToIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2);

    virtual void didEndTweenToIndexPath(CCIndexPath& p0, TableView* p1);

    virtual void TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2);

    virtual void TableViewDidDisplayCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2);

    virtual void TableViewWillReloadCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2);

    virtual float cellHeightForRowAtIndexPath(CCIndexPath& p0, TableView* p1);

    virtual void didSelectRowAtIndexPath(CCIndexPath& p0, TableView* p1);
};