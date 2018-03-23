//
//  Shape.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//
#include "Shape.h"
using std::ifstream;
using std::string;

bool Shape::file_open(const string & s){
    ifstream file(s);
    if(file.is_open())
        return true;
    return false;
}
