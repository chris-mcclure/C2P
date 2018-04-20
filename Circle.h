//
//  Circle.h
//  C2P
//
//  Created by Chris McClure on 3/21/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Circle_h
#define Circle_h
#include "Shape.h"


class Circle : public Shape{
public:
    Circle(double width, const std::string & name);
    std::ostringstream & toPostScript(std::ostringstream & stream)override;
    double getBoundingBox_X();
    double getBoundingBox_Y();
    double getWidth()override;
    double getHeight()override;
    double getRadius();
    void setWidth(double w)override;
    void setHeight(double h)override;
    
    void setPostScript(std::ostringstream & stream);
    std::ostringstream & getPostScript()override;
    std::string getName()override;
private:
    double _radius;
    double _width;
    double _height;
    std::ostringstream _stream;
    std::string _name;
};

#endif /* Circle_h */
