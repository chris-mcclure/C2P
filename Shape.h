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
#include "fstream"

class Shape{
public:
    bool file_open(const std::string & s);
    std::string checkPostScript(const std::string & s);
    virtual void toPostScript(double var1) = 0;
    virtual void toPostScript(double var1, double var2) = 0;
    
private:
    int bounding_box;
    int current_point;
    
};
#endif /* Shape_h */
