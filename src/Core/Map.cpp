#include "../../include/Core/Map.hpp"

#include <iostream>
#include <random>
#include "../../include/Core/Element.hpp"

namespace pppe {
    namespace Core {
        Map::Map(int width, int height) {
            Element* voidElement = new Element(0x00000000, "void");
            this->width = width;
            this->height = height;
            
            Element*** elementArray2D = new Element**[height];
            for (int i = 0; i < height; ++i) {
                elementArray2D[i] = new Element*[width];
            }

            this->map = elementArray2D;
        }
        Map::~Map() {
            for (int i = 0; i < width; i++) {
                delete[] this->map[i];
            }
            delete[] this->map;
        }
        void Map::Debug() {
            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < this->height; j++) {
                    std::cout << "\"" << this->map[i][j]->name << "\" ";
                }
                std::cout << std::endl;
            }
        }
        void Map::DebugHead() {
            int width = 5;
            int height = 10;
            if (this->width < width) {
                width = this->width;
            }
            if (this->height < height) {
                height = this->height;
            }

            for (int i = 0; i < width; i++) {
                for (int j = 0; j < height; j++) {
                    std::cout << "\"" << this->map[i][j]->name << "\" ";
                }
                std::cout << std::endl;
            }
        }
        void Map::Fill(Element* element) {
            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < this->height; j++) {
                    this->map[i][j] = element;
                }
            }
        }
        void Map::RandomFill(Element* element, float chance) {
            unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::mt19937 generator(seed);
            std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < this->height; j++) {
                    if (distribution(generator) <= chance) {
                        this->map[i][j] = element;
                    }
                }
            }
        }
        void Map::RandomSeedFill(Element* element, float chance, int seed) {
            std::mt19937 generator(seed);
            std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < this->height; j++) {
                    if (distribution(generator) <= chance) {
                        this->map[i][j] = element;
                    }
                }
            }
        }
    }
}
