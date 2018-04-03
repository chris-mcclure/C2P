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
using std::string;

Spacer::Spacer(double width, double height, const string & name)
:_width(width), _height(height), _name(name)
{}

double Spacer::getWidth(){
    return _width;
}

double Spacer::getHeight(){
    return _height;
}

string Spacer::getName(){
    return _name;
}

void Spacer::setPostScript(ostringstream & stream){
    _stream = std::move(stream);
}

ostringstream & Spacer::getPostScript(){
    return _stream;
}

ostringstream & Spacer::toPostScript(ostringstream & stream){
    stream << "%%Spacer" << endl;
    stream << "/spacer {" << endl;
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
