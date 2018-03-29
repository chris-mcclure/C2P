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
#include <fstream>

class Spacer : public BasicShape{
public:
   Spacer(double width, double height, std::ofstream & stream);
   std::ofstream & toPostScript(double width, double height, std::ofstream & stream);
   std::ofstream & toPostScript(double var1, std::ofstream & stream);
   double getBoundingBox_X();
   double getBoundingBox_Y();
   std::ofstream & drawBoundingBox(double radius, std::ofstream & stream);
   std::ofstream & drawBoundingBox(double boxWidth, double boxHeight, std::ofstream & stream);
   
private:
   double _width;
   double _height;
};

#endif /* Spacer_h */
