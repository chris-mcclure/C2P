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

Rectangle::Rectangle(double width, double height){
    _width = width;
    _height = height;
    toPostScript(width, height);
}

void Rectangle::toPostScript(double width, double height){
    ofstream post_stream;
    post_stream.open("rectangle.ps");
    post_stream << "%!" << endl;
    post_stream << "%% Rectangle Example" << endl;
    post_stream << "/inch {72 mul} def" << endl;
    post_stream << "/buffer {72 add} def" << endl;
    post_stream << "newpath" << endl;
    post_stream << "1 inch 1 inch moveto" << endl;
    post_stream << "1 inch " << height << " buffer lineto" << endl;
    post_stream << width << " buffer " << height << " buffer lineto" << endl;
    post_stream << width << " buffer 1 inch lineto" << endl;
    post_stream << "closepath" << endl;
    post_stream << "0 0.5 1 setrgbcolor fill" << endl;
    post_stream << "stroke" << endl;
    post_stream << "showpage" << endl;
    post_stream.close();
}

















