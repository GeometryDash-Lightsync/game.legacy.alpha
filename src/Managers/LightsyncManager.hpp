#pragma once
#include "../lightsync.h"

class LightsyncManager : public CCNode, FLAlertLayerProtocol
{
public:
    CCLayer *m_mainLayer;
    MenuLayer *m_menuLayer;
    CCSprite *m_creatorBackground;
    CCLayer *m_bgNode;
    CCLayer *m_videoOptionsLayer;
    CCLayer *m_onlineMenu;
    CCLayer *m_garageLayer;
    LoadingLayer *m_loadingLayer;

    GJGameLevel *m_currentLevel;

    std::string m_gdpsUrl = "-";
    std::vector<BYTE> m_gdpsBytes = {0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x67, 0x64, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x73, 0x79, 0x6e, 0x63, 0x2e, 0x70, 0x73, 0x2e, 0x66, 0x68, 0x67, 0x64, 0x70, 0x73, 0x2e, 0x63, 0x6f, 0x6d, 0x2f};

    float m_pulseTime = 0.00f;

    bool m_practiceEnabled = false;
    bool m_screenEnabled = false;
    bool m_gameInit = false;

    int m_updateCallbackResponse = -1;
    bool m_needUpdate = false;
    std::string m_versionCode = "Awk01";

    bool m_fromReload = false;

    bool m_extraSettingsOpened = false;
    int m_lastOptionPage = 0;

    int m_preloadStep = 0;
    int m_requestAttempts = 0;

    int m_cubeLimit = 484;
    int m_shipLimit = 169;
    int m_ballLimit = 118;
    int m_ufoLimit = 149;
    int m_waveLimit = 96;
    int m_spiderLimit = 69;
    int m_swingLimit = 43;
    int m_jetpackLimit = 5;
    int m_streakLimit = 7;
    int m_shipFireLimit = 6;
    int m_explodeLimit = 20;
    int m_colorLimit = 106;
    int m_robotLimit = 68;

    std::string m_version = "Version 1.0 pre-release 1";

    static LightsyncManager *sharedState();

    bool init()
    {
        m_gdpsUrl = std::string(m_gdpsBytes.begin(), m_gdpsBytes.end());

        return true;
    }

    bool hasAccount()
    {
        if (GJAccountManager::sharedState()->getAccountID() < 1)
            return false;

        return true;
    }

    bool isConnectetToInternet()
    {
        return InternetCheckConnection("http://www.google.com", FLAG_ICC_FORCE_CONNECTION, 0);
    }

    void noWifiAlert()
    {
        FLAlertLayer::create(
            "Womp womp",
            "It seems that you are not connected to the internet.\nPlease check your internet connection and restart the game."
            "\n(The game will be saved after closing it)",
            "Close Game",
            400)
            ->show();
    }

    void showConsole()
    {
        AllocConsole();
        freopen("CONOUT$", "w", stdout);
    }

    int getMaxItemLimit(UnlockType type)
    {
        switch (type)
        {
        case UnlockType::kShip:
            return m_shipLimit;
        case UnlockType::kBall:
            return m_ballLimit;
        case UnlockType::kUfo:
            return m_ufoLimit;
        case UnlockType::kWave:
            return m_waveLimit;
        case UnlockType::kRobot:
            return m_robotLimit;
        case UnlockType::kSpider:
            return m_spiderLimit;
        case UnlockType::kSwing:
            return m_swingLimit;
        case UnlockType::kJetPack:
            return m_jetpackLimit;
        case UnlockType::kDeathEffect:
            return m_explodeLimit;
        case UnlockType::kSpecial:
            return m_streakLimit;
        case UnlockType::kShipFire:
            return m_shipFireLimit;
        case UnlockType::kColor1:
            return m_colorLimit;
        case UnlockType::kColor2:
            return m_colorLimit;
        default:
            return m_cubeLimit;
        }
    }

