#pragma once

#include <cstdint>
#include <vector>

struct Pixel {
    uint8_t r, g, b;

    Pixel() : r(0), g(0), b(0) {}
    Pixel(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
};

class Renderer {
private:
    int m_width;
    int m_height;

    std::vector<Pixel> m_framebuffer;

public:
    Renderer(const int width, const int height) : m_width(width), m_height(height) {
        m_framebuffer.resize(width * height);
    }

    int getWidth() const noexcept{
        return m_width;
    }

    int getHeight() const noexcept {
        return m_height;
    }

    const std::vector<Pixel>& getFramebuffer() const {
        return m_framebuffer;
    }

    void draw() {
        std::cout << "P3\n";
        std::cout << m_width << " " << m_height << "\n";
        std::cout << 255 << "\n";

        for(int i = 0; i < m_height; ++i) {
            for(int j = 0; j < m_width; ++j) {
                int pixelIndex = i * m_width + j;
                std::cout << static_cast<int>(m_framebuffer[pixelIndex].r)  << " " << static_cast<int>(m_framebuffer[pixelIndex].g) << " " << static_cast<int>(m_framebuffer[pixelIndex].b) << "\n";
            }
        }
    }
};