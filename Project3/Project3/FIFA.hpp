//
//  Kit.hpp
//  Project4
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

//Create a enum for what the team wears
enum kit {Home, Away, Alternative};
enum type {IF, FG, SG, AG, AT};

//Create a struct for the _______ class:
struct cleats {
    string brand;
    string model;
    type type;
};

//Class for a single player in FIFA
class FIFA_player {
public:
    
    //default constructor
    FIFA_player();
    //constructor with all params
    FIFA_player(string n, int g, int a, string t, bool s, enum kit k, cleats c);
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
    virtual enum kit getKit() const;
    virtual struct cleats getCleats() const;
    
    //Setters
    virtual void setGoals(int in_g);
    virtual void setAssists(int in_a);
    virtual void setStart(bool in_s);
    virtual void setTeam(string in_t);
    virtual void setName(string in_n);
    virtual void setKit(kit in_k);
    virtual void setCleats(cleats in_c);
    
    // binary operator overloads
    friend ostream& operator << (ostream& output, const FIFA_player &fifa_player);
    
    friend bool operator > (const FIFA_player &lhs, const FIFA_player &rhs);
    
protected:
    
    
    
    //Fields
    int goals;      //the players goals scored
    int assists;    //the players assists
    int overall;    //the players overall stat - calculated
    bool starter;   //Does the player start or are they a sub?
    string team;    //the player's club
    string name;    //the player's name
    kit kit;        //kit or jersey of the players
    cleats cleats;   //The cleats the player is wearing
    
private:
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  calculates the overall rating for player
     */
    virtual int calcOverall() const;
};

///////////////////////////////////////////////////////////////////////////////////////////////


//Create a team class to hold the parent class
class FIFA_goalie : public FIFA_player
{
    
public:
    //constructors
    FIFA_goalie();
    //All params
    FIFA_goalie(string n, int g, int a, string t, bool s, enum kit k, struct cleats c);
    
    /**
     * Requires: nothing or input from user for setting field
     * Modifies: goals_against, saves, and overrides to calc
     *           overall
     * Effects:  gets or sets values for goals_against, saves,
     *           and overall
     */
    //Getters
    virtual int getGoalsAgainst() const;
    virtual int getSaves() const;
    
    //Setters
    virtual void setGoalsAgainst(int in_ga);
    virtual void setSaves(int in_s);
    
    // binary operator overloads
    friend ostream& operator << (ostream& output, const FIFA_goalie &fifa_goalie);
    
private:
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  calculates the overall rating for
     *           goalie from stats the goalie has
     */
    virtual int calcOverall() const override;
    
protected:
    //Fields
    int saves;          //Goalies number of saves
    int goals_against;  //Goalies number of saves
};


///////////////////////////////////////////////////////////////////////////////////////////////


//Class for a team of FIFA players -> FIFA_Team
class FIFA_team
{
    
public:
    
    //Constructors
    //default
    FIFA_team();
    //with a vector of FIFA_Player - only 5 players max.
    FIFA_team(vector<FIFA_player> team);
    //with everything!!!
    FIFA_team(vector<FIFA_player> team, int w, int l, int d, int s, string name, FIFA_goalie goalie);
    //Destructor
    ~FIFA_team();
    
    //Getters
    string getTeamName() const;     //returns team name
    int getWins() const;            //return team wins
    int getLosses() const;          //return team losses
    int getDraws() const;           //return team draws
    int getStanding() const;        //return team's standing
    int getTeamGoals();             //return team goals total
    int getTeamAssists();           //return team assists total
    vector<string> getPlayerNames() const; //returns the names of all the players on the team
    vector<FIFA_player> getTeam() const;   //returns the team - all player object instances
    FIFA_goalie getGoalie() const;
    
    //Setters for the teams
    void setTeamName(string in_n);
    void setWins(int in_w);
    void setLosses(int in_l);
    void setDraws(int in_d);
    void setStandings(int in_s);
    void setTeamGoals();
    void setTeamAssists();
    void setGoalie(FIFA_goalie g);
    
    //Set a specific players goals or assists
    vector<FIFA_player> setPlayerGoals(vector<FIFA_player> &players_in, string n, int g);
    vector<FIFA_player> setPlayerAssists(vector<FIFA_player> &players_in, string n, int a);
    
    //add or delete fifa_player from the team (vector of players)
    void addPlayer(FIFA_player player); //adds a player to the end of the team roster (vector)
    void deletePlayer(string n);        //deletes a player on the team based upon their name
    
    // overloaded operators
    friend ostream& operator << (ostream& outs, const FIFA_team &ft);
    
private:
    
    //fields
    string team_name;           //Teams name
    int wins;                   //Team Wins
    int losses;                 //Team Losses
    int draws;                  //Team Draws
    int standing;               //Team's Standing in the table
    vector<FIFA_player> players;//vector of the players on the team
    int team_goals;             //Team's total goals
    int team_assists;           //Team's total assists
    FIFA_goalie goalie;         //Team needs a goalie
};


#endif /* FIFA_hpp */






