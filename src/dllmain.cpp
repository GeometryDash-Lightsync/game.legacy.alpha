#include "includes.h"
#include "Lightsync.hpp"

auto base = redecore::getBase();


DWORD WINAPI thread_func(void* hModule) { 

    MH_Initialize();

    //Lightsync->showConsole();

    /*  Sfx - Mightor level end */
    MusicDownloadManager::sharedState()->m_resourceSfxUnorderedSet.insert(6082);

    /* More icones */
    Lightsync->setItemLimit(517, IconType::Cube);
    Lightsync->setItemLimit(129, IconType::Ball);
    Lightsync->setItemLimit(151, IconType::Ufo);
    Lightsync->setItemLimit(50, IconType::Swing);
    Lightsync->setItemLimit(10, IconType::Special);

    utils::CreateHook(base + 0x178d60, GameManager_countForType_H, &GameManager_countForType);

    utils::CreateHook(base + 0x311db0, MenuGameLayer_resetPlayer_H, &MenuGameLayer_resetPlayer);
    
    /* Menus*/
    utils::CreateHook(base + 0x30db60, LoadingLayer_init_H, &LoadingLayer_init);
    utils::CreateHook(base + 0x30e400, LoadingLayer_loadAssets_H, &LoadingLayer_loadAssets);

    utils::CreateHook(base + 0x3130F0, MenuLayer_init_H, &MenuLayer_init);

    utils::CreateHook(base + 0x9a300, CreatorLayer_init_H, &CreatorLayer_init);

    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}


BOOL APIENTRY DllMain(HMODULE handle, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0x100, thread_func, handle, 0, 0);

    }
    return TRUE;
}