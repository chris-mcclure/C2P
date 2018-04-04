//
//  Customshape.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Customshape.h"
using std::ostream;
using std::endl;
using std::ostringstream;
#include <cmath>
#include <math.h>

Custom::Custom(double degrees, const string & name):_radius(width/2),
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

ostringstream & Circle::toPostScript(ostringstream & stream){
  // stream << "300 300 translate" << endl;  <--- this puts shape in the middle of the page
  stream << "/rad 216 def " << endl;
  stream << "/rad1 rad 2 div def " << endl;
  stream << "/rad2 rad 12 div def " << endl;
  stream << "1 1 1 setrgbcolor fill " << endl;
  stream << "0 rad1 neg rad1 270 90 arc " << endl; //270 and 90 values are degree values
  stream << "0 rad1 rad1 270 90 arcn " << endl; //270 and 90 values are degrees values
  stream << "0 0 0 setrgbcolor eofill " << endl; // ^^replace with degrees value.
  stream << "fill " << endl;
  stream << "stroke " << endl;
  stream << "showpage " << endl;
  return stream;
}
