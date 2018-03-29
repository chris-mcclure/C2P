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

Triangle::Triangle(double sideLength, ofstream & stream)
:_sideLength(sideLength)
{
   toPostScript(_sideLength, stream);
}

double Triangle::getBoundingBox_X(){
   return _sideLength;
}

double Triangle::getBoundingBox_Y(){
   return _sideLength;
}

std::ofstream & Triangle::toPostScript(double sideLength, ofstream & stream){
   stream << "%!" << endl;
   stream << "%% Triangle Example" << endl;
   stream << "/sideLength {" << sideLength << " mul} def" << endl;
   stream << "newpath" << endl;
   stream << "1 sideLength 1 sideLength moveto" << endl;
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

ofstream & Triangle::toPostScript(double var1, double var2, ofstream & stream){
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
