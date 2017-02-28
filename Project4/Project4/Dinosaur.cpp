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


// Derived class
class Herbavore: public Dinosaur
{
    Herbavore :()
public:
    int getArea() {
        return (width * height);
    }
};
