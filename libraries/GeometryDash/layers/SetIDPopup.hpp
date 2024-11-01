#pragma once
#include <GDLib.h>
#include "../delegates/SetIDPopupDelegate.hpp"
#include "../extra/CCTextInputNode.hpp"
#include "../layers/FLALertlayer.hpp"

class FLAlertLayer;
class SetIDPopupDelegate;

class SetIDPopup : public FLAlertLayer, public TextInputDelegate {
public:
    CCTextInputNode* m_inputNode;
    int m_value;
    bool m_unkBool;
    bool m_cancelled;
    int m_minimum;
    int m_maximum;
    int m_default;
    SetIDPopupDelegate* m_delegate;
};