#pragma once

#include <GDLib.h>

#include "FLALertlayer.hpp"
#include "../delegates/UploadPopupDelegate.hpp"

class FLAlertLayer;
class UploadPopupDelegate;
class TextArea;
class LoadingCircle;
class CCMenuItemSpriteExtra;

class UploadActionPopup : public FLAlertLayer {
    UploadPopupDelegate* m_delegate;
    TextArea* m_textArea;
    LoadingCircle* m_loadingCircle;
    CCMenuItemSpriteExtra* m_menuItemSpriteExtra;
    bool m_succeeded;
};