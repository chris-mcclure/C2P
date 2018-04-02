//
//  Polygon.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Polygon_h
#define Polygon_h
#include "BasicShape.h"

class Polygon : public BasicShape{
public:
    Polygon(double numSides, double sideLength);
    std::ostream & toPostScript(std::ostream & stream);
    double getNumSides() const;
    double getSideLength() const;
    double getHeight();
    double getWidth();
private:
    double _numSides;
    double _width;
    double _height;
    double _sideLength;
};

#endif /* Polygon_h */
