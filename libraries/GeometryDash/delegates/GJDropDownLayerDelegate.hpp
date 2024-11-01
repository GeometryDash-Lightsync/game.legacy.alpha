#pragma once


#include <GDLib.h>
#include "../layers/GJDropDownLayer.hpp"

class GJDropDownLayerDelegate {
public:

    virtual void dropDownLayerWillClose(GJDropDownLayer* p0) {}
};