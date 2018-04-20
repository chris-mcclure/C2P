//
//  Rectangle.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Rectangle.h"
using std::ostream;
using std::endl;
using std::ostringstream;
using std::string;

Rectangle::Rectangle(double width, double height, const string & name)
:_width(width), _height(height), _name(name)
{}

double Rectangle::getWidth(){
    return _width;
}

double Rectangle::getHeight(){
    return _height;
}

void Rectangle::setWidth(double w) {
    _width = w;
}

void Rectangle::setHeight(double h) {
    _height = h;
}

void Rectangle::setPostScript(ostringstream & stream){
    _stream = std::move(stream);
}

string Rectangle::getName(){
    return _name;
}

ostringstream & Rectangle::getPostScript(){
    std::cout << _stream.str() << std::endl;
    return _stream;
}

ostringstream & Rectangle::toPostScript(ostringstream & stream){
    stream << "%%Rectangle" << endl;
    stream << "/rectangle{" << endl;
    stream << "/width {" << getWidth() << " mul} def" << endl;
    stream << "/height {" << getHeight() << " mul} def" << endl;
    stream << "gsave" << endl;
    stream << "1 width 0 height rlineto" << endl;
    stream << "0 width 1 height rlineto" << endl;
    stream << "-1 width 0 height rlineto" << endl;
    stream << "closepath" << endl;
    stream << "gsave" << endl;
    stream << "0.9 0.1 0.9 setrgbcolor" << endl;
    stream << "fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
   // stream << "1 width 0 height rmoveto" << endl;
    stream << "}def" << endl;
   // stream << "rectangle" <<endl;
    stream << endl;
    return stream;
}

ostringstream & Rectangle::drawBoundingBox(double radius, ostringstream & stream){
    return stream;
}

ostringstream & Rectangle::drawBoundingBox(double boxWidth, double boxHeight, ostringstream & stream){
    return stream;
}
