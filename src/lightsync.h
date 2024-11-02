#pragma once
#include "includes.h"

#include <iomanip>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <fmt/core.h>
#include <openssl/sha.h>
#include <ctime>
#include <wininet.h>
#include <filesystem>

#pragma comment(lib, "wininet.lib")

using namespace cocos2d;

#include "Miscellaneous/Utils.h"
#include "Miscellaneous/LayerExtProtocol.h"

#include "Managers/LightsyncManager.hpp"
#include "Managers/LSIconDataManager.h"

#include "Miscellaneous/BackgroundSprite.h"
#include "Miscellaneous/CrashLog.h"
#include "Miscellaneous/LSButtonSprite.h"
#include "Miscellaneous/LSLevelTools.h"
#include "Miscellaneous/LSItemIcon.h"

#include "LayerExt/CreatorLayerExt.h"
#include "LayerExt/MenuLayerExt.h"

#include "Menus/HomePage.h"
#include "Menus/MainMenuLayer.h"

#include "Hooks/HookedCreatorLayer.h"
#include "Hooks/HookedGameManager.h"
#include "Hooks/HookedGJGarageLayer.h"
#include "Hooks/HookedItemInfoPopup.h"
#include "Hooks/HookedLoadingLayer.h"
#include "Hooks/HookedMenuGameLayer.h"
#include "Hooks/HookedMenulayer.h"