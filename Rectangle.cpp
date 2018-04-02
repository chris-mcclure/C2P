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

Rectangle::Rectangle(double width, double height)
:_width(width), _height(height)
{}

double Rectangle::getWidth(){
    return _width;
}

double Rectangle::getHeight(){
    return _height;
}


ostringstream & Rectangle::toPostScript(ostringstream & stream){
    stream << "%%Rectangle" << endl;
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
    stream << "1 width 0 height rmoveto" << endl;
    stream << endl;
    return stream;
}

ostringstream & Rectangle::drawBoundingBox(double radius, ostringstream & stream){
    return stream;
}

ostringstream & Rectangle::drawBoundingBox(double boxWidth, double boxHeight, ostringstream & stream){
    return stream;
}
