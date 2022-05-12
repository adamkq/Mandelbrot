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
#include <vector>
#include <math.h>
#include <memory>

#include "Bitmap.hpp"
#include "Mandelbrot.hpp"
#include "Zoom.h"
#include "ZoomList.h"
#include "RGB.h"

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
    
    vector<int> m_ranges; // number of iterations
    vector<int> m_rangeTotals;
    vector<RGB> m_colors;
    
public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    
    void calculateIterations();
    void reportStats();
    void draw();
    void addRange(double rangeEnd, const RGB& rgb);
    void addZoom(const Zoom& zoom);
    void writeBitmap(string name);
    int getRange(int iterations) const;
};

#endif /* FractalCreator_hpp */
