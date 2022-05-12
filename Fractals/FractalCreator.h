//
//  FractalCreator.hpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/12/22.
//

#ifndef FractalCreator_h
#define FractalCreator_h

#include <stdio.h>
#include <string>
#include <cstdint>
#include <math.h>
#include <memory>
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"
#include "Zoom.h"
#include "ZoomList.h"

using namespace std;

class FractalCreator
{
private:
    int m_width;
    int m_height;
    int m_total;
    
    Bitmap m_bmp;
    ZoomList m_zoomList;
    
    unique_ptr<int[]> histogram;
    unique_ptr<int[]> frac;
public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    
    void calculateIteration();
    void draw();
    void addZoom(const Zoom& zoom);
    void writeBitmap(string name);
};

#endif /* FractalCreator_hpp */
