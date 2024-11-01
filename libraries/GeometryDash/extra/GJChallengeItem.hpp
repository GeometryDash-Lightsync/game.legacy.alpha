#include <GDLib.h>

class GJChallengeItem : public cocos2d::CCObject {
public:
    GJChallengeType m_challengeType;
    int m_countSeed;
    int m_countRand;
    int m_count;
    int m_rewardSeed;
    int m_rewardRand;
    int m_reward;
    int m_goalSeed;
    int m_goalRand;
    int m_goal;
    int m_timeLeft;
    bool m_canClaim;
    int m_position;
    std::string m_name;
};