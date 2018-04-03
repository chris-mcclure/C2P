//
//  Shape.h
//  C2P
//
//  Created by Chris McClure on 3/21/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Shape_h
#define Shape_h
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Shape{
public:
    bool file_open(const std::string & s);
    std::string checkPostScript(const std::string & s);
    virtual std::ostringstream & toPostScript(std::ostringstream & stream) = 0;
    virtual double getWidth() = 0;
    virtual double getHeight() = 0;
    virtual std::ostringstream & getPostScript() = 0;
    void getShape(Shape & s);
    virtual std::string getName() = 0;
private:
    double bounding_box;
    double current_point;
    
};
#endif /* Shape_h */
