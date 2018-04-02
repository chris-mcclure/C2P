//
//  Square.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Square.h"
using std::ostream;
using std::endl;

Square::Square(double width):_width(width), _height(width)
{}

double Square::getWidth(){
    return _width;
}

double Square::getHeight(){
    return _height;
}


ostream & Square::toPostScript(ostream & stream){
    stream << "/sideLength {" << getWidth() << " mul} def" << endl;
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

ostream & Square::drawBoundingBox(double sideLength, ostream & stream){
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

ostream & Square::drawBoundingBox(double boxWidth, double boxHeight, ostream & stream){
    return stream;
}
