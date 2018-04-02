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

class Triangle : public BasicShape{
public:
    Triangle(double width);
    std::ostream & toPostScript(std::ostream & stream);
    double getBoundingBox_X();
    double getBoundingBox_Y();
    std::ostream & drawBoundingBox(double sideLength, std::ostream & stream);
    std::ostream & drawBoundingBox(double boxWidth, double boxHeight, std::ostream & stream);
    double getWidth();
    double getHeight();
private:
    double _width;
    double _height;
    
};


#endif /* Triangle_h */
