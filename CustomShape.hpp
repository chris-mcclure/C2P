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
    Custom(double xpos, double ypos, double radius, std::string name);
    std::ostringstream & toPostScript(std::ostringstream & stream);
    double getHeight();
    double getWidth();
    double getX() const;
    double getY() const;
    double getRadius();
    std::string getName();
    std::ostringstream & getPostScript();
    std::ostringstream & rotate(int degree, std::ostringstream & stream, std::string name);
    
private:
    double _width;
    double _height;
    std::string _name;
    double _radius;
    std::ostringstream _stream;
    double _xpos;
    double _ypos;
};

#endif /*Customshape_h */

