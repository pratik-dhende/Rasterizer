#include <iostream>
#include "Renderer.h"

int main(int argc, char* argv[]) {
    constexpr int WIDTH = 426;
    constexpr int HEIGHT = 240;

    Renderer renderer(WIDTH, HEIGHT);
    renderer.draw();

    return 0;
}