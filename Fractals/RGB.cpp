//
//  RGB.cpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/12/22.
//

#include "RGB.h"


RGB::RGB(double r, double g, double b):
    r(r),
    g(g),
    b(b)
{
    
}

RGB::~RGB() {
}

RGB operator-(const RGB& first, const RGB& second)
{
    return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
}
