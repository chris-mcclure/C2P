//
//  ComplexShape.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef ComplexShape_h
#define ComplexShape_h

#include "Shape.h"
#include <vector>
#include <fstream>
#include <memory>
class CompoundShape : public Shape{
public:
    std::ostringstream & rotate(int degree, std::ostringstream & stream, std::string name);
    void scale(CompoundShape & shape, double fx, double fy);
    void stackHorizontal(std::vector<std::unique_ptr<Shape>> & cShape, std::ostringstream & stream);
    void stackVertical(std::vector<std::unique_ptr<Shape>> & cShape, std::ostringstream & stream);
    
};
#endif /* ComplexShape_h */
