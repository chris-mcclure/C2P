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

class Rectangle : public BasicShape{
public:
    Rectangle(double width, double height);
    std::ostream & toPostScript(std::ostream & stream);
    double getBoundingBox_X();
    double getBoundingBox_Y();
    std::ostream & drawBoundingBox(double radius, std::ostream & stream);
    std::ostream & drawBoundingBox(double width, double height, std::ostream & stream);
    void setWidth(double width);
    void setHeight(double height);
    double getWidth();
    double getHeight();
private:
    double _width;
    double _height;
};


#endif /* Rectangle_h */
