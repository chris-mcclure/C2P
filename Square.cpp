//
//  Square.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Square.h"
using std::ofstream;
using std::endl;

Square::Square(double sideLength):
    _sideLength(sideLength)
{
    toPostScript(_sideLength);
}

void Square::toPostScript(double sideLength){
    ofstream post_stream;
    post_stream.open("square.ps");
    post_stream << "%!" << endl;
    post_stream << "%% Square Example" << endl;
    post_stream << "/inch {72 mul} def" << endl;
    post_stream << "newpath" << endl;
    post_stream << "1 inch 1 inch moveto" << endl;
    post_stream << 2*sideLength << " " << sideLength << " lineto" << endl;
    post_stream << 2*sideLength << " " << 2*sideLength << " lineto" << endl;
    post_stream << sideLength << " " << 2*sideLength << " lineto" << endl;
    post_stream << "closepath" << endl;
    post_stream << "fill" << endl;
    post_stream << "stroke" << endl;
    post_stream << "showpage" << endl;
    post_stream.close();
}

void Square::toPostScript(double var1, double var2){}
