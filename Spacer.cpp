//
//  Spacer.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Spacer.h"
using std::ofstream;
using std::endl;

Spacer::Spacer(double width, double height):
_width(width), _height(height)
{}

double Spacer::getWidth() const{
   return _width;
}

double Spacer::getHeight() const{
   return _height;
}

ofstream & Spacer::toPostScript(ofstream & stream){
   stream << "/width {" << getWidth() << " mul} def" << endl;
   stream << "/height {" << getHeight() << " mul} def" << endl;
   stream << "1 inch 0 inch moveto" << endl;
   stream << "1 width 0 height rlineto" << endl;
   stream << "0 width 1 height rlineto" << endl;
   stream << "-1 width 0 height rlineto" << endl;
   stream << "closepath" << endl;
   stream << "stroke" << endl;
   //stream << "showpage" << endl;
   stream << endl; 
   return stream;
}

