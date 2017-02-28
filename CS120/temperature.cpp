//
//  temperature.cpp
//  CS 120 A
//
//  Created by Lisa Dion on 2/2/17.
//  Copyright © 2017 Lisa Dion. All rights reserved.
//

#include "temperature.hpp"

Temperature::Temperature() {
    celsius = 0.0;
    fahrenheit = 32.0;
}

Temperature::Temperature(temperatureType tt, double v) {
    if (tt == celsiusType) {
        setCelsius(v);
    } else {
        setFahrenheit(v);
    }
}

Temperature::~Temperature() {
}

double Temperature::getFahrenheit() const{
    return fahrenheit;
}

double Temperature::getCelsius() const{
    return celsius;
}

void Temperature::setFahrenheit(double fIn) {
    fahrenheit = fIn;
    celsius = convertFtoC(fIn);
}

void Temperature::setCelsius(double cIn) {
    celsius = cIn;
    fahrenheit = convertCtoF(cIn);
}

ostream& operator << (ostream& outs, const Temperature &t) {
    outs << t.fahrenheit << "F/" << t.celsius << "C";
    return outs;
}

bool operator < (const Temperature &lhs, const Temperature &rhs) {
    return lhs.celsius < rhs.celsius;
}

Temperature& Temperature::operator += (const Temperature &rhs) {
    fahrenheit += rhs.fahrenheit;
    return *this;
}

double Temperature::convertFtoC(double fIn) const {
    return (5.0/9.0)*(fIn-32);
}

double Temperature::convertCtoF(double cIn) const {
    return (9.0/5.0*cIn)+32;
}

WeatherForecast::WeatherForecast() {
    for (int i = 0; i < 7; ++i) {
        highs.push_back(Temperature());
        lows.push_back(Temperature());
    }
    startDay = tuesday;
}

void WeatherForecast::setHigh(const Temperature &h, weekday wd) {
    // assume our vector highs has 7 temps.
    int index = ((int)wd - (int)startDay);
    if (index < 0) {
        index += 7;
    }
    cout << "index: " << index << endl;
    highs[index] = h;
}

ostream& operator << (ostream& outs, const WeatherForecast & wf) {
    weekday tempDay = wf.startDay;
    for (int i = 0; i < 7; ++i) {
        outs << wf.dayToString(tempDay) << " high: " << wf.highs[i] << endl;
        // update tempDay to be the next
        // day of the week
        tempDay=weekday(((int)tempDay + 1) % 7);
    }
    return outs;
}

string WeatherForecast::dayToString(const weekday &day) const {
    switch(day) {
        case sunday: return "Sun";
        case monday: return "Mon";
        case tuesday: return "Tue";
        case wednesday: return "Wed";
        case thursday: return "Thu";
        case friday: return "Fri";
        case saturday: return "Sat";
    }
}

