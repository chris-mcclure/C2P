//
//  Polygon.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef Polygon_h
#define Polygon_h
#include "BasicShape.h"
#include <fstream>
#include <iostream>

class Polygon : public BasicShape{
public:
   Polygon(double numSides, double sideLength);
   std::ofstream & toPostScript(std::ofstream & stream);
   double getNumSides() const;
   double getSideLength() const;
private:
   double _numSides;
   double _sideLength;
};

#endif /* Polygon_h */
