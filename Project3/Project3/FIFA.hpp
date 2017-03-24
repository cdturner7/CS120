//
//  FIFA.hpp
//  Project5
//
//  Created by Collin on 2/28/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#ifndef FIFA_hpp
#define FIFA_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

enum position {Goalie = 0, Striker, Midfielder, Defenseman};

///////////////////////////////
// PLAYER Class construction //
///////////////////////////////

//Abstract class for a soccer player in FIFA
class FIFA_player {

public:

    //default constructor
    FIFA_player();
    //constructor with all params
    FIFA_player(string n, int g, int a, string t, bool s);
    //destructor//
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
    virtual int getGoals() const;
    virtual int getAssists() const;
    virtual int getOverall() const;
    virtual bool getStart() const;
    virtual string getTeam() const;
    virtual string getName() const;
    virtual position getPosition() const;
    
    //Setters
    virtual void setGoals(int in_g);
    virtual void setAssists(int in_a);
    virtual void setStart(bool in_s);
    virtual void setTeam(string in_t);
    virtual void setName(string in_n);

protected:
    
    //Fields
    int goals;      //the players goals scored
    int assists;    //the players assists
    int overall;    //the players overall stat - calculated
    bool starter;   //Does the player start or are they a sub?
    string team;    //the player's club
    string name;    //the player's name
    position pos;   //the players position
    
private:
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  calculates the overall rating for player
     */
    virtual int calcOverall() const = 0;    //Pure Virtual Function makes abstract class
};


///////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////
// STRIKER Class construction //
////////////////////////////////

//Create a team class to hold the parent class
class FIFA_striker : public FIFA_player
{
    
public:
    
    //constructors
    FIFA_striker();
    //All params
    FIFA_striker(string n, int g, int a, string t, bool s, int sh, int sog);
    
    /**
     * Requires: nothing or input from user for setting field
     * Modifies: goals_against, saves, and overrides to calc
     *           overall
     * Effects:  gets or sets values for goals_against, saves,
     *           and overall
     */
    //Getters
    int getShots() const;
    int getShotsOnGoal() const;
    float getShotPercentage() const;
    
    //Setters
    void setShots(int in_s);
    void setShotsOnGoal(int in_sog);
    
    //binary operator overloads
    friend ostream& operator << (ostream& output, const FIFA_striker &fifa_striker);
   
protected:
    
    //Fields
    int shots;             //number of shots player has taken
    int shotsOnGoal;       //number of shots on frame
    float shotPercentage;  //holds percent calculated from shots to shots on goal
  
private:
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  calculates the overall rating for
     *           striker - based upon goals, assists, and shot percentage
     */
    virtual int calcOverall() const override;
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  Calculates the player's shot percentage
     */
    float calcShotPercent() const;
};


///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////
// MIDFIELDER Class construction //
///////////////////////////////////


//Create a team class to hold the parent class
class FIFA_midfielder : public FIFA_player
{
    
public:
    
    //constructors
    FIFA_midfielder();
    //All params
    FIFA_midfielder(string n, int g, int a, string t, bool s, int pc, int tb);
    
    /**
     * Requires: nothing or input from user for setting field
     * Modifies: goals_against, saves, and overrides to calc
     *           overall
     * Effects:  gets or sets values for goals_against, saves,
     *           and overall
     */
    //Getters
    int getPlayCreations() const;
    int getThroughBalls() const;
    
    //Setters
    void setPlayCreations(int in_pc);
    void setThroughBalls(int in_tb);
    
    //binary operator overloads
    friend ostream& operator << (ostream& output, const FIFA_midfielder &fifa_midfielder);
    
protected:
    
    //Fields
    int playCreations;          //Number of created plays player makes pg
    int throughBalls;           //Number of Through balls player makes pg

private:
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  calculates the overall rating for
     *           goalie from stats the goalie has
     */
    virtual int calcOverall() const override;
};


///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////
// DEFENSEMAN Class construction //
///////////////////////////////////

//Create a team class to hold the parent class
class FIFA_defenseman : public FIFA_player
{
    
public:
    
    //constructors
    FIFA_defenseman();
    //All params
    FIFA_defenseman(string n, int g, int a, string t, bool s, int tk, int i);
    
    /**
     * Requires: nothing or input from user for setting field
     * Modifies: goals_against, saves, and overrides to calc
     *           overall
     * Effects:  gets or sets values for goals_against, saves,
     *           and overall
     */
    //Getters
    virtual int getTackles() const;
    virtual int getInterceptions() const;
    
    //Setters
    virtual void setTackles(int in_tk);
    virtual void setInterceptions(int in_i);
    
    //binary operator overloads
    friend ostream& operator << (ostream& output, const FIFA_defenseman &fifa_defenseman);
    
protected:
    
    //Fields
    int tackles;        //average tackles pg
    int interceptions;  //average interceptions pg

private:
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  calculates the overall rating for
     *           goalie from stats the goalie has
     */
    virtual int calcOverall() const override;
};


///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////
// GOALIE Class construction //
///////////////////////////////

//Create a team class to hold the parent class
class FIFA_goalie : public FIFA_player
{
    
public:
    
    //constructors
    FIFA_goalie();
    //All params
    FIFA_goalie(string n, int g, int a, string t, bool s, int ga, int sv);
    
    /**
     * Requires: nothing or input from user for setting field
     * Modifies: goals_against, saves, and overrides to calc
     *           overall
     * Effects:  gets or sets values for goals_against, saves,
     *           and overall
     */
    //Getters
    int getGoalsAgainst() const;
    int getSaves() const;
    
    //Setters
    void setGoalsAgainst(int in_ga);
    void setSaves(int in_s);
    
    //binary operator overloads
    friend ostream& operator << (ostream& output, const FIFA_goalie &fifa_goalie);
    
protected:
    
    //Fields
    int saves;          //Goalies number of saves
    int goals_against;  //Goalies number of saves
    
private:
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  calculates the overall rating for
     *           goalie from stats the goalie has
     */
    virtual int calcOverall() const override;
};



#endif /* FIFA_hpp */






