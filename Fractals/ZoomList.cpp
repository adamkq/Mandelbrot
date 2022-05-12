//
//  ZoomList.cpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/11/22.
//

#include "ZoomList.h"

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height)
{
    
}

ZoomList::ZoomList()
{
    
}

void ZoomList::add(const Zoom& zoom)
{
    zooms.push_back(zoom);
    
    // dist from selected coord to center of bmp
    m_xCenter += (zoom.x_pos - m_width/2)*m_scale;
    m_yCenter += (zoom.y_pos - m_height/2)*m_scale;
    
    m_scale *= zoom.scale;
}

pair<double, double> ZoomList::doZoom(int x_pos, int y_pos)
{
    double xFrac = (x_pos - m_width/2)*m_scale + m_xCenter;
    double yFrac = (y_pos - m_height/2)*m_scale + m_yCenter;
    return pair<double, double>(xFrac, yFrac);
}
