#include <GDLib.h>
#include "../managers/SongInfoObject.hpp"

class MusicDownloadDelegate {
public:
	void loadSongInfoFinished(SongInfoObject* p0) {}

	void loadSongInfoFailed(int p0, GJSongError p1) {}

	void downloadSongFinished(int p0) {}

	void downloadSongFailed(int p0, GJSongError p1) {}

	void songStateChanged() {}

	void downloadSFXFinished(int p0) {}

	void downloadSFXFailed(int p0, GJSongError p1) {}

	void musicActionFinished(GJMusicAction p0) {}

	void musicActionFailed(GJMusicAction p0) {}
};