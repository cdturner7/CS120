//
//  FIFA.cpp
//  Project2
//
//  Created by Collin on 2/8/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#include "FIFA.hpp"
#include <iostream>

/////////////Constructors////////////


//default contrusctor
FIFA_player::FIFA_player()
{
    goals = 0;
    assists = 0;
    name = "Unknown";
    team = "Unknown";
    starter = false;
    overall = calcOverall();
}

//contrusctor with name
FIFA_player::FIFA_player(string n)
{
    goals = 0;
    assists = 0;
    name = n;
    team = "Unknown";
    starter = false;
    overall = calcOverall();
}

//contrusctor with name & goals
FIFA_player::FIFA_player(string n, int g)
{
    goals = g;
    assists = 0;
    name = n;
    team = "Unknown";
    starter = false;
    overall = calcOverall();
}

//contrusctor with name & goals & assists
FIFA_player::FIFA_player(string n, int g, int a)
{
    goals = g;
    assists = a;
    name = n;
    team = "Unknown";
    starter = false;
    overall = calcOverall();
}

//contrusctor with name & goals & assists & team
FIFA_player::FIFA_player(string n, int g, int a, string t)
{
    goals = g;
    assists = a;
    name = n;
    team = t;
    starter = false;
    overall = calcOverall();
}

//contrusctor with name & goals & assists & team & starting position
FIFA_player::FIFA_player(string n, int g, int a, string t, bool s)
{
    goals = g;
    assists = a;
    name = n;
    team = t;
    starter = s;
    overall = calcOverall();
}

//deconstructor
FIFA_player::~FIFA_player()
{
}


/////////////Getters////////////////////


//get the players goals
int FIFA_player::getGoals() const
{
    return goals;
}

//get tthe players assists
int FIFA_player::getAssists() const
{
    return assists;
}

//get the players overall stat
int FIFA_player::getOverall() const
{
    return overall;
}

//get whether the player starts or not
bool FIFA_player::getStart() const
{
    return starter;
}

//get the players team
string FIFA_player::getTeam() const
{
    return team;
}

//get the players name
string FIFA_player::getName() const
{
    return name;
}


//////////////Setters///////////////////


//set the players goals stat
//and calculate the calcOverall
void FIFA_player::setGoals(int in_g)
{
    goals = in_g;
    overall = calcOverall();
}

//set the players assists stat
//and calculate the calcOverall
void FIFA_player::setAssists(int in_a)
{
    assists = in_a;
    overall = calcOverall();
}

//set the players starting role - true or false
//and calculate the calcOverall
void FIFA_player::setStart(bool in_s)
{
    starter = in_s;
    overall = calcOverall();
}

//set the players team
void FIFA_player::setTeam(string in_t)
{
    team = in_t;
}

//set the players name
void FIFA_player::setName(string in_n)
{
    name = in_n;
}


//////////////////////Other Methods/////////////////////


//binary operator overloads, prints object instance fields.
ostream& operator << (ostream& output, const FIFA_player &fifa_player)
{
    //if player starts? string yes or no
    string st;
    if(fifa_player.starter == 1)
    {
        st = "Yes";;
    }
    else
    {
        st = "No";
    }
    //Print everything
    output << "Player's Name: " << fifa_player.name
    << "\nTeam: " << fifa_player.team
    << "\nDoes Player Start? " << st
    << "\nGoals Scored: " << fifa_player.goals
    << "\nAssists: " << fifa_player.assists
    << "\nOverall FIFA Rating: " << fifa_player.overall;
    return output;
}

//binary operator - Compare the overall ratings of two player objects
bool operator > (const FIFA_player &lhs, const FIFA_player &rhs)
{
    return lhs.getOverall() > rhs.getOverall();
}

//calculate the overall rating of player
int FIFA_player::calcOverall() const
{
    //no matter what player rating isnt below a 65.
    int rating = 65;
    
    //if the player starts then they get 10 points on their rating
    if (starter)
    {
        rating += 10;
    }
    
    //Goals:
    
    //Player has between 0-5 goals
    if (getGoals() > 0 && getGoals() <= 5)
    {
        rating += 5;
    }
    //Player has between 6-10 goals
    else if(getGoals() > 5 && getGoals() <= 10)
    {
        rating += 7;
    }
    //Player has between 11-15 goals
    else if(getGoals() > 10 && getGoals() <= 15)
    {
        rating += 9;
    }
    //Player has between 16-20 goals
    else if(getGoals() > 15 && getGoals() <= 20)
    {
        rating += 11;
    }
    //Player has more than 20 goals
    else if(getGoals() > 20)
    {
        rating += 14;
    }
    //Player scored negative goals
    else
    {
        rating += 0;
    }
    
    
    //Assists:
    
    //Player has between 0-5 assists
    if (getAssists() > 0 && getAssists() <= 5)
    {
        rating += 2;
    }
    //Player has between 6-10 assists
    else if(getAssists() > 5 && getAssists() <= 10)
    {
        rating += 3;
    }
    //Player has between 11-15 assists
    else if(getAssists() > 10 && getAssists() <= 15)
    {
        rating += 4;
    }
    //Player has between 16-20 assists
    else if(getAssists() > 15 && getAssists() <= 20)
    {
        rating += 5;
    }
    //Player has more than 20 assists
    else if(getAssists() > 20)
    {
        rating += 6;
    }
    //Player has negative assists
    else
    {
        rating += 0;
    }

    //return rating to get the players overall stat
    return rating;
}










