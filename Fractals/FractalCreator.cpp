//
//  FractalCreator.cpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/12/22.
//

#include <iostream>
#include "FractalCreator.h"

using namespace std;

FractalCreator::FractalCreator(int width, int height):
    m_width(width),
    m_height(height),
    m_bmp(m_width, m_height),
    m_zoomList(m_width, m_height),
    histogram(new int[Mandelbrot::MAX_ITER]{0}),
    frac(new int[m_width*m_height]{0})
{
    m_total = 0;
}

FractalCreator::~FractalCreator()
{
    
}

void FractalCreator::calculateIterations()
{
    for(int yy = 0; yy < m_height; yy++)
    {
        for(int xx = 0; xx < m_width; xx++)
        {
            pair<double, double> coords = m_zoomList.doZoom(xx, yy);
            
            int iterations = Mandelbrot::GetIterations(coords.first, coords.second);
            
            frac[yy*m_width + xx] = iterations;
            
            if (iterations < Mandelbrot::MAX_ITER)
            {
                histogram[iterations]++;
            }
        }
    }
    
    // Totals
    for(int i = 0; i < Mandelbrot::MAX_ITER; i++)
    {
        m_total += histogram[i];
    }
    
    int rangeIndex = 0;
    for(int i=0; i < Mandelbrot::MAX_ITER; i++)
    {
        int pixels = histogram[i];
        
        if (i >= m_ranges[rangeIndex + 1])
        {
            rangeIndex++;
        }
        m_rangeTotals[rangeIndex] += pixels;
    }
}

void FractalCreator::reportStats()
{
    cout<<"Total Pixels: "<<m_total<<endl;
    cout<<"Pixels for each range:"<<endl;
    for(int value: m_rangeTotals)
    {
        cout<<value<<endl;
    }
}

void FractalCreator::draw() {
    for(int yy = 0; yy < m_height; yy++)
    {
        for(int xx = 0; xx < m_width; xx++)
        {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;
            
            int iterations = frac[yy*m_width + xx];
            
            int range = getRange(iterations);
            int rangeTotal = m_rangeTotals[range];
            int rangeStart = m_ranges[range];
            
            RGB& startColor = m_colors[range];
            RGB& endColor = m_colors[range + 1];
            RGB dColor = endColor - startColor;
            
            if (iterations != Mandelbrot::MAX_ITER)
            {
                int totalPixels = 0;
                
                for(int i = rangeStart; i <= iterations; i++)
                {
                    totalPixels += histogram[i];
                }
                
                red = startColor.r + dColor.r*(double)totalPixels/rangeTotal;
                green = startColor.g + dColor.g*(double)totalPixels/rangeTotal;
                blue = startColor.b + dColor.b*(double)totalPixels/rangeTotal;
            }
            
            m_bmp.setPixel(xx, yy, red, green, blue);
        }
    }
}

void FractalCreator::addZoom(const Zoom &zoom) { 
    m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(std::string name) { 
    m_bmp.write(name);
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) { 
    m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITER);
    m_colors.push_back(rgb);
    
    if (m_ranges.size() > 1)
    {
        m_rangeTotals.push_back(0);
    }
}

int FractalCreator::getRange(int iterations) const {
    int range = 0;

    for(int i=1; i < m_ranges.size(); i++) {

        range = i;

        if(m_ranges[i] > iterations) {
            break;
        }

    }

    range--;

    assert(range > -1);
    assert(range < m_ranges.size());

    return range;
}



