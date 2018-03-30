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

double Square::getSideLength() const{
   return _sideLength;
}

double Square::getBoundingBox_X(){
   return _sideLength;
}

double Square::getBoundingBox_Y(){
   return _sideLength;
}

ofstream & Square::toPostScript(ofstream & stream){
   stream << "/sideLength {" << getSideLength() << " mul} def" << endl;
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
   //drawBoundingBox(sideLength, stream);
   return stream;
}

ofstream & Square::drawBoundingBox(double sideLength, ofstream & stream){
 /*  stream << "newpath" << endl;
   stream << "/inch {72 mul} def" << endl;
   stream << "/sideLength {" << sideLength << "} def" << endl;
   stream << "4 inch 1 inch moveto" << endl;
   stream << "1 sideLength 0 sideLength rlineto" << endl;
   stream << "0 sideLength 1 sideLength rlineto" << endl;
   stream << "-1 sideLength 0 sideLength rlineto" << endl;
   stream << "closepath" << endl;
   stream << "stroke" << endl;*/
   return stream;
   
}

ofstream & Square::drawBoundingBox(double boxWidth, double boxHeight, ofstream & stream){
   return stream;
}
