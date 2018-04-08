//
//  Spacer.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Spacer_h
#define Spacer_h

#include "Shape.h"

class Spacer : public Shape{
public:
    Spacer(double width, double height, const std::string & name);
    std::ostringstream & toPostScript(std::ostringstream & stream)override;
    void setWidth(double width)override;
    void setHeight(double height)override;
    double getWidth()override;
    double getHeight()override;
    void setPostScript(std::ostringstream & stream);
    std::string getName()override;
    std::ostringstream & getPostScript()override;

private:
    double _width;
    double _height;
    std::string _name;
    std::ostringstream _stream;
};

#endif /* Spacer_h */
