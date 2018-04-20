//
//  Shape.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//
#include "Shape.h"
using std::ifstream;
#include "CompoundShape.h"
#include "BasicShape.h"
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include <memory>
#include <iostream>
using std::ostream;
using std::vector;
using std::unique_ptr;
using std::endl;
using std::make_unique;
using std::string;
using std::ostringstream;


bool Shape::file_open(const string & s){
    ifstream file(s);
    if(file.is_open())
        return true;
    return false;
}

string Shape::checkPostScript(const string & s){
    string s1;
    ifstream file(s);
    for(int i = 0; i < 2; ++i)
        s1 += file.get();
    return s1;
}



ostringstream & Shape::rotate(int degree, ostringstream & stream, string name){
    stream << "gsave" << endl;
    stream << "0 0 " << degree << " rotate" << endl;
    stream << name << " stroke" << endl;
    stream << "grestore" << endl;
    stream << "1 width 0 height rmoveto" << endl;
    return stream;
}

ostringstream & Shape::scale(double width, double height, ostringstream & stream, string name){
    
    stream << "gsave" << endl;
    stream << height << width << " scale" << endl;
    stream << name << " stroke" << endl;
    stream << "grestore" << endl;
    stream << "1 width 0 height rmoveto" << endl;
    return stream;
    
}

ostringstream & Shape::stackHorizontal(vector<string> & name, ostringstream & stream){
    std::unique_ptr<Shape> shape;
    
    for (int i = 0; i < name.size(); ++i) {
        if (name[i] == "triangle"){
            shape = std::make_unique<Triangle>(72, "triangle");
            shape->toPostScript(stream);
            stream << "triangle stroke" << endl;
            stream << "1 width 0 height translate" << endl;
            
        }
        else if(name[i] == "square") {
            shape = std::make_unique<Square>(45, "square");
            shape->toPostScript(stream);
            stream << "square stroke" << endl;
            stream << "1 width 0 height translate" << endl;
            
        }
        else if(name[i] == "circle") {
            shape = std::make_unique<Circle>(25, "circle");
            shape->toPostScript(stream);
            stream << "cricle stroke" << endl;
            stream << "1 width 0 height translate" << endl;
        }
        else if(name[i] == "rectangle") {
            shape = std::make_unique<Rectangle>(144, 72, "rectangle");
            shape->toPostScript(stream);
            stream << "rectangle stroke" << endl;
            stream << "1 width 0 height translate" << endl;
        }
        else if(name[i] == "polygon") {
            shape = std::make_unique<Polygon>(5, 72, "pentagon");
            shape->toPostScript(stream);
            stream << "polygon stroke" << endl;
            stream << "1 width 0 height translate" << endl;
            
        }
    }
    return stream;
}

ostringstream & Shape::stackVertical(vector<string> & name, ostringstream & stream){
    
    std::unique_ptr<Shape> shape;
    
    for (int i = 0; i < name.size(); ++i) {
        if (name[i] == "triangle"){
            shape = std::make_unique<Triangle>(72, "triangle");
            shape->toPostScript(stream);
            stream << "triangle stroke" << endl;
            stream << "0 width 1 height translate" << endl;
            
        }
        else if(name[i] == "square") {
            shape = std::make_unique<Square>(45, "square");
            shape->toPostScript(stream);
            stream << "square stroke" << endl;
            stream << "0 width 1 height translate" << endl;
            
        }
        else if(name[i] == "circle") {
            shape = std::make_unique<Circle>(25, "circle");
            shape->toPostScript(stream);
            stream << "cricle stroke" << endl;
            stream << "0 width 1 height translate" << endl;
        }
        else if(name[i] == "rectangle") {
            shape = std::make_unique<Rectangle>(144, 72, "rectangle");
            shape->toPostScript(stream);
            stream << "rectangle stroke" << endl;
            stream << "0 width 1 height translate" << endl;
        }
        else if(name[i] == "polygon") {
            shape = std::make_unique<Polygon>(5, 72, "pentagon");
            shape->toPostScript(stream);
            stream << "polygon stroke" << endl;
            stream << "0 width 1 height translate" << endl;
            
        }
    }
    return stream;
}

