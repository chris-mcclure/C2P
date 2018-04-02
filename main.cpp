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
#include "catch.hpp"
#include <memory>
using std::ostream;
using std::ofstream;
using std::vector;
using std::unique_ptr;
using std::endl;

ostream & intro(ostream & stream){
    stream << "%!" << endl;
    stream << "%% C2P" << endl;
    stream << "/inch {72 mul} def" << endl;
    stream << "0 inch 0 inch moveto" << endl;
    stream << "0 inch 1 inch rmoveto" << endl;
    stream << endl;
    return stream;
}

/* Checks to see if the file actually gets created and opened. */

TEST_CASE("Basic Shape creation", "[Basic Shapes]"){
    SECTION("Basic Shapes"){
        ofstream post_stream("C2P.ps");
        REQUIRE(post_stream.is_open() == true);
        
        intro(post_stream);
        std::unique_ptr<BasicShape> shape;
        
        shape = std::move(std::make_unique<Circle>(25));
        shape->toPostScript(post_stream);
        shape = std::move(std::make_unique<Spacer>(72, 72));
        shape->toPostScript(post_stream);
        shape = std::move(std::make_unique<Square>(34));
        shape->toPostScript(post_stream);
        shape = std::move(std::make_unique<Spacer>(72, 72));
        shape->toPostScript(post_stream);
        shape = std::move(std::make_unique<Triangle>(72));
        shape->toPostScript(post_stream);
        shape = std::move(std::make_unique<Spacer>(72, 72));
        shape->toPostScript(post_stream);
        shape = std::move(std::make_unique<Rectangle>(144, 72));
        shape->toPostScript(post_stream);
        shape = std::move(std::make_unique<Spacer>(72, 72));
        shape->toPostScript(post_stream);
        post_stream.close();
        
        REQUIRE(shape->checkPostScript("C2P.ps") == "%!");
        REQUIRE(post_stream.is_open() == false);
    }
    SECTION("get size"){
    }
}


//*** Attempting to create a compound shape through vector ***

TEST_CASE("compund shape creation", "[compund]"){
    ofstream post_stream("c3.ps");
    intro(post_stream);
    
    vector<unique_ptr<Shape>> _cShape;
    unique_ptr<Shape> circle = std::make_unique<Circle>(25);
    unique_ptr<Shape> square = std::make_unique<Square>(34);
    unique_ptr<Shape> triangle = std::make_unique<Triangle>(72);
    unique_ptr<Shape> rectangle = std::make_unique<Rectangle>(72, 144);
    unique_ptr<Shape> spacer = std::make_unique<Spacer>(72, 72);
    
    _cShape.push_back(std::move(circle));
    _cShape.push_back(std::move(square));
    _cShape.push_back(std::move(triangle));
    _cShape.push_back(std::move(rectangle));
    _cShape.push_back(std::move(spacer));
    
    for(auto &i : _cShape){
        i->toPostScript(post_stream);
    }
    post_stream.close();
}
