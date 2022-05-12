//
//  BitmapInfoHeader.h
//  Fractals
//
//  Created by Adam Kilbourne on 4/30/22.
//

#ifndef BitmapInfoHeader_h
#define BitmapInfoHeader_h

#include <cstdint>

using namespace std;

#pragma pack(2)

// based off of the bmp file structure
struct BitmapInfoHeader {
    int32_t headerSize{40};
    int32_t width;
    int32_t height;
    int16_t planes{1};
    int16_t bitsPerPixel{24}; // one byte for each color RGB
    int32_t compression{0}; // no compression
    int32_t dataSize{0};
    int32_t horizontalResolution{2400};
    int32_t verticalResolution{2400};
    int32_t colors{0};
    int32_t importantColors{0};
};

#endif /* BitmapInfoHeader_h */
