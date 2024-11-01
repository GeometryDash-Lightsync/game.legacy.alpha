#pragma once

#include <GDLib.h>

class CreatorLayer : public cocos2d::CCLayer {
public:
    /*
    2.200: 0x6FE90
    */
    void onMyLevels(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9b4a0)(this, pSender);
    }

    /*
    2.200: 0x6FF80
    */
    void onSaved(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9b6b0)(this, pSender);
    }

    /*
    2.200: 0x70060
    */
    void onLeaderboards(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9b8b0)(this, pSender);
    }

    /*
    2.200: 0x70910
    */
    void onQuests(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__fastcall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9c770)(this, pSender);
    }


    /*
    2.200: 0x70330
    */
    void onVersus(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__fastcall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9bdd0)(this, pSender);
    }

    /*
    2.200: 0x9c3a0
    */
    void onAdventureMap(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9c3a0)(this, pSender);
    }

    /*
    2.200: 0x70700
    */
    void onDaily(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9c510)(this, pSender);
    }


    /*
    2.200: 0x70720
    */
    void onWeekly(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9c530)(this, pSender);
    }

    /*
    2.200: 0x70740
    */
    void onEventLevel(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9c550)(this, pSender);
    }


    /*
    2.200: 0x702D0
    */
    void onGauntlets(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__fastcall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9b8b0)(this, pSender);
    }

    /*
    2.200: 0x700C0
    */
    void onFeaturedLevel(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9ba60)(this, pSender);
    }

    /*
    2.200: 0x70160
    */
    void onLists(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9bb40)(this, pSender);
    }

    /*
    2.200: 0x70140
    */
    void onPaths(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9bb20)(this, pSender);
    }

    /*
    2.200: 0x70250
    */
    void onMapPacks(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9bc90)(this, pSender);
    }

    /*
    2.200: 0x701E0
    */
    void onSearch(cocos2d::CCObject* pSender) {
        reinterpret_cast<void(__thiscall*)(
            CreatorLayer*, cocos2d::CCObject*
            )>(redecore::getBase() + 0x9bc10)(this, pSender);
    }

};
