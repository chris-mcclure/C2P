
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
<<<<<<< HEAD
    std::ostringstream & stackHorizontal(std::vector<std::string> name, std::ostringstream & stream);
    std::ostringstream & stackVertical(std::vector<std::string> name, std::ostringstream & stream);
=======
    //void stackHorizontal(std::vector<std::unique_ptr<Shape>> & cShape, std::ostringstream & stream);
    //void stackVertical(std::vector<std::unique_ptr<Shape>> & cShape, std::ostringstream & stream);
>>>>>>> eef650d5d6c6c5160914ea680891f1a454f16871

};
#endif /* ComplexShape_h */

