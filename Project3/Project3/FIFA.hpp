//
//  FIFA.hpp
//  Project3
//
//  Created by Collin on 2/22/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#ifndef FIFA_hpp
#define FIFA_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

//Class for a single player in FIFA
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


///////////////////////////////////////////////////////////////////////////////////////////////


//Class for a team of FIFA players -> FIFA_Team
class FIFA_team {
public:
    
    //Constructors
    //default
    FIFA_team();
    //with a vector of FIFA_Player - only 5 players max.
    FIFA_team(vector<FIFA_player> team);
    //with everything!!!
    FIFA_team(vector<FIFA_player> team, int w, int l, int d, int s, string name);
    
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
    
    //Setters for the teams
    void setTeamName(string in_n);
    void setWins(int in_w);
    void setLosses(int in_l);
    void setDraws(int in_d);
    void setStandings(int in_s);
    void setTeamGoals();
    void setTeamAssists();
    
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
    string record;              //Team's Record in a string
    int standing;               //Team's Standing in the table
    vector<FIFA_player> players;//vector of the players on the team
    int team_goals;             //Team's total goals
    int team_assists;           //Team's total assists
};

#endif /* FIFA_hpp */











