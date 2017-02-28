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

//Create a struct
struct  {
    double red;
    double green;
    double blue;
};

// Base class Shape
class Dinosaur {
public:
    void setWidth(int w);
    void setHeight(int h);
    
private:
    int width;
    int height;
};


// Derived class
class Herbavore: public Dinosaur
{
public:
    
};




#endif /* Dinosaur_hpp */
