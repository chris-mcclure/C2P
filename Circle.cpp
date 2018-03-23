//
//  Circle.cpp
//  C2P
//
//  Created by Chris McClure on 3/21/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include <stdio.h>
#include "Circle.h"
using std::ofstream;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
Circle::Circle(double radius){
    _radius = radius;
    toPostScript(_radius);
}

void Circle::toPostScript(double radius){
    ofstream post_stream;
    post_stream.open("circle.ps");
    post_stream << "%!" << endl;
    post_stream << "%% Circle Example" << endl;
    post_stream << "72 72 " << 2*radius
       << " 0 360" << " arc" << endl;
    post_stream << "closepath" << endl;
    post_stream << "0 1 0.5 setrgbcolor fill" << endl;
    post_stream << "stroke" << endl;
    post_stream << "showpage" << endl;
    post_stream.close();
}


