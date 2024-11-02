#include "../lightsync.h"

class LoadingLayerExt : public LoadingLayer {
public:


    CCLabelBMFont* getLoadingLabel() {
        return (CCLabelBMFont*) this->getChildByTag(1000);
    }

    void checkForUpdates() {
        this->getLoadingLabel()->setString("Checking For Updates");

        //if (m_requestAttempts < 0 && m_requestAttempts > 600) m_requestAttempts = 0;
        

        auto request = new extension::CCHttpRequest();

        std::string url = "https://raw.githubusercontent.com/Chumiu/lightSync-test/master/test.txt";// fmt::format("{}/version", Lightsync->m_gdpsUrl);
        request->setUrl(url.c_str());

        request->setRequestType(extension::CCHttpRequest::kHttpGet);

        request->setResponseCallback(this, httpresponse_selector(LoadingLayerExt::doRequest));

        extension::CCHttpClient::getInstance()->send(request);
        
    }



    void verifyResources()
    {
        if (Lightsync->m_preloadStep < 0 || Lightsync->m_preloadStep > 7) Lightsync->m_preloadStep = 0;

        if (Lightsync->m_preloadStep < 7) {

            if (this->getLoadingLabel()) this->getLoadingLabel()->setString("Verifying Resources");

            std::string hash1 = Lightsync->generateHashForFile("Lightsync.exe");
            std::string realHash1 = "e11daa6e90fd68684a1ee195f0d84760dae61aef71990c8b58cdf974671f4510";

            std::string hash2 = Lightsync->generateHashForFile("FMOD.dll");
            std::string realHash2 = "ba377c62ad807fe17e4177b46259237035e544a5893367e296fbae07b11b1bcb";

            std::string hash3 = Lightsync->generateHashForFile("glew32.dll");
            std::string realHash3 = "842a3f20177eb44ac0413116c66430f9508bf88a05fcdab14284a566d5d0774f";


            switch (Lightsync->m_preloadStep)
            {
            case 1:
                hash1 = Lightsync->generateHashForFile("jpeg62.dll");
                realHash1 = "de96d250f25fd6a50add6cea1e6abdedd4e56c05aebd1706e8255d5a4e0b2f1d";

                hash2 = Lightsync->generateHashForFile("legacy.dll");
                realHash2 = "0e7cda5a19c5313666db3ed74aac84b3d679f8f0704a03044b988bbfa9857042";

                hash3 = Lightsync->generateHashForFile("libcocos2d.dll");
                realHash3 = "8411a475caf9ad19e091a0625e5a7f96e83d72ff4ae1b858a16f2bed1791c8e9";
                break;

            case 2:
                hash1 = Lightsync->generateHashForFile("libcrypto-3-x64.dll");
                realHash1 = "c5976bb8527b63d8667891da7807555b1941d44e1c0bf202c62c72212794535f";

                hash2 = Lightsync->generateHashForFile("libcurl.dll");
                realHash2 = "3ffb64501f5dde0a7fd817bea0bda3e470fa58c6ccb7500e1b3758ef316ff396";

                hash3 = Lightsync->generateHashForFile("liblzma.dll");
                realHash3 = "b8725ff8b702429be2ccd86d5b91099f08ea7427708348b8ee99566b295d1ee5";
                break;

            case 3:
                hash1 = Lightsync->generateHashForFile("libssl-3-x64.dll");
                realHash1 = "1bea1193f8f103c077cc09f913216685de246bf9b5234ea89976d07ee4d8f7e5";

                hash2 = Lightsync->generateHashForFile("pthreadVC3.dll");
                realHash2 = "7e6417c37145bcb72efbcb97053a793ea92ac3efaa93673b1e4b578be3501ff3";

                hash3 = Lightsync->generateHashForFile("pthreadVCE3.dll");
                realHash3 = "49fd35b5d137aa20c97edd9542e9d26072c6668d7769694694a73d7ee9840bae";
                break;

            case 4:
                hash1 = Lightsync->generateHashForFile("pthreadVSE3.dll");
                realHash1 = "780080e2049076bd4833ec639194de0604829fc0f0ff1a37b9223938ac9e1ef0";

                hash2 = Lightsync->generateHashForFile("sdkencryptedappticket64.dll");
                realHash2 = "151b53f46c0d163ac2b47531508df942a92295fe75cbaa99e481339cb4ae82f3";

                hash3 = Lightsync->generateHashForFile("sqlite3.dll");
                realHash3 = "e1187d49a14af178ca19ed8561aa88be1bd24a0fb61837f78b38136124155007";
                break;
            case 5:

                hash1 = Lightsync->generateHashForFile("steam_api64.dll");
                realHash1 = "0cfe547ea82071953cf99daffa3bd11bb468eec0e400961e7e33e4dc36674ea8";

                hash2 = Lightsync->generateHashForFile("tiff.dll");
                realHash2 = "4aa9fbc89abbe56f4d493f5649a2aec1e90230c69919eab223a1de1e48043bc6";

                hash3 = Lightsync->generateHashForFile("turbojpeg.dll");
                realHash3 = "b1fcb7c7c8ab4903f6eb84cb3a12ff92597d069f3ec3154fc3782de0385568fb";
                break;

            case 6:

                hash1 = Lightsync->generateHashForFile("uv.dll");
                realHash1 = "f8a8031438bcc91a8c6b5c7e12f60c95ec6e55012b1b81117780a40e15a0315e";

                hash2 = Lightsync->generateHashForFile("websockets.dll");
                realHash2 = "1690f0dc02d8f5232c02c182377efea0a9ef795cb09e98d82e126b0b6e616467";

                hash3 = Lightsync->generateHashForFile("XInput1_4.dll");
                realHash3 = "144622c53d2e4b3d721b35d30a5f3ea78d5297bb758d8b043e4247880901cd02";

                auto hash4 = Lightsync->generateHashForFile("zlib1.dll");
                auto realHash4 = "7d2e3f94feb47f7260648b4fb75bde90b9669ee04402fb470c11a1bacb1a90f1";

                if (hash4.compare(realHash4) != 0) Lightsync->m_screenEnabled = true;

                break;

            }


            if (hash1.compare(realHash1) + hash2.compare(realHash2) + hash3.compare(realHash3) != 0)
            {
                Lightsync->m_screenEnabled = true;
            }

            Lightsync->m_preloadStep += 1;

            this->runAction(
                CCSequence::createWithTwoActions(
                    CCDelayTime::create(.25f),
                    CCCallFunc::create(this, callfunc_selector(LoadingLayerExt::verifyResources))
                )
            );
        }
        else if (Lightsync->m_preloadStep == 7) {

            this->runAction(
                CCSequence::createWithTwoActions(
                    CCDelayTime::create(.5f),
                    CCCallFunc::create(this, callfunc_selector(LoadingLayerExt::preloadIcons))
                )
            );
        }

    }