    void setItemLimit(IconType iconType, int value)
    {
        BYTE var = Utils::intToByte(value);
        switch (iconType)
        {
        case IconType::Ship:
            m_shipLimit = value;
            break;
        case IconType::Ball:

            Utils::patchBytes(redecore::getBase() + 0x37C5A3, {0xB8, var}); // idk

            Utils::patchBytes(redecore::getBase() + 0x172C5E, {0x41, 0x83, 0xC0, var}); // GameManager::init

            Utils::patchBytes(redecore::getBase() + 0x1C7532, {0x44, 0x8D, 0x75, var}); // idk

            Utils::patchBytes(redecore::getBase() + 0x267FD0, {0xBE, var}); // SimplePlayer updatePlayerFrame

            m_ballLimit = value;
            break;
        case IconType::Ufo:

            Utils::patchBytes(redecore::getBase() + 0x37C309, {0xB8, var}); // idk

            Utils::patchBytes(redecore::getBase() + 0x172C6A, {0x41, 0x81, 0xC0, var}); // GameManager::init

            Utils::patchBytes(redecore::getBase() + 0x1C7540, {0x41, 0xBE, var}); // idk

            Utils::patchBytes(redecore::getBase() + 0x267FEF, {0xBE, var}); // SimplePlayer updatePlayerFrame

            m_ufoLimit = value;
            break;
        case IconType::Wave:
            m_waveLimit = value;
            break;
        case IconType::Robot:
            m_robotLimit = value;
            //
            break;
        case IconType::Spider:
            //
            m_spiderLimit = value;
            //
            break;
        case IconType::Swing:

            Utils::patchBytes(redecore::getBase() + 0x37C7D3, {0xB8, var}); // idk

            Utils::patchBytes(redecore::getBase() + 0x172C9D, {0x41, 0x83, 0xC0, var}); // GameManager::init

            Utils::patchBytes(redecore::getBase() + 0x1C759A, {0x44, 0x8D, 0x75, var}); // idk

            Utils::patchBytes(redecore::getBase() + 0x268079, {0xBE, var}); // SimplePlayer updatePlayerFrame

            m_swingLimit = value;
            break;
        case IconType::Jetpack:
            break;
        case IconType::DeathEffect:
            break;
        case IconType::Special:

            Utils::patchBytes(redecore::getBase() + 0x1C756E, {0x44, 0x8D, 0x75, var}); // idk

            Utils::patchBytes(redecore::getBase() + 0x366993, {0x83, 0xFA, var});
            Utils::patchBytes(redecore::getBase() + 0x3669A4, {0xBA, var}); // streak max

            m_streakLimit = value;
            break;
        default:
            auto bytes = Utils::intToBytes(value);

            Utils::patchBytes(redecore::getBase() + 0x3649B5, {0xB8, bytes[0], bytes[1]}); // PlayerObject init

            Utils::patchBytes(redecore::getBase() + 0x37BC73, {0x41, 0xBE, bytes[0], bytes[1]}); // PlayerObject updatePlayerFrame

            Utils::patchBytes(redecore::getBase() + 0x26744A, {0xB8, bytes[0], bytes[1]}); // SimplePlayer init

            Utils::patchBytes(redecore::getBase() + 0x2680C2, {0xBE, bytes[0], bytes[1]}); // SimplePlayer updatePlayerFrame

            Utils::patchBytes(redecore::getBase() + 0x172C40, {0x41, 0x81, 0xC0, bytes[0], bytes[1]}); // GameManager::init

            Utils::patchBytes(redecore::getBase() + 0x1C7512, {0x41, 0xBE, bytes[0], bytes[1]}); // idk
            m_cubeLimit = value;
            break;
        }
    };

    std::string getLoadingString()
    {
        std::vector<std::string> arr =
            {
                "Hola :D",
                "5 Minutes Of Coding Every Day!",
                "Processing Your Blast...",
                "Loading Will Finish When The Sun Turns Bigger",
                ":)",
                "Loading Rage Cannon",
                "Tremenjj",
                "Spikes Of DOOM",
                "Catgirl Supremacy",
                "You must have Geometry Dash in your steam library...",
                "Hey You, Buy Geometry Dash!",
                "Available on Windows!",
                "Android Coming Soon...",
                "A Launcher Would Be Nice...",
                "Also Try Unnamed GDPS!",
                "Copy + Paste",
                "Paste + Copy",
                "Running My Super Ultra Troyan In Your Computer",
                "Hehehe",
                "Starting DOOM",
                "0.1% Virus Free.",
                "The Path Leads To An Old Tower...",
                "Wundws? Windw- Windows!",
                "100% Gluten Free",
                "The Worst Code You Will See :)",
                "In A What?\nWait... Wrong Text.",
                "Pro Tip: Jump",
                "Pro Tip: Don't Crash",
                "What exactly is a Soleum?",
                "Loading the loading screen",
            };
        auto number = rand() % arr.size() + 1;

        auto string = arr[number - 1];
        if (string.empty())
            string = arr[0];

        return string;
    }

