//
//  Mandelbrot.cpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/8/22.
//

#include <complex>
#include "Mandelbrot.hpp"

using namespace std;

Mandelbrot::Mandelbrot()
{

}

Mandelbrot::~Mandelbrot()
{

}

int Mandelbrot::GetIterations(double x, double y) {
    
    complex<double> z = 0;
    complex<double> c(x, y);
    
    int iterations = 0;
    
    for (iterations = 0; iterations < MAX_ITER; iterations++)
    {
        z = z*z + c;
        
        if (abs(z) > 2)
        {
            break;
        }
    }
    return iterations;
}

