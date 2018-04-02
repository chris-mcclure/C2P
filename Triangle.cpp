//
//  Triangle.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Triangle.h"
using std::ostream;
using std::endl;

Triangle::Triangle(double width)
:_width(width), _height(width)
{}

double Triangle::getWidth(){
    return _width;
}

double Triangle::getHeight(){
    return _height;
}


std::ostream & Triangle::toPostScript(ostream & stream){
    stream << "/sideLength {" << getWidth() << " mul} def" << endl;
    stream << "newpath" << endl;
    stream << "2 inch 2 inch moveto" << endl;
    stream << "1 sideLength 1 sideLength rlineto" << endl;
    stream << "1 sideLength -1 sideLength rlineto" << endl;
    stream << "closepath" << endl;
    stream << "gsave" << endl;
    stream << "0 0.5 1 setrgbcolor" << endl;
    stream << "fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << endl;
    return stream;
}

ostream & Triangle::drawBoundingBox(double sideLength, ostream & stream){
    stream << "/sideLength {" << sideLength << "} def" << endl;
    stream << "newpath" << endl;
    stream << "sideLength sideLength moveto" << endl;
    return stream;
}

ostream & Triangle::drawBoundingBox(double boxWidth, double boxHeight, ostream & stream){
    return stream;
}
