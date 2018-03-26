//
//  Rectangle.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h


#include <iostream>
#include <fstream>
#include "BasicShape.h"

class Rectangle : public BasicShape{
public:
    Rectangle(double width, double height);
    void toPostScript(double width, double height);
private:
    double _width;
    double _height;
};


#endif /* Rectangle_h */