        void doRequest(extension::CCHttpClient* sender, extension::CCHttpResponse* response) {
        Lightsync->m_requestAttempts++;

        if (!response) {
            Lightsync->m_updateCallbackResponse = -2;
            this->verifyResources();
        }
        if (!response->isSucceed()) {
            if (response->getResponseCode() == -1 && Lightsync->m_requestAttempts < 500) {
	        this->checkForUpdates();
            }
            else {
                Lightsync->m_updateCallbackResponse = response->getResponseCode();
                this->verifyResources();
                
            }
            return;
        }

        std::vector<char>* buffer = response->getResponseData();
        std::string responseData(buffer->begin(), buffer->end());

        Lightsync->m_needUpdate = (responseData.compare(Lightsync->m_versionCode) == 0);

        Lightsync->m_updateCallbackResponse = 0;

        this->verifyResources();
        
    }


    void preloadIcons() {

        UnlockType item = gm->IconToUnlock(static_cast<IconType>(Lightsync->m_preloadStep - 8));

        if (this->getLoadingLabel() && Lightsync->m_preloadStep < 16) 
            this->getLoadingLabel()->setString(fmt::format("Preloading Icons: {}s", gm->getItemName(item)).c_str());

        switch (Lightsync->m_preloadStep)
        {
        case 7: Lightsync->loadIcons(IconType::Cube); break;
        case 8: Lightsync->loadIcons(IconType::Ship); break;
        case 9: Lightsync->loadIcons(IconType::Ball); break;
        case 10: Lightsync->loadIcons(IconType::Ufo); break;
        case 11: Lightsync->loadIcons(IconType::Wave); break;
        case 12: Lightsync->loadIcons(IconType::Robot); break;
        case 13: Lightsync->loadIcons(IconType::Spider); break;
        case 14: Lightsync->loadIcons(IconType::Swing); break;
        case 15: Lightsync->loadIcons(IconType::Jetpack); break;
        case 16: LSIconDataManager::sharedState()->setData(); break;     
        }

        if (Lightsync->m_preloadStep < 17) {
            Lightsync->m_preloadStep++;

            this->runAction(
                CCSequence::createWithTwoActions(
                    CCDelayTime::create(.5f),
                    CCCallFunc::create(this, callfunc_selector(LoadingLayerExt::preloadIcons))
                )
            );

        }
        else {
            this->getLoadingLabel()->setString("Loading Textures");

            this->runAction(
                CCSequence::createWithTwoActions(
                    CCDelayTime::create(.5f),
                    CCCallFunc::create(this, callfunc_selector(LoadingLayer::loadAssets))
                )
            );
        }
    }
};



