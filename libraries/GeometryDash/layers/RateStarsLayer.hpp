#pragma once

#include <GDLib.h>

class RateStarsLayer : public FLAlertLayer, public UploadPopupDelegate, public UploadActionDelegate {
public:
	PAD(16);
	int m_starsRate;
};