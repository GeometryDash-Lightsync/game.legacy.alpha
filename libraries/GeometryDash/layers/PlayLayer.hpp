#pragma once
#include <GDLib.h>


class PlayLayer : public GJBaseGameLayer {
public:
    PAD(48);
    cocos2d::CCArray* m_coinArray;
    PAD(112);
    cocos2d::CCLabelBMFont* m_statusLabel;
    int m_unk3778;
    PAD(24);
    float m_unkSomeFloat;
    CCObject* m_currentCheckpoint;
    cocos2d::CCArray* m_checkpointArray;
    cocos2d::CCArray* m_unk37a8;
    int m_unk37b0;
    int m_unk37b4;
    int m_unk37b8;
    cocos2d::CCArray* m_unk37c0;
    int m_unk37c8;
    int m_unk37cc;
    cocos2d::CCArray* m_circleWaveArray;
    cocos2d::CCArray* m_unk37d8;
    int m_unk37e0;
    int m_unk37e4;
    float m_unk37e8;
    cocos2d::CCLabelBMFont* m_attemptLabel;
    cocos2d::CCLabelBMFont* m_percentageLabel;
    bool m_0126;
    cocos2d::CCSprite* m_progressBar;
    cocos2d::CCSprite* m_progressFill;
    PAD(125);
    bool m_hasCompletedLevel;
    PAD(6);
    bool m_endLayerStars;
    PAD(98);
    bool m_isPaused;
    PAD(24);
    cocos2d::CCDictionary* m_colorKeyDict;
    std::vector<int> m_keyColors;
    std::vector<int> m_keyOpacities;
    std::vector<int> m_keyPulses;
    int m_nextColorKey;
    PAD(40);
};