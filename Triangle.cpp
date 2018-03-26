//
//  Triangle.cpp
//  C2P
//
//  Created by Chris McClure on 3/23/18.
//  Copyright © 2018 Chris McClure. All rights reserved.
//

#include "Triangle.h"
using std::ofstream;
using std::endl;

Triangle::Triangle(double sideLength)
   :_sideLength(sideLength)
{
   toPostScript(_sideLength);
}

void Triangle::toPostScript(double sideLength){
   ofstream post_stream;
   post_stream.open("t1.ps");
   post_stream << "%!" << endl;
   post_stream << "%% Triangle Example" << endl;
   post_stream << "/sideLength {" << sideLength << " mul} def" << endl;
   post_stream << "newpath" << endl;
   post_stream << "1 sideLength 1 sideLength moveto" << endl;
   post_stream << "2 sideLength 2 sideLength lineto" << endl;
   post_stream << "3 sideLength 1 sideLength lineto" << endl;
   post_stream << "closepath" << endl;
   post_stream << "stroke" << endl;
   post_stream << "showpage" << endl;
}

void Triangle::toPostScript(double var1, double var2){}
