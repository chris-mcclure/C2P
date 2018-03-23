//
//  BasicShape.hpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef BasicShape_h
#define BasicShape_h

#include <stdio.h>
#include "Shape.h"

class BasicShape : public Shape{
public:
   virtual ~BasicShape() = default;
};
#endif /* BasicShape_h */
