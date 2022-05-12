//
//  Bitmap.hpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/2/22.
//

#ifndef Bitmap_hpp
#define Bitmap_hpp

#include <string>
#include <cstdint>
using namespace std;

#include <stdio.h>

class Bitmap {
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr};
    
public:
    Bitmap(int width, int height);
    void setPixel(int xpos, int ypos, uint8_t red, uint8_t green, uint8_t blue);
    bool write(string filename);
    virtual ~Bitmap();
};

#endif /* Bitmap_hpp */
