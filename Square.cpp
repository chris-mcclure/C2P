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
{}

double Square::getBoundingBox_X(){
    return _sideLength;
}

double Square::getBoundingBox_Y(){
    return _sideLength;
}

ofstream & Square::toPostScript(double sideLength, ofstream & stream){
    stream << "%!" << endl;
    stream << "%% Square Example" << endl;
    stream << "/inch {72 mul} def" << endl;
    stream << "/sideLength {" << sideLength << " mul} def" << endl;
    stream << "newpath" << endl;
    stream << "4 inch 1 inch moveto" << endl;
    stream << "1 sideLength 0 sideLength rlineto" << endl;
    stream << "0 sideLength 1 sideLength rlineto" << endl;
    stream << "-1 sideLength 0 sideLength rlineto" << endl;
    stream << "closepath" << endl;
    stream << "gsave" << endl;
    stream << "1 0 0.5 setrgbcolor" << endl;
    stream << "fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << endl;
    return stream;
}

ofstream & Square::toPostScript(double var1, double var2, ofstream & stream){
    return stream;
}

