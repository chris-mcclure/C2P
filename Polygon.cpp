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

Polygon::Polygon(int numSides, double sideLength, const std::string & name) //change sideLength to size
:_numSides(numSides), _sideLength(sideLength),  _name(name)
{}

double Polygon::getWidth(){
    switch (_numSides % 2) {
        case 0:
            if(_numSides % 4 == 0) {
                _width = (_sideLength * cos(M_PI/_numSides))/(sin(M_PI/_numSides));
            }
            else {
                _width = _sideLength / (sin(M_PI/_numSides));
            }
            break;
        case 1:
            _width = (_sideLength * sin(M_PI*(_numSides - 1)/(2 * _numSides))) / (sin(M_PI/_numSides));
            break;
        default:
            break;
    }

    return _width;
}

double Polygon::getHeight(){
    switch (_numSides % 2) {
        case 0:
            if(_numSides % 4 == 0) {
                _height = _sideLength * (cos(M_PI/_numSides)) / (sin(M_PI/_numSides));
            }
            else {
                _height = _sideLength * (cos(M_PI/_numSides)) / (sin(M_PI/_numSides));
            }
            break;
        case 1:
            _height = _sideLength * (1 + cos(M_PI/_numSides)) / (2 * sin(M_PI/_numSides));
            break;
        default:
            break;
    }


    return _height;
}

void Polygon::setWidth(double w) {
    _width = w;
}

void Polygon::setHeight(double h) {
    _height = h;
}

double Polygon::getNumSides() const{
    return _numSides;
}

double Polygon::getSideLength() const{
    return _sideLength;
}

void Polygon::setPostScript(ostringstream & stream){
    _stream = std::move(stream);
}

std::string Polygon::getName(){
    return _name;
}

ostringstream & Polygon::getPostScript(){
    return _stream;
}
ostringstream & Polygon::toPostScript(ostringstream & stream){
    
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
    stream << "/drawpoly {" << endl;
    stream << "gsave" << endl;
    stream << "translate" << endl;
    stream << "1 index 0 moveto" << endl;
    stream << "{" << endl;
    stream << "1 0 lineto" << endl;
    stream << "} defpoly" << endl;
    stream << "closepath stroke" << endl;
    stream << "grestore" << endl;
    stream << "} def" << endl;
    stream << "100" << getNumSides() << getHeight() << getWidth() << "drawpoly"<< endl;
    return stream;
}
