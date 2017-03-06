//
//  shapes_test.cpp
//  CS 120 B
//
//  Created by Lisa Dion on 2/23/17.
//  Copyright © 2017 Lisa Dion. All rights reserved.
//

#include "shapes.hpp"

#include <iostream>
using namespace std;

int main() {
    
    color aqua = {0, 0, 1};
    cout << aqua.red << endl;
    
    color grass;
    grass.red = grass.blue = 0;
    grass.green = 1;
    
    /*
     Shape r(rhombus);
     r.setFill(aqua);
     cout << r.getName() << endl;
     */
    
    Rectangle r;
    r.setWidth(4.4);
    r.setHeight(2);
    cout << r.getArea() << endl;
    
    return 0;
}
