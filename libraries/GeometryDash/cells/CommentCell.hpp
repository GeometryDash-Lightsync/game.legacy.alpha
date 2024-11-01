#pragma once
#include <GDLib.h>

#include "../extra/FLAlertProtocol.hpp"
#include "../managers/GJComment.hpp"

class CommentCell : public TableViewCell, public FLAlertLayerProtocol {
public:
	void* unk0;
	cocos2d::CCSprite* m_iconSprite;
	cocos2d::CCLabelBMFont* m_likeLabel;
	GJComment* m_comment;
	bool m_accountComment;
};