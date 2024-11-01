#pragma once

class FMODMusic {
public:
    static constexpr auto CLASS_NAME = "FMODMusic";
    int m_channelID;
    void* m_unk;
    std::string m_filePath;
};