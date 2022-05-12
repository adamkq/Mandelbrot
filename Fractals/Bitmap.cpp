//
//  Bitmap.cpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/2/22.
//

#include <cstdint>
#include <fstream>

#include "Bitmap.hpp"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;

Bitmap::Bitmap(int width, int height): m_width(width),  m_height(height), m_pPixels(new uint8_t[width*height*3]{})
{
    //TODO
}

bool Bitmap::write(string filename)
{
    BitmapFileHeader bmpFileHeader;
    BitmapInfoHeader bmpInfoHeader;
    
    bmpFileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3; // in bytes
    
    bmpFileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    
    bmpInfoHeader.width = m_width;
    bmpInfoHeader.height = m_height;
    
    ofstream file;
    
    file.open(filename, ios::out|ios::binary);
    
    if (!file)
    {
        return false;
    }
    
    file.write((char *)&bmpFileHeader, sizeof(bmpFileHeader));
    file.write((char *)&bmpInfoHeader, sizeof(bmpInfoHeader));
    file.write((char *)m_pPixels.get(), m_width*m_height*3);
    
    file.close();
    
    if (!file)
    {
        return false;
    }
    
    return true;
}

void Bitmap::setPixel(int xpos, int ypos, uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t *pPixel = m_pPixels.get();
    
    pPixel += (ypos * 3) * m_width + (xpos * 3); // shifts the address to write to over by this number of bytes
    
    // little endian
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

Bitmap::~Bitmap()
{
    
}
