//
//  Circle.h
//  C2P
//
//  Created by Chris McClure on 3/21/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Circle_h
#define Circle_h
#include "BasicShape.h"
#include <iostream>
#include <fstream>
#include <string>


class Circle : public BasicShape{
public:
    Circle(double radius);
    void toPostScript(double radius);
    void toPostScript(double var1, double var2);

private:
    double _radius;
};

#endif /* Circle_h */
