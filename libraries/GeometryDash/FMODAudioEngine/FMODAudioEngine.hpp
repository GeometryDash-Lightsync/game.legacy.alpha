#pragma once

#include <GDLib.h>
#include "FMODMusic.hpp"

class FMODAudioEngine : public cocos2d::CCNode {
public:
    std::unordered_map<int, FMODMusic> m_musicChannels;
    std::unordered_map<void*, void*> m_unkMap180;
    std::unordered_map<void*, void*> m_unkMap1c0;
    float m_musicVolume;
    float m_sfxVolume;
    PAD(8);
    float m_pulse1;
    float m_pulse2;
    float m_pulse3;
    int m_pulseCounter;
    bool m_metering;
    FMOD::Channel* m_backgroundMusicChannel;
    FMOD::System* m_system;
    FMOD::Sound* m_sound;
    FMOD::Channel* m_currentSoundChannel;
    FMOD::Channel* m_globalChannel;
    FMOD::DSP* m_DSP;
    FMOD_RESULT m_lastResult;
    int m_version;
    void* m_extraDriverData;
    int m_musicOffset;
    void* m_audioState;
    PAD(88);
    std::unordered_map<int, FMOD::Channel*> m_channelIDToChannel;
    PAD(512);

    /*
    Similar to the "Shared Director" function. 
    2.200: 0x32B80 (stdcall)
    */
    static FMODAudioEngine* sharedEngine() {
        //return reinterpret_cast<FMODAudioEngine*(__stdcall*)()>
        //    (redecore::getBase() + 0x32B80)();
        auto** instancePtr = reinterpret_cast<FMODAudioEngine**>(redecore::getBase() + 0x687dc0);

        if (!*instancePtr) {

            *instancePtr = new FMODAudioEngine();

            (*instancePtr)->init();

        }

        return *instancePtr;

    };

    FMOD::Channel* getActiveMusicChannel(int musicChannel) {

        // TODO: this might do other checks or whatever but i cant be bothered

        return m_channelIDToChannel[m_musicChannels[musicChannel].m_channelID];

    }


    void pauseMusic(int musicChannel)
    {
        auto* channel = this->getActiveMusicChannel(musicChannel);

        std::cout << "Channel: " << channel << std::endl;

        /*if (channel)

            channel->setPaused(true);*/
    }
private:
    /*
    2.200: 0x380C0
    */

    /**
 * @note[short] Windows: 0x5b170
 * @note[short] Android
 */
    void fadeInMusic(float p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x36bec0
     * @note[short] MacOS (Intel): 0x3ef250
     * @note[short] Windows: 0x5b2b0
     * @note[short] Android
     */
    float fadeOutMusic(float p0, int p1);

    /*
    [Missing]
    2.200:  (...)
    */
    void playMusic(std::string p0, bool p1, float p2, int p3);

    /*
    [Missing]
    2.200: (...)
    */
    void stopAllEffects();

    void pauseAllMusic()
    {
        reinterpret_cast<void(__fastcall*)(FMODAudioEngine*)>
            (redecore::getBase() + 0x59050)(this);
    }
    /*



    2.200: 0x58ec0
    */
    public:
    void resumeAllMusic()
    {
        reinterpret_cast<void(__fastcall*)(FMODAudioEngine*)>
            (redecore::getBase() + 0x58ec0)(this);
    }


    /*
    Plays a sound effect.
    Example: explode_11.ogg
    2.206: 0x55ee0
    */
    void playEffect(std::string file) {
       reinterpret_cast<void(__fastcall*)(FMODAudioEngine*, std::string)>
            (redecore::getBase() + 0x55ee0)(this, file);
    };

    /*
    Plays a sound effect.
    Example: explode_11.ogg
    2.206: 0x55f60
    */
    void playEffect(std::string file, float speed, float p2, float volume) {
        reinterpret_cast<void(__fastcall*)(FMODAudioEngine*, std::string, float, float, float)>
            (redecore::getBase() + 0x55f60)(this, file, speed, p2, volume);
    };
};