//
//  RGB.hpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/12/22.
//

#ifndef RGB_h
#define RGB_h

#include <stdio.h>

struct RGB
{
    double r;
    double g;
    double b;
    RGB(double r, double g, double b);
    virtual ~RGB();
};

RGB operator-(const RGB& first, const RGB& second);

#endif /* RGB_hpp */
