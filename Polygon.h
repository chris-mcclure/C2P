//  Polygon.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//
#ifndef Polygon_h
#define Polygon_h
#include <cmath>
#include <math.h>
#include "Shape.h"
using std::ostringstream;


class Polygon : public Shape{
public:
    Polygon(int numSides, double sideLength, const std::string & name);
    std::ostringstream & toPostScript(std::ostringstream & stream)override;
    double getNumSides() const;
    double getSideLength() const;
    double getHeight()override;
    double getWidth()override;
    void setWidth(double w)override;
    void setHeight(double h)override;
    void setPostScript(std::ostringstream & stream);
    std::string getName()override;
    std::ostringstream & getPostScript()override;
    
    

private:
    int _numSides;
    double _width;
    double _height;
    double _sideLength;
    std::ostringstream _stream;
    std::string _name;
};

#endif /* Polygon_h */
