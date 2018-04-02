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
    void rotate(CompoundShape & shape, int degree);
    void scale(CompoundShape & shape, double fx, double fy);
    void stackHorizontal(std::vector<std::unique_ptr<Shape>> & cShape, std::ostream & stream);
    void stackVertical(std::vector<std::unique_ptr<Shape>> & cShape, std::ostream & stream);
    
};
#endif /* ComplexShape_h */