void(__fastcall* LoadingLayer_loadAssets)(LoadingLayerExt*);
void __fastcall LoadingLayer_loadAssets_H(LoadingLayerExt* _this) {
    Lightsync->m_requestAttempts = 0;

    if (!_this->m_fromRefresh && Lightsync->m_preloadStep != 17) _this->checkForUpdates();
    else LoadingLayer_loadAssets(_this);

}

bool(__fastcall* LoadingLayer_init)(LoadingLayerExt*, bool);
bool __fastcall LoadingLayer_init_H(LoadingLayerExt* _this, bool fromRefresh) {

    if (!LoadingLayer_init(_this, fromRefresh)) return false;

    Lightsync->m_loadingLayer = _this;
    Lightsync->m_fromReload = fromRefresh;

    auto size = ccDir->getWinSize();

    //hiding some things from the old layer
    reinterpret_cast<CCSprite*>(_this->getChildren()->objectAtIndex(7))->setOpacity(0);



    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GJ_LaunchSheet.plist");
    _this->addChild(CCSpriteBatchNode::create("GJ_LaunchSheet.png"));

    auto bg = CCLayerColor::create({20, 20, 20, 255}, size.width, size.height);
    _this->addChild(bg, 1);


    const char* loadingText = "Loading Textures";

    if (fromRefresh) loadingText = "Reloading Textures...";

    auto InfoLabel = CCLabelBMFont::create(
        loadingText,
        "goldFont.fnt"
    );

    InfoLabel->setScale(.5f);
    InfoLabel->setAnchorPoint({ .5f, .5f });
    InfoLabel->setPosition({ size.width / 2, 85 });
    InfoLabel->setTag(1000);
    
    _this->addChild(InfoLabel, 9);

    auto bgSmall = CCLayerColor::create({ 0,0, 0, 255 }, 215, 5);
    bgSmall->ignoreAnchorPointForPosition(false);

    bgSmall->setAnchorPoint({ .5f, .5f });

    bgSmall->setPosition({ size.width / 2, size.height / 2 - 60 });


    _this->addChild(bgSmall, 1);

    auto loadingLabel = TextArea::create(Lightsync->getLoadingString(), "bigFont.fnt", 1, 300, { 1, 0 }, 25, false);
    loadingLabel->setScale(.5f);
    loadingLabel->setAnchorPoint({ 1, 0 });
    loadingLabel->setPosition({ size.width - 25, 25 });
    _this->addChild(loadingLabel, 9);

    auto logo = CCSprite::createWithSpriteFrameName("GJ_logo_001.png");
    logo->setScale(.8f);
    logo->setPosition({ size.width / 2, size.height / 2 });
    _this->addChild(logo, 99);

    auto logo2 = CCSprite::createWithSpriteFrameName("GJ_logo_02_001.png");
    logo2->setScale(.8f);
    logo2->setAnchorPoint({ .5f, 1 });
    logo2->setColor({ 175, 175, 175 });
    logo2->setPosition({ size.width / 2, size.height / 2 + logo->getScaledContentSize().height });
    _this->addChild(logo2, 99);

    auto cocos = CCSprite::createWithSpriteFrameName("cocos2DxLogo.png");
    cocos->setScale(.5f);
    cocos->setPosition({ size.width - 45, size.height - 20 });
    _this->addChild(cocos, 99);

    auto fmod = CCSprite::createWithSpriteFrameName("fmodLogo.png");
    fmod->setScale(.5f);
    fmod->setPosition({ size.width - 95, size.height - 20 });
    _this->addChild(fmod, 99);

    return true;
}