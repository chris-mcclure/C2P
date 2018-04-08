//
//  Rectangle.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"

class Rectangle : public Shape{
public:
    Rectangle(double width, double height, const std::string & name);
    std::ostringstream & toPostScript(std::ostringstream & stream)override;
    double getBoundingBox_X();
    double getBoundingBox_Y();
    std::ostringstream & drawBoundingBox(double radius, std::ostringstream & stream);
    std::ostringstream & drawBoundingBox(double width, double height, std::ostringstream & stream);
    void setWidth(double width)override;
    void setHeight(double height)override;
    double getWidth()override;
    double getHeight()override;
    void setPostScript(std::ostringstream & stream);
    std::ostringstream & getPostScript()override;
    std::string getName()override;

private:
    double _width;
    double _height;
    std::string _name;
    std::ostringstream _stream;
};


#endif /* Rectangle_h */
