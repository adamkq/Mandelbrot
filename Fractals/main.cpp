//
//  main.cpp
//  Fractals
//
//  Created by Adam Kilbourne on 4/18/22.
//

#include <iostream>
#include <chrono>
#include "FractalCreator.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int const WIDTH = 1440;
    int const HEIGHT = 900;
    
    cout<<"Generating Fractal with dimensions: "<<WIDTH<<", "<<HEIGHT<<endl;
    FractalCreator fc(WIDTH, HEIGHT);
    
    fc.addRange(0.0, RGB(0, 0, 0));
    fc.addRange(0.015, RGB(255, 64, 0));
    fc.addRange(0.02, RGB(255, 255, 255));
    fc.addRange(0.03, RGB(0, 255, 0));
    fc.addRange(1.0, RGB(0, 0, 255));
    
    fc.addZoom(Zoom(WIDTH/2 - 0.00001, HEIGHT/2, 4.0/WIDTH)); // full view
    fc.addZoom(Zoom(1000, HEIGHT-202, 0.2));// zoom to area between main cardioid and top lobe
    
    auto start = chrono::high_resolution_clock::now();
    
    fc.calculateIterations();
    fc.reportStats();
    fc.draw();
    
    auto stop = chrono::high_resolution_clock::now();
    double duration_ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
    double duration_s = duration_ms / 1000.0;
    cout<<"Duration (s): "<<duration_s<<endl;
    
    fc.writeBitmap("mandelbrot.bmp");
    
    return 0;
}
