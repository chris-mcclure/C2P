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

Spacer::Spacer(double width, double height, ofstream & stream):
_width(width), _height(height)
{
   toPostScript(_width, _height, stream);
}

double Spacer::getBoundingBox_X(){
   return _width;
}

double Spacer::getBoundingBox_Y(){
   return _height;
}

ofstream & Spacer::toPostScript(double width, double height, ofstream & stream){
   stream << "%!" << endl;
   stream << "%% Spacer example" << endl;
   stream << "/width {" << width << " mul} def" << endl;
   stream << "/height {" << height << " mul} def" << endl;
   stream << "newpath" << endl;
   stream << "216 360 moveto" << endl;
   stream << "1 width 0 height rlineto" << endl;
   stream << "0 width 1 height rlineto" << endl;
   stream << "-1 width 0 height rlineto" << endl;
   stream << "closepath" << endl;
   stream << "showpage" << endl;
   stream << endl;
   return stream;
}

ofstream & Spacer::toPostScript(double var1, ofstream & stream){
   return stream;
}

ofstream & Spacer::drawBoundingBox(double radius, ofstream & stream){
   return stream;
}

ofstream & Spacer::drawBoundingBox(double boxWidth, double boxHeight, ofstream & stream){
   return stream;
}
