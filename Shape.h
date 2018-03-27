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

class Shape{
public:
    bool file_open(const std::string & s);
    std::string checkPostScript(const std::string & s);
    virtual std::ofstream & toPostScript(double var1, std::ofstream & stream) = 0;
    virtual std::ofstream & toPostScript(double var1, double var2, std::ofstream & stream) = 0;
    virtual double getBoundingBox_X() = 0;
    virtual double getBoundingBox_Y() = 0;
    
private:
    double bounding_box;
    double current_point;
    
};
#endif /* Shape_h */
