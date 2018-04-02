//
//  Polygon.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Polygon.h"
using std::ostream;
using std::endl;
using std::ostringstream;

Polygon::Polygon(double numSides, double sideLength)
:_numSides(numSides), _sideLength(sideLength)
{}


double Polygon::getWidth(){
    return _width;
}

double Polygon::getHeight(){
    return _height;
}


double Polygon::getNumSides() const{
    return _numSides;
}

double Polygon::getSideLength() const{
    return _sideLength;
}

ostringstream & Polygon::toPostScript(ostringstream & stream){
    stream << "/numSides {" << getNumSides() << "} def" << endl;
    stream << "/sideLength {" << getSideLength() << "} def" << endl;
    stream << "newpath" << endl;
    stream << "72 72 moveto" << endl;
    stream << "" << endl;
    return stream;
}

