//
//  shapes_test.cpp
//  CS120
//
//  Created by Collin on 2/27/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#include "shapes.hpp"
#include <iostream>
using namespace std;

int main() {
    
    color blue = {0, 0, 1};
    cout << blue.red << endl;
    
    color green;
    green.red = green.blue = 0;
    green.green = 1;
    
    Shape parallelogram(4, 8, green);
    cout << parallelogram.get_area() << endl;
    cout << parallelogram.get_perimeter() << endl;
    color par = parallelogram.get_fill();
    cout << "(" << par.red << ", " << par.green << ", " << par.blue << ")" << endl;
    parallelogram.set_color(blue);
    par = parallelogram.get_fill();
    cout << "(" << par.red << ", " << par.green << ", " << par.blue << ")" << endl;
    parallelogram.set_color(1, 0, 0);
    par = parallelogram.get_fill();
    cout << "(" << par.red << ", " << par.green << ", " << par.blue << ")" << endl;
    
    Rectangle r(5, 2.5, color{1, 0, 0});
    r.set_width(7);
    cout << r.get_area() << endl;
    
    
    return 0;
}
