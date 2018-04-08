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
#include "CustomShape.hpp"
#include "catch.hpp"
#include <memory>
using std::ostream;
using std::ofstream;
using std::ostringstream;
using std::vector;
using std::unique_ptr;
using std::endl;
using std::istringstream;
using std::ifstream;
using std::string;

ostringstream & intro(ostringstream & stream){
    stream << "%!" << endl;
    stream << "%% C2P" << endl;
    stream << "/inch {72 mul} def" << endl;
    stream << "0 inch 0 inch moveto" << endl;
    stream << "0 inch 1 inch rmoveto" << endl;
    stream << endl;
    return stream;
}

string readFile(string fileName){
    string s1;
    ifstream file(fileName);
    while(!file.eof())
        s1 += file.get();
    return s1;
}

/* Checks to see if the file actually gets created and opened. */

TEST_CASE("Basic Shape creation", "[Basic Shapes]"){
    SECTION("Basic Shapes"){
        ofstream post_stream("C2P.ps");
        ostringstream stream;
        intro(stream);
        std::unique_ptr<BasicShape> shape;
        
        REQUIRE(post_stream.is_open() == true);
        //Circle
        shape = std::make_unique<Circle>(25, "circle");
        shape->toPostScript(stream);
        shape->rotate(0, stream, shape->getName());
        REQUIRE(shape->getWidth() == 25);
        REQUIRE(shape->getHeight() == 25);
      
        //Spacer
        shape = std::make_unique<Spacer>(72, 72, "spacer");
        shape->toPostScript(stream);
        REQUIRE(shape->getWidth() == 72);
        REQUIRE(shape->getHeight() == 72);
        
        //Square
        shape = std::make_unique<Square>(45, "square");
        shape->toPostScript(stream);
        shape->rotate(45, stream, shape->getName());
        REQUIRE(shape->getWidth() == 45);
        REQUIRE(shape->getHeight() == 45);
        
        //Spacer
        shape = std::make_unique<Spacer>(72, 72, "spacer");
        shape->toPostScript(stream);
        REQUIRE(shape->getWidth() == 72);
        REQUIRE(shape->getHeight() == 72);
        
        //Triangle
        shape = std::make_unique<Triangle>(72, "triangle");
        shape->toPostScript(stream);
        shape->rotate(-10, stream, shape->getName());
        REQUIRE(shape->getWidth() == 72);
        REQUIRE(shape->getHeight() == 72);
        
        //Spacer
        shape = std::make_unique<Spacer>(72, 72, "spacer");
        shape->toPostScript(stream);
        REQUIRE(shape->getWidth() == 72);
        REQUIRE(shape->getHeight() == 72);
        
        //Rectangle
        shape = std::make_unique<Rectangle>(144, 72, "rectangle");
        shape->toPostScript(stream);
        shape->rotate(10, stream, shape->getName());
        REQUIRE(shape->getWidth() == 144);
        REQUIRE(shape->getHeight() == 72);

        
        //Spacer
        shape = std::make_unique<Spacer>(72, 72, "spacer");
        shape->toPostScript(stream);
        REQUIRE(shape->getWidth() == 72);
        REQUIRE(shape->getHeight() == 72);

        post_stream << stream.str();
        post_stream.close();
        REQUIRE(post_stream.is_open() == false);
        
        stream << "\377";
        string contents;
        contents = readFile("template.ps");
        REQUIRE(contents == stream.str());
        REQUIRE(shape->checkPostScript("C2P.ps") == "%!");
    }

    
  SECTION("custom shape"){
        ofstream post_stream("custom1.ps");
        REQUIRE(post_stream.is_open() == true);
        ostringstream stream;
        string contents;
        std::unique_ptr<Custom> custom = std::make_unique<Custom>(144*3, 144*3, 100, "watermelon");
       
        REQUIRE(custom->getRadius() == 100);
        REQUIRE(custom->getX() == 144*3);
        REQUIRE(custom->getY() == 144*3);
        REQUIRE(custom->getName() == "watermelon");
        custom->toPostScript(stream);
        custom->rotate(10, stream, custom->getName());
        post_stream << stream.str();
        post_stream.close();
        REQUIRE(post_stream.is_open() == false);
      
        stream << "\377";
        contents = readFile("customTemplate.ps");
        REQUIRE(contents == stream.str());
        REQUIRE(custom->checkPostScript("custom1.ps") == "%!");
        
    }
    
    SECTION("polygon"){
        ofstream post_stream("polygon.ps");
        ostringstream stream;
        string contents;
        
        REQUIRE(post_stream.is_open() == true);
        std::unique_ptr<Polygon> poly = std::make_unique<Polygon>(8, 50, "polygon");
        REQUIRE(poly->getNumSides() == 8);
        REQUIRE(poly->getSideLength() == 50);
        REQUIRE(poly->getName() == "polygon");
        poly->toPostScript(stream);
        post_stream << stream.str();
        post_stream.close();
        REQUIRE(post_stream.is_open() == false);
        
        stream << "\377";
        contents = readFile("polygonTemplate.ps");
        REQUIRE(contents == stream.str());
        REQUIRE(poly->checkPostScript("polygon.ps") == "%!");
        
    }
}

