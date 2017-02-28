//
//  Dinosaur.cpp
//  Project4
//
//  Created by Collin on 2/28/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#include "Dinosaur.hpp"
using namespace std;

// Base class Dinosaur
class Dinoasuar {
public:
    
    
    
    void setWidth(int w) {
        width = w;
    }
    
    void setHeight(int h) {
        height = h;
    }
    

};

// Base class PaintCost
class PaintCost  {
public:
    int getCost(int area) {
        return area * 70;
    }
};

// Derived class
class Rectangle: public Shape, public PaintCost {
public:
    int getArea() {
        return (width * height);
    }
};
