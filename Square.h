//
//  Square.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Square_h
#define Square_h

#include "BasicShape.h"

class Square : public BasicShape{
public:
    Square(double width);
    std::ostream & toPostScript(std::ostream & stream);
    double getBoundingBox_X();
    double getBoundingBox_Y();
    std::ostream & drawBoundingBox(double radius, std::ostream & stream);
    std::ostream & drawBoundingBox(double boxWidth, double boxHeight, std::ostream & stream);
    double getWidth();
    double getHeight();
private:
    double _width;
    double _height;
};
#endif /* Square_h */