    std::string generateHashForFile(std::string filePath)
    {

        try
        {
            std::ifstream file(filePath, std::ios::binary);
            if (!file)
            {
                return "-";
            }

            SHA256_CTX sha256;
            SHA256_Init(&sha256);

            const size_t bufferSize = 32768;
            char buffer[bufferSize];
            while (file.good())
            {
                file.read(buffer, bufferSize);
                SHA256_Update(&sha256, buffer, file.gcount());
            }

            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256_Final(hash, &sha256);

            std::stringstream ss;
            for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
            {
                ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
            }

            return ss.str();
        }
        catch (const std::exception &ex)
        {
            MessageBox(NULL, ex.what(), "Error", MB_ICONERROR | MB_OK);
        }
    }

    std::string sheetNameForIcon(IconType type)
    {
        switch (type)
        {
        case IconType::Ship:
            return "ship";
        case IconType::Ball:
            return "player_ball";
        case IconType::Ufo:
            return "bird";
        case IconType::Wave:
            return "dart";
        case IconType::Robot:
            return "robot";
        case IconType::Spider:
            return "spider";
        case IconType::Swing:
            return "swing";
        case IconType::Jetpack:
            return "jetpack";
        default:
            return "player";
        }
    }

    std::string sheetNameForIcon(IconType type, int id)
    {
        return fmt::format("icons/{}_{:02}", sheetNameForIcon(type), id);
    }

    std::string getFullPathForFile()
    {
        char path[MAX_PATH];

        GetModuleFileName(NULL, path, MAX_PATH);

        std::string fullPath(path);

        size_t posicion = fullPath.find_last_of("\\/");
        if (posicion != std::string::npos)
        {
            fullPath = fullPath.substr(0, posicion);
        }

        return (fullPath + "\\");
    }

    void logObjectsFromDictionary(CCDictionary *dict, bool values)
    {
        auto keys = dict->allKeys();

        for (int i = 0; i < keys->count(); ++i)
        {
            CCString *key = (CCString *)keys->objectAtIndex(i);
            CCString *value = (CCString *)dict->objectForKey(key->getCString());

            if (values)
                fmt::print("Key: {} Value: {} \n", key->getCString(), value->getCString());
            else
                fmt::print("Key: {} \n", key->getCString());
        };
    }

    void logDictionariesFromArray(CCArray *arr, bool values)
    {
        for (int i = 0; i < arr->count(); i++)
        {
            auto dict = (CCDictionary*)arr->objectAtIndex(i);
            auto keys = dict->allKeys();
            CCString *key = (CCString *)keys->objectAtIndex(0);
            CCString *value = (CCString *)dict->objectForKey(key->getCString());
            if (values)
                fmt::print("Key: {} Value: {} \n", key->getCString(), value->getCString());
            else
                fmt::print("Key: {} \n", key->getCString());
        };
    }

    void loadIcons(IconType type)
    {
        if (static_cast<int>(type) > 8)
            return;

        auto tc = CCTextureCache::sharedTextureCache();

        std::string filepath = fmt::format("/icons/{}\n", sheetNameForIcon(type));

        auto max = getMaxItemLimit(gm->IconToUnlock(type));

        const char *q = "uhd";

        auto originalIndex = tc->m_pTextures->allKeys()->count();

        if (ccDir->getLoadedTextureQuality() == TextureQuality::kTextureQualityMedium)
            q = "hd";

        tc->m_pTextures->allKeys()->retain();

        for (int i = 0; i < max; i++)
        {
            std::string sheet = sheetNameForIcon(type, i + 1);

            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile((sheet + ".plist").c_str());
            auto node = CCSpriteBatchNode::create((sheet + ".png").c_str());

            node->release();

            auto fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fmt::format("{}-{}.png", sheet, q).c_str(), false);

            tc->m_pTextures->removeObjectForKey(fullpath);
        }

