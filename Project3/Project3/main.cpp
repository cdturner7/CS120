//
//  main.cpp
//  Project3
//
//  Created by Collin on 2/22/17.
//  Copyright © 2017 Collin. All rights reserved.
//
/*
 
 MY PROGRAM -
 
 This is a program to test the FIFA class. The class is designed
 to hold information about a FIFA soccer player and then it
 calculates the overall value of the player on a scale of 100.
 It calculates this based on the goals, assists, and whether the
 player starts or is a sub.
 
 Overloaded operaors were implemented to compare players
 overall ratings.
 
 * These are also all stats in a given year. So typically a
 player doesnt score more than 20 goals or assists in a season
 but the stats are made to support this.
 No player can actually hit a perfect score because no player
 is perfect on the pitch. So the min is 65 and the max score
 is set at 95, even though its on a scale of 0-100.
 
 Setters will only allow the expected input to be submitted as
 parameter, but as for the setAssists and setGoals you can pass
 a double but it will be truncated. If you submit anything
 negative then the player doesnt recieve any positive points
 for goals or assists in their overall rating. (tested below)
 
 */
/*
 
 The Second part of this program is the testing of the second class
 for Project #3. I created a FIFA_team, which has FIFA_players. It 
 has players on the team and are passed to the constructor or just 
 constructed using a vector of FIFA_players.
 
 There are many getters and setters with an add and delete function 
 to the team roster. Theres an overloading operator to display
 all the team stats and players. A function to get the team returned
 into a vecotr that has just the players names in it - the roster
 There are also fields that are in the FIFA_team class that are initiated
 by calculating the sum of fields in the instances in the vector - the 
 total teams goals and the total team assists.
 
 There should be sufficient testing to show that all of the methods 
 and classes work and function as they are suppose to.
 
 testing names livpl,livpool,liverpool - all referencing same team 
 just to make it easier.. so each vector and team object are essentially 
 creating same team differently
 */

#include <iostream>
#include "FIFA.hpp"

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

    //Done with testing
    cout << "\n\nEnd of Testing ... " << endl;
    
    cout << endl;
    return 0;
}








