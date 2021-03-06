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
using std::ostringstream;

Circle::Circle(double width, const string & name):_radius(width/2),
_width(width), _height(width), _name(name)
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

void Circle::setWidth(double w) {
    _width = w;
}

void Circle::setHeight(double h) {
    _height = h;
}

void Circle::setPostScript(ostringstream & stream){
    _stream = std::move(stream);
}

string Circle::getName(){
    return _name;
}

ostringstream & Circle::getPostScript(){
    return _stream;
}

ostringstream & Circle::toPostScript(ostringstream & stream){
    stream << "%%Circle" << endl;
    stream << "/circle{" << endl;
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
    //stream << "1 width 0 height rmoveto" << endl;
    stream << "}def" << endl;
    //stream << "circle" <<endl;
    stream << endl;
    // drawBoundingBox(radius, stream);
    return stream;
}
