//
//  Square.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Square.h"
using std::ostream;
using std::endl;
using std::ostringstream;
using std::string;

Square::Square(double width, const string & name)
:_width(width), _height(width), _name(name)
{}

double Square::getWidth(){
    return _width;
}

double Square::getHeight(){
    return _height;
}

string Square::getName(){
    return _name;
}

void Square::setWidth(double w) {
    _width = w;
}

void Square::setHeight(double h) {
    _height = h;
}

void Square::setPostScript(ostringstream & stream){
    _stream = std::move(stream);
}

ostringstream & Square::getPostScript(){
    //std::cout << _stream.str() << std::endl;
    return _stream;
}

ostringstream & Square::toPostScript(ostringstream & stream){
    stream << "%%Square" << endl;
    stream << "/square{" << endl;
    stream << "/width {" << getWidth() << " mul} def" << endl;
    stream << "/height {" << getHeight() << " mul} def" << endl;
    stream << "gsave" << endl;
    stream << "1 width 0 height rlineto" << endl;
    stream << "0 width 1 height rlineto" << endl;
    stream << "-1 width 0 height rlineto" << endl;
    stream << "closepath" << endl;
    stream << "gsave" << endl;
    stream << "1 0 0.5 setrgbcolor" << endl;
    stream << "fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    //stream << "1 width 0 height rmoveto" << endl;
    stream << "}def" << endl;
    //stream << "square" <<endl;
    stream << endl;
    return stream;
}

ostringstream & Square::drawBoundingBox(double sideLength, ostringstream & stream){
    /*  stream << "newpath" << endl;
     stream << "/inch {72 mul} def" << endl;
     stream << "/sideLength {" << sideLength << "} def" << endl;
     stream << "4 inch 1 inch moveto" << endl;
     stream << "1 sideLength 0 sideLength rlineto" << endl;
     stream << "0 sideLength 1 sideLength rlineto" << endl;
     stream << "-1 sideLength 0 sideLength rlineto" << endl;
     stream << "closepath" << endl;
     stream << "stroke" << endl;*/
    return stream;

}

ostringstream & Square::drawBoundingBox(double boxWidth, double boxHeight, ostringstream & stream){
    return stream;
}
