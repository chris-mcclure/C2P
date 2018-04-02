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


class Circle : public BasicShape{
public:
    Circle(double radius);
    std::ostream & toPostScript(std::ostream & stream);
    double getBoundingBox_X();
    double getBoundingBox_Y();
    double getWidth();
    double getHeight();
private:
    double _radius;
    double _width;
    double _height;
};

#endif /* Circle_h */
