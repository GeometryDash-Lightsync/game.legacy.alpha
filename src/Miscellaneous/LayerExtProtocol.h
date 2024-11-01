#pragma once
#include "../lightsync.hpp"

#include <type_traits>

template <typename T>

class LayerExtProtocol {
public:

    static constexpr std::size_t padding_size = sizeof(T) + 16;
    alignas(T) char padding[padding_size];
};