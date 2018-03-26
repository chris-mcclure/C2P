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
{
    toPostScript(_width, _height);
}

void Rectangle::toPostScript(double width, double height){
    ofstream post_stream;
    post_stream.open("rectangle.ps");
    post_stream << "%!" << endl;
    post_stream << "%% Rectangle example" << endl;
    post_stream << "/width {" << width << " mul} def" << endl;
    post_stream << "/height {" << height << " mul} def" << endl;
    post_stream << "newpath" << endl;
    post_stream << "72 72 moveto" << endl;
    post_stream << "1 width 0 height rlineto" << endl;
    post_stream << "0 width 1 height rlineto" << endl;
    post_stream << "-1 width 0 height rlineto" << endl;
    post_stream << "closepath" << endl;
    post_stream << "stroke" << endl;
    post_stream << "showpage" << endl;
}

void Rectangle::toPostScript(double var1){}
