#pragma once
#include <GDLib.h>

class MusicDownloadManager : public cocos2d::CCNode {
public:
    void* unk0;
    cocos2d::CCDictionary* m_activeDownloads;
    cocos2d::CCArray* m_musicDownloadDelegates;
    cocos2d::CCDictionary* m_songObjects;
    cocos2d::CCDictionary* m_MDLM003;
    int m_songPriority;
    std::string m_customContentURL;
    cocos2d::CCDictionary* m_sfxObjects;
    cocos2d::CCArray* m_sfxArtists;
    int m_sfxLibraryVersion;
    int m_sfxObjectCount;
    bool m_requestedSfxLibraryDownloaded;
    cocos2d::CCDictionary* m_musicObjects;
    cocos2d::CCDictionary* m_musicArtists;
    std::map<int, std::string> m_musicTags;
    int m_musicLibraryVersion;
    int m_musicObjectCount;
    bool m_requestedMusicLibraryDownloaded;
    bool m_triedToLoadLibraries;
    bool m_unkBool;
    std::unordered_set<int> m_resourceSfxUnorderedSet;
    std::unordered_set<int> m_resourceSongUnorderedSet;
	static MusicDownloadManager* sharedState() {
		return reinterpret_cast<MusicDownloadManager * (__fastcall*)()>(
			redecore::getBase() + 0x31bca0
			)();
	}

	std::string pathForSFXFolder(int p0) {
		return reinterpret_cast<std::string(__fastcall*)(MusicDownloadManager*, int)>(
				redecore::getBase() + 0x31e5e0
				)(
					this, p0
					);
	}
};