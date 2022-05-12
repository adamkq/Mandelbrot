//
//  ZoomList.hpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/11/22.
//

#ifndef ZoomList_h
#define ZoomList_h

#include <stdio.h>
#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

class ZoomList
{
private:
    double m_xCenter{0};
    double m_yCenter{0};
    double m_scale{1.0};
    
    int m_width{0};
    int m_height{0};
    vector<Zoom> zooms;
    
public:
    ZoomList(int width, int height);
    ZoomList();
    void add(const Zoom& zoom);
    pair<double, double> doZoom(int x_pos, int y_pos);
};

#endif /* ZoomList_hpp */
