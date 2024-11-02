#include "includes.h"
#include "lightsync.h"

void CreateAllHooks(uintptr_t base)
{
    Utils::CreateHook(base + 0x178d60, GameManager_countForType_H, &GameManager_countForType);
    Utils::CreateHook(base + 0x311db0, MenuGameLayer_resetPlayer_H, &MenuGameLayer_resetPlayer);    
    Utils::CreateHook(base + 0x30db60, LoadingLayer_init_H, &LoadingLayer_init);
    Utils::CreateHook(base + 0x30e400, LoadingLayer_loadAssets_H, &LoadingLayer_loadAssets);
    Utils::CreateHook(base + 0x3130F0, MenuLayer_init_H, &MenuLayer_init);
    Utils::CreateHook(base + 0x9a300, CreatorLayer_init_H, &CreatorLayer_init);
    Utils::CreateHook(base + 0x261150, GJGarageLayer_init_H, &GJGarageLayer_init);
    Utils::CreateHook(base + 0x269730, ItemInfoPopup_init_H, &ItemInfoPopup_init);
}