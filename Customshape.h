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
#include <string>

class Custom : public BasicShape{
public:
    Custom(double degree, const std::string & name, double width);
    std::ostringstream & toPostScript(std::ostringstream & stream);
    double getNumSides() const;
    double getSideLength() const;
    double getHeight();
    double getWidth();
    void setWidth(double w);
    void setHeight(double h);
    double getRadius();
    std::string getName();
    std::ostringstream & getPostScript();

private:
    int _numSides;
    double _width;
    double _height;
    std::string _name;
    double _radius;
    double _sideLength;
    std::ostringstream _stream;
};

#endif /*Customshape_h */
