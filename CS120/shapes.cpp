//
//  shapes.cpp
//  CS120
//
//  Created by Collin on 2/27/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#include "shapes.hpp"

Shape::Shape(): area(0), perimeter(0) {
    fill.red = fill.green = fill.blue = 0;
}

Shape::Shape(double a, double p, color f): area(a), perimeter(p), fill(f) {
}

Shape::Shape(color f) : area(0), perimeter(0), fill(f) {
}

double Shape::get_area() const {
    return area;
}

double Shape::get_perimeter() const {
    return perimeter;
}

color Shape::get_fill() const {
    return fill;
}

void Shape::set_color(color c) {
    fill = c;
}

void Shape::set_color(double r, double g, double b) {
    fill = {r, g, b};
    /*
     fill.red = r;
     fill.green = g;
     fill.blue = b;
     */
}

Rectangle::Rectangle(): Shape(), length(0), width(0) {
}

Rectangle::Rectangle(double l, double w): Shape() {
    set_width(w);
    set_length(l);
}

Rectangle::Rectangle(double l, double w, color c): Shape(c) {
    set_width(w);
    set_length(l);
}

Rectangle::Rectangle(color c): Rectangle(0, 0, c) {
}

double Rectangle::get_length() const {
    return length;
}

double Rectangle::get_width() const {
    return width;
}

void Rectangle::set_length(double l) {
    length = l;
    if (l < 0) {
        length = 0;
    }
    calc_area_peri();
}

void Rectangle::set_width(double w) {
    width = w;
    if (w < 0) {
        width = 0;
    }
    calc_area_peri();
}

void Rectangle::calc_area_peri() {
    area = length * width;
    perimeter = 2 * length + 2 * width;
}

