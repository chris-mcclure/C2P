//
//  Triangle.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h

#include "BasicShape.h"
#include <fstream>
#include <iostream>

class Triangle : public BasicShape{
public:
   Triangle(double sideLength);
   std::ofstream & toPostScript(std::ofstream & stream);
   double getBoundingBox_X();
   double getBoundingBox_Y();
   std::ofstream & drawBoundingBox(double sideLength, std::ofstream & stream);
   std::ofstream & drawBoundingBox(double boxWidth, double boxHeight, std::ofstream & stream);
   double getSideLength() const;
private:
   double _sideLength;
};


#endif /* Triangle_h */
