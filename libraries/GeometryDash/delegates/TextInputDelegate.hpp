#pragma once
#include <GDLib.h>

#include "../extra/CCTextInputNode.hpp"

class CCTextInputNode;

class TextInputDelegate {
public:
	void textChanged(CCTextInputNode* p0);

	void textInputOpened(CCTextInputNode* p0);

	void textInputClosed(CCTextInputNode* p0);

	void textInputShouldOffset(CCTextInputNode* p0, float p1);

	void textInputReturn(CCTextInputNode* p0);

	bool allowTextInput(CCTextInputNode* p0);

	void enterPressed(CCTextInputNode* p0);
};