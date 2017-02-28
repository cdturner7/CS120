//
//  shapes.hpp
//  CS120
//
//  Created by Collin on 2/27/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#ifndef shapes_hpp
#define shapes_hpp

struct color {
    double red;
    double green;
    double blue;
};

class Shape {
public:
    Shape();
    Shape(double a, double p, color f);
    Shape(color f);
    
    double get_area() const;
    double get_perimeter() const;
    color get_fill() const;
    
    void set_color(color c);
    void set_color(double r, double g, double b);
protected:
    double area;
    double perimeter;
private:
    color fill;
};

class Rectangle : public Shape {
public:
    Rectangle();
    Rectangle(double l, double w);
    Rectangle(double l, double w, color c);
    Rectangle(color c);
    
    double get_length() const;
    double get_width() const;
    
    void set_length(double l);
    void set_width(double w);
private:
    // Modifies: area and perimeter
    // Will access length and width directly
    void calc_area_peri();
    
    double length;
    double width;
};



#endif /* shapes_hpp */
