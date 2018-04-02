//
//  Circle.cpp
//  C2P
//
//  Created by Chris McClure on 3/21/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Circle.h"
using std::ostream;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;

Circle::Circle(double radius):_radius(radius),
_width(radius*2), _height(radius*2)
{}

double Circle::getWidth(){
    return _width;
}

double Circle::getHeight(){
    return _height;
}

double Circle::getRadius(){
    return _radius;
}


ostream & Circle::toPostScript(ostream & stream){
    stream << "%%Circle" << endl;
    stream << "/radius {" << getRadius() << " mul} def" << endl;
    stream << "/width {" << getWidth() << " mul} def" << endl;
    stream << "/height {" << getHeight() << " mul} def" << endl;
    stream << "gsave" << endl;
    stream << "1 radius 1 inch 1 radius add 1 radius 0 360 arc" << endl;
    stream << "gsave" << endl;
    stream << "0 1 0.5 setrgbcolor fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    stream << "1 width 0 height rmoveto" << endl;
    stream << endl;
    // drawBoundingBox(radius, stream);
    return stream;
}

