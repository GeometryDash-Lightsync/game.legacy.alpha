#pragma once
#include "../Lightsync.hpp"

void(__fastcall *MenuGameLayer_resetPlayer)(MenuGameLayer *);
void __fastcall MenuGameLayer_resetPlayer_H(MenuGameLayer *_this)
{
    MenuGameLayer_resetPlayer(_this);

    auto player = _this->m_playerObject;

    if (player->m_isBall)
    {
        player->updatePlayerRollFrame(Lightsync->randomBallId());
    }
    else if (player->m_isDart)
    {
        player->updatePlayerDartFrame(Lightsync->randomWaveId());
    }
    else if (player->m_isRobot)
    {
        player->updatePlayerRobotFrame(Lightsync->randomRobotId());
    }
    else if (player->m_isSpider)
    {
        player->updatePlayerSpiderFrame(Lightsync->randomSpiderId());
    }
    else if (player->m_isSwing)
    {
        player->updatePlayerSwingFrame(Lightsync->randomSwingId());
    }
    else
    {
        player->updatePlayerFrame(Lightsync->randomCubeId());
        if (player->m_isShip)
        {
            player->updatePlayerShipFrame(Lightsync->randomShipId());
        }
        else if (player->m_isBird)
        {
            player->updatePlayerBirdFrame(Lightsync->randomUfoId());
        }
    }
}