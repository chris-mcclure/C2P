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
    Circle(double width, const std::string & name);
    std::ostringstream & toPostScript(std::ostringstream & stream);
    double getBoundingBox_X();
    double getBoundingBox_Y();
    double getWidth();
    double getHeight();
    double getRadius();
    void setPostScript(std::ostringstream & stream);
    std::ostringstream & getPostScript();
    std::string getName();
private:
    double _radius;
    double _width;
    double _height;
    std::ostringstream _stream;
    std::string _name;
};

#endif /* Circle_h */
