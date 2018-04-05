
//
//  Customshape.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "CustomShape.hpp"
using std::ostream;
using std::endl;
using std::ostringstream;
using std::string;
#include <cmath>
#include <math.h>
#include <string>

Custom::Custom(double degrees, const string & name, double width):_radius(width/2),
_width(width), _height(width), _name(name)
{}

double Custom::getWidth(){
    return _width;
}

double Custom::getHeight(){
    return _height;
}

double Custom::getRadius(){
    return _radius;
}

void Custom::setWidth(double w) {
    _width = w;
}

void Custom::setHeight(double h) {
    _height = h;
}

string Custom::getName(){
    return _name;
}

ostringstream & Custom::getPostScript(){
    return _stream;
}

ostringstream & Custom::toPostScript(ostringstream & stream){
    // stream << "300 300 translate" << endl;  <--- this puts shape in the middle of the page
   /* stream << "%green part" << endl;
    stream << "/watermelon{" << endl;
    stream << "200 200 110 180 0 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "0 1 0.5 setrgbcolor fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;

    stream << "%melon" << endl;
    stream << "gsave" << endl;
    stream << "200 200 110 180 0 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "1 0 0.3 setrgbcolor fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    
    stream << "gsave" << endl;
    stream << "240 220 40 0 360 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << " 0.95 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    
    stream << "gsave" << endl;
    stream << "160 220 40 0 360 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "0.95 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    
    stream << "gsave" << endl;
    stream << "240 220 10 0 360 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "0 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    
    stream << "gsave" << endl;
    stream << "160 220 10 0 360 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "0 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    
    stream << "gsave" << endl;
    stream << "200 175 50 180 0 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "1 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    stream << "} def" << endl;
    stream << endl;
    */
    return stream;

}
