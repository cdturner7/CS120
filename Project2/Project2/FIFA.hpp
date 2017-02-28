//
//  FIFA.hpp
//  Project2
//
//  Created by Collin on 2/6/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#ifndef FIFA_hpp
#define FIFA_hpp

#include <stdio.h>
#include <string>
using namespace std;

class FIFA_player {
    
public:
    
    //default constructor
    FIFA_player();
    
    //constructor with player name only
    FIFA_player(string n);
    
    //constructor with name & goals
    FIFA_player(string n, int g);
    
    //constructor with name & goals & assists
    FIFA_player(string n, int g, int a);
    
    //constructor with name & goals & assists & team
    FIFA_player(string n, int g, int a, string t);
    
    //constructor with name & goals & assists & team & starting position
    FIFA_player(string n, int g, int a, string t, bool s);
    
    //destructor
    ~FIFA_player();
    
    /**
     * Requires: nothing or input from user for setting field
     * Modifies: goals, assists, team name, player name, 
     *           overall rating, starting
     * Effects:  gets or sets values for goals, assists,
     *           team name, player name, overall rating,
     *           starting
     */
    //Getters
    int getGoals() const;
    int getAssists() const;
    int getOverall() const;
    bool getStart() const;
    string getTeam() const;
    string getName() const;
    
    //Setters
    void setGoals(int in_g);
    void setAssists(int in_a);
    void setStart(bool in_s);
    void setTeam(string in_t);
    void setName(string in_n);
    
    //toString method
    string toString() const;
    
    // binary operator overloads
    friend ostream& operator << (ostream& output, const FIFA_player &fifa_player);
    
    friend bool operator > (const FIFA_player &lhs, const FIFA_player &rhs);
    
    
    
private:
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  calculates the overall rating for player
     */
    int calcOverall() const;
    
    //Fields
    int goals;      //the players goals scored
    int assists;    //the players assists
    int overall;    //the players overall stat - calculated
    bool starter;   //Does the player start or are they a sub?
    string team;    //the player's club
    string name;    //the player's name
    
};
#endif /* FIFA_hpp */
