//
//  FractalCreator.cpp
//  Fractals
//
//  Created by Adam Kilbourne on 5/12/22.
//

#include "FractalCreator.h"

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

void FractalCreator::calculateIteration()
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
    
    for(int i = 0; i < Mandelbrot::MAX_ITER; i++)
    {
        m_total += histogram[i];
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
            
            double hue = 0.0;
            
            for(int i = 0; i <= iterations; i++)
            {
                hue += ((double)histogram[i]/m_total);
            }
            
            green = iterations == Mandelbrot::MAX_ITER ? 0 : pow(255, hue);
            
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
