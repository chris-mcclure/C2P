//
//  Rectangle.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Rectangle.h"
using std::ofstream;
using std::endl;

Rectangle::Rectangle(double width, double height):
    _width(width), _height(height)
{}

double Rectangle::getBoundingBox_X(){
    return _width;
}

double Rectangle::getBoundingBox_Y(){
    return _height;
}

ofstream & Rectangle::toPostScript(double width, double height, ofstream & stream){
    stream << "%!" << endl;
    stream << "%% Rectangle example" << endl;
    stream << "/width {" << width << " mul} def" << endl;
    stream << "/height {" << height << " mul} def" << endl;
    stream << "newpath" << endl;
    stream << "216 216 moveto" << endl;
    stream << "1 width 0 height rlineto" << endl;
    stream << "0 width 1 height rlineto" << endl;
    stream << "-1 width 0 height rlineto" << endl;
    stream << "closepath" << endl;
    stream << "gsave" << endl;
    stream << "0.9 0.1 0.9 setrgbcolor" << endl;
    stream << "fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "showpage" << endl;
    stream << endl;
    return stream;
}

ofstream & Rectangle::toPostScript(double var1, ofstream & stream){
    return stream;
}


