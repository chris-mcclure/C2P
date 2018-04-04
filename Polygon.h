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
    Polygon(int numSides, double sideLength, const string & name);
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
    std::ostringstream _stream;
    std::string _name;
};

#endif /* Polygon_h */
