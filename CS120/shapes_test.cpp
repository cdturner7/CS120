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
    cout << r.getName() << endl;
    r.setWidth(4.4);
    r.setHeight(2);
    cout << r.getArea() << endl;
    
    return 0;
}
