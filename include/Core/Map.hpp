#pragma once

#include <functional>
#include "Element.hpp"

namespace pppe {
    namespace Core {
        class Map {
            public:
                Element*** RawMap;

                Map(int width, int height);
                ~Map();
                void Debug();
                void DebugHead();
                void Fill(Element* element);
                void RandomFill(Element* element, float chance);
                void RandomSeedFill(Element* element, float chance, int seed);
                void Update();
                int GetWidth();
                int GetHeight();
                Element* GetElement(int x, int y);
                Element*** GetMap();

            private:
                int width;
                int height;
                Element*** map;
        };
    };
}
