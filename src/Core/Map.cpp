#include "../../include/Core/Map.hpp"

#include <iostream>

namespace pppe {
    Map::Map(int width, int height) {
        this->width = width;
        this->height = height;
        this->map = new int*[width];
        for (int i = 0; i < width; i++) {
            this->map[i] = new int[height];
        }
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
                std::cout << this->map[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}
