//
//  main.cpp
//  Project4
//
//  Created by Collin on 2/28/17.
//  Copyright © 2017 Collin. All rights reserved.
//
/*
 
 MY PROGRAM -
 
 For Project 4, I implemented a kit struct for the parent FIFA_team class. This is implemented in the parent class because all of the child object instances should be wearing the same kit at the same time. So like the color struct described in class - the kit struct will describe which kit the team is wearing at any given time and can be set at any given time. The options for their kit are Home, Away, or Alternative kits. The kit is simply the jersey, shorts and combo that the team is wearing for the game.
 */

#include <iostream>
#include "Kit.cpp"

using namespace std;

int main() {
/*
     //Testing from the first class
     
     //Testing all constructors:
     //default
     cout << "Constructor Testing" << endl;
     FIFA_player collin = FIFA_player();
     cout << collin << endl;
     cout << endl;
     //just name
     FIFA_player ct1 = FIFA_player("Collin Turner");
     cout << ct1 << endl;
     cout << endl;
     //name and goals
     FIFA_player ct2 = FIFA_player("Collin Turner", 12);
     cout << ct2 << endl;
     cout << endl;
     //name and goals and assists
     FIFA_player ct3 = FIFA_player("Collin Turner", 12, 8);
     cout << ct3 << endl;
     cout << endl;
     //name and goals and assists and team name
     FIFA_player ct4 = FIFA_player("Collin Turner", 12, 8, "Liverpool FC");
     cout << ct4 << endl;
     cout << endl;
     //name and goals and assists and team name and whether player starts on the field (all fields)
     FIFA_player ct5 = FIFA_player("Collin Turner", 12, 8, "Liverpool FC", false);
     cout << ct5 << endl;
     cout << endl;
     
     cout << "**********************" << endl;
     
     //test all of the getters
     cout << "Getters Testing\n" << endl;
     cout << "getName - " << ct5.getName() << endl;
     cout << "getTeam - " << ct5.getTeam() << endl;
     cout << "getGoals - " << ct5.getGoals() << endl;
     cout << "getAssists - " << ct5.getAssists() << endl;
     string st;
     if(ct5.getStart() == 1)
     {
     string st = "Yes";
     }
     else
     {
     st = "No";
     }
     cout << "getStart - " << st << endl;
     cout << "getOverall - " << ct5.getOverall() << endl;
     cout << endl;
     
     cout << "**********************" << endl;
     
     //test all of the setters
     cout << "Setters Testing\n" << endl;
     cout << "setName - Lionel Messi" << endl;
     ct5.setName("Lionel Messi");
     cout << "setTeam - Barcelona FC" << endl;
     ct5.setTeam("Barcelona FC");
     cout << "setGoals - 24" << endl;
     ct5.setGoals(24);
     cout << "setAssists - 16" << endl;
     ct5.setAssists(16);
     cout << "setStart - true" << endl;
     ct5.setStart(true);
     cout << "\n" << ct5 << endl;
     
     //Test incorrect inputs
     ct5.setGoals(-5422);
     cout << "\n" << ct5 << endl;
     ct5.setAssists(-293);
     cout << "\n" << ct5 << endl;
     ct5.setGoals(5.5);
     cout << "\n" << ct5 << endl;
     cout << endl;
     
     cout << "********************************" << endl;
     
     //test the operator to compare overall rating of two FIFAplayers
     cout << "Compare overall rating of Ronaldo vs Messi\n" << endl;
     FIFA_player ronaldo = FIFA_player("Christiano Ronaldo", 19, 25, "Real Madrid", true);
     FIFA_player messi = FIFA_player("Lionel Messi", 21, 16, "Barcelona FC", true);
     
     cout << "Messi Overall   : " << messi.getOverall() << endl;
     cout << "Ronaldo Overall : " << ronaldo.getOverall() << endl;
     
     if(messi > ronaldo)
     {
     cout << "\nMessi is better than Ronaldo" << endl;
     }
     else
     {
     cout << "\nRonaldo is better than Messi, but that's just not possible..." << endl;
     }
*/
    
    //////////////////////////////////////////////////////////////////////////////////////////////
    ///TEST 2nd CLASS///
/*
    cout << "\nTesting the Second class: \n" << endl;
    
    //Test the default constructor
    FIFA_team chelsea = FIFA_team();
    cout << chelsea << endl;
    
    //Create vector of players to pass to other class - to create a team
    FIFA_player sturridge = FIFA_player("Daniel Sturridge", 7, 5, "Liverpool FC", false);
    FIFA_player mane = FIFA_player("Sadio Mané", 20, 13, "Liverpool FC", true);
    FIFA_player firmino = FIFA_player("Roberto Firmino", 12, 8, "Liverpool FC", true);
    FIFA_player coutinho = FIFA_player("Philippe Coutinho", 15, 10, "Liverpool FC", true);
    FIFA_player lallana = FIFA_player("Adam Lallana", 19, 16, "Liverpool FC", true);
    vector<FIFA_player> livpl = {sturridge, mane, firmino, coutinho, lallana};
    
    //test the vector of players constructor
    FIFA_team livpool = FIFA_team(livpl);
    cout << livpool << endl;
    
    //test the constructor that takes in all params
    FIFA_team liverpool = FIFA_team(livpl, 14, 7, 4, 5, "Liverpool");
    cout << liverpool << endl;
    
    //test the add player function and create player to add
    FIFA_player gerrard = FIFA_player("Steven Gerrard", 0, 0, "Liverpool FC", false);
    liverpool.addPlayer(gerrard);
    cout << endl;
    cout << liverpool << endl; //shows the name was added
    
    //test the delete player function
    liverpool.deletePlayer("Firmino");          //doesnt find name - error message
    liverpool.deletePlayer("Roberto Firmino");  //finds and deletes name
    cout << endl;
    cout << liverpool << endl; //shows the name was deleted
    
    //test to get just the players names
    vector<string> justNames = liverpool.getPlayerNames();
    for(int i=0 ; i < justNames.size(); i++)
    {
        cout << justNames[i] << endl;
    }
    
    //Test all of the setters and getters!
    liverpool.setTeamName("Liverpool FC Rules");
    liverpool.setWins(20);
    liverpool.setLosses(1);
    liverpool.setDraws(3);
    liverpool.setStandings(1);
    
    cout << "\nTeam: " << liverpool.getTeamName() << endl;
    cout << "Wins: " << liverpool.getWins() << endl;
    cout << "Losses: " << liverpool.getLosses() << endl;
    cout << "Draws: " << liverpool.getDraws() << endl;
    cout << "Standings: " << liverpool.getStanding() << endl;
    cout << "Total Goals: " << liverpool.getTeamGoals() << endl;
    cout << "Total Assists: " << liverpool.getTeamAssists() << endl;
    cout << "\n" << liverpool << endl;  //See if it all worked with overloaded operator
    
    //test the getTeam method - list all the player instances
    vector<FIFA_player> theTeam = liverpool.getTeam();
    for(int i = 0; i < theTeam.size(); i++)
    {
        cout << "\n" << theTeam[i] << endl;
    }
    
    //The goals, losses, and draws dont take anything unrealistic - (negatives/over 1000)
    //NEGATIVES
    liverpool.setWins(-20);
    liverpool.setLosses(-1);
    liverpool.setDraws(-3);
    liverpool.setStandings(-1);
    cout << "Negatives - \nWins: " << liverpool.getWins() << endl;
    cout << "Losses: " << liverpool.getLosses() << endl;
    cout << "Draws: " << liverpool.getDraws() << endl;
    cout << "Standings: " << liverpool.getStanding() << endl;
    liverpool.setWins(2000);
    liverpool.setLosses(1000);
    liverpool.setDraws(3000);
    liverpool.setStandings(1000);
    cout << "\nOver 1000 - \nWins: " << liverpool.getWins() << endl;
    cout << "Losses: " << liverpool.getLosses() << endl;
    cout << "Draws: " << liverpool.getDraws() << endl;
    cout << "Standings: " << liverpool.getStanding() << endl;
    
    //Change one of the team members goals and assists....
    cout << "\n" << theTeam[4] << endl;                                     //print player instance before changes
    cout << "\nTeams total goals: " << liverpool.getTeamGoals() << endl;      //print team goals before changes
    cout << "Teams total assists: " << liverpool.getTeamAssists() << "\n" << endl;  //print team assists before changes
    
    liverpool.setPlayerGoals(theTeam, "Gerrard", 30);           //doesnt find player
    liverpool.setPlayerGoals(theTeam, "Steven Gerrard", 30);    //finds player changes goals
    liverpool.setPlayerAssists(theTeam, "Gerrard", 20);         //doesnt find player
    liverpool.setPlayerAssists(theTeam, "Steven Gerrard", 20);  //finds player and changes assists
    
    //With changes:
    cout << "\n" << theTeam[4] << endl;                                                 //print player instance after changes
    cout << "\nTeams total goals (up by 30): " << liverpool.getTeamGoals() << endl;     //print team goals after changes
    cout << "Teams total assists (up by 20): " << liverpool.getTeamAssists() << endl;   //print team assits after changes
    
*/
    
    //////////////////////////////////////////////////////////////////////////////////////////////
    ///TEST struct - 3rd class basically   ( KIT! )   ///
    
    
    //Done with testing
    cout << "\n\nEnd of Testing ... " << endl;
    
    cout << endl;
    return 0;
}









