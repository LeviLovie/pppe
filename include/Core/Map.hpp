#pragma once

#include "Element.hpp"

namespace pppe {
    namespace Core {
        class Map {
            public:
                Map(int width, int height);
                ~Map();
                void Debug();
                void DebugHead();
                void Fill(Element* element);
                void RandomFill(Element* element, float chance);
                void RandomSeedFill(Element* element, float chance, int seed);

            private:
                int width;
                int height;
                Element*** map;
        };
    };
}
