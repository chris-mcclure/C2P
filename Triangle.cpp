//
//  Triangle.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Triangle.h"
using std::ofstream;
using std::endl;

Triangle::Triangle(double sideLength)
:_sideLength(sideLength)
{}

double Triangle::getSideLength() const{
   return _sideLength;
}


std::ofstream & Triangle::toPostScript(ofstream & stream){
   stream << "/sideLength {" << getSideLength() << " mul} def" << endl;
   stream << "newpath" << endl;
   stream << "2 inch 2 inch moveto" << endl;
   stream << "1 sideLength 1 sideLength rlineto" << endl;
   stream << "1 sideLength -1 sideLength rlineto" << endl;
   stream << "closepath" << endl;
   stream << "gsave" << endl;
   stream << "0 0.5 1 setrgbcolor" << endl;
   stream << "fill" << endl;
   stream << "grestore" << endl;
   stream << "stroke" << endl;
   stream << endl;
   return stream;
}

ofstream & Triangle::drawBoundingBox(double sideLength, ofstream & stream){
   stream << "/sideLength {" << sideLength << "} def" << endl;
   stream << "newpath" << endl;
   stream << "sideLength sideLength moveto" << endl;
   return stream;
}

ofstream & Triangle::drawBoundingBox(double boxWidth, double boxHeight, ofstream & stream){
   return stream;
}
