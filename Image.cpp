#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <memory>
#include <string> 

class Image {
    private:
    std::unique_ptr<unsigned char[]> img;

    public:
    Image() = delete; 
    
    Image(std::string path) {
        
    }
};