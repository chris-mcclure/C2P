//
//  Polygon.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Customshape_h
#define Customshape_h
#include "BasicShape.h"

class Custom : public BasicShape{
public:
    Custom(double degree, double sideLength);
    std::ostringstream & toPostScript(std::ostringstream & stream);
    double getNumSides() const;
    double getSideLength() const;
    double getHeight();
    double getWidth();
    void setWidth(double w);
    void setHeight(double h);

private:
    int _numSides;
    double _width;
    double _height;
    double _sideLength;
};

#endif /*Customshape_h */
