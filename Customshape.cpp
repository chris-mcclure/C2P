
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

Custom::Custom(double xpos, double ypos, double radius, std::string name) :_xpos(xpos), _ypos(ypos), _radius(radius), _name(name)
{}

double Custom::getX()const{
    return _xpos;
}

double Custom::getY()const{
    return _ypos;
}

double Custom::getWidth(){
    return _width;
}

double Custom::getHeight(){
    return _height;
}

double Custom::getRadius(){
    return _radius;
}


string Custom::getName(){
    return _name;
}

ostringstream & Custom::getPostScript(){
    return _stream;
}

ostringstream & Custom::toPostScript(ostringstream & stream){
    stream << "%green part" << endl;
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
    return stream;

}
