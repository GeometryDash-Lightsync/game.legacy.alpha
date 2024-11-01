#pragma once

#include <GDLib.h>

class EditLevelLayer : public cocos2d::CCLayer, public FLAlertLayerProtocol
{    
//, public TextInputDelegate, , public UploadActionDelegate, public UploadPopupDelegate, public SetIDPopupDelegate 
public:
    cocos2d::CCMenu* m_buttonMenu;
    GJGameLevel* m_level;
    TextArea* m_descriptionInput;
    cocos2d::CCArray* m_someArray;
    cocos2d::CCLabelBMFont* m_folderLabel;
    bool m_unk;
    bool m_lowDetailModeTriggered;
    GJLevelType m_levelType;
};