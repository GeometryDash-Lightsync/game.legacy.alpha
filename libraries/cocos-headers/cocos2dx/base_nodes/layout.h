#pragma once
#include <cocos2d.h>

#pragma warning(disable: 4273)

void cocos2d::CCNode::setContentWidth(float width) { this->setContentSize({ width, m_obContentSize.height }); }
void cocos2d::CCNode::setContentHeight(float height) { this->setContentSize({ m_obContentSize.width, height }); }
float cocos2d::CCNode::getContentWidth() const { return getContentSize().width; }
float cocos2d::CCNode::getContentHeight() const { return getContentSize().height; }