#pragma once
#include <GDLib.h>;

class SongInfoObject : public cocos2d::CCNode
{
public:
    int m_songID;
    std::string m_songName;
    std::string m_artistName;
    std::string m_youtubeVideo;
    std::string m_youtubeChannel;
    std::string m_songUrl;
    std::string m_artistID;
    float m_fileSize;
    bool m_isUnkownSong;
    int m_priority;
};