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
using std::ostream;
using std::cout;
using std::endl;

bool Shape::file_open(const string & s){
    ifstream file(s);
    if(file.is_open())
        return true;
    return false;
}

string Shape::checkPostScript(const string & s){
    string s1;
    ifstream file(s);
    for(int i = 0; i < 2; ++i)
        s1 += file.get();
    return s1;
}



