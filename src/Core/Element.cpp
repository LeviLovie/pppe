#include "../../include/Core/Element.hpp"

#include <iostream>
#include <string>
#include <cstdint>

namespace pppe {
    namespace Core {
        Element::Element(uint32_t color, std::string name) {
            this->color = color;
            this->name = name;
        }
    }
}