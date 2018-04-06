
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

Custom::Custom(double xpos, double ypos, double radius, string name):_radius(radius), _xpos(xpos), _ypos(ypos), _name(name)
{}

double Custom::getWidth(){
    return _width;
}

double Custom::getHeight(){
    return _height;
}

double Custom::getX() const{
    return _xpos;
}

double Custom::getY() const{
    return _ypos;
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

ostringstream & Custom::rotate(int degree, ostringstream & stream, string name){
    stream << "gsave" << endl;
    stream << "0 0 " << degree << " rotate" << endl;
    stream << name << " stroke" << endl;
    stream << "grestore" << endl;
    return stream;
}

ostringstream & Custom::toPostScript(ostringstream & stream){
    stream << "%!" << endl;
    stream << "%%Custom Shape" << endl;
    stream << "/watermelon {" << endl;
    stream << "/radius {" << getRadius() << " mul} def" << endl;
    stream << "/xpos {" << getX() << " mul} def" << endl;
    stream << "/ypos {" << getY() << " mul} def" << endl;
    
    stream << "gsave" << endl;
    stream << "1 xpos 1 ypos 1 radius 10 add 180 0 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "0 1 0.5 setrgbcolor fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;

    stream << "gsave" << endl;
    stream << "1 xpos 1 ypos 1 radius 180 0 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "1 0 0.3 setrgbcolor fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;

    stream << "gsave" << endl;
    stream << "1 xpos 40 add 1 ypos 20 add 1 radius 60 sub 0 360 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "0.95 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    
    stream << "gsave" << endl;
    stream << "1 xpos 40 sub 1 ypos 20 add 1 radius 60 sub 0 360 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "0.95 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    
    
    stream << "gsave" << endl;
    stream << "1 xpos 40 add 1 ypos 20 add 1 radius 90 sub 0 360 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "0 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    
    stream << "gsave" << endl;
    stream << "1 xpos 40 sub 1 ypos 20 add 1 radius 90 sub 0 360 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "0 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    
    stream << "gsave" << endl;
    stream << "1 xpos 1 ypos 25 sub 1 radius 50 sub 180 0 arc closepath" << endl;
    stream << "gsave" << endl;
    stream << "1 setgray fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    stream << "} def" << endl;
    
    stream << endl;
    return stream;

}
