//
//  main.cpp
//  C2P
//
//  Created by Chris McClure on 3/21/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//
#define CATCH_CONFIG_MAIN
#include "Circle.h"
#include "Square.h"
#include "catch.hpp"


TEST_CASE("file opens", "[opens]"){
   SECTION("circle"){
      BasicShape *shape = new Circle(25);
      REQUIRE(shape->file_open("circle.ps") == true);
      REQUIRE(shape->file_open("s.ps") == false);
      delete shape;
   }

   SECTION("square"){
      BasicShape *shape = new Square(72);
      REQUIRE(shape->file_open("square.ps") == true);
      REQUIRE(shape->file_open("s.ps") == false);
      delete shape;
   }
}



