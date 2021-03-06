//
//  shapes.cpp
//  CS 120 B
//
//  Created by Lisa Dion on 2/23/17.
//  Copyright © 2017 Lisa Dion. All rights reserved.
//

/* Rappin' Rodney by Rodney Dangerfield */

#include "shapes.hpp"

Shape::Shape() : area(0), perimeter(0), name(polygon), fill({0, 0, 0}) {
}

Shape::Shape(color f) : area(0), perimeter(0), name(polygon), fill(f) {
}

Shape::Shape(double r, double g, double b) : area(0), perimeter(0), name(polygon), fill({r, g, b}) {
}

Shape::Shape(shapeName sn) : area(0), perimeter(0), name(sn), fill({0, 0, 0}) {
}
Shape::Shape(shapeName sn, color f) : area(0), perimeter(0), name(sn), fill(f) {
}
Shape::Shape(shapeName sn, double r, double g, double b) : area(0), perimeter(0), name(sn), fill({r, g, b}) {
}

double Shape::getArea() const {
    return area;
}

double Shape::getPerimeter() const {
    return perimeter;
}

color Shape::getFill() const {
    return fill;
}

shapeName Shape::getName() const {
    return name;
}

void Shape::setFill(color f) {
    fill = f;
}

void Shape::setFill(double r, double g, double b) {
    fill = {r, g, b};
}

Rectangle::Rectangle() : Shape(rectangle), height(0), width(0) {
}

void Rectangle::setHeight(double h) {
    height = h;
    if (h < 0) {
        height = 0;
    }
    calcAreaPeri(area, perimeter);
}

void Rectangle::setWidth(double w) {
    width = w;
    if (w < 0) {
        width = 0;
    }
    calcAreaPeri(area, perimeter);
}

void Rectangle::calcAreaPeri(double &a, double &p) {
    a = height * width;
    p = 2 * height + 2 * width;
}

Circle::Circle() : Shape(), radius(0) {
    calcAreaPeri(area, perimeter);
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    radius = r;
    calcAreaPeri(area, perimeter);
}

void Circle::calcAreaPeri(double &a, double &p) {
    a = M_PI * radius * radius;
    p = 2.0 * M_PI * radius;
}
