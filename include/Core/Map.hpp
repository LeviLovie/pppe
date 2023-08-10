#pragma once

namespace pppe {
    class Map {
        public:
            Map(int width, int height);
            ~Map();
            void Debug();

        private:
            int width;
            int height;
            int** map;
    };
}
