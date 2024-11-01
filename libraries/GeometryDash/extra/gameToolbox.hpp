#pragma once

#include <GDLib.h>

class GameToolbox {

public:
    /*
    2.200: 0x44140 (fastcall)
    */
    static void particleStringToStruct(std::string const& p0, cocos2d::ParticleStruct& p1)
    {
        return reinterpret_cast<void(__fastcall*)(std::string const&, cocos2d::ParticleStruct&)>(
            redecore::getBase() + 0x65f50
            )(p0, p1);
    }

    static cocos2d::CCParticleSystemQuad* particleFromStruct(cocos2d::ParticleStruct const& p0, cocos2d::CCParticleSystemQuad* p1, bool p2)
    {
        return reinterpret_cast<cocos2d::CCParticleSystemQuad * (__fastcall*)(cocos2d::ParticleStruct, cocos2d::CCParticleSystemQuad*, bool)>(
            redecore::getBase() + 0x66a10
            )(p0, p1, p2);
    }


    static cocos2d::CCParticleSystemQuad* particleFromString(std::string const& str, cocos2d::CCParticleSystemQuad* system, bool p2) {
        cocos2d::ParticleStruct ret;


        GameToolbox::particleStringToStruct(str, ret);

        return GameToolbox::particleFromStruct(ret, system, p2);
    };

    /*
        static cocos2d::CCParticleSystemQuad* particleFromString(std::string const& p0, cocos2d::CCParticleSystemQuad* p1, bool p2) {
        return reinterpret_cast<cocos2d::CCParticleSystemQuad * (__fastcall*)(std::string const&, cocos2d::CCParticleSystemQuad*, bool)>(
            redecore::getBase() + 0x66A10
            )(p0, p1, p2);
    };
    */
};