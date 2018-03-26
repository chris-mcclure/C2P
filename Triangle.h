//
//  Triangle.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h

#include "BasicShape.h"
#include <fstream>
#include <iostream>

class Triangle : public BasicShape{
public:
    Triangle(double sideLenth);
    void toPostScript(double sideLength);
    void toPostScript(double var1, double var2);

private:
    double _sideLength;
};


#endif /* Triangle_h */
