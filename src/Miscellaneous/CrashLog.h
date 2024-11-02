#include "../lightsync.h"
#include <DbgHelp.h>
#pragma comment(lib, "Dbghelp.lib")

void ShowCrashMessage(EXCEPTION_POINTERS* pExceptionInfo) {
    std::stringstream ss;
    ss << "Game Crashed!\n\n";
    ss << "Exception code: 0x" << std::hex << pExceptionInfo->ExceptionRecord->ExceptionCode << "\n";
    ss << "Exception address: 0x" << pExceptionInfo->ExceptionRecord->ExceptionAddress << "\n";
    ss << "New dmp file created in CrashDumps folder.\n";

    MessageBoxA(nullptr, ss.str().c_str(), "Error", MB_OK | MB_ICONERROR);
}

LONG WINAPI ExceptionHandler(EXCEPTION_POINTERS* pExceptionInfo) {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    char date[16];
    strftime(date, sizeof(date), "%Y-%m-%d", ltm);
    std::string directoryPath = "./CrashDumps/" + std::string(date);

    std::filesystem::create_directories(directoryPath);

    char timeStr[16];
    strftime(timeStr, sizeof(timeStr), "%H-%M-%S", ltm);
    std::string dumpFileName = directoryPath + "/crash_" + timeStr + ".dmp";

    HANDLE hFile = CreateFileA(dumpFileName.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (hFile != INVALID_HANDLE_VALUE) {
        MINIDUMP_EXCEPTION_INFORMATION mdei;
        mdei.ThreadId = GetCurrentThreadId();
        mdei.ExceptionPointers = pExceptionInfo;
        mdei.ClientPointers = FALSE;

        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpWithDataSegs, &mdei, nullptr, nullptr);
        CloseHandle(hFile);
    }
     ShowCrashMessage(pExceptionInfo);

    return EXCEPTION_EXECUTE_HANDLER;
}