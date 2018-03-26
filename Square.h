//
//  Square.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Square_h
#define Square_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "BasicShape.h"

class Square : public BasicShape{
public:
    Square(double sideLenth);
    void toPostScript(double sideLenth);
    void toPostScript(double var1, double var2);
    
private:
    double _sideLength;
};
#endif /* Square_h */
