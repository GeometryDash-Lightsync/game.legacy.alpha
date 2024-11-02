#include "includes.h"
#include "lightsync.h"
#include "dllhooks.h"

auto base = redecore::getBase();

DWORD WINAPI thread_func(void* hModule) { 

    SetUnhandledExceptionFilter(ExceptionHandler); 

    LSIconDataManager::sharedState()->removeGDAchievements();

    if (MH_Initialize() != MH_OK) {
        return 1;
    };

    /*  Sfx - Nightor level end */
    MusicDownloadManager::sharedState()->m_resourceSfxUnorderedSet.insert(6082);

    Lightsync->showConsole();

    /* More icons */
    Lightsync->setItemLimit(IconType::Cube, 517);
    Lightsync->setItemLimit(IconType::Ball, 129);
    Lightsync->setItemLimit(IconType::Ufo, 151);
    Lightsync->setItemLimit(IconType::Swing, 50);
    Lightsync->setItemLimit(IconType::Special, 10);

    CreateAllHooks(base);

    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}

BOOL APIENTRY DllMain(HMODULE handle, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0x100, thread_func, handle, 0, 0);
    }

    return TRUE;
}