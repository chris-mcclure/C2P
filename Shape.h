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
#include <vector>
#include <string>
using std::string;


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
    virtual void setWidth(double w) = 0;
    virtual void setHeight(double h) = 0;
    
    std::ostringstream & rotate(int degree, std::ostringstream & stream, std::string name);
    std::ostringstream & scale(double width, double height, std::ostringstream & stream, std::string name);
    std::ostringstream & stackHorizontal(std::vector<string> & name, std::ostringstream & stream);
    std::ostringstream & stackVertical(std::vector<string> & name, std::ostringstream & stream);

    
private:
    double bounding_box;
    double current_point;
    
};
#endif /* Shape_h */
