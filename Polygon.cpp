//
//  Polygon.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Polygon.h"
using std::ofstream;
using std::endl;

Polygon::Polygon(double numSides, double sideLength)
    :_numSides(numSides), _sideLength(sideLength)
{}

ofstream & Polygon::toPostScript(double numSides, double sideLength, ofstream & stream){
    stream.open("polygon.ps");
    stream << "%!" << endl;
    stream << "%% Polygon Example" << endl;
    stream << "/numSides {" << numSides << "} def" << endl;
    stream << "/sideLength {" << sideLength << "} def" << endl;
    stream << "newpath" << endl;
    stream << "72 72 moveto" << endl;
    stream << "" << endl;
    return stream;
}

ofstream & Polygon::toPostScript(double var1, ofstream & stream){
    return stream;
}
