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
    Spacer(double width, double height, const std::string & name);
    std::ostringstream & toPostScript(std::ostringstream & stream);
    void setWidth(double width);
    void setHeight(double height);
    double getWidth();
    double getHeight();
    void setPostScript(std::ostringstream & stream);
    std::string getName();
    std::ostringstream & getPostScript();

private:
    double _width;
    double _height;
    std::string _name;
    std::ostringstream _stream;
};

#endif /* Spacer_h */
