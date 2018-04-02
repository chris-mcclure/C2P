//
//  Spacer.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Spacer_h
#define Spacer_h

#include "BasicShape.h"

class Spacer : public BasicShape{
public:
    Spacer(double width, double height);
    std::ostream & toPostScript(std::ostream & stream);
    void setWidth(double width);
    void setHeight(double height);
    double getWidth();
    double getHeight();
private:
    double _width;
    double _height;
};

#endif /* Spacer_h */
