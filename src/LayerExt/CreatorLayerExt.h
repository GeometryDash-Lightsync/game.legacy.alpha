#pragma once

#include "../lightsync.h"

class CreatorLayerExt : public CreatorLayer, LayerExtProtocol<CreatorLayer> {
public:
    BackgroundSprite* m_background;

};

