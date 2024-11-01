#pragma once
#include <GDLib.h>


class ChallengesPage : public FLAlertLayer, public FLAlertLayerProtocol { //, public GJChallengeDelegate, public CurrencyRewardDelegate
public:
    void* unk0;
    void* unk1;
    cocos2d::CCArray* m_dots;
    cocos2d::CCLabelBMFont* m_countdownLabel;
    LoadingCircle* m_circle;
    bool m_triedToLoad;
    bool m_unkBool;
    cocos2d::CCNode* m_currencyRewardLayer;
    cocos2d::CCDictionary* m_challengeNodes;
};