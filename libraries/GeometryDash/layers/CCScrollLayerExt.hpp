#ifndef __CCSCROLLLAYEREXT_HPP__
#define __CCSCROLLLAYEREXT_HPP__

#include <GDLib.h>

class CCScrollLayerExt : public cocos2d::CCLayer {
public:
    cocos2d::CCTouch* m_touch;
    cocos2d::CCPoint m_touchPosition;
    cocos2d::CCPoint m_touchStartPosition;
    cocos2d::cc_timeval m_timeValue;
    bool m_touchDown;
    bool m_notAtEndOfScroll;
    cocos2d::CCLayerColor* m_verticalScrollbar;
    cocos2d::CCLayerColor* m_horizontalScrollbar;
    TodoReturn* m_delegate;
    cocos2d::CCLayerColor* m_contentLayer; //CCContentLayer
    bool m_cutContent;
    bool m_vScrollbarVisible;
    bool m_hScrollbarVisible;
    bool m_disableHorizontal;
    bool m_disableVertical;
    bool m_disableMovement;
    float m_scrollLimitTop;
    float m_scrollLimitBottom;
    float m_peekLimitTop;
    float m_peekLimitBottom;

};

#endif 

