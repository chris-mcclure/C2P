//
//  Triangle.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h

#include "Shape.h"

class Triangle : public Shape{
public:
    Triangle(double width, const std::string & name);
    std::ostringstream & toPostScript(std::ostringstream & stream)override;
    double getBoundingBox_X();
    double getBoundingBox_Y();
    std::ostringstream & drawBoundingBox(double sideLength, std::ostringstream & stream);
    std::ostringstream & drawBoundingBox(double boxWidth, double boxHeight, std::ostringstream & stream);
    double getWidth() override;
    double getHeight()override;
    std::string getName()override;
    void setPostScript(std::ostringstream & stream);
    std::ostringstream & getPostScript()override;
    void setWidth(double w)override;
    void setHeight(double h)override;
    

private:
    double _width;
    double _height;
    std::string _name;
    std::ostringstream _stream;
};


#endif /* Triangle_h */
