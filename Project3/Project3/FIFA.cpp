//
//  Kit.cpp
//  Project4
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
    kit = Home;
    overall = calcOverall();
    cleats = {"", "", FG};
}
//Constructor with all params
FIFA_player::FIFA_player(string n, int g, int a, string t, bool s, enum kit k, struct cleats c)
{
    goals = g;
    assists = a;
    name = n;
    team = t;
    starter = s;
    kit = k;
    overall = calcOverall();
    cleats = c;
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
//set the goalies kit
 kit FIFA_player::getKit() const
 {
 return kit;
 }
 //set the goalies kit
 cleats FIFA_player::getCleats() const
 {
 return cleats;
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
//set the players kit
 void FIFA_player::setKit(enum kit in_k)
 {
 kit = in_k;
 }
 //set the players cleats
 void FIFA_player::setCleats(struct cleats in_c)
 {
 cleats = in_c;
 }

//////////////////////Other Methods/////////////////////

//binary operator overloads, prints object instance fields.
ostream& operator << (ostream& output, const FIFA_player &fifa_player)
{
    //Print everything
    output << "Player's Name: " << fifa_player.name
    << "\nTeam: " << fifa_player.team
    << "\nDoes Player Start? " << boolalpha << fifa_player.starter
    << "\nGoals Scored: " << fifa_player.goals
    << "\nAssists: " << fifa_player.assists
    << "\nOverall FIFA Rating: " << fifa_player.overall
    << "\nKit: " << fifa_player.kit
    << "\nCleats: " << &fifa_player.cleats;
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


//////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////
// GOALIE Class construction //
///////////////////////////////

//constructor - default
FIFA_goalie::FIFA_goalie() : FIFA_player()
{
    goals_against = 0;
    saves = 0;
    overall = calcOverall();
}
//Constructor with all params
FIFA_goalie::FIFA_goalie(string n, int g, int a, string t, bool s, enum kit k, struct cleats c) : FIFA_player(n, 0, 0, t, s, k, c)
{
    goals_against = a;
    saves = g;
    overall = calcOverall();
}

/////////////Additional Getters////////////////////

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

//////////////Additional Setters///////////////////

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

//////////////////////Other Methods/////////////////////

//binary operator overloads, prints object instance fields.
 ostream& operator << (ostream& output, const FIFA_goalie &fifa_goalie)
 {
 //Print everything
 output << "Player's Name: " << fifa_goalie.name
 << "\nTeam: " << fifa_goalie.team
 << "\nDoes Player Start? " << boolalpha << fifa_goalie.starter
 << "\nGoals Scored Against: " << fifa_goalie.goals_against
 << "\nSaves: " << fifa_goalie.saves
 << "\nOverall FIFA Rating: " << fifa_goalie.overall
 << "\nKit: " << fifa_goalie.kit
 << "\nCleats: " << fifa_goalie.cleats.brand << " " << fifa_goalie.cleats.model << " " << fifa_goalie.cleats.type << endl;
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
    
    //Saves:
    
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
    
    //Goals Against:
    
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

/////////////////////////////
// TEAM Class construction //
/////////////////////////////

//default contrusctor
FIFA_team::FIFA_team()
{
    team_name = "Unknown";
    wins = 0;
    losses = 0;
    draws = 0;
    standing = 20;
    //Put 5 random players on the team
    for (int i = 0; i < 5; i++)
    {
        players.push_back(FIFA_player());
    }
    goalie = FIFA_goalie();
    players.push_back(goalie);
    //call the methods to set the other fields
    //based upon player vector (objects of subclass)
    setTeamGoals();
    setTeamAssists();
    
}
//constructor with just vector
FIFA_team::FIFA_team(vector<FIFA_player> team)
{
    team_name = "Unknown";
    wins = 0;
    losses = 0;
    draws = 0;
    standing = 20;
    players = team;
    goalie = FIFA_goalie();
    players.push_back(goalie);
    //call the methods to set the other fields
    setTeamGoals();
    setTeamAssists();
}
//constructor passing everything!
FIFA_team::FIFA_team(vector<FIFA_player> team, int w, int l, int d, int s, string name, FIFA_goalie goal)
{
    team_name = name;
    wins = w;
    losses = l;
    draws = d;
    standing = s;
    players = team;
    goalie = goal;
    players.push_back(goalie);
    //call the methods to set the other fields
    setTeamGoals();
    setTeamAssists();
}
//deconstructor
FIFA_team::~FIFA_team()
{
}
/////////////////////////
//Getters for the teams//
/////////////////////////

//Returns the teams name
string FIFA_team::getTeamName() const
{
    return team_name;
}
//returns the number of team wins
int FIFA_team::getWins() const
{
    return wins;
}
//returns the number of team losses
int FIFA_team::getLosses() const
{
    return losses;
}
//returns number of ties
int FIFA_team::getDraws() const
{
    return draws;
}
//gets the teams standing
int FIFA_team::getStanding() const
{
    return standing;
}
//returns the teams total goals
int FIFA_team::getTeamGoals()
{
    setTeamGoals();
    return team_goals;
}
//returns the teams total assists
int FIFA_team::getTeamAssists()
{
    setTeamAssists();
    return team_assists;
}
//Gets all of the player names in a string vector
vector<string> FIFA_team::getPlayerNames() const
{
    vector<string> player_names;
    
    for (int i=0; i<players.size(); i++)
    {
        player_names.push_back(players[i].getName());
    }
    return player_names;
}
//Gets all of the player names in a string vector
vector<FIFA_player> FIFA_team::getTeam() const
{
    return players;
}
//returns the goalie object
FIFA_goalie FIFA_team::getGoalie() const
{
    return goalie;
}

/////////////////////////
//Setters for the teams//
/////////////////////////

//sets teams name
void FIFA_team::setTeamName(string in_n)
{
    team_name = in_n;
}
//sets the teams total wins
void FIFA_team::setWins(int in_w)
{
    if(in_w < 0 || in_w >= 1000)
        wins = 0;
    else
        wins = in_w;
}
//sets the teams total losses
void FIFA_team::setLosses(int in_l)
{
    if(in_l < 0 || in_l >= 1000)
        losses = 0;
    else
        losses = in_l;
}
//sets the teams total ties
void FIFA_team::setDraws(int in_d)
{
    if(in_d < 0 || in_d >= 1000)
        draws = 0;
    else
        draws = in_d;
}
//sets the teams standings
void FIFA_team::setStandings(int in_s)
{
    if(in_s < 0 || in_s >= 1000)
        standing = 20;
    else
        standing = in_s;
}
//sets the teams goals based upon players on the teams goals added up
void FIFA_team::setTeamGoals()
{
    team_goals = 0;
    
    for(int i = 0; i < players.size();i++)
    {
        team_goals += players[i].getGoals();
    }
}
//sets the teams assists based upon players on the teams assists added up
void FIFA_team::setTeamAssists()
{
    team_assists = 0;
    
    for(int i = 0; i < players.size();i++)
    {
        team_assists += players[i].getAssists();
    }
}
//Set - change a specific players goals stat from the team.
vector<FIFA_player> FIFA_team::setPlayerGoals(vector<FIFA_player> &players_in, string n, int g)
{
    bool found = false;
    int count = 0;
    while(!found && (count < players_in.size()))
    {
        if(players_in[count].getName() == n)
        {
            found = true;
            players_in[count].setGoals(g);
            players[count] = players_in[count];
            cout << "Success " << n << " goals were updated" << endl;
        }
        count++;
    }
    if(!found)
    {
        cout << "Error: " << n << " was not found on the team roster" << endl;
    }
    setTeamGoals(); //update teamGoals
    return players;
}
// Set - change a players assists stat from the team
vector<FIFA_player> FIFA_team::setPlayerAssists(vector<FIFA_player> &players_in, string n, int a)
{
    bool found = false;
    int count = 0;
    while(!found && (count < players_in.size()))
    {
        if(players_in[count].getName() == n)
        {
            found = true;
            players_in[count].setAssists(a);
            players[count] = players_in[count];
            cout << "Success " << n << " assists were updated" << endl;
        }
        count++;
    }
    if(!found)
    {
        cout << "Error: " << n << " was not found on the team roster" << endl;
    }
    setTeamAssists();  //update teamAssists
    return players;
}
void FIFA_team::setGoalie(FIFA_goalie g)
{
    goalie = g;
}

///         OTHER  METHODS          ///

//adds a player to the end of the team roster (vector)
void FIFA_team::addPlayer(FIFA_player player)
{
    players.push_back(player);
    cout << "Success " << player.getName() << " was added to the roster" << endl;
    setTeamGoals();
    setTeamAssists();
}
//Deletes a player from the roster based upon name - if found
void FIFA_team::deletePlayer(string n)
{
    bool found = false;
    int count = 0;
    while(!found && (count < players.size()))
    {
        if(players[count].getName() == n)
        {
            found = true;
            players.erase(players.begin()+count);
            setTeamGoals();
            setTeamAssists();
            cout << "Success " << n << " was deleted from team roster" << endl;
        }
        count++;
    }
    if(!found)
    {
        cout << "Error: " << n << " was not found on the team roster" << endl;
    }
}

//binary operator overloads, prints object instance fields.
ostream& operator << (ostream& outs, const FIFA_team &ft)
{
    //Print everything about the team and print players
    outs << "Team's Name: " << ft.team_name
    << "\nRecord: " << ft.wins << "-" << ft.draws << "-" << ft.losses
    << "\nOverall Standing: " << ft.standing
    << "\nTeam's Total Goals: " << ft.team_goals
    << "\nTeam's Total Assists: " << ft.team_assists
    << "\nPlayers -- \n";
    
    for (int i = 0; i < ft.players.size(); i++)
    {
        outs << i+1 << " " << ft.players[i].getName() << endl;
    }
    return outs;
}






