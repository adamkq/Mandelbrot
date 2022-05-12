//
//  Zoom.hpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/11/22.
//

#ifndef Zoom_hpp
#define Zoom_hpp

#include <stdio.h>

struct Zoom
{
    int x_pos{0};
    int y_pos{0};
    double scale{0.0};
    
    Zoom(int x_pos, int y_pos, double scale) : x_pos(x_pos), y_pos(y_pos), scale(scale) {};
};
#endif /* Zoom_hpp */
