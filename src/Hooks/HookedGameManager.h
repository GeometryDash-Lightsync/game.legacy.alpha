#include "../lightsync.hpp"

int(__fastcall* GameManager_countForType)(GameManager*, IconType);
int __fastcall GameManager_countForType_H(GameManager* _this, IconType type)
{
	return Lightsync->getMaxItemLimit(_this->IconToUnlock(type));
}



CCTexture2D* (__fastcall* GameManager_loadIcon)(GameManager*, int, int, int);
CCTexture2D* __fastcall GameManager_loadIcon_H(GameManager* _this, int iconId, int iconType, int iconRequestId)
{
	CCTexture2D* texture = GameManager_loadIcon(_this, iconId, iconType, iconRequestId);


	fmt::print("{} {} {}\n", iconId, iconType, iconRequestId);

	if (texture) {
		return texture;
	}
}