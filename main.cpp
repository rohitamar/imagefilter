#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>



int main() {
    int width, height, channels;
    unsigned char* img = stbi_load("image.png", &width, &height, &channels, 0);
    
    if (!img) {
        std::cerr << "Failed to load image\n";
        return 1;
    }

    std::cout << "Image loaded: " << width << "x" << height << ", Channels: " << channels << "\n";

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channels;
            unsigned char r = img[index];
            unsigned char g = img[index + 1];
            unsigned char b = img[index + 2];
            std::cout << "Pixel(" << x << "," << y << "): R=" << (int)r << " G=" << (int)g << " B=" << (int)b << "\n";
        }
    }

    stbi_image_free(img); // Free memory
    return 0;
}
