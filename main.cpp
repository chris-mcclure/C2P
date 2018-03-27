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
#include "Polygon.h"
#include "catch.hpp"
using std::ofstream;

/* Checks to see if the file begins with the correct postscript comment "%!". */
/*TEST_CASE("check if postscript", "[comment]"){
   BasicShape *shape = new Circle(25);
   BasicShape *shape2 = new Square(72);
   REQUIRE(shape->checkPostScript("circle.ps") == "%!");
   REQUIRE(shape2->checkPostScript("square.ps") == "%!");
   delete shape2;
   delete shape;
}*/

/* Checks to see if the file actually gets created and opened. */
TEST_CASE("Basic Shape creation", "[Basic Shapes]"){
   
   SECTION("Basic Shapes"){
      ofstream post_stream;
      post_stream.open("C2P.ps");
      
      BasicShape *shape = new Circle(25);
      REQUIRE(shape->file_open("C2P.ps") == true);
      shape->toPostScript(25, post_stream);

      shape = new Square(34);
      shape->toPostScript(34, post_stream);

      shape = new Triangle(57.4);
      shape->toPostScript(57.4, post_stream);
      
      shape = new Rectangle(144, 72);
      shape->toPostScript(144, 72, post_stream);

      post_stream.close();
      delete shape;
   }
}




