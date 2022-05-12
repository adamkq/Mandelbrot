//
//  Mandelbrot.hpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/8/22.
//

#ifndef Mandelbrot_hpp
#define Mandelbrot_hpp

#include <stdio.h>

class Mandelbrot
{
public:
    Mandelbrot();
    virtual ~Mandelbrot();
    
    static int GetIterations(double x, double y);
    
    static const int MAX_ITER = 2000;
    
};
#endif /* Mandelbrot_hpp */
