//
//  HorizontalShape.hpp
//  C2P
//
//  Created by Chris McClure on 3/31/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#ifndef HorizontalShape_hpp
#define HorizontalShape_hpp

#include "Shape.h"

class HorizontalShape{
public:
    HorizontalShape(Shape &s1, Shape &s2);
    HorizontalShape(Shape &s1, Shape &s2, Shape &s3);
};

#endif /* HorizontalShape_hpp */
