//
//  Rectangle.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h

#include "BasicShape.h"
#include <fstream>
#include <iostream>

class Rectangle : public BasicShape{
public:
    Rectangle(double width, double height);
    void toPostScript(double width, double height);
    void toPostScript(double var1);
private:
    double _width;
    double _height;
};


#endif /* Rectangle_h */
