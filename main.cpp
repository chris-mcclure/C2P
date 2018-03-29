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
#include "Spacer.h"
#include "Rectangle.h"
#include "catch.hpp"
#include <memory>

using std::ofstream;
using std::vector;
using std::unique_ptr;
/* Checks to see if the file actually gets created and opened. */
TEST_CASE("Basic Shape creation", "[Basic Shapes]"){
   SECTION("Basic Shapes"){
      ofstream post_stream;
      post_stream.open("C2P.ps");
      std::unique_ptr<BasicShape> shape;
      
      REQUIRE(post_stream.is_open() == true);
      shape = std::move(std::make_unique<Circle>(25, post_stream));
      REQUIRE(shape->checkPostScript("C2P.ps") == "%!");
      shape = std::move(std::make_unique<Square>(34, post_stream));
      shape = std::move(std::make_unique<Triangle>(72, post_stream));
      shape = std::move(std::make_unique<Rectangle>(144, 72, post_stream));
      shape = std::move(std::make_unique<Spacer>(144, 72, post_stream));
      post_stream.close();
      REQUIRE(post_stream.is_open() == false);
   }
   
}

 


