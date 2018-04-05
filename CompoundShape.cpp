#include "CompoundShape.h"
#include "Shape.h"
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

void stackHorizontal(vector<unique_ptr<Shape>> & cShape, ostringstream & stream){
    for(auto &i : cShape){
        
        //print shape
        stream << "1 width 0 height translate" << endl;
    }
}

void stackVertical(vector<unique_ptr<Shape>> & cShape, ostringstream & stream){
    for(auto &i : cShape){
        
        //print shape
        stream << "0 width 1 height translate" << endl;
    }
}

