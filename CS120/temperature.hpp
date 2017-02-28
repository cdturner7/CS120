

//
//  temperature.hpp
//  CS 120 A
//
//  Created by Lisa Dion on 2/2/17.
//  Copyright © 2017 Lisa Dion. All rights reserved.
//

#ifndef temperature_hpp
#define temperature_hpp

#include <iostream>
#include <vector>
using namespace std;

enum temperatureType {celsiusType, fahrenheitType};

enum weatherCondition {sunny, cloudy, rainy, snowy, stormy, apocalypse};

enum weekday {sunday, monday, tuesday, wednesday, thursday, friday, saturday};

class Temperature {
public:
    // default constructor
    /**
     * Requires: nothing
     * Modifies: fahrenheit and celsius
     * Effects: sets default values for
     *          fahrenheit (32) and
     *          celsius (0)
     */
    Temperature();
    /**
     * Requires: nothing
     * Modifies: fahrenheit and celsius
     * Effects: initialize fahrenheit and
     *          celsius
     */
    Temperature(temperatureType tt, double v);
    // destructor
    ~Temperature();
    
    // one RME for all getters and setters
    /**
     * Requires: nothing
     * Modifies: fahrenheit and celsius
     * Effects: get and set values for
     *          fahrenheit and celsius
     */
    double getFahrenheit() const;
    double getCelsius() const;
    void setFahrenheit(double fIn);
    void setCelsius(double cIn);
    
    // binary overloaded operators
    friend ostream& operator << (ostream& outs, const Temperature &t);
    friend bool operator < (const Temperature &lhs, const Temperature &rhs);
    // unary overloaded operator
    Temperature& operator += (const Temperature &rhs);
    Temperature& operator += (const double &rhs);
    
private:
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns celsius value
     *          equivalent to fahrenheit fIn
     */
    double convertFtoC(double fIn) const;
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns fahrenheit value
     *          equivalent to celsius cIn
     */
    double convertCtoF(double cIn) const;
    
    // fields
    double fahrenheit;
    double celsius;
};

class WeatherForecast {
public:
    WeatherForecast();
    
    // sets highs for the week
    // if vector contains > 7 elements,
    //   user first seven.
    // if vector contains < 7 elements,
    //   use those and default values for
    //   rest of the week
    void setHighs(const vector<Temperature> &highsIn);
    void setHigh(const Temperature &h, weekday wd);
    void setLows(const vector<Temperature> &lowsIn);
    void setLow(const Temperature &l, weekday wd);
    void setConditions(const vector<weatherCondition> &cndsIn);
    void setCondition(const weatherCondition &cnd, weekday wd);
    void setStartDay(weekday wd);
    
    // overloaded operators
    friend ostream& operator << (ostream& outs, const WeatherForecast & wf);
    
private:
    string dayToString(const weekday &day) const;
    
    vector<Temperature> highs;
    vector<Temperature> lows;
    vector<weatherCondition> conditions;
    weekday startDay;
};

/*
 const:
 parameter - cannot modify it
 method - cannot modify fields of the class 
 */

#endif /* temperature_hpp */
