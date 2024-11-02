#pragma once
#include "../lightsync.h"

#include <type_traits>
#include <memory>

template <typename Parent>

class LayerExtProtocol {

  std::aligned_storage_t<sizeof(Parent), alignof(Parent)> m_padding;

    std::vector<void*> m_containedFields;
    std::vector<void(*)(void*)> m_destructorFunctions;

public:

static void fieldConstructor(void* offsetField) {
        (void) new (offsetField) typename Parent::Fields();
    }

    static void fieldDestructor(void* offsetField) {
        static_cast<typename Parent::Fields*>(offsetField)->~Fields();
    }

    // Obtener el campo extendido en el índice dado
    void* getField(size_t index) {
        while (m_containedFields.size() <= index) {
            m_containedFields.push_back(nullptr);
            m_destructorFunctions.push_back(nullptr);
        }
        return m_containedFields.at(index);
    }

    // Método para gestionar la creación de campos extendidos si no existen
    auto self(size_t index) {
        void* offsetField = getField(index);
        if (!offsetField) {
            offsetField = allocateField(index);
        }
        return reinterpret_cast<typename Parent::Fields*>(offsetField);
    }

    auto operator->() {
        return this->self(0);  // Ajusta `index` si necesitas varios campos extendidos
    }

private:
    // Crear y asignar un nuevo campo extendido
    void* allocateField(size_t index) {
        void* offsetField = std::malloc(sizeof(typename Parent::Fields));
        if (offsetField) {
            m_containedFields[index] = offsetField;
            fieldConstructor(offsetField);
            m_destructorFunctions[index] = &fieldDestructor;
        }
        return offsetField;
    }
};