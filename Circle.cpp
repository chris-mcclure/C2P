//
//  Circle.cpp
//  C2P
//
//  Created by Chris McClure on 3/21/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include <stdio.h>
#include "Circle.h"
using std::ofstream;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;

Circle::Circle(double radius):
    _radius(radius)
{}

double Circle::getBoundingBox_X(){
    return 2.0 * _radius;
}

double Circle::getBoundingBox_Y(){
    return 2.0 * _radius;
}

ofstream & Circle::toPostScript(double radius, ofstream & stream){
    stream << "%!" << endl;
    stream << "%% Circle Example" << endl;
    stream << "/radius {" << radius << " mul} def" << endl;
    stream << "72 216 1 radius 0 360 arc" << endl;
    stream << "closepath" << endl;
    stream << "gsave" << endl;
    stream << "0 1 0.5 setrgbcolor fill" << endl;
    stream << "grestore" << endl;
    stream << "stroke" << endl;
    stream << endl;
    return stream;
}

ofstream & Circle::toPostScript(double var1, double var2, ofstream & stream){
    return stream;
}
