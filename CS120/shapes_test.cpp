//
//  shapes_test.cpp
//  CS 120 B
//
//  Created by Lisa Dion on 2/23/17.
//  Copyright © 2017 Lisa Dion. All rights reserved.
//

#include "shapes.hpp"

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

/**
 * Requires: nothing
 * Modifies: a and b
 * Effects: swaps the addresses that a and b point at
 */
void swapPointers(int* &a, int* &b);

/**
 * Requires: nothing
 * Modifies: the memory a and b point at
 * Effects: swaps the values that a and b point at
 */
void swapValues(int* a, int* b);

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
    
    Circle c;
    c.setRadius(3.2);
    cout << c.getPerimeter() << endl;
    
    int first = 169;
    int second = 32;
    int* firstPtr = &first;
    int* secondPtr = &second;
    
    cout << "Before swap:" << endl;
    cout << firstPtr << endl;
    cout << secondPtr << endl;
    
    cout << first << endl;
    cout << second << endl;
    
    swapPointers(firstPtr, secondPtr);
    
    cout << "After swap pointers:" << endl;
    cout << firstPtr << endl;
    cout << secondPtr << endl;
    
    cout << first << endl;
    cout << second << endl;
    
    swapValues(firstPtr, secondPtr);
    
    cout << "After swap values:" << endl;
    cout << firstPtr << endl;
    cout << secondPtr << endl;
    
    cout << first << endl;
    cout << second << endl;
    
    
    
    vector<unique_ptr<Shape> > myShapes;
    //myShapes.push_back(make_unique<Rectangle>());
    //myShapes.push_back(make_unique<Circle>());
    
    for (int i = 0; i < myShapes.size(); ++i) {
        cout << myShapes[i]->getArea() << endl;
    }
    
    return 0;
}

void swapPointers(int* &a, int* &b) {
    int* temp = a;
    a = b;
    b = temp;
}

void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}





