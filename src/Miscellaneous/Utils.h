#include "../lightsync.h"

namespace Utils {

    static ccColor3B grayScaleColor(GLubyte col) { return { col, col, col }; }

    static ccColor4B grayScaleColor(GLubyte col, GLubyte opacity) { return { col, col, col, opacity }; }

	static bool patchBytes(const std::uintptr_t address, std::vector<uint8_t> const& bytes) {
        return WriteProcessMemory(
            GetCurrentProcess(),
            reinterpret_cast<LPVOID>(address),
            bytes.data(),
            bytes.size(),
            nullptr
        );

    }

    static BYTE intToByte(int value) {
        BYTE bytes[4];

        for (int i = 0; i < 4; ++i) {
            bytes[i] = static_cast<BYTE>((value >> (i * 8)) & 0xFF);
        }

        return { bytes[0] };
    }

    static std::vector<BYTE> intToBytes(int value) {

        value &= 0xFFFF;

        BYTE byte1 = static_cast<BYTE>((value >> 8) & 0xFF);
        BYTE byte0 = static_cast<BYTE>(value & 0xFF);

        return { byte0, byte1 };

    }

    static std::vector<int> getSystemTime() {
        time_t now = time(0);
        tm* time = localtime(&now);
        return { time->tm_hour, time->tm_min, time->tm_sec };
    }

    static int getCurrentDay() {
        time_t now = time(0);
        tm* time = localtime(&now);
        return time->tm_mday;
    }

    static int getCurrentYear() {
        time_t now = time(0);
        tm* time = localtime(&now);
        return time->tm_year;
    }

    static int getCurrentMonth() {
        time_t now = time(0);
        tm* time = localtime(&now);
        return time->tm_mon + 1;
    }

    template <typename FuncType>

    static bool CreateHook(uintptr_t address, LPVOID detour, FuncType* original) {
        auto _hook = MH_CreateHook(
                reinterpret_cast<void*>(address), 
                detour,
                reinterpret_cast<void**>(original)
        );

        if (_hook != MH_OK)
            return false;

        return true;
    }

    void hideRandomChildFromParent(CCNode* parent) {
        srand(time(NULL));

         
        int count = parent->getChildrenCount();

        auto num = rand() % count + 1;

        auto obj = reinterpret_cast<CCNode*>(parent->getChildren()->objectAtIndex(num - 1));
        obj->setVisible(false);

        fmt::print("{}:{}\n", num, count);
    }
}