        // logObjectsFromDictionary(tc->m_pTextures, false);
    }

    void showOfflineAlert(CCObject *)
    {
        FLAlertLayer::create(
            "Offline Mode",
            "You can't use this funciton in the offline mode.",
            240)
            ->show();
    }

    void showPatchNotes()
    {
        FLAlertLayer::create(
            nullptr,
            "Welcome to Lightsync!",
            "Maybe you are so confused and don't know where to start, so, let's summarize what the game brings!\n\n"
            "- Play all 5 main levels!\n\n"
            "- Explore this new GDPS with the new <cr>interface redesign</c>!\n\n"
            "- Want more icons to play with? <cl>Unlock</c> and <cy>buy</c> new icons created by the GDPS community!\n\n"
            "- New effects on difficulty faces depending on how epic your level is! It could even be a... '<cg>Divine</c>' level...\n\n"
            "- Tired of the boring particles that the player drops when walking? How about we change them with the new <cy>cosmetics</c>?!\n\n"
            "- Added <cl>Discord Rich Presence</c> to the game! You can disable it in the <cy>options menu</c> if you don't like it.\n\n"
            "We want to bring more content in the future, adding community suggestions and crazy ideas we have, we hope to have your support in the future and continue improving the game :)\n\n"
            "-  Soleum",
            "Close", nullptr, 400, true, 500, 1

            )
            ->show();
    }

    ccColor3B colorForIdx(int id)
    {
        switch (id)
        {
        case 0:
            return {125, 255, 0};
        case 1:
            return {0, 255, 0};
        case 2:
            return {0, 255, 125};
        case 3:
            return {0, 255, 255};
        case 4:
            return {0, 125, 255};
        case 5:
            return {0, 0, 255};
        case 6:
            return {125, 0, 255};
        case 7:
            return {255, 0, 255};
        case 8:
            return {255, 0, 125};
        case 9:
            return {255, 0, 0};
        case 10:
            return {255, 125, 0};
        case 11:
            return {255, 255, 0};
        case 12:
            return {255, 255, 255};
        case 13:
            return {185, 0, 255};
        case 14:
            return {255, 185, 0};
        case 15:
            return {0, 0, 0};
        case 16:
            return {0, 200, 255};
        case 17:
            return {175, 175, 175};
        case 18:
            return {90, 90, 90};
        case 19:
            return {255, 125, 125};
        case 20:
            return {0, 175, 75};
        case 21:
            return {0, 125, 125};
        case 22:
            return {0, 75, 175};
        case 23:
            return {75, 0, 175};
        case 24:
            return {125, 0, 125};
        case 25:
            return {175, 0, 75};
        case 26:
            return {175, 75, 0};
        case 27:
            return {125, 125, 0};
        case 28:
            return {75, 175, 0};
        case 29:
            return {255, 75, 0};
        case 30:
            return {150, 50, 0};
        case 31:
            return {150, 100, 0};
        case 32:
            return {100, 150, 0};
        case 33:
            return {0, 150, 100};
        case 34:
            return {0, 100, 150};
        case 35:
            return {100, 0, 150};
        case 36:
            return {150, 0, 100};
        case 37:
            return {150, 0, 0};
        case 38:
            return {0, 150, 0};
        case 39:
            return {0, 0, 150};
        case 40:
            return {125, 255, 175};
        case 41:
            return {125, 125, 255};
        case 42:
            return {255, 250, 127};
        case 43:
            return {250, 127, 255};
        case 44:
            return {0, 255, 192};
        case 45:
            return {80, 50, 14};
        case 46:
            return {205, 165, 118};
        case 47:
            return {182, 128, 255};
        case 48:
            return {255, 58, 58};
        case 49:
            return {77, 77, 143};
        case 50:
            return {0, 10, 76};
        case 51:
            return {253, 212, 206};
        case 52:
            return {190, 181, 255};
        case 53:
            return {112, 0, 0};
        case 54:
            return {82, 2, 0};
        case 55:
            return {56, 1, 6};
        case 56:
            return {128, 79, 79};
        case 57:
            return {122, 53, 53};
        case 58:
            return {81, 36, 36};
        case 59:
            return {163, 98, 70};
        case 60:
            return {117, 73, 54};
        case 61:
            return {86, 53, 40};
        case 62:
            return {255, 185, 114};
        case 63:
            return {255, 160, 64};
        case 64:
            return {102, 49, 30};
        case 65:
            return {91, 39, 0};
        case 66:
            return {71, 32, 0};
        case 67:
            return {167, 123, 77};
        case 68:
            return {109, 83, 57};
        case 69:
            return {81, 62, 42};
        case 70:
            return {255, 255, 192};
        case 71:
            return {253, 224, 160};
        case 72:
            return {192, 255, 160};
        case 73:
            return {177, 255, 109};
        case 74:
            return {192, 255, 224};
        case 75:
            return {148, 255, 228};
        case 76:
            return {67, 161, 138};
        case 77:
            return {49, 109, 95};
        case 78:
            return {38, 84, 73};
        case 79:
            return {0, 96, 0};
        case 80:
            return {0, 64, 0};
        case 81:
            return {0, 96, 96};
        case 82:
            return {0, 64, 64};
        case 83:
            return {160, 255, 255};
        case 84:
            return {1, 7, 112};
        case 85:
            return {0, 73, 109};
        case 86:
            return {0, 50, 76};
        case 87:
            return {0, 38, 56};
        case 88:
            return {80, 128, 173};
        case 89:
            return {51, 83, 117};
        case 90:
            return {35, 60, 86};
        case 91:
            return {224, 224, 224};
        case 92:
            return {61, 6, 140};
        case 93:
            return {55, 8, 96};
        case 94:
            return {64, 64, 64};
        case 95:
            return {111, 73, 164};
        case 96:
            return {84, 54, 127};
        case 97:
            return {66, 42, 99};
        case 98:
            return {252, 181, 255};
        case 99:
            return {175, 87, 175};
        case 100:
            return {130, 67, 130};
        case 101:
            return {94, 49, 94};
        case 102:
            return {128, 128, 128};
        case 103:
            return {102, 3, 62};
        case 104:
            return {71, 1, 52};
        case 105:
            return {210, 255, 50};
        case 106:
            return {118, 189, 255};
        default:
            return {255, 255, 255};
        };
    }

    void playMenuAudio(bool secondary)
    {
        FMODAudioEngine::sharedEngine()->playEffect(
            (secondary) ? "a_menu03.ogg" : "a_menu01.ogg");
    }

    int randomCubeId()
    {
        return rand() % getMaxItemLimit(UnlockType::kCube) + 1;
    }

    int randomShipId()
    {
        return rand() % getMaxItemLimit(UnlockType::kShip) + 1;
    }

    int randomBallId()
    {
        return rand() % getMaxItemLimit(UnlockType::kBall) + 1;
    }

    int randomUfoId()
    {
        return rand() % getMaxItemLimit(UnlockType::kUfo) + 1;
    }

    int randomWaveId()
    {
        return rand() % getMaxItemLimit(UnlockType::kWave) + 1;
    }

    int randomRobotId()
    {
        return rand() % getMaxItemLimit(UnlockType::kRobot) + 1;
    }

    int randomSpiderId()
    {
        return rand() % getMaxItemLimit(UnlockType::kSpider) + 1;
    }

    int randomSwingId()
    {
        return rand() % getMaxItemLimit(UnlockType::kSwing) + 1;
    }
};

#define Lightsync LightsyncManager::sharedState()

LightsyncManager *s_sharedLightsyncManager = nullptr;

LightsyncManager *LightsyncManager::sharedState()
{
    if (!s_sharedLightsyncManager)
    {
        s_sharedLightsyncManager = new LightsyncManager();
        s_sharedLightsyncManager->init();
    }
    return s_sharedLightsyncManager;
}