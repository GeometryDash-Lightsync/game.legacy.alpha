#pragma once

#include <GDLib.h>

class GJAccountManager : public cocos2d::CCNode {
public:
    cocos2d::CCDictionary* m_activeDownloads;
    std::string m_username;
    int m_accountID;
    int m_unkInt1;
    int m_unkInt2;
    std::string m_GJP2;
    void* m_accountRegisterDelegate;
    void* m_accountLoginDelegate;
    void* m_accountDelegate;
    void* m_backupDelegate;
    void* m_syncDelegate;
    void* m_accountSettingsDelegate;
    int m_gameManagerSize;
    int m_localLevelsSize;
    std::string m_password;

public:
    static GJAccountManager* sharedState() {
        return reinterpret_cast<GJAccountManager * (__stdcall*)()>(
            redecore::getBase() + 0x1f1220
            )();
    }

    const char* getPassword() {
        return this->m_password.c_str();
    }
    const char* getUsername() {
        return this->m_username.c_str();
    }

    int getAccountID() {
        return this->m_accountID;
    }

};

