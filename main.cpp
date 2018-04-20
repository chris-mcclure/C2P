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
        std::unique_ptr<Shape> shape;
        
        
        REQUIRE(post_stream.is_open() == true);

        //Circle
        shape = std::make_unique<Circle>(25, "circle");
        shape->toPostScript(stream);
       // shape->rotate(0, stream, shape->getName());
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
       // shape->rotate(45, stream, shape->getName());
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
     //   shape->rotate(-10, stream, shape->getName());
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
       // shape->rotate(10, stream, shape->getName());
        REQUIRE(shape->getWidth() == 144);
        REQUIRE(shape->getHeight() == 72);
        
        //Spacer
        shape = std::make_unique<Spacer>(72, 72, "spacer");
        shape->toPostScript(stream);
        REQUIRE(shape->getWidth() == 72);
        REQUIRE(shape->getHeight() == 72);
        
        //watermelon
       /* shape = std::move(std::make_unique<Custom>(72, "watermelon", 72));
        shape->toPostScript(stream);
        shape->rotate(0, stream, shape->getName());
        */
        /*shape = std::move(std::make_unique<Polygon>(5, 50, "polygon"));
        shape->toPostScript(stream);
        shape->rotate(0, stream, "polygon");*/
        
        post_stream << stream.str();
        post_stream.close();
        stream << "\377";
        
        string contents;
        contents = readFile("template.ps");
        REQUIRE(contents == stream.str());
        REQUIRE(shape->checkPostScript("C2P.ps") == "%!");
        REQUIRE(post_stream.is_open() == false);
    }
}


//*** Attempting to create a compound shape through vector ***
/*
TEST_CASE("compund shape creation", "[compund]"){
    ofstream post_stream("c3.ps");
    ostringstream stream;
    intro(stream);
    
<<<<<<< HEAD
    /*
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
        
    }*/
=======
    vector<unique_ptr<CompoundShape>> _cShape;
    unique_ptr<CompoundShape> circle = std::make_unique<Circle>(25, "circle");
    unique_ptr<CompoundShape> square = std::make_unique<Square>(34, "square");
    unique_ptr<CompoundShape> triangle = std::make_unique<Triangle>(72, "triangle");
    unique_ptr<CompoundShape> rectangle = std::make_unique<Rectangle>(72, 144, "rectangle");
    unique_ptr<CompoundShape> spacer = std::make_unique<Spacer>(72, 72, "spacer");
>>>>>>> eef650d5d6c6c5160914ea680891f1a454f16871
    
    _cShape.push_back(std::move(circle));
    _cShape.push_back(std::move(square));
    _cShape.push_back(std::move(triangle));
    _cShape.push_back(std::move(rectangle));
    _cShape.push_back(std::move(spacer));
    
    for(auto &i : _cShape){
        i->toPostScript(stream);
    }
<<<<<<< HEAD
    
    SECTION("compound shape"){
        ofstream post_stream("compound.ps");
        ostringstream stream;
        
        intro(stream);
        vector<string> shapes;
        
        //shapes.push_back("circle");
        //shapes.push_back("rectangle");
        shapes.push_back("triangle");
        shapes.push_back("square");
        
        std::unique_ptr<CompoundShape> shape;
        shape->stackHorizontal(shapes, stream);
        stream << "showpage" << endl;
        
        post_stream << stream.str();
        post_stream.close();
        
    }
=======
    post_stream << stream.str();
    post_stream << "showpage" << endl;
    post_stream.close();
>>>>>>> eef650d5d6c6c5160914ea680891f1a454f16871
}
*/
