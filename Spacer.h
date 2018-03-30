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
   Spacer(double width, double height);
   std::ofstream & toPostScript(std::ofstream & stream);
   double getWidth() const;
   double getHeight() const;
private:
   double _width;
   double _height;
};

#endif /* Spacer_h */
