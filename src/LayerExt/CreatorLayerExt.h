#pragma once

#include "../lightsync.hpp"

class CreatorLayerExt : public CreatorLayer, LayerExtProtocol<CreatorLayer> {
public:
    BackgroundSprite* m_background;

};

