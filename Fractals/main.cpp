//
//  main.cpp
//  Fractals
//
//  Created by Adam Kilbourne on 4/18/22.
//

#include <iostream>
#include "FractalCreator.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int const WIDTH = 1440;
    int const HEIGHT = 900;
    
    FractalCreator fc(WIDTH, HEIGHT);
    
    fc.addZoom(Zoom(WIDTH/2 - 0.00001, HEIGHT/2, 4.0/WIDTH));
    fc.addZoom(Zoom(1000, HEIGHT-202, 0.1));// zoom to area between main cardioid and top lobe
    
    fc.calculateIteration();
    fc.draw();
    fc.writeBitmap("mandelbrot.bmp");
    
    std::cout << "Finished "<< endl;
    return 0;
}
