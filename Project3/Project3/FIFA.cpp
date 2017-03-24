//
//  FIFA.cpp
//  Project5
//
//  Created by Collin on 2/28/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#include "FIFA.hpp"
#include <iostream>
#include <sstream>

///////////////////////////////
// PLAYER Class construction //
///////////////////////////////

/////////////Constructors////////////

//default contrusctor
FIFA_player::FIFA_player()
{
    goals = 0;
    assists = 0;
    name = "Unknown";
    team = "Unknown";
    starter = false;
}
//Constructor with all params
FIFA_player::FIFA_player(string n, int g, int a, string t, bool s)
{
    name = n;
    goals = g;
    assists = a;
    team = t;
    starter = s;
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

//get the players position
position FIFA_player::getPosition() const
{
    return pos;
}

//////////////Setters///////////////////

//set the players goals stat
//and calculate the calcOverall
void FIFA_player::setGoals(int in_g)
{
    if(in_g < 0 || in_g > 1000)
    {
        goals = 0;
    }
    else
    {
        goals = in_g;
    }

    overall = calcOverall();
}

//set the players assists stat
//and calculate the calcOverall
void FIFA_player::setAssists(int in_a)
{
    if (in_a < 0 || in_a > 1000)
    {
        assists = 0;
    }
    else
    {
        assists = in_a;
    }
    
    overall = calcOverall();
}

//set the players starting role - true or false
//and calculate the calcOverall
void FIFA_player::setStart(bool in_s)
{
    if((in_s != true) && (in_s != false))
    {
        starter = false;
    }
    else
    {
        starter = in_s;
    }
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

//////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////
// GOALIE Class construction //
///////////////////////////////

//constructor - default
FIFA_goalie::FIFA_goalie() : FIFA_player()
{
    goals_against = 0;
    saves = 0;
    pos = Goalie;
    overall = calcOverall();
}
//Constructor with all params
FIFA_goalie::FIFA_goalie(string n, int g, int a, string t, bool s, int ga, int sv) : FIFA_player(n, g, a, t, s)
{
    goals_against = ga;
    saves = sv;
    pos = Goalie;
    overall = calcOverall();
}

/////////////GOALIE Getters////////////////////

//get the goalies goals against
int FIFA_goalie::getGoalsAgainst() const
{
    return goals_against;
}

//get the goalies saves
int FIFA_goalie::getSaves() const
{
    return saves;
}

//////////////GOALIE Setters///////////////////

//set the players goals stat
//and calculate the calcOverall
void FIFA_goalie::setGoalsAgainst(int in_ga)
{
    if(in_ga < 0 || in_ga > 1000)
    {
        goals_against = 0;
    }
    else
    {
        goals_against = in_ga;
    }
    overall = calcOverall();
}

//set the players assists stat
//and calculate the calcOverall
void FIFA_goalie::setSaves(int in_s)
{
    if(in_s < 0 || in_s > 1000)
    {
        saves = 0;
    }
    else
    {
        saves = in_s;
    }
    overall = calcOverall();
}

//binary operator overloads, prints object instance fields.
ostream& operator << (ostream& output, const FIFA_goalie &fifa_goalie)
{
    //Print everything out to console
    output << "Player's Name: " << fifa_goalie.name
    << "\nTeam: " << fifa_goalie.team
    << "\nPosition: " << fifa_goalie.pos
    << "\nPlayer Starts? " << boolalpha << fifa_goalie.starter
    << "\nGoals Conceeded(pg): " << fifa_goalie.goals_against
    << "\nSaves(pg): " << fifa_goalie.saves
    << "\nOverall FIFA Rating: " << fifa_goalie.overall;
    
    return output;
}

//calculate the overall rating of player
int FIFA_goalie::calcOverall() const
{
    //no matter what player rating isnt below a 65.
    int rating = 65;
    
    //if the player starts then they get 10 points on their rating
    if (starter)
    {
        rating += 10;
    }
    
    //Saves per game:
    
    //Player has between 0-5 goals
    if (getSaves() > 0 && getSaves() <= 5)
    {
        rating += 2;
    }
    //Player has between 6-10 goals
    else if(getSaves() > 5 && getSaves() <= 10)
    {
        rating += 3;
    }
    //Player has between 11-15 goals
    else if(getSaves() > 10 && getSaves() <= 15)
    {
        rating += 4;
    }
    //Player has between 16-20 goals
    else if(getSaves() > 15 && getSaves() <= 20)
    {
        rating += 5;
    }
    //Player has more than 20 goals
    else if(getSaves() > 20)
    {
        rating += 6;
    }
    //Player scored negative goals
    else
    {
        rating += 0;
    }
    
    //Goals Against per game:
    
    //Player has between 0-5 assists
    if (getGoalsAgainst() > 0 && getGoalsAgainst() <= 5)
    {
        rating += 14;
    }
    //Player has between 6-10 assists
    else if(getGoalsAgainst() > 5 && getGoalsAgainst() <= 10)
    {
        rating += 11;
    }
    //Player has between 11-15 assists
    else if(getGoalsAgainst() > 10 && getGoalsAgainst() <= 15)
    {
        rating += 9;
    }
    //Player has between 16-20 assists
    else if(getGoalsAgainst() > 15 && getGoalsAgainst() <= 20)
    {
        rating += 7;
    }
    //Player has more than 20 assists
    else if(getGoalsAgainst() > 20)
    {
        rating += 5;
    }
    //Player has negative assists
    else
    {
        rating += 0;
    }
    //return rating to get the players overall stat
    return rating;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////
// Striker Class construction //
////////////////////////////////

//constructor - default
FIFA_striker::FIFA_striker() : FIFA_player()
{
    shots = 0;
    shotsOnGoal = 0;
    pos = Striker;
    overall = calcOverall();
}
//Constructor with all params
FIFA_striker::FIFA_striker(string n, int g, int a, string t, bool s, int sh, int sog) : FIFA_player(n, g, a, t, s)
{
    shots = sh;
    shotsOnGoal = sog;
    pos = Striker;
    overall = calcOverall();
}

/////////////Striker Getters////////////////////

//get the striker's shots per game
int FIFA_striker::getShots() const
{
    return shots;
}

//get the strikers shots on goal per game
int FIFA_striker::getShotsOnGoal() const
{
    return shotsOnGoal;
}

//get the strikers shots on goal per game
float FIFA_striker::getShotPercentage() const
{
    return shotPercentage;
}

//////////////GOALIE Setters///////////////////

//set the players goals stat
//and calculate the calcOverall
void FIFA_striker::setShots(int in_s)
{
    //cant have negative shots, and no way over 50 .. lets be real
    if(in_s < 0 || in_s > 50)
    {
        shots = 0;
    }
    //cant take less shots than shots on goal.. doesnt make sense
    else if(in_s < getShotsOnGoal())
    {
        shots = shotsOnGoal*2;
    }
    else
    {
        shots = in_s;
    }
    //calculate necessary fields
    shotPercentage = calcShotPercent();
    overall = calcOverall();
}

//set the players assists stat
//and calculate the calcOverall
void FIFA_striker::setShotsOnGoal(int in_sog)
{
    //cant have negative shots on goal, and cant take 50 shots in a game average..
    if(in_sog < 0 || in_sog > 50)
    {
        shotsOnGoal = 0;
    }
    //cant take more shots on goal than shots taken.
    else if(in_sog > shots)
    {
        shotsOnGoal = 0;
    }
    else
    {
        shotsOnGoal = in_sog;
    }
    //calculate necessary fields
    shotPercentage = calcShotPercent();
    overall = calcOverall();
}

//binary operator overloads, prints object instance fields.
ostream& operator << (ostream& output, const FIFA_striker &fifa_striker)
{
    //Print everything out to console
    output << "Player's Name: " << fifa_striker.name
    << "\nTeam: " << fifa_striker.team
    << "\nPosition: " << fifa_striker.pos
    << "\nPlayer Starts? " << boolalpha << fifa_striker.starter
    << "\nShots(pg): " << fifa_striker.shots
    << "\nShots On Goal(pg): " << fifa_striker.shotsOnGoal
    << "\nOverall FIFA Rating: " << fifa_striker.overall;
    
    return output;
}

//calculate the overall rating of player
int FIFA_striker::calcOverall() const
{
    //no matter what player rating isnt below a 65.
    int rating = 65;
    
    //if the player starts then they get 7 points on their rating
    if (starter)
    {
        rating += 7;
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
        rating += 6;
    }
    //Player has between 11-15 goals
    else if(getGoals() > 10 && getGoals() <= 15)
    {
        rating += 8;
    }
    //Player has between 16-20 goals
    else if(getGoals() > 15 && getGoals() <= 20)
    {
        rating += 9;
    }
    //Player has more than 20 goals
    else if(getGoals() > 20)
    {
        rating += 10;
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
    
    //Shot Percentage - average per game
    
    //Player has between 10-25%
    if (getShotPercentage() > 10.0 && getShotPercentage() <= 25.0)
    {
        rating += 2;
    }
    //Player has between 25-45%
    else if(getShotPercentage() > 25.0 && getShotPercentage() <= 45.0)
    {
        rating += 3;
    }
    //Player has between 45-65%
    else if(getShotPercentage() > 45.0 && getShotPercentage() <= 65.0)
    {
        rating += 4;
    }
    //Player has between 65-80%
    else if(getShotPercentage() > 65.0 && getShotPercentage() <= 80.0)
    {
        rating += 5;
    }
    //Player has more than 80%
    else if(getShotPercentage() > 80.0)
    {
        rating += 6;
    }
    //Player has less than 10% accuracy
    else
    {
        rating += 0;
    }
    
    //return rating to get the players overall stat
    return rating;
}

//calculates the strikers shot percentage
float FIFA_striker::calcShotPercent() const
{
    return (float(getShotsOnGoal())/float(getShots()))*100;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////
// Midfielder Class construction //
///////////////////////////////////

//constructor - default
FIFA_midfielder::FIFA_midfielder() : FIFA_player()
{
    playCreations = 0;
    throughBalls = 0;
    pos = Midfielder;
    overall = calcOverall();
}
//Constructor with all params
FIFA_midfielder::FIFA_midfielder(string n, int g, int a, string t, bool s, int pc, int tb) : FIFA_player(n, g, a, t, s)
{
    playCreations = pc;
    throughBalls = tb;
    pos = Midfielder;
    overall = calcOverall();
}

/////////////Midfielder Getters////////////////////

//get the midfielder's plays created per game stat
int FIFA_midfielder::getPlayCreations() const
{
    return playCreations;
}

//get the midfielder's through balls on average per game stat
int FIFA_midfielder::getThroughBalls() const
{
    return throughBalls;
}

//////////////GOALIE Setters///////////////////

//set the players playsCreated stat
//and calculate the calcOverall
void FIFA_midfielder::setPlayCreations(int in_pc)
{
    //cant have negative play creations, and not over 50, but close
    if(in_pc < 0 || in_pc > 50)
    {
        playCreations = 0;
    }
    else
    {
        playCreations = in_pc;
    }
    //calculate overall with new stats
    overall = calcOverall();
}

//set the players through balls stat
//and calculate the calcOverall
void FIFA_midfielder::setThroughBalls(int in_tb)
{
    //cant have negative through balls made, and maybe over 50.. not likely
    if(in_tb < 0 || in_tb > 50)
    {
        throughBalls = 0;
    }
    else
    {
        throughBalls = in_tb;
    }
    //calculate overall with new tb stat
    overall = calcOverall();
}

//binary operator overloads, prints object instance fields.
ostream& operator << (ostream& output, const FIFA_midfielder &fifa_midfielder)
{
    //Print everything out to console
    output << "Player's Name: " << fifa_midfielder.name
    << "\nTeam: " << fifa_midfielder.team
    << "\nPosition: " << fifa_midfielder.pos
    << "\nPlayer Starts? " << boolalpha << fifa_midfielder.starter
    << "\nPlays Created(pg): " << fifa_midfielder.playCreations
    << "\nThrough Balls(pg): " << fifa_midfielder.throughBalls
    << "\nOverall FIFA Rating: " << fifa_midfielder.overall;
    
    return output;
}

//calculate the overall rating of player
int FIFA_midfielder::calcOverall() const
{
    //no matter what player rating isnt below a 65.
    int rating = 65;
    
    //if the player starts then they get 7 points on their rating
    if (starter)
    {
        rating += 7;
    }
    
    //Goals:
    
    //Player has between 0-5 goals
    if (getGoals() > 0 && getGoals() <= 5)
    {
        rating += 3;
    }
    //Player has between 6-10 goals
    else if(getGoals() > 5 && getGoals() <= 10)
    {
        rating += 4;
    }
    //Player has between 11-15 goals
    else if(getGoals() > 10 && getGoals() <= 15)
    {
        rating += 5;
    }
    //Player has between 16-20 goals
    else if(getGoals() > 15 && getGoals() <= 20)
    {
        rating += 6;
    }
    //Player has more than 20 goals
    else if(getGoals() > 20)
    {
        rating += 7;
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
        rating += 1;
    }
    //Player has between 6-10 assists
    else if(getAssists() > 5 && getAssists() <= 10)
    {
        rating += 2;
    }
    //Player has between 11-15 assists
    else if(getAssists() > 10 && getAssists() <= 15)
    {
        rating += 3;
    }
    //Player has between 16-20 assists
    else if(getAssists() > 15 && getAssists() <= 20)
    {
        rating += 4;
    }
    //Player has more than 20 assists
    else if(getAssists() > 20)
    {
        rating += 5;
    }
    //Player has negative assists
    else
    {
        rating += 0;
    }
    
    //play creations per game:
    
    //Player has between 0-5 plays created
    if (getPlayCreations() > 0 && getPlayCreations() <= 5)
    {
        rating += 1;
    }
    //Player has between 6-10 plays created
    else if(getPlayCreations() > 5 && getPlayCreations() <= 10)
    {
        rating += 2;
    }
    //Player has between 11-15 plays created
    else if(getPlayCreations() > 10 && getPlayCreations() <= 15)
    {
        rating += 3;
    }
    //Player has between 16-20 plays created
    else if(getPlayCreations() > 15 && getPlayCreations() <= 20)
    {
        rating += 4;
    }
    //Player has more than 20 plays created
    else if(getPlayCreations() > 20)
    {
        rating += 5;
    }
    //Player has negative assists
    else
    {
        rating += 0;
    }
    
    //Through Balls per game:
    
    //Player has between 0-5 through balls
    if (getThroughBalls() > 0 && getThroughBalls() <= 5)
    {
        rating += 1;
    }
    //Player has between 6-10 through balls
    else if(getThroughBalls() > 5 && getThroughBalls() <= 10)
    {
        rating += 2;
    }
    //Player has between 11-15 through balls
    else if(getThroughBalls() > 10 && getThroughBalls() <= 15)
    {
        rating += 3;
    }
    //Player has between 16-20 through balls
    else if(getThroughBalls() > 15 && getThroughBalls() <= 20)
    {
        rating += 4;
    }
    //Player has more than 20 through balls
    else if(getThroughBalls() > 20)
    {
        rating += 5;
    }
    //Player has negative through balls
    else
    {
        rating += 0;
    }

    //return rating to get the players overall stat
    return rating;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////
// Defenseman Class construction //
///////////////////////////////////





