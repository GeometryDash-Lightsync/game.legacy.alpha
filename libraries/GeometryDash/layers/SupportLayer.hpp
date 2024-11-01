#pragma once

#include <GDLib.h>

class SupportLayer : public GJDropDownLayer, public FLAlertLayerProtocol, public UploadActionDelegate, public UploadPopupDelegate {
public:
	static SupportLayer* create() {
		SupportLayer* pRet = new SupportLayer();

		if (pRet && pRet->init("Support")) {

			pRet->autorelease();

			return pRet;

		}

		CC_SAFE_DELETE(pRet);

		return nullptr;
	}

	static SupportLayer* addToScene() {
		auto layer = SupportLayer::create();
		cocos2d::CCDirector::sharedDirector()
			->getRunningScene()
			->addChild(layer);
		layer->showLayer(false);
		return layer;
	}
};