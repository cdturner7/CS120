//
//  Dinosaur.hpp
//  Project4
//
//  Created by Collin on 2/28/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#ifndef Dinosaur_hpp
#define Dinosaur_hpp

#include <stdio.h>
#include <string>
using namespace std;

// Base class Shape
class Dinosaur {
public:
    void setWidth(int w);
    void setHeight(int h);
    
private:
    int width;
    int height;
};

//Im making changes to see what this does in git!


// Derived class
class Rectangle: public Dinosaur
{
public:
    
};




#endif /* Dinosaur_hpp */
