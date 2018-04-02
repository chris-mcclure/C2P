//
//  Spacer.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Spacer.h"
using std::ostream;
using std::endl;
using std::ostringstream;

Spacer::Spacer(double width, double height)
:_width(width), _height(height)
{}

double Spacer::getWidth(){
    return _width;
}

double Spacer::getHeight(){
    return _height;
}


ostringstream & Spacer::toPostScript(ostringstream & stream){
    stream << "%%Spacer" << endl;
    stream << "/spacer {"
    stream << "gsave" << endl;
    stream << "1 inch 0 inch rlineto" << endl;
    stream << "0 inch 1 inch rlineto" << endl;
    stream << "-1 inch 0 inch rlineto" << endl;
    stream << "closepath" << endl;
    stream << "stroke" << endl;
    stream << "grestore" << endl;
    stream << "1 inch 0 inch rmoveto" << endl;
    stream << "}def" << endl;
    stream << "spacer" <<endl; 
    stream << endl;
    return stream;
}
