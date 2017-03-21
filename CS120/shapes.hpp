//
//  shapes.hpp
//  CS 120 B
//
//  Created by Lisa Dion on 2/23/17.
//  Copyright © 2017 Lisa Dion. All rights reserved.
//

#ifndef shapes_hpp
#define shapes_hpp

#include <cmath>

enum shapeName {circle, rectangle, square, triangle, parallelogram, rhombus, trapezoid, quadrilateral, polygon};

struct color {
    double red;
    double green;
    double blue;
};

class Shape {
public:
    Shape();
    Shape(color f);
    Shape(double r, double g, double b);
    Shape(shapeName sn);
    Shape(shapeName sn, color f);
    Shape(shapeName sn, double r, double g, double b);
    
    virtual double getArea() const;
    virtual double getPerimeter() const;
    virtual color getFill() const;
    virtual shapeName getName() const;
    
    virtual void setFill(color f);
    virtual void setFill(double r, double g, double b);
protected:
    virtual void calcAreaPeri(double &a, double &p) = 0;
    
    double area;
    double perimeter;
    shapeName name;
private:
    color fill;
};

class Rectangle : public Shape {
public:
    Rectangle();
    
    // setters will modify area and perimeter also
    virtual void setHeight(double h);
    virtual void setWidth(double w);
private:
    // helper method to calculate area and perimeter
    virtual void calcAreaPeri(double &a, double &p) override;
    
    double height;
    double width;
};

class Circle : public Shape {
public:
    Circle();
    
    virtual double getRadius() const;
    
    // setters will modify area and perimeter also
    virtual void setRadius(double r);
private:
    // helper method to calculate area and perimeter
    virtual void calcAreaPeri(double &a, double &p) override;
    
    double radius;
};

// cout << "\u25A0";

#endif /* shapes_hpp */
