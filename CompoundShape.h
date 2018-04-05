
#ifndef CompoundShape_h
#define CompoundShape_h
#include "Shape.h"
#include <vector>
#include <fstream>
#include <memory>
class CompoundShape : public Shape {
public:
    std::ostringstream & rotate(int degree, std::ostringstream & stream, std::string name);
    std::ostringstream & scale(double width, double height, std::ostringstream & stream, std::string name);
    void stackHorizontal(std::vector<std::unique_ptr<Shape>> & cShape, std::ostringstream & stream);
    void stackVertical(std::vector<std::unique_ptr<Shape>> & cShape, std::ostringstream & stream);
    
};
#endif /* ComplexShape_h */

