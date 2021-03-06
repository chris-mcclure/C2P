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
using std::ostringstream;
using std::string;

Triangle::Triangle(double width, const string & name)
:_width(width), _height(width), _name(name)
{}

double Triangle::getWidth(){
    return _width;
}

double Triangle::getHeight(){
    return _height;
}

string Triangle::getName(){
    return _name;
}

void Triangle::setWidth(double w) {
    _width = w;
}

void Triangle::setHeight(double h) {
    _height = h;
}

void Triangle::setPostScript(ostringstream & stream){
    _stream = std::move(stream);
}

ostringstream & Triangle::getPostScript(){
    std::cout << _stream.str() << std::endl;
    return _stream;
}

ostringstream & Triangle::toPostScript(ostringstream & stream){
    stream << "%%Triangle" << endl;
    stream << "/triangle{" << endl;
    stream << "/width {" << getWidth() << " mul} def" << endl;
    stream << "/height {" << getHeight() << " mul} def" << endl;
    stream << "gsave" << endl;
    stream << "1 width 2 div 1 height rlineto" << endl;
    stream << "1 width 2 div -1 height rlineto" << endl;
    stream << "closepath" << endl;
    stream << "gsave" << endl;
    stream << "0 0.5 1 setrgbcolor" << endl;
    stream << "fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
   // stream << "1 width 0 height rmoveto" << endl;
    stream << "}def" << endl;
    //stream << "triangle" <<endl;
    stream << endl;
    return stream;
}

ostringstream & Triangle::drawBoundingBox(double sideLength, ostringstream & stream){
    stream << "/sideLength {" << sideLength << "} def" << endl;
    stream << "newpath" << endl;
    stream << "sideLength sideLength moveto" << endl;
    return stream;
}

ostringstream & Triangle::drawBoundingBox(double boxWidth, double boxHeight, ostringstream & stream){
    return stream;
}
