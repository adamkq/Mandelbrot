//
//  BitmapFileHeader.h
//  Fractals
//
//  Created by Adam Kilbourne on 4/30/22.
//

#ifndef BitmapFileHeader_h
#define BitmapFileHeader_h

#include <cstdint>

using namespace std;

#pragma pack(2)

struct BitmapFileHeader {
    char header[2]{'B','M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};

#endif /* BitmapFileHeader_h */
