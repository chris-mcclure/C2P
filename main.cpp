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
#include "Triangle.h"
#include "Rectangle.h"
#include "catch.hpp"


/* Checks to see if the file begins with the correct postscript comment "%!". */
TEST_CASE("check if postscript", "[comment]"){
   BasicShape *shape = new Circle(25);
   BasicShape *shape2 = new Square(72);
   REQUIRE(shape->checkPostScript("circle.ps") == "%!");
   REQUIRE(shape2->checkPostScript("square.ps") == "%!");
   delete shape2;
   delete shape;
}

/* Checks to see if the file actually gets created and opened. */
TEST_CASE("file opens", "[opens]"){
   SECTION("circle"){
      BasicShape *shape = new Circle(25);
      REQUIRE(shape->file_open("circle.ps") == true);
      REQUIRE(shape->file_open("c.ps") == false);
      delete shape;
   }

   SECTION("square"){
      BasicShape *shape = new Square(72);
      REQUIRE(shape->file_open("square.ps") == true);
      REQUIRE(shape->file_open("s.ps") == false);
      delete shape;
   }
   
   SECTION("triangle"){
      BasicShape *shape = new Triangle(57.4);
      REQUIRE(shape->file_open("t1.ps") == true);
      REQUIRE(shape->file_open("t.ps") == false);
      delete shape;
   }
   
   SECTION("rectangle"){
      BasicShape *shape = new Rectangle(144, 72);
      REQUIRE(shape->file_open("rectangle.ps") == true);
      REQUIRE(shape->file_open("r.ps") == false);
      delete shape;
   }
}




