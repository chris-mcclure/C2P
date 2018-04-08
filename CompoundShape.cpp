


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

ostringstream & CompoundShape::rotate(int degree, ostringstream & stream, string name){
    stream << "gsave" << endl;
    stream << "0 0 " << degree << " rotate" << endl;
    stream << name << " stroke" << endl;
    stream << "grestore" << endl;
    stream << "1 width 0 height rmoveto" << endl;
    return stream;
}

ostringstream & CompoundShape::scale(double width, double height, ostringstream & stream, string name){

    stream << "gsave" << endl;
    stream << height << width << " scale" << endl;
    stream << name << " stroke" << endl;
    stream << "grestore" << endl;
    stream << "1 width 0 height rmoveto" << endl;
    return stream;

}

ostringstream & stackHorizontal(vector<string> & name, ostringstream & stream){
    
    for (int i = 0; i < name.size(); ++i) {
        if (name[i] == "triangle"){
                Triangle m(1, "triangle");
                m.toPostScript(stream);
            stream << "triangle stroke" << endl;
            stream << "1 width 0 height translate" << endl;
            
        }
        else if(name[i] == "square") {
                Square n(1, "square");
                n.toPostScript(stream);
            stream << "square stroke" << endl;
            stream << "1 width 0 height translate" << endl;
            
        }
        else if(name[i] == "circle") {
            Circle n(1, "circle");
            n.toPostScript(stream);
            stream << "cricle stroke" << endl;
            stream << "1 width 0 height translate" << endl;
        }
        else if(name[i] == "rectangle") {
            Rectangle n(1, 2, "rectangle");
            n.toPostScript(stream);
            stream << "rectangle stroke" << endl;
            stream << "1 width 0 height translate" << endl;
        }
        else if(name[i] == "polygon") {
            Polygon n(5, 1, "polygon");
            n.toPostScript(stream);
            stream << "polygon stroke" << endl;
            stream << "1 width 0 height translate" << endl;
            
        }
    }
    return stream;
}

ostringstream & stackVertical(vector<string> & name, ostringstream & stream){
    
    for (int i = 0; i < name.size(); ++i) {
        if (name[i] == "triangle"){
            Triangle m(1, "triangle");
            m.toPostScript(stream);
            stream << "triangle stroke" << endl;
            stream << "0 width 1 height translate" << endl;
            
        }
        else if(name[i] == "square") {
            Square n(1, "square");
            n.toPostScript(stream);
            stream << "square stroke" << endl;
            stream << "0 width 1 height translate" << endl;
            
        }
        else if(name[i] == "circle") {
            Circle n(1, "circle");
            n.toPostScript(stream);
            stream << "cricle stroke" << endl;
            stream << "0 width 1 height translate" << endl;
        }
        else if(name[i] == "rectangle") {
            Rectangle n(1, 2, "rectangle");
            n.toPostScript(stream);
            stream << "rectangle stroke" << endl;
           stream << "0 width 1 height translate" << endl;
        }
        else if(name[i] == "polygon") {
            Polygon n(5, 1, "polygon");
            n.toPostScript(stream);
            stream << "polygon stroke" << endl;
            stream << "0 width 1 height translate" << endl;
            
        }
    }
    return stream;
}

