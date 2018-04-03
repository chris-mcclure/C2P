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
using std::string;

Polygon::Polygon(double numSides, double sideLength, const string & name)
:_numSides(numSides), _sideLength(sideLength), _name(name)
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

string Polygon::getName(){
    return _name;
}

void Polygon::setPostScript(ostringstream & stream){
    _stream = std::move(stream);
}

ostringstream & Polygon::getPostScript(){
    std::cout << _stream.str() << std::endl;
    return _stream;
}

ostringstream & Polygon::toPostScript(ostringstream & stream){
    stream << "%%Polygon" << endl;
    stream << "/numSides {" << getNumSides() << "} def" << endl;
    stream << "/sideLength {" << getSideLength() << " mul} def" << endl;
    stream << "/defpoly {" << endl;
    stream << "4 dict begin /p exch def /n exch def" << endl;
    stream << "/m matrix currentmatrix def" << endl;
    stream << " dup scale" << endl;
    stream << "/s matrix currentmatrix def" << endl;
    stream << "0 360 n div 359.9" << endl;
    stream << "({" << endl;
    stream << "{" << endl;
    stream << "//s setmatrix" << endl;
    stream << "rotate" << endl;
    stream << "//p exec" << endl;
    stream << "} for" << endl;
    stream << "//m setmatrix" << endl;
    stream << "}) token pop exch pop" << endl;
    stream << "bind" << endl;
    stream << "end exec" << endl;
    stream << "} bind def" << endl;
    stream << endl;
    stream << "/polygon {" << endl;
    stream << "gsave" << endl;
    stream << "translate" << endl;
    stream << "1 index 0 moveto" << endl;
    stream << "{" << endl;
    stream << "1 0 lineto" << endl;
    stream << "} defpoly" << endl;
    stream << "closepath" << endl;
    stream << "gsave" << endl;
    stream << "0.4 0.3 0.8 setrgbcolor" << endl;
    stream << "fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    stream << "} def" << endl;
    stream << "72 numSides 144 72 drawpoly" << endl;
    stream << "1 sideLength 0 sideLength rmoveto" << endl;
    //this is the how its set up I just gave it a set size of 100 but used
    // your functions to complete the rest.
    //100 6 300 200 drawpoly %size, #sides, lenght?, width?
    return stream;
}

