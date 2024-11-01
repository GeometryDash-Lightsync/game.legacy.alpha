#pragma once 

#include <GDLib.h>
class FLAlertLayer;

class FLAlertLayerProtocol {
public:
	virtual void FLAlert_Clicked(FLAlertLayer*, bool btn2) {};
};