#pragma once

#include <iostream>
#include <string>
#include <cstdint>

namespace pppe {
    namespace Core {
        class Element {
            public:
                uint32_t color;
                std::string name;

                Element(uint32_t color, std::string name);
        };
    }
}