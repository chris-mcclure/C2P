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
    std::ostringstream & toPostScript(std::ostringstream & stream);
    double getBoundingBox_X();
    double getBoundingBox_Y();
    std::ostringstream & drawBoundingBox(double radius, std::ostringstream & stream);
    std::ostringstream & drawBoundingBox(double width, double height, std::ostringstream & stream);
    void setWidth(double width);
    void setHeight(double height);
    double getWidth();
    double getHeight();
private:
    double _width;
    double _height;
};


#endif /* Rectangle_h */